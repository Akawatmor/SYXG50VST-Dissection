"""Inspect the supplied S-YXG50 bank and verify the legacy wave transform."""
from pathlib import Path
import hashlib
import json
import struct

ROOT = Path(__file__).resolve().parents[1]
OUTPUT = ROOT / "analysis/step3"


def decode_wave(encoded):
    decoded = bytearray(len(encoded))
    for offset, value in enumerate(encoded):
        alternating = 0x5D if offset % 2 == 0 else 0xA2
        value ^= alternating ^ (offset & 255)
        decoded[offset] = ((value << 4 | value >> 4) & 255) ^ 0x5C
    return decoded


def read_bank(path):
    data = path.read_bytes()
    if len(data) < 100:
        raise ValueError("Truncated bank header")
    lengths = struct.unpack_from("<17I", data, 32)
    if 100 + sum(lengths) != len(data):
        raise ValueError("Bank segment lengths do not match file length")
    segments = []
    cursor = 100
    for index, length in enumerate(lengths):
        segments.append({"index": index, "offset": cursor, "length": length,
                         "data": data[cursor:cursor+length]})
        cursor += length
    return data, segments


def main():
    OUTPUT.mkdir(parents=True, exist_ok=True)
    bank, segments = read_bank(ROOT / "dll/legacy/sxgbin41.tbl")
    encoded = (ROOT / "dll/legacy/Sxgwave4.tbl").read_bytes()
    decoded = decode_wave(encoded)
    prefix = (ROOT / "reference/legacy-note-a-bank2-prefix.bin").read_bytes()
    assert decoded[:len(prefix)] == prefix
    (OUTPUT / "wave-decoded.bin").write_bytes(decoded)
    for segment in segments:
        (OUTPUT / ("segment-%02d.bin" % segment["index"])).write_bytes(segment["data"])
    report = {"bank_header": bank[:16].split(b"\0")[0].decode("ascii"),
              "wave_filename": bank[16:32].split(b"\0")[0].decode("ascii"),
              "wave_encoded_size": len(encoded),
              "wave_decoded_sha256": hashlib.sha256(decoded).hexdigest(),
              "legacy_runtime_prefix_matches": True,
              "full_wave_matches_dll_memory": decoded == (OUTPUT/"legacy-dump-bank2-full.bin").read_bytes() if (OUTPUT/"legacy-dump-bank2-full.bin").exists() else None,
              "full_parameter_bank_matches_dll_memory": bank == (OUTPUT/"legacy-dump-bank1-full.bin").read_bytes() if (OUTPUT/"legacy-dump-bank1-full.bin").exists() else None,
              "segments": [{k: v for k, v in s.items() if k != "data"} for s in segments]}
    (OUTPUT / "bank-layout.json").write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps(report, indent=2))
    print("prevoice prefix", segments[13]["data"][:160].hex(" "))
    print("sample directory", segments[15]["data"][:32].hex(" "))
    print("sample records", segments[16]["data"][:128].hex(" "))


if __name__ == "__main__":
    main()
