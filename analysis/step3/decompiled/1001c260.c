/* Ghidra analysis of supplied S-YXG50.dll at 1001c260 */

uint __fastcall FUN_1001c260(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  void *pvVar3;
  uint uVar4;
  
  puVar1 = (undefined *)operator_new(0x80010);
  if (puVar1 != (undefined *)0x0) {
    puVar2 = (undefined *)operator_new(0x20020);
    if (puVar2 != (undefined *)0x0) {
      pvVar3 = operator_new(0x80020);
      if (pvVar3 != (void *)0x0) {
        *(undefined **)(param_1 + 0x40) = puVar1;
        *(undefined **)(param_1 + 0x44) = puVar2;
        *(void **)(param_1 + 0x48) = pvVar3;
        *(uint *)(param_1 + 0x4c) = (uint)(puVar1 + 0xf) & 0xfffffff0;
        uVar4 = (int)pvVar3 + 0xfU & 0xfffffff0;
        *(uint *)(param_1 + 0x50) = (uint)(puVar2 + 0xf) & 0xfffffff0;
        *(uint *)(param_1 + 0x54) = uVar4;
        return CONCAT31((int3)(uVar4 >> 8),1);
      }
      FUN_1003392b(puVar2);
    }
    puVar1 = (undefined *)FUN_1003392b(puVar1);
  }
  return (uint)puVar1 & 0xffffff00;
}


