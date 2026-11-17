/* Ghidra analysis of supplied S-YXG50.dll at 1001a690 */

void __fastcall FUN_1001a690(int param_1)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  
  if ((*(byte *)(param_1 + 4) & 2) != 0) {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x24) + 0x4c) & 0xfff;
    *(uint *)(param_1 + 0x78) = uVar1;
    iVar2 = ((int)*(short *)(*(int *)(param_1 + 0x24) + 0x4c) >> 0xc) + 4;
    if (iVar2 != 0) {
      if (iVar2 < 1) {
        iVar2 = (int)uVar1 >> (-(byte)iVar2 & 0x1f);
      }
      else {
        iVar2 = uVar1 << ((byte)iVar2 & 0x1f);
      }
      *(int *)(param_1 + 0x78) = iVar2;
    }
    lVar3 = __ftol();
    *(int *)(param_1 + 0x78) = (int)lVar3;
  }
  return;
}


