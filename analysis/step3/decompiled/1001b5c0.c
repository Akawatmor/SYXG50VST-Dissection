/* Ghidra analysis of supplied S-YXG50.dll at 1001b5c0 */

void __fastcall FUN_1001b5c0(int param_1)

{
  code *pcVar1;
  
  *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x15c) = 0x38000000;
  *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x158) = 0x38000000;
  *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x154) = 0x38000000;
  *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x150) = 0x38000000;
  *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x16c) = 0x3c000000;
  *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x168) = 0x3c000000;
  *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x164) = 0x3c000000;
  *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x160) = 0x3c000000;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  pcVar1 = FUN_1001b9e0;
  if (*(int *)(param_1 + 4) != 1) {
    pcVar1 = FUN_1001b660;
  }
  *(code **)(param_1 + 100) = pcVar1;
  return;
}


