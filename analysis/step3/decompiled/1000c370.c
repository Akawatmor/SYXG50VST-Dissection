/* Ghidra analysis of supplied S-YXG50.dll at 1000c370 */

void __cdecl FUN_1000c370(int param_1,int param_2)

{
  *(undefined1 *)(param_2 + 0xf) = 0;
  if ((*(char *)(param_1 + 0xca) == '\x01') &&
     ((*(char *)(param_1 + 0x60) == '\0' ||
      ((*(char *)(param_1 + 5) == '\x01' && (*(char *)(param_2 + 0x11) == '\x01')))))) {
    *(undefined1 *)(param_2 + 0xf) = 1;
  }
  return;
}


