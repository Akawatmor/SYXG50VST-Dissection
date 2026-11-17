/* Ghidra analysis of supplied S-YXG50.dll at 1002fc30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_1002fc30(void *this,uint param_1)

{
  *(uint *)((int)this + 4) = param_1;
  *(float *)((int)this + 0x50) = _DAT_1004dec8 / (float)param_1;
  FUN_1002f650((void *)((int)this + 0x14),param_1);
  return;
}


