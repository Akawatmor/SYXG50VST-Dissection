/* Ghidra analysis of supplied S-YXG50.dll at 10018cf0 */

void __fastcall FUN_10018cf0(int param_1)

{
  uint uVar1;
  uint uVar2;
  float10 fVar3;
  longlong lVar4;
  
  if ((*(byte *)(param_1 + 4) & 2) != 0) {
    *(uint *)(param_1 + 0xd0) = (*(uint *)(*(int *)(param_1 + 0x24) + 0x28) & 0xff) << 0xc;
    uVar1 = *(uint *)(*(int *)(param_1 + 0x24) + 0x24);
    uVar2 = uVar1 & 0x7f;
    if ((char)uVar1 < '\0') {
      if ((*(int *)(param_1 + 0xc4) == 0) || (*(int *)(param_1 + 0xc4) == 4)) {
        uVar1 = FUN_100195d0();
        *(uint *)(param_1 + 200) = uVar1;
      }
      *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(*(int *)(param_1 + 0x20) + uVar2 * 4);
      if (0x5f < uVar2) {
        *(undefined4 *)(param_1 + 0xc4) = 4;
        *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffffd;
        fVar3 = FUN_10019580(*(uint *)(param_1 + 0xd0));
        fVar3 = (fVar3 - (float10)*(float *)(param_1 + 0xe0)) /
                (float10)(*(int *)(param_1 + 200) - *(int *)(param_1 + 0xd0));
        *(float *)(param_1 + 0xe8) = (float)fVar3;
        *(float *)(param_1 + 0xec) =
             (float)((float10)*(int *)(param_1 + 200) * fVar3 + (float10)*(float *)(param_1 + 0xe0))
        ;
        FUN_10019580(0x100000);
        lVar4 = __ftol();
        *(int *)(param_1 + 0xd8) = (int)lVar4;
        return;
      }
      *(undefined4 *)(param_1 + 0xc4) = 3;
      return;
    }
    *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(*(int *)(param_1 + 0x1c) + uVar2 * 4);
  }
  return;
}


