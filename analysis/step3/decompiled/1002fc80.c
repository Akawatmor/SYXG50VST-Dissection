/* Ghidra analysis of supplied S-YXG50.dll at 1002fc80 */

void __fastcall FUN_1002fc80(int param_1)

{
  float fVar1;
  
  if (*(float *)(param_1 + 0x48) != *(float *)(param_1 + 0x4c)) {
    if (*(float *)(param_1 + 0x48) <= *(float *)(param_1 + 0x4c)) {
      fVar1 = *(float *)(param_1 + 0x50) + *(float *)(param_1 + 0x48);
      *(float *)(param_1 + 0x48) = fVar1;
      if (*(float *)(param_1 + 0x4c) < fVar1) {
        *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_1 + 0x4c);
      }
    }
    else {
      fVar1 = *(float *)(param_1 + 0x48) - *(float *)(param_1 + 0x50);
      *(float *)(param_1 + 0x48) = fVar1;
      if (fVar1 < *(float *)(param_1 + 0x4c)) {
        *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_1 + 0x4c);
        return;
      }
    }
  }
  return;
}


