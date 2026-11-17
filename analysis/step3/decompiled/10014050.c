/* Ghidra analysis of supplied S-YXG50.dll at 10014050 */

void __cdecl FUN_10014050(int param_1)

{
  if ((*(char *)(param_1 + 2) != '\x01') && (*(char *)(param_1 + 8) == '\0')) {
    FUN_10013ea0(param_1,*(int *)(param_1 + 0x28),*(byte *)(*(int *)(param_1 + 0x28) + 0x2e),
                 *(byte *)(*(int *)(param_1 + 0x20) + 0x1a));
    if ((*(short *)(param_1 + 0x44) < *(short *)(param_1 + 0x42)) &&
       (*(short *)(param_1 + 0x46) != -0x8000)) {
      *(short *)(param_1 + 0x46) = -*(short *)(param_1 + 0x46);
    }
  }
  return;
}


