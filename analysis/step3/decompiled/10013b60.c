/* Ghidra analysis of supplied S-YXG50.dll at 10013b60 */

void __cdecl FUN_10013b60(int param_1)

{
  short sVar1;
  
  sVar1 = *(short *)(param_1 + 0x46);
  if (sVar1 != -0x8000) {
    *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + sVar1;
    if (sVar1 < 0) {
      if (*(short *)(param_1 + 0x44) < *(short *)(param_1 + 0x42)) goto LAB_10013b93;
    }
    else if (*(short *)(param_1 + 0x42) < *(short *)(param_1 + 0x44)) goto LAB_10013b93;
  }
  FUN_10013bb0(param_1);
LAB_10013b93:
  *(short *)(param_1 + 0x1a) = *(short *)(param_1 + 0x42) >> 2;
  return;
}


