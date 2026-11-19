/* VEG parameter conversion, VA 100050d0 */

int FUN_100050d0(int param_1,int param_2)

{
  if (((ushort)param_2 < 4) && (0x7c0 < (ushort)param_1)) {
    param_1 = 0x7c0;
  }
  return param_2 * 0x800 + param_1;
}


