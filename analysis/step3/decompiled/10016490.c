/* Ghidra analysis of supplied S-YXG50.dll at 10016490 */

void __cdecl FUN_10016490(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_100164f0((byte *)(param_1 + 0x38),*(byte *)(param_2 + 1));
  *(char *)(param_2 + 8) = (char)iVar1 << 1;
  return;
}


