/* Ghidra analysis of supplied S-YXG50.dll at 1001c120 */

void __thiscall FUN_1001c120(void *this,char param_1)

{
  uint uVar1;
  
  if (param_1 != '\0') {
    uVar1 = FUN_10017180();
    if (uVar1 != 0) {
      **(undefined4 **)((int)this + 0x5c) = 0;
      *(undefined4 *)(*(int *)((int)this + 0x5c) + 0xc) = 0x3f800000;
      *(undefined4 *)(*(int *)((int)this + 0x5c) + 8) = 0x3f800000;
      *(undefined4 *)(*(int *)((int)this + 0x5c) + 4) = 0x3f800000;
      *(code **)((int)this + 0x164) = FUN_100200f0;
      *(code **)((int)this + 0x168) = FUN_100201f0;
      *(code **)((int)this + 0x16c) = FUN_10020340;
      *(code **)((int)this + 0x170) = FUN_10020520;
      *(code **)((int)this + 0x18c) = FUN_1001f160;
      *(code **)((int)this + 400) = FUN_1001f810;
      *(code **)((int)this + 0x194) = FUN_1001cd10;
      *(code **)((int)this + 0x198) = FUN_1001cfa0;
      *(code **)((int)this + 0x19c) = FUN_10020e40;
      *(code **)((int)this + 0x1a0) = FUN_100210f0;
      *(code **)((int)this + 0x1a4) = FUN_10023630;
      *(code **)((int)this + 0x1a8) = FUN_10023b20;
      *(code **)((int)this + 0x1ac) = FUN_100240b0;
      *(code **)((int)this + 0x1b0) = FUN_100244b0;
      *(undefined1 **)((int)this + 0x1b4) = &LAB_10024790;
      *(code **)((int)this + 0x1bc) = FUN_10024ca0;
      *(code **)((int)this + 0x1c0) = FUN_10022040;
      *(code **)((int)this + 0x1c4) = FUN_10022810;
      *(code **)((int)this + 0x1c8) = FUN_10022900;
      *(code **)((int)this + 0x1cc) = FUN_10025a80;
      *(code **)((int)this + 0x1d0) = FUN_100261f0;
      *(code **)((int)this + 0x1d4) = FUN_10026a40;
    }
  }
  return;
}


