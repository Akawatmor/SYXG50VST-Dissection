/* Ghidra analysis of supplied S-YXG50.dll at 1001d350 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_1001d350(void *this,uint param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float10 fVar5;
  
  *(uint *)((int)this + 0x18) = param_1;
  fVar5 = FUN_10017ca0((float)param_1,44100.0);
  fVar1 = (float)fVar5;
  *(float *)((int)this + 0x20) = fVar1;
  fVar2 = _DAT_10048dd8;
  if (0xac44 < param_1) {
    fVar2 = fVar1;
  }
  *(float *)((int)this + 0x24) = fVar2;
  fVar5 = FUN_10017ca0(1.0,fVar1);
  *(float *)((int)this + 0x28) = (float)fVar5;
  *(float *)((int)this + 0x2c) = *(float *)((int)this + 0x20) * _DAT_10049220;
  fVar2 = _DAT_10048dd8;
  if (param_1 < 0xac45) {
    fVar3 = _DAT_10049210;
    if ((param_1 == 0xac44) ||
       (((fVar3 = _DAT_10049214, param_1 == 0x2b11 || (fVar3 = _DAT_10049218, param_1 == 0x5622)) ||
        (fVar3 = _DAT_1004921c, param_1 == 0x8133)))) goto LAB_1001d428;
  }
  else {
    fVar3 = _DAT_10049208;
    if ((param_1 == 48000) || (fVar3 = _DAT_1004920c, param_1 == 96000)) goto LAB_1001d428;
  }
  fVar3 = fVar1;
LAB_1001d428:
  *(undefined4 *)((int)this + 0x30) = 0x3f800000;
  iVar4 = 0x80;
  do {
    iVar4 = iVar4 + -1;
    fVar2 = fVar2 * fVar3;
  } while (iVar4 != 0);
  *(float *)((int)this + 0x30) = fVar2;
  return;
}


