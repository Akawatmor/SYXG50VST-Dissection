import fs from 'node:fs';
import path from 'node:path';
import crypto from 'node:crypto';
import { fileURLToPath } from 'node:url';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const module = await WebAssembly.compile(fs.readFileSync(path.join(root, 'build/syxg_core.wasm')));
const instance = await WebAssembly.instantiate(module);
const core = instance.exports;
const bank = fs.readFileSync(path.join(root, 'dll/legacy/sxgbin41.tbl'));
const wave = fs.readFileSync(path.join(root, 'dll/legacy/Sxgwave4.tbl'));
const memory = new Uint8Array(core.memory.buffer);
memory.set(bank, core.sxg_bank_buffer());
memory.set(wave, core.sxg_wave_buffer());
if (core.sxg_init(bank.length, wave.length, 44100) !== 0) throw new Error('init failed');
const decoded = Buffer.from(core.memory.buffer, core.sxg_wave_buffer(), wave.length);
const hash = value => crypto.createHash('sha256').update(value).digest('hex');
const report = {
  imports: WebAssembly.Module.imports(module),
  decoded_wave_sha256: hash(decoded),
  decoded_wave_matches_dll_memory: decoded.equals(fs.readFileSync(path.join(root, 'analysis/step3/legacy-dump-bank2-full.bin'))),
  kernels: {},
  envelope_gain_matches_original: true,
};
const gainCases = fs.readFileSync(path.join(root, 'analysis/step3/legacy-dump-envelope-gain.bin'));
for (let offset = 0; offset < gainCases.length; offset += 8) {
  const value = gainCases.readInt32LE(offset);
  const expected = gainCases.readFloatLE(offset + 4);
  if (Math.fround(core.sxg_envelope_gain(value)) !== expected) report.envelope_gain_matches_original = false;
}
for (const variant of ['', '-wrap', '-carry']) {
  const stem = path.join(root, `analysis/step3/legacy-dump-oscillator${variant}`);
  const seed = fs.readFileSync(`${stem}-seed.bin`);
  const params = Array.from({ length: 6 }, (_, index) => seed.readInt32LE(index * 4));
  const status = core.sxg_probe_oscillator8(...params, 128);
  if (status !== 0) throw new Error(`kernel ${variant} returned ${status}`);
  const actual = Buffer.from(core.memory.buffer, core.sxg_oscillator_output(), 512);
  const expected = fs.readFileSync(`${stem}-expected.i32`);
  const final = fs.readFileSync(`${stem}-final.bin`);
  report.kernels[variant || 'attack'] = {
    samples_bit_identical_to_original_kernel: actual.equals(expected),
    position_matches: core.sxg_oscillator_position() === final.readInt32LE(0),
    fraction_matches: core.sxg_oscillator_fraction() === final.readUInt32LE(4),
  };
}
const passed = report.imports.length === 0 && report.decoded_wave_matches_dll_memory && report.envelope_gain_matches_original &&
  Object.values(report.kernels).every(result => Object.values(result).every(Boolean));
fs.writeFileSync(path.join(root, 'analysis/step3/wasm-verification.json'), JSON.stringify(report, null, 2));
console.log(JSON.stringify(report, null, 2));
if (!passed) throw new Error('Wasm verification failed');
