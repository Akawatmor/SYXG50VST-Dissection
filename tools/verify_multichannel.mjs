import fs from 'node:fs';
import assert from 'node:assert/strict';
const core = new WebAssembly.Instance(new WebAssembly.Module(fs.readFileSync('build/syxg_core.wasm'))).exports;
const memory=new Uint8Array(core.memory.buffer);
const bank=fs.readFileSync('dll/legacy/sxgbin41.tbl'),wave=fs.readFileSync('dll/legacy/Sxgwave4.tbl');
memory.set(bank,core.sxg_bank_buffer());memory.set(wave,core.sxg_wave_buffer());assert.equal(core.sxg_init(bank.length,wave.length,48000),0);
let position=0;const parts=[];
for(const [frame,event] of [...JSON.parse(fs.readFileSync('build/multichannel-sequence.json')),[48000,null]]){
 while(position<frame){const count=Math.min(128,frame-position);assert.equal(core.sxg_render(count),0);parts.push(Buffer.from(new Uint8Array(core.memory.buffer,core.sxg_output_buffer(),count*8)));position+=count;}
 if(event)assert.equal(core.sxg_midi(...event),0);
}
fs.writeFileSync('build/multichannel-wasm.f32',Buffer.concat(parts));
