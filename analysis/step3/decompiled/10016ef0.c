/* Ghidra analysis of supplied S-YXG50.dll at 10016ef0 */

undefined * __cdecl FUN_10016ef0(int param_1,byte param_2)

{
  ushort uVar1;
  undefined *puVar2;
  
  uVar1 = *(ushort *)(param_1 + (uint)param_2 * 2);
  if (uVar1 == 0xffff) {
    return &DAT_10041950;
  }
  puVar2 = (undefined *)FUN_10016f70(uVar1);
  return puVar2;
}


