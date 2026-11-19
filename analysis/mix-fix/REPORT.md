# Effects, release and percussion balance revision

The user reported effects/release masking the music and unnatural drum effects. This revision adjusts the provisional renderer; it does not claim original DLL acoustic fidelity.

Confirmed implementation issues:

- The wet buses received the full mono sample while each center-panned dry channel received half. Reverb also had undamped feedback and comparatively high wet returns. Sends now use the center dry level, returns/feedback are reduced, and feedback has high-frequency damping.
- Drum record bytes 5/6 were ignored. The supplied DLL decompilation `analysis/step3/decompiled/10016620.c` scales part sends by these drum fields (product shifted right seven). The renderer now applies these bank-specific factors divided by 128. This is a recovered routing detail; the reverb/chorus algorithms remain provisional.
- Chorus delay was truncated to integer samples, causing moving read-position jumps. It now interpolates neighboring samples.
- Exclusive-group percussion choking used the ordinary 80 ms half-life. It now fades with a provisional 3 ms half-life. Normal release is provisionally shortened to 35 ms. These constants are listening-oriented adjustments, not decoded Yamaha AEG values.
- Sustain Off incorrectly released drum voices even when their bank flag said to ignore Note Off. The flag is now respected. Existing natural decay continues during release instead of being replaced by a potentially slower release multiplier. One-shots use their sample's decay; looped percussion retains a provisional note-dependent decay.

`python tools/test_mix_balance.py` renders identical events using the preserved previous native library and current native library. It compares dry and effects-enabled PCM, checks unchanged held melodic levels, shorter release tails, percussion send scaling, open-hat choking, sustain-off behavior and no clipping in the test mix. It writes `before.wav`, `after.wav` and `results.json` here. These are controlled fixtures, not the user's MIDI song.

For programs 0/40/80 with both sends at 127, wet-difference RMS relative to dry falls from approximately 41–47% to 13–14%. Dry release RMS measured 150–300 ms after Note Off falls by approximately 18 dB. Held dry melodic RMS is unchanged. These measurements are specific to the fixtures, not a guarantee for all instruments or songs.

Also rerun the existing primitive/DLL evidence checks, five native/WASM comparisons, multichannel native/WASM sequence and all 16 Phase 6–7 test groups. Full DLL PCM fidelity remains false. Original source DLL/TBL hashes remain unchanged. Updated runtime ZIP includes this report and the measured JSON; the old ZIP is retained as `build/syxg50-web-before-mix.zip` for rollback.

Reload the page and restart the audio engine to instantiate the new WASM. The client requests WASM with `cache: no-store` to avoid a stale compiled module after updates. Editor remains closed until requested.

The original `syxg50-web.zip` was locked when packaging, so the corrected delivery is `build/syxg50-web-mix2.zip`. Build with `python tools/package_web.py --output build/syxg50-web-mix2.zip`. Existing workspace WASM is updated as well.
