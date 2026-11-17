/* Ghidra analysis of supplied S-YXG50.dll at 10018820 */

int __fastcall FUN_10018820(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  return *(int *)(iVar1 + 0x30) + *(int *)(iVar1 + 0x28) + *(int *)(iVar1 + 0x20);
}


