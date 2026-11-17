/* Ghidra analysis of supplied S-YXG50.dll at 10017220 */

undefined4 __thiscall FUN_10017220(void *this,char param_1,undefined4 param_2,undefined1 param_3)

{
  undefined1 *puVar1;
  char *this_00;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1003f18b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = (undefined1 *)operator_new(0x18);
  local_4 = 0;
  if (puVar1 == (undefined1 *)0x0) {
    this_00 = (char *)0x0;
  }
  else {
    this_00 = (char *)FUN_10018090(puVar1);
  }
  local_4 = 0xffffffff;
  if (this_00 != (char *)0x0) {
    uVar2 = FUN_100180e0(this_00,param_1,param_2,param_3);
    if ((char)uVar2 != '\0') {
      *(char **)((int)this + 0xc) = this_00;
      ExceptionList = local_c;
      return CONCAT31((int3)((uint)uVar2 >> 8),1);
    }
    FUN_100180b0(this_00);
    this_00 = (char *)FUN_1003392b(this_00);
  }
  ExceptionList = local_c;
  return (uint)this_00 & 0xffffff00;
}


