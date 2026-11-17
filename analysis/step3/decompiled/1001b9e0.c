/* Ghidra analysis of supplied S-YXG50.dll at 1001b9e0 */

void __fastcall FUN_1001b9e0(int param_1)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  int iVar13;
  int iVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  
  iVar14 = *(int *)(param_1 + 0x34);
  iVar2 = *(int *)(param_1 + 0x14);
  iVar3 = *(int *)(param_1 + 0x18);
  uVar4 = *(uint *)(param_1 + 0x38);
  *(float *)(iVar14 + 0x50) = *(float *)(iVar14 + 0x50) * *(float *)(iVar14 + 0x150);
  *(float *)(iVar14 + 0x54) = *(float *)(iVar14 + 0x54) * *(float *)(iVar14 + 0x154);
  *(float *)(iVar14 + 0x58) = *(float *)(iVar14 + 0x58) * *(float *)(iVar14 + 0x158);
  *(float *)(iVar14 + 0x5c) = *(float *)(iVar14 + 0x5c) * *(float *)(iVar14 + 0x15c);
  *(float *)(iVar14 + 0x60) = *(float *)(iVar14 + 0x60) * *(float *)(iVar14 + 0x150);
  *(float *)(iVar14 + 100) = *(float *)(iVar14 + 100) * *(float *)(iVar14 + 0x154);
  *(float *)(iVar14 + 0x68) = *(float *)(iVar14 + 0x68) * *(float *)(iVar14 + 0x158);
  *(float *)(iVar14 + 0x6c) = *(float *)(iVar14 + 0x6c) * *(float *)(iVar14 + 0x15c);
  if ((uVar4 & 0x100000) != 0) {
    fVar15 = *(float *)(iVar14 + 0x70) * *(float *)(iVar14 + 0x50);
    fVar17 = *(float *)(iVar14 + 0x74) * *(float *)(iVar14 + 0x54);
    fVar19 = *(float *)(iVar14 + 0x78) * *(float *)(iVar14 + 0x58);
    fVar21 = *(float *)(iVar14 + 0x7c) * *(float *)(iVar14 + 0x5c);
    fVar23 = *(float *)(iVar14 + 0x90) * *(float *)(iVar14 + 0x50);
    fVar24 = *(float *)(iVar14 + 0x94) * *(float *)(iVar14 + 0x54);
    fVar25 = *(float *)(iVar14 + 0x98) * *(float *)(iVar14 + 0x58);
    fVar26 = *(float *)(iVar14 + 0x9c) * *(float *)(iVar14 + 0x5c);
    fVar27 = *(float *)(iVar14 + 0x80) * *(float *)(iVar14 + 0x60) - fVar15;
    fVar28 = *(float *)(iVar14 + 0x84) * *(float *)(iVar14 + 100) - fVar17;
    fVar29 = *(float *)(iVar14 + 0x88) * *(float *)(iVar14 + 0x68) - fVar19;
    fVar30 = *(float *)(iVar14 + 0x8c) * *(float *)(iVar14 + 0x6c) - fVar21;
    fVar31 = *(float *)(iVar14 + 0xa0) * *(float *)(iVar14 + 0x60) - fVar23;
    fVar32 = *(float *)(iVar14 + 0xa4) * *(float *)(iVar14 + 100) - fVar24;
    fVar33 = *(float *)(iVar14 + 0xa8) * *(float *)(iVar14 + 0x68) - fVar25;
    fVar34 = *(float *)(iVar14 + 0xac) * *(float *)(iVar14 + 0x6c) - fVar26;
    fVar5 = *(float *)(iVar14 + 0x160);
    fVar6 = *(float *)(iVar14 + 0x164);
    fVar7 = *(float *)(iVar14 + 0x168);
    fVar8 = *(float *)(iVar14 + 0x16c);
    fVar16 = *(float *)(iVar14 + 0x160);
    fVar18 = *(float *)(iVar14 + 0x164);
    fVar20 = *(float *)(iVar14 + 0x168);
    fVar22 = *(float *)(iVar14 + 0x16c);
    iVar13 = -0x200;
    do {
      pfVar1 = (float *)(iVar2 + 0xa00 + iVar13 * 4);
      fVar9 = *pfVar1;
      fVar10 = pfVar1[1];
      fVar11 = pfVar1[2];
      fVar12 = pfVar1[3];
      *(float *)(iVar3 + 0x200 + iVar13) =
           fVar9 * fVar15 + fVar11 * fVar19 + fVar10 * fVar17 + fVar12 * fVar21 +
           *(float *)(iVar3 + 0x200 + iVar13);
      *(float *)(iVar3 + 0x400 + iVar13) =
           fVar9 * fVar23 + fVar11 * fVar25 + fVar10 * fVar24 + fVar12 * fVar26 +
           *(float *)(iVar3 + 0x400 + iVar13);
      fVar15 = fVar15 + fVar27 * fVar5;
      fVar17 = fVar17 + fVar28 * fVar6;
      fVar19 = fVar19 + fVar29 * fVar7;
      fVar21 = fVar21 + fVar30 * fVar8;
      fVar23 = fVar23 + fVar31 * fVar16;
      fVar24 = fVar24 + fVar32 * fVar18;
      fVar25 = fVar25 + fVar33 * fVar20;
      fVar26 = fVar26 + fVar34 * fVar22;
      iVar13 = iVar13 + 4;
    } while (iVar13 != 0);
  }
  if ((uVar4 & 0x200000) != 0) {
    fVar16 = *(float *)(iVar14 + 0xb0) * *(float *)(iVar14 + 0x50);
    fVar18 = *(float *)(iVar14 + 0xb4) * *(float *)(iVar14 + 0x54);
    fVar20 = *(float *)(iVar14 + 0xb8) * *(float *)(iVar14 + 0x58);
    fVar22 = *(float *)(iVar14 + 0xbc) * *(float *)(iVar14 + 0x5c);
    fVar15 = *(float *)(iVar14 + 0xc0) * *(float *)(iVar14 + 0x60) - fVar16;
    fVar17 = *(float *)(iVar14 + 0xc4) * *(float *)(iVar14 + 100) - fVar18;
    fVar19 = *(float *)(iVar14 + 200) * *(float *)(iVar14 + 0x68) - fVar20;
    fVar21 = *(float *)(iVar14 + 0xcc) * *(float *)(iVar14 + 0x6c) - fVar22;
    fVar5 = *(float *)(iVar14 + 0x160);
    fVar6 = *(float *)(iVar14 + 0x164);
    fVar7 = *(float *)(iVar14 + 0x168);
    fVar8 = *(float *)(iVar14 + 0x16c);
    iVar14 = -0x200;
    do {
      pfVar1 = (float *)(iVar2 + 0xa00 + iVar14 * 4);
      *(float *)(iVar3 + 0x600 + iVar14) =
           *pfVar1 * fVar16 + pfVar1[2] * fVar20 + pfVar1[1] * fVar18 + pfVar1[3] * fVar22 +
           *(float *)(iVar3 + 0x600 + iVar14);
      fVar16 = fVar16 + fVar15 * fVar5;
      fVar18 = fVar18 + fVar17 * fVar6;
      fVar20 = fVar20 + fVar19 * fVar7;
      fVar22 = fVar22 + fVar21 * fVar8;
      iVar14 = iVar14 + 4;
    } while (iVar14 != 0);
  }
  return;
}


