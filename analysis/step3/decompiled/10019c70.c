/* Ghidra analysis of supplied S-YXG50.dll at 10019c70 */

void __thiscall FUN_10019c70(void *this,int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  void *this_00;
  undefined4 local_4;
  
  uVar5 = param_1 * 0x20;
  uVar1 = (param_1 + 1) * 0x20;
  local_4 = 1;
  if (uVar5 < uVar1) {
    iVar6 = param_1 * 0xa80;
    do {
      if ((local_4 & param_2) != 0) {
        iVar4 = 0x100;
        uVar3 = *(uint *)((int)this + 0x1c);
        do {
          iVar4 = iVar4 + -1;
          uVar2 = *(int *)((int)this + 0x1c) + 1U & 0xff;
          *(uint *)((int)this + 0x1c) = uVar2;
          if (*(char *)(*(int *)((int)this + 0x18) + uVar3) == '\0') break;
          uVar3 = uVar2;
        } while (iVar4 != 0);
        this_00 = (void *)(uVar3 * 0x170 + *(int *)((int)this + 0xc));
        *(void **)(*(int *)((int)this + 0x10) + uVar5 * 4) = this_00;
        *(undefined1 *)(uVar3 + *(int *)((int)this + 0x18)) = 1;
        FUN_100192d0((int)this_00);
                    /* WARNING: Load size is inaccurate */
        FUN_10019390(this_00,*this + iVar6);
      }
      local_4 = local_4 << 1;
      uVar5 = uVar5 + 1;
      iVar6 = iVar6 + 0x54;
    } while (uVar5 < uVar1);
  }
  return;
}


