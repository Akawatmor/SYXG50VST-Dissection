/* Ghidra analysis of supplied S-YXG50.dll at 10017000 */

short __cdecl FUN_10017000(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  ushort uVar2;
  undefined4 uVar3;
  short sVar4;
  uint uVar5;
  int *piVar6;
  
  uVar2 = FUN_10016f80(param_1);
  sVar4 = 0;
  if (0 < (short)uVar2) {
    piVar6 = (int *)(param_1 + 0xe8);
    uVar5 = (uint)uVar2;
    do {
      iVar1 = *piVar6;
      uVar3 = FUN_10017060(iVar1,param_4);
      if ((short)uVar3 != 0) {
        *(int *)(param_3 + sVar4 * 4) = iVar1;
        sVar4 = sVar4 + 1;
      }
      piVar6 = piVar6 + 1;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  return sVar4;
}


