/* Ghidra analysis of supplied S-YXG50.dll at 100172d0 */

void __fastcall FUN_100172d0(int param_1)

{
  char *pcVar1;
  
  pcVar1 = *(char **)(param_1 + 0xc);
  if (pcVar1 != (char *)0x0) {
    FUN_100180b0(pcVar1);
    FUN_1003392b(pcVar1);
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}


