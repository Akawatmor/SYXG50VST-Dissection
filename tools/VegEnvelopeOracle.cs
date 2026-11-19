using System;
using System.IO;
using System.Runtime.InteropServices;

partial class ReferenceHost {
    [UnmanagedFunctionPointer(CallingConvention.ThisCall)] delegate uint EnvelopeStatus(IntPtr voice);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate uint CoreStatus(IntPtr core,int index);
    static partial void TraceVegVoices(IntPtr module,IntPtr core,string prefix,int frame) {
        IntPtr renderer=Marshal.ReadIntPtr(core,0x10),manager=Marshal.ReadIntPtr(renderer,0x0c),pool=Marshal.ReadIntPtr(manager,0x0c);
        using(BinaryWriter output=new BinaryWriter(new FileStream(prefix+"-voice-trace.bin",frame==0?FileMode.Create:FileMode.Append))) {
            for(int index=0;index<256;index++) {
                IntPtr voice=IntPtr.Add(pool,index*0x170);
                if((Marshal.ReadInt32(voice,4)&1)==0)continue;
                if(Environment.GetEnvironmentVariable("SYXG_DIAGNOSTIC_STATUS")=="1" && index==0 && frame>=13000 && frame<14500){
                    EnvelopeStatus status=(EnvelopeStatus)Marshal.GetDelegateForFunctionPointer(IntPtr.Add(module,0x18e20),typeof(EnvelopeStatus));
                    CoreStatus packed=(CoreStatus)Marshal.GetDelegateForFunctionPointer(Marshal.ReadIntPtr(Marshal.ReadIntPtr(core),0x90),typeof(CoreStatus));
                    File.AppendAllText(prefix+"-status.txt",frame+" raw="+status(voice)+" packed="+packed(core,0)+" midi="+Marshal.ReadByte(IntPtr.Add(core,0x13a0),1)+"\n");
                }
                IntPtr config=Marshal.ReadIntPtr(voice,0x24);if(config==IntPtr.Zero)continue;
                byte[] values=new byte[0x48];Marshal.Copy(config,values,0,values.Length);
                output.Write(frame);output.Write(index);output.Write(values);WriteEnvelopeState(output,voice);
            }
        }
    }
    [UnmanagedFunctionPointer(CallingConvention.ThisCall)] delegate void EnvelopeCall(IntPtr voice);
    static partial void CaptureVegEnvelope(IntPtr module,IntPtr core,string prefix) {
        IntPtr renderer=Marshal.ReadIntPtr(core,0x10),manager=Marshal.ReadIntPtr(renderer,0x0c),pool=Marshal.ReadIntPtr(manager,0x0c);
        IntPtr voice=IntPtr.Zero;
        for(int index=0;index<256;index++) {
            IntPtr candidate=IntPtr.Add(pool,index*0x170);
            if((Marshal.ReadInt32(candidate,4)&1)!=0){voice=candidate;break;}
        }
        if(voice==IntPtr.Zero)throw new Exception("No active original voice for envelope capture");
        DumpMemory(voice,0x170,prefix+"-voice.bin");
        IntPtr parameters=Marshal.ReadIntPtr(voice,0x24);
        DumpMemory(parameters,0x60,prefix+"-parameters.bin");
        IntPtr midiVoice=IntPtr.Add(core,0x13a0);
        DumpMemory(midiVoice,0x8c,prefix+"-midi-voice0.bin");
        foreach(int pointerOffset in new int[]{0x20,0x28,0x2c,0x30}) {
            IntPtr pointer=Marshal.ReadIntPtr(midiVoice,pointerOffset);
            if(pointer!=IntPtr.Zero)DumpMemory(pointer,pointerOffset==0x20?0x11c:80,prefix+"-midi-pointer"+pointerOffset.ToString("X")+".bin");
        }
        File.WriteAllText(prefix+"-mapping.txt","mode="+Marshal.ReadByte(core,0x63ae)+"\nbase="+(Marshal.ReadIntPtr(voice,0x68).ToInt64()-module.ToInt64()-0x7e768)+"\nbefore="+Marshal.ReadInt32(voice,0x6c)+"\nloop="+Marshal.ReadInt32(voice,0x70)+"\nstep="+Marshal.ReadInt32(voice,0x84)+"\nflags="+Marshal.ReadInt32(parameters,0x44)+"\n");
        for(int table=0;table<3;table++)DumpMemory(Marshal.ReadIntPtr(voice,0x18+table*4),512,prefix+"-rate"+table+".bin");
        DumpMemory(IntPtr.Add(module,0x48dd4),8,prefix+"-constants.bin");
        EnvelopeCall init=(EnvelopeCall)Marshal.GetDelegateForFunctionPointer(IntPtr.Add(module,0x18ea0),typeof(EnvelopeCall));
        EnvelopeCall tick=(EnvelopeCall)Marshal.GetDelegateForFunctionPointer(IntPtr.Add(module,0x18fe0),typeof(EnvelopeCall));
        EnvelopeCall update=(EnvelopeCall)Marshal.GetDelegateForFunctionPointer(IntPtr.Add(module,0x18cf0),typeof(EnvelopeCall));
        IntPtr copy=Marshal.AllocHGlobal(0x170),config=Marshal.AllocHGlobal(0x60);
        byte[] original=new byte[0x170],param=new byte[0x60];Marshal.Copy(voice,original,0,original.Length);Marshal.Copy(parameters,param,0,param.Length);
        CaptureVegOscillator(module,prefix,original);
        try {
            using(BinaryWriter output=new BinaryWriter(File.Create(prefix+"-envelope-fixtures.bin"))) {
                for(int initialRate=0;initialRate<256;initialRate++)
                foreach(int endRate in EnvelopeEndRates(initialRate))
                foreach(int target in new int[]{0,32,127}) {
                    Marshal.Copy(original,0,copy,original.Length);Marshal.Copy(param,0,config,param.Length);
                    Marshal.WriteIntPtr(copy,0x24,config);Marshal.WriteInt32(copy,4,3);
                    Marshal.WriteInt32(config,0x1c,initialRate);Marshal.WriteInt32(config,0x20,target);
                    Marshal.WriteInt32(config,0x24,endRate);Marshal.WriteInt32(config,0x28,255);
                    output.Write(initialRate);output.Write(endRate);output.Write(target);
                    init(copy);WriteEnvelopeState(output,copy);
                    for(int index=0;index<24;index++) {
                        if(index==8){Marshal.WriteInt32(config,0x28,32);update(copy);}
                        tick(copy);WriteEnvelopeState(output,copy);
                    }
                }
            }
        } finally {Marshal.FreeHGlobal(copy);Marshal.FreeHGlobal(config);}
        Log("Captured original VEG envelope tables and 9156 state-machine fixtures");
    }
    static void CaptureVegOscillator(IntPtr module,string prefix,byte[] original) {
        string fixture=Environment.GetEnvironmentVariable("SYXG_OSCILLATOR_FIXTURE");
        if(String.IsNullOrEmpty(fixture))return;
        byte[] wave=File.ReadAllBytes(Path.Combine(fixture,"wave-decoded.bin"));
        // VEG stores the physical wave with the legacy 0x5C XOR already removed.
        for(int i=0;i<wave.Length;i++)wave[i]^=0x5c;
        IntPtr waveCopy=Marshal.AllocHGlobal(wave.Length),voiceCopy=Marshal.AllocHGlobal(0x170),pcm=Marshal.AllocHGlobal(512);
        EnvelopeCall oscillator=(EnvelopeCall)Marshal.GetDelegateForFunctionPointer(IntPtr.Add(module,0x1abb0),typeof(EnvelopeCall));
        try {
            Marshal.Copy(wave,0,waveCopy,wave.Length);
            foreach(string variant in new string[]{"","-wrap","-carry"}) {
                byte[] seed=File.ReadAllBytes(Path.Combine(fixture,"legacy-dump-oscillator"+variant+"-seed.bin"));
                Marshal.Copy(original,0,voiceCopy,original.Length);
                Marshal.WriteIntPtr(voiceCopy,0x10,pcm);
                Marshal.WriteIntPtr(voiceCopy,0x68,IntPtr.Add(waveCopy,BitConverter.ToInt32(seed,0)));
                Marshal.WriteInt32(voiceCopy,0x70,BitConverter.ToInt32(seed,4));
                Marshal.WriteInt32(voiceCopy,0x74,BitConverter.ToInt32(seed,8));
                Marshal.WriteInt32(voiceCopy,0x7c,BitConverter.ToInt32(seed,12));
                Marshal.WriteInt32(voiceCopy,0x80,BitConverter.ToInt32(seed,16));
                Marshal.WriteInt32(voiceCopy,0x84,BitConverter.ToInt32(seed,20));
                oscillator(voiceCopy);
                DumpMemory(pcm,512,prefix+"-oscillator"+variant+".i32");
                byte[] final=new byte[8];Buffer.BlockCopy(BitConverter.GetBytes(Marshal.ReadInt32(voiceCopy,0x7c)),0,final,0,4);Buffer.BlockCopy(BitConverter.GetBytes(Marshal.ReadInt32(voiceCopy,0x80)),0,final,4,4);
                File.WriteAllBytes(prefix+"-oscillator"+variant+"-final.bin",final);
            }
        } finally {Marshal.FreeHGlobal(waveCopy);Marshal.FreeHGlobal(voiceCopy);Marshal.FreeHGlobal(pcm);}
    }
    static int[] EnvelopeEndRates(int initialRate) {
        if(initialRate<2){int[] values=new int[256];for(int i=0;i<256;i++)values[i]=i;return values;}
        return new int[]{0,32,95,96,127,128,160,223,224,255};
    }
    static void WriteEnvelopeState(BinaryWriter output,IntPtr voice) {
        output.Write(Marshal.ReadInt32(voice,4));
        byte[] values=new byte[0x2c];Marshal.Copy(IntPtr.Add(voice,0xc4),values,0,values.Length);output.Write(values);
    }
}
