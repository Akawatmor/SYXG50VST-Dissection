/* Ghidra analysis of supplied S-YXG50.dll at 10014010 */

void __fastcall FUN_10014010(undefined4 param_1,undefined4 param_2,int param_3,byte param_4)

{
  int iVar1;
  
  iVar1 = FUN_10013df0(param_1,param_2,param_3,param_4);
  *(short *)(param_3 + 0x44) = (short)iVar1;
  if (((short)iVar1 < *(short *)(param_3 + 0x42)) && (*(short *)(param_3 + 0x46) != -0x8000)) {
    *(short *)(param_3 + 0x46) = -*(short *)(param_3 + 0x46);
  }
  return;
}


