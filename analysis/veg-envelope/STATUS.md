# VEG-derived envelope port — validated component, integration unfinished

The requested full original-engine effect/envelope port is **not complete**. This checkpoint contains a separately compiled envelope component and direct original-DLL reference fixtures. The playback engine, browser UI and runtime ZIP have not been updated by this work. No new guessed release time, effect coefficient or gain adjustment has been introduced into playback.

## Recovered and tested

`port/syxg_veg_envelope.c` translates VEG RVAs 0x18CF0 (parameter update), 0x18EA0 (initialization), and 0x18FE0 (state stepping), including the supporting gain conversion, inverse conversion and integer advance. Three 128-entry int32 tables are captured from the pointers in an actual VEG voice at each tested sample rate, rather than regenerated from guessed curves.

The assembly is authoritative where the decompiler omitted floating-point operands: 0x195D0 takes a float argument from the stack; the linear paths use constants at 0x48DD4/0x48DDC (2^-20 and 2^-19 respectively). These are original binary constants, not tuning choices. The state layout preserves flags, stage, current/target values, both rates, auxiliary attack value, gain/next gain, slope and intercept.

The oracle loads the supplied VEG DLL unchanged using the existing x86 VST host, starts an actual voice, copies its state and parameters, and calls original internal functions on the copy. It does not patch the DLL, and it leaves the live voice unmodified. The initial incorrectly resolved pointer during development caused a test-host crash; the corrected pointer path follows core +0x10 -> renderer +0x0C -> manager +0x0C -> voice pool.

At each of 44,100/48,000 Hz, 9,156 fixture cases exercise all 256 initial-rate bytes, all 256 end-rate bytes for initial rates 0/1, selected boundary end rates for other initial rates, three target values (0/32/127), and an in-flight target update. Each case compares initialization and 24 updates, giving 228,900 state snapshots per rate. All 12 words of every snapshot match VEG bit-for-bit in both the native component and the WASM component. This is broad branch/table coverage, not exhaustive coverage of every possible envelope input or song state.

Results: `verification-44100.json`, `verification-48000.json`, `wasm-verification-44100.json`, `wasm-verification-48000.json`. Raw tables, source voice/parameter snapshots and expected states are adjacent. The WASM component has no imports. Its buffers must be initialized with the captured original tables and validated parameter state before use.

## Full-song original reference

`analysis/veg-song/50938-source.json` records the supplied song's hash and event conversion. The isolated original host now accepts an ordered short-MIDI event sequence with sample offsets, preserving the original VST wrapper's own event scheduling. This path explicitly rejects SysEx rather than dropping it. The supplied file has no SysEx.

`analysis/veg-song/50938-veg.float.wav` is VEG's original output at 44,100 Hz with 128-frame host callbacks and four seconds after the final event. It contains 7,155,225 stereo frames. A fresh second VEG process produces identical float PCM. Legacy differs from VEG starting at frame 88,193 (approximately 1.99984 seconds), so the earlier single-note legacy equivalence must not be generalized to the song. The cause of this difference has not been established.

Original VEG float output peaks above unity (approximately 2.774), so its PCM16 listening WAV is clipped by the reference host's format conversion. Use the float WAV for analysis; no normalization has been applied. Do not infer original mixing rules from the PCM16 file.

## Work still required

1. Port the original bank/MIDI-to-voice parameter construction and gate/Note Off transitions. The captured parameter block is already a compiled per-voice state, not a raw bank element. Feeding raw bank bytes to the validated component would be incorrect.
2. Confirm the original envelope tick cadence and per-block gain interpolation in the render kernels before replacing playback's provisional envelope.
3. Recover effect algorithm selection, coefficient/delay tables, state updates and complete routing. The original effect manager at 0x1F870 has multiple buses, active/tail flags and function-pointer dispatch; initialization at 0x1BF00 and CPU-path selection at 0x1C120 select different implementations. The current simplified reverb/chorus are not this chain.
4. Verify drums/program 32 and unusual percussion notes against actual VEG voices in the attached song.
5. Integrate only after component and song comparisons support it. Full DLL PCM fidelity is not established by the isolated envelope tests.

## Reproduce

```powershell
python tools/capture_veg_envelope.py
python tools/build_veg_envelope.py
python tools/verify_veg_envelope.py 44100
python tools/verify_veg_envelope.py 48000
node tools/verify_veg_envelope.mjs 44100
node tools/verify_veg_envelope.mjs 48000
```

The build uses the existing GCC and local Zig toolchain. On this machine Zig cache operations require execution outside the restricted sandbox. Source DLL/TBL files must remain unchanged.
