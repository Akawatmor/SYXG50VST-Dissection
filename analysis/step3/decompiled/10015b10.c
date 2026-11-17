/* Ghidra analysis of supplied S-YXG50.dll at 10015b10 */

void __cdecl FUN_10015b10(int param_1)

{
  int iVar1;
  char cVar2;
  undefined2 uVar3;
  
  *(undefined2 *)(param_1 + 0x38) = *(undefined2 *)(param_1 + 0x3a);
  cVar2 = *(char *)(param_1 + 5) + '\x01';
  *(char *)(param_1 + 5) = cVar2;
  iVar1 = *(int *)(param_1 + 0x28);
  if (cVar2 == '\x01') {
    if (*(char *)(iVar1 + 0x1b) != *(char *)(iVar1 + 0x1c)) {
      uVar3 = FUN_10015fe0(param_1,*(char *)(iVar1 + 0x17),'@');
      *(undefined2 *)(param_1 + 0x3c) = uVar3;
      FUN_10016080(param_1,iVar1,*(byte *)(iVar1 + 0x1c));
      return;
    }
    *(undefined1 *)(param_1 + 5) = 2;
  }
  else if (cVar2 != '\x02') {
    return;
  }
  if (*(char *)(iVar1 + 0x1c) != *(char *)(iVar1 + 0x1d)) {
    uVar3 = FUN_10015fe0(param_1,*(char *)(iVar1 + 0x18),*(char *)(*(int *)(param_1 + 0x20) + 0x1b))
    ;
    *(undefined2 *)(param_1 + 0x3c) = uVar3;
    FUN_10016080(param_1,iVar1,*(byte *)(iVar1 + 0x1d));
    return;
  }
  *(undefined1 *)(param_1 + 5) = 3;
  return;
}


