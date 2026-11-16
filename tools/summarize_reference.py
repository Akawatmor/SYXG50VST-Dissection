"""Render measured reference results and the documented function table as reviewable files."""
from pathlib import Path
import csv
import json

ROOT = Path(__file__).resolve().parents[1]
report = json.loads((ROOT/"analysis/evidence/reference-results.json").read_text(encoding="utf-8"))
lines = ["# ผลทดสอบ reference DLL", "", "ผลจากการรัน DLL จริงแบบ offline บนเครื่องนี้ ทุกกรณีเปิด process ใหม่และบันทึก 4 วินาที", "",
         "## การตรวจหลัก", "", "| การตรวจ | ผล |", "|---|---|"]
for key, value in report["verification"].items():
    lines.append("| `"+key+"` | "+("PASS" if value else "FAIL")+" |")
lines += ["", "## กรณีทดสอบ", "", "เลข frame เริ่มจาก 0; first audible ใช้ threshold 1e-7 และเป็นผลวัดเสียง ไม่ใช่เวลาที่ร้องขอ MIDI", "",
          "| กรณี | Hz | Block | Requested Note On | First audible frame | Peak | RMS |", "|---|---:|---:|---:|---:|---:|---:|"]
for name, row in report["cases"].items():
    lines.append("| "+name+" | "+str(row["sample_rate"])+" | "+str(row["block_size"])+" | "+("—" if row["mode"] == "silence" else str(row["note_on_sample"]))+" | "+str(row["first_audible_frame_threshold_1e_7"])+" | %.9f | %.9f |" % (row["peak"], row["rms"]))
lines += ["", "## เทียบ float PCM กับ legacy-note-a", "", "different_samples นับ interleaved L/R samples; 0 หมายถึงตรงกันทุก sample ตลอด 4 วินาที", "",
          "| เทียบกับ | Different samples | Max absolute difference | RMS difference |", "|---|---:|---:|---:|"]
for pair, row in report["comparisons"].items():
    lines.append("| "+pair.split(" vs ")[1]+" | "+str(row["different_samples"])+" | %.9f | %.9f |" % (row["max_abs_difference"], row["rms_difference"]))
baseline = report["cases"]["legacy-note-a"]
hold = report["cases"]["legacy-hold"]
lines += ["", "## Baseline สำหรับใช้เทียบพอร์ต", "", "- Float PCM SHA-256: `"+baseline["pcm_sha256"]+"`",
          "- Sample rate 44100 Hz, stereo float32, host block 256, Note 60, velocity 100, MIDI program 0",
          "- ขอ Note On frame 11008 และ Note Off frame 55040; มีเสียงเกิน threshold ครั้งแรกที่ frame "+str(baseline["first_audible_frame_threshold_1e_7"]),
          "- RMS ช่วง 2–4 วินาที: Note Off `%.12f`, hold `%.12f`" % (baseline["tail_rms_2_to_4_seconds"], hold["tail_rms_2_to_4_seconds"]),
          "- [WAV สำหรับฟัง](../reference/legacy-note-a.wav)", "- [Float32 WAV สำหรับวัดผล](../reference/legacy-note-a.float.wav)",
          "- [Log ของ baseline](../reference/legacy-note-a.log)", "- [ผลดิบและ input hashes](evidence/reference-results.json)",
          "", "Baseline ตรงกัน 3 process บนเครื่องนี้ ยังไม่รับรองความเหมือนข้ามเครื่องหรือหลังพอร์ต WASM และผลที่ legacy/VEG ตรงกันครอบคลุมเฉพาะกรณี baseline ที่วัดเท่านั้น", ""]
(ROOT/"analysis/REFERENCE_RESULTS.md").write_text("\n".join(lines), encoding="utf-8")

source = (ROOT/"analysis/STEP_1_2_REPORT.md").read_text(encoding="utf-8")
table = source.split("| หน้าที่ | RVA | หลักฐานและข้อสังเกต |",1)[1].split("\n\n",1)[0]
with (ROOT/"analysis/function-map.csv").open("w", encoding="utf-8-sig", newline="") as out:
    writer = csv.writer(out)
    writer.writerow(["Analyst-assigned function", "Legacy RVA", "Evidence / notes"])
    for line in table.splitlines():
        if line.startswith("|") and not line.startswith("|---"):
            writer.writerow([cell.strip().replace("`", "") for cell in line.strip("|").split("|")])
print("Wrote analysis/REFERENCE_RESULTS.md and analysis/function-map.csv")
