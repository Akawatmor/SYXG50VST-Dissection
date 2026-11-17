/* Ghidra analysis of supplied S-YXG50.dll at 10018480 */

undefined4 __thiscall FUN_10018480(void *this,char param_1,undefined1 param_2)

{
  undefined4 *puVar1;
  void *this_00;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1003f1eb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = (undefined4 *)operator_new(0x7c);
  local_4 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    this_00 = (void *)0x0;
  }
  else {
    this_00 = (void *)FUN_1002fb60(puVar1);
  }
  local_4 = 0xffffffff;
  if (this_00 != (void *)0x0) {
    uVar2 = FUN_1002fbc0(this_00,*(int *)((int)this + 4),param_1,param_2);
    *(void **)((int)this + 0x14) = this_00;
    ExceptionList = local_c;
    return CONCAT31((int3)((uint)uVar2 >> 8),1);
  }
  ExceptionList = local_c;
  return 0;
}


