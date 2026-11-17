/* Ghidra analysis of supplied S-YXG50.dll at 10015f90 */

uint __fastcall FUN_10015f90(undefined4 param_1,undefined4 param_2,int param_3,byte param_4)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = CONCAT22((short)((uint)param_3 >> 0x10),(ushort)*(byte *)(param_3 + 0x13)) - 0x40;
  if ((short)uVar1 == 0) {
    return uVar1 & 0xffffff00;
  }
  iVar2 = uVar1 * 0x10;
  if (-1 < (short)iVar2) {
    return (uint)(CONCAT22((short)((uint)iVar2 >> 0x10),(ushort)param_4) * iVar2) >> 8;
  }
  return (uint)-((0x80 - CONCAT22((short)((uint)param_2 >> 0x10),(ushort)param_4)) * iVar2) >> 8;
}


