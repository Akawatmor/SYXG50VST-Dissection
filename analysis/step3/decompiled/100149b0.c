/* Ghidra analysis of supplied S-YXG50.dll at 100149b0 */

ushort __cdecl FUN_100149b0(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  short sVar5;
  ushort uVar6;
  
  iVar1 = *(int *)(param_1 + 0x20);
  sVar5 = 0;
  if ((((*(char *)(param_1 + 2) == '\0') && (*(char *)(iVar1 + 0x51) != '\0')) &&
      (cVar2 = *(char *)(param_1 + 3) + -0x24, -1 < cVar2)) &&
     ((cVar2 < '>' && (bVar3 = *(byte *)(cVar2 + 0x70 + iVar1), bVar3 != 0)))) {
    iVar4 = (int)(short)((short)*(char *)(iVar1 + 0x51) * (ushort)bVar3);
    sVar5 = (short)((int)(iVar4 + (iVar4 >> 0x1f & 0x3ffU)) >> 10);
  }
  bVar3 = FUN_10016c00(iVar1);
  uVar6 = sVar5 + (ushort)bVar3;
  if (0xf < (short)uVar6) {
    uVar6 = 0xf;
  }
  if ((short)uVar6 < (short)(ushort)*(byte *)(param_2 + 0xc)) {
    return (ushort)*(byte *)(param_2 + 0xc);
  }
  return uVar6 & 0xff;
}


