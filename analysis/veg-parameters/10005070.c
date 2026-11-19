/* VEG parameter conversion, VA 10005070 */

void FUN_10005070(int *param_1,undefined4 param_2)

{
  undefined2 uVar1;
  
  (**(code **)(*param_1 + 0x58))(param_1,0x440,param_2,(char)param_1[0x6e]);
  uVar1 = FUN_100050d0(*(undefined2 *)((int)param_1 + 0x1b6),(char)param_1[0x6d]);
  (**(code **)(*param_1 + 0x5c))(param_1,0x400,param_2,uVar1);
  return;
}


