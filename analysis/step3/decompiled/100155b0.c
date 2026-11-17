/* Ghidra analysis of supplied S-YXG50.dll at 100155b0 */

void FUN_100155b0(int *param_1,int param_2,int param_3)

{
  byte bVar1;
  
  if (*(char *)(param_3 + 6) == '\0') {
    *(undefined1 *)((int)param_1 + 0x1c6) = 0;
  }
  else {
    *(undefined1 *)((int)param_1 + 0x1c6) = 0x80;
  }
  *(undefined1 *)(param_2 + 10) = 0;
  bVar1 = *(byte *)(param_3 + 5) & 7;
  if (1 < bVar1) {
    *(undefined1 *)(param_2 + 10) = 8;
  }
  *(char *)((int)param_1 + 0x1b9) =
       " !!\"##$%%&\'\'())*++,--.//0112334556778899::;;<<==>>??@@AABBCCDDEEFFGGHIIJKKLMMNOOPQQRSSTUUVWWXYYZ[[\\]]^__`aabccdeefgg"
       [bVar1 + 0x74];
  (**(code **)(*param_1 + 0x4c4))(param_1,param_2,param_3);
  (**(code **)(*param_1 + 0x550))(param_1,param_2,param_3);
  return;
}


