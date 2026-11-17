/* Ghidra analysis of supplied S-YXG50.dll at 100192f0 */

uint __fastcall FUN_100192f0(int param_1)

{
  uint uVar1;
  uint local_8 [2];
  
  FUN_10017d60(local_8);
  FUN_1001ab80(param_1);
  FUN_1001a790(param_1);
  FUN_10019b40(param_1);
  FUN_10018fe0(param_1);
  FUN_1001b1d0(param_1);
  uVar1 = FUN_10017d80(local_8);
  *(uint *)(param_1 + 0x28) = uVar1 >> 7;
  FUN_10017d60(local_8);
  (**(code **)(param_1 + 0x88))();
  uVar1 = FUN_10017d80(local_8);
  *(uint *)(param_1 + 0x2c) = uVar1 >> 7;
  FUN_10017d60(local_8);
  (**(code **)(param_1 + 0x34))();
  uVar1 = FUN_10017d80(local_8);
  *(uint *)(param_1 + 0x30) = uVar1 >> 7;
  if ((*(uint *)(param_1 + 4) & 0x1010) != 0) {
    uVar1 = FUN_100192d0(param_1);
    return uVar1 & 0xffffff00;
  }
  return CONCAT31((uint3)(uVar1 >> 0xf),1);
}


