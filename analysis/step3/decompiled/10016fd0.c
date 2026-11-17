/* Ghidra analysis of supplied S-YXG50.dll at 10016fd0 */

int __cdecl FUN_10016fd0(int param_1,short param_2)

{
  if ((*(byte *)(param_1 + 1) >> ((byte)param_2 & 0x1f) & 1) != 0) {
    return param_2 * 0x4e + 2 + param_1;
  }
  return 0;
}


