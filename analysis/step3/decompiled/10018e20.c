/* Ghidra analysis of supplied S-YXG50.dll at 10018e20 */

uint __fastcall FUN_10018e20(int param_1)

{
  uint uVar1;
  
  if ((*(byte *)(param_1 + 4) & 1) == 0) {
    uVar1 = 0xff;
  }
  else {
    if ((*(int *)(param_1 + 0xc4) == 0) || (*(int *)(param_1 + 0xc4) == 4)) {
      uVar1 = FUN_100195d0();
    }
    else {
      uVar1 = *(uint *)(param_1 + 200);
    }
    uVar1 = uVar1 >> 0xe & 0x3f;
    if ((*(uint *)(param_1 + 4) & 0x2000) == 0) {
      uVar1 = uVar1 | 0x40;
    }
    if ((2 < *(int *)(param_1 + 0xc4)) && (*(int *)(param_1 + 0xc4) < 5)) {
      return uVar1 | 0x80;
    }
  }
  return uVar1;
}


