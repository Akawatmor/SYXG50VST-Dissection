/* Ghidra analysis of supplied S-YXG50.dll at 10013df0 */

int __fastcall FUN_10013df0(undefined4 param_1,undefined4 param_2,int param_3,byte param_4)

{
  int iVar1;
  undefined4 in_EAX;
  
  iVar1 = CONCAT22((short)((uint)in_EAX >> 0x10),(ushort)param_4) * 2 + -0x80;
  return (iVar1 - CONCAT22((short)((uint)param_2 >> 0x10),
                           (short)((ushort)*(byte *)(param_3 + 0x56) * (short)iVar1) >> 8)) * 0x40;
}


