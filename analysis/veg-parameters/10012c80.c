/* VEG parameter conversion, VA 10012c80 */

void FUN_10012c80(int *param_1,undefined1 *param_2)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  undefined4 unaff_retaddr;
  
  bVar1 = (**(code **)(*param_1 + 0x90))(param_1,*param_2);
  bVar2 = ~(bVar1 << 2) & 0xfc;
  uVar4 = (byte)~(bVar1 << 2) & 0xfc;
  bVar1 = bVar1 & 0xc0;
  param_2[0x74] = (char)((byte)param_2[0x73] * uVar4 * 2 >> 8);
  if ((char)bVar1 < '\0') {
    uVar3 = (ushort)(byte)param_2[0x71] << 1;
    if (0xc0 < uVar3) {
      uVar3 = 0xc0;
    }
    if ((ushort)uVar4 < uVar3) {
      bVar2 = 0;
    }
    else {
      bVar2 = bVar2 - (char)uVar3;
    }
    param_2[0x6d] = bVar2;
  }
  switch(param_2[1]) {
  case 1:
    if ((param_2[2] == '\x01') && (param_2[0x87] == '\0')) {
      bVar1 = 0x70;
    }
    else {
      bVar1 = ((bVar1 != 0xc0) - 1U & 0x60) + 0x20;
    }
    if (bVar1 <= bVar2) {
      return;
    }
    if (param_2[0x6c] != '\0') {
      return;
    }
  case 6:
    param_2[0x6d] = 0;
    param_2[0x8a] = 0;
    param_2[1] = 0;
    param_2[0x78] = param_2[0x78] & 0xfe;
    (**(code **)(*param_1 + 0x3c0))(param_1,param_2);
    break;
  case 3:
    if (bVar1 == 0xc0) {
      (**(code **)(*param_1 + 0x84))(param_1,unaff_retaddr,param_2[0x6a],param_2[0x6b]);
      param_2[1] = 4;
      return;
    }
    break;
  case 4:
    if ((param_2[2] == '\x01') && (param_2[0x87] == '\0')) {
      bVar1 = ((param_2[0x8a] == '\0') - 1U & 0xf0) + 0x80;
    }
    else {
      bVar1 = 0x20;
    }
    if ((bVar2 < bVar1) && (param_2[0x6c] == '\0')) {
      param_2[1] = 0;
      param_2[0x8a] = 0;
      param_2[0x6d] = 0;
      param_2[0x78] = param_2[0x78] & 0xfe;
      (**(code **)(*param_1 + 0x3c0))(param_1,param_2);
      return;
    }
    break;
  case 5:
    if (bVar1 == 0xc0) {
      (**(code **)(*param_1 + 0x84))(param_1,unaff_retaddr,param_2[0x6a],param_2[0x6b]);
      param_2[1] = 4;
      return;
    }
  }
  return;
}


