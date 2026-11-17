/* Ghidra analysis of supplied S-YXG50.dll at 10015380 */

uint __cdecl FUN_10015380(short param_1,int param_2)

{
  short sVar1;
  
  sVar1 = param_1 + -0x40;
  if (sVar1 == 0) {
    return 0;
  }
  if (0 < sVar1) {
    return (uint)(byte)(&DAT_10048058)[sVar1] * param_2 >> 8 & 0xff;
  }
  return -((uint)(byte)(&DAT_10048058)[-(int)sVar1] * param_2 >> 8 & 0xff);
}


