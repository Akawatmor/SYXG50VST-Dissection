/* VEG parameter conversion, VA 10013440 */

void FUN_10013440(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  
  uVar1 = FUN_10013530(param_2,param_3);
  iVar2 = CONCAT22((short)((uint)uVar1 >> 0x10),(ushort)*(byte *)(param_3 + 0x1f)) -
          (CONCAT31((int3)((uint)extraout_ECX >> 8),(char)uVar1) & 0xffff00ff);
  if ((short)iVar2 < 0) {
    iVar2 = 0;
  }
  if (*(char *)(param_2 + 2) == '\x02') {
    iVar2 = (**(code **)(*param_1 + 0x4f4))(param_1,param_2,iVar2 * 2);
  }
  (**(code **)(*param_1 + 0x4f0))(param_1,param_2,iVar2);
  return;
}


