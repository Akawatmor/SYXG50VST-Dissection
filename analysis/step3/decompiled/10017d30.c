/* Ghidra analysis of supplied S-YXG50.dll at 10017d30 */

void __fastcall FUN_10017d30(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_10017180();
  if (uVar1 != 0) {
    MXCSR = *(undefined4 *)(param_1 + 4);
  }
  return;
}


