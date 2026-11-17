/* Ghidra analysis of supplied S-YXG50.dll at 10019780 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_10019780(void *this,uint param_1)

{
  float fVar1;
  longlong lVar2;
  
  if (*(uint *)((int)this + 8) != param_1) {
    *(uint *)((int)this + 8) = param_1;
    fVar1 = _DAT_10048dcc / (float)param_1;
    *(float *)((int)this + 0xc) = fVar1;
    FUN_10017cb0(256.0,fVar1);
    lVar2 = __ftol();
    *(int *)((int)this + 0x10) = (int)lVar2;
    FUN_100198f0((int)this);
  }
  return;
}


