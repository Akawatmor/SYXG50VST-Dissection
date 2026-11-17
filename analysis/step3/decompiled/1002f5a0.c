/* Ghidra analysis of supplied S-YXG50.dll at 1002f5a0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_1002f5a0(void *this,int param_1,uint param_2)

{
  float fVar1;
  undefined1 *puVar2;
  
  if (param_2 != 0) {
    *(float *)this = (float)param_2;
    fVar1 = _DAT_10048dd8 / (float)param_2;
    *(undefined4 *)((int)this + 0x18) = 0x1e;
    *(undefined4 *)((int)this + 0x1c) = 0x1e;
    *(undefined4 *)((int)this + 4) = 0;
    *(undefined4 *)((int)this + 8) = 0;
    *(undefined4 *)((int)this + 0xc) = 1;
    *(undefined4 *)((int)this + 0x10) = 1;
    *(undefined4 *)((int)this + 0x20) = 600;
    *(undefined4 *)((int)this + 0x24) = 0;
    *(undefined4 *)((int)this + 0x28) = 0x3f800000;
    puVar2 = &LAB_1002f6e0;
    *(float *)((int)this + 0x2c) = fVar1;
    if (param_1 != 0) {
      puVar2 = &LAB_1002f760;
    }
    *(undefined1 **)((int)this + 0x30) = puVar2;
    puVar2 = (undefined1 *)FUN_10017180();
    if (puVar2 != (undefined1 *)0x0) {
      puVar2 = &LAB_1002f950;
      if (param_1 != 0) {
        puVar2 = &LAB_1002f9c0;
      }
      *(undefined1 **)((int)this + 0x30) = puVar2;
    }
    return CONCAT31((int3)((uint)puVar2 >> 8),1);
  }
  return 0;
}


