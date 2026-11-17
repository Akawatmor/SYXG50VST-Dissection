/* Ghidra analysis of supplied S-YXG50.dll at 1001d850 */

void __thiscall FUN_1001d850(void *this,char param_1)

{
  uint uVar1;
  
  *(char *)((int)this + 0x15) = param_1;
  if (*(char *)((int)this + 0x12) == '\0') {
    *(uint *)((int)this + 0xc) = *(uint *)((int)this + 0xc) & 0xfffffffb;
  }
  else {
    *(uint *)((int)this + 0xc) = *(uint *)((int)this + 0xc) | 4;
    if (param_1 == '\0') {
      *(code **)((int)this + 0x17c) = FUN_10028e20;
      goto LAB_1001d88c;
    }
  }
  *(undefined4 *)((int)this + 0x17c) = *(undefined4 *)((int)this + 0x188);
LAB_1001d88c:
  if (*(int *)((int)this + 4) == 1) {
    *(uint *)((int)this + 0xc) = *(uint *)((int)this + 0xc) & 0xfffffffb;
    *(undefined4 *)((int)this + 0x17c) = *(undefined4 *)((int)this + 0x188);
  }
  else if (*(int *)((int)this + 4) == 2) {
    uVar1 = *(uint *)((int)this + 0xc);
    if ((uVar1 & 0x1000) != 0) {
      *(uint *)((int)this + 0xc) = uVar1 | 4;
      *(code **)((int)this + 0x17c) = FUN_10028e20;
      return;
    }
    *(uint *)((int)this + 0xc) = uVar1 & 0xfffffffb;
    *(undefined4 *)((int)this + 0x17c) = *(undefined4 *)((int)this + 0x188);
    return;
  }
  return;
}


