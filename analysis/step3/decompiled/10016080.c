/* Ghidra analysis of supplied S-YXG50.dll at 10016080 */

void __cdecl FUN_10016080(int param_1,int param_2,byte param_3)

{
  short sVar1;
  undefined4 in_EAX;
  int iVar2;
  uint uVar3;
  
  iVar2 = CONCAT22((short)((uint)in_EAX >> 0x10),(ushort)param_3) + -0x40;
  if ((short)iVar2 == 0) {
    sVar1 = 0;
  }
  else {
    uVar3 = FUN_10015e50(param_2,*(byte *)(param_1 + 0x51),iVar2);
    sVar1 = (short)uVar3;
  }
  *(short *)(param_1 + 0x3a) = sVar1;
  if ((sVar1 < *(short *)(param_1 + 0x38)) && (*(short *)(param_1 + 0x3c) != -0x8000)) {
    *(short *)(param_1 + 0x3c) = -*(short *)(param_1 + 0x3c);
  }
  return;
}


