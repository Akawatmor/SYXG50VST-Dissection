/* Ghidra analysis of supplied S-YXG50.dll at 10015f60 */

uint __fastcall FUN_10015f60(undefined4 param_1,undefined4 param_2,uint param_3,byte param_4)

{
  int iVar1;
  
  iVar1 = CONCAT22((short)((uint)param_1 >> 0x10),(ushort)*(byte *)(param_3 + 0x14)) + -0x40;
  if ((short)iVar1 == 0) {
    return param_3 & 0xffffff00;
  }
  return (CONCAT22((short)(param_3 >> 0x10),(ushort)param_4) -
         CONCAT22((short)((uint)param_2 >> 0x10),(ushort)*(byte *)(param_3 + 0x15))) * iVar1 * 0x10
         >> 8;
}


