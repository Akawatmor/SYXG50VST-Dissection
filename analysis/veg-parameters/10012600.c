/* VEG parameter conversion, VA 10012600 */

undefined4 FUN_10012600(uint param_1,byte param_2)

{
  uint uVar1;
  int iVar2;
  undefined3 uVar3;
  short sVar4;
  int iVar5;
  
  iVar5 = param_1;
  iVar2 = CONCAT22((short)((uint)*(int *)(param_1 + 0x20) >> 0x10),
                   (ushort)*(byte *)(*(int *)(param_1 + 0x20) + 0x1b)) + -0x40;
  if ((short)iVar2 < 1) {
    param_1 = CONCAT22((short)((uint)iVar2 >> 0x10),(short)iVar2 >> 2);
  }
  else {
    param_1 = (uint)(iVar2 * 0x70) >> 8 & 0xff;
  }
  iVar5 = ((ushort)(short)*(char *)(iVar5 + 0x65) - param_1) + (uint)param_2;
  uVar1 = param_1 >> 0x10;
  sVar4 = (short)iVar5;
  param_1._0_1_ = (char)iVar5;
  uVar3 = (undefined3)(CONCAT22((short)uVar1,sVar4) >> 8);
  if (0x3f < sVar4) {
    return CONCAT31(uVar3,0x7e);
  }
  if (sVar4 < 0) {
    param_1._0_1_ = '\0';
  }
  return CONCAT31(uVar3,(char)param_1 << 1);
}


