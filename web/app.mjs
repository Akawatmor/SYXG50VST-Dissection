import { SyxgSynth } from './synth-client.mjs';
import { parseMidi } from './midi-file.mjs';

const $ = id => document.getElementById(id);
const synth = new SyxgSynth();
let bank = null, wave = null, song = null, playing = false, paused = false, startTime = 0;
let midi = null, input = null, destroyEditor = null;
const status = (message,error=false) => { $('status').textContent=message; $('status').classList.toggle('error',error); };
const controls = enabled => { for(const id of ['connect-midi','midi-file','test-note','demo','panic','open-editor'])$(id).disabled=!enabled; $('play').disabled=!enabled||!song; $('stop').disabled=!enabled; $('pause').disabled=!enabled||!playing; };
function bankState() { const ready=bank?.length===145014&&wave?.length===4299476; $('power').disabled=!ready; $('bank-state').textContent=ready?'MU50 4 MB · พร้อมโหลด':`เลือก sxgbin41.tbl และ Sxgwave4.tbl`; return ready; }
async function defaults() {
  try {
    const responses=await Promise.all([fetch('./banks/sxgbin41.tbl'),fetch('./banks/Sxgwave4.tbl')]);
    if(responses.some(response=>!response.ok))throw new Error();
    [bank,wave]=await Promise.all(responses.map(async response=>new Uint8Array(await response.arrayBuffer())));
    if(!bankState())throw new Error(); status('พร้อมเริ่มเสียง หน้าจอเครื่องจะเปิดเมื่อกดเรียกใช้');
  } catch { bankState(); $('bank-picker').open=true; status('เลือกไฟล์ bank ทั้งสองไฟล์จากโฟลเดอร์ legacy'); }
}
for(const [id,type] of [['bank-file','bank'],['wave-file','wave']])$(id).onchange=async event=>{
  const file=event.target.files[0]; if(!file)return;
  const size=type==='bank'?145014:4299476;
  if(file.size!==size){status(`ขนาดไฟล์ไม่ตรง ต้องเป็น ${size.toLocaleString()} ไบต์`,true);return;}
  const bytes=new Uint8Array(await file.arrayBuffer()); if(type==='bank')bank=bytes;else wave=bytes;bankState();
};
$('power').onclick=async()=>{
  $('power').disabled=true;
  try {
    if(synth.ready){closeEditor();playing=false;paused=false;await synth.close();controls(false);$('power').textContent='เริ่มเสียง';$('engine-state').textContent='ปิดเสียง';$('engine-state').classList.remove('on');status('ปิดเสียงแล้ว');}
    else {status('กำลังโหลด WASM และ bank…');await synth.load(bank,wave);controls(true);$('power').textContent='ปิดเสียง';$('engine-state').textContent=`${synth.context.sampleRate.toLocaleString()} Hz`; $('engine-state').classList.add('on');status('พร้อมเล่น MIDI · หน้าจอเครื่องปิดอยู่');}
  }catch(error){status(error.message,true);controls(false);}finally{$('power').disabled=false;}
};
$('test-note').onclick=()=>{const now=synth.context.currentTime;synth.send([0x90,60,100],now+.02);synth.send([0x80,60,0],now+.7);status('เล่นโน้ต C4');};
$('demo').onclick=async()=>{try{const response=await fetch('./demo.mid');if(!response.ok)throw new Error('โหลดเพลงทดสอบไม่สำเร็จ');song=parseMidi(await response.arrayBuffer());$('song-name').textContent='Demo · 4 MIDI parts';$('play').disabled=false;await synth.resume();startTime=synth.play(song.events,song.duration);playing=true;paused=false;$('pause').disabled=false;$('pause').textContent='พัก';status('กำลังเล่นเพลงทดสอบ 4 ช่อง');}catch(error){status(error.message,true);}};
$('panic').onclick=async()=>{synth.panic();await synth.resume();playing=false;paused=false;$('pause').disabled=true;$('pause').textContent='พัก';status('หยุดทุกโน้ตแล้ว');};
$('midi-file').onchange=async event=>{const file=event.target.files[0];if(!file)return;try{if(file.size>20*1024*1024)throw new Error('เลือกไฟล์ MIDI ขนาดไม่เกิน 20 MB');song=parseMidi(await file.arrayBuffer());$('song-name').textContent=file.name;$('play').disabled=false;status(`${song.tracks} tracks · ${song.events.length.toLocaleString()} events · ${formatTime(song.duration)}`);}catch(error){song=null;$('play').disabled=true;status(error.message,true);} };
$('play').onclick=async()=>{if(!song)return;await synth.resume();startTime=synth.play(song.events,song.duration);playing=true;paused=false;$('pause').textContent='พัก';$('pause').disabled=false;status('กำลังเล่นเพลง');};
$('pause').onclick=async()=>{if(!playing)return;if(paused){await synth.resume();status('กำลังเล่นเพลง');}else{await synth.pause();status('พักเพลง');}paused=!paused;$('pause').textContent=paused?'เล่นต่อ':'พัก';};
$('stop').onclick=async()=>{synth.panic();await synth.resume();playing=false;paused=false;$('pause').disabled=true;$('pause').textContent='พัก';$('progress').value=0;$('song-time').textContent='0:00';status('หยุดเพลงแล้ว');};
synth.addEventListener('ended',()=>{playing=false;$('pause').disabled=true;$('progress').value=1;status('เล่นเพลงจบแล้ว');});
synth.addEventListener('error',event=>status(event.detail.message,true));
function refreshInputs(){const selected=$('midi-input').value;$('midi-input').replaceChildren(new Option('เลือก MIDI input',''));for(const device of midi.inputs.values())$('midi-input').add(new Option(device.name||device.id,device.id));$('midi-input').disabled=false;if([...midi.inputs.values()].some(device=>device.id===selected))$('midi-input').value=selected;}
$('connect-midi').onclick=async()=>{try{if(!navigator.requestMIDIAccess)throw new Error('เบราว์เซอร์นี้ไม่มี Web MIDI ใช้ไฟล์ MIDI หรือคีย์บอร์ดบนหน้าจอได้');midi=await navigator.requestMIDIAccess({sysex:$('allow-sysex').checked});midi.onstatechange=()=>{if(input?.state==='disconnected'){input.onmidimessage=null;input=null;synth.panic();status('MIDI input ถูกถอดออก');}refreshInputs();};refreshInputs();const first=[...midi.inputs.values()][0];if(first){$('midi-input').value=first.id;connectInput();}else status('เปิด MIDI แล้ว ยังไม่พบอุปกรณ์ input');}catch(error){status(error.message,true);}};
function connectInput(){if(input){input.onmidimessage=null;synth.panic();}input=midi.inputs.get($('midi-input').value);if(input){input.onmidimessage=event=>{if(!synth.ready)return;const when=synth.context.currentTime+Math.max(0,(event.timeStamp-performance.now())/1000);synth.send(event.data,when);};status(`รับ MIDI จาก ${input.name}`);}}
$('midi-input').onchange=connectInput;
$('open-editor').onclick=async()=>{if(destroyEditor){$('editor').showModal();return;}$('open-editor').disabled=true;try{const {createEditor}=await import('./editor.mjs');if(!synth.ready)return;destroyEditor=createEditor($('editor-content'),synth);$('editor').showModal();}catch(error){status(error.message,true);}finally{$('open-editor').disabled=!synth.ready;}};
function closeEditor(){if($('editor').open)$('editor').close();if(destroyEditor){destroyEditor();destroyEditor=null;}}
$('close-editor').onclick=closeEditor;$('editor').addEventListener('cancel',event=>{event.preventDefault();closeEditor();});
function formatTime(seconds){seconds=Math.max(0,Math.floor(seconds));return `${Math.floor(seconds/60)}:${String(seconds%60).padStart(2,'0')}`;}
setInterval(()=>{if(playing&&song&&synth.context){const elapsed=Math.max(0,synth.context.currentTime-startTime);$('progress').value=Math.min(1,elapsed/Math.max(.01,song.duration));$('song-time').textContent=`${formatTime(elapsed)} / ${formatTime(song.duration)}`;}},200);
window.addEventListener('pagehide',()=>synth.close());
defaults();
