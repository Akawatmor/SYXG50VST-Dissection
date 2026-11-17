/* Ghidra analysis of supplied S-YXG50.dll at 10019740 */

uint __fastcall FUN_10019740(int param_1)

{
  uint uVar1;
  uint local_8 [2];
  
  if ((*(char *)(param_1 + 0x31) != '\0') && (*(int *)(param_1 + 0x3c) == 4)) {
    FUN_10017d60(local_8);
    FUN_1001b650(param_1);
    uVar1 = FUN_10017d80(local_8);
    return uVar1 >> 7;
  }
  return 0;
}


