/* Ghidra analysis of supplied S-YXG50.dll at 10015bb0 */

void __cdecl FUN_10015bb0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined2 uVar5;
  
  iVar3 = param_1;
  *(undefined1 *)(param_1 + 0x55) = *(undefined1 *)(param_1 + 0x51);
  *(undefined1 *)(param_1 + 0x53) = *(undefined1 *)(param_1 + 0x4f);
  *(undefined1 *)(param_1 + 0x54) = *(undefined1 *)(param_1 + 0x50);
  iVar1 = *(int *)(param_1 + 0x28);
  *(undefined2 *)(param_1 + 0x40) = *(undefined2 *)(param_1 + 0x3c);
  iVar2 = *(int *)(param_1 + 0x20);
  *(char *)(param_1 + 0x52) = *(char *)(param_1 + 5);
  *(undefined2 *)(param_1 + 0x3e) = *(undefined2 *)(param_1 + 0x3a);
  if (((*(char *)(iVar1 + 0x1d) == *(char *)(iVar1 + 0x1e)) && (*(char *)(param_1 + 5) == '\x03'))
     && (*(char *)(iVar2 + 100) == '@')) {
    *(undefined1 *)(param_1 + 5) = 5;
    return;
  }
  *(undefined1 *)(param_1 + 5) = 4;
  param_1._0_1_ = *(char *)(iVar1 + 0x19);
  cVar4 = *(char *)(iVar2 + 0x65) + -0x40;
  if (cVar4 < '\x01') {
    param_1._0_1_ = (char)param_1 - (cVar4 >> 1);
    if ('?' < (char)param_1) {
      param_1._0_1_ = '?';
    }
  }
  else if ((char)(&DAT_10046cd8)[cVar4] < (char)param_1) {
    param_1._0_1_ = (&DAT_10046cd8)[cVar4];
  }
  uVar5 = FUN_10015fe0(iVar3,(char)param_1,*(char *)(iVar2 + 0x1c));
  *(undefined2 *)(iVar3 + 0x3c) = uVar5;
  FUN_100160d0(iVar3,iVar1,*(byte *)(iVar1 + 0x1e));
  return;
}


