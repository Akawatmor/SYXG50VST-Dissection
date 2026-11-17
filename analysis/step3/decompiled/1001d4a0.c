/* Ghidra analysis of supplied S-YXG50.dll at 1001d4a0 */

void __thiscall FUN_1001d4a0(void *this,byte param_1)

{
  *(byte *)((int)this + 0x1c) = param_1;
  *(code **)((int)this + 0x180) = FUN_10028e20;
  *(undefined1 *)((int)this + 0x10) = 0;
  if ((param_1 != 0) && (param_1 < 0x13)) {
    *(undefined4 *)((int)this + 0x180) = *(undefined4 *)((int)this + 0x18c);
    *(undefined1 *)((int)this + 0x10) = 1;
  }
  FUN_1001d7b0(this,*(char *)((int)this + 0x13));
  return;
}


