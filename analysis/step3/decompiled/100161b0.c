/* Ghidra analysis of supplied S-YXG50.dll at 100161b0 */

void FUN_100161b0(short param_1,int param_2)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  
  iVar2 = *(int *)(param_2 + 0x20);
  if ((((*(char *)(param_2 + 2) == '\0') && (*(char *)(iVar2 + 0x4c) != '@')) &&
      (cVar4 = *(char *)(param_2 + 3) + -0x24, -1 < cVar4)) &&
     ((cVar4 < '>' && (cVar4 = *(char *)(cVar4 + 0x70 + iVar2), cVar4 != '\0')))) {
    param_1 = param_1 + (short)((uint)((*(char *)(iVar2 + 0x4c) + -0x40) * (int)cVar4 * 0xc947) >>
                               0x10);
  }
  sVar1 = *(short *)(iVar2 + 0x114);
  uVar3 = FUN_10016b00(iVar2);
  param_1 = param_1 + sVar1 + (short)uVar3;
  FUN_100163f0(param_1,*(byte *)(param_2 + 0x89));
  return;
}


