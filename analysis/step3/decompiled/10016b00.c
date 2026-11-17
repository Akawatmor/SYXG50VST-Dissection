/* Ghidra analysis of supplied S-YXG50.dll at 10016b00 */

uint __cdecl FUN_10016b00(int param_1)

{
  undefined4 in_EAX;
  uint uVar1;
  
  if ((*(byte *)(param_1 + 0x112) & 2) == 0) {
    return CONCAT22((short)((uint)in_EAX >> 0x10),*(undefined2 *)(param_1 + 0x108));
  }
  uVar1 = FUN_10016230(param_1);
  *(byte *)(param_1 + 0x112) = *(byte *)(param_1 + 0x112) & 0xfd;
  *(short *)(param_1 + 0x108) = (short)uVar1;
  return uVar1;
}


