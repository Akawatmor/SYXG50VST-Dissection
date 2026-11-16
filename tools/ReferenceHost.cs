using System;
using System.IO;
using System.Text;
using System.Collections.Generic;
using System.Runtime.InteropServices;

// Small offline x86 host. Loads the supplied DLL unchanged; no audio device or GUI.
class ReferenceHost {
    [DllImport("kernel32.dll", CharSet=CharSet.Unicode, SetLastError=true)] static extern IntPtr LoadLibraryW(string path);
    [DllImport("kernel32.dll", CharSet=CharSet.Ansi)] static extern IntPtr GetProcAddress(IntPtr module, string name);
    [DllImport("kernel32.dll")] static extern bool FreeLibrary(IntPtr module);
    [UnmanagedFunctionPointer(CallingConvention.Cdecl)] delegate IntPtr Callback(IntPtr effect, int opcode, int index, IntPtr value, IntPtr ptr, float opt);
    [UnmanagedFunctionPointer(CallingConvention.Cdecl)] delegate IntPtr Entry(IntPtr callback);
    [UnmanagedFunctionPointer(CallingConvention.Cdecl)] delegate void Process(IntPtr effect, IntPtr inputs, IntPtr outputs, int frames);
    static Callback host = Host;
    static int rate, block;
    static long samplePosition;
    static IntPtr timeInfo;
    static StreamWriter log;
    static List<byte[]> pendingMidi = new List<byte[]>();
    static List<IntPtr> eventMemory = new List<IntPtr>();
    static void Log(string s) { Console.WriteLine(s); log.WriteLine(s); log.Flush(); }
    static IntPtr Host(IntPtr e, int op, int index, IntPtr value, IntPtr ptr, float opt) {
        if (op != 7) Log("host opcode="+op+" index="+index+" value="+value+" opt="+opt);
        switch(op) {
            case 1: return new IntPtr(2400); // audioMasterVersion
            case 7:
                byte[] info=new byte[88];
                Buffer.BlockCopy(BitConverter.GetBytes((double)samplePosition),0,info,0,8);
                Buffer.BlockCopy(BitConverter.GetBytes((double)rate),0,info,8,8);
                Marshal.Copy(info,0,timeInfo,info.Length);
                return timeInfo;
            case 16: return new IntPtr(rate);
            case 17: return new IntPtr(block);
            case 23: return new IntPtr(4); // offline processing
            case 32: if(ptr!=IntPtr.Zero) Marshal.Copy(Encoding.ASCII.GetBytes("Dissection\0"),0,ptr,11); return new IntPtr(1);
            case 33: if(ptr!=IntPtr.Zero) Marshal.Copy(Encoding.ASCII.GetBytes("ReferenceHost\0"),0,ptr,14); return new IntPtr(1);
            case 34: return new IntPtr(1);
            case 37:
                string cap=ptr==IntPtr.Zero ? "" : Marshal.PtrToStringAnsi(ptr);
                Log("host canDo="+cap);
                return new IntPtr(cap=="sendVstEvents" || cap=="sendVstMidiEvent" || cap=="sendVstTimeInfo" ? 1 : 0);
            case 43: return new IntPtr(1); // English
            default: return IntPtr.Zero;
        }
    }
    static string Rva(IntPtr p, IntPtr module) { return "0x"+unchecked((uint)(p.ToInt32()-module.ToInt32())).ToString("X8"); }
    static IntPtr Dispatch(Callback d, IntPtr e, int op, int index, int value, IntPtr ptr, float opt) {
        IntPtr result=d(e,op,index,new IntPtr(value),ptr,opt);
        Log("dispatch opcode="+op+" result="+result);
        return result;
    }
    static void Midi(Callback d, IntPtr e, int status, int a, int b, int delta) {
        byte[] data=new byte[32];
        Buffer.BlockCopy(BitConverter.GetBytes(1),0,data,0,4);
        Buffer.BlockCopy(BitConverter.GetBytes(32),0,data,4,4);
        Buffer.BlockCopy(BitConverter.GetBytes(delta),0,data,8,4);
        data[24]=(byte)status; data[25]=(byte)a; data[26]=(byte)b;
        pendingMidi.Add(data);
        Log("midi sample="+(samplePosition+delta)+" bytes="+status.ToString("X2")+" "+a.ToString("X2")+" "+b.ToString("X2"));
    }
    static void FlushMidi(Callback d, IntPtr e) {
        if(pendingMidi.Count==0) return;
        IntPtr list=Marshal.AllocHGlobal(8+4*Math.Max(2,pendingMidi.Count)); eventMemory.Add(list);
        Marshal.WriteInt32(list,0,pendingMidi.Count); Marshal.WriteInt32(list,4,0);
        for(int i=0;i<pendingMidi.Count;i++) {
            IntPtr ev=Marshal.AllocHGlobal(32); eventMemory.Add(ev);
            Marshal.Copy(pendingMidi[i],0,ev,32); Marshal.WriteIntPtr(list,8+i*4,ev);
        }
        pendingMidi.Clear();
        Dispatch(d,e,25,0,0,list,0);
    }
    static void FreeEvents() {
        foreach(IntPtr p in eventMemory) Marshal.FreeHGlobal(p);
        eventMemory.Clear();
    }
    static void DumpMemory(IntPtr p, int size, string path) { byte[] b=new byte[size]; Marshal.Copy(p,b,0,size); File.WriteAllBytes(path,b); }
    static void WriteWav(string path, float[] pcm, int format) {
        using(BinaryWriter w=new BinaryWriter(File.Create(path))) {
            int bytes=format==3 ? 4 : 2, data=pcm.Length*bytes;
            w.Write(Encoding.ASCII.GetBytes("RIFF")); w.Write(data+36); w.Write(Encoding.ASCII.GetBytes("WAVEfmt "));
            w.Write(16); w.Write((short)format); w.Write((short)2); w.Write(rate); w.Write(rate*2*bytes); w.Write((short)(2*bytes)); w.Write((short)(bytes*8));
            w.Write(Encoding.ASCII.GetBytes("data")); w.Write(data);
            foreach(float x in pcm) { if(format==3) w.Write(x); else w.Write((short)Math.Round(Math.Max(-1,Math.Min(1,x))*32767)); }
        }
    }
    static int Main(string[] args) {
        if(args.Length<3) { Console.Error.WriteLine("ReferenceHost DLL OUTPUT_PREFIX probe|silence|note|hold [sampleRate=44100] [blockSize=256] [note=60] [velocity=100] [program=0] [eventOffset=0] [process|replacing]"); return 2; }
        if(IntPtr.Size!=4) throw new Exception("Host must be compiled /platform:x86");
        string dll=Path.GetFullPath(args[0]), prefix=Path.GetFullPath(args[1]), mode=args[2];
        rate=args.Length>3 ? int.Parse(args[3]) : 44100; block=args.Length>4 ? int.Parse(args[4]) : 256;
        int note=args.Length>5 ? int.Parse(args[5]) : 60, velocity=args.Length>6 ? int.Parse(args[6]) : 100;
        int program=args.Length>7 ? int.Parse(args[7]) : 0, offset=args.Length>8 ? int.Parse(args[8]) : 0;
        if(rate<8000 || rate>192000 || block<1 || block>8192 || offset<0 || offset>=block || note<0 || note>127 || velocity<1 || velocity>127 || program<0 || program>127) throw new ArgumentException("Invalid audio/MIDI argument");
        Directory.CreateDirectory(Path.GetDirectoryName(prefix));
        log=new StreamWriter(prefix+".log",false,Encoding.UTF8); log.AutoFlush=true;
        IntPtr module=IntPtr.Zero, effect=IntPtr.Zero, outputs=IntPtr.Zero;
        IntPtr[] channels=null; Callback dispatcher=null; bool opened=false, resumed=false;
        try {
            Log("dll="+dll+" mode="+mode+" rate="+rate+" block="+block);
            // Match a conventional host's plugin working directory; never change the DLL.
            Directory.SetCurrentDirectory(Path.GetDirectoryName(dll));
            timeInfo=Marshal.AllocHGlobal(88);
            Log("stage=LoadLibrary"); module=LoadLibraryW(dll);
            if(module==IntPtr.Zero) throw new Exception("LoadLibrary error "+Marshal.GetLastWin32Error());
            IntPtr entry=GetProcAddress(module,"main"); if(entry==IntPtr.Zero) entry=GetProcAddress(module,"VSTPluginMain");
            if(entry==IntPtr.Zero) throw new Exception("VST entry missing");
            Log("entry RVA="+Rva(entry,module));
            Log("stage=entry"); effect=((Entry)Marshal.GetDelegateForFunctionPointer(entry,typeof(Entry)))(Marshal.GetFunctionPointerForDelegate(host));
            if(effect==IntPtr.Zero) throw new Exception("entry returned null");
            if(Marshal.ReadInt32(effect)!=0x56737450) throw new Exception("Invalid AEffect magic");
            DumpMemory(effect,144,prefix+"-aeffect.bin");
            int numIn=Marshal.ReadInt32(effect,28), numOut=Marshal.ReadInt32(effect,32), flags=Marshal.ReadInt32(effect,36);
            Log("AEffect inputs="+numIn+" outputs="+numOut+" flags=0x"+flags.ToString("X")+" programs="+Marshal.ReadInt32(effect,20)+" params="+Marshal.ReadInt32(effect,24)+" version="+Marshal.ReadInt32(effect,76));
            foreach(int field in new int[]{4,8,12,16,80}) Log("callback offset="+field+" RVA="+Rva(Marshal.ReadIntPtr(effect,field),module));
            IntPtr obj=Marshal.ReadIntPtr(effect,64); DumpMemory(obj,0x104,prefix+"-object.bin");
            IntPtr vt=Marshal.ReadIntPtr(obj); DumpMemory(vt,0x220,prefix+"-vtable.bin");
            for(int i=0;i<0x220;i+=4) Log("vtable +0x"+i.ToString("X3")+" RVA="+Rva(Marshal.ReadIntPtr(vt,i),module));
            IntPtr engine=Marshal.ReadIntPtr(obj,0xB0);
            DumpMemory(engine,0x58,prefix+"-engine-adapter.bin");
            IntPtr engineVt=Marshal.ReadIntPtr(engine);
            for(int i=0;i<0x24;i+=4) Log("engine vtable +0x"+i.ToString("X2")+" RVA="+Rva(Marshal.ReadIntPtr(engineVt,i),module));
            IntPtr core=Marshal.ReadIntPtr(engine,8);
            if(core!=IntPtr.Zero) {
                DumpMemory(core,0x80,prefix+"-core-header.bin");
                IntPtr coreVt=Marshal.ReadIntPtr(core);
                Log("core vtable RVA="+Rva(coreVt,module));
                DumpMemory(coreVt,0x600,prefix+"-core-vtable.bin");
                for(int i=0;i<0x600;i+=4) Log("core vtable +0x"+i.ToString("X3")+" RVA="+Rva(Marshal.ReadIntPtr(coreVt,i),module));
            }
            // The supplied builds use these globals for the two loaded bank buffers.
            // Capture only the prefixes; matching prefixes are evidence, not a full bank hash.
            for(int i=0;i<2;i++) {
                IntPtr bank=Marshal.ReadIntPtr(IntPtr.Add(module,0x55340+i*4));
                if(bank!=IntPtr.Zero) DumpMemory(bank,64,prefix+"-bank"+(i+1)+"-prefix.bin");
            }
            dispatcher=(Callback)Marshal.GetDelegateForFunctionPointer(Marshal.ReadIntPtr(effect,4),typeof(Callback));
            Dispatch(dispatcher,effect,0,0,0,IntPtr.Zero,0); opened=true;
            Dispatch(dispatcher,effect,10,0,0,IntPtr.Zero,(float)rate);
            Dispatch(dispatcher,effect,11,0,block,IntPtr.Zero,0);
            Dispatch(dispatcher,effect,2,0,0,IntPtr.Zero,0);
            if(mode=="probe") return 0;
            if(mode!="note" && mode!="hold" && mode!="silence") throw new ArgumentException("Unknown mode");
            if(numIn!=0 || numOut!=2) throw new Exception("This reference recorder expects a stereo instrument with zero inputs");
            bool replacing=(flags&16)!=0 && Marshal.ReadIntPtr(effect,80)!=IntPtr.Zero;
            if(args.Length>9) replacing=args[9]=="replacing";
            IntPtr proc=Marshal.ReadIntPtr(effect,replacing ? 80 : 8); if(proc==IntPtr.Zero) throw new Exception("Process callback missing");
            Log("render callback="+(replacing ? "processReplacing" : "process")+" RVA="+Rva(proc,module));
            Process render=(Process)Marshal.GetDelegateForFunctionPointer(proc,typeof(Process));
            channels=new IntPtr[2]; outputs=Marshal.AllocHGlobal(8);
            for(int i=0;i<2;i++) { channels[i]=Marshal.AllocHGlobal(block*4); Marshal.WriteIntPtr(outputs,i*4,channels[i]); }
            Dispatch(dispatcher,effect,12,0,1,IntPtr.Zero,0); resumed=true;
            Midi(dispatcher,effect,0xB0,0,0,0); Midi(dispatcher,effect,0xB0,32,0,0); Midi(dispatcher,effect,0xC0,program,0,0);
            int total=rate*4, on=((rate/4)/128)*128+offset, off=((rate*5/4)/128)*128+offset;
            Log("schedule noteOn="+on+" noteOff="+off+" total="+total);
            float[] pcm=new float[total*2], left=new float[block], right=new float[block], zeros=new float[block];
            for(int pos=0;pos<total;pos+=block) {
                samplePosition=pos; int n=Math.Min(block,total-pos);
                if(mode!="silence" && on>=pos && on<pos+n) Midi(dispatcher,effect,0x90,note,velocity,on-pos);
                if(mode=="note" && off>=pos && off<pos+n) Midi(dispatcher,effect,0x80,note,0,off-pos);
                FlushMidi(dispatcher,effect);
                for(int c=0;c<2;c++) Marshal.Copy(zeros,0,channels[c],block);
                render(effect,IntPtr.Zero,outputs,n);
                FreeEvents();
                Marshal.Copy(channels[0],left,0,n); Marshal.Copy(channels[1],right,0,n);
                for(int i=0;i<n;i++) { pcm[(pos+i)*2]=left[i]; pcm[(pos+i)*2+1]=right[i]; }
            }
            double peak=0,sum=0; int nonzero=0;
            foreach(float x in pcm) { if(float.IsNaN(x)||float.IsInfinity(x)) throw new Exception("Nonfinite PCM"); peak=Math.Max(peak,Math.Abs(x)); sum+=(double)x*x; if(x!=0) nonzero++; }
            WriteWav(prefix+".float.wav",pcm,3); WriteWav(prefix+".wav",pcm,1);
            Log("RESULT peak="+peak.ToString("R")+" rms="+Math.Sqrt(sum/pcm.Length).ToString("R")+" nonzero="+nonzero);
            return mode=="note" && nonzero==0 ? 3 : 0;
        } catch(Exception ex) { Log("ERROR "+ex); return 1; }
        finally {
            if(dispatcher!=null && effect!=IntPtr.Zero) {
                if(resumed) Dispatch(dispatcher,effect,12,0,0,IntPtr.Zero,0);
                if(opened) Dispatch(dispatcher,effect,1,0,0,IntPtr.Zero,0);
            }
            if(channels!=null) foreach(IntPtr p in channels) if(p!=IntPtr.Zero) Marshal.FreeHGlobal(p);
            FreeEvents();
            if(outputs!=IntPtr.Zero) Marshal.FreeHGlobal(outputs);
            if(module!=IntPtr.Zero) FreeLibrary(module);
            if(timeInfo!=IntPtr.Zero) Marshal.FreeHGlobal(timeInfo);
            GC.KeepAlive(host); log.Dispose();
        }
    }
}
