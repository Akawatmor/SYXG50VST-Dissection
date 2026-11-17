/* Ghidra analysis of supplied S-YXG50.dll at 1001d930 */

void __thiscall FUN_1001d930(void *this,ushort param_1)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  
  uVar2 = (uint)param_1;
  uVar1 = (uint)*(byte *)((int)this + 0x1e);
  if ((&DAT_10049108)[uVar2 + uVar1 * 0x40] != -1) {
    switch(uVar2) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1b:
    case 0x1c:
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x3f:
      lVar3 = __ftol();
      *(int *)((int)this + uVar2 * 4 + 100) = (int)lVar3;
      return;
    }
    if (uVar1 == 0) {
      switch(uVar2) {
      case 0x28:
      case 0x2d:
      case 0x33:
      case 0x38:
      case 0x3a:
      case 0x3b:
        lVar3 = __ftol();
        *(int *)((int)this + uVar2 * 4 + 100) = (int)lVar3;
      }
    }
    else if (uVar1 == 2) {
      if ((0x23 < uVar2) && (uVar2 < 0x3f)) {
        lVar3 = __ftol();
        *(int *)((int)this + uVar2 * 4 + 100) = (int)lVar3;
        return;
      }
    }
    else if (((uVar1 == 3) && (0x23 < uVar2)) && (uVar2 < 0x3f)) {
      lVar3 = __ftol();
      *(int *)((int)this + uVar2 * 4 + 100) = (int)lVar3;
      return;
    }
  }
  return;
}


