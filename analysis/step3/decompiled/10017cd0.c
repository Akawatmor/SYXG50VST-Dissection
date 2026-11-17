/* Ghidra analysis of supplied S-YXG50.dll at 10017cd0 */

void __fastcall FUN_10017cd0(undefined4 *param_1)

{
  uint uVar1;
  undefined2 in_FPUControlWord;
  undefined4 local_8;
  
  local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
  *param_1 = local_8;
  uVar1 = FUN_10017180();
  if (uVar1 != 0) {
    param_1[1] = MXCSR;
    MXCSR = MXCSR & 0xffff1fff | 0xe000;
  }
  return;
}


