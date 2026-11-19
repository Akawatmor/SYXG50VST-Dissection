/* VEG parameter conversion, VA 100129a0 */

void FUN_100129a0(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  
  if (*(char *)(param_2 + 2) == '\x01') {
    if (*(char *)(param_1 + 0x63ae) == '\x01') {
      uVar2 = (*(byte *)(*(int *)(param_2 + 0x30) + 0xd) - 0x40) +
              (ushort)*(byte *)(*(int *)(param_2 + 0x2c) + 0xd);
      if ((short)uVar2 < 0) {
        uVar2 = 0;
      }
      else if (0x7f < (short)uVar2) {
        uVar2 = 0x7f;
      }
    }
    else {
      uVar2 = (ushort)*(byte *)(*(int *)(param_2 + 0x2c) + 0xd);
    }
    bVar1 = FUN_100124f0(*(undefined4 *)(param_2 + 0x20),(int)(short)uVar2 / 2);
    if (bVar1 < 0x20) {
      bVar1 = 0x20;
      goto LAB_10012a49;
    }
  }
  else if ((*(char *)(param_2 + 4) == '\0') || (*(char *)(param_2 + 0x85) != '\0')) {
    bVar1 = FUN_10012550(*(undefined4 *)(param_2 + 0x20),
                         *(undefined1 *)(*(int *)(param_2 + 0x28) + 0x45));
  }
  else {
    bVar1 = *(byte *)(param_2 + 0x67);
  }
  if (0x7c < bVar1) {
    *(undefined1 *)(param_2 + 0x67) = 0x7c;
    return;
  }
LAB_10012a49:
  *(byte *)(param_2 + 0x67) = bVar1;
  return;
}


