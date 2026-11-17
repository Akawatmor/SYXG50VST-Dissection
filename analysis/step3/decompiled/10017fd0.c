/* Ghidra analysis of supplied S-YXG50.dll at 10017fd0 */

void __cdecl FUN_10017fd0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  longlong lVar3;
  
  puVar2 = &DAT_100512f8;
  iVar1 = 0x80;
  do {
    lVar3 = __ftol();
    *(int *)(param_1 + -0x100512f8 + (int)puVar2) = (int)lVar3;
    puVar2 = puVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


