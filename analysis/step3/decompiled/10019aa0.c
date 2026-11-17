/* Ghidra analysis of supplied S-YXG50.dll at 10019aa0 */

void __fastcall FUN_10019aa0(int param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_1 + 4);
  if ((uVar1 & 2) != 0) {
    iVar2 = *(int *)(param_1 + 0x24);
    if (*(char *)(iVar2 + 0xc) < '\0') {
      *(uint *)(param_1 + 4) = uVar1 | 0x100;
      *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0xa4);
      *(undefined4 *)(param_1 + 0xac) = 0x80000;
      *(undefined4 *)(param_1 + 0xa8) =
           *(undefined4 *)(*(int *)(param_1 + 0x1c) + (*(uint *)(iVar2 + 0xc) & 0x7f) * 4);
      return;
    }
    *(uint *)(param_1 + 4) = uVar1 & 0xfffffeff;
    *(undefined4 *)(param_1 + 0xa8) =
         *(undefined4 *)(*(int *)(param_1 + 0x1c) + (*(uint *)(iVar2 + 0xc) & 0x7f) * 4);
  }
  return;
}


