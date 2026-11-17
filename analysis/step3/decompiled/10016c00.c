/* Ghidra analysis of supplied S-YXG50.dll at 10016c00 */

undefined1 __cdecl FUN_10016c00(int param_1)

{
  undefined1 uVar1;
  
  if ((*(byte *)(param_1 + 0x112) & 0x20) == 0) {
    return *(undefined1 *)(param_1 + 0x111);
  }
  uVar1 = FUN_10014bc0(param_1);
  *(byte *)(param_1 + 0x112) = *(byte *)(param_1 + 0x112) & 0xdf;
  *(undefined1 *)(param_1 + 0x111) = uVar1;
  return uVar1;
}


