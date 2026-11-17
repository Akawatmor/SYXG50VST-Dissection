/* Ghidra analysis of supplied S-YXG50.dll at 10015e50 */

uint __cdecl FUN_10015e50(int param_1,byte param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (-1 < (short)param_3) {
    if ((short)param_3 != 0) {
      param_3 = param_3 + 1;
    }
    iVar1 = param_3 - ((uint)param_2 * param_3 >> 8 & 0xff);
    param_3._0_2_ = (short)iVar1 * 0x4b;
    uVar2 = (uint)*(byte *)(param_1 + 0x11);
    if (uVar2 == 0) {
      return (uint)(ushort)((short)param_3 >> 2);
    }
    if (uVar2 == 1) {
      return (uint)(ushort)((short)param_3 >> 1);
    }
    iVar3 = uVar2 - 3;
    if (iVar3 == 0) {
      return iVar1 * 0x96;
    }
    goto LAB_10015efb;
  }
  iVar1 = (-((uint)param_2 * param_3) >> 8 & 0xff) + param_3;
  param_3._0_2_ = (short)iVar1 * -0x4b;
  uVar2 = (uint)*(byte *)(param_1 + 0x11);
  if (uVar2 == 0) {
    param_3._0_2_ = (short)param_3 >> 1;
    iVar3 = 0;
LAB_10015eec:
    param_3._0_2_ = (short)param_3 >> 1;
  }
  else {
    iVar3 = uVar2 - 1;
    if (iVar3 == 0) goto LAB_10015eec;
    iVar3 = uVar2 - 3;
    if (iVar3 == 0) {
      return iVar1 * 0x96 & 0xffff;
    }
  }
  param_3._0_2_ = -(short)param_3;
LAB_10015efb:
  return CONCAT22((short)((uint)iVar3 >> 0x10),(short)param_3);
}


