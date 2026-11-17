/* Ghidra analysis of supplied S-YXG50.dll at 1000bd50 */

void FUN_1000bd50(int *param_1,int param_2,char *param_3)

{
  uint uVar1;
  
  FUN_1000c370(param_2,(int)param_3);
  uVar1 = FUN_1000bc40(param_2,*param_3);
  if ((short)uVar1 != 0) {
    if (*(char *)(param_2 + 0xd3) == '\0') {
      (**(code **)(*param_1 + 0x398))(param_1,param_2);
      return;
    }
    (**(code **)(*param_1 + 0x394))(param_1,param_2,param_3);
  }
  return;
}


