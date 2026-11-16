# S-YXG50: ผลการ dissect ขั้น 1 และ reference ขั้น 2

วันที่ทำงาน: 16 พฤศจิกายน 2026 (Asia/Bangkok)

## สถานะและขอบเขต

ทำแผนที่เส้นทางขั้นต่ำตั้งแต่ VST entry ไปจนถึง MIDI, render และ cleanup แล้ว และสร้าง offline reference host ที่รัน DLL เดิมเพื่อบันทึก PCM ได้จริง มีชุดทดสอบ 18 กรณีและตรวจการทำซ้ำ 3 process แยกกัน

ยังไม่ได้สร้าง engine พอร์ตหรือ WASM และยังไม่ได้กู้รายละเอียด voice/sample/filter/effects ทั้งหมด ชื่อฟังก์ชันในเอกสารนี้เป็นชื่อที่ผู้วิเคราะห์ตั้งตามพฤติกรรม ไม่ใช่ symbol ต้นฉบับ

ไฟล์ทั้งหมดใน `dll/` รวมทั้ง DLL, EXE, SET และ TBL มีขนาดและ SHA-256 ตรงกันก่อนและหลังชุดทดสอบ ตัวทดสอบที่เพิ่มได้รับอนุญาตจากผู้ใช้และอยู่ใน `tools/`; ผลลัพธ์อยู่ใน `analysis/` และ `reference/`

## ตัวอย่างที่ใช้

- เป้าหมายหลัก: `dll/legacy/S-YXG50.dll`, 634,880 bytes = 620 KiB, PE32 x86
- SHA-256: `0a34eea43c56d2776c212a2378046437b14c1a710cd72efd7b02d0d1cf7cea5d`
- ตัวเปรียบเทียบ: `dll/veg/syxg50.dll`, 5,070,848 bytes
- Preferred image base ทั้งสองตัว: `0x10000000`
- `.text` virtual size ทั้งสองตัว: 254,802 bytes; เทียบแล้วต่าง 5,591 bytes จึงห้ามถือว่าเป็นโค้ดเดียวกันทั้งหมด
- บันทึก hash ทุกไฟล์: [input-manifest.json](evidence/input-manifest.json)

คำว่า legacy หมายถึงไฟล์ที่ผู้ใช้จัดไว้ในโฟลเดอร์นี้ ไม่ได้รับรองว่าเป็นไฟล์จากผู้ผลิตที่ไม่เคยถูกดัดแปลงก่อนส่งมา

## ขั้น 1: เส้นทางและขอบเขตที่ยืนยันได้

Address ในตารางเป็น **RVA** ให้บวก module base ที่โหลดจริงก่อนใช้ใน debugger เช่น entry RVA `0x3610` จะเป็น VA `0x10003610` เมื่อโหลดที่ preferred base

