/* Ghidra analysis of supplied S-YXG50.dll at 1001d8e0 */

void __thiscall FUN_1001d8e0(void *this,ushort param_1,uint param_2)

{
  if ((&DAT_10048e08)[(uint)param_1 + (uint)*(byte *)((int)this + 0x1e) * 0xc0] != -1) {
    FUN_1001da80(this,(&DAT_10048e08)[(uint)param_1 + (uint)*(byte *)((int)this + 0x1e) * 0xc0],
                 param_1,param_2);
    FUN_1001db30(this,param_1);
  }
  return;
}


