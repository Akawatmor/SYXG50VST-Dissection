/* Ghidra analysis of supplied S-YXG50.dll at 1001aa90 */

void __fastcall FUN_1001aa90(int param_1)

{
  if ((*(byte *)(param_1 + 4) & 2) != 0) {
    *(uint *)(param_1 + 100) = *(uint *)(*(int *)(param_1 + 0x24) + 0x10) & 0x1f;
    *(uint *)(param_1 + 0x60) = *(uint *)(*(int *)(param_1 + 0x24) + 0x10) >> 5 & 7;
  }
  return;
}


