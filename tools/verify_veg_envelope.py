"""Compare every envelope state word with original VEG calls on cloned voices."""
import ctypes,struct,json,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
sample_rate=int(sys.argv[1]) if len(sys.argv)>1 else 44100
stem=ROOT/('analysis/veg-envelope/veg-'+str(sample_rate))
lib=ctypes.CDLL(str(ROOT/'build/veg_envelope.dll'))
for name in ('veg_env_buffer','veg_env_tables','veg_env_parameters'):getattr(lib,name).restype=ctypes.c_void_p
state=lib.veg_env_buffer();params=lib.veg_env_parameters()
ctypes.memmove(lib.veg_env_tables(),b''.join(Path(str(stem)+'-rate'+str(i)+'.bin').read_bytes() for i in range(3)),1536)
original=Path(str(stem)+'-voice.bin').read_bytes()
fixtures=Path(str(stem)+'-envelope-fixtures.bin').read_bytes();size=12+25*48
failures=[];count=0
for pos in range(0,len(fixtures),size):
    case=fixtures[pos:pos+size];initial,end,target=struct.unpack_from('<3I',case)
    ctypes.memmove(state,original[4:8]+original[0xc4:0xf0],48)
    ctypes.memmove(params,struct.pack('<4I',initial,target,end,255),16)
    ctypes.c_uint32.from_address(state).value=3
    lib.veg_env_init()
    for step in range(25):
        if step:
            if step==9:
                ctypes.c_uint32.from_address(params+12).value=32
                lib.veg_env_update()
            lib.veg_env_tick()
        actual=ctypes.string_at(state,48);expected=case[12+step*48:12+(step+1)*48];count+=1
        if actual!=expected:
            fields=[i for i in range(12) if actual[i*4:i*4+4]!=expected[i*4:i*4+4]]
            if len(failures)<12:failures.append({'case':[initial,end,target],'step':step,'fields':fields,'actual':list(struct.unpack('<12I',actual)),'expected':list(struct.unpack('<12I',expected))})
            break
report={'states_checked':count,'first_failures':failures,'passed':not failures,'integrated_in_renderer':False}
(ROOT/('analysis/veg-envelope/verification-'+str(sample_rate)+'.json')).write_text(json.dumps(report,indent=2))
print(json.dumps(report,indent=2))
if failures:raise SystemExit(1)
