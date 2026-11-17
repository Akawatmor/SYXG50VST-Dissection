/* Ghidra analysis of supplied S-YXG50.dll at 1001c320 */

void __thiscall FUN_1001c320(void *this,byte param_1)

{
  if (param_1 < 3) {
    if (param_1 == 2) {
      FUN_10017c70(*(undefined4 **)((int)this + 0x54),0x80010);
      return;
    }
    if (param_1 == 0) {
      FUN_10017c70(*(undefined4 **)((int)this + 0x4c),0x80000);
      return;
    }
    if (param_1 == 1) {
      FUN_10017c70(*(undefined4 **)((int)this + 0x50),0x20010);
      return;
    }
  }
  else if ((param_1 == 0xf) || (param_1 == 0xff)) {
    FUN_10017c70(*(undefined4 **)((int)this + 0x4c),0x80000);
    FUN_10017c70(*(undefined4 **)((int)this + 0x50),0x20010);
    FUN_10017c70(*(undefined4 **)((int)this + 0x54),0x80010);
  }
  return;
}


