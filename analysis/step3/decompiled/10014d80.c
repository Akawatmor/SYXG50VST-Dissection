/* Ghidra analysis of supplied S-YXG50.dll at 10014d80 */

void __cdecl FUN_10014d80(int param_1)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  ushort uVar6;
  short sVar7;
  
  bVar1 = *(byte *)(*(int *)(param_1 + 0x20) + 0x61);
  if (bVar1 == 0) {
    *(undefined2 *)(param_1 + 0x16) = *(undefined2 *)(param_1 + 0x14);
    return;
  }
  uVar2 = (ushort)bVar1;
  if (uVar2 < 0x18) {
    sVar7 = *(short *)(param_1 + 0x14);
    sVar3 = *(short *)(param_1 + 0x16);
    if (sVar3 < sVar7) {
      sVar3 = *(short *)(&DAT_10047e50 + (short)uVar2 * 2) * 2 + sVar3;
      *(short *)(param_1 + 0x16) = sVar3;
      if (sVar7 < sVar3) {
        *(short *)(param_1 + 0x16) = sVar7;
        return;
      }
    }
    else {
      sVar3 = sVar3 + *(short *)(&DAT_10047e50 + (short)uVar2 * 2) * -2;
      *(short *)(param_1 + 0x16) = sVar3;
      if (sVar3 < sVar7) {
        *(short *)(param_1 + 0x16) = sVar7;
        return;
      }
    }
  }
  else {
    sVar3 = *(short *)(param_1 + 0x14);
    uVar6 = *(ushort *)(&DAT_10047e50 + (short)uVar2 * 2) & 0xff;
    sVar4 = (short)*(ushort *)(&DAT_10047e50 + (short)uVar2 * 2) >> 8;
    sVar7 = *(short *)(param_1 + 0x16);
    if (sVar7 < sVar3) {
      *(short *)(param_1 + 0x34) = *(short *)(param_1 + 0x34) + uVar6 * 2;
      uVar2 = *(ushort *)(param_1 + 0x34);
      sVar7 = sVar7 + sVar4 * 2;
      iVar5 = (int)(short)uVar2 + ((int)(short)uVar2 >> 0x1f & 0xffU);
      *(short *)(param_1 + 0x16) = sVar7;
      if (iVar5 >> 8 != 0) {
        *(short *)(param_1 + 0x16) = sVar7 + (short)((uint)iVar5 >> 8);
        *(ushort *)(param_1 + 0x34) = uVar2 & 0xff;
      }
      if (sVar3 < *(short *)(param_1 + 0x16)) {
        *(short *)(param_1 + 0x16) = sVar3;
        return;
      }
    }
    else {
      *(short *)(param_1 + 0x34) = *(short *)(param_1 + 0x34) + uVar6 * -2;
      uVar2 = *(ushort *)(param_1 + 0x34);
      sVar7 = sVar7 + sVar4 * -2;
      iVar5 = (int)(short)uVar2 + ((int)(short)uVar2 >> 0x1f & 0xffU);
      *(short *)(param_1 + 0x16) = sVar7;
      if (iVar5 >> 8 != 0) {
        *(short *)(param_1 + 0x16) = sVar7 + (short)((uint)iVar5 >> 8);
        *(ushort *)(param_1 + 0x34) = uVar2 & 0xff;
      }
      if (*(short *)(param_1 + 0x16) < sVar3) {
        *(short *)(param_1 + 0x16) = sVar3;
      }
    }
  }
  return;
}


