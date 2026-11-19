/* VEG parameter conversion, VA 100125b0 */

undefined4 FUN_100125b0(int param_1,char param_2)

{
  short sVar1;
  int iVar2;
  undefined3 uVar3;
  char cVar4;
  
  iVar2 = CONCAT22((short)((uint)*(int *)(param_1 + 0x20) >> 0x10),
                   (ushort)*(byte *)(*(int *)(param_1 + 0x20) + 0x1a)) + -0x40;
  sVar1 = (short)iVar2;
  uVar3 = (undefined3)((uint)iVar2 >> 8);
  if ((0 < sVar1) && (cVar4 = (char)((short)(0x3f - sVar1) >> 2) + '\x02', cVar4 < param_2)) {
    param_2 = cVar4;
  }
  param_2 = param_2 + *(char *)(param_1 + 0x65);
  if ('\0' < param_2) {
    if ('?' < param_2) {
      param_2 = '?';
    }
    return CONCAT31(uVar3,param_2 << 1);
  }
  return CONCAT31(uVar3,2);
}


