/* Ghidra analysis of supplied S-YXG50.dll at 10019970 */

undefined4 __thiscall FUN_10019970(void *this,char param_1)

{
  undefined4 in_EAX;
  void *pvVar1;
  uint uVar2;
  
  uVar2 = CONCAT31((int3)((uint)in_EAX >> 8),param_1);
  *(undefined1 *)this = 0;
  *(undefined1 *)((int)this + 0x32) = 0;
  *(undefined1 *)((int)this + 0x31) = 0;
  *(undefined1 *)((int)this + 0x30) = 0;
  if (param_1 != '\0') {
    pvVar1 = operator_new(0x180);
    if (pvVar1 == (void *)0x0) {
      return 0;
    }
    *(void **)((int)this + 0x60) = pvVar1;
    *(uint *)((int)this + 0x34) = (int)pvVar1 + 0xfU & 0xfffffff0;
    FUN_1001b5c0((int)this);
    uVar2 = FUN_10017130();
    *(bool *)((int)this + 0x30) = uVar2 != 0;
    uVar2 = FUN_10017180();
    *(bool *)((int)this + 0x31) = uVar2 != 0;
    uVar2 = FUN_100171d0();
    *(bool *)((int)this + 0x32) = uVar2 != 0;
    *(undefined1 *)this = 1;
  }
  return CONCAT31((int3)(uVar2 >> 8),1);
}


