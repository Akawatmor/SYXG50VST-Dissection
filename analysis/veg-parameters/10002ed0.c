/* VEG parameter conversion, VA 10002ed0 */

void __thiscall FUN_10002ed0(int param_1,int *param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  iVar4 = 0;
  *(undefined1 *)(param_1 + 0xdc) = 0;
  local_8 = *param_2;
  local_4 = param_2[1];
  local_c = 0;
  if (*(int **)(param_1 + 0xe0) == (int *)0x0) {
    local_10 = 0;
  }
  else {
    local_10 = **(int **)(param_1 + 0xe0);
  }
  iVar5 = *(int *)(param_1 + 0x100);
  if (iVar5 == 0) {
    param_2 = (int *)0x0;
LAB_10002fc0:
    do {
      param_2 = (int *)((int)param_2 + 0x80);
      if (iVar4 < local_10) {
        iVar5 = iVar4 * 4 + 8;
        do {
          piVar2 = *(int **)(iVar5 + *(int *)(param_1 + 0xe0));
          if (*piVar2 == 1) {
            if ((int)param_2 < piVar2[2]) break;
            (**(code **)(**(int **)(param_1 + 0xb0) + 8))(*(int **)(param_1 + 0xb0),piVar2[6]);
          }
          else if (*piVar2 == 6) {
            if ((int)param_2 < piVar2[2]) break;
            (**(code **)(**(int **)(param_1 + 0xb0) + 0xc))
                      (*(int **)(param_1 + 0xb0),piVar2[6],piVar2[4]);
            iVar4 = local_c;
          }
          iVar4 = iVar4 + 1;
          iVar5 = iVar5 + 4;
          local_c = iVar4;
        } while (iVar4 < local_10);
      }
      iVar5 = *(int *)(param_1 + 0xe8) + 0x80;
      *(int *)(param_1 + 0xe8) = iVar5;
      for (uVar3 = ((uint)(iVar5 * 1000) / *(uint *)(param_1 + 0xd8) - *(int *)(param_1 + 0xec)) /
                   10; uVar3 != 0; uVar3 = uVar3 - 1) {
        (**(code **)(**(int **)(param_1 + 0xb0) + 0x10))(*(int **)(param_1 + 0xb0));
        *(int *)(param_1 + 0xec) = *(int *)(param_1 + 0xec) + 10;
      }
      if (*(int *)(param_1 + 0xe4) == *(int *)(param_1 + 0xe8)) {
        *(undefined4 *)(param_1 + 0xe8) = 0;
        *(undefined4 *)(param_1 + 0xec) = 0;
      }
      piVar2 = *(int **)(param_1 + 0xb0);
      iVar5 = *piVar2;
      if (param_3 < 0x81) goto LAB_100030fc;
      (**(code **)(iVar5 + 0x18))(piVar2,&local_8,param_4);
      local_8 = local_8 + 0x200;
      param_3 = param_3 + -0x80;
      local_4 = local_4 + 0x200;
    } while( true );
  }
  if (iVar5 < param_3) {
    FUN_100031e0(local_8,local_4,*(undefined4 *)(param_1 + 0xf8),*(undefined4 *)(param_1 + 0xfc),
                 iVar5,param_4);
    param_2 = *(int **)(param_1 + 0x100);
    local_8 = local_8 + (int)param_2 * 4;
    param_3 = param_3 - (int)param_2;
    local_4 = local_4 + (int)param_2 * 4;
    *(undefined4 *)(param_1 + 0x100) = 0;
    goto LAB_10002fc0;
  }
  FUN_100031e0(local_8,local_4,*(undefined4 *)(param_1 + 0xf8),*(undefined4 *)(param_1 + 0xfc),
               param_3,param_4);
  iVar5 = *(int *)(param_1 + 0x100);
  *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + param_3 * 4;
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + param_3 * 4;
LAB_1000315e:
  *(int *)(param_1 + 0x100) = iVar5 - param_3;
LAB_10003169:
  if (iVar4 < local_10) {
    iVar5 = iVar4 * 4 + 8;
    local_10 = local_10 - iVar4;
    do {
      piVar2 = *(int **)(iVar5 + *(int *)(param_1 + 0xe0));
      if (*piVar2 == 1) {
        (**(code **)(**(int **)(param_1 + 0xb0) + 8))(*(int **)(param_1 + 0xb0),piVar2[6]);
      }
      else if (*piVar2 == 6) {
        (**(code **)(**(int **)(param_1 + 0xb0) + 0xc))
                  (*(int **)(param_1 + 0xb0),piVar2[6],piVar2[4]);
      }
      iVar5 = iVar5 + 4;
      local_10 = local_10 + -1;
    } while (local_10 != 0);
  }
  *(undefined4 *)(param_1 + 0xe0) = 0;
  return;
LAB_100030fc:
  if (param_3 == 0x80) {
    (**(code **)(iVar5 + 0x18))(piVar2,&local_8,param_4);
    goto LAB_10003169;
  }
  piVar1 = (int *)(param_1 + 0xf0);
  (**(code **)(iVar5 + 0x18))(piVar2,piVar1,1);
  FUN_100031e0(local_8,local_4,*piVar1,*(undefined4 *)(param_1 + 0xf4),param_3,param_4);
  *(int *)(param_1 + 0xf8) = *piVar1 + param_3 * 4;
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xf4) + param_3 * 4;
  iVar5 = 0x80;
  goto LAB_1000315e;
}


