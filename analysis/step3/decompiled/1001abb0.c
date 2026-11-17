/* Ghidra analysis of supplied S-YXG50.dll at 1001abb0 */

void __fastcall FUN_1001abb0(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  short sVar8;
  short sVar9;
  
  uVar3 = *(uint *)(param_1 + 0x80);
  iVar4 = *(int *)(param_1 + 0x7c);
  iVar2 = -0x80;
  sVar8 = (short)(uVar3 >> 0x10);
  uVar7 = CONCAT44(CONCAT22(sVar8,0x7fff - sVar8),CONCAT22((short)uVar3,0x7fff - (short)uVar3));
  sVar8 = (short)*(undefined4 *)(param_1 + 0x84);
  do {
    uVar1 = *(undefined2 *)(*(int *)(param_1 + 0x68) + iVar4);
    uVar5 = (ulonglong)
            CONCAT61((int6)(((ulonglong)(byte)((ushort)uVar1 >> 8) << 0x18) >> 0x10),(char)uVar1) <<
            8 ^ 0x5c005c00;
    uVar6 = pmaddwd((ulonglong)CONCAT22((short)(uVar5 >> 0x10) + -0x8000,(short)uVar5 + -0x8000),
                    uVar7);
    uVar7 = (ulonglong)CONCAT22((short)(uVar7 >> 0x10) + sVar8,(short)uVar7 - sVar8) & 0x7fff7fff;
    *(int *)(*(int *)(param_1 + 0x10) + 0x200 + iVar2 * 4) = (int)uVar6;
    uVar3 = uVar3 + *(int *)(param_1 + 0x84);
    iVar4 = iVar4 + (uVar3 >> 0xf);
    uVar3 = uVar3 & 0x7fff;
    if (*(int *)(param_1 + 0x70) <= iVar4) {
      do {
        sVar9 = (short)*(int *)(param_1 + 0x74);
        uVar7 = (ulonglong)CONCAT22((short)(uVar7 >> 0x10) + sVar9,(short)uVar7 - sVar9) &
                0x7fff7fff;
        uVar3 = uVar3 + *(int *)(param_1 + 0x74);
        iVar4 = (iVar4 + (uVar3 >> 0xf)) - *(int *)(param_1 + 0x70);
        uVar3 = uVar3 & 0x7fff;
      } while (*(int *)(param_1 + 0x70) <= iVar4);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0);
  *(uint *)(param_1 + 0x80) = uVar3;
  *(int *)(param_1 + 0x7c) = iVar4;
  return;
}


