/* Ghidra analysis of supplied S-YXG50.dll at 10016bd0 */

uint __cdecl FUN_10016bd0(int param_1)

{
  undefined4 in_EAX;
  uint uVar1;
  
  if ((*(byte *)(param_1 + 0x112) & 0x10) == 0) {
    return CONCAT31((int3)((uint)in_EAX >> 8),*(undefined1 *)(param_1 + 0x110));
  }
  uVar1 = FUN_10014cb0(param_1);
  *(byte *)(param_1 + 0x112) = *(byte *)(param_1 + 0x112) & 0xef;
  *(char *)(param_1 + 0x110) = (char)uVar1;
  return uVar1;
}


