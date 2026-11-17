/* Ghidra analysis of supplied S-YXG50.dll at 10019bc0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_10019bc0(uint param_1)

{
  if ((int)param_1 < 0) {
    param_1 = 0;
  }
  return (float10)(param_1 & 0xffff | 0x10000) /
         ((float10)(1 << (0x18U - (char)(param_1 >> 0x10) & 0x1f)) * (float10)_DAT_10048de4);
}


