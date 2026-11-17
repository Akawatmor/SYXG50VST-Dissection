/* Ghidra analysis of supplied S-YXG50.dll at 10013ea0 */

void __cdecl FUN_10013ea0(int param_1,int param_2,byte param_3,byte param_4)

{
  if ((param_4 < 0x40) && (*(byte *)(param_2 + 0x33) < *(byte *)(param_2 + 0x32))) {
    param_4 = 0x40;
  }
  FUN_10013ee0(param_1,param_3,param_4);
  return;
}


