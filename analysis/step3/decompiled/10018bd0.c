/* Ghidra analysis of supplied S-YXG50.dll at 10018bd0 */

void __thiscall FUN_10018bd0(void *this,char param_1)

{
  uint *puVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  void *this_00;
  undefined4 *puVar7;
  
  if (param_1 == '\0') {
    iVar4 = *(int *)((int)this + 0xc);
    iVar5 = 0x100;
    do {
      FUN_100192d0(iVar4);
      iVar4 = iVar4 + 0x170;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar2 = 0;
    iVar4 = 0x80;
    puVar1 = *this;
    do {
      uVar6 = (uint)uVar2;
      uVar2 = uVar2 + 1;
      iVar4 = iVar4 + -1;
      *puVar1 = uVar6;
      puVar1 = puVar1 + 0x15;
    } while (iVar4 != 0);
    this_00 = *(void **)((int)this + 0xc);
    iVar4 = 0x100;
    do {
      FUN_100191a0(this_00,*(char **)((int)this + 8));
      this_00 = (void *)((int)this_00 + 0x170);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar4 = *(int *)((int)this + 0xc);
    piVar3 = *(int **)((int)this + 0x10);
    iVar5 = 0x80;
    do {
      *piVar3 = iVar4;
      iVar4 = iVar4 + 0x170;
      piVar3 = piVar3 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  puVar7 = *(undefined4 **)((int)this + 0x18);
  for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined4 *)((int)this + 0x1c) = 0;
  return;
}


