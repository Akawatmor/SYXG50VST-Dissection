/* Ghidra analysis of supplied S-YXG50.dll at 100151c0 */

void FUN_100151c0(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_1 + 0x78;
  iVar1 = 0x10;
  do {
    (**(code **)(*param_1 + 0x568))(param_1,piVar2);
    FUN_10016a90((int)piVar2);
    piVar2 = piVar2 + 0x47;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


