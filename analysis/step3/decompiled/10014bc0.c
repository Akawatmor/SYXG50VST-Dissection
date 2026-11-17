/* Ghidra analysis of supplied S-YXG50.dll at 10014bc0 */

undefined1 __cdecl FUN_10014bc0(int param_1)

{
  short sVar1;
  int iVar2;
  short sVar3;
  
  sVar3 = 0;
  if (*(char *)(param_1 + 0x28) != 0) {
    iVar2 = *(short *)(param_1 + 0x6e) + -0x2000;
    sVar1 = (short)(iVar2 + (iVar2 >> 0x1f & 0xffU) >> 8);
    if (sVar1 != 0) {
      if (sVar1 < 0) {
        sVar1 = -sVar1;
      }
      iVar2 = (int)(short)(sVar1 * *(char *)(param_1 + 0x28));
      sVar3 = (short)(iVar2 + (iVar2 >> 0x1f & 0xffU) >> 8);
    }
  }
  if (*(byte *)(param_1 + 0x6b) != 0) {
    iVar2 = (int)*(char *)(param_1 + 0x22) * (int)(short)(ushort)*(byte *)(param_1 + 0x6b);
    sVar3 = sVar3 + (short)((int)(iVar2 + (iVar2 >> 0x1f & 0x3ffU)) >> 10);
  }
  if (*(byte *)(param_1 + 0x6d) != 0) {
    iVar2 = (int)*(char *)(param_1 + 0x4b) * (int)(short)(ushort)*(byte *)(param_1 + 0x6d);
    sVar3 = sVar3 + (short)((int)(iVar2 + (iVar2 >> 0x1f & 0x3ffU)) >> 10);
  }
  if (*(byte *)(param_1 + 0xc2) != 0) {
    iVar2 = (int)*(char *)(param_1 + 0x58) * (int)(short)(ushort)*(byte *)(param_1 + 0xc2);
    sVar3 = sVar3 + (short)((int)(iVar2 + (iVar2 >> 0x1f & 0x3ffU)) >> 10);
  }
  if (*(byte *)(param_1 + 0xc3) != 0) {
    iVar2 = (int)*(char *)(param_1 + 0x5f) * (int)(short)(ushort)*(byte *)(param_1 + 0xc3);
    sVar3 = sVar3 + (short)((int)(iVar2 + (iVar2 >> 0x1f & 0x3ffU)) >> 10);
  }
  if (0x7f < sVar3) {
    return 0x7f;
  }
  return (char)sVar3;
}


