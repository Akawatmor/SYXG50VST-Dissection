"""Build/run the isolated x86 reference host and verify the recorded PCM.

Run from anywhere: python tools/run_reference.py
Uses only the Python standard library and the installed .NET Framework compiler.
"""
from pathlib import Path
import array
import hashlib
import json
import math
import os
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / "reference"
EVIDENCE = ROOT / "analysis" / "evidence"


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def inputs():
    return {p.relative_to(ROOT).as_posix(): {"size": p.stat().st_size, "sha256": sha(p)}
            for p in sorted((ROOT / "dll").rglob("*")) if p.is_file()}


def read_float_wav(path):
    data = path.read_bytes()
    assert data[:4] == b"RIFF" and data[8:12] == b"WAVE"
    pos = 12
    fmt = payload = None
    while pos + 8 <= len(data):
        name, size = struct.unpack_from("<4sI", data, pos)
        body = data[pos + 8:pos + 8 + size]
        if name == b"fmt ":
            fmt = struct.unpack_from("<HHIIHH", body)
        if name == b"data":
            payload = body
        pos += 8 + size + size % 2
    assert fmt is not None and fmt[0] == 3 and fmt[1] == 2 and fmt[5] == 32
    assert payload is not None
    pcm = array.array("f")
    pcm.frombytes(payload)
    if sys.byteorder != "little":
        pcm.byteswap()
    assert all(math.isfinite(x) for x in pcm)
    return fmt[2], pcm, payload


def rms(pcm):
    return math.sqrt(sum(x*x for x in pcm) / len(pcm)) if pcm else 0


def compare(a, b):
    assert len(a) == len(b)
    diffs = [float(x)-float(y) for x, y in zip(a, b)]
    return {"different_samples": sum(x != 0 for x in diffs),
            "max_abs_difference": max(map(abs, diffs), default=0),
            "rms_difference": rms(diffs)}


