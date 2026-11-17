/* Ghidra analysis of supplied S-YXG50.dll at 10016a90 */

void __cdecl FUN_10016a90(int param_1)

{
  int iVar1;
  
  *(undefined2 *)(param_1 + 0x112) = 0x3f;
  for (iVar1 = *(int *)(param_1 + 0xdc); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x24)) {
    *(ushort *)(iVar1 + 0xc) = *(ushort *)(iVar1 + 0xc) | 7;
  }
  return;
}


