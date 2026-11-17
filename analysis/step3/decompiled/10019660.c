/* Ghidra analysis of supplied S-YXG50.dll at 10019660 */

undefined4 __thiscall FUN_10019660(void *this,undefined4 param_1,char param_2,undefined4 param_3)

{
  undefined4 in_EAX;
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = CONCAT31((int3)((uint)in_EAX >> 8),*(char *)((int)this + 0x28));
  if (*(char *)((int)this + 0x28) == '\0') {
    *(undefined4 *)((int)this + 4) = param_3;
    uVar1 = FUN_100197e0((int)this);
    if ((char)uVar1 != '\0') {
      uVar2 = FUN_10019830((int)this);
      if ((char)uVar2 != '\0') {
        uVar2 = FUN_10019970(this,param_2);
        if ((char)uVar2 != '\0') {
          uVar2 = FUN_10019780(this,0xac44);
          *(undefined4 *)((int)this + 0x18) = param_1;
          *(undefined1 *)((int)this + 0x28) = 1;
          return CONCAT31((int3)((uint)uVar2 >> 8),1);
        }
        FUN_100198b0((int)this);
      }
      uVar1 = FUN_10019810((int)this);
    }
  }
  return uVar1 & 0xffffff00;
}


