/* Ghidra analysis of supplied S-YXG50.dll at 1001b030 */

void __fastcall FUN_1001b030(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 4);
  if ((uVar1 & 2) != 0) {
    uVar2 = (*(uint *)(*(int *)(param_1 + 0x24) + 0x38) & 0xff) * 0x1000;
    *(uint *)(param_1 + 0x120) = uVar2;
    if (0xfefff < uVar2) {
      *(undefined4 *)(param_1 + 0x120) = 0xfffff;
      *(uint *)(param_1 + 4) = uVar1 & 0xff7fffff;
      return;
    }
    *(uint *)(param_1 + 4) = uVar1 | 0x800000;
  }
  return;
}


