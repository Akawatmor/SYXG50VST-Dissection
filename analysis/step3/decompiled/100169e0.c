/* Ghidra analysis of supplied S-YXG50.dll at 100169e0 */

void FUN_100169e0(int *param_1)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = 0;
  if ((short)param_1[0x1aa6] != 0) {
    do {
      sVar1 = (**(code **)(*param_1 + 0x5c0))
                        (param_1,param_1 + (uint)*(byte *)((uVar2 & 0xffff) + 0x6a17 + (int)param_1)
                                           * 0x23 + 0x4e8);
      if (sVar1 == 0) {
        (**(code **)(*param_1 + 0x5bc))(param_1,uVar2);
      }
      else {
        uVar2 = uVar2 + 1;
      }
    } while ((ushort)uVar2 < *(ushort *)(param_1 + 0x1aa6));
  }
  return;
}


