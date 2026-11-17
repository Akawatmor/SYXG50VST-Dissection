/* Ghidra analysis of supplied S-YXG50.dll at 1001aff0 */

void __fastcall FUN_1001aff0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 4);
  if ((uVar1 & 2) != 0) {
    uVar2 = (*(uint *)(*(int *)(param_1 + 0x24) + 0x34) & 0xff) * 0x1000;
    *(uint *)(param_1 + 0x11c) = uVar2;
    if (0xfefff < uVar2) {
      *(undefined4 *)(param_1 + 0x11c) = 0xfffff;
      *(uint *)(param_1 + 4) = uVar1 & 0xffbfffff;
      return;
    }
    *(uint *)(param_1 + 4) = uVar1 | 0x400000;
  }
  return;
}


