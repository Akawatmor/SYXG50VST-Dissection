# Phase 6–7 delivery — 17 November 2026

Delivered a local browser synthesizer around the portable C/WASM core. Phase 6 browser integration and Phase 7's implemented MIDI/editor functionality work in the tests below. **Full legacy engine reconstruction is still incomplete:** the recovered primitives pass, but end-to-end DLL PCM fidelity fails. Do not treat this package as an acoustically faithful replacement for S-YXG50.

## Implementation

- AudioWorklet instantiates WASM and decodes supplied banks before connecting audio output. Events carry absolute audio-frame timestamps; each callback splits rendering at event boundaries. Frame count is taken from the output buffer, rather than assuming every callback has 128 frames. Static C output/memory buffers are reused.
- Sixteen independent channel states and up to 128 sample voices; voice stealing, two-element notes, 8/16-bit wave reads, loop/one-shot playback, drum kits and exclusive groups.
- Sustain, volume, expression, pan, pitch bend/RPN range, modulation, filter controllers, reverb/chorus sends, all notes/sounds off and controller reset. Limited GM/XG/GS resets and part/master SysEx. Unimplemented messages return unsupported.
- SMF format 0/1 parser merges tracks and tempo maps, handles running status and SMPTE division. Events are scheduled on the audio clock. Malformed track boundaries, excess event counts and oversized SysEx are rejected.
- Browser editor uses original resource 111 converted losslessly to PNG. This is a web reconstruction of controls, not a binary port of the Win32 dialog procedure. Editor DOM, keyboard listeners and meter messages are absent/off until requested; closing it leaves the audio engine running.
- Web MIDI is an explicit opt-in. Bank files are served only from localhost by the launcher. No original DLL execution is required for playback.

## Validation evidence

`tools/verify_port.py`: original bank memory, all three oscillator fixture cases (128 int32 samples each, including final state), nine gain values and baseline sample mapping pass. Native/WASM match in the five original audio cases. All original input hashes match their initial manifest.

`tools/verify_multichannel.py`: 48,000 stereo frames, 16 MIDI events including channel 2/3, drum notes, sustain, pitch bend, pan, effect sends and note termination produce bit-identical native/WASM PCM. Exact SHA is in `analysis/multichannel-parity.json`.

`tools/test_phase67.mjs`: 16 test groups pass. Tests render 128 melodic programs on keys 36/60/84 (waiting through sample leading silence), GM drum notes 35–81, 128-voice stealing, sustain/release, pan/mute, RPN state and XG reset. Parser fixtures cover SMF 0/1, running status, tempo merge, SMPTE and malformed inputs. A Node VM executes the actual AudioWorklet source with actual WASM to verify event onset at sample 37, variable callback sizes, panic, transport end and optional meter telemetry.

The Node benchmark renders one second of 128 sample voices with effects. Measured result is stored in `analysis/phase67-tests.json`; the initial run took about 86 ms on this machine. This measures core throughput, not browser deadline compliance, output-device latency, sustained glitch-free playback or other machines.

Chrome was tested through UI automation against localhost: start engine at 48,000 Hz, open original-screen editor, change part/program/sustain, trigger keyboard, close editor, load/play the generated four-part demo through the browser SMF parser and receive transport-ended status. Editor settings hide/show and default-closed behavior were checked. Captured browser console showed no errors. Screenshots: `analysis/phase67-main.jpg` and `analysis/phase67-editor.jpg`.

File selection by the automation extension could not proceed without enabling its file URL permission; that setting was not changed. Physical MIDI devices, the MIDI permission flow and long-duration hardware audio performance were not tested. The built-in demo exercises the same MIDI parser/scheduler without the file chooser.

## Fidelity and remaining limits

Full DLL PCM equality is false in all five comparison cases. Bank decoding and probe kernels are recovered; the complete audible render path still uses provisional gain, pitch setup outside the measured baseline, attack/release/drum decay, filter, vibrato, stereo mixing and effects. The simple reverb/chorus are not recovered Yamaha algorithms. Native/WASM equality proves consistent execution of this implementation; it does not prove equality to the DLL.

The renderer has a 128 **sample-voice** limit; layered notes can consume two slots. Pressure/aftertouch and unknown controllers are unsupported. XG/GS SysEx coverage is partial, with a 1,024-byte message cap. Drum definitions outside the supported bank mapping can return unsupported. Format 2 MIDI is deliberately rejected. Bank/program selection has broad functional coverage, not a DLL acoustic validation for each variation.

To complete a faithful engine port, recover and validate original voice parameter interpretation, pitch/tuning, AEG/FEG/filter/pan and all effect paths, then run the complete reference suite and real MIDI songs against DLL output. This remaining reverse-engineering work is not declared complete by the browser delivery.

## Deliverables

- `build/syxg_core.wasm`: portable freestanding module.
- `build/syxg_core.dll`, `build/render_native.exe`: native verification artifacts.
- `web/`: host page, headless-capable client API, Worklet, MIDI parser and lazy editor.
- `Start S-YXG50.cmd`, `tools/serve_web.py`: local launcher.
- `build/syxg50-web.zip`: local runtime package (requires installed Python and a browser), including the two user-supplied banks, original screen bitmap, WASM, launcher, README, this report and per-file hash manifest. Original DLL and toolchains are excluded.

No deployment, publication or external upload was performed. Original inputs remain unchanged.