| หน้าที่ | RVA | หลักฐานและข้อสังเกต |
|---|---|---|
| Export `main` | `0x3610` | อ่าน export และเรียกจริงจาก host; ตรวจ host version ก่อนสร้าง object |
| Derived plugin constructor | `0x3280` | entry เรียกตำแหน่ง `0x3274` ซึ่งมี NOP นำหน้า; ตัว constructor เริ่มที่ `0x3280` |
| Base plugin constructor | `0x2840` | สร้าง VST wrapper; object size ที่ entry จองคือ `0x104` |
| Derived initialization | `0x32D0` | entry เรียกผ่าน plugin vtable slot `+0x210`; ต่อไป `0x2920` และส่วน editor |
| Engine adapter setup | `0x2920` | สร้าง adapter ขนาด `0x58`, เก็บที่ plugin object `+0xB0`, สร้าง scratch buffers |
| Adapter constructor | `0x30280` | ตั้ง vtable RVA `0x4E110` |
| Adapter init / core creation path | `0x30330` | เรียกระบบตั้งค่า, สร้าง core, โหลด bank และเรียก reset |
| Bank acquisition | `0x32970` | เส้นทาง legacy อ่านค่าจาก INI, resolve ชื่อไฟล์, โหลดสอง bank, reference count ใน global |
| Raw file loader | `0x32AE0` | เส้นทาง CreateFile/ReadFile สำหรับข้อมูล bank |
| VST dispatcher trampoline | `0x1000` | pointer ที่อ่านจาก AEffect จริง; ส่งต่อ virtual dispatcher |
| Extended dispatcher | `0x1A90` | opcode 25 ส่งต่อไป processEvents slot `+0xC8` |
| Queue VST events | `0x3260` | เก็บ pointer VstEvents ที่ plugin object `+0xE0`, ไม่ได้คัดลอก events ในฟังก์ชันนี้ |
| Set sample rate | `0x2DA0` | plugin slot `+0x4C`; adapter `0x30580` → core state setter `0x17F30` |
| Set block size | `0x16D0` | plugin slot `+0x50`; เก็บค่า host block size; render wrapper แบ่งทำงานภายในเป็น 128 frames |
| Resume / suspend | `0x33A0` / `0x3380` | plugin slots `+0x58` / `+0x54`; wrapper reset/ตั้งค่า และ editor notification |
| `process` trampoline | `0x10A0` | pointer AEffect ที่อ่านจริง → plugin slot `+0x10` → `0x2E90` |
| `processReplacing` trampoline | `0x10C0` | pointer AEffect ที่อ่านจริง → plugin slot `+0x14` → `0x2EB0` |
| Shared render wrapper | `0x2ED0` | จัดการ events, tick 10 ms, render quantum 128, buffering สำหรับบล็อกขนาดอื่น |
| Adapter packed MIDI | `0x305F0` | adapter slot `+0x08` → core slot `+0x10` |
| Core packed MIDI decoder | `0x3700` | แยก status/channel/data bytes → core slot `+0x17C` |
| Channel MIDI dispatcher | `0x7560` | core slot `+0x17C`; dispatch table ที่ RVA `0x41BB0` |
| Note Off branch | `0xB620` | table index 0 ของ status high nibble `0x8` → `0xB640` → `0xB6F0` |
| Note On branch | `0xB670` | table index 1 ของ status high nibble `0x9` → `0xB690` → `0xB770` |
| Adapter SysEx | `0x30630` | adapter slot `+0x0C` → core byte stream parser `0x3790`; ยังไม่ได้ทดสอบ SysEx |
| Adapter periodic tick | `0x30670` | adapter slot `+0x10` → core `0x3810`; wrapper เรียกตามช่วงสะสม 10 ms |
| Adapter reset | `0x306A0` | adapter slot `+0x14` → embedded state reset `0x17750` |
| Adapter audio render | `0x30710` | adapter slot `+0x18`; เส้นทางที่ตรวจพบส่งต่อ embedded state `core+4` |
| Core render bridges | `0x17300` / `0x17310` | ส่งต่อ `0x18150` / `0x181A0` สำหรับ accumulate/replacing |
| Internal render | `0x18150` / `0x181A0` | clear workspace, call `0x18680`, `0x18330`, แล้ว output bridges |
| Output bridges | `0x18530` / `0x18540` | ส่งต่อ `0x2FCD0` / `0x2FD30`; ยังไม่ได้อธิบาย DSP ทุกขั้น |
| Plugin destructors | `0x32C0` → `0x28A0` | effClose trampoline เรียก virtual destructor และคืน object |
| Adapter destructor | `0x302B0` | cleanup embedded core ที่ `0x17DC0`, คืน memory, release banks `0x32BC0` |

AEffect ที่อ่านจาก legacy ขณะทำงาน: magic `VstP`, inputs 0, outputs 2, programs 1, parameters 0, flags `0x131`, version 1, uniqueID ดู raw AEffect dump ได้ โปรแกรม VST มี 1 ช่อง แต่ MIDI Program Change เลือกเสียงต่างกันได้จริง (ทดสอบ program 0 และ 40)

VST C callbacks ใช้ cdecl; C++ wrapper ภายในใช้ thiscall หลายจุด ส่วน core/adapter มี callback ที่ส่ง self เป็น argument และคืน stack ตาม assembly ต้องยืนยัน ABI ทีละขอบเขต ห้ามคัดลอก signature ของ VST ไปใช้กับทุกฟังก์ชันภายใน

โครงสร้าง state ที่ระบุได้:

