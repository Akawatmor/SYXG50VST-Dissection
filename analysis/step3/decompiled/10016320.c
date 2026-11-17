/* Ghidra analysis of supplied S-YXG50.dll at 10016320 */

void __cdecl FUN_10016320(int param_1)

{
  int iVar1;
  
  iVar1 = *(short *)(param_1 + 0x6e) + -0x2000;
  if (0x1ffd < iVar1) {
    iVar1 = 0x2000;
  }
  *(short *)(param_1 + 0x114) =
       (short)((uint)((short)((*(char *)(param_1 + 0x23) + -0x40) * 800) * iVar1) >> 0x10);
  return;
}


