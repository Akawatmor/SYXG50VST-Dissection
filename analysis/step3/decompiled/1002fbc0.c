/* Ghidra analysis of supplied S-YXG50.dll at 1002fbc0 */

void __thiscall FUN_1002fbc0(void *this,int param_1,char param_2,undefined1 param_3)

{
  *(int *)this = param_1;
  *(int *)((int)this + 0xc) = param_1;
  *(undefined1 *)((int)this + 8) = param_3;
  *(int *)((int)this + 0x10) = param_1 + 0x200;
  FUN_1002f5a0((void *)((int)this + 0x14),1,*(uint *)((int)this + 4));
  FUN_1002fc00(this,param_2);
  return;
}


