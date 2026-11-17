/* Ghidra analysis of supplied S-YXG50.dll at 10015f10 */

int __cdecl FUN_10015f10(byte param_1,int param_2)

{
  short sVar1;
  
  sVar1 = (short)param_2;
  if (-1 < sVar1) {
    if (sVar1 != 0) {
      param_2 = param_2 + 1;
    }
    return ((int)(short)param_2 - (int)(short)((ushort)((uint)param_1 * param_2 >> 8) & 0xff)) *
           0x4b >> 1;
  }
  return -((short)(((ushort)(-((uint)param_1 * param_2) >> 8) & 0xff) + sVar1) * -0x4b >> 1);
}


