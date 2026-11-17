/* Ghidra analysis of supplied S-YXG50.dll at 1001d4e0 */

void __thiscall FUN_1001d4e0(void *this,undefined1 param_1)

{
  *(undefined1 *)((int)this + 0x1d) = param_1;
  *(code **)((int)this + 0x184) = FUN_10028e20;
  *(undefined1 *)((int)this + 0x11) = 0;
  switch(param_1) {
  case 1:
  case 2:
  case 3:
  case 7:
  case 8:
  case 0xc:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
    *(undefined4 *)((int)this + 0x184) = *(undefined4 *)((int)this + 0x194);
    *(undefined1 *)((int)this + 0x11) = 1;
    FUN_1001d7f0(this,*(char *)((int)this + 0x14));
    return;
  case 4:
  case 5:
  case 6:
  case 0xd:
    *(undefined4 *)((int)this + 0x184) = *(undefined4 *)((int)this + 0x198);
    *(undefined1 *)((int)this + 0x11) = 1;
  }
  FUN_1001d7f0(this,*(char *)((int)this + 0x14));
  return;
}


