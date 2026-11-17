/* Ghidra analysis of supplied S-YXG50.dll at 100164c0 */

void __cdecl FUN_100164c0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_100164f0((byte *)(param_1 + 0x22),*(byte *)(param_2 + 1));
  *(short *)(param_2 + 4) = (short)(char)iVar1 << 5;
  return;
}


