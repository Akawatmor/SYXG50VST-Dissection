/* Ghidra analysis of supplied S-YXG50.dll at 100140a0 */

void __cdecl FUN_100140a0(int param_1)

{
  if ((*(char *)(param_1 + 2) != '\x01') && (*(char *)(param_1 + 8) == '\x04')) {
    FUN_10013ee0(param_1,*(byte *)(*(int *)(param_1 + 0x28) + 0x31),
                 *(byte *)(*(int *)(param_1 + 0x20) + 0x1c));
    if (*(short *)(param_1 + 0x44) < *(short *)(param_1 + 0x42)) {
      *(short *)(param_1 + 0x46) = -*(short *)(param_1 + 0x46);
    }
  }
  return;
}


