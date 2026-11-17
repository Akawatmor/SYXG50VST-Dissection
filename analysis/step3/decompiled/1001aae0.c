/* Ghidra analysis of supplied S-YXG50.dll at 1001aae0 */

void __fastcall FUN_1001aae0(int param_1)

{
  if ((*(byte *)(param_1 + 4) & 2) != 0) {
    *(uint *)(param_1 + 0x5c) = *(uint *)(*(int *)(param_1 + 0x24) + 0x18) & 0xff;
  }
  return;
}


