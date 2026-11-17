/* Ghidra analysis of supplied S-YXG50.dll at 10019b00 */

void __fastcall FUN_10019b00(int param_1)

{
  float10 fVar1;
  
  FUN_10019a20(param_1);
  FUN_10019aa0(param_1);
  *(uint *)(param_1 + 0xa0) = *(uint *)(param_1 + 0xa4);
  fVar1 = FUN_10019bc0(*(uint *)(param_1 + 0xa4));
  *(float *)(param_1 + 0xb8) = (float)fVar1;
  *(float *)(param_1 + 0xb4) = (float)fVar1;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  return;
}


