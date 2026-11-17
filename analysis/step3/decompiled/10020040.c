/* Ghidra analysis of supplied S-YXG50.dll at 10020040 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short __cdecl FUN_10020040(float *param_1)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = 0x80;
  while( true ) {
    fVar1 = *param_1;
    iVar3 = iVar3 + -1;
    bVar2 = fVar1 < _DAT_10048dd8;
    param_1 = param_1 + 1;
    if ((!bVar2) || (bVar2 = fVar1 < _DAT_1004923c, bVar2 != (fVar1 == _DAT_1004923c))) break;
    if (iVar3 == 0) {
      return (ushort)bVar2 << 8;
    }
  }
  return CONCAT11(bVar2,1);
}


