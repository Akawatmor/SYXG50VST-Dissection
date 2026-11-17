/* Ghidra analysis of supplied S-YXG50.dll at 1001ae30 */

void __fastcall FUN_1001ae30(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  short sVar8;
  
  uVar3 = *(uint *)(param_1 + 0x80);
  iVar4 = *(int *)(param_1 + 0x7c);
  iVar2 = -0x80;
  sVar8 = (short)(uVar3 >> 0x10);
  uVar7 = CONCAT44(CONCAT22(sVar8,0x7fff - sVar8),CONCAT22((short)uVar3,0x7fff - (short)uVar3));
  sVar8 = (short)*(undefined4 *)(param_1 + 0x84);
  while( true ) {
    uVar5 = (ulonglong)*(uint *)(*(int *)(param_1 + 0x68) + iVar4 * 2) ^ 0x5c5c5c5c;
    uVar6 = pmaddwd((ulonglong)CONCAT22((short)(uVar5 >> 0x10) + -0x8000,(short)uVar5 + -0x8000),
                    uVar7);
    uVar7 = (ulonglong)CONCAT22((short)(uVar7 >> 0x10) + sVar8,(short)uVar7 - sVar8) & 0x7fff7fff;
    *(int *)(*(int *)(param_1 + 0x10) + 0x200 + iVar2 * 4) = (int)uVar6;
    uVar3 = uVar3 + *(int *)(param_1 + 0x84);
    iVar4 = iVar4 + (uVar3 >> 0xf);
    uVar3 = uVar3 & 0x7fff;
    if (*(int *)(param_1 + 0x70) <= iVar4) break;
    iVar2 = iVar2 + 1;
    if (iVar2 == 0) goto LAB_1001aedb;
  }
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x10;
  iVar1 = *(int *)(param_1 + 0x10);
  while (iVar2 = iVar2 + 1, iVar2 != 0) {
    *(undefined4 *)(iVar1 + 0x200 + iVar2 * 4) = 0;
  }
LAB_1001aedb:
  *(uint *)(param_1 + 0x80) = uVar3;
  *(int *)(param_1 + 0x7c) = iVar4;
  return;
}


