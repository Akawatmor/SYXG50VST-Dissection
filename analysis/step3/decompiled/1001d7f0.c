/* Ghidra analysis of supplied S-YXG50.dll at 1001d7f0 */

void __thiscall FUN_1001d7f0(void *this,char param_1)

{
  *(char *)((int)this + 0x14) = param_1;
  if (*(char *)((int)this + 0x11) == '\0') {
    *(uint *)((int)this + 0xc) = *(uint *)((int)this + 0xc) & 0xfffffffd;
  }
  else {
    *(uint *)((int)this + 0xc) = *(uint *)((int)this + 0xc) | 2;
    if (param_1 == '\0') {
      *(code **)((int)this + 0x178) = FUN_10028e20;
      goto LAB_1001d82f;
    }
  }
  *(undefined4 *)((int)this + 0x178) = *(undefined4 *)((int)this + 0x184);
LAB_1001d82f:
  if (*(int *)((int)this + 4) == 1) {
    *(uint *)((int)this + 0xc) = *(uint *)((int)this + 0xc) & 0xfffffffd;
    *(undefined4 *)((int)this + 0x178) = *(undefined4 *)((int)this + 0x184);
  }
  return;
}


