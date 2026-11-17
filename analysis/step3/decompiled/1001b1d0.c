/* Ghidra analysis of supplied S-YXG50.dll at 1001b1d0 */

void __fastcall FUN_1001b1d0(int param_1)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  float10 fVar6;
  
  cVar3 = FUN_10019540((int *)(param_1 + 0xf0),*(int *)(param_1 + 0xf4),*(int *)(param_1 + 0xf8));
  if (cVar3 == '\0') {
    uVar4 = *(uint *)(param_1 + 4) | 0x10000;
  }
  else {
    uVar4 = *(uint *)(param_1 + 4) & 0xfffeffff;
  }
  *(uint *)(param_1 + 4) = uVar4;
  piVar1 = (int *)(param_1 + 0xfc);
  cVar3 = FUN_10019540(piVar1,*(int *)(param_1 + 0x100),*(int *)(param_1 + 0x104));
  if (cVar3 == '\0') {
    uVar4 = *(uint *)(param_1 + 4) | 0x20000;
  }
  else {
    uVar4 = *(uint *)(param_1 + 4) & 0xfffdffff;
  }
  *(uint *)(param_1 + 4) = uVar4;
  piVar2 = (int *)(param_1 + 0x108);
  cVar3 = FUN_10019540(piVar2,*(int *)(param_1 + 0x10c),*(int *)(param_1 + 0x110));
  if (cVar3 == '\0') {
    uVar4 = *(uint *)(param_1 + 4) | 0x40000;
  }
  else {
    uVar4 = *(uint *)(param_1 + 4) & 0xfffbffff;
  }
  *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x128);
  iVar5 = (*(int *)(param_1 + 100) * *(int *)(param_1 + 0x44) >>
          ((byte)*(undefined4 *)(param_1 + 0x58) & 0x1f)) + *(int *)(param_1 + 0xf0);
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x130);
  *(undefined4 *)(param_1 + 0x13c) = *(undefined4 *)(param_1 + 0x140);
  *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(param_1 + 0x148);
  *(undefined4 *)(param_1 + 0x154) = *(undefined4 *)(param_1 + 0x158);
  *(uint *)(param_1 + 4) = uVar4;
  *(undefined4 *)(param_1 + 0x134) = *(undefined4 *)(param_1 + 0x138);
  *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(param_1 + 0x150);
  fVar6 = FUN_10019580(*piVar1 + *(int *)(param_1 + 0x114) + iVar5);
  *(float *)(param_1 + 0x128) = (float)fVar6;
  fVar6 = FUN_10019580(*(int *)(param_1 + 0x114) + *piVar2 + iVar5);
  *(float *)(param_1 + 0x130) = (float)fVar6;
  fVar6 = FUN_10019580(*(int *)(param_1 + 0x118) + iVar5);
  *(float *)(param_1 + 0x138) = (float)fVar6;
  fVar6 = FUN_10019580(*piVar1 + *(int *)(param_1 + 0x11c) + iVar5);
  *(float *)(param_1 + 0x140) = (float)fVar6;
  fVar6 = FUN_10019580(*(int *)(param_1 + 0x11c) + *piVar2 + iVar5);
  *(float *)(param_1 + 0x148) = (float)fVar6;
  fVar6 = FUN_10019580(*piVar1 + iVar5 + *(int *)(param_1 + 0x120));
  *(float *)(param_1 + 0x150) = (float)fVar6;
  fVar6 = FUN_10019580(*piVar2 + iVar5 + *(int *)(param_1 + 0x120));
  *(float *)(param_1 + 0x158) = (float)fVar6;
  return;
}


