/* VEG parameter conversion, VA 100124f0 */

int __thiscall FUN_100124f0(undefined4 param_1,int param_2,char param_3)

{
  ushort uVar2;
  int iVar1;
  short sVar3;
  int iVar4;
  
  iVar4 = CONCAT22((short)((uint)param_1 >> 0x10),(ushort)*(byte *)(param_2 + 0x1a)) + -0x40;
  sVar3 = (short)iVar4;
  uVar2 = (ushort)((uint)param_2 >> 0x10);
  if (sVar3 < 1) {
    iVar1 = CONCAT22(uVar2,(ushort)(byte)(param_3 << 1));
    if (((byte)(param_3 << 1) < 0x5e) && (iVar1 = iVar1 - iVar4, 0x5e < (short)iVar1)) {
      iVar1 = 0x5e;
    }
    iVar1 = iVar1 + 0x21;
  }
  else {
    if ((byte)(&DAT_10046c98)[sVar3] < (byte)(param_3 + 0x21U)) {
      iVar1 = CONCAT31((int3)(((uint)uVar2 << 0x10) >> 8),(&DAT_10046c98)[sVar3]);
    }
    else {
      iVar1 = CONCAT22(uVar2,(ushort)(byte)(param_3 + 0x21U));
    }
    iVar1 = iVar1 << 1;
  }
  if ((short)iVar1 < 4) {
    iVar1 = 4;
  }
  return iVar1;
}


