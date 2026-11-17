/* Ghidra analysis of supplied S-YXG50.dll at 1001b380 */

void __fastcall FUN_1001b380(int param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  float *pfVar4;
  
  **(int **)(param_1 + 0x164) = **(int **)(param_1 + 0x164) + 1;
  iVar2 = **(int **)(param_1 + 0x164);
  *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0x1c + iVar2 * 4) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined4 *)(*(int *)(param_1 + 0x15c) + -4 + iVar2 * 4) = *(undefined4 *)(param_1 + 0xb4);
  *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0xc + iVar2 * 4) = *(undefined4 *)(param_1 + 0xb8);
  iVar2 = iVar2 + -1;
  *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0x30 + iVar2 * 4) = *(undefined4 *)(param_1 + 0xbc);
  *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0x40 + iVar2 * 4) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0x50 + iVar2 * 4) = *(undefined4 *)(param_1 + 0xe0);
  *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0x60 + iVar2 * 4) = *(undefined4 *)(param_1 + 0xe4);
  *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0x70 + iVar2 * 4) = *(undefined4 *)(param_1 + 0x124);
  *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0x80 + iVar2 * 4) = *(undefined4 *)(param_1 + 0x128);
  *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0x90 + iVar2 * 4) = *(undefined4 *)(param_1 + 300);
  *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0xa0 + iVar2 * 4) = *(undefined4 *)(param_1 + 0x130);
  *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0xb0 + iVar2 * 4) = *(undefined4 *)(param_1 + 0x134);
  *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0xc0 + iVar2 * 4) = *(undefined4 *)(param_1 + 0x138);
  *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0xd0 + iVar2 * 4) = *(undefined4 *)(param_1 + 0x13c);
  *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0xe0 + iVar2 * 4) = *(undefined4 *)(param_1 + 0x140);
  *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0xf0 + iVar2 * 4) = *(undefined4 *)(param_1 + 0x144);
  *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0x100 + iVar2 * 4) = *(undefined4 *)(param_1 + 0x148);
  *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0x110 + iVar2 * 4) = *(undefined4 *)(param_1 + 0x14c);
  *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0x120 + iVar2 * 4) = *(undefined4 *)(param_1 + 0x150);
  *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0x130 + iVar2 * 4) = *(undefined4 *)(param_1 + 0x154);
  *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0x140 + iVar2 * 4) = *(undefined4 *)(param_1 + 0x158);
  *(int *)(*(int *)(param_1 + 0x168) + iVar2 * 4) = param_1 + 0xbc;
  *(int *)(*(int *)(param_1 + 0x16c) + iVar2 * 4) = param_1 + 0xc0;
  if ((*(uint *)(param_1 + 4) & 0x100000) != 0) {
    **(uint **)(param_1 + 0x160) = **(uint **)(param_1 + 0x160) | 0x100000;
  }
  if ((*(uint *)(param_1 + 4) & 0x200000) != 0) {
    **(uint **)(param_1 + 0x160) = **(uint **)(param_1 + 0x160) | 0x200000;
  }
  if ((*(uint *)(param_1 + 4) & 0x400000) != 0) {
    **(uint **)(param_1 + 0x160) = **(uint **)(param_1 + 0x160) | 0x400000;
  }
  if ((*(uint *)(param_1 + 4) & 0x800000) != 0) {
    **(uint **)(param_1 + 0x160) = **(uint **)(param_1 + 0x160) | 0x800000;
  }
  puVar3 = *(undefined8 **)(param_1 + 0x10);
  pfVar4 = (float *)((int)puVar3 + iVar2 * 4 + 0x200);
  iVar2 = -0x80;
  do {
    uVar1 = *puVar3;
    *pfVar4 = (float)(int)uVar1;
    pfVar4[4] = (float)(int)((ulonglong)uVar1 >> 0x20);
    puVar3 = puVar3 + 1;
    pfVar4 = pfVar4 + 8;
    iVar2 = iVar2 + 2;
  } while (iVar2 != 0);
  return;
}


