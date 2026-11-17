/* Ghidra analysis of supplied S-YXG50.dll at 1001aab0 */

void __fastcall FUN_1001aab0(int param_1)

{
  if ((*(byte *)(param_1 + 4) & 2) != 0) {
    *(undefined4 *)(param_1 + 0x3c) =
         *(undefined4 *)
          (*(int *)(param_1 + 0x1c) + 0x80 + (*(uint *)(*(int *)(param_1 + 0x24) + 0x14) & 0x3f) * 4
          );
    if (*(char *)(*(int *)(param_1 + 0x24) + 0x14) < '\0') {
      *(undefined4 *)(param_1 + 0x38) = 0;
    }
  }
  return;
}