def main():
    OUT.mkdir(exist_ok=True)
    EVIDENCE.mkdir(parents=True, exist_ok=True)
    before = inputs()
    csc = Path(os.environ.get("WINDIR", r"C:\Windows")) / "Microsoft.NET/Framework/v4.0.30319/csc.exe"
    subprocess.run([str(csc), "/nologo", "/platform:x86", "/optimize+",
                    "/out:"+str(ROOT / "tools/ReferenceHost.exe"),
                    str(ROOT / "tools/ReferenceHost.cs")], check=True, cwd=ROOT)
    # Every case gets a fresh process, fresh plugin instance, and a complete lifecycle.
    cases = [
        ("legacy-note-a", "legacy", "note", 44100, 256, 60, 100, 0, 0, "replacing"),
        ("legacy-note-b", "legacy", "note", 44100, 256, 60, 100, 0, 0, "replacing"),
        ("legacy-note-c", "legacy", "note", 44100, 256, 60, 100, 0, 0, "replacing"),
        ("legacy-silence", "legacy", "silence", 44100, 256, 60, 100, 0, 0, "replacing"),
        ("legacy-hold", "legacy", "hold", 44100, 256, 60, 100, 0, 0, "replacing"),
        ("legacy-process", "legacy", "note", 44100, 256, 60, 100, 0, 0, "process"),
        ("legacy-block64", "legacy", "note", 44100, 64, 60, 100, 0, 0, "replacing"),
        ("legacy-block128", "legacy", "note", 44100, 128, 60, 100, 0, 0, "replacing"),
        ("legacy-block512", "legacy", "note", 44100, 512, 60, 100, 0, 0, "replacing"),
        ("legacy-block257", "legacy", "note", 44100, 257, 60, 100, 0, 0, "replacing"),
        ("legacy-offset64", "legacy", "note", 44100, 256, 60, 100, 0, 64, "replacing"),
        ("legacy-offset127", "legacy", "note", 44100, 256, 60, 100, 0, 127, "replacing"),
        ("legacy-offset128", "legacy", "note", 44100, 256, 60, 100, 0, 128, "replacing"),
        ("legacy-velocity40", "legacy", "note", 44100, 256, 60, 40, 0, 0, "replacing"),
        ("legacy-note72", "legacy", "note", 44100, 256, 72, 100, 0, 0, "replacing"),
        ("legacy-program40", "legacy", "note", 44100, 256, 60, 100, 40, 0, "replacing"),
        ("legacy-48000", "legacy", "note", 48000, 256, 60, 100, 0, 0, "replacing"),
        ("veg-note-a", "veg", "note", 44100, 256, 60, 100, 0, 0, "replacing"),
    ]
    records, audio = {}, {}
    for case in cases:
        name, variant, mode, rate, block, note, velocity, program, offset, callback = case
        dll = ROOT / ("dll/legacy/S-YXG50.dll" if variant == "legacy" else "dll/veg/syxg50.dll")
        command = [str(ROOT / "tools/ReferenceHost.exe"), str(dll), str(OUT/name), mode,
                   *map(str, (rate, block, note, velocity, program, offset)), callback]
        result = subprocess.run(command, capture_output=True, text=True, timeout=30, cwd=ROOT)
        (OUT / (name+".console.txt")).write_text(result.stdout+result.stderr, encoding="utf-8")
        if result.returncode:
            raise RuntimeError(name+" failed: "+str(result.returncode)+"\n"+result.stdout[-2500:]+result.stderr)
        actual_rate, pcm, payload = read_float_wav(OUT/(name+".float.wav"))
        assert actual_rate == rate and len(pcm) == rate*4*2
        audible = [i//2 for i, x in enumerate(pcm) if abs(x)>1e-7]
        records[name] = {
            "variant": variant, "mode": mode, "sample_rate": rate, "block_size": block,
            "midi_note": note, "velocity": velocity, "program": program,
            "event_offset": offset, "callback": callback,
            "note_on_sample": ((rate//4)//128)*128+offset,
            "note_off_sample": ((rate*5//4)//128)*128+offset if mode == "note" else None,
            "frames": len(pcm)//2, "pcm_sha256": hashlib.sha256(payload).hexdigest(),
            "wav_sha256": sha(OUT/(name+".float.wav")),
            "peak": max(map(abs, pcm)), "rms": rms(pcm),
            "first_audible_frame_threshold_1e_7": min(audible) if audible else None,
            "last_audible_frame_threshold_1e_7": max(audible) if audible else None,
            "tail_rms_2_to_4_seconds": rms(pcm[rate*4:]),
            "loaded_bank_prefix_matches": {
                str(i): [p.relative_to(ROOT).as_posix() for p in (ROOT/"dll/legacy").glob("*.tbl")
                         if p.read_bytes()[:64] == (OUT/(name+"-bank"+str(i)+"-prefix.bin")).read_bytes()]
                for i in (1, 2) if (OUT/(name+"-bank"+str(i)+"-prefix.bin")).exists()
            },
        }
        audio[name] = pcm
        print(name, "peak=%.9f" % records[name]["peak"], "first=", records[name]["first_audible_frame_threshold_1e_7"])
    pairs = [("legacy-note-a", name) for name in (
        "legacy-note-b", "legacy-note-c", "legacy-process", "legacy-block64", "legacy-block128",
        "legacy-block512", "legacy-block257", "legacy-offset64", "legacy-offset127", "legacy-offset128",
        "legacy-hold", "legacy-velocity40", "legacy-note72", "legacy-program40", "veg-note-a")]
    comparisons = {a+" vs "+b: compare(audio[a], audio[b]) for a, b in pairs}
    after = inputs()
    verification = {
        "input_files_unchanged": before == after,
        "silence_is_exact_zero": records["legacy-silence"]["peak"] == 0,
        "note_is_audible": records["legacy-note-a"]["peak"] > 0.001,
        "three_fresh_runs_bit_identical": all(comparisons["legacy-note-a vs "+x]["different_samples"] == 0 for x in ("legacy-note-b", "legacy-note-c")),
        "note_off_changes_tail": compare(audio["legacy-note-a"][44100*4:], audio["legacy-hold"][44100*4:])["different_samples"] > 0,
        "all_pcm_finite_and_correct_length": True,
    }
    report = {"scope": "Offline original DLL reference; no ported engine", "verification": verification,
              "host_source_sha256": sha(ROOT/"tools/ReferenceHost.cs"),
              "host_exe_sha256": sha(ROOT/"tools/ReferenceHost.exe"),
              "input_manifest": before, "cases": records, "comparisons": comparisons}
    (EVIDENCE/"reference-results.json").write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps(verification, indent=2))
    if not all(verification.values()):
        raise SystemExit("Reference checks failed; inspect analysis/evidence/reference-results.json")


if __name__ == "__main__":
    main()
