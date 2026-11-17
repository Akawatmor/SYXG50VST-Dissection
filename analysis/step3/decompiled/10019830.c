/* Ghidra analysis of supplied S-YXG50.dll at 10019830 */

undefined4 __fastcall FUN_10019830(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined *local_c;
  undefined *local_8;
  undefined4 local_4;
  
  uVar1 = FUN_10017fa0(&local_8);
  if ((char)uVar1 != '\0') {
    uVar2 = FUN_10017fa0(&local_c);
    if ((char)uVar2 != '\0') {
      uVar2 = FUN_10017fa0(&local_4);
      if ((char)uVar2 != '\0') {
        *(undefined **)(param_1 + 0x1c) = local_8;
        *(undefined **)(param_1 + 0x20) = local_c;
        *(undefined4 *)(param_1 + 0x24) = local_4;
        return CONCAT31((int3)((uint)local_8 >> 8),1);
      }
      thunk_FUN_1003392b(local_c);
    }
    uVar1 = thunk_FUN_1003392b(local_8);
  }
  return uVar1 & 0xffffff00;
}


