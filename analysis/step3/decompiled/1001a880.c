/* Ghidra analysis of supplied S-YXG50.dll at 1001a880 */

void __fastcall FUN_1001a880(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = *(int *)(param_1 + 0x7c);
  piVar4 = *(int **)(param_1 + 0x10);
  iVar2 = 0x80;
  do {
    *piVar4 = (0x8000 - *(int *)(param_1 + 0x80)) *
              (char)((*(byte *)(*(int *)(param_1 + 0x68) + iVar3) ^ 0x5c) + 0x80) * 0x100 +
              *(int *)(param_1 + 0x80) *
              (char)((*(byte *)(*(int *)(param_1 + 0x68) + iVar3 + 1) ^ 0x5c) + 0x80) * 0x100;
    uVar1 = *(int *)(param_1 + 0x84) + *(int *)(param_1 + 0x80);
    iVar3 = *(int *)(param_1 + 0x7c) + ((int)uVar1 >> 0xf);
    *(uint *)(param_1 + 0x80) = uVar1 & 0x7fff;
    iVar2 = iVar2 + -1;
    piVar4 = piVar4 + 1;
    *(int *)(param_1 + 0x7c) = iVar3;
    if (*(int *)(param_1 + 0x70) <= iVar3) {
      if (iVar2 != 0) {
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          *piVar4 = 0;
          piVar4 = piVar4 + 1;
        }
      }
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x10;
      return;
    }
  } while (iVar2 != 0);
  return;
}


