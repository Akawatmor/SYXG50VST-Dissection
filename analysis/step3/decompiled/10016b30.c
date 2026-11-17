/* Ghidra analysis of supplied S-YXG50.dll at 10016b30 */

undefined2 __cdecl FUN_10016b30(int param_1)

{
  short sVar1;
  
  if ((*(byte *)(param_1 + 0x112) & 4) != 0) {
    sVar1 = FUN_100152b0(param_1);
    *(byte *)(param_1 + 0x112) = *(byte *)(param_1 + 0x112) & 0xfb;
    *(short *)(param_1 + 0x10a) = sVar1;
  }
  return *(undefined2 *)(param_1 + 0x10a);
}


