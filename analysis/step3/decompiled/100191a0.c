/* Ghidra analysis of supplied S-YXG50.dll at 100191a0 */

void __thiscall FUN_100191a0(void *this,char *param_1)

{
  code *pcVar1;
  undefined1 *puVar2;
  
  *(char **)((int)this + 8) = param_1 + 0xc;
  *(undefined4 *)((int)this + 4) = 0;
  *(char **)((int)this + 0xc) = param_1 + 0x10;
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)((int)this + 0x18) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)((int)this + 0x1c) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)((int)this + 0x20) = *(undefined4 *)(param_1 + 0x24);
  *(undefined1 **)((int)this + 0x8c) = &LAB_1001a7c0;
  *(code **)((int)this + 0x90) = FUN_1001a880;
  *(undefined1 **)((int)this + 0x94) = &LAB_1001a920;
  *(undefined1 **)((int)this + 0x98) = &LAB_1001a9e0;
  puVar2 = &LAB_1001bde0;
  if (*(int *)(param_1 + 4) != 1) {
    puVar2 = &LAB_1001bb50;
  }
  *(undefined1 **)((int)this + 0x34) = puVar2;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  if (*param_1 != '\0') {
    *(undefined4 *)((int)this + 0x15c) = *(undefined4 *)(param_1 + 0x34);
    *(char **)((int)this + 0x160) = param_1 + 0x38;
    *(char **)((int)this + 0x164) = param_1 + 0x3c;
    *(char **)((int)this + 0x168) = param_1 + 0x40;
    *(char **)((int)this + 0x16c) = param_1 + 0x50;
    if (param_1[0x30] == '\0') {
      *(code **)((int)this + 0x8c) = FUN_1001a090;
      *(code **)((int)this + 0x90) = FUN_1001a130;
      *(code **)((int)this + 0x94) = FUN_1001a1d0;
      *(code **)((int)this + 0x98) = FUN_1001a270;
    }
    else {
      *(code **)((int)this + 0x8c) = FUN_1001abb0;
      *(code **)((int)this + 0x90) = FUN_1001ac90;
      *(code **)((int)this + 0x94) = FUN_1001ad60;
      *(code **)((int)this + 0x98) = FUN_1001ae30;
    }
    if (param_1[0x31] != '\0') {
      *(code **)((int)this + 0x34) = FUN_1001b380;
      return;
    }
    pcVar1 = FUN_1001a570;
    if (*(int *)(param_1 + 4) != 1) {
      pcVar1 = FUN_1001a310;
    }
    *(code **)((int)this + 0x34) = pcVar1;
  }
  return;
}


