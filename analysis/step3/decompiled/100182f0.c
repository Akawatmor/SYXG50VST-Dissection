/* Ghidra analysis of supplied S-YXG50.dll at 100182f0 */

void __fastcall FUN_100182f0(int param_1)

{
  char *pcVar1;
  
  pcVar1 = *(char **)(param_1 + 0x10);
  if (pcVar1 != (char *)0x0) {
    FUN_1001c050(pcVar1);
    FUN_1003392b(pcVar1);
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


