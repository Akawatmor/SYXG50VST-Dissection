/* Ghidra analysis of supplied S-YXG50.dll at 10018c90 */

void __thiscall FUN_10018c90(void *this,int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)((int)this + 0x24) + (param_1 * 0x10 - *(int *)((int)this + 0x24) >> 4);
  *(int *)((int)this + 0x24) = iVar1;
  *(int *)((int)this + 0x20) = iVar1 >> 4;
  iVar1 = *(int *)((int)this + 0x2c) + (param_2 * 0x10 - *(int *)((int)this + 0x2c) >> 4);
  *(int *)((int)this + 0x2c) = iVar1;
  *(int *)((int)this + 0x28) = iVar1 >> 4;
  iVar1 = *(int *)((int)this + 0x34) + (param_3 * 0x10 - *(int *)((int)this + 0x34) >> 4);
  *(int *)((int)this + 0x34) = iVar1;
  *(int *)((int)this + 0x30) = iVar1 >> 4;
  return;
}


