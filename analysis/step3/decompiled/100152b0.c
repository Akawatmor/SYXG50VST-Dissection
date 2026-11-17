/* Ghidra analysis of supplied S-YXG50.dll at 100152b0 */

short __cdecl FUN_100152b0(int param_1)

{
  short sVar1;
  uint in_EAX;
  int iVar2;
  uint uVar3;
  short sVar4;
  
  sVar4 = (short)*(char *)(param_1 + 0x25);
  uVar3 = 0;
  if (sVar4 != 0x40) {
    sVar1 = *(short *)(param_1 + 0x6e);
    in_EAX = CONCAT22((short)(in_EAX >> 0x10),sVar1);
    if (sVar1 != 0x2000) {
      iVar2 = sVar1 + -0x2000 >> 6;
      if ((short)iVar2 < 0) {
        in_EAX = FUN_10015380(sVar4,-iVar2);
        uVar3 = -(in_EAX & 0xffff);
      }
      else {
        in_EAX = FUN_10015380(sVar4,iVar2);
        uVar3 = in_EAX;
      }
    }
  }
  sVar4 = (short)uVar3;
  uVar3 = CONCAT22((short)(in_EAX >> 0x10),(ushort)*(byte *)(param_1 + 0x6b));
  if (*(byte *)(param_1 + 0x6b) != 0) {
    uVar3 = FUN_10015380((short)*(char *)(param_1 + 0x1f),uVar3);
    sVar4 = sVar4 + (short)uVar3;
  }
  uVar3 = CONCAT22((short)(uVar3 >> 0x10),(ushort)*(byte *)(param_1 + 0x6d));
  if (*(byte *)(param_1 + 0x6d) != 0) {
    uVar3 = FUN_10015380((short)*(char *)(param_1 + 0x48),uVar3);
    sVar4 = sVar4 + (short)uVar3;
  }
  uVar3 = CONCAT22((short)(uVar3 >> 0x10),(ushort)*(byte *)(param_1 + 0xc2));
  if (*(byte *)(param_1 + 0xc2) != 0) {
    uVar3 = FUN_10015380((short)*(char *)(param_1 + 0x55),uVar3);
    sVar4 = sVar4 + (short)uVar3;
  }
  if (*(byte *)(param_1 + 0xc3) != 0) {
    uVar3 = FUN_10015380((short)*(char *)(param_1 + 0x5c),
                         CONCAT22((short)(uVar3 >> 0x10),(ushort)*(byte *)(param_1 + 0xc3)));
    sVar4 = sVar4 + (short)uVar3;
  }
  return sVar4;
}


