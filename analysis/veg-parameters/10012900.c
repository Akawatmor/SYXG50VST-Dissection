/* VEG parameter conversion, VA 10012900 */

int FUN_10012900(byte param_1,byte param_2,byte param_3)

{
  int iVar1;
  
  iVar1 = (uint)param_1 - (uint)param_2;
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  iVar1 = (iVar1 << 0x10) / (int)(uint)*(ushort *)(&DAT_10046d48 + (uint)param_3 * 2);
  if (0xffff < iVar1) {
    iVar1 = 0xffff;
  }
  return iVar1;
}


