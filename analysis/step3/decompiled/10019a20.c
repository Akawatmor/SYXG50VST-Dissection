/* Ghidra analysis of supplied S-YXG50.dll at 10019a20 */

void __fastcall FUN_10019a20(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  float10 fVar4;
  
  if ((*(byte *)(param_1 + 4) & 2) != 0) {
    fVar4 = FUN_10019580(((*(uint *)(*(int *)(param_1 + 0x24) + 8) >> 0xb & 0x1f) + 4) * 0x2000);
    *(float *)(param_1 + 0xb0) = (float)(fVar4 + fVar4);
    uVar1 = *(uint *)(*(int *)(param_1 + 0x24) + 8);
    uVar2 = uVar1 & 0x7ff;
    if (uVar2 != 0) {
      iVar3 = uVar2 + **(int **)(param_1 + 0xc);
      if (0x7ff < iVar3) {
        iVar3 = 0x7ff;
      }
      if ((((byte)(uVar1 >> 0xb) & 0x1f) < 4) && (0x7c0 < iVar3)) {
        iVar3 = 0x7c0;
      }
      uVar2 = iVar3 + 0x800;
    }
    *(uint *)(param_1 + 0xa4) = uVar2 << 8;
  }
  return;
}


