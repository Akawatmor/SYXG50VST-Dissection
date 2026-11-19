/* VEG parameter conversion, VA 10012310 */

void FUN_10012310(int param_1,int param_2)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  undefined1 uVar4;
  ushort uVar5;
  undefined2 uVar8;
  int iVar6;
  uint uVar7;
  undefined2 extraout_var;
  int iVar9;
  undefined4 unaff_EBX;
  
  if (*(char *)(param_1 + 0x63ae) == '\x01') {
    cVar1 = *(char *)(*(int *)(param_2 + 0x30) + 0xd);
    uVar7 = CONCAT22((short)((uint)*(int *)(param_2 + 0x2c) >> 0x10),
                     (short)*(char *)(*(int *)(param_2 + 0x2c) + 0xd)) + -0x40 +
            CONCAT22((short)((uint)unaff_EBX >> 0x10),(short)cVar1);
    if (((short)uVar7 < 0x5e) ||
       (uVar7 = CONCAT31((int3)(uVar7 >> 8),cVar1) & 0xffff00ff, 0x5d < (ushort)uVar7)) {
      if ((short)uVar7 < 0x80) {
        if ((short)uVar7 < 0) {
          uVar7 = 0;
        }
      }
      else {
        uVar7 = 0x7f;
      }
    }
    else {
      uVar7 = 0x5e;
    }
    bVar3 = FUN_100124f0(*(undefined4 *)(param_2 + 0x20),(int)uVar7 >> 1);
    *(byte *)(param_1 + 0x1c7) = bVar3;
    if (bVar3 < 0x20) {
      *(undefined1 *)(param_1 + 0x1c7) = 0x20;
    }
    bVar3 = *(byte *)(param_1 + 0x1c7);
    if (bVar3 < 0x80) {
      if (bVar3 == 0x7f) {
        *(undefined1 *)(param_1 + 0x1c7) = 0xff;
      }
      iVar9 = CONCAT22(extraout_var,(short)*(char *)(*(int *)(param_2 + 0x30) + 0xe));
      iVar6 = iVar9 + -0x40 + (uint)(ushort)(short)*(char *)(*(int *)(param_2 + 0x2c) + 0xe);
    }
    else {
      *(byte *)(param_1 + 0x1c7) = '~' - bVar3;
      cVar1 = *(char *)(*(int *)(param_2 + 0x30) + 0xf);
      iVar9 = *(int *)(param_2 + 0x2c);
      cVar2 = *(char *)(iVar9 + 0xf);
      *(undefined1 *)(param_1 + 0x1c9) = 0xff;
      *(undefined1 *)(param_2 + 1) = 4;
      iVar6 = ((ushort)(short)cVar1 - 0x40) + (uint)(ushort)(short)cVar2;
    }
    if ((short)iVar6 < 0x80) {
      if ((short)iVar6 < 0) {
        iVar6 = 0;
      }
    }
    else {
      iVar6 = 0x7f;
    }
    *(char *)(param_1 + 0x1ca) = (char)iVar6;
    iVar6 = CONCAT22((short)((uint)iVar9 >> 0x10),(short)*(char *)(*(int *)(param_2 + 0x30) + 0xf))
            + -0x40 + CONCAT22((short)((uint)*(int *)(param_2 + 0x30) >> 0x10),
                               (short)*(char *)(*(int *)(param_2 + 0x2c) + 0xf));
    if ((short)iVar6 < 0x80) {
      if ((short)iVar6 < 0) {
        iVar6 = 0;
      }
    }
    else {
      iVar6 = 0x7f;
    }
    uVar7 = iVar6 >> 1;
  }
  else {
    uVar8 = (undefined2)((uint)*(int *)(param_2 + 0x2c) >> 0x10);
    uVar5 = (ushort)*(byte *)(*(int *)(param_2 + 0x2c) + 0xd);
    iVar6 = CONCAT22(uVar8,uVar5);
    if ((0x5e < uVar5) &&
       (uVar5 = (ushort)*(byte *)(*(int *)(param_2 + 0x30) + 0xd), iVar6 = CONCAT22(uVar8,uVar5),
       uVar5 < 0x5e)) {
      iVar6 = 0x5e;
    }
    bVar3 = FUN_100124f0(*(undefined4 *)(param_2 + 0x20),iVar6 >> 1);
    *(byte *)(param_1 + 0x1c7) = bVar3;
    if (bVar3 < 0x20) {
      *(undefined1 *)(param_1 + 0x1c7) = 0x20;
    }
    bVar3 = *(byte *)(param_1 + 0x1c7);
    if (bVar3 < 0x80) {
      if (bVar3 == 0x7f) {
        *(undefined1 *)(param_1 + 0x1c7) = 0xff;
      }
      *(undefined1 *)(param_1 + 0x1ca) = *(undefined1 *)(*(int *)(param_2 + 0x2c) + 0xe);
      uVar7 = (uint)(*(byte *)(*(int *)(param_2 + 0x2c) + 0xf) >> 1);
    }
    else {
      *(byte *)(param_1 + 0x1c7) = '~' - bVar3;
      *(undefined1 *)(param_1 + 0x1ca) = *(undefined1 *)(*(int *)(param_2 + 0x2c) + 0xf);
      *(undefined1 *)(param_1 + 0x1c9) = 0xff;
      *(undefined1 *)(param_2 + 1) = 4;
      uVar7 = (uint)(*(byte *)(*(int *)(param_2 + 0x2c) + 0xf) >> 1);
    }
  }
  uVar4 = FUN_10012600(param_2,uVar7);
  *(undefined1 *)(param_2 + 100) = uVar4;
  *(undefined1 *)(param_2 + 0x6a) = uVar4;
  *(undefined1 *)(param_2 + 0x69) = 0x50;
  *(undefined1 *)(param_2 + 0x66) = 0x50;
  *(undefined1 *)(param_2 + 0x67) = *(undefined1 *)(param_1 + 0x1c7);
  return;
}


