/* VEG parameter conversion, VA 10012950 */

undefined4 __fastcall FUN_10012950(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  *(char *)(param_3 + 0x72) = *(char *)(param_3 + 0x72) + (char)param_4;
  param_4 = param_4 + CONCAT22((short)((uint)param_2 >> 0x10),(ushort)*(byte *)(param_3 + 0x6f));
  if (0x7f < (ushort)param_4) {
    param_4 = 0x7f;
  }
  *(char *)(param_3 + 0x6f) = (char)param_4;
  return CONCAT31((int3)((uint)param_4 >> 8),(char)param_4 << 1);
}


