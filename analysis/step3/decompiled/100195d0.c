/* Ghidra analysis of supplied S-YXG50.dll at 100195d0 */

uint FUN_100195d0(void)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar3 = __ftol();
  uVar1 = (uint)uVar3;
  if ((int)uVar1 < 1) {
    return 0xfffff;
  }
  iVar2 = 0;
  if ((uVar3 & 0x10000) == 0) {
    do {
      uVar1 = uVar1 << 1;
      iVar2 = iVar2 + 1;
    } while ((uVar1 & 0x10000) == 0);
  }
  return ~uVar1 & 0xffff | iVar2 << 0x10;
}


