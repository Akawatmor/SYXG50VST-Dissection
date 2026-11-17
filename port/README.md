# S-YXG50 Web Synth

อัปเดต 17 พฤศจิกายน 2026 — มี C core, native DLL และ freestanding WASM พร้อมเว็บ AudioWorklet, MIDI 16 ช่อง, ตัวเล่น Standard MIDI File และจอเครื่องที่เปิดเมื่อเรียกใช้แล้ว

**ยังไม่ใช่ S-YXG50 ที่เสียงตรง DLL ครบสาย** การถอด bank และ primitive บางส่วนยืนยันตรงกับ DLL แล้ว ส่วน amplifier, envelope, filter, vibrato และ reverb/chorus ใน renderer ปัจจุบันเป็นการประมาณ ผล `full_dll_audio_fidelity_passed` ยังเป็น `false`

## เปิดใช้งาน

1. ถ้าใช้ ZIP ให้แตก `syxg50-web.zip` ก่อน
2. ดับเบิลคลิก `Start S-YXG50.cmd` บนเครื่องที่มี Python 3 หรือเรียก `python tools/serve_web.py --open`
3. เปิด `http://127.0.0.1:8765/` ด้วย Chrome หรือ Edge แล้วกด **เริ่มเสียง**
4. กด **เพลงทดสอบ**, เลือกไฟล์ `.mid` หรือกด **เชื่อมต่อ MIDI** เพื่อเลือกอุปกรณ์ในเครื่อง
5. กด **เปิดหน้าจอเครื่อง** เมื่อต้องการปรับเสียง ปิดจอได้โดยที่ engine และเพลงทำงานต่อ

กด Ctrl+C ใน terminal เพื่อหยุดเซิร์ฟเวอร์ ถ้า port ถูกใช้อยู่ เรียก `python tools/serve_web.py --port 8766 --open` แทน หน้าเว็บและ bank ทำงานในเครื่อง ไม่ใช้ CDN และไม่ต้องรัน DLL ต้นฉบับ เปิดผ่าน HTTP localhost; การเปิด `index.html` โดยตรงผ่าน `file://` ใช้ไม่ได้กับขั้นตอนโหลด Worklet นี้

จอเครื่องปิดเป็นค่าเริ่มต้น: ไม่มี editor DOM และไม่มี meter telemetry จนกดเปิด โหลด editor JavaScript แบบ dynamic import และแสดง bitmap resource 111 ของ DLL เดิม ปิดจอแล้วล้าง event listeners/keyboard และปิด telemetry ตัวควบคุมเว็บเชื่อมกับ WASM ไม่ได้รัน Win32 editor ใน WASM

## ความสามารถ

| ส่วน | สถานะ |
|---|---|
| AudioWorklet | Stereo float32, จัด event ตรงตำแหน่ง sample, รองรับขนาด callback ที่เปลี่ยนได้ |
| MIDI | 16 parts, Note On/Off, velocity-zero Note Off, bank/program, pitch bend, modulation, volume, expression, pan, sustain |
| Polyphony | 128 sample voices; หนึ่งโน้ตใช้ได้สูงสุด 2 elements; voice stealing เมื่อเต็ม |
| Samples | wave bank เดิม, 8/16-bit, loop และ one-shot |
| Controllers | CC 0/1/6/7/10/11/32/38/64/71/74/91/93/100/101/120/121/123, RPN bend range/coarse tune |
| Drums | Part 10, drum banks 126/127, kit mapping, exclusive group; ทดสอบ GM notes 35–81 |
| SysEx | GM/GM2/XG/GS reset, master volume, XG part bank/program/drum mode/volume/pan บางรายการ; สูงสุด 1,024 bytes |
| Effects | Reverb/chorus เปิด/ปิดได้ เป็น DSP ที่ประมาณขึ้น |
| MIDI files | SMF 0/1, tempo changes, running status, SMPTE timing, play/pause/resume/stop; ไม่รับ format 2 |
| Input | Web MIDI ต้องให้สิทธิ์เบราว์เซอร์; SysEx ไม่ร้องขอจนเลือก checkbox |
| Editor | bitmap เดิม, meter/voice count, 16-part controls, on-screen/PC keyboard A–; |

