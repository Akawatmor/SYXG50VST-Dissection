/* Ghidra analysis of supplied S-YXG50.dll at 1002fcd0 */

void __fastcall FUN_1002fcd0(void *param_1)

{
  uint uVar1;
  uint auStack_14 [2];
  undefined4 local_8;
  undefined4 uStack_4;
  
  auStack_14[1] = 0x1002fcdf;
  FUN_10017d60(&local_8);
  if (*(char *)((int)param_1 + 8) != '\0') {
    auStack_14[1] = 0x80;
    auStack_14[0] = (int)param_1 + 0xc;
    FUN_1002f6d0((int)param_1 + 0x14);
  }
  FUN_1002fc80((int)param_1);
  (**(code **)((int)param_1 + 0x5c))(uStack_4);
  if (*(char *)((int)param_1 + 100) != '\0') {
    (**(code **)((int)param_1 + 0x70))();
  }
  uVar1 = FUN_10017d80(auStack_14);
  FUN_100300f0(param_1,uVar1 >> 7);
  return;
}


