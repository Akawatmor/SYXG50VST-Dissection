# ผลทดสอบ reference DLL

ผลจากการรัน DLL จริงแบบ offline บนเครื่องนี้ ทุกกรณีเปิด process ใหม่และบันทึก 4 วินาที

## การตรวจหลัก

| การตรวจ | ผล |
|---|---|
| `input_files_unchanged` | PASS |
| `silence_is_exact_zero` | PASS |
| `note_is_audible` | PASS |
| `three_fresh_runs_bit_identical` | PASS |
| `note_off_changes_tail` | PASS |
| `all_pcm_finite_and_correct_length` | PASS |

## กรณีทดสอบ

เลข frame เริ่มจาก 0; first audible ใช้ threshold 1e-7 และเป็นผลวัดเสียง ไม่ใช่เวลาที่ร้องขอ MIDI

| กรณี | Hz | Block | Requested Note On | First audible frame | Peak | RMS |
|---|---:|---:|---:|---:|---:|---:|
| legacy-note-a | 44100 | 256 | 11008 | 11018 | 0.134465307 | 0.018010920 |
| legacy-note-b | 44100 | 256 | 11008 | 11018 | 0.134465307 | 0.018010920 |
| legacy-note-c | 44100 | 256 | 11008 | 11018 | 0.134465307 | 0.018010920 |
| legacy-silence | 44100 | 256 | — | None | 0.000000000 | 0.000000000 |
| legacy-hold | 44100 | 256 | 11008 | 11018 | 0.134465307 | 0.020025685 |
| legacy-process | 44100 | 256 | 11008 | 11018 | 0.134465307 | 0.018010920 |
| legacy-block64 | 44100 | 64 | 11008 | 11018 | 0.134465307 | 0.018010920 |
| legacy-block128 | 44100 | 128 | 11008 | 11018 | 0.134465307 | 0.018010920 |
| legacy-block512 | 44100 | 512 | 11008 | 10890 | 0.134471148 | 0.018014158 |
| legacy-block257 | 44100 | 257 | 11008 | 10890 | 0.134471148 | 0.018024456 |
| legacy-offset64 | 44100 | 256 | 11072 | 11018 | 0.134465307 | 0.018010920 |
| legacy-offset127 | 44100 | 256 | 11135 | 11018 | 0.134465307 | 0.018010920 |
| legacy-offset128 | 44100 | 256 | 11136 | 11018 | 0.134465307 | 0.018010920 |
| legacy-velocity40 | 44100 | 256 | 11008 | 11018 | 0.020884151 | 0.002892126 |
| legacy-note72 | 44100 | 256 | 11008 | 11016 | 0.120358139 | 0.013699637 |
| legacy-program40 | 44100 | 256 | 11008 | 11009 | 0.141543150 | 0.030864101 |
| legacy-48000 | 48000 | 256 | 11904 | 11787 | 0.134806454 | 0.017811376 |
| veg-note-a | 44100 | 256 | 11008 | 11018 | 0.134465307 | 0.018010920 |

## เทียบ float PCM กับ legacy-note-a

different_samples นับ interleaved L/R samples; 0 หมายถึงตรงกันทุก sample ตลอด 4 วินาที

| เทียบกับ | Different samples | Max absolute difference | RMS difference |
|---|---:|---:|---:|
| legacy-note-b | 0 | 0.000000000 | 0.000000000 |
| legacy-note-c | 0 | 0.000000000 | 0.000000000 |
| legacy-process | 0 | 0.000000000 | 0.000000000 |
| legacy-block64 | 0 | 0.000000000 | 0.000000000 |
| legacy-block128 | 0 | 0.000000000 | 0.000000000 |
| legacy-block512 | 331020 | 0.207764536 | 0.028051700 |
| legacy-block257 | 331020 | 0.207764536 | 0.028059591 |
| legacy-offset64 | 0 | 0.000000000 | 0.000000000 |
| legacy-offset127 | 0 | 0.000000000 | 0.000000000 |
| legacy-offset128 | 0 | 0.000000000 | 0.000000000 |
| legacy-hold | 242718 | 0.036331579 | 0.008244019 |
| legacy-velocity40 | 330764 | 0.117500240 | 0.015330948 |
| legacy-note72 | 330768 | 0.155079510 | 0.023985026 |
| legacy-program40 | 330784 | 0.203703731 | 0.036957355 |
| veg-note-a | 0 | 0.000000000 | 0.000000000 |

## Baseline สำหรับใช้เทียบพอร์ต

- Float PCM SHA-256: `bf6a14937a191456da51de07373b28e3ae1f6a24f0427dea014dc7a40ecf0f6a`
- Sample rate 44100 Hz, stereo float32, host block 256, Note 60, velocity 100, MIDI program 0
- ขอ Note On frame 11008 และ Note Off frame 55040; มีเสียงเกิน threshold ครั้งแรกที่ frame 11018
- RMS ช่วง 2–4 วินาที: Note Off `0.000083476729`, hold `0.006532719484`
- [WAV สำหรับฟัง](../reference/legacy-note-a.wav)
- [Float32 WAV สำหรับวัดผล](../reference/legacy-note-a.float.wav)
- [Log ของ baseline](../reference/legacy-note-a.log)
- [ผลดิบและ input hashes](evidence/reference-results.json)

Baseline ตรงกัน 3 process บนเครื่องนี้ ยังไม่รับรองความเหมือนข้ามเครื่องหรือหลังพอร์ต WASM และผลที่ legacy/VEG ตรงกันครอบคลุมเฉพาะกรณี baseline ที่วัดเท่านั้น
