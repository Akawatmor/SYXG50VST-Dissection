"""Read-only PE inspection and reproducible disassembly evidence collection."""
from pathlib import Path
import hashlib
import json
import re
import struct
import subprocess

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / "analysis/evidence"


class PE:
    def __init__(self, path):
        self.data = path.read_bytes()
        b = self.data
        pe = self.u32(60)
        assert b[:2] == b"MZ" and b[pe:pe+4] == b"PE\0\0"
        opt = pe+24
        assert self.u16(opt) == 0x10B
        self.image_base = self.u32(opt+28)
        self.resource_rva = self.u32(opt+96+16)
        table = opt+self.u16(pe+20)
        self.sections = []
        for i in range(self.u16(pe+6)):
            pos = table+40*i
            virtual_size, rva, raw_size, offset = struct.unpack_from("<IIII", b, pos+8)
            self.sections.append({"name": b[pos:pos+8].rstrip(b"\0").decode(),
                                  "rva": rva, "virtual_size": virtual_size,
                                  "raw_size": raw_size, "file_offset": offset})

    def u16(self, pos):
        return struct.unpack_from("<H", self.data, pos)[0]

    def u32(self, pos):
        return struct.unpack_from("<I", self.data, pos)[0]

    def offset(self, rva):
        for s in self.sections:
            if s["rva"] <= rva < s["rva"]+max(s["raw_size"], s["virtual_size"]):
                return s["file_offset"]+rva-s["rva"]
        raise ValueError(hex(rva))

    def resources(self):
        base = self.offset(self.resource_rva)
        def walk(relative, path):
            pos = base+relative
            for i in range(self.u16(pos+12)+self.u16(pos+14)):
                name, target = struct.unpack_from("<II", self.data, pos+16+i*8)
                if name & 0x80000000:
                    p = base+(name & 0x7FFFFFFF)
                    name = self.data[p+2:p+2+self.u16(p)*2].decode("utf-16le")
                if target & 0x80000000:
                    yield from walk(target & 0x7FFFFFFF, path+[name])
                else:
                    rva, size = struct.unpack_from("<II", self.data, base+target)
                    body = self.data[self.offset(rva):self.offset(rva)+size]
                    yield {"path": path+[name], "rva": hex(rva), "size": size,
                           "sha256": hashlib.sha256(body).hexdigest()}
        return list(walk(0, []))


def main():
    OUT.mkdir(parents=True, exist_ok=True)
    report = {}
    binaries = {"legacy": PE(ROOT/"dll/legacy/S-YXG50.dll"), "veg": PE(ROOT/"dll/veg/syxg50.dll")}
    for name, pe in binaries.items():
        dll = ROOT / ("dll/legacy/S-YXG50.dll" if name == "legacy" else "dll/veg/syxg50.dll")
        disassembly = subprocess.check_output(["objdump", "-d", "-Mintel", str(dll)], text=True)
        (OUT/(name+"-disassembly.txt")).write_text(disassembly, encoding="utf-8")
        headers = subprocess.check_output(["objdump", "-p", str(dll)], text=True).split("PE File Base Relocations")[0]
        (OUT/(name+"-pe.txt")).write_text(headers, encoding="utf-8")
        report[name] = {"image_base": hex(pe.image_base), "sections": pe.sections, "resources": pe.resources()}
    tables = {p.name.lower(): {"size": p.stat().st_size, "sha256": hashlib.sha256(p.read_bytes()).hexdigest()}
              for p in (ROOT/"dll/legacy").glob("*.tbl")}
    report["external_tables"] = tables
    report["embedded_table_comparisons"] = []
    for item in report["veg"]["resources"]:
        if item["path"][0] == 10:
            match = tables.get(str(item["path"][1]).lower())
            report["embedded_table_comparisons"].append({**item, "matches_legacy_file_exactly": match is not None and match["sha256"] == item["sha256"]})
    a, b = binaries["legacy"], binaries["veg"]
    text = next(s for s in a.sections if s["name"] == ".text")
    begin, size = text["rva"], text["virtual_size"]
    diffs = [rva for rva in range(begin, begin+size) if a.data[a.offset(rva)] != b.data[b.offset(rva)]]
    report["text_comparison"] = {"compared_virtual_bytes": size, "different_bytes": len(diffs), "byte_identical": not diffs}
    table = 0x41BB0
    report["midi_channel_dispatch_table"] = {"0x%02X" % status: "0x%08X" % (a.u32(a.offset(table+4*i))-a.image_base)
                                               for i, status in enumerate(range(0x80, 0xF0, 0x10))}
    # Named excerpt ranges use preferred VAs solely to match objdump output.
    ranges = {
        "vst-entry": (0x3610,0x36DA), "vst-callbacks": (0x1000,0x10DC),
        "construct-init-cleanup": (0x2840,0x2A80), "sample-rate": (0x2DA0,0x2E2D),
        "render-wrapper": (0x2E90,0x3274), "entry-object-construction": (0x3280,0x32C5),
        "derived-init": (0x32D0,0x3380), "engine-adapter": (0x30280,0x30770),
        "midi-packed-and-sysex": (0x3700,0x3810), "core-reset": (0x3810,0x38A0),
        "midi-channel-dispatch": (0x7560,0x75D0), "note-handlers": (0xB620,0xB7D0),
        "render-engine-bridges": (0x17300,0x17320), "render-engine": (0x18150,0x181EA),
        "render-output-bridges": (0x18530,0x18550), "bank-loader": (0x32970,0x32D90),
        "wrapper-destructors": (0x3280,0x32D0),
    }
    lines = (OUT/"legacy-disassembly.txt").read_text(encoding="utf-8").splitlines()
    excerpts = []
    for name, (lo, hi) in ranges.items():
        excerpts.append("\n=== "+name+" (RVA 0x%X to 0x%X) ===" % (lo, hi))
        for line in lines:
            match = re.match(r"([0-9a-f]+):", line)
            if match and a.image_base+lo <= int(match[1],16) < a.image_base+hi:
                excerpts.append(line)
    (OUT/"legacy-key-paths.txt").write_text("\n".join(excerpts), encoding="utf-8")
    (OUT/"binary-inspection.json").write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps({"text_comparison": report["text_comparison"], "embedded_table_comparisons": report["embedded_table_comparisons"]}, indent=2))


if __name__ == "__main__":
    main()
