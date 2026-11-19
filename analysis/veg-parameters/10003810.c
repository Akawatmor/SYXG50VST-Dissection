/* VEG parameter conversion, VA 10003810 */

void FUN_10003810(int *param_1)

{
  (**(code **)(*param_1 + 0xc4))(param_1,(short)param_1[6]);
  (**(code **)(*param_1 + 0x238))(param_1);
  (**(code **)(*param_1 + 0x5b0))(param_1);
  (**(code **)(*param_1 + 0x4b8))(param_1,4);
  (**(code **)(*param_1 + 0x4bc))(param_1,8);
  (**(code **)(*param_1 + 0x538))(param_1,0x10);
  (**(code **)(*param_1 + 0x4c0))(param_1,4);
  return;
}


