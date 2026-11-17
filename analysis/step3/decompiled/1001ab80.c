/* Ghidra analysis of supplied S-YXG50.dll at 1001ab80 */

void __fastcall FUN_1001ab80(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x38);
  *(uint *)(param_1 + 0x40) = *(uint *)(*(int *)(param_1 + 0x48) + ((int)uVar1 >> 0x12) * 4) ^ uVar1
  ;
  *(uint *)(param_1 + 0x44) = *(uint *)(*(int *)(param_1 + 0x4c) + ((int)uVar1 >> 0x12) * 4) ^ uVar1
  ;
  *(uint *)(param_1 + 0x38) = *(int *)(param_1 + 0x3c) + uVar1 & 0xfffff;
  return;
}


