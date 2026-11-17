/* Ghidra analysis of supplied S-YXG50.dll at 100189e0 */

undefined4 __thiscall FUN_100189e0(void *this,undefined4 param_1,char param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  char *this_00;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1003f22b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = (undefined1 *)operator_new(0x68);
  local_4 = 0;
  if (puVar1 == (undefined1 *)0x0) {
    this_00 = (char *)0x0;
  }
  else {
    this_00 = (char *)FUN_10019610(puVar1);
  }
  local_4 = 0xffffffff;
  if (this_00 != (char *)0x0) {
    uVar2 = FUN_10019660(this_00,param_1,param_2,param_3);
    if ((char)uVar2 != '\0') {
      *(char **)((int)this + 8) = this_00;
      ExceptionList = local_c;
      return CONCAT31((int3)((uint)uVar2 >> 8),1);
    }
    FUN_10019640(this_00);
    this_00 = (char *)FUN_1003392b(this_00);
  }
  ExceptionList = local_c;
  return (uint)this_00 & 0xffffff00;
}


