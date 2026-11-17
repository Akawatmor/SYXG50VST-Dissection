/* Ghidra analysis of supplied S-YXG50.dll at 10014ac0 */

short __cdecl FUN_10014ac0(int param_1)

{
  short sVar1;
  int iVar2;
  short sVar3;
  
  sVar3 = 0;
  if (*(char *)(param_1 + 0x27) != 0) {
    iVar2 = *(short *)(param_1 + 0x6e) + -0x2000;
    sVar1 = (short)(iVar2 + (iVar2 >> 0x1f & 0xffU) >> 8);
    if (sVar1 != 0) {
      if (sVar1 < 0) {
        sVar1 = -sVar1;
      }
      iVar2 = (int)(short)(sVar1 * *(char *)(param_1 + 0x27));
      sVar3 = (short)(iVar2 + (iVar2 >> 0x1f & 0xffU) >> 8);
    }
  }
  if ((*(char *)(param_1 + 0x21) != '\0') && (*(byte *)(param_1 + 0x6b) != 0)) {
    iVar2 = (int)(short)(ushort)*(byte *)(param_1 + 0x6b) * (int)(short)*(char *)(param_1 + 0x21);
    sVar3 = sVar3 + (short)((int)(iVar2 + (iVar2 >> 0x1f & 0x3ffU)) >> 10);
  }
  if ((*(char *)(param_1 + 0x4a) != '\0') && (*(byte *)(param_1 + 0x6d) != 0)) {
    iVar2 = (int)(short)(ushort)*(byte *)(param_1 + 0x6d) * (int)(short)*(char *)(param_1 + 0x4a);
    sVar3 = sVar3 + (short)((int)(iVar2 + (iVar2 >> 0x1f & 0x3ffU)) >> 10);
  }
  if ((*(char *)(param_1 + 0x57) != '\0') && (*(byte *)(param_1 + 0xc2) != 0)) {
    iVar2 = (int)(short)(ushort)*(byte *)(param_1 + 0xc2) * (int)(short)*(char *)(param_1 + 0x57);
    sVar3 = sVar3 + (short)((int)(iVar2 + (iVar2 >> 0x1f & 0x3ffU)) >> 10);
  }
  if ((*(char *)(param_1 + 0x5e) != '\0') && (*(byte *)(param_1 + 0xc3) != 0)) {
    iVar2 = (int)(short)(ushort)*(byte *)(param_1 + 0xc3) * (int)(short)*(char *)(param_1 + 0x5e);
    sVar3 = sVar3 + (short)((int)(iVar2 + (iVar2 >> 0x1f & 0x3ffU)) >> 10);
  }
  return sVar3;
}


