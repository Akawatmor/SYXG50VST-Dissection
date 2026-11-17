/* Ghidra analysis of supplied S-YXG50.dll at 1002f650 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_1002f650(void *this,int param_1)

{
  float10 extraout_ST0;
  longlong lVar1;
  
  if (param_1 != 0) {
    lVar1 = __ftol();
    *(float *)this = (float)extraout_ST0;
    *(int *)((int)this + 8) = (int)lVar1;
    *(float *)((int)this + 0x2c) =
         (float)((float10)_DAT_10048dd8 / ((float10)*(uint *)((int)this + 0xc) * extraout_ST0));
    return CONCAT31((int3)((ulonglong)lVar1 >> 8),1);
  }
  return 0;
}


