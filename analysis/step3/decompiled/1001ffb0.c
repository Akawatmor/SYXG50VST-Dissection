/* Ghidra analysis of supplied S-YXG50.dll at 1001ffb0 */

void __thiscall FUN_1001ffb0(void *this,int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = *(int *)((int)this + 0x2f0) + (param_1 * 0x10 - *(int *)((int)this + 0x2f0) >> 4);
  *(int *)((int)this + 0x2f0) = iVar1;
  *(int *)((int)this + 0x2ec) = iVar1 >> 4;
  iVar1 = *(int *)((int)this + 0x2f8) + (param_2 * 0x10 - *(int *)((int)this + 0x2f8) >> 4);
  *(int *)((int)this + 0x2f8) = iVar1;
  *(int *)((int)this + 0x2f4) = iVar1 >> 4;
  iVar1 = *(int *)((int)this + 0x300) + (param_3 * 0x10 - *(int *)((int)this + 0x300) >> 4);
  *(int *)((int)this + 0x300) = iVar1;
  *(int *)((int)this + 0x2fc) = iVar1 >> 4;
  iVar1 = *(int *)((int)this + 0x308) + (param_4 * 0x10 - *(int *)((int)this + 0x308) >> 4);
  *(int *)((int)this + 0x308) = iVar1;
  *(int *)((int)this + 0x304) = iVar1 >> 4;
  return;
}


