/* Ghidra analysis of supplied S-YXG50.dll at 1001d460 */

void __thiscall FUN_1001d460(void *this,char param_1)

{
  uint uVar1;
  
  if (param_1 == '\0') {
    uVar1 = *(uint *)((int)this + 0xc) & 0xffffefff;
  }
  else {
    uVar1 = *(uint *)((int)this + 0xc) | 0x1000;
  }
  *(uint *)((int)this + 0xc) = uVar1;
  if (*(int *)((int)this + 4) == 2) {
    FUN_1001d850(this,*(char *)((int)this + 0x15));
    return;
  }
  return;
}


