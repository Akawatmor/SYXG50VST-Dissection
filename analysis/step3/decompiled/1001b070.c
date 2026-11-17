/* Ghidra analysis of supplied S-YXG50.dll at 1001b070 */

void __fastcall FUN_1001b070(int param_1)

{
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  int extraout_ECX_03;
  int iVar1;
  float10 fVar2;
  
  FUN_1001aef0(param_1);
  FUN_1001af20(extraout_ECX);
  FUN_1001af70(extraout_ECX_00);
  FUN_1001afb0(extraout_ECX_01);
  FUN_1001aff0(extraout_ECX_02);
  FUN_1001b030(extraout_ECX_03);
  *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_1 + 0x10c);
  iVar1 = *(int *)(param_1 + 0x1c);
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0x100);
  *(int *)(param_1 + 0xf0) = *(int *)(param_1 + 0xf4);
  *(undefined4 *)(param_1 + 0xf8) = *(undefined4 *)(iVar1 + 0x160);
  *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(iVar1 + 0x160);
  *(undefined4 *)(param_1 + 0x110) = *(undefined4 *)(iVar1 + 0x160);
  iVar1 = (*(int *)(param_1 + 100) * *(int *)(param_1 + 0x44) >>
          ((byte)*(undefined4 *)(param_1 + 0x58) & 0x1f)) + *(int *)(param_1 + 0xf4);
  fVar2 = FUN_10019580(*(int *)(param_1 + 0x100) + iVar1 + *(int *)(param_1 + 0x114));
  *(float *)(param_1 + 0x128) = (float)fVar2;
  *(float *)(param_1 + 0x124) = (float)fVar2;
  fVar2 = FUN_10019580(*(int *)(param_1 + 0x108) + iVar1 + *(int *)(param_1 + 0x114));
  *(float *)(param_1 + 0x130) = (float)fVar2;
  *(float *)(param_1 + 300) = (float)fVar2;
  fVar2 = FUN_10019580(*(int *)(param_1 + 0x118) + iVar1);
  *(float *)(param_1 + 0x138) = (float)fVar2;
  *(float *)(param_1 + 0x134) = (float)fVar2;
  fVar2 = FUN_10019580(*(int *)(param_1 + 0xfc) + iVar1 + *(int *)(param_1 + 0x11c));
  *(float *)(param_1 + 0x140) = (float)fVar2;
  *(float *)(param_1 + 0x13c) = (float)fVar2;
  fVar2 = FUN_10019580(*(int *)(param_1 + 0x108) + iVar1 + *(int *)(param_1 + 0x11c));
  *(float *)(param_1 + 0x148) = (float)fVar2;
  *(float *)(param_1 + 0x144) = (float)fVar2;
  fVar2 = FUN_10019580(*(int *)(param_1 + 0xfc) + *(int *)(param_1 + 0x120) + iVar1);
  *(float *)(param_1 + 0x150) = (float)fVar2;
  *(float *)(param_1 + 0x14c) = (float)fVar2;
  fVar2 = FUN_10019580(*(int *)(param_1 + 0x108) + *(int *)(param_1 + 0x120) + iVar1);
  *(float *)(param_1 + 0x158) = (float)fVar2;
  *(float *)(param_1 + 0x154) = (float)fVar2;
  return;
}


