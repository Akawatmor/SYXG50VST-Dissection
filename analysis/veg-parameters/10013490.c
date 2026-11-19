/* VEG parameter conversion, VA 10013490 */

void FUN_10013490(int *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (*(char *)((int)param_1 + 0x63ae) == '\x01') {
    uVar1 = (uint)*(byte *)(*(int *)(param_2 + 0x30) + 0xc);
  }
  else {
    uVar1 = CONCAT22((short)((uint)*(int *)(param_2 + 0x2c) >> 0x10),
                     (ushort)*(byte *)(*(int *)(param_2 + 0x2c) + 0xc));
  }
  uVar2 = (**(code **)(*param_1 + 0x4f4))(param_1,param_2,uVar1);
  (**(code **)(*param_1 + 0x4f0))(param_1,param_2,uVar2);
  return;
}


