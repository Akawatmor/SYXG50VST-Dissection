/* Ghidra analysis of supplied S-YXG50.dll at 1001da80 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_1001da80(void *this,char param_1,ushort param_2,uint param_3)

{
  uint uVar1;
  float fVar2;
  ushort uVar3;
  
  uVar3 = (ushort)(param_3 & 0x3ff);
  if (param_1 != '\x02') {
    if (0x200 < uVar3) {
      uVar3 = uVar3 | 0xfc00;
    }
    fVar2 = (float)(int)(short)uVar3 * _DAT_10049228;
    if (param_1 == '\x01') {
      fVar2 = fVar2 * _DAT_10049224;
    }
    *(float *)(*(int *)((int)this + 0x60) + (uint)param_2 * 4) = fVar2;
    return;
  }
  uVar1 = (param_3 & 0x3ff) >> 7;
  if ((short)uVar1 == 7) {
    *(float *)(*(int *)((int)this + 0x60) + (uint)param_2 * 4) =
         _DAT_10048df4 * (float)(param_3 & 0x7f);
    return;
  }
  *(float *)(*(int *)((int)this + 0x60) + (uint)param_2 * 4) =
       (float)(1 << (sbyte)uVar1) * _DAT_10048e04 * (float)(param_3 & 0x7f);
  return;
}


