/* Ghidra analysis of supplied S-YXG50.dll at 100163b0 */

void __cdecl FUN_100163b0(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0x20);
  uVar2 = FUN_10016b00(iVar1);
  FUN_100163f0((short)uVar2 + *(short *)(iVar1 + 0x114) + *(short *)(param_1 + 0x10),
               *(byte *)(param_1 + 0x89));
  return;
}


