/* Ghidra analysis of supplied S-YXG50.dll at 10020080 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10020080(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar5;
  undefined2 uVar4;
  
  iVar5 = 0x80;
  while( true ) {
    fVar1 = *param_1;
    fVar2 = *param_2;
    iVar5 = iVar5 + -1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    uVar4 = (undefined2)((uint)fVar2 >> 0x10);
    uVar3 = CONCAT22(uVar4,(ushort)(fVar1 < _DAT_10048dd8) << 8 |
                           (ushort)(NAN(fVar1) || NAN(_DAT_10048dd8)) << 10 |
                           (ushort)(fVar1 == _DAT_10048dd8) << 0xe);
    if ((((fVar1 < _DAT_10048dd8 == 0) ||
         (uVar3 = CONCAT22(uVar4,(ushort)(fVar1 < _DAT_1004923c) << 8 |
                                 (ushort)(NAN(fVar1) || NAN(_DAT_1004923c)) << 10 |
                                 (ushort)(fVar1 == _DAT_1004923c) << 0xe),
         fVar1 < _DAT_1004923c != (fVar1 == _DAT_1004923c))) ||
        (uVar3 = CONCAT22(uVar4,(ushort)(fVar2 < _DAT_10048dd8) << 8 |
                                (ushort)(NAN(fVar2) || NAN(_DAT_10048dd8)) << 10 |
                                (ushort)(fVar2 == _DAT_10048dd8) << 0xe), fVar2 < _DAT_10048dd8 == 0
        )) || (uVar3 = CONCAT22(uVar4,(ushort)(fVar2 < _DAT_1004923c) << 8 |
                                      (ushort)(NAN(fVar2) || NAN(_DAT_1004923c)) << 10 |
                                      (ushort)(fVar2 == _DAT_1004923c) << 0xe),
              fVar2 < _DAT_1004923c != (fVar2 == _DAT_1004923c))) break;
    if (iVar5 == 0) {
      return uVar3;
    }
  }
  return CONCAT31((int3)((uint)uVar3 >> 8),1);
}


