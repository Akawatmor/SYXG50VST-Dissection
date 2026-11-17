/* Ghidra analysis of supplied S-YXG50.dll at 1001ad60 */

void __fastcall FUN_1001ad60(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  short sVar7;
  short sVar8;
  
  uVar2 = *(uint *)(param_1 + 0x80);
  iVar3 = *(int *)(param_1 + 0x7c);
  iVar1 = -0x80;
  sVar7 = (short)(uVar2 >> 0x10);
  uVar6 = CONCAT44(CONCAT22(sVar7,0x7fff - sVar7),CONCAT22((short)uVar2,0x7fff - (short)uVar2));
  sVar7 = (short)*(undefined4 *)(param_1 + 0x84);
  do {
    uVar4 = (ulonglong)*(uint *)(*(int *)(param_1 + 0x68) + iVar3 * 2) ^ 0x5c5c5c5c;
    uVar5 = pmaddwd((ulonglong)CONCAT22((short)(uVar4 >> 0x10) + -0x8000,(short)uVar4 + -0x8000),
                    uVar6);
    uVar6 = (ulonglong)CONCAT22((short)(uVar6 >> 0x10) + sVar7,(short)uVar6 - sVar7) & 0x7fff7fff;
    *(int *)(*(int *)(param_1 + 0x10) + 0x200 + iVar1 * 4) = (int)uVar5;
    uVar2 = uVar2 + *(int *)(param_1 + 0x84);
    iVar3 = iVar3 + (uVar2 >> 0xf);
    uVar2 = uVar2 & 0x7fff;
    if (*(int *)(param_1 + 0x70) <= iVar3) {
      do {
        sVar8 = (short)*(int *)(param_1 + 0x74);
        uVar6 = (ulonglong)CONCAT22((short)(uVar6 >> 0x10) + sVar8,(short)uVar6 - sVar8) &
                0x7fff7fff;
        uVar2 = uVar2 + *(int *)(param_1 + 0x74);
        iVar3 = (iVar3 + (uVar2 >> 0xf)) - *(int *)(param_1 + 0x70);
        uVar2 = uVar2 & 0x7fff;
      } while (*(int *)(param_1 + 0x70) <= iVar3);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0);
  *(uint *)(param_1 + 0x80) = uVar2;
  *(int *)(param_1 + 0x7c) = iVar3;
  return;
}


