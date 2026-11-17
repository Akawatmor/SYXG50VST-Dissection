/* Ghidra analysis of supplied S-YXG50.dll at 10016230 */

uint __cdecl FUN_10016230(int param_1)

{
  short sVar1;
  undefined4 in_EAX;
  uint uVar2;
  
  sVar1 = *(short *)(param_1 + 0xba);
  uVar2 = CONCAT22((short)((uint)in_EAX >> 0x10),sVar1);
  if (sVar1 != 0) {
    if (sVar1 == -0x2000) {
      uVar2 = 0xffffff9c;
    }
    else {
      uVar2 = (int)sVar1 / 0x52;
    }
  }
  if ((*(char *)(param_1 + 0x1d) != 0x40) && (*(byte *)(param_1 + 0x6b) != 0)) {
    uVar2 = uVar2 + (((short)*(char *)(param_1 + 0x1d) + -0x40) *
                     (int)(short)(ushort)*(byte *)(param_1 + 0x6b) * 0xc947 >> 0x10);
  }
  if ((*(char *)(param_1 + 0x46) != 0x40) && (*(byte *)(param_1 + 0x6d) != 0)) {
    uVar2 = uVar2 + (((short)*(char *)(param_1 + 0x46) + -0x40) *
                     (int)(short)(ushort)*(byte *)(param_1 + 0x6d) * 0xc947 >> 0x10);
  }
  if ((*(char *)(param_1 + 0x53) != 0x40) && (*(byte *)(param_1 + 0xc2) != 0)) {
    uVar2 = uVar2 + (((short)*(char *)(param_1 + 0x53) + -0x40) *
                     (int)(short)(ushort)*(byte *)(param_1 + 0xc2) * 0xc947 >> 0x10);
  }
  if ((*(char *)(param_1 + 0x5a) != 0x40) && (*(byte *)(param_1 + 0xc3) != 0)) {
    uVar2 = uVar2 + (((short)*(char *)(param_1 + 0x5a) + -0x40) *
                     (int)(short)(ushort)*(byte *)(param_1 + 0xc3) * 0xc947 >> 0x10);
  }
  return uVar2;
}


