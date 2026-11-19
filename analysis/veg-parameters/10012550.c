/* VEG parameter conversion, VA 10012550 */

int __thiscall FUN_10012550(undefined4 param_1,int param_2,byte param_3)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  
  iVar3 = CONCAT22((short)((uint)param_1 >> 0x10),(ushort)*(byte *)(param_2 + 0x1a)) + -0x40;
  sVar2 = (short)iVar3;
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  if (sVar2 < 1) {
    iVar3 = CONCAT22(uVar1,(ushort)param_3) - CONCAT22((short)((uint)iVar3 >> 0x10),sVar2 >> 1);
    if (0x3f < (short)iVar3) {
      iVar3 = 0x3f;
      goto LAB_1001259f;
    }
  }
  else if ((byte)(&DAT_10046c98)[sVar2] < param_3) {
    iVar3 = CONCAT22(uVar1,(ushort)(byte)(&DAT_10046c98)[sVar2]);
  }
  else {
    iVar3 = CONCAT31((int3)(((uint)uVar1 << 0x10) >> 8),param_3);
  }
  if ((short)iVar3 == 0) {
    iVar3 = 4;
  }
LAB_1001259f:
  iVar3 = iVar3 << 1;
  if ((short)iVar3 == 0x7e) {
    iVar3 = 0xff;
  }
  return iVar3;
}


