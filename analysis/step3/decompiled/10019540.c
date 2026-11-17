/* Ghidra analysis of supplied S-YXG50.dll at 10019540 */

undefined1 __cdecl FUN_10019540(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined1 uVar2;
  
  iVar1 = *param_1;
  uVar2 = 1;
  if (iVar1 != param_2) {
    uVar2 = 0;
    if (param_2 < iVar1) {
      *param_1 = iVar1 - param_3;
      if (iVar1 - param_3 < param_2) {
        *param_1 = param_2;
        return 1;
      }
    }
    else {
      *param_1 = iVar1 + param_3;
      if (param_2 < iVar1 + param_3) {
        *param_1 = param_2;
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}


