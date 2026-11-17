/* Ghidra analysis of supplied S-YXG50.dll at 10018ea0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_10018ea0(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  float10 fVar6;
  float10 fVar7;
  longlong lVar8;
  
  *(undefined4 *)(param_1 + 0xdc) = 0x80000;
  uVar3 = *(uint *)(*(int *)(param_1 + 0x24) + 0x20) & 0xff;
  iVar4 = uVar3 << 0xc;
  *(int *)(param_1 + 0xcc) = iVar4;
  uVar1 = *(uint *)(*(int *)(param_1 + 0x24) + 0x1c);
  uVar5 = uVar1 & 0x7f;
  if (-1 < (char)uVar1) {
    *(undefined4 *)(param_1 + 200) = 0;
    *(uint *)(param_1 + 0xc4) = (uVar3 != 0) + 1;
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x1c) + uVar5 * 4);
    *(undefined4 *)(param_1 + 0xe0) = 0x3f800000;
    *(undefined4 *)(param_1 + 0xd4) = uVar2;
    *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_1 + 0xe0);
    FUN_10018cf0(param_1);
    return;
  }
  *(int *)(param_1 + 200) = iVar4;
  *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(*(int *)(param_1 + 0x18) + uVar5 * 4);
  fVar6 = FUN_10019580(*(uint *)(param_1 + 200));
  *(float *)(param_1 + 0xe0) = (float)fVar6;
  if (*(int *)(param_1 + 0xcc) == 0) {
    *(undefined4 *)(param_1 + 0xc4) = 3;
    *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_1 + 0xe0);
    FUN_10018cf0(param_1);
    return;
  }
  fVar7 = (float10)_DAT_10048dd8;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  fVar7 = (fVar7 - fVar6) / (float10)*(int *)(param_1 + 0xcc);
  *(float *)(param_1 + 0xe8) = (float)fVar7;
  *(float *)(param_1 + 0xec) = (float)(fVar7 * (float10)*(int *)(param_1 + 0xcc) + fVar6);
  FUN_10019580(0x80000);
  lVar8 = __ftol();
  *(int *)(param_1 + 0xd4) = (int)lVar8;
  *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_1 + 0xe0);
  FUN_10018cf0(param_1);
  return;
}