| ตำแหน่ง | ความหมาย |
|---|---|
| plugin `+0x20` | AEffect; entry คืน pointer มายังตำแหน่งนี้ |
| AEffect `+0x40` | pointer กลับไปยัง plugin object |
| plugin `+0xB0` | engine adapter |
| plugin `+0xD8` | sample rate ที่ wrapper ใช้ |
| plugin `+0xE0` | pending VstEvents pointer |
| plugin `+0xE8`, `+0xEC` | counters สำหรับ scheduling/tick |
| plugin `+0xF0`, `+0xF4` | scratch buffers ช่องซ้าย/ขวา |
| plugin `+0xF8`, `+0xFC`, `+0x100` | cached render cursors และจำนวน frame ที่เหลือ |
| adapter `+0x08` | core object, vtable RVA `0x4E138` |
| core `+0x04` | embedded engine state; ไม่ใช่ vtable pointer |
| module RVA `0x55340`, `0x55344` | loaded bank buffers |
| module RVA `0x55348` | bank reference count |

มีทั้ง instance state และ global state ดังนั้นยังไม่ควรสมมติว่ารองรับหลาย instance แยกกันโดยสมบูรณ์

หลักฐาน: [legacy-key-paths.txt](evidence/legacy-key-paths.txt), [disassembly เต็ม](evidence/legacy-disassembly.txt), [runtime log](../reference/legacy-note-a.log), [function-map.csv](function-map.csv)

## ขั้น 2: ตัวอ้างอิงที่ใช้งานได้

ตัวทดสอบเป็น C#/.NET Framework แบบ x86 เพื่อให้เรียก DLL x86 ได้โดยใช้ compiler ที่ติดตั้งอยู่แล้ว ไม่ต้องติดตั้ง DAW, debugger หรือ audio driver เพิ่ม รัน offline โดยไม่เปิดอุปกรณ์เสียงและไม่เปิด editor

ลำดับที่ใช้จริง:

1. ตั้ง working directory เป็น directory ของ DLL และ LoadLibrary โดยไม่ patch memory/ไฟล์
2. หา export `main`, เรียกด้วย host callback, ตรวจ AEffect magic, dump callback pointers/vtables
3. `effOpen (0)` → `effSetSampleRate (10)` → `effSetBlockSize (11)` → `effSetProgram (2)`
4. `effMainsChanged (12, value=1)`
5. ส่ง CC bank MSB=0, bank LSB=0 และ MIDI Program Change ใน event batch แรก
6. ส่ง MIDI events ผ่าน `effProcessEvents (25)` ก่อน audio callback ของแต่ละบล็อก
7. เก็บ VstEvents และ event buffers ไว้จน render คืนค่า เพราะ DLL เก็บ pointer ไปใช้อีกที
8. เรียก processReplacing (หรือ process โดยเคลียร์ output ก่อนสะสม), เก็บ planar float เป็น interleaved stereo
9. บันทึก float32 WAV สำหรับวัดผล และ PCM16 WAV สำหรับฟัง; ไม่ normalize
10. `effMainsChanged (12, value=0)` → `effClose (1)` → FreeLibrary

แต่ละกรณีเปิด process ใหม่ บันทึก 4 วินาที ที่ 44,100 Hz เว้นแต่ชื่อกรณีระบุ 48,000 Hz ใช้ channel 1, note 60, velocity 100, program 0 (เลข MIDI เริ่มจาก 0) เป็น baseline โดย Note On ขอที่ frame 11008 และ Note Off frame 55040 ที่ 44,100 Hz

ผลตรวจเชิงตัวเลข: [REFERENCE_RESULTS.md](REFERENCE_RESULTS.md) และ [reference-results.json](evidence/reference-results.json)

## ข้อค้นพบที่มีผลต่อพอร์ต

