/* Ghidra analysis of supplied S-YXG50.dll at 10013bb0 */

void __cdecl FUN_10013bb0(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  
  *(undefined2 *)(param_1 + 0x42) = *(undefined2 *)(param_1 + 0x44);
  cVar2 = *(char *)(param_1 + 8) + '\x01';
  *(char *)(param_1 + 8) = cVar2;
  iVar1 = *(int *)(param_1 + 0x28);
  *(undefined1 *)(param_1 + 0x4d) = 0xc1;
  if (cVar2 == '\x01') {
    if (*(char *)(iVar1 + 0x33) != *(char *)(iVar1 + 0x34)) {
      FUN_10013ee0(param_1,*(byte *)(iVar1 + 0x2f),0x40);
      FUN_10014010(extraout_ECX,extraout_EDX,param_1,*(byte *)(iVar1 + 0x34));
      return;
    }
    *(undefined1 *)(param_1 + 8) = 2;
  }
  else if (cVar2 != '\x02') {
    return;
  }
  if (*(char *)(iVar1 + 0x34) != *(char *)(iVar1 + 0x35)) {
    FUN_10013ee0(param_1,*(byte *)(iVar1 + 0x30),*(byte *)(*(int *)(param_1 + 0x20) + 0x1b));
    FUN_10014010(extraout_ECX_00,(uint)*(byte *)(iVar1 + 0x35),param_1,*(byte *)(iVar1 + 0x35));
    return;
  }
  *(undefined1 *)(param_1 + 8) = 3;
  return;
}


