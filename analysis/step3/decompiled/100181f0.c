/* Ghidra analysis of supplied S-YXG50.dll at 100181f0 */

undefined4 __fastcall FUN_100181f0(int param_1)

{
  void *pvVar1;
  uint uVar2;
  
  pvVar1 = operator_new(0x1410);
  if (pvVar1 != (void *)0x0) {
    *(void **)(param_1 + 8) = pvVar1;
    uVar2 = (int)pvVar1 + 0xfU & 0xfffffff0;
    *(uint *)(param_1 + 4) = uVar2;
    return CONCAT31((int3)(uVar2 >> 8),1);
  }
  return 0;
}


