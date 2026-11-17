/* Ghidra analysis of supplied S-YXG50.dll at 1001a310 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_1001a310(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  int iVar11;
  
  uVar6 = *(uint *)(param_1 + 4);
  iVar7 = *(int *)(param_1 + 0x10);
  iVar8 = *(int *)(param_1 + 0x14);
  fVar1 = *(float *)(param_1 + 0xbc);
  fVar2 = *(float *)(param_1 + 0xc0);
  fVar3 = *(float *)(param_1 + 0xb4);
  fVar9 = (*(float *)(param_1 + 0xb8) - fVar3) * _DAT_10048dec;
  iVar11 = -0x80;
  do {
    fVar1 = (((float)*(int *)(iVar7 + 0x200 + iVar11 * 4) - *(float *)(param_1 + 0xb0) * fVar1) -
            fVar2) * fVar3 + fVar1;
    fVar2 = fVar1 * fVar3 + fVar2;
    fVar3 = fVar3 + fVar9;
    *(float *)(iVar7 + 0x200 + iVar11 * 4) = fVar2;
    iVar11 = iVar11 + 1;
  } while (iVar11 != 0);
  *(float *)(param_1 + 0xc0) = fVar2;
  *(float *)(param_1 + 0xbc) = fVar1;
  fVar1 = *(float *)(param_1 + 0xe0) * _DAT_10048de8;
  fVar2 = *(float *)(param_1 + 0xe4) * _DAT_10048de8;
  if ((uVar6 & 0x100000) != 0) {
    fVar3 = *(float *)(param_1 + 0x124) * fVar1;
    fVar9 = *(float *)(param_1 + 300) * fVar1;
    fVar10 = (*(float *)(param_1 + 0x128) * fVar2 - fVar3) * _DAT_10048dec;
    fVar5 = (*(float *)(param_1 + 300) * fVar2 - fVar9) * _DAT_10048dec;
    iVar11 = -0x80;
    do {
      fVar4 = *(float *)(iVar7 + 0x200 + iVar11 * 4);
      *(float *)(iVar8 + 0x400 + iVar11 * 4) =
           fVar4 * fVar9 + *(float *)(iVar8 + 0x400 + iVar11 * 4);
      *(float *)(iVar8 + 0x200 + iVar11 * 4) =
           fVar4 * fVar3 + *(float *)(iVar8 + 0x200 + iVar11 * 4);
      fVar9 = fVar9 + fVar5;
      fVar3 = fVar3 + fVar10;
      iVar11 = iVar11 + 1;
    } while (iVar11 != 0);
  }
  if ((uVar6 & 0x200000) != 0) {
    fVar3 = *(float *)(param_1 + 0x134) * fVar1;
    fVar9 = (*(float *)(param_1 + 0x138) * fVar2 - fVar3) * _DAT_10048dec;
    iVar11 = -0x80;
    do {
      *(float *)(iVar8 + 0x600 + iVar11 * 4) =
           *(float *)(iVar7 + 0x200 + iVar11 * 4) * fVar3 + *(float *)(iVar8 + 0x600 + iVar11 * 4);
      fVar3 = fVar3 + fVar9;
      iVar11 = iVar11 + 1;
    } while (iVar11 != 0);
  }
  if ((uVar6 & 0x400000) != 0) {
    fVar3 = *(float *)(param_1 + 0x13c) * fVar1;
    fVar9 = *(float *)(param_1 + 0x144) * fVar1;
    fVar10 = (*(float *)(param_1 + 0x140) * fVar2 - fVar3) * _DAT_10048dec;
    fVar5 = (*(float *)(param_1 + 0x144) * fVar2 - fVar9) * _DAT_10048dec;
    iVar11 = -0x80;
    do {
      fVar4 = *(float *)(iVar7 + 0x200 + iVar11 * 4);
      *(float *)(iVar8 + 0xc00 + iVar11 * 4) =
           fVar4 * fVar9 + *(float *)(iVar8 + 0xc00 + iVar11 * 4);
      *(float *)(iVar8 + 0xa00 + iVar11 * 4) =
           fVar4 * fVar3 + *(float *)(iVar8 + 0xa00 + iVar11 * 4);
      fVar9 = fVar9 + fVar5;
      fVar3 = fVar3 + fVar10;
      iVar11 = iVar11 + 1;
    } while (iVar11 != 0);
  }
  if ((uVar6 & 0x800000) != 0) {
    fVar3 = *(float *)(param_1 + 0x14c) * fVar1;
    fVar1 = *(float *)(param_1 + 0x154) * fVar1;
    fVar9 = (*(float *)(param_1 + 0x150) * fVar2 - fVar3) * _DAT_10048dec;
    fVar2 = (*(float *)(param_1 + 0x154) * fVar2 - fVar1) * _DAT_10048dec;
    iVar11 = -0x80;
    do {
      fVar5 = *(float *)(iVar7 + 0x200 + iVar11 * 4);
      *(float *)(iVar8 + 0x1000 + iVar11 * 4) =
           fVar5 * fVar1 + *(float *)(iVar8 + 0x1000 + iVar11 * 4);
      *(float *)(iVar8 + 0xe00 + iVar11 * 4) =
           fVar5 * fVar3 + *(float *)(iVar8 + 0xe00 + iVar11 * 4);
      fVar1 = fVar1 + fVar2;
      fVar3 = fVar3 + fVar9;
      iVar11 = iVar11 + 1;
    } while (iVar11 != 0);
  }
  return;
}


