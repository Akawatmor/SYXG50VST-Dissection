/* Ghidra analysis of supplied S-YXG50.dll at 1001a6e0 */

void __fastcall FUN_1001a6e0(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(iVar1 + 0x48);
  *(uint *)(param_1 + 0x6c) = *(uint *)(iVar1 + 4) & 0xffff;
  *(uint *)(param_1 + 0x70) = *(uint *)(iVar1 + 0x50) & 0xffff;
  *(uint *)(param_1 + 0x74) = (*(uint *)(iVar1 + 0x44) & 0x3f) << 9;
  *(int *)(param_1 + 0x7c) = -*(int *)(param_1 + 0x6c);
  *(undefined4 *)(param_1 + 0x80) = 0;
  uVar2 = *(uint *)(iVar1 + 0x44) & 0xc0;
  if (uVar2 == 0) {
    if (*(int *)(param_1 + 0x70) != 0) {
      *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_1 + 0x94);
      FUN_1001a690(param_1);
      return;
    }
    *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_1 + 0x98);
  }
  else if (uVar2 == 0x80) {
    if (*(int *)(param_1 + 0x70) != 0) {
      *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_1 + 0x8c);
      FUN_1001a690(param_1);
      return;
    }
    *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_1 + 0x90);
    FUN_1001a690(param_1);
    return;
  }
  FUN_1001a690(param_1);
  return;
}


