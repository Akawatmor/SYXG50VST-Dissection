/* Ghidra analysis of supplied S-YXG50.dll at 1001f870 */

void __fastcall FUN_1001f870(void *param_1)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint local_18;
  uint local_14;
  uint auStack_10 [2];
  uint local_8 [2];
  
  local_14 = 0;
  local_18 = 0;
  FUN_10017d60(local_8);
  (**(code **)((int)param_1 + 0x164))();
  if ((*(uint *)((int)param_1 + 0xc) & 4) != 0) {
    if ((*(uint *)((int)param_1 + 0xc) & 0x400) == 0) {
      uVar2 = FUN_10020080((float *)(*(int *)((int)param_1 + 8) + 0xc00),
                           (float *)(*(int *)((int)param_1 + 8) + 0xe00));
      if ((char)uVar2 != '\0') {
        *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) | 0x40;
        *(undefined4 *)((int)param_1 + 0x3c) = 0;
      }
    }
    if ((*(byte *)((int)param_1 + 0xc) & 0x40) != 0) {
      FUN_10017d60(auStack_10);
      (**(code **)((int)param_1 + 0x17c))();
      local_18 = FUN_10017d80(auStack_10);
      local_18 = local_18 >> 7;
      uVar2 = FUN_10020080((float *)(*(int *)((int)param_1 + 8) + 0xc00),
                           (float *)(*(int *)((int)param_1 + 8) + 0xe00));
      if ((char)uVar2 == '\0') {
        if (*(int *)((int)param_1 + 0x3c) < 0x400) {
          *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) | 0x400;
          *(int *)((int)param_1 + 0x3c) = *(int *)((int)param_1 + 0x3c) + 1;
          (**(code **)((int)param_1 + 0x170))();
        }
        else {
          *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) & 0xfffffbbf;
        }
      }
      else {
        *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) | 0x400;
        *(undefined4 *)((int)param_1 + 0x3c) = 0;
        (**(code **)((int)param_1 + 0x170))();
      }
    }
  }
  if ((*(uint *)((int)param_1 + 0xc) & 2) != 0) {
    if ((*(uint *)((int)param_1 + 0xc) & 0x200) == 0) {
      uVar2 = FUN_10020080((float *)(*(int *)((int)param_1 + 8) + 0x800),
                           (float *)(*(int *)((int)param_1 + 8) + 0xa00));
      if ((char)uVar2 != '\0') {
        *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) | 0x20;
        *(undefined4 *)((int)param_1 + 0x38) = 0;
      }
    }
    if ((*(byte *)((int)param_1 + 0xc) & 0x20) != 0) {
      FUN_10017d60(auStack_10);
      (**(code **)((int)param_1 + 0x178))();
      local_14 = FUN_10017d80(auStack_10);
      local_14 = local_14 >> 7;
      uVar2 = FUN_10020080((float *)(*(int *)((int)param_1 + 8) + 0x800),
                           (float *)(*(int *)((int)param_1 + 8) + 0xa00));
      if ((char)uVar2 == '\0') {
        if (*(int *)((int)param_1 + 0x38) < 0x100) {
          *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) | 0x200;
          *(int *)((int)param_1 + 0x38) = *(int *)((int)param_1 + 0x38) + 1;
          (**(code **)((int)param_1 + 0x16c))();
        }
        else {
          *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) & 0xfffffddf;
        }
      }
      else {
        *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) | 0x200;
        *(undefined4 *)((int)param_1 + 0x38) = 0;
        (**(code **)((int)param_1 + 0x16c))();
      }
    }
  }
  uVar3 = 0;
  if ((*(uint *)((int)param_1 + 0xc) & 1) != 0) {
    if ((*(uint *)((int)param_1 + 0xc) & 0x100) == 0) {
      sVar1 = FUN_10020040((float *)(*(int *)((int)param_1 + 8) + 0x400));
      if ((char)sVar1 != '\0') {
        *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) | 0x10;
        *(undefined4 *)((int)param_1 + 0x34) = 0;
      }
    }
    if ((*(byte *)((int)param_1 + 0xc) & 0x10) != 0) {
      FUN_10017d60(auStack_10);
      (**(code **)((int)param_1 + 0x174))();
      uVar3 = FUN_10017d80(auStack_10);
      uVar3 = uVar3 >> 7;
      uVar2 = FUN_10020080((float *)(*(int *)((int)param_1 + 8) + 0x400),
                           (float *)(*(int *)((int)param_1 + 8) + 0x600));
      if ((char)uVar2 == '\0') {
        if (*(int *)((int)param_1 + 0x34) < 0x400) {
          *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) | 0x100;
          *(int *)((int)param_1 + 0x34) = *(int *)((int)param_1 + 0x34) + 1;
          (**(code **)((int)param_1 + 0x168))();
        }
        else {
          *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) & 0xfffffeef;
        }
      }
      else {
        *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) | 0x100;
        *(undefined4 *)((int)param_1 + 0x34) = 0;
        (**(code **)((int)param_1 + 0x168))();
      }
    }
  }
  uVar4 = FUN_10017d80(local_8);
  FUN_1001ffb0(param_1,uVar4 >> 7,uVar3,local_14,local_18);
  return;
}


