/* Ghidra analysis of supplied S-YXG50.dll at 1001ab00 */

void __fastcall FUN_1001ab00(int param_1)

{
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  
  FUN_1001aa90(param_1);
  FUN_1001aab0(extraout_ECX);
  FUN_1001aae0(extraout_ECX_00);
  if ((*(byte *)(*(int *)(extraout_ECX_01 + 0x24) + 0x14) & 0x40) == 0) {
    *(undefined4 *)(extraout_ECX_01 + 0x50) = 0x13;
    *(undefined4 *)(extraout_ECX_01 + 0x54) = 5;
    *(undefined4 *)(extraout_ECX_01 + 0x58) = 6;
    *(undefined4 **)(extraout_ECX_01 + 0x48) = &DAT_100518f8;
    *(undefined4 **)(extraout_ECX_01 + 0x4c) = &DAT_1005530c;
  }
  else {
    *(undefined4 *)(extraout_ECX_01 + 0x50) = 0x12;
    *(undefined4 *)(extraout_ECX_01 + 0x54) = 4;
    *(undefined4 *)(extraout_ECX_01 + 0x58) = 5;
    *(undefined4 **)(extraout_ECX_01 + 0x48) = &DAT_10051908;
    *(undefined4 **)(extraout_ECX_01 + 0x4c) = &DAT_10051918;
  }
  *(undefined4 *)(extraout_ECX_01 + 0x38) = 0;
  *(undefined4 *)(extraout_ECX_01 + 0x40) = **(undefined4 **)(extraout_ECX_01 + 0x48);
  *(undefined4 *)(extraout_ECX_01 + 0x44) = **(undefined4 **)(extraout_ECX_01 + 0x4c);
  return;
}


