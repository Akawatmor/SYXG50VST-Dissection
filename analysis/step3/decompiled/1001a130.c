/* Ghidra analysis of supplied S-YXG50.dll at 1001a130 */

void __fastcall FUN_1001a130(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = *(uint *)(param_1 + 0x80);
  iVar4 = *(int *)(param_1 + 0x7c);
  iVar2 = -0x80;
  while( true ) {
    iVar1 = (*(byte *)(*(int *)(param_1 + 0x68) + iVar4) ^ 0x5c) - 0x80;
    *(uint *)(*(int *)(param_1 + 0x10) + 0x200 + iVar2 * 4) =
         iVar1 * 0x800000 +
         (((*(byte *)(*(int *)(param_1 + 0x68) + 1 + iVar4) ^ 0x5c) - 0x80) * 0x100 + iVar1 * -0x100
         ) * uVar3;
    uVar3 = uVar3 + *(int *)(param_1 + 0x84);
    iVar4 = iVar4 + (uVar3 >> 0xf);
    uVar3 = uVar3 & 0x7fff;
    if (*(int *)(param_1 + 0x70) <= iVar4) break;
    iVar2 = iVar2 + 1;
    if (iVar2 == 0) goto LAB_1001a1bd;
  }
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x10;
  iVar1 = *(int *)(param_1 + 0x10);
  while (iVar2 = iVar2 + 1, iVar2 != 0) {
    *(undefined4 *)(iVar1 + 0x200 + iVar2 * 4) = 0;
  }
LAB_1001a1bd:
  *(uint *)(param_1 + 0x80) = uVar3;
  *(int *)(param_1 + 0x7c) = iVar4;
  return;
}


