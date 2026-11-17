/* Ghidra analysis of supplied S-YXG50.dll at 100142d0 */

undefined1 __cdecl FUN_100142d0(int param_1,int param_2)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_2 + 3);
  *(byte *)(param_1 + 0x73) = bVar1;
  return (&DAT_10047f50)[(byte)(&DAT_100477d8)[bVar1]];
}


