/* Ghidra analysis of supplied S-YXG50.dll at 1002fc00 */

void __thiscall FUN_1002fc00(void *this,char param_1)

{
  uint uVar1;
  
  if (param_1 != '\0') {
    uVar1 = FUN_10017180();
    if (uVar1 != 0) {
      *(code **)((int)this + 0x5c) = FUN_10030110;
      *(code **)((int)this + 0x60) = FUN_10030190;
      *(code **)((int)this + 0x70) = FUN_10030200;
    }
  }
  return;
}


