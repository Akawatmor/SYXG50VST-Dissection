/* Ghidra analysis of supplied S-YXG50.dll at 1001db30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_1001db30(void *this,ushort param_1)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  
  uVar3 = (uint)param_1;
  switch(uVar3) {
  case 1:
  case 0xd:
    *(float *)(*(int *)((int)this + 0x5c) + 0x1c) =
         *(float *)(*(int *)((int)this + 0x60) + 0x34) * *(float *)(*(int *)((int)this + 0x60) + 4);
    *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x18) =
         *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x1c);
    *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x14) =
         *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x18);
    *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x10) =
         *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x14);
    return;
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 0xe:
  case 0xf:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x17:
  case 0x18:
  case 0x42:
  case 0x4f:
  case 0x50:
  case 0x60:
  case 0x61:
  case 0x69:
  case 0x6a:
    *(undefined4 *)(*(int *)((int)this + 0x5c) + 0xc + uVar3 * 0x10) =
         *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
    iVar4 = *(int *)((int)this + 0x5c) + uVar3 * 0x10;
    goto LAB_1001e535;
  case 9:
    lVar5 = __ftol();
    *(int *)((int)this + 0x228) = (int)lVar5;
    return;
  default:
    switch(*(undefined1 *)((int)this + 0x1e)) {
    case 0:
      switch(uVar3) {
      case 0x6d:
      case 0x70:
        lVar5 = __ftol();
        *(int *)((int)this + 0x2a4) = (int)lVar5;
        return;
      case 0x6e:
        lVar5 = __ftol();
        *(int *)((int)this + 0x2a8) = (int)lVar5;
        return;
      case 0x6f:
      case 0x7a:
      case 0x89:
      case 0x8e:
        iVar4 = uVar3 * 0x10;
        *(undefined4 *)(iVar4 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        if (uVar3 == 0x7a) {
          *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x6f4) =
               *(undefined4 *)(iVar4 + *(int *)((int)this + 0x5c));
          return;
        }
        if (uVar3 == 0x89) {
          *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x6f8) =
               *(undefined4 *)(iVar4 + *(int *)((int)this + 0x5c));
          return;
        }
        if (uVar3 == 0x8e) {
          *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x6fc) =
               *(undefined4 *)(iVar4 + *(int *)((int)this + 0x5c));
          return;
        }
        break;
      case 0x71:
      case 0x7b:
      case 0x8a:
      case 0x8f:
        iVar4 = uVar3 * 0x10;
        *(float *)(iVar4 + *(int *)((int)this + 0x5c)) =
             _DAT_10048dd8 -
             *(float *)(*(int *)((int)this + 0x60) + uVar3 * 4) * *(float *)((int)this + 0x28) *
             _DAT_10049224;
        if (*(float *)(*(int *)((int)this + 0x5c) + iVar4) < _DAT_100402b0) {
          *(undefined4 *)(*(int *)((int)this + 0x5c) + iVar4) = 0;
        }
        if (uVar3 == 0x7b) {
          *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x714) =
               *(undefined4 *)(iVar4 + *(int *)((int)this + 0x5c));
          return;
        }
        if (uVar3 == 0x8a) {
          *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x718) =
               *(undefined4 *)(iVar4 + *(int *)((int)this + 0x5c));
          return;
        }
        if (uVar3 == 0x8f) {
          *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x71c) =
               *(undefined4 *)(iVar4 + *(int *)((int)this + 0x5c));
          return;
        }
        break;
      case 0x72:
      case 0x7c:
      case 0x8b:
      case 0x90:
        iVar4 = uVar3 * 0x10;
        *(float *)(iVar4 + *(int *)((int)this + 0x5c)) =
             *(float *)(*(int *)((int)this + 0x60) + uVar3 * 4) * *(float *)((int)this + 0x28) *
             _DAT_10049224;
        if (_DAT_10048dd8 < *(float *)(*(int *)((int)this + 0x5c) + iVar4)) {
          *(undefined4 *)(*(int *)((int)this + 0x5c) + iVar4) = 0x3f800000;
        }
        if (uVar3 == 0x7c) {
          *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x724) =
               *(undefined4 *)(iVar4 + *(int *)((int)this + 0x5c));
          return;
        }
        if (uVar3 == 0x8b) {
          *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x728) =
               *(undefined4 *)(iVar4 + *(int *)((int)this + 0x5c));
          return;
        }
        if (uVar3 == 0x90) {
          *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x72c) =
               *(undefined4 *)(iVar4 + *(int *)((int)this + 0x5c));
          return;
        }
        break;
      case 0x73:
      case 0x7d:
      case 0x8c:
      case 0x91:
        iVar4 = uVar3 * 0x10;
        *(undefined4 *)(iVar4 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        if (uVar3 == 0x7d) {
          *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x734) =
               *(undefined4 *)(iVar4 + *(int *)((int)this + 0x5c));
          return;
        }
        if (uVar3 == 0x8c) {
          *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x738) =
               *(undefined4 *)(iVar4 + *(int *)((int)this + 0x5c));
          return;
        }
        if (uVar3 == 0x91) {
          *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x73c) =
               *(undefined4 *)(iVar4 + *(int *)((int)this + 0x5c));
          return;
        }
        break;
      case 0x74:
        iVar4 = *(int *)((int)this + 0x60);
        lVar5 = __ftol();
        *(int *)((int)this + 0x2ac) = (int)lVar5;
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(iVar4 + uVar3 * 4);
        return;
      case 0x75:
        iVar4 = *(int *)((int)this + 0x60);
        lVar5 = __ftol();
        *(int *)((int)this + 0x2c0) = (int)lVar5;
        *(float *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(float *)((int)this + 0x2c) * *(float *)(iVar4 + uVar3 * 4);
        return;
      case 0x76:
      case 0x86:
      case 0x96:
        iVar4 = uVar3 * 0x10;
        *(float *)(iVar4 + *(int *)((int)this + 0x5c)) =
             *(float *)(*(int *)((int)this + 0x60) + uVar3 * 4) * *(float *)((int)this + 0x2c);
        if (uVar3 == 0x86) {
          *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x764) =
               *(undefined4 *)(iVar4 + *(int *)((int)this + 0x5c));
          return;
        }
        if (uVar3 == 0x96) {
          *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x768) =
               *(undefined4 *)(iVar4 + *(int *)((int)this + 0x5c));
          return;
        }
        break;
      case 0x77:
        lVar5 = __ftol();
        *(int *)((int)this + 0x2a0) = (int)lVar5;
        lVar5 = __ftol();
        *(int *)((int)this + 0x2a4) = (int)lVar5;
        return;
      case 0x79:
        lVar5 = __ftol();
        *(int *)((int)this + 0x2b0) = (int)lVar5;
        return;
      case 0x7e:
      case 0x7f:
      case 0x80:
      case 0xa7:
      case 0xa8:
      case 0xa9:
switchD_1001e361_caseD_6d:
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        return;
      case 0x83:
      case 0x94:
      case 0xa4:
        iVar4 = uVar3 * 0x10;
        *(undefined4 *)(iVar4 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        if (uVar3 == 0x94) {
          *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x834) =
               *(undefined4 *)(iVar4 + *(int *)((int)this + 0x5c));
          return;
        }
        if (uVar3 == 0xa4) {
          *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x838) =
               *(undefined4 *)(iVar4 + *(int *)((int)this + 0x5c));
          return;
        }
        break;
      case 0x84:
        iVar4 = *(int *)((int)this + 0x60);
        lVar5 = __ftol();
        *(int *)((int)this + 0x2b4) = (int)lVar5;
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x744) = *(undefined4 *)(iVar4 + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x744);
        return;
      case 0x85:
        iVar4 = *(int *)((int)this + 0x60);
        lVar5 = __ftol();
        *(int *)((int)this + 0x2c4) = (int)lVar5;
        *(float *)(*(int *)((int)this + 0x5c) + 0x754) =
             *(float *)((int)this + 0x2c) * *(float *)(iVar4 + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x754);
        return;
      case 0x88:
        lVar5 = __ftol();
        *(int *)((int)this + 0x2b8) = (int)lVar5;
        return;
      case 0x8d:
        lVar5 = __ftol();
        *(int *)((int)this + 700) = (int)lVar5;
        return;
      case 0x95:
        iVar4 = *(int *)((int)this + 0x60);
        lVar5 = __ftol();
        *(int *)((int)this + 0x2c8) = (int)lVar5;
        *(float *)(*(int *)((int)this + 0x5c) + 0x758) =
             *(float *)((int)this + 0x2c) * *(float *)(iVar4 + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x758);
        return;
      case 0x98:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x7e8) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x7e8);
        return;
      case 0x99:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x7f8) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x7f8);
        return;
      case 0x9a:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x808) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x808);
        return;
      case 0x9b:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0xa78) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0xa78);
        return;
      case 0x9c:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0xa88) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0xa88);
        return;
      case 0x9d:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0xa98) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0xa98);
        return;
      case 0x9e:
      case 0x9f:
      case 0xa0:
      case 0xa1:
      case 0xaa:
      case 0xab:
      case 0xac:
      case 0xad:
      case 0xae:
      case 0xaf:
      case 0xb2:
      case 0xb3:
      case 0xb4:
      case 0xb5:
      case 0xb6:
      case 0xb7:
      case 0xb8:
      case 0xb9:
      case 0xba:
      case 0xbb:
switchD_1001e71d_caseD_6d:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0xc + uVar3 * 0x10) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        iVar4 = *(int *)((int)this + 0x5c) + uVar3 * 0x10;
LAB_1001e535:
        iVar2 = uVar3 * 0x10;
        *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar4 + 0xc);
        *(undefined4 *)(*(int *)((int)this + 0x5c) + iVar2 + 4) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 8 + iVar2);
        *(undefined4 *)(iVar2 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(iVar2 + 4 + *(int *)((int)this + 0x5c));
        return;
      case 0xa5:
        *(float *)(*(int *)((int)this + 0x5c) + 0x75c) =
             *(float *)(*(int *)((int)this + 0x60) + uVar3 * 4) * *(float *)((int)this + 0x2c);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x75c);
        return;
      }
      break;
    case 1:
      switch(uVar3) {
      case 0x6d:
      case 0x6e:
      case 0x6f:
      case 0x70:
      case 0x71:
      case 0x72:
      case 0x86:
      case 0x87:
      case 0x89:
      case 0x8a:
      case 0x8d:
      case 0x8e:
      case 0x91:
      case 0x92:
      case 0x95:
      case 0x96:
      case 0x99:
      case 0x9a:
      case 0xa9:
      case 0xaa:
      case 0xad:
      case 0xae:
      case 0xb1:
      case 0xb2:
      case 0xb5:
      case 0xb6:
      case 0xb9:
      case 0xba:
        goto switchD_1001e361_caseD_6d;
      case 0x73:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x6d8) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x6d8);
        return;
      case 0x74:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x6e8) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x6e8);
        return;
      case 0x75:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x6f8) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x6f8);
        return;
      case 0x76:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x708) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x708);
        return;
      case 0x77:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x718) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x718);
        return;
      case 0x78:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x728) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x728);
        return;
      case 0x79:
        lVar5 = __ftol();
        *(int *)((int)this + 0x2cc) = (int)lVar5;
        return;
      default:
        break;
      case 0x7b:
      case 0x7c:
      case 0x7d:
      case 0xa3:
        goto switchD_1001db4f_caseD_49;
      case 0x7e:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x7b8) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x7b8);
        return;
      case 0x7f:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x7c8) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x7c8);
        return;
      case 0x80:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x7d8) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x7d8);
        return;
      case 0x82:
        *(float *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(float *)(*(int *)((int)this + 0x60) + uVar3 * 4) * _DAT_10049230;
        return;
      case 0x83:
        *(float *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(float *)(*(int *)((int)this + 0x60) + uVar3 * 4) * _DAT_10048ddc;
        return;
      case 0x84:
      case 0x85:
      case 0x9f:
      case 0xa2:
      case 0xa6:
        goto switchD_1001e71d_caseD_6d;
      case 0x9c:
        lVar5 = __ftol();
        *(int *)((int)this + 0x2d0) = (int)lVar5;
        return;
      case 0x9d:
        *(float *)(*(int *)((int)this + 0x5c) + 0x824) =
             *(float *)(*(int *)((int)this + 0x60) + uVar3 * 4) * _DAT_10049230;
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x824);
        return;
      case 0x9e:
        *(float *)(*(int *)((int)this + 0x5c) + 0x834) =
             *(float *)(*(int *)((int)this + 0x60) + uVar3 * 4) * _DAT_10048ddc;
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x834);
        return;
      case 0xa0:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x878) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x878);
        return;
      case 0xa1:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x868) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x868);
        return;
      case 0xa4:
      case 0xa5:
        iVar4 = uVar3 * 0x10;
        *(undefined4 *)(iVar4 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0xc + iVar4) = 0;
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 8 + iVar4) = 0;
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 4 + iVar4) = 0;
        return;
      case 0xa7:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0xa38) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0xa38);
        return;
      }
    case 2:
      switch(uVar3) {
      case 0x6d:
      case 0x6e:
      case 0x7b:
      case 0x7c:
      case 0x7e:
      case 0x7f:
      case 0x81:
      case 0x82:
      case 0x83:
      case 0x84:
      case 0x85:
      case 0x86:
      case 0x87:
      case 0x88:
      case 0x89:
      case 0x8a:
      case 0x8b:
      case 0x8c:
      case 0x8d:
      case 0x8e:
      case 0x8f:
      case 0x90:
      case 0x91:
      case 0x92:
      case 0x93:
      case 0x94:
      case 0x95:
      case 0x96:
      case 0x97:
      case 0x98:
      case 0x99:
      case 0x9a:
      case 0x9b:
      case 0x9c:
      case 0x9d:
      case 0x9e:
      case 0x9f:
      case 0xa0:
      case 0xa1:
      case 0xad:
      case 0xaf:
      case 0xb0:
      case 0xb1:
      case 0xb2:
      case 0xb3:
      case 0xb4:
      case 0xb5:
      case 0xb6:
      case 0xb7:
      case 0xb8:
      case 0xb9:
      case 0xba:
      case 0xbb:
        goto switchD_1001db4f_caseD_1b;
      case 0x6f:
      case 0x70:
      case 0x71:
      case 0x72:
      case 0x73:
      case 0x74:
      case 0x77:
      case 0x78:
      case 0x79:
      case 0xa2:
      case 0xa3:
      case 0xa4:
      case 0xa5:
      case 0xa6:
      case 0xa7:
      case 0xa8:
      case 0xa9:
      case 0xaa:
      case 0xab:
      case 0xac:
      case 0xbf:
        goto switchD_1001db4f_caseD_49;
      default:
        break;
      case 0x76:
      case 0x7a:
      case 0x7d:
      case 0x80:
        iVar4 = *(int *)((int)this + 0x60);
        *(float *)(*(int *)((int)this + 0x5c) + 0x76c) =
             *(float *)(iVar4 + 0x200) * *(float *)(iVar4 + 500) * *(float *)(iVar4 + 0x1e8) *
             *(float *)(iVar4 + 0x1d8);
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x768) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x76c);
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x764) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x768);
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x760) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x764);
        return;
      }
    case 3:
      switch(uVar3) {
      case 0x6d:
      case 0x6e:
      case 0x75:
      case 0x76:
      case 0x77:
      case 0x78:
      case 0x79:
      case 0x7a:
      case 0x7b:
      case 0x7c:
      case 0x7d:
      case 0x88:
      case 0x8f:
      case 0x90:
      case 0x91:
      case 0x92:
      case 0x93:
      case 0x94:
      case 0x95:
      case 0x9c:
      case 0x9d:
      case 0x9e:
      case 0x9f:
      case 0xa0:
      case 0xa1:
      case 0xa2:
      case 0xa3:
      case 0xa4:
      case 0xa5:
      case 0xa6:
      case 0xa7:
      case 0xa8:
      case 0xa9:
      case 0xaa:
      case 0xab:
      case 0xac:
      case 0xad:
      case 0xae:
      case 0xaf:
      case 0xb0:
      case 0xb1:
      case 0xb2:
      case 0xb3:
      case 0xb4:
      case 0xb5:
      case 0xb6:
      case 0xb7:
      case 0xb8:
      case 0xb9:
      case 0xba:
      case 0xbb:
        goto switchD_1001e71d_caseD_6d;
      case 0x6f:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x808) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x808);
        return;
      case 0x70:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x818) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x818);
        return;
      case 0x71:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x828) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x828);
        return;
      case 0x72:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x838) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x838);
        return;
      case 0x73:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x848) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x848);
        return;
      case 0x74:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x858) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x858);
        return;
      case 0x7e:
        lVar5 = __ftol();
        fVar1 = *(float *)((int)this + 0x28) * _DAT_1004922c;
        *(int *)((int)this + 0x2d4) = (int)lVar5;
        *(float *)(*(int *)((int)this + 0x5c) + 0xbf0) = fVar1;
        return;
      default:
        break;
      case 0x80:
      case 0x81:
      case 0x82:
      case 0x83:
      case 0x84:
      case 0x85:
        goto switchD_1001db4f_caseD_2d;
      case 0x86:
        *(float *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(float *)(*(int *)((int)this + 0x60) + uVar3 * 4) * _DAT_10048ddc;
        return;
      case 0x87:
        *(float *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(float *)(*(int *)((int)this + 0x60) + uVar3 * 4) * _DAT_10049230;
        return;
      case 0x89:
      case 0x8a:
      case 0x8b:
      case 0x8d:
      case 0xbf:
        goto switchD_1001db4f_caseD_49;
      case 0x96:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x898) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x898);
        return;
      case 0x97:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x8a8) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x8a8);
        return;
      case 0x98:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x8b8) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x8b8);
        return;
      case 0x9a:
        *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x8d8) =
             *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
        *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
             *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x8d8);
        return;
      }
    default:
      break;
    }
    break;
  case 0xb:
  case 0x57:
  case 0xbc:
    fVar1 = _DAT_100402b0;
    if (*(float *)(*(int *)((int)this + 0x60) + uVar3 * 4) != _DAT_100402b0) {
      fVar1 = _DAT_10048dd8 - *(float *)((int)this + 0x30);
    }
    iVar4 = uVar3 * 0x10;
    *(float *)(*(int *)((int)this + 0x5c) + 0xc + iVar4) = fVar1;
    *(float *)(*(int *)((int)this + 0x5c) + 8 + iVar4) = fVar1;
    *(float *)(*(int *)((int)this + 0x5c) + 4 + iVar4) = fVar1;
    *(float *)(iVar4 + *(int *)((int)this + 0x5c)) = fVar1;
    return;
  case 0xc:
  case 0x58:
  case 0xbd:
    iVar4 = uVar3 * 0x10;
    *(undefined4 *)(*(int *)((int)this + 0x5c) + 0xc + iVar4) = *(undefined4 *)((int)this + 0x30);
    *(undefined4 *)(*(int *)((int)this + 0x5c) + iVar4 + 8) =
         *(undefined4 *)(*(int *)((int)this + 0x5c) + 0xc + iVar4);
    *(undefined4 *)(*(int *)((int)this + 0x5c) + iVar4 + 4) =
         *(undefined4 *)(*(int *)((int)this + 0x5c) + 8 + iVar4);
    *(undefined4 *)(*(int *)((int)this + 0x5c) + iVar4) =
         *(undefined4 *)(*(int *)((int)this + 0x5c) + 4 + iVar4);
    return;
  case 0x16:
  case 0xbe:
    *(float *)(*(int *)((int)this + 0x5c) + 0xbec) =
         *(float *)(*(int *)((int)this + 0x60) + 0x2f8) *
         *(float *)(*(int *)((int)this + 0x60) + 0x58);
    *(undefined4 *)(*(int *)((int)this + 0x5c) + 0xbe8) =
         *(undefined4 *)(*(int *)((int)this + 0x5c) + 0xbec);
    *(undefined4 *)(*(int *)((int)this + 0x5c) + 0xbe4) =
         *(undefined4 *)(*(int *)((int)this + 0x5c) + 0xbe8);
    *(undefined4 *)(*(int *)((int)this + 0x5c) + 0xbe0) =
         *(undefined4 *)(*(int *)((int)this + 0x5c) + 0xbe4);
    return;
  case 0x1a:
    lVar5 = __ftol();
    *(int *)((int)this + 0x234) = (int)lVar5;
    return;
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x33:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
  case 0x67:
switchD_1001db4f_caseD_1b:
    iVar2 = uVar3 * 0x10;
    *(undefined4 *)(*(int *)((int)this + 0x5c) + 0xc + iVar2) =
         *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
    iVar4 = *(int *)((int)this + 0x5c) + iVar2;
    *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar4 + 0xc);
    *(undefined4 *)(*(int *)((int)this + 0x5c) + iVar2 + 4) =
         *(undefined4 *)(*(int *)((int)this + 0x5c) + 8 + iVar2);
    *(undefined4 *)(iVar2 + *(int *)((int)this + 0x5c)) =
         *(undefined4 *)(iVar2 + 4 + *(int *)((int)this + 0x5c));
    return;
  case 0x25:
    lVar5 = __ftol();
    *(int *)((int)this + 0x22c) = (int)lVar5;
    return;
  case 0x28:
    lVar5 = __ftol();
    *(int *)((int)this + 0x238) = (int)lVar5;
    return;
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
  case 0x32:
switchD_1001db4f_caseD_2d:
    *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
         *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
    return;
  case 0x34:
    lVar5 = __ftol();
    *(int *)((int)this + 0x230) = (int)lVar5;
    return;
  case 0x37:
    lVar5 = __ftol();
    *(int *)((int)this + 0x23c) = (int)lVar5;
    return;
  case 0x3c:
    *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x498) =
         *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
    *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
         *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x498);
    return;
  case 0x3d:
    *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x4a8) =
         *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
    *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
         *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x4a8);
    return;
  case 0x3e:
    *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x4b8) =
         *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
    *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
         *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x4b8);
    return;
  case 0x3f:
    *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x4c8) =
         *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
    *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
         *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x4c8);
    return;
  case 0x40:
    *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x4d8) =
         *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
    *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
         *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x4d8);
    return;
  case 0x41:
    *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x4e8) =
         *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
    *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
         *(undefined4 *)(*(int *)((int)this + 0x5c) + 0x4e8);
    return;
  case 0x49:
  case 0x4a:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
switchD_1001db4f_caseD_49:
    *(undefined4 *)(uVar3 * 0x10 + *(int *)((int)this + 0x5c)) =
         *(undefined4 *)(*(int *)((int)this + 0x60) + uVar3 * 4);
  }
  return;
}


