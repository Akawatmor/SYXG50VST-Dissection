/* VEG parameter conversion, VA 10012930 */

uint FUN_10012930(int param_1,byte param_2)

{
  return (uint)*(ushort *)(&DAT_10046d48 + (uint)param_2 * 2) * param_1 >> 0x10;
}


