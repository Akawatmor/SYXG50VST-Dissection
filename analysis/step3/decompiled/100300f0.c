/* Ghidra analysis of supplied S-YXG50.dll at 100300f0 */

void __thiscall FUN_100300f0(void *this,int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)this + 0x78) + (param_1 * 0x10 - *(int *)((int)this + 0x78) >> 4);
  *(int *)((int)this + 0x78) = iVar1;
  *(int *)((int)this + 0x74) = iVar1 >> 4;
  return;
}


