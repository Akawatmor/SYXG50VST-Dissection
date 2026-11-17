/* Ghidra analysis of supplied S-YXG50.dll at 100300c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_100300c0(void *this,float *param_1)

{
  *param_1 = *(float *)((int)this + 0x68) * _DAT_10048df0;
  param_1[1] = *(float *)((int)this + 0x6c) * _DAT_10048df0;
  *(undefined4 *)((int)this + 0x6c) = 0;
  *(undefined4 *)((int)this + 0x68) = 0;
  return;
}


