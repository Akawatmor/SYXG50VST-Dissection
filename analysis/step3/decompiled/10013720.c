/* Ghidra analysis of supplied S-YXG50.dll at 10013720 */

int __cdecl FUN_10013720(short param_1,byte param_2)

{
  if (-1 < param_1) {
    return (int)((uint)*(ushort *)(&DAT_100471d0 + (uint)param_2 * 2) * (int)param_1) >> 0x10;
  }
  return (int)((uint)*(ushort *)(&DAT_100472d0 + (uint)param_2 * 2) * (int)param_1) >> 0x10;
}


