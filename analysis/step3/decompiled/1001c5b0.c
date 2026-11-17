/* Ghidra analysis of supplied S-YXG50.dll at 1001c5b0 */

undefined4 __fastcall FUN_1001c5b0(int param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined *)operator_new(0xc10);
  if (puVar1 != (undefined *)0x0) {
    puVar2 = (undefined4 *)operator_new(0x300);
    if (puVar2 != (undefined4 *)0x0) {
      *(undefined **)(param_1 + 0x58) = puVar1;
      *(uint *)(param_1 + 0x5c) = (uint)(puVar1 + 0xf) & 0xfffffff0;
      *(undefined4 **)(param_1 + 0x60) = puVar2;
      uVar3 = FUN_10017c70(puVar2,0x300);
      return CONCAT31((int3)((uint)uVar3 >> 8),1);
    }
    puVar1 = (undefined *)FUN_1003392b(puVar1);
  }
  return (uint)puVar1 & 0xffffff00;
}


