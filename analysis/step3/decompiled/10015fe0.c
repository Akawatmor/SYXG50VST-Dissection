/* Ghidra analysis of supplied S-YXG50.dll at 10015fe0 */

undefined2 __cdecl FUN_10015fe0(int param_1,char param_2,char param_3)

{
  char cVar1;
  
  cVar1 = ((char)('@' - param_3) >> 2) + param_2;
  if (cVar1 < '@') {
    if (cVar1 < '\0') {
      cVar1 = '\0';
    }
  }
  else {
    cVar1 = '?';
  }
  cVar1 = cVar1 + *(char *)(param_1 + 0x4f);
  if (cVar1 < '\0') {
    cVar1 = '\0';
  }
  else if ('>' < cVar1) {
    return DAT_100481d6;
  }
  cVar1 = cVar1 + *(char *)(param_1 + 0x50);
  if ('>' < cVar1) {
    return DAT_100481d4;
  }
  return *(undefined2 *)(&DAT_10048158 + cVar1 * 2);
}


