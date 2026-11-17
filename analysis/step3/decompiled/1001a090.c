/* Ghidra analysis of supplied S-YXG50.dll at 1001a090 */

void __fastcall FUN_1001a090(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = *(uint *)(param_1 + 0x80);
  iVar4 = *(int *)(param_1 + 0x7c);
  iVar2 = -0x80;
  do {
    iVar1 = (*(byte *)(*(int *)(param_1 + 0x68) + iVar4) ^ 0x5c) - 0x80;
    *(uint *)(*(int *)(param_1 + 0x10) + 0x200 + iVar2 * 4) =
         iVar1 * 0x800000 +
         (((*(byte *)(*(int *)(param_1 + 0x68) + 1 + iVar4) ^ 0x5c) - 0x80) * 0x100 + iVar1 * -0x100
         ) * uVar3;
    uVar3 = uVar3 + *(int *)(param_1 + 0x84);
    iVar4 = iVar4 + (uVar3 >> 0xf);
    uVar3 = uVar3 & 0x7fff;
    if (*(int *)(param_1 + 0x70) <= iVar4) {
      do {
        uVar3 = uVar3 + *(int *)(param_1 + 0x74);
        iVar4 = (iVar4 + (uVar3 >> 0xf)) - *(int *)(param_1 + 0x70);
        uVar3 = uVar3 & 0x7fff;
      } while (*(int *)(param_1 + 0x70) <= iVar4);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0);
  *(uint *)(param_1 + 0x80) = uVar3;
  *(int *)(param_1 + 0x7c) = iVar4;
  return;
}


