/* Ghidra analysis of supplied S-YXG50.dll at 10013ee0 */

void __cdecl FUN_10013ee0(int param_1,byte param_2,byte param_3)

{
  byte bVar1;
  char cVar2;
  
  if (param_3 != 0x40) {
    bVar1 = (&DAT_100475d0)[param_3];
    if (param_3 < 0x41) {
      if ((int)(char)param_2 < (int)(uint)bVar1) {
        param_2 = bVar1;
      }
    }
    else if ((int)(uint)bVar1 < (int)(char)param_2) {
      param_2 = bVar1;
    }
  }
  if ('>' < (char)param_2) {
    *(undefined2 *)(param_1 + 0x46) = 0x8000;
    return;
  }
  cVar2 = param_2 + *(char *)(param_1 + 0x57);
  if (cVar2 < '\0') {
    cVar2 = '\0';
  }
  else if ('>' < cVar2) {
    *(undefined2 *)(param_1 + 0x46) = DAT_100475ce;
    return;
  }
  cVar2 = cVar2 + *(char *)(param_1 + 0x58);
  if (-1 < cVar2) {
    if ('>' < cVar2) {
      cVar2 = '>';
    }
    *(undefined2 *)(param_1 + 0x46) = (&DAT_10047550)[cVar2];
    return;
  }
  *(undefined2 *)(param_1 + 0x46) = DAT_10047550;
  return;
}