- สาม fresh processes ของ baseline ให้ float PCM ตรงกันทุก sample บนเครื่องนี้
- silence ให้ศูนย์ทุก sample; Note On มีเสียง; Note Off เปลี่ยน tail ชัดเจนเมื่อเทียบกับ hold
- process กับ processReplacing ให้ผลตรงกันในกรณีที่ทดสอบ โดย process เริ่มจาก output ที่เคลียร์เป็นศูนย์
- host blocks 64/128/256 ให้ผลตรงกันสำหรับตาราง event ที่ทดสอบ แต่ 512/257 ให้ผลต่าง แม้ขอ event ที่ absolute sample เดียวกัน
- event offsets 0, 64, 127, 128 ในกรณี 256-frame block ที่ทดสอบให้ผลเหมือนกัน: wrapper เปรียบเทียบ deltaFrames กับขอบ quantum 128 แบบรวมขอบ (`<=`) ก่อน render ไม่ได้ทำ event timing แบบ sample-accurate ทั่วไป
- ที่ 48,000 Hz เริ่มมีเสียงก่อน sample ที่ขออย่างชัดเจนด้วย ต้องเก็บพฤติกรรม scheduling เดิมเป็นส่วนหนึ่งของ reference ห้ามนับเป็น latency ของ sample bank โดยตรง
- legacy และ VEG ให้ผลตรงกันทุก sample เฉพาะ baseline นี้ แต่ `.text` และ resource banks ไม่ตรงกันทั้งไฟล์ จึงยังสรุปว่าเทียบเท่ากันทุก program/setting ไม่ได้
- prefix 64 bytes ของ loaded bank แรกตรงกับ `sxgbin41.tbl`; header ระบุ `MU50 4MB V2.0` และ `SXGWAVE4.TBL` ส่วน loaded bank ที่สองมี prefix ต่างจากไฟล์ภายนอก ต้องตรวจการแปลงข้อมูลระหว่างโหลดในขั้น 3
- bank data มี pointers แบบ global และ reference count; native DLL มี x87 instructions ในเส้นทางคำนวณ จึงยังไม่รับรองว่า WASM จะ bit-identical

## ข้อจำกัดที่บันทึกไว้

ยังไม่ได้ทำ SysEx, sustain/pitch bend, polyphony, drums, preset restore, effect bypass, ทุก sample rate หรือ multi-instance tests และยังไม่ได้วัด realtime performance การทดสอบใช้ค่า effects/config เริ่มต้นของ DLL บนเครื่องนี้ ไม่ได้บังคับปิด effects และไม่ได้แก้ registry/INI

รายงานนี้ไม่ได้อ้างว่าได้ dynamic breakpoint trace ทุกฟังก์ชันภายใน หลักฐาน dynamic คือ callback/vtable pointers, memory prefixes และเสียงที่รันจริง ส่วนเส้นทางย่อยภายในอาศัย direct calls/virtual slots ใน disassembly ที่แนบไว้

## วิธีทำซ้ำ

จากราก workspace:

```powershell
python tools\inspect_binaries.py
python tools\run_reference.py
```

คำสั่งแรกใช้ objdump ที่มีอยู่ใน PATH คำสั่งหลังใช้ .NET Framework compiler `Framework\v4.0.30319\csc.exe`, คอมไพล์ host เป็น x86 และสร้างผลลัพธ์ของ 18 กรณีใหม่ใน `reference/` พร้อมตรวจ hash ของ input ก่อน/หลัง

เรียกกรณีเดียว:

```powershell
.\tools\ReferenceHost.exe .\dll\legacy\S-YXG50.dll .\reference\manual-note note 44100 256 60 100 0 0 replacing
```

ตัว host นี้ออกแบบเพื่อไฟล์สอง build ที่แนบมา มีการอ่าน layout และ global RVAs เฉพาะ build เหล่านี้ ไม่ใช่ host สำหรับ DLL ใด ๆ โดยทั่วไป

## จุดเริ่มขั้น 3 ที่พร้อมแล้ว

เริ่มจาก loader `0x32970`/`0x32B80`, container parser `0x43D0`, Note On path `0x3700 → 0x7560 → 0xB670 → 0xB690 → 0xB770` และ render `0x30710 → 0x17310 → 0x181A0` เพื่อกู้ข้อมูลและ DSP สำหรับโน้ตเดียว โดยใช้ baseline block 128 หรือ 256 ที่กำหนดแน่นอนก่อน

## เอกสาร API ที่ตรวจประกอบ

ตัว host กำหนด calling convention ของ delegates และใช้ Marshal สำหรับ function pointers ตามเอกสาร Microsoft: [GetDelegateForFunctionPointer](https://learn.microsoft.com/en-us/dotnet/api/system.runtime.interopservices.marshal.getdelegateforfunctionpointer?view=net-10.0), [unmanaged calling conventions](https://learn.microsoft.com/en-us/dotnet/standard/native-interop/calling-conventions)
