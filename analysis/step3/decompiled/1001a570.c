/* Ghidra analysis of supplied S-YXG50.dll at 1001a570 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_1001a570(int param_1)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int iVar11;
  
  uVar2 = *(uint *)(param_1 + 4);
  iVar3 = *(int *)(param_1 + 0x10);
  iVar4 = *(int *)(param_1 + 0x14);
  iVar11 = -0x80;
  do {
    *(float *)(iVar3 + 0x200 + iVar11 * 4) = (float)*(int *)(iVar3 + 0x200 + iVar11 * 4);
    iVar11 = iVar11 + 1;
  } while (iVar11 != 0);
  fVar5 = *(float *)(param_1 + 0xe0) * _DAT_10048de8;
  fVar8 = *(float *)(param_1 + 0xe4) * _DAT_10048de8;
  if ((uVar2 & 0x100000) != 0) {
    fVar6 = *(float *)(param_1 + 0x124) * fVar5;
    fVar7 = *(float *)(param_1 + 300) * fVar5;
    fVar10 = (*(float *)(param_1 + 0x128) * fVar8 - fVar6) * _DAT_10048dec;
    fVar9 = (*(float *)(param_1 + 300) * fVar8 - fVar7) * _DAT_10048dec;
    iVar11 = -0x80;
    do {
      fVar1 = *(float *)(iVar3 + 0x200 + iVar11 * 4);
      *(float *)(iVar4 + 0x400 + iVar11 * 4) =
           fVar1 * fVar7 + *(float *)(iVar4 + 0x400 + iVar11 * 4);
      *(float *)(iVar4 + 0x200 + iVar11 * 4) =
           fVar1 * fVar6 + *(float *)(iVar4 + 0x200 + iVar11 * 4);
      fVar7 = fVar7 + fVar9;
      fVar6 = fVar6 + fVar10;
      iVar11 = iVar11 + 1;
    } while (iVar11 != 0);
  }
  if ((uVar2 & 0x200000) != 0) {
    fVar5 = *(float *)(param_1 + 0x134) * fVar5;
    fVar8 = (*(float *)(param_1 + 0x138) * fVar8 - fVar5) * _DAT_10048dec;
    iVar11 = -0x80;
    do {
      *(float *)(iVar4 + 0x600 + iVar11 * 4) =
           *(float *)(iVar3 + 0x200 + iVar11 * 4) * fVar5 + *(float *)(iVar4 + 0x600 + iVar11 * 4);
      fVar5 = fVar5 + fVar8;
      iVar11 = iVar11 + 1;
    } while (iVar11 != 0);
  }
  return;
}


