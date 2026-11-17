/* Ghidra analysis of supplied S-YXG50.dll at 10016ba0 */

short __cdecl FUN_10016ba0(int param_1)

{
  short sVar1;
  
  if ((*(byte *)(param_1 + 0x112) & 8) == 0) {
    return *(short *)(param_1 + 0x10e);
  }
  sVar1 = FUN_10014ac0(param_1);
  *(byte *)(param_1 + 0x112) = *(byte *)(param_1 + 0x112) & 0xf7;
  *(short *)(param_1 + 0x10e) = sVar1;
  return sVar1;
}


