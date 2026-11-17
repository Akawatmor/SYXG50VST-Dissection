/* Ghidra analysis of supplied S-YXG50.dll at 1001af20 */

void __fastcall FUN_1001af20(int param_1)

{
  uint uVar1;
  
  if ((*(byte *)(param_1 + 4) & 2) != 0) {
    uVar1 = (*(uint *)(*(int *)(param_1 + 0x24) + 0x40) >> 4 & 0xf) * 0x4000;
    *(uint *)(param_1 + 0x100) = uVar1;
    if (0x3bfff < uVar1) {
      *(undefined4 *)(param_1 + 0x100) = 0xfffff;
    }
    uVar1 = (*(uint *)(*(int *)(param_1 + 0x24) + 0x40) & 0xf) * 0x4000;
    *(uint *)(param_1 + 0x10c) = uVar1;
    if (0x3bfff < uVar1) {
      *(undefined4 *)(param_1 + 0x10c) = 0xfffff;
    }
  }
  return;
}


