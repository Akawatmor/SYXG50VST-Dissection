"""Verify recovered kernels, compare native/Wasm, and measure remaining DLL differences."""
from pathlib import Path
import array
import ctypes
import hashlib
import json
import math
import struct
import subprocess
import wave

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / "build"
ANALYSIS = ROOT / "analysis/step3"


def floats(data):
    values = array.array("f")
    values.frombytes(data)
    return values


def rms(values):
    return math.sqrt(sum(float(x) ** 2 for x in values) / len(values))


def main():
    library = ctypes.CDLL(str(OUT/"syxg_core.dll"))
    library.sxg_envelope_gain.restype = ctypes.c_double
    for name in ("sxg_bank_buffer", "sxg_wave_buffer", "sxg_output_buffer", "sxg_oscillator_output"):
        getattr(library, name).restype = ctypes.c_void_p
    bank = (ROOT/"dll/legacy/sxgbin41.tbl").read_bytes()
    encoded_wave = (ROOT/"dll/legacy/Sxgwave4.tbl").read_bytes()
    checks = {"render_before_init_rejected": library.sxg_render(128) == 5}
    checks["analysis_capture_preserves_reference_pcm"] = (ANALYSIS/"legacy-dump.float.wav").read_bytes() == (ROOT/"reference/legacy-note-a.float.wav").read_bytes()
    ctypes.memmove(library.sxg_bank_buffer(), bank, len(bank))
    ctypes.memmove(library.sxg_wave_buffer(), encoded_wave, len(encoded_wave))
    checks["init_succeeds"] = library.sxg_init(len(bank), len(encoded_wave), 44100) == 0
    decoded = ctypes.string_at(library.sxg_wave_buffer(), len(encoded_wave))
    checks["full_wave_matches_original_memory"] = decoded == (ANALYSIS/"legacy-dump-bank2-full.bin").read_bytes()
    checks["zero_frames_rejected"] = library.sxg_render(0) == 1
    checks["oversized_render_rejected"] = library.sxg_render(4097) == 1
    checks["second_channel_supported"] = library.sxg_midi(0x91, 60, 100) == 0
    library.sxg_reset()
    checks["invalid_midi_rejected"] = library.sxg_midi(0x90, 128, 100) == 1
    checks["silence_render_succeeds"] = library.sxg_render(128) == 0
    checks["silence_is_zero"] = not any(ctypes.string_at(library.sxg_output_buffer(), 128*8))
    kernels = {}
    for variant in ("", "-wrap", "-carry"):
        stem = str(ANALYSIS/("legacy-dump-oscillator"+variant))
        seed = struct.unpack("<6i", Path(stem+"-seed.bin").read_bytes())
        status = library.sxg_probe_oscillator8(*seed, 128)
        actual = ctypes.string_at(library.sxg_oscillator_output(), 512)
        final = struct.unpack("<2i", Path(stem+"-final.bin").read_bytes())
        kernels[variant or "attack"] = {
            "status": status,
            "samples_bit_identical_to_original_kernel": actual == Path(stem+"-expected.i32").read_bytes(),
            "position_matches": library.sxg_oscillator_position() == final[0],
            "fraction_matches": library.sxg_oscillator_fraction() == final[1],
        }
    checks["native_kernel_matches_original"] = all(result["status"] == 0 and all(value for key, value in result.items() if key != "status") for result in kernels.values())
    gain_cases = list(struct.iter_unpack("<if", (ANALYSIS/"legacy-dump-envelope-gain.bin").read_bytes()))
    checks["envelope_gain_matches_original"] = all(struct.pack("<f", library.sxg_envelope_gain(value)) == struct.pack("<f", expected) for value, expected in gain_cases)
    checks["baseline_note_selection_succeeds"] = library.sxg_midi(0xC0, 0, 0) == 0 and library.sxg_midi(0x90, 60, 100) == 0
    baseline_seed = struct.unpack("<6i", (ANALYSIS/"legacy-dump-oscillator-seed.bin").read_bytes())
    mapping = {name: library.sxg_layer_info(0, index) for index, name in enumerate(
        ("wave_record_offset", "sample_start", "sample_base", "sample_end", "bytes_per_sample", "root_key", "flags", "step_q15"))}
    checks["baseline_sample_base_matches_live_voice"] = mapping["sample_base"] == baseline_seed[0]
    checks["baseline_loop_length_matches_live_voice"] = mapping["sample_end"] - mapping["sample_base"] == baseline_seed[1]
    checks["baseline_pitch_step_matches_live_voice"] = mapping["step_q15"] == baseline_seed[5]
    (ANALYSIS/"note60-mapping.json").write_text(json.dumps(mapping, indent=2), encoding="utf-8")
    subprocess.run(["node", str(ROOT/"tools/verify_wasm.mjs")], check=True, cwd=ROOT)
    wasm_checks = json.loads((ANALYSIS/"wasm-verification.json").read_text())
    cases = [
        ("note60", 60, 100, 0, 44100, "legacy-note-a"),
        ("note72", 72, 100, 0, 44100, "legacy-note72"),
        ("velocity40", 60, 40, 0, 44100, "legacy-velocity40"),
        ("program40", 60, 100, 40, 44100, "legacy-program40"),
        ("48000", 60, 100, 0, 48000, "legacy-48000"),
    ]
    results = {}
    for name, note, velocity, program, rate, reference in cases:
        native_path, wasm_path = OUT/("native-"+name+".f32"), OUT/("wasm-"+name+".f32")
        arguments = [str(ROOT/"dll/legacy/sxgbin41.tbl"), str(ROOT/"dll/legacy/Sxgwave4.tbl")]
        controls = list(map(str, (note, velocity, program, rate)))
        native = subprocess.run([str(OUT/"render_native.exe"), *arguments, str(native_path), *controls], capture_output=True, text=True, check=True)
        wasm_result = subprocess.run(["node", str(ROOT/"tools/render_wasm.mjs"), *arguments, str(wasm_path), *controls], capture_output=True, text=True, check=True)
        (OUT/(name+".native.log")).write_text(native.stdout)
        (OUT/(name+".wasm.log")).write_text(wasm_result.stdout)
        data, wasm_data = native_path.read_bytes(), wasm_path.read_bytes()
        actual = floats(data)
        reference_data = (ROOT/("reference/"+reference+".float.wav")).read_bytes()[44:]
        original = floats(reference_data)
        if len(data) != rate*4*8 or not all(math.isfinite(x) for x in actual):
            raise RuntimeError("Invalid output "+name)
        difference = [float(a)-float(b) for a, b in zip(actual, original)]
        results[name] = {
            "native_wasm_bit_identical": data == wasm_data,
            "pcm_sha256": hashlib.sha256(data).hexdigest(),
            "native_rms": rms(actual), "original_rms": rms(original),
            "original_rms_difference": rms(difference),
            "original_max_abs_difference": max(map(abs, difference)),
            "original_bit_identical": data == reference_data,
        }
        pcm16 = array.array("h", (round(max(-1, min(1, x))*32767) for x in actual))
        with wave.open(str(OUT/("native-"+name+".wav")), "wb") as file:
            file.setnchannels(2)
            file.setsampwidth(2)
            file.setframerate(rate)
            file.writeframes(pcm16.tobytes())
    checks["native_wasm_match_all_five_cases"] = all(row["native_wasm_bit_identical"] for row in results.values())
    manifest = json.loads((ROOT/"analysis/evidence/input-manifest.json").read_text())
    checks["all_original_input_hashes_unchanged"] = all(hashlib.sha256((ROOT/item["path"]).read_bytes()).hexdigest() == item["sha256"] for item in manifest)
    report = {
        "checks": checks, "native_kernels": kernels, "wasm": wasm_checks, "audio_cases": results,
        "full_dll_audio_fidelity_passed": all(row["original_bit_identical"] for row in results.values()),
        "provisional_dsp": ["pitch setup beyond the validated note", "amplifier gain", "amplitude envelope", "filter", "effects", "legacy MIDI scheduling"],
    }
    (ANALYSIS/"port-verification.json").write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps(report, indent=2))
    if not all(checks.values()):
        raise SystemExit("Port verification failed")


if __name__ == "__main__":
    main()
