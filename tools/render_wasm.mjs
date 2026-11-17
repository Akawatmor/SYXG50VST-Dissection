import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const args = process.argv.slice(2);
if (args.length < 3 || args.length > 7) {
  throw new Error('Usage: node render_wasm.mjs bank.tbl wave.tbl output.f32 [note=60] [velocity=100] [program=0] [rate=44100]');
}
const [bankPath, wavePath, outputPath] = args;
const note = Number(args[3] ?? 60);
const velocity = Number(args[4] ?? 100);
const program = Number(args[5] ?? 0);
const rate = Number(args[6] ?? 44100);
const { instance } = await WebAssembly.instantiate(fs.readFileSync(path.join(root, 'build/syxg_core.wasm')));
const core = instance.exports;
const bank = fs.readFileSync(bankPath);
const wave = fs.readFileSync(wavePath);
if (bank.length !== core.sxg_bank_capacity() || wave.length !== core.sxg_wave_capacity()) {
  throw new Error('Input lengths do not match the supported bank');
}
const memory = new Uint8Array(core.memory.buffer);
memory.set(bank, core.sxg_bank_buffer());
memory.set(wave, core.sxg_wave_buffer());
function check(result, operation) {
  if (result !== 0) throw new Error(`${operation} returned ${result}`);
}
check(core.sxg_init(bank.length, wave.length, rate), 'init');
check(core.sxg_midi(0xc0, program, 0), 'program');
const noteOn = Math.floor(Math.floor(rate / 4) / 128) * 128;
const noteOff = Math.floor(Math.floor(rate * 5 / 4) / 128) * 128;
const total = rate * 4;
const pcm = Buffer.alloc(total * 2 * 4);
for (let position = 0; position < total; position += 128) {
  const frames = Math.min(128, total - position);
  if (position === noteOn) check(core.sxg_midi(0x90, note, velocity), 'note on');
  if (position === noteOff) check(core.sxg_midi(0x80, note, 0), 'note off');
  check(core.sxg_render(frames), 'render');
  const samples = new Uint8Array(core.memory.buffer, core.sxg_output_buffer(), frames * 2 * 4);
  pcm.set(samples, position * 2 * 4);
}
fs.writeFileSync(outputPath, pcm);
console.log(`layers=${core.sxg_layer_count()} rate=${rate} frames=${total}`);
for (let index = 0; index < core.sxg_layer_count(); index++) {
  console.log(JSON.stringify({ layer: index, record: core.sxg_layer_info(index, 0),
    start: core.sxg_layer_info(index, 1), base: core.sxg_layer_info(index, 2),
    end: core.sxg_layer_info(index, 3), bytes: core.sxg_layer_info(index, 4),
    root: core.sxg_layer_info(index, 5), flags: core.sxg_layer_info(index, 6) }));
}
