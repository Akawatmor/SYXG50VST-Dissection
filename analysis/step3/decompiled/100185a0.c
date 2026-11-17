/* Ghidra analysis of supplied S-YXG50.dll at 100185a0 */

undefined4 __thiscall FUN_100185a0(void *this,char param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1003f20b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = (undefined4 *)operator_new(0x38);
  local_4 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)FUN_10018860(puVar1);
  }
  local_4 = 0xffffffff;
  if (puVar1 != (undefined4 *)0x0) {
    uVar2 = FUN_100188b0(puVar1,*(undefined4 *)((int)this + 4),param_1,param_2);
    if ((char)uVar2 != '\0') {
      *(undefined4 **)((int)this + 0xc) = puVar1;
      ExceptionList = local_c;
      return CONCAT31((int3)((uint)uVar2 >> 8),1);
    }
    FUN_10018890(puVar1);
    puVar1 = (undefined4 *)FUN_1003392b((undefined *)puVar1);
  }
  ExceptionList = local_c;
  return (uint)puVar1 & 0xffffff00;
}


