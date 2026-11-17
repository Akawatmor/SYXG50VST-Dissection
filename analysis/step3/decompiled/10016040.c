/* Ghidra analysis of supplied S-YXG50.dll at 10016040 */

uint __fastcall FUN_10016040(undefined4 param_1,undefined4 param_2,uint param_3,byte param_4)

{
  int iVar1;
  
  iVar1 = CONCAT22((short)((uint)param_1 >> 0x10),(ushort)*(byte *)(param_3 + 0x12)) + -0x40;
  if ((short)iVar1 == 0) {
    return param_3 & 0xffffff00;
  }
  if (0 < (short)iVar1) {
    return (uint)((0x80 - CONCAT22((short)((uint)param_2 >> 0x10),(ushort)param_4)) * iVar1 * 0x24)
           >> 7;
  }
  return (uint)(CONCAT22((short)(param_3 >> 0x10),(ushort)param_4) * iVar1 * -0x24) >> 7;
}


