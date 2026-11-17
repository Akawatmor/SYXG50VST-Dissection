/* Ghidra analysis of supplied S-YXG50.dll at 10018ac0 */

undefined4 __fastcall FUN_10018ac0(undefined4 *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  void *pvVar5;
  undefined4 uVar6;
  
  puVar1 = (undefined *)operator_new(0x2a00);
  if (puVar1 != (undefined *)0x0) {
    puVar2 = (undefined *)operator_new(0x17000);
    if (puVar2 != (undefined *)0x0) {
      puVar3 = (undefined *)operator_new(0x200);
      if (puVar3 != (undefined *)0x0) {
        puVar4 = (undefined *)operator_new(0x10);
        if (puVar4 != (undefined *)0x0) {
          pvVar5 = operator_new(0x100);
          if (pvVar5 != (void *)0x0) {
            param_1[3] = puVar2;
            *param_1 = puVar1;
            param_1[4] = puVar3;
            param_1[5] = puVar4;
            param_1[6] = pvVar5;
            uVar6 = FUN_10018bd0(param_1,'\x01');
            return CONCAT31((int3)((uint)uVar6 >> 8),1);
          }
          FUN_1003392b(puVar4);
        }
        FUN_1003392b(puVar3);
      }
      FUN_1003392b(puVar2);
    }
    puVar1 = (undefined *)FUN_1003392b(puVar1);
  }
  return (uint)puVar1 & 0xffffff00;
}


