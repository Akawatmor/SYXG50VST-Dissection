from pathlib import Path
import ctypes,struct,json,sys
root=Path(__file__).resolve().parents[1];prefix=sys.argv[1] if len(sys.argv)>1 else 'piano-trace'
program=int(sys.argv[2]) if len(sys.argv)>2 else 0
channel=int(sys.argv[3]) if len(sys.argv)>3 else 0
note=int(sys.argv[4]) if len(sys.argv)>4 else 60
lib=ctypes.CDLL(str(root/'build/syxg_core.dll'))
for n in ['sxg_bank_buffer','sxg_wave_buffer']:getattr(lib,n).restype=ctypes.c_void_p
for n,f in [('sxg_bank_buffer','sxgbin41.tbl'),('sxg_wave_buffer','Sxgwave4.tbl')]:
    d=(root/'dll/legacy'/f).read_bytes();ctypes.memmove(getattr(lib,n)(),d,len(d))
lib.sxg_init(145014,4299476,44100);lib.sxg_midi(0xc0|channel,program,0)
raw=(root/('analysis/veg-envelope/'+prefix+'-voice-trace.bin')).read_bytes()
records={}
for p in range(0,len(raw),128):
    frame,voice=struct.unpack_from('<2i',raw,p)
    if voice==0:records[frame]=(struct.unpack_from('<4I',raw,p+8+0x1c),struct.unpack_from('<12I',raw,p+80))
errors=[];count=0
for frame in range(0,176400,128):
    if frame==11008:lib.sxg_midi(0x90|channel,note,100)
    if frame==55040 and 'hold' not in prefix:lib.sxg_midi(0x80|channel,note,0)
    lib.sxg_render(min(128,176400-frame))
    if frame not in records:continue
    params,state=records[frame];actual=[lib.sxg_voice_envelope(0,i)&0xffffffff for i in range(16)]
    expected=list(state)+list(params);actual[0]&=0x3003;expected[0]&=0x3003
    fields=[i for i in range(16) if actual[i]!=expected[i]];count+=1
    if fields and len(errors)<5:errors.append({'frame':frame,'fields':fields,'actual':actual,'expected':expected})
report={'profile':prefix,'snapshots':count,'first_errors':errors,'passed':not errors}
(root/('analysis/veg-envelope/live-'+prefix+'.json')).write_text(json.dumps(report,indent=2));print(json.dumps(report,indent=2))
if errors:sys.exit(1)
