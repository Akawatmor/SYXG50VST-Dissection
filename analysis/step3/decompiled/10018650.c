/* Ghidra analysis of supplied S-YXG50.dll at 10018650 */

void __fastcall FUN_10018650(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_10018890(puVar1);
    FUN_1003392b((undefined *)puVar1);
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}


