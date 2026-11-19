/* VEG parameter conversion, VA 10012670 */

undefined4 __thiscall FUN_10012670(undefined4 param_1,int param_2,byte param_3)

{
  ushort uVar2;
  int iVar1;
  short sVar3;
  int iVar4;
  
  iVar4 = CONCAT22((short)((uint)param_1 >> 0x10),(ushort)*(byte *)(*(int *)(param_2 + 0x20) + 0x1c)
                  ) + -0x40;
  sVar3 = (short)iVar4;
  uVar2 = (ushort)((uint)*(int *)(param_2 + 0x20) >> 0x10);
  if (sVar3 < 1) {
    iVar1 = CONCAT22(uVar2,(ushort)param_3);
    if ((param_3 < 0x38) &&
       (iVar1 = iVar1 - CONCAT22((short)((uint)iVar4 >> 0x10),sVar3 >> 1), 0x37 < (short)iVar1)) {
      iVar1 = 0x37;
    }
  }
  else if ((byte)(&DAT_10046cd8)[(short)(sVar3 + (ushort)*(byte *)(param_2 + 0x68))] < param_3) {
    iVar1 = CONCAT22(uVar2,(ushort)(byte)(&DAT_10046cd8)
                                         [(short)(sVar3 + (ushort)*(byte *)(param_2 + 0x68))]);
  }
  else {
    iVar1 = CONCAT31((int3)(((uint)uVar2 << 0x10) >> 8),param_3);
  }
  iVar1 = iVar1 + CONCAT22((short)((uint)param_2 >> 0x10),(short)*(char *)(param_2 + 0x65));
  if ((short)iVar1 < 1) {
    return 2;
  }
  if (0x3f < (short)iVar1) {
    iVar1 = 0x3f;
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),(char)iVar1 << 1);
}


