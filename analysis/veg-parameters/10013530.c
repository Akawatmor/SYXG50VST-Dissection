/* VEG parameter conversion, VA 10013530 */

uint __thiscall FUN_10013530(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = CONCAT22((short)((uint)param_1 >> 0x10),(short)*(char *)(param_3 + 0x4d)) + -0x40;
  if ((short)iVar1 == 0) {
    return param_3 & 0xffffff00;
  }
  uVar2 = (undefined2)((uint)param_2 >> 0x10);
  if (0 < (short)iVar1) {
    iVar1 = (0x80 - CONCAT22(uVar2,(ushort)*(byte *)(param_2 + 0x73))) * iVar1 * 0x12;
    return CONCAT31((int3)((uint)iVar1 >> 8),(char)((uint)iVar1 >> 8));
  }
  iVar1 = CONCAT22(uVar2,(ushort)*(byte *)(param_2 + 0x73)) * iVar1 * -0x12;
  return CONCAT31((int3)((uint)iVar1 >> 8),(char)((uint)iVar1 >> 8));
}


