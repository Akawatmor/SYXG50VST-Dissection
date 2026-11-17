/* Ghidra analysis of supplied S-YXG50.dll at 10019520 */

int __fastcall FUN_10019520(int param_1)

{
  uint uVar1;
  uint3 uVar2;
  
  uVar1 = *(uint *)(param_1 + 4);
  uVar2 = (uint3)(uVar1 >> 8);
  if (((uVar1 & 1) != 0) && ((uVar1 & 2) != 0)) {
    return CONCAT31(uVar2,1);
  }
  return (uint)uVar2 << 8;
}


