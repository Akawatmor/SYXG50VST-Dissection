/* Ghidra analysis of supplied S-YXG50.dll at 10014cb0 */

undefined4 __cdecl FUN_10014cb0(int param_1)

{
  int iVar1;
  short sVar2;
  short sVar3;
  
  iVar1 = (int)*(short *)(param_1 + 0x6e);
  sVar2 = (short)((int)((iVar1 >> 0x1f & 0x3fU) + iVar1) >> 6) + -0x80;
  sVar3 = 0;
  if (sVar2 != 0) {
    if (sVar2 < 0) {
      sVar2 = -sVar2;
    }
    iVar1 = (int)*(char *)(param_1 + 0x26) * (int)sVar2;
    iVar1 = iVar1 + (iVar1 >> 0x1f & 0x7fU);
    sVar3 = (short)(iVar1 >> 7);
  }
  if (*(byte *)(param_1 + 0x6b) != 0) {
    iVar1 = (int)*(char *)(param_1 + 0x20) * (int)(short)(ushort)*(byte *)(param_1 + 0x6b);
    iVar1 = (int)(iVar1 + (iVar1 >> 0x1f & 0x7fU)) >> 7;
    sVar3 = sVar3 + (short)iVar1;
  }
  if (*(byte *)(param_1 + 0x6d) != 0) {
    iVar1 = (int)*(char *)(param_1 + 0x49) * (int)(short)(ushort)*(byte *)(param_1 + 0x6d);
    iVar1 = (int)(iVar1 + (iVar1 >> 0x1f & 0x7fU)) >> 7;
    sVar3 = sVar3 + (short)iVar1;
  }
  if (*(byte *)(param_1 + 0xc2) != 0) {
    iVar1 = (int)*(char *)(param_1 + 0x56) * (int)(short)(ushort)*(byte *)(param_1 + 0xc2);
    iVar1 = (int)(iVar1 + (iVar1 >> 0x1f & 0x7fU)) >> 7;
    sVar3 = sVar3 + (short)iVar1;
  }
  if (*(byte *)(param_1 + 0xc3) != 0) {
    iVar1 = (int)*(char *)(param_1 + 0x5d) * (int)(short)(ushort)*(byte *)(param_1 + 0xc3);
    iVar1 = (int)(iVar1 + (iVar1 >> 0x1f & 0x7fU)) >> 7;
    sVar3 = sVar3 + (short)iVar1;
  }
  if (0x7f < sVar3) {
    return 0x7f;
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),(char)sVar3);
}


