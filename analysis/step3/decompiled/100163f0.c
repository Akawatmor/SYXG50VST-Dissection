/* Ghidra analysis of supplied S-YXG50.dll at 100163f0 */

uint __cdecl FUN_100163f0(short param_1,byte param_2)

{
  int iVar1;
  uint uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 < 0) {
    iVar4 = (int)param_1 / 0x4b0;
    iVar1 = -(int)param_1 % 0x4b0;
    iVar5 = iVar1;
  }
  else {
    iVar5 = (int)param_1 % 0x4b0;
    iVar4 = (int)param_1 / 0x4b0 + 1;
    iVar1 = 0x4b0 - iVar5;
  }
  sVar3 = (short)iVar4;
  uVar2 = CONCAT22((short)((uint)iVar5 >> 0x10),*(undefined2 *)(&DAT_100481d8 + (short)iVar1 * 2));
  if (sVar3 < -8) {
    do {
      uVar2 = (int)(short)uVar2 / 2;
      iVar4 = iVar4 + 1;
    } while ((short)iVar4 != -8);
    return iVar4 * 0x1000 | uVar2;
  }
  if ((param_2 & 0xc0) == 0xc0) {
    if (3 < sVar3) {
      return uVar2 | 0x3000;
    }
  }
  else if (7 < sVar3) {
    iVar4 = 7;
  }
  return iVar4 << 0xc | uVar2;
}


