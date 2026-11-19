/* VEG parameter conversion, VA 10012210 */

void FUN_10012210(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  ushort uVar2;
  
  uVar2 = (ushort)*(byte *)(param_3 + 0x45);
  if (*(char *)(param_1 + 0x63ae) == '\x01') {
    uVar2 = (uVar2 - 0x40) + (short)*(char *)(*(int *)(param_2 + 0x2c) + 0xd);
    if ((short)uVar2 < 0x80) {
      if ((short)uVar2 < 0) {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0x7f;
    }
  }
  uVar1 = FUN_10012550(*(undefined4 *)(param_2 + 0x20),uVar2);
  *(undefined1 *)(param_1 + 0x1c7) = uVar1;
  uVar2 = (ushort)*(byte *)(param_3 + 0x46);
  if (*(char *)(param_1 + 0x63ae) == '\x01') {
    uVar2 = (uVar2 - 0x40) + (short)*(char *)(*(int *)(param_2 + 0x2c) + 0xe);
    if ((short)uVar2 < 0x80) {
      if ((short)uVar2 < 0) {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0x7f;
    }
  }
  uVar1 = FUN_100125b0(param_2,uVar2);
  *(undefined1 *)(param_1 + 0x1ca) = uVar1;
  uVar2 = (ushort)*(byte *)(param_3 + 0x47);
  if (*(char *)(param_1 + 0x63ae) == '\x01') {
    uVar2 = (uVar2 - 0x40) + (short)*(char *)(*(int *)(param_2 + 0x2c) + 0xf);
    if ((short)uVar2 < 0x80) {
      if ((short)uVar2 < 0) {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0x7f;
    }
  }
  uVar1 = FUN_10012600(param_2,uVar2);
  *(undefined1 *)(param_2 + 100) = uVar1;
  *(undefined1 *)(param_2 + 0x6a) = uVar1;
  uVar1 = FUN_10012670(param_2,*(undefined1 *)(param_3 + 0x48));
  *(undefined1 *)(param_2 + 0x69) = uVar1;
  *(undefined1 *)(param_2 + 0x66) = uVar1;
  *(undefined1 *)(param_2 + 0x67) = *(undefined1 *)(param_1 + 0x1c7);
  return;
}


