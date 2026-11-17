/* Ghidra analysis of supplied S-YXG50.dll at 100160d0 */

void __cdecl FUN_100160d0(int param_1,int param_2,byte param_3)

{
  undefined4 in_EAX;
  uint uVar1;
  int iVar2;
  short sVar3;
  uint uVar4;
  
  iVar2 = *(int *)(param_1 + 0x20);
  uVar1 = CONCAT22((short)((uint)in_EAX >> 0x10),(ushort)param_3) - 0x40;
  if ((short)uVar1 == 0) {
    uVar4 = 0;
  }
  else {
    uVar1 = FUN_10015e50(param_2,*(byte *)(param_1 + 0x51),uVar1);
    uVar4 = uVar1;
  }
  iVar2 = CONCAT22((short)(uVar1 >> 0x10),(ushort)*(byte *)(iVar2 + 100)) + -0x40;
  if ((short)iVar2 == 0) {
    sVar3 = 0;
  }
  else {
    iVar2 = FUN_10015f10(*(byte *)(param_1 + 0x51),iVar2);
    sVar3 = (short)iVar2;
  }
  sVar3 = (short)uVar4 + sVar3;
  *(short *)(param_1 + 0x3a) = sVar3;
  if ((sVar3 < *(short *)(param_1 + 0x38)) && (*(short *)(param_1 + 0x3c) != -0x8000)) {
    *(short *)(param_1 + 0x3c) = -*(short *)(param_1 + 0x3c);
  }
  return;
}


