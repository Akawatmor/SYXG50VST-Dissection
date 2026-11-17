/* Ghidra analysis of supplied S-YXG50.dll at 10016f20 */

undefined1 * __cdecl FUN_10016f20(int param_1,byte param_2)

{
  ushort uVar1;
  undefined1 *puVar2;
  
  uVar1 = *(ushort *)(param_1 + (uint)param_2 * 2);
  if (uVar1 == 0xffff) {
    return &DAT_10041960;
  }
  puVar2 = (undefined1 *)FUN_10016f70(uVar1);
  return puVar2;
}


