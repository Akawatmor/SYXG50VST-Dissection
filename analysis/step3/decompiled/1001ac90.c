/* Ghidra analysis of supplied S-YXG50.dll at 1001ac90 */

void __fastcall FUN_1001ac90(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  short sVar9;
  
  uVar4 = *(uint *)(param_1 + 0x80);
  iVar5 = *(int *)(param_1 + 0x7c);
  iVar3 = -0x80;
  sVar9 = (short)(uVar4 >> 0x10);
  uVar8 = CONCAT44(CONCAT22(sVar9,0x7fff - sVar9),CONCAT22((short)uVar4,0x7fff - (short)uVar4));
  sVar9 = (short)*(undefined4 *)(param_1 + 0x84);
  while( true ) {
    uVar1 = *(undefined2 *)(*(int *)(param_1 + 0x68) + iVar5);
    uVar6 = (ulonglong)
            CONCAT61((int6)(((ulonglong)(byte)((ushort)uVar1 >> 8) << 0x18) >> 0x10),(char)uVar1) <<
            8 ^ 0x5c005c00;
    uVar7 = pmaddwd((ulonglong)CONCAT22((short)(uVar6 >> 0x10) + -0x8000,(short)uVar6 + -0x8000),
                    uVar8);
    uVar8 = (ulonglong)CONCAT22((short)(uVar8 >> 0x10) + sVar9,(short)uVar8 - sVar9) & 0x7fff7fff;
    *(int *)(*(int *)(param_1 + 0x10) + 0x200 + iVar3 * 4) = (int)uVar7;
    uVar4 = uVar4 + *(int *)(param_1 + 0x84);
    iVar5 = iVar5 + (uVar4 >> 0xf);
    uVar4 = uVar4 & 0x7fff;
    if (*(int *)(param_1 + 0x70) <= iVar5) break;
    iVar3 = iVar3 + 1;
    if (iVar3 == 0) goto LAB_1001ad44;
  }
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x10;
  iVar2 = *(int *)(param_1 + 0x10);
  while (iVar3 = iVar3 + 1, iVar3 != 0) {
    *(undefined4 *)(iVar2 + 0x200 + iVar3 * 4) = 0;
  }
LAB_1001ad44:
  *(uint *)(param_1 + 0x80) = uVar4;
  *(int *)(param_1 + 0x7c) = iVar5;
  return;
}


