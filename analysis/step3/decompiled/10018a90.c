/* Ghidra analysis of supplied S-YXG50.dll at 10018a90 */

void __fastcall FUN_10018a90(int param_1)

{
  char *pcVar1;
  
  pcVar1 = *(char **)(param_1 + 8);
  if (pcVar1 != (char *)0x0) {
    FUN_10019640(pcVar1);
    FUN_1003392b(pcVar1);
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}


