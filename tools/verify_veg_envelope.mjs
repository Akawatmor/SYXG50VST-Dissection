import fs from 'node:fs';
import assert from 'node:assert/strict';
const rate=Number(process.argv[2]||44100),stem=`analysis/veg-envelope/veg-${rate}`;
const module=new WebAssembly.Module(fs.readFileSync('build/veg_envelope.wasm'));
assert.deepEqual(WebAssembly.Module.imports(module),[]);
const core=new WebAssembly.Instance(module).exports;
const memory=new Uint8Array(core.memory.buffer),view=new DataView(core.memory.buffer);
const state=core.veg_env_buffer(),params=core.veg_env_parameters();
for(let i=0;i<3;i++)memory.set(fs.readFileSync(`${stem}-rate${i}.bin`),core.veg_env_tables()+i*512);
const original=fs.readFileSync(`${stem}-voice.bin`),fixtures=fs.readFileSync(`${stem}-envelope-fixtures.bin`);
let states=0;
for(let pos=0;pos<fixtures.length;pos+=1212){
 const initial=fixtures.readUInt32LE(pos),end=fixtures.readUInt32LE(pos+4),target=fixtures.readUInt32LE(pos+8);
 memory.set(original.subarray(4,8),state);memory.set(original.subarray(0xc4,0xf0),state+4);
 [initial,target,end,255].forEach((v,i)=>view.setUint32(params+i*4,v,true));view.setUint32(state,3,true);
 core.veg_env_init();
 for(let step=0;step<25;step++){
  if(step){if(step===9){view.setUint32(params+12,32,true);core.veg_env_update();}core.veg_env_tick();}
  const actual=Buffer.from(memory.buffer,state,48),expected=fixtures.subarray(pos+12+step*48,pos+60+step*48);
  assert.ok(actual.equals(expected),`VEG state mismatch: rate ${rate}, case ${initial}/${end}/${target}, step ${step}`);states++;
 }
}
const report={sample_rate:rate,states,all_state_words_bit_identical_to_veg:true,wasm_imports:[],integrated_in_renderer:false};
fs.writeFileSync(`analysis/veg-envelope/wasm-verification-${rate}.json`,JSON.stringify(report,null,2));console.log(report);
