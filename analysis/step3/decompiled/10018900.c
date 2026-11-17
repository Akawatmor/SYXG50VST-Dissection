/* Ghidra analysis of supplied S-YXG50.dll at 10018900 */

void __fastcall FUN_10018900(void *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  char *local_18;
  uint local_14;
  uint local_10;
  int local_c;
  
  iVar1 = *(int *)((int)param_1 + 8);
  FUN_100196d0(iVar1);
  local_18 = *(char **)((int)param_1 + 0x18);
  iVar5 = *(int *)((int)param_1 + 0xc);
  uVar4 = 0;
  uVar3 = 0;
  local_14 = 0;
  local_10 = 0;
  iVar6 = 0;
  local_c = 0x100;
  do {
    if (*local_18 != '\0') {
      uVar4 = FUN_100192f0(iVar5);
      *local_18 = (char)uVar4;
      uVar2 = FUN_10019740(iVar1);
      local_14 = local_14 + 1;
      uVar4 = local_10 + *(int *)(iVar5 + 0x2c);
      uVar3 = uVar3 + *(int *)(iVar5 + 0x28);
      iVar6 = iVar6 + uVar2 + *(int *)(iVar5 + 0x30);
      local_10 = uVar4;
    }
    iVar5 = iVar5 + 0x170;
    local_18 = local_18 + 1;
    local_c = local_c + -1;
  } while (local_c != 0);
  uVar2 = FUN_10019700(iVar1);
  uVar2 = iVar6 + uVar2;
  if (1 < local_14) {
    uVar3 = uVar3 / local_14;
    uVar4 = uVar4 / local_14;
    uVar2 = uVar2 / local_14;
  }
  FUN_10018c90(param_1,uVar3,uVar4,uVar2);
  return;
}


