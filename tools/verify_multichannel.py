"""Compare a MIDI/controller/drum/effects sequence in native C and WASM."""
from pathlib import Path
import ctypes
import hashlib
import json
import subprocess

ROOT = Path(__file__).resolve().parents[1]
lib = ctypes.CDLL(str(ROOT/'build/syxg_core.dll'))
for name in ('sxg_bank_buffer','sxg_wave_buffer','sxg_output_buffer'):
    getattr(lib,name).restype = ctypes.c_void_p
for name, source in (('sxg_bank_buffer','sxgbin41.tbl'),('sxg_wave_buffer','Sxgwave4.tbl')):
    data=(ROOT/'dll/legacy'/source).read_bytes()
    ctypes.memmove(getattr(lib,name)(),data,len(data))
assert lib.sxg_init(145014,4299476,48000)==0
events=[(0,[0x90,60,100]),(17,[0x91,64,90]),(63,[0x99,36,110]),(149,[0xb0,64,127]),
        (201,[0x80,60,0]),(403,[0xe1,0,96]),(670,[0xb1,10,12]),(901,[0xb1,91,100]),
        (1203,[0xb1,93,70]),(1409,[0x99,42,100]),(1800,[0xb0,64,0]),(2107,[0x81,64,0]),
        (3000,[0xc2,40,0]),(3001,[0x92,72,80]),(9000,[0xb2,123,0]),(47000,[0xb9,120,0])]
parts=[]
position=0
for frame,event in events+[(48000,None)]:
    while position<frame:
        count=min(128,frame-position)
        assert lib.sxg_render(count)==0
        parts.append(ctypes.string_at(lib.sxg_output_buffer(),count*8))
        position+=count
    if event: assert lib.sxg_midi(*event)==0
native=b''.join(parts)
(ROOT/'build/multichannel-native.f32').write_bytes(native)
(ROOT/'build/multichannel-sequence.json').write_text(json.dumps(events))
subprocess.run(['node',str(ROOT/'tools/verify_multichannel.mjs')],check=True,cwd=ROOT)
wasm=(ROOT/'build/multichannel-wasm.f32').read_bytes()
report={'native_wasm_bit_identical':native==wasm,'frames':48000,'events':len(events),'pcm_sha256':hashlib.sha256(native).hexdigest()}
(ROOT/'analysis/multichannel-parity.json').write_text(json.dumps(report,indent=2))
print(json.dumps(report,indent=2))
assert native==wasm
