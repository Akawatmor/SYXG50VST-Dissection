const names = ['Piano','Chromatic percussion','Organ','Guitar','Bass','Strings','Ensemble','Brass','Reed','Pipe','Synth lead','Synth pad','Synth effects','Ethnic','Percussive','Sound effects'];
const keyMap = 'awsedftgyhujkolp;';

export function createEditor(container, synth) {
  container.innerHTML = `<div class="original-panel" role="img" aria-label="หน้าจอ S-YXG50 จาก bitmap เดิม"><div class="lcd">${Array.from({length:18},()=>'<i class="meter"></i>').join('')}</div><div class="polyphony">0</div><button class="panel-setup" aria-label="แสดงหรือซ่อนการตั้งค่า">Setup</button></div>
    <div class="editor-grid"><label>Part<select id="part">${Array.from({length:16},(_,i)=>`<option value="${i}">${i+1}${i===9?' · Drums':''}</option>`).join('')}</select></label>
    <label>Program<select id="program">${Array.from({length:128},(_,i)=>`<option value="${i}">${String(i+1).padStart(3,'0')} · ${names[Math.floor(i/8)]} ${i%8+1}</option>`).join('')}</select></label>
    <label>Bank MSB<input id="msb" type="number" min="0" max="127" value="0"></label><label>Bank LSB<input id="lsb" type="number" min="0" max="127" value="0"></label>
    <label>Volume<input id="volume" type="range" min="0" max="127" value="100"></label><label>Pan<input id="pan" type="range" min="0" max="127" value="64"></label>
    <label>Expression<input id="expression" type="range" min="0" max="127" value="127"></label><label>Pitch bend<input id="bend" type="range" min="0" max="16383" value="8192"></label>
    <label>Reverb send<input id="reverb" type="range" min="0" max="127" value="40"></label><label>Chorus send<input id="chorus" type="range" min="0" max="127" value="0"></label></div>
    <div class="editor-actions"><label><input type="checkbox" id="sustain"> Sustain</label><label><input type="checkbox" id="effects" checked> Effects</label><button id="xg-reset">XG reset</button></div>
    <label class="volume-row">Master<input id="master" type="range" min="0" max="100" value="80"></label><div class="keyboard" aria-label="คีย์บอร์ดโน้ต"></div><p class="key-hint">คีย์ A–; · โน้ต C4–E5 · velocity 100</p>
    <p class="editor-notice">ใช้ภาพหน้าจอจาก resource ของ DLL ส่วนควบคุมเชื่อมกับ engine บนเว็บ เสียงและ effect chain ยังอยู่ระหว่างตรวจความตรงกับต้นฉบับ</p>`;
  let part = 0, latest = null;
  const held = new Map();
  const query = id => container.querySelector(`#${id}`);
  query('master').value = synth.master * 100;
  query('effects').checked = synth.effects;
  const send = data => synth.send(data);
  const cc = (control, value) => send([0xb0|part,control,Number(value)]);
  query('part').onchange = event => { releaseKeys(); part = Number(event.target.value); sync(); };
  query('program').onchange = event => send([0xc0|part,Number(event.target.value)]);
  for (const [id, number] of Object.entries({msb:0,lsb:32,volume:7,pan:10,expression:11,reverb:91,chorus:93})) {
    query(id).oninput = event => { const value = Number(event.target.value); if (Number.isInteger(value) && value>=0 && value<=127) cc(number,value); };
  }
  query('bend').oninput = event => { const value=Number(event.target.value); send([0xe0|part,value&127,value>>7]); };
  query('bend').ondblclick = () => { query('bend').value=8192; send([0xe0|part,0,64]); };
  query('sustain').onchange = event => cc(64,event.target.checked?127:0);
  query('effects').onchange = event => synth.setEffects(event.target.checked);
  query('master').oninput = event => synth.setMaster(Number(event.target.value)/100);
  query('xg-reset').onclick = () => { releaseKeys(); send([0xf0,0x43,0x10,0x4c,0,0,0x7e,0,0xf7]); synth.setMaster(0.8); query('master').value=80; };
  container.querySelector('.panel-setup').onclick = () => { container.querySelector('.editor-grid').hidden = !container.querySelector('.editor-grid').hidden; };
  const keyboard = container.querySelector('.keyboard');
  for (let note=60;note<=76;note++) {
    const button=document.createElement('button');
    button.type='button'; button.dataset.note=String(note); button.setAttribute('aria-label',`โน้ต ${note}`);
    button.className=[1,3,6,8,10].includes(note%12)?'black':'';
    button.textContent=keyMap[note-60]?.toUpperCase()||'';
    button.onpointerdown=event=>{ event.preventDefault(); button.setPointerCapture(event.pointerId); down(`p${event.pointerId}`,note); };
    button.onpointerup=event=>up(`p${event.pointerId}`);
    button.onpointercancel=button.onpointerup;
    keyboard.append(button);
  }
  function down(key,note) { if(held.has(key))return; held.set(key,{note,part}); send([0x90|part,note,100]); keyboard.querySelector(`[data-note="${note}"]`)?.classList.add('active'); }
  function up(key) { const value=held.get(key); if(!value)return; send([0x80|value.part,value.note,0]); held.delete(key); if(![...held.values()].some(item=>item.note===value.note))keyboard.querySelector(`[data-note="${value.note}"]`)?.classList.remove('active'); }
  function releaseKeys() { for(const key of [...held.keys()])up(key); }
  function keydown(event) { if(event.repeat||event.ctrlKey||event.metaKey||/INPUT|SELECT|TEXTAREA/.test(event.target.tagName))return; const index=keyMap.indexOf(event.key.toLowerCase()); if(index>=0){event.preventDefault();down(event.code,60+index);} }
  function keyup(event) { up(event.code); }
  function sync() { if(!latest)return; const state=latest.channels[part]; for(const [id,index] of Object.entries({program:0,volume:1,expression:2,pan:3,bend:5,msb:6,lsb:7,reverb:9,chorus:10})) if(document.activeElement!==query(id))query(id).value=state[index]; query('sustain').checked=Boolean(state[4]); }
  function meters(event) {
    latest=event.detail; sync();
    container.querySelector('.polyphony').textContent=latest.voices;
    const bars=container.querySelectorAll('.meter');
    for(let index=0;index<16;index++)bars[index].style.height=`${Math.min(29,latest.channels[index][11]*5)}px`;
    bars[16].style.height=`${Math.min(29,latest.peak[0]*80)}px`; bars[17].style.height=`${Math.min(29,latest.peak[1]*80)}px`;
  }
  document.addEventListener('keydown',keydown); document.addEventListener('keyup',keyup); window.addEventListener('blur',releaseKeys);
  synth.addEventListener('meters',meters); synth.setTelemetry(true);
  return ()=>{ releaseKeys(); document.removeEventListener('keydown',keydown); document.removeEventListener('keyup',keyup); window.removeEventListener('blur',releaseKeys); synth.removeEventListener('meters',meters); synth.setTelemetry(false); container.replaceChildren(); };
}
