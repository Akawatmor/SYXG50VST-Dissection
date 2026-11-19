"""Measure wet/dry and post-note-off tails; render the old/new cores identically."""
from pathlib import Path
import ctypes
import json
import wave
import numpy as np

ROOT=Path(__file__).resolve().parents[1]
RATE=48000
OUT=ROOT/'analysis/mix-fix'
OUT.mkdir(exist_ok=True)

def load(name):
    lib=ctypes.CDLL(str(ROOT/'build'/name))
    for func in ('sxg_bank_buffer','sxg_wave_buffer','sxg_output_buffer'):
        getattr(lib,func).restype=ctypes.c_void_p
    for func,filename in (('sxg_bank_buffer','sxgbin41.tbl'),('sxg_wave_buffer','Sxgwave4.tbl')):
        data=(ROOT/'dll/legacy'/filename).read_bytes()
        ctypes.memmove(getattr(lib,func)(),data,len(data))
    assert lib.sxg_init(145014,4299476,RATE)==0
    return lib

def render(lib,events,effects=True,program=0):
    lib.sxg_reset();lib.sxg_set_effects(int(effects));lib.sxg_midi(0xc0,program,0)
    result=[];position=0
    for frame,event in sorted(events,key=lambda e:e[0])+[(RATE*2,None)]:
        while position<frame:
            count=min(128,frame-position)
            assert lib.sxg_render(count)==0
            result.append(np.ctypeslib.as_array((ctypes.c_float*(count*2)).from_address(lib.sxg_output_buffer())).copy().reshape(-1,2))
            position+=count
        if event: assert lib.sxg_midi(*event)==0
    return np.concatenate(result)

def rms(pcm):return float(np.sqrt(np.mean(pcm.astype(np.float64)**2)))
def wav(path,pcm):
    with wave.open(str(path),'wb') as file:
        file.setparams((2,2,RATE,0,'NONE','not compressed'))
        file.writeframes((np.clip(pcm,-1,1)*32767).astype('<i2').tobytes())

report={}
for label,name in [('before','syxg_core-before-mix.dll'),('after','syxg_core.dll')]:
    lib=load(name);rows={}
    for program in [0,40,80]:
        events=[(0,[0xb0,91,127]),(0,[0xb0,93,127]),(0,[0x90,60,100]),(24000,[0x80,60,0])]
        dry=render(lib,events,False,program);wet=render(lib,events,True,program)
        rows[str(program)]={'wet_difference_to_dry_rms':rms((wet-dry)[:24000])/rms(dry[:24000]),
                            'release_tail_rms_150_to_300ms':rms(dry[31200:38400]),
                            'held_last_100ms_rms':rms(dry[19200:24000])}
    # Repeated kick/snare/open/closed hats plus a melodic chord, with full sends.
    events=[(0,[0xb0,91,127]),(0,[0xb0,93,127]),(0,[0xb9,91,127]),(0,[0xb9,93,127]),
            (0,[0x90,60,90]),(0,[0x90,64,90]),(0,[0x90,67,90])]
    for tick,note in [(0,36),(6000,46),(12000,38),(18000,42),(24000,36),(30000,46),(36000,38),(42000,42)]:
        events.extend([(tick,[0x99,note,110]),(tick+600,[0x89,note,0])])
    events.extend([(48000,[0x80,n,0]) for n in [60,64,67]])
    pcm=render(lib,events);wav(OUT/(label+'.wav'),pcm)
    rows['mix_peak']=float(np.max(np.abs(pcm)))
    # Kick's bank send (32/127) must scale the full part CC93 send.
    drum_events=[(0,[0xb9,91,0]),(0,[0xb9,93,127]),(0,[0x99,36,100])]
    a=render(lib,drum_events,False);b=render(lib,drum_events,True)
    rows['kick_chorus_difference_rms']=rms(a-b)
    open_then_closed=render(lib,[(0,[0x99,46,100]),(12000,[0x99,42,100])],False)
    closed=render(lib,[(12000,[0x99,42,100])],False)
    rows['choked_open_hat_tail_rms']=rms((open_then_closed-closed)[13920:16800])
    no_pedal=render(lib,[(0,[0x99,36,100]),(600,[0x89,36,0])],False)
    pedal_off=render(lib,[(0,[0x99,36,100]),(600,[0x89,36,0]),(1440,[0xb9,64,0])],False)
    rows['one_shot_pedal_off_difference_rms']=rms(no_pedal-pedal_off)
    report[label]=rows

for program in ['0','40','80']:
    assert report['after'][program]['wet_difference_to_dry_rms']<0.5
    assert report['after'][program]['release_tail_rms_150_to_300ms']<report['before'][program]['release_tail_rms_150_to_300ms']*0.5
    assert report['after'][program]['held_last_100ms_rms']==report['before'][program]['held_last_100ms_rms']
assert report['after']['kick_chorus_difference_rms']<report['before']['kick_chorus_difference_rms']*0.15
assert report['after']['choked_open_hat_tail_rms']<report['before']['choked_open_hat_tail_rms']*0.1
assert report['after']['one_shot_pedal_off_difference_rms']==0
assert report['after']['mix_peak']<1
(OUT/'results.json').write_text(json.dumps(report,indent=2))
print(json.dumps(report,indent=2))
