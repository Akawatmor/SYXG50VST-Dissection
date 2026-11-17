/* Ghidra analysis of supplied S-YXG50.dll at 10015ac0 */

void __cdecl FUN_10015ac0(int param_1)

{
  short sVar1;
  
  sVar1 = *(short *)(param_1 + 0x3c);
  if (sVar1 != -0x8000) {
    *(short *)(param_1 + 0x38) = *(short *)(param_1 + 0x38) + sVar1;
    if (sVar1 < 0) {
      if (*(short *)(param_1 + 0x3a) < *(short *)(param_1 + 0x38)) goto LAB_10015af3;
    }
    else if (*(short *)(param_1 + 0x38) < *(short *)(param_1 + 0x3a)) goto LAB_10015af3;
  }
  FUN_10015b10(param_1);
LAB_10015af3:
  *(short *)(param_1 + 0x36) = *(short *)(param_1 + 0x38) >> 2;
  return;
}