พารามิเตอร์ XG/GS ทั้งชุด, NRPN, pressure/aftertouch, MIDI tuning และ effect algorithms เดิมยังไม่ครบ Unknown MIDI/SysEx รายงานเป็น unsupported ภายใน Worklet โปรแกรมในจอแสดงเลขและตระกูลเสียง ยังไม่มีชื่อ patch XG ทั้ง bank และ drum notes นอกช่วงมาตรฐานอาจไม่มี mapping

## ผลตรวจ

- Parameter/wave bank ตรงกับ memory ที่ DLL โหลด; decoded wave SHA-256 `22ea1584608a172a939db96fa13f774cdd392c29e8a17664acc99370e987ae62`
- Oscillator 8-bit Q15 primitive ตรงกับ kernel เดิมที่ RVA `0x1ABB0` ใน 3 กรณี พร้อม final position/fraction; gain primitive ตรง 9 ค่า
- Native/WASM PCM ตรงกันทั้ง 5 กรณีเดิม และชุด multichannel 48,000 frames ที่รวม drums/controllers/effects
- ชุด Phase 6–7 ผ่าน 16 กลุ่ม รวม 128 programs × 3 keys, GM drums 35–81, sustain/release, pan/mute, voice cap, MIDI parser และ Worklet scheduling
- Chrome จริง: เริ่ม engine 48 kHz, เล่น demo MIDI 4 parts จบ, เปิด/ปิด editor และตัวควบคุม; ไม่พบ console error ในช่วงตรวจ
- ยังไม่ได้ทดสอบอุปกรณ์ MIDI จริงหรือวัด audio underrun ระยะยาว การเลือกไฟล์ผ่าน browser automation ถูกจำกัดด้วยสิทธิ์ extension; demo `.mid` ผ่าน parser/Worklet จริงแล้ว
- Hash ไฟล์ต้นฉบับใน manifest ไม่เปลี่ยน ไม่มีการแก้ DLL/TBL

รายละเอียดอยู่ใน `analysis/PHASE_6_7_REPORT.md`, `analysis/phase67-tests.json`, `analysis/multichannel-parity.json` และ `analysis/step3/port-verification.json` ใน workspace ต้นทาง ZIP สำหรับรันมีรายงาน Phase 6–7 และ SHA256 ของไฟล์ที่บรรจุ

## Source และการตรวจซ้ำใน workspace

`port/syxg_core.c`/`.h` และ `syxg_synth.inc` เป็น engine; `web/synth-worklet.js` เป็น audio processor; `web/synth-client.mjs` เป็น host API ที่ใช้โดยไม่เปิดจอก็ได้; `web/midi-file.mjs` เป็น SMF parser; `web/editor.mjs` เป็นจอที่โหลดเมื่อเรียกใช้

```powershell
python tools/build_port.py
python tools/verify_port.py
python tools/verify_multichannel.py
node tools/test_phase67.mjs
python tools/package_web.py
```

Build ต้องมี GCC, Python, Node และ Zig 0.15.2 ใน `.tools/zig-x86_64-windows-0.15.2/` โมดูล WASM ไม่มี imports ใช้ memory เริ่ม 8 MiB / สูงสุด 16 MiB, sample rates 22,050–192,000 Hz, render 1–4,096 frames ต่อครั้ง ในเซสชันนี้ Zig ต้องคอมไพล์นอก sandbox เนื่องจาก compiler cache rename ถูกจำกัด

แพ็กเกจรันมี bank และ bitmap จากไฟล์ที่ผู้ใช้จัดหา สำหรับใช้ในเครื่องนี้; ไม่ได้เผยแพร่ขึ้น hosting หรือแจกจ่ายไปยังบริการภายนอก
