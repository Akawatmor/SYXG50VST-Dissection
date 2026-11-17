/* Ghidra analysis of supplied S-YXG50.dll at 100188b0 */

undefined4 __thiscall FUN_100188b0(void *this,undefined4 param_1,char param_2,undefined4 param_3)

{
  undefined4 in_EAX;
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = CONCAT31((int3)((uint)in_EAX >> 8),*(char *)((int)this + 4));
  if (*(char *)((int)this + 4) == '\0') {
    uVar1 = FUN_100189e0(this,param_1,param_2,param_3);
    if ((char)uVar1 != '\0') {
      uVar2 = FUN_10018ac0((undefined4 *)this);
      if ((char)uVar2 != '\0') {
        *(undefined1 *)((int)this + 4) = 1;
        return CONCAT31((int3)((uint)uVar2 >> 8),1);
      }
      uVar1 = FUN_10018a90((int)this);
    }
  }
  return uVar1 & 0xffffff00;
}


