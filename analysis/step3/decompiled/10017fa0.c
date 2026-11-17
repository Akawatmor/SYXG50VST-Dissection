/* Ghidra analysis of supplied S-YXG50.dll at 10017fa0 */

undefined4 __cdecl FUN_10017fa0(undefined4 *param_1)

{
  void *pvVar1;
  uint3 uVar2;
  
  pvVar1 = operator_new(0x200);
  uVar2 = (uint3)((uint)pvVar1 >> 8);
  if (pvVar1 != (void *)0x0) {
    *param_1 = pvVar1;
    return CONCAT31(uVar2,1);
  }
  return (uint)uVar2 << 8;
}


