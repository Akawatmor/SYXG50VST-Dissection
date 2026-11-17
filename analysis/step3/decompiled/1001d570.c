/* Ghidra analysis of supplied S-YXG50.dll at 1001d570 */

void __thiscall FUN_1001d570(void *this,undefined1 param_1,byte param_2)

{
  undefined4 uVar1;
  
  *(undefined1 *)((int)this + 0x1e) = param_1;
  *(byte *)((int)this + 0x1f) = param_2;
  *(code **)((int)this + 0x188) = FUN_10028e20;
  *(undefined1 *)((int)this + 0x12) = 0;
  switch(param_1) {
  case 0:
    switch(param_2) {
    case 1:
      *(undefined4 *)((int)this + 0x188) = *(undefined4 *)((int)this + 0x1b8);
      *(undefined1 *)((int)this + 0x12) = 1;
      FUN_1001d850(this,*(char *)((int)this + 0x15));
      return;
    case 2:
    case 3:
    case 4:
    case 8:
    case 9:
    case 0x14:
    case 0x16:
      uVar1 = *(undefined4 *)((int)this + 0x19c);
      break;
    case 5:
    case 6:
    case 7:
    case 0x15:
      *(undefined4 *)((int)this + 0x188) = *(undefined4 *)((int)this + 0x1a0);
      *(undefined1 *)((int)this + 0x12) = 1;
      FUN_1001d850(this,*(char *)((int)this + 0x15));
      return;
    case 10:
      uVar1 = *(undefined4 *)((int)this + 0x1a4);
      break;
    case 0xb:
      *(undefined4 *)((int)this + 0x188) = *(undefined4 *)((int)this + 0x1a8);
      *(undefined1 *)((int)this + 0x12) = 1;
      FUN_1001d850(this,*(char *)((int)this + 0x15));
      return;
    case 0xc:
    case 0xd:
      uVar1 = *(undefined4 *)((int)this + 0x1ac);
      break;
    case 0xe:
    case 0xf:
    case 0x10:
    case 0x11:
      *(undefined4 *)((int)this + 0x188) = *(undefined4 *)((int)this + 0x1b0);
      *(undefined1 *)((int)this + 0x12) = 1;
      FUN_1001d850(this,*(char *)((int)this + 0x15));
      return;
    default:
      goto switchD_1001d598_default;
    case 0x13:
      uVar1 = *(undefined4 *)((int)this + 0x1b4);
    }
    break;
  case 1:
    if ((param_2 != 0) && (param_2 < 3)) {
      *(undefined4 *)((int)this + 0x188) = *(undefined4 *)((int)this + 0x1bc);
      *(undefined1 *)((int)this + 0x12) = 1;
      FUN_1001d850(this,*(char *)((int)this + 0x15));
      return;
    }
    goto switchD_1001d598_default;
  case 2:
    switch(param_2) {
    case 1:
    case 2:
    case 3:
    case 4:
      uVar1 = *(undefined4 *)((int)this + 0x1c0);
      break;
    case 5:
    case 6:
    case 7:
      *(undefined4 *)((int)this + 0x188) = *(undefined4 *)((int)this + 0x1c4);
      *(undefined1 *)((int)this + 0x12) = 1;
      FUN_1001d850(this,*(char *)((int)this + 0x15));
      return;
    case 8:
      uVar1 = *(undefined4 *)((int)this + 0x1c8);
      break;
    default:
      goto switchD_1001d598_default;
    }
    break;
  case 3:
    switch(param_2) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
      uVar1 = *(undefined4 *)((int)this + 0x1cc);
      break;
    case 9:
      uVar1 = *(undefined4 *)((int)this + 0x1d4);
      break;
    case 10:
    case 0xb:
    case 0xc:
      *(undefined4 *)((int)this + 0x188) = *(undefined4 *)((int)this + 0x1d0);
      *(undefined1 *)((int)this + 0x12) = 1;
      FUN_1001d850(this,*(char *)((int)this + 0x15));
      return;
    default:
      goto switchD_1001d598_default;
    }
    break;
  default:
    goto switchD_1001d598_default;
  }
  *(undefined4 *)((int)this + 0x188) = uVar1;
  *(undefined1 *)((int)this + 0x12) = 1;
switchD_1001d598_default:
  FUN_1001d850(this,*(char *)((int)this + 0x15));
  return;
}


