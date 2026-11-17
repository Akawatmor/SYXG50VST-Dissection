/* Ghidra analysis of supplied S-YXG50.dll at 100197e0 */

undefined4 __fastcall FUN_100197e0(int param_1)

{
  void *pvVar1;
  uint uVar2;
  
  pvVar1 = operator_new(0xa10);
  if (pvVar1 != (void *)0x0) {
    *(void **)(param_1 + 0x2c) = pvVar1;
    uVar2 = (int)pvVar1 + 0xfU & 0xfffffff0;
    *(uint *)(param_1 + 0x14) = uVar2;
    return CONCAT31((int3)(uVar2 >> 8),1);
  }
  return 0;
}


