/* Ghidra analysis of supplied S-YXG50.dll at 10019c30 */

void __thiscall FUN_10019c30(void *this,int param_1,uint param_2)

{
  *(undefined4 *)(*(int *)((int)this + 0x14) + param_1 * 4) =
       *(undefined4 *)(*(int *)((int)this + 0x10) + (param_2 & 0x1f | param_1 << 5) * 4);
  FUN_100193d0(*(void **)(*(int *)((int)this + 0x14) + param_1 * 4),param_2);
  return;
}


