/* Ghidra analysis of supplied S-YXG50.dll at 1001d7b0 */

void __thiscall FUN_1001d7b0(void *this,char param_1)

{
  *(char *)((int)this + 0x13) = param_1;
  if (*(char *)((int)this + 0x10) == '\0') {
    *(uint *)((int)this + 0xc) = *(uint *)((int)this + 0xc) & 0xfffffffe;
  }
  else {
    *(uint *)((int)this + 0xc) = *(uint *)((int)this + 0xc) | 1;
    if (param_1 == '\0') {
      *(undefined4 *)((int)this + 0x174) = *(undefined4 *)((int)this + 400);
      return;
    }
  }
  *(undefined4 *)((int)this + 0x174) = *(undefined4 *)((int)this + 0x180);
  return;
}


