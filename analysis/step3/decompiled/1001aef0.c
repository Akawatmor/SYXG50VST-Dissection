/* Ghidra analysis of supplied S-YXG50.dll at 1001aef0 */

void __fastcall FUN_1001aef0(int param_1)

{
  uint uVar1;
  
  if (((*(byte *)(param_1 + 4) & 2) != 0) &&
     (uVar1 = (*(uint *)(*(int *)(param_1 + 0x24) + 0x3c) & 0xff) * 0x1000,
     *(uint *)(param_1 + 0xf4) = uVar1, 0xfefff < uVar1)) {
    *(undefined4 *)(param_1 + 0xf4) = 0xfffff;
  }
  return;
}


