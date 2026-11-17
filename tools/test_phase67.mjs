import fs from 'node:fs';
import assert from 'node:assert/strict';
import vm from 'node:vm';
import { performance } from 'node:perf_hooks';
import { parseMidi } from '../web/midi-file.mjs';

const module = await WebAssembly.compile(fs.readFileSync('build/syxg_core.wasm'));
const bank = fs.readFileSync('dll/legacy/sxgbin41.tbl');
const wave = fs.readFileSync('dll/legacy/Sxgwave4.tbl');
const core = new WebAssembly.Instance(module).exports;
const bytes = new Uint8Array(core.memory.buffer);
bytes.set(bank,core.sxg_bank_buffer()); bytes.set(wave,core.sxg_wave_buffer());
assert.equal(core.sxg_init(bank.length,wave.length,48000),0);
const checks = {};
function check(name, fn) { fn(); checks[name] = true; }
const midi=(...args)=>assert.equal(core.sxg_midi(...args),0);
const pcm=()=>new Float32Array(core.memory.buffer,core.sxg_output_buffer(),256);
const render=(blocks=1)=>{for(let i=0;i<blocks;i++)assert.equal(core.sxg_render(128),0);};
const reset=()=>{core.sxg_reset();core.sxg_set_effects(0);};
check('sixteen_channels',()=>{reset();for(let ch=0;ch<16;ch++)midi(0x90|ch,ch===9?36:60,100);assert.ok(core.sxg_active_voices()>=16);render();assert.ok(pcm().some(x=>x!==0));});
check('all_128_programs_three_keys',()=>{for(let program=0;program<128;program++)for(const note of [36,60,84]){reset();midi(0xc0,program,0);midi(0x90,note,100);let audible=false;for(let block=0;block<32;block++){render();assert.ok(pcm().every(Number.isFinite));audible ||= pcm().some(x=>x!==0);}assert.ok(audible,`${program}:${note}`);}});
check('gm_drums_35_to_81',()=>{for(let note=35;note<=81;note++){reset();midi(0x99,note,100);render();assert.ok(pcm().some(x=>x!==0),String(note));}});
check('voice_stealing_bounded',()=>{reset();for(let n=0;n<200;n++)midi(0x90,36+n%60,80);assert.equal(core.sxg_active_voices(),128);render(100);assert.ok(pcm().every(x=>Number.isFinite(x)&&Math.abs(x)<=1));});
check('sustain_and_release',()=>{reset();midi(0x90,60,100);midi(0xb0,64,127);midi(0x80,60,0);render(400);assert.ok(core.sxg_active_voices()>0);midi(0xb0,64,0);render(800);assert.equal(core.sxg_active_voices(),0);});
check('pan_and_volume',()=>{reset();midi(0xb0,10,0);midi(0x90,60,100);render();let a=0,b=0;pcm().forEach((x,i)=>i%2?b+=x*x:a+=x*x);assert.ok(a>b*100);midi(0xb0,7,0);render();assert.ok(pcm().every(x=>x===0));});
check('rpn_pitchbend_and_reset',()=>{reset();midi(0xb0,101,0);midi(0xb0,100,0);midi(0xb0,6,12);midi(0xe0,127,127);assert.equal(core.sxg_channel_info(0,5),16383);midi(0xb0,121,0);assert.equal(core.sxg_channel_info(0,5),8192);});
check('xg_reset_sysex',()=>{midi(0xc0,40,0);bytes.set([0xf0,0x43,0x10,0x4c,0,0,0x7e,0,0xf7],core.sxg_sysex_buffer());assert.equal(core.sxg_sysex(9),0);assert.equal(core.sxg_channel_info(0,0),0);assert.equal(core.sxg_active_voices(),0);});

