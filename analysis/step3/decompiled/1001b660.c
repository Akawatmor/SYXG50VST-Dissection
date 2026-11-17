/* Ghidra analysis of supplied S-YXG50.dll at 1001b660 */

void __fastcall FUN_1001b660(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  float fVar12;
  float fVar13;
  float fVar14;
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
  float fVar35;
  
  pfVar2 = *(float **)(param_1 + 0x34);
  iVar11 = *(int *)(param_1 + 0x14);
  iVar3 = *(int *)(param_1 + 0x18);
  uVar4 = *(uint *)(param_1 + 0x38);
  fVar12 = *pfVar2;
  fVar13 = pfVar2[1];
  fVar14 = pfVar2[2];
  fVar15 = pfVar2[3];
  fVar16 = pfVar2[4] - fVar12;
  fVar19 = pfVar2[5] - fVar13;
  fVar22 = pfVar2[6] - fVar14;
  fVar25 = pfVar2[7] - fVar15;
  fVar18 = pfVar2[0x58];
  fVar21 = pfVar2[0x59];
  fVar24 = pfVar2[0x5a];
  fVar27 = pfVar2[0x5b];
  fVar17 = pfVar2[8];
  fVar20 = pfVar2[9];
  fVar23 = pfVar2[10];
  fVar26 = pfVar2[0xb];
  fVar28 = pfVar2[0xc];
  fVar29 = pfVar2[0xd];
  fVar30 = pfVar2[0xe];
  fVar31 = pfVar2[0xf];
  fVar32 = pfVar2[0x10];
  fVar33 = pfVar2[0x11];
  fVar34 = pfVar2[0x12];
  fVar35 = pfVar2[0x13];
  iVar10 = -0x800;
  do {
    pfVar1 = (float *)(iVar11 + 0xa00 + iVar10);
    fVar28 = fVar28 + ((*pfVar1 - fVar28 * fVar17) - fVar32) * fVar12;
    fVar29 = fVar29 + ((pfVar1[1] - fVar29 * fVar20) - fVar33) * fVar13;
    fVar30 = fVar30 + ((pfVar1[2] - fVar30 * fVar23) - fVar34) * fVar14;
    fVar31 = fVar31 + ((pfVar1[3] - fVar31 * fVar26) - fVar35) * fVar15;
    fVar32 = fVar32 + fVar28 * fVar12;
    fVar33 = fVar33 + fVar29 * fVar13;
    fVar34 = fVar34 + fVar30 * fVar14;
    fVar35 = fVar35 + fVar31 * fVar15;
    pfVar1 = (float *)(iVar11 + 0xa00 + iVar10);
    *pfVar1 = fVar32;
    pfVar1[1] = fVar33;
    pfVar1[2] = fVar34;
    pfVar1[3] = fVar35;
    fVar12 = fVar12 + fVar16 * fVar18;
    fVar13 = fVar13 + fVar19 * fVar21;
    fVar14 = fVar14 + fVar22 * fVar24;
    fVar15 = fVar15 + fVar25 * fVar27;
    iVar10 = iVar10 + 0x10;
  } while (iVar10 != 0);
  pfVar2[0xc] = fVar28;
  pfVar2[0xd] = fVar29;
  pfVar2[0xe] = fVar30;
  pfVar2[0xf] = fVar31;
  pfVar2[0x10] = fVar32;
  pfVar2[0x11] = fVar33;
  pfVar2[0x12] = fVar34;
  pfVar2[0x13] = fVar35;
  pfVar2[0x14] = pfVar2[0x14] * pfVar2[0x54];
  pfVar2[0x15] = pfVar2[0x15] * pfVar2[0x55];
  pfVar2[0x16] = pfVar2[0x16] * pfVar2[0x56];
  pfVar2[0x17] = pfVar2[0x17] * pfVar2[0x57];
  pfVar2[0x18] = pfVar2[0x18] * pfVar2[0x54];
  pfVar2[0x19] = pfVar2[0x19] * pfVar2[0x55];
  pfVar2[0x1a] = pfVar2[0x1a] * pfVar2[0x56];
  pfVar2[0x1b] = pfVar2[0x1b] * pfVar2[0x57];
  if ((uVar4 & 0x100000) != 0) {
    fVar17 = pfVar2[0x1c] * pfVar2[0x14];
    fVar20 = pfVar2[0x1d] * pfVar2[0x15];
    fVar23 = pfVar2[0x1e] * pfVar2[0x16];
    fVar26 = pfVar2[0x1f] * pfVar2[0x17];
    fVar28 = pfVar2[0x24] * pfVar2[0x14];
    fVar29 = pfVar2[0x25] * pfVar2[0x15];
    fVar30 = pfVar2[0x26] * pfVar2[0x16];
    fVar31 = pfVar2[0x27] * pfVar2[0x17];
    fVar32 = pfVar2[0x20] * pfVar2[0x18] - fVar17;
    fVar33 = pfVar2[0x21] * pfVar2[0x19] - fVar20;
    fVar34 = pfVar2[0x22] * pfVar2[0x1a] - fVar23;
    fVar35 = pfVar2[0x23] * pfVar2[0x1b] - fVar26;
    fVar16 = pfVar2[0x28] * pfVar2[0x18] - fVar28;
    fVar19 = pfVar2[0x29] * pfVar2[0x19] - fVar29;
    fVar22 = pfVar2[0x2a] * pfVar2[0x1a] - fVar30;
    fVar25 = pfVar2[0x2b] * pfVar2[0x1b] - fVar31;
    fVar12 = pfVar2[0x58];
    fVar13 = pfVar2[0x59];
    fVar14 = pfVar2[0x5a];
    fVar15 = pfVar2[0x5b];
    fVar18 = pfVar2[0x58];
    fVar21 = pfVar2[0x59];
    fVar24 = pfVar2[0x5a];
    fVar27 = pfVar2[0x5b];
    iVar10 = -0x200;
    do {
      pfVar1 = (float *)(iVar11 + 0xa00 + iVar10 * 4);
      fVar5 = *pfVar1;
      fVar6 = pfVar1[1];
      fVar7 = pfVar1[2];
      fVar8 = pfVar1[3];
      *(float *)(iVar3 + 0x200 + iVar10) =
           fVar5 * fVar17 + fVar7 * fVar23 + fVar6 * fVar20 + fVar8 * fVar26 +
           *(float *)(iVar3 + 0x200 + iVar10);
      *(float *)(iVar3 + 0x400 + iVar10) =
           fVar5 * fVar28 + fVar7 * fVar30 + fVar6 * fVar29 + fVar8 * fVar31 +
           *(float *)(iVar3 + 0x400 + iVar10);
      fVar17 = fVar17 + fVar32 * fVar12;
      fVar20 = fVar20 + fVar33 * fVar13;
      fVar23 = fVar23 + fVar34 * fVar14;
      fVar26 = fVar26 + fVar35 * fVar15;
      fVar28 = fVar28 + fVar16 * fVar18;
      fVar29 = fVar29 + fVar19 * fVar21;
      fVar30 = fVar30 + fVar22 * fVar24;
      fVar31 = fVar31 + fVar25 * fVar27;
      iVar10 = iVar10 + 4;
    } while (iVar10 != 0);
  }
  if ((uVar4 & 0x200000) != 0) {
    fVar18 = pfVar2[0x2c] * pfVar2[0x14];
    fVar21 = pfVar2[0x2d] * pfVar2[0x15];
    fVar24 = pfVar2[0x2e] * pfVar2[0x16];
    fVar27 = pfVar2[0x2f] * pfVar2[0x17];
    fVar17 = pfVar2[0x30] * pfVar2[0x18] - fVar18;
    fVar20 = pfVar2[0x31] * pfVar2[0x19] - fVar21;
    fVar23 = pfVar2[0x32] * pfVar2[0x1a] - fVar24;
    fVar26 = pfVar2[0x33] * pfVar2[0x1b] - fVar27;
    fVar12 = pfVar2[0x58];
    fVar13 = pfVar2[0x59];
    fVar14 = pfVar2[0x5a];
    fVar15 = pfVar2[0x5b];
    iVar10 = -0x200;
    do {
      pfVar1 = (float *)(iVar11 + 0xa00 + iVar10 * 4);
      *(float *)(iVar3 + 0x600 + iVar10) =
           *pfVar1 * fVar18 + pfVar1[2] * fVar24 + pfVar1[1] * fVar21 + pfVar1[3] * fVar27 +
           *(float *)(iVar3 + 0x600 + iVar10);
      fVar18 = fVar18 + fVar17 * fVar12;
      fVar21 = fVar21 + fVar20 * fVar13;
      fVar24 = fVar24 + fVar23 * fVar14;
      fVar27 = fVar27 + fVar26 * fVar15;
      iVar10 = iVar10 + 4;
    } while (iVar10 != 0);
  }
  if ((uVar4 & 0x400000) != 0) {
    fVar17 = pfVar2[0x34] * pfVar2[0x14];
    fVar20 = pfVar2[0x35] * pfVar2[0x15];
    fVar23 = pfVar2[0x36] * pfVar2[0x16];
    fVar26 = pfVar2[0x37] * pfVar2[0x17];
    fVar28 = pfVar2[0x3c] * pfVar2[0x14];
    fVar29 = pfVar2[0x3d] * pfVar2[0x15];
    fVar30 = pfVar2[0x3e] * pfVar2[0x16];
    fVar31 = pfVar2[0x3f] * pfVar2[0x17];
    fVar32 = pfVar2[0x38] * pfVar2[0x18] - fVar17;
    fVar33 = pfVar2[0x39] * pfVar2[0x19] - fVar20;
    fVar34 = pfVar2[0x3a] * pfVar2[0x1a] - fVar23;
    fVar35 = pfVar2[0x3b] * pfVar2[0x1b] - fVar26;
    fVar16 = pfVar2[0x40] * pfVar2[0x18] - fVar28;
    fVar19 = pfVar2[0x41] * pfVar2[0x19] - fVar29;
    fVar22 = pfVar2[0x42] * pfVar2[0x1a] - fVar30;
    fVar25 = pfVar2[0x43] * pfVar2[0x1b] - fVar31;
    fVar12 = pfVar2[0x58];
    fVar13 = pfVar2[0x59];
    fVar14 = pfVar2[0x5a];
    fVar15 = pfVar2[0x5b];
    fVar18 = pfVar2[0x58];
    fVar21 = pfVar2[0x59];
    fVar24 = pfVar2[0x5a];
    fVar27 = pfVar2[0x5b];
    iVar10 = -0x200;
    do {
      pfVar1 = (float *)(iVar11 + 0xa00 + iVar10 * 4);
      fVar5 = *pfVar1;
      fVar6 = pfVar1[1];
      fVar7 = pfVar1[2];
      fVar8 = pfVar1[3];
      *(float *)(iVar3 + 0xa00 + iVar10) =
           fVar5 * fVar17 + fVar7 * fVar23 + fVar6 * fVar20 + fVar8 * fVar26 +
           *(float *)(iVar3 + 0xa00 + iVar10);
      *(float *)(iVar3 + 0xc00 + iVar10) =
           fVar5 * fVar28 + fVar7 * fVar30 + fVar6 * fVar29 + fVar8 * fVar31 +
           *(float *)(iVar3 + 0xc00 + iVar10);
      fVar17 = fVar17 + fVar32 * fVar12;
      fVar20 = fVar20 + fVar33 * fVar13;
      fVar23 = fVar23 + fVar34 * fVar14;
      fVar26 = fVar26 + fVar35 * fVar15;
      fVar28 = fVar28 + fVar16 * fVar18;
      fVar29 = fVar29 + fVar19 * fVar21;
      fVar30 = fVar30 + fVar22 * fVar24;
      fVar31 = fVar31 + fVar25 * fVar27;
      iVar10 = iVar10 + 4;
    } while (iVar10 != 0);
  }
  if ((uVar4 & 0x800000) != 0) {
    fVar17 = pfVar2[0x44] * pfVar2[0x14];
    fVar20 = pfVar2[0x45] * pfVar2[0x15];
    fVar23 = pfVar2[0x46] * pfVar2[0x16];
    fVar26 = pfVar2[0x47] * pfVar2[0x17];
    fVar28 = pfVar2[0x4c] * pfVar2[0x14];
    fVar29 = pfVar2[0x4d] * pfVar2[0x15];
    fVar30 = pfVar2[0x4e] * pfVar2[0x16];
    fVar31 = pfVar2[0x4f] * pfVar2[0x17];
    fVar32 = pfVar2[0x48] * pfVar2[0x18] - fVar17;
    fVar33 = pfVar2[0x49] * pfVar2[0x19] - fVar20;
    fVar34 = pfVar2[0x4a] * pfVar2[0x1a] - fVar23;
    fVar35 = pfVar2[0x4b] * pfVar2[0x1b] - fVar26;
    fVar16 = pfVar2[0x50] * pfVar2[0x18] - fVar28;
    fVar19 = pfVar2[0x51] * pfVar2[0x19] - fVar29;
    fVar22 = pfVar2[0x52] * pfVar2[0x1a] - fVar30;
    fVar25 = pfVar2[0x53] * pfVar2[0x1b] - fVar31;
    fVar12 = pfVar2[0x58];
    fVar13 = pfVar2[0x59];
    fVar14 = pfVar2[0x5a];
    fVar15 = pfVar2[0x5b];
    fVar18 = pfVar2[0x58];
    fVar21 = pfVar2[0x59];
    fVar24 = pfVar2[0x5a];
    fVar27 = pfVar2[0x5b];
    iVar10 = -0x200;
    do {
      pfVar2 = (float *)(iVar11 + 0xa00 + iVar10 * 4);
      fVar5 = *pfVar2;
      fVar6 = pfVar2[1];
      fVar7 = pfVar2[2];
      fVar8 = pfVar2[3];
      *(float *)(iVar3 + 0xe00 + iVar10) =
           fVar5 * fVar17 + fVar7 * fVar23 + fVar6 * fVar20 + fVar8 * fVar26 +
           *(float *)(iVar3 + 0xe00 + iVar10);
      *(float *)(iVar3 + 0x1000 + iVar10) =
           fVar5 * fVar28 + fVar7 * fVar30 + fVar6 * fVar29 + fVar8 * fVar31 +
           *(float *)(iVar3 + 0x1000 + iVar10);
      fVar17 = fVar17 + fVar32 * fVar12;
      fVar20 = fVar20 + fVar33 * fVar13;
      fVar23 = fVar23 + fVar34 * fVar14;
      fVar26 = fVar26 + fVar35 * fVar15;
      fVar28 = fVar28 + fVar16 * fVar18;
      fVar29 = fVar29 + fVar19 * fVar21;
      fVar30 = fVar30 + fVar22 * fVar24;
      fVar31 = fVar31 + fVar25 * fVar27;
      iVar10 = iVar10 + 4;
    } while (iVar10 != 0);
  }
  iVar11 = 0;
  if (0 < *(int *)(param_1 + 0x3c)) {
    puVar9 = (undefined4 *)(param_1 + 0x50);
    do {
      *(undefined4 *)puVar9[-4] =
           *(undefined4 *)((int)puVar9 + *(int *)(param_1 + 0x34) + (-0x20 - param_1));
      *(undefined4 *)*puVar9 =
           *(undefined4 *)((int)puVar9 + *(int *)(param_1 + 0x34) + (-0x10 - param_1));
      iVar11 = iVar11 + 1;
      puVar9 = puVar9 + 1;
    } while (iVar11 < *(int *)(param_1 + 0x3c));
  }
  return;
}


