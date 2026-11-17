/* Ghidra analysis of supplied S-YXG50.dll at 10017d80 */

uint __fastcall FUN_10017d80(uint *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = rdtsc();
  uVar1 = *param_1;
  *param_1 = (uint)uVar2 - *param_1;
  param_1[1] = ((int)((ulonglong)uVar2 >> 0x20) - param_1[1]) - (uint)((uint)uVar2 < uVar1);
  return *param_1;
}


