/* Ghidra analysis of supplied S-YXG50.dll at 10015460 */

void FUN_10015460(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  short sVar4;
  undefined2 uVar5;
  int iVar6;
  undefined4 unaff_EBX;
  int *unaff_ESI;
  
  iVar2 = param_2;
  *(undefined1 *)(param_2 + 3) = *(undefined1 *)(param_4 + 1);
  iVar1 = *(int *)(param_2 + 0x20);
  if (*(char *)(param_2 + 2) == '\0') {
    uVar3 = (ushort)*(byte *)((uint)*(byte *)(param_4 + 1) % 0xc + 0x3a + iVar1) +
            *(short *)((int)param_1 + 0x63a6);
  }
  else {
    uVar3 = (ushort)*(byte *)(*(int *)(param_2 + 0x2c) + 1);
  }
  param_2._0_2_ =
       (ushort)*(byte *)(param_3 + 0xe) +
       ((short)*(char *)(param_4 + 6) - (ushort)*(byte *)(*(int *)(param_4 + 0x24) + 1)) * 100 +
       (short)*(char *)(*(int *)(param_4 + 0x24) + 2) + uVar3 + -0x80 +
       (short)*(char *)(param_4 + 7);
  sVar4 = ((*(char *)(iVar1 + 9) + -8) * 0x10 + (short)*(char *)(iVar1 + 10)) * 0x10;
  if (sVar4 != 0) {
    if (*(char *)((int)param_1 + 0x63ae) == '\0') {
      iVar6 = FUN_10013720(sVar4,*(byte *)(param_4 + 1));
      sVar4 = (short)iVar6;
    }
    else {
      iVar6 = FUN_100136f0(sVar4);
      sVar4 = (short)iVar6;
    }
    param_2._0_2_ = (short)param_2 + sVar4;
  }
  *(short *)(iVar2 + 0x10) = (short)param_2;
  if (*(char *)(iVar1 + 7) == '\0') {
    param_2._0_2_ = (short)param_2 + *(short *)((int)param_1 + 0x6a0a);
  }
  (**(code **)(*param_1 + 0x54c))(param_1,iVar2,param_3,param_4);
  sVar4 = *(short *)(iVar2 + 0x16);
  (**(code **)(*unaff_ESI + 0x598))(unaff_ESI,iVar2,unaff_EBX,param_4);
  uVar5 = FUN_100161b0((short)param_2 + sVar4 + *(short *)(iVar2 + 0x36),iVar2);
  *(undefined2 *)(unaff_ESI + 0x71) = uVar5;
  return;
}