const chunk=(tag,data)=>Buffer.concat([Buffer.from(tag),Buffer.from([data.length>>>24,data.length>>>16&255,data.length>>>8&255,data.length&255]),Buffer.from(data)]);
const smf=(tracks,format=0,division=480)=>Buffer.concat([chunk('MThd',[0,format,0,tracks.length,division>>>8,division&255]),...tracks.map(t=>chunk('MTrk',t))]);
const notes=[0,0x90,60,100,0x83,0x60,60,0,0,0xff,0x2f,0];
check('smf_running_status_and_tempo',()=>{const song=parseMidi(smf([notes]));assert.equal(song.events.length,2);assert.equal(song.duration,.5);assert.equal(song.events[1].data[0],0x90);});
check('smf_format1_tempo_merge',()=>{const song=parseMidi(smf([[0,0xff,0x51,3,0x0f,0x42,0x40,0,0xff,0x2f,0],notes],1));assert.equal(song.duration,1);});
check('smf_smpte',()=>{assert.equal(parseMidi(smf([[0,0x90,60,100,100,0x80,60,0,0,0xff,0x2f,0]],0,0xe728)).duration,.1);});
check('smf_rejects_malformed_tracks',()=>{assert.throws(()=>parseMidi(smf([[0,0xff,0x2f,10],[0,0xff,0x2f,0]],1)));assert.throws(()=>parseMidi(smf([notes],2)));assert.throws(()=>parseMidi(Buffer.from('bad')));});
const demo=smf([[0,0xc0,0,0,0x90,60,90,0,0x91,64,80,0,0x92,67,80,0,0x99,36,100,0x83,0x60,0x80,60,0,0,0x81,64,0,0,0x82,67,0,0x83,0x60,0xff,0x2f,0]]);
fs.writeFileSync('build/demo.mid',demo);

let Processor;
const messages=[];
const scope=vm.createContext({WebAssembly,Float32Array,Uint8Array,sampleRate:48000,currentFrame:0,
 AudioWorkletProcessor:class{constructor(){this.port={postMessage:m=>messages.push(structuredClone(m))};}},
 registerProcessor:(name,ctor)=>{assert.equal(name,'syxg50');Processor=ctor;}});
vm.runInContext(fs.readFileSync('web/synth-worklet.js','utf8'),scope);
const worklet=new Processor();
worklet.receive({type:'init',module,bank:bank.buffer.slice(bank.byteOffset,bank.byteOffset+bank.length),wave:wave.buffer.slice(wave.byteOffset,wave.byteOffset+wave.length)});
check('worklet_ready_editor_telemetry_off',()=>{assert.equal(messages[0].type,'ready');assert.equal(worklet.telemetry,false);});
check('worklet_event_at_sample_37',()=>{worklet.receive({type:'effects',enabled:false});worklet.receive({type:'events',events:[{frame:37,data:[0x90,60,100]}]});const out=[new Float32Array(128),new Float32Array(128)];worklet.process([], [out]);assert.ok(out[0].slice(0,37).every(x=>x===0));assert.ok(out[0].slice(38).some(x=>x!==0));});
check('worklet_variable_block_and_panic',()=>{scope.currentFrame=128;worklet.receive({type:'events',events:[{frame:200,data:[0x91,64,100]}]});worklet.process([],[[new Float32Array(256),new Float32Array(256)]]);assert.ok(worklet.core.sxg_channel_info(1,11)>0);worklet.receive({type:'panic'});assert.equal(worklet.core.sxg_active_voices(),0);assert.equal(worklet.queue.length,0);});
check('worklet_end_and_optional_telemetry',()=>{scope.currentFrame=384;worklet.receive({type:'events',events:[{frame:384,data:[0x90,60,100]}],endFrame:512});worklet.process([],[[new Float32Array(128),new Float32Array(128)]]);assert.ok(messages.some(m=>m.type==='ended'));worklet.receive({type:'telemetry',enabled:true});for(let n=0;n<32;n++){scope.currentFrame+=128;worklet.process([],[[new Float32Array(128),new Float32Array(128)]]);}assert.equal(messages.find(m=>m.type==='meters').channels.length,16);worklet.receive({type:'telemetry',enabled:false});});
reset();for(let n=0;n<128;n++)midi(0x90,48+n%36,70);core.sxg_set_effects(1);
const start=performance.now();render(375);const elapsed=performance.now()-start;
const report={checks,passed:Object.keys(checks).length,wasm_bytes:fs.statSync('build/syxg_core.wasm').size,benchmark:{voices:128,audio_seconds:1,render_ms:elapsed,realtime_factor:elapsed/1000,environment:'Node WASM on this machine; excludes browser scheduling'},full_dll_audio_fidelity_passed:false};
fs.writeFileSync('analysis/phase67-tests.json',JSON.stringify(report,null,2));console.log(JSON.stringify(report,null,2));
