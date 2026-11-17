/* Ghidra analysis of supplied S-YXG50.dll at 100165b0 */

int __cdecl FUN_100165b0(byte param_1,char param_2,byte param_3,byte param_4)

{
  undefined4 in_EAX;
  int iVar1;
  uint uVar2;
  
  if (param_3 != 0) {
    if (param_2 != '\0') {
      uVar2 = (uint)param_3;
      if (param_2 < '\0') {
        iVar1 = (int)(short)((ushort)param_1 * (short)param_2);
        iVar1 = iVar1 / (int)uVar2 +
                CONCAT22((short)((uint)(iVar1 % (int)uVar2) >> 0x10),(ushort)param_4);
        if ((short)iVar1 < 0) {
          return -0x40;
        }
      }
      else {
        iVar1 = (int)(short)((ushort)param_1 * (short)param_2);
        iVar1 = iVar1 / (int)uVar2 +
                CONCAT22((short)((uint)(iVar1 % (int)uVar2) >> 0x10),(ushort)param_4);
        if (0x7f < (short)iVar1) {
          return 0x3f;
        }
      }
      goto LAB_10016613;
    }
  }
  iVar1 = CONCAT22((short)((uint)in_EAX >> 0x10),(ushort)param_4);
LAB_10016613:
  return iVar1 + -0x40;
}


