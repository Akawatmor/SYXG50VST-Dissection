/* Ghidra analysis of supplied S-YXG50.dll at 1001a790 */

void __fastcall FUN_1001a790(int param_1)

{
  *(int *)(param_1 + 0x84) =
       ((*(int *)(param_1 + 0x5c) * *(int *)(param_1 + 0x40) >>
        ((byte)*(undefined4 *)(param_1 + 0x50) & 0x1f)) * *(int *)(param_1 + 0x78) >> 0xb) +
       *(int *)(param_1 + 0x78);
  return;
}


