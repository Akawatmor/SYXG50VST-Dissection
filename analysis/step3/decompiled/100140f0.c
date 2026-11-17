/* Ghidra analysis of supplied S-YXG50.dll at 100140f0 */

void __cdecl FUN_100140f0(int param_1,int param_2)

{
  byte bVar1;
  short sVar2;
  char cVar3;
  char cVar4;
  ushort uVar5;
  short sVar6;
  
  cVar3 = *(char *)(param_1 + 0x10);
  *(char *)(param_2 + 6) = cVar3;
  bVar1 = *(byte *)(param_1 + 0xf);
  if (bVar1 != 5) {
    if (*(char *)(param_2 + 10) == '\0') {
      uVar5 = (ushort)*(byte *)(param_2 + 1);
    }
    else if (*(char *)(param_2 + 0xe) == '\0') {
      uVar5 = (ushort)*(byte *)(param_2 + 0xb);
    }
    else {
      uVar5 = (ushort)*(byte *)(param_2 + 0xc);
    }
    sVar6 = uVar5 - (short)cVar3;
    if (bVar1 == 0) {
      cVar3 = cVar3 + (char)sVar6;
    }
    else {
      sVar2 = (ushort)(byte)(&DAT_10047750)[bVar1] * sVar6;
      if (-1 < sVar6) {
        *(char *)(param_2 + 6) = cVar3 + (char)((int)sVar2 / 100);
        *(char *)(param_2 + 7) = (char)((int)sVar2 % 100);
        return;
      }
      cVar3 = cVar3 - (char)((int)-sVar2 / 100);
      cVar4 = (char)((int)-sVar2 % 100);
      if (cVar4 != '\0') {
        *(char *)(param_2 + 6) = cVar3 + -1;
        *(char *)(param_2 + 7) = 'd' - cVar4;
        return;
      }
    }
    *(char *)(param_2 + 6) = cVar3;
  }
  *(undefined1 *)(param_2 + 7) = 0;
  return;
}


