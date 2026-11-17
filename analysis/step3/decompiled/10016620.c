/* Ghidra analysis of supplied S-YXG50.dll at 10016620 */

void FUN_10016620(int *param_1,int param_2)

{
  char *pcVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  char cVar5;
  int iVar6;
  ushort uVar7;
  ushort uVar8;
  uint local_4;
  
  piVar4 = param_1;
  iVar3 = *(int *)(param_2 + 0x20);
  if (*(char *)((int)param_1 + 0x69dd) != '\0') {
    uVar7 = (ushort)*(byte *)(iVar3 + 0x13);
    uVar8 = (ushort)*(byte *)(iVar3 + 0x12);
    local_4 = (uint)*(byte *)(iVar3 + 0x11);
    pcVar1 = (char *)((int)param_1 + 0x63b6);
    param_1 = (int *)(uint)*(byte *)(iVar3 + 0x14);
    if (*pcVar1 == '\x01') {
      (**(code **)(*piVar4 + 0x314))(piVar4,0x41);
      (**(code **)(*piVar4 + 0x314))(piVar4,0x42);
      (**(code **)(*piVar4 + 0x314))(piVar4,0x40);
      *(undefined1 *)((int)piVar4 + 0x63b6) = 0;
    }
    goto LAB_1001679f;
  }
  if (*(char *)(iVar3 + 0xd8) != *(char *)((int)param_1 + 0x69de)) {
    uVar7 = (ushort)*(byte *)(iVar3 + 0x13);
    uVar8 = (ushort)*(byte *)(iVar3 + 0x12);
    local_4 = 0x7f;
    param_1 = (int *)0x0;
    goto LAB_1001679f;
  }
  if (*(char *)(param_2 + 2) == '\0') {
LAB_10016693:
    uVar8 = 0;
    local_4 = 0;
    uVar7 = 0;
    param_1 = (int *)0x7f;
  }
  else {
    if ((*(char *)((int)param_1 + 0x63ae) == '\x01') && (*(char *)(iVar3 + 7) == '\x01')) {
      iVar6 = *(int *)(param_2 + 0x30);
    }
    else {
      iVar6 = *(int *)(param_2 + 0x2c);
    }
    if (*(char *)(iVar6 + 7) != '\0') goto LAB_10016693;
    uVar7 = (ushort)*(byte *)(iVar3 + 0x13);
    uVar8 = (ushort)*(byte *)(iVar3 + 0x12);
    local_4 = (uint)*(byte *)(iVar3 + 0x11);
    param_1 = (int *)0x0;
  }
  if ((char)piVar4[0x1a65] != *(char *)(iVar3 + 0x13)) {
    *(char *)(piVar4 + 0x1a65) = *(char *)(iVar3 + 0x13);
    (**(code **)(*piVar4 + 0x318))
              (piVar4,*(undefined1 *)(iVar3 + 0xb),*(undefined1 *)(iVar3 + 0x6c));
  }
  if (*(char *)((int)piVar4 + 0x6995) != *(char *)(iVar3 + 0x12)) {
    *(char *)((int)piVar4 + 0x6995) = *(char *)(iVar3 + 0x12);
    (**(code **)(*piVar4 + 0x318))
              (piVar4,*(undefined1 *)(iVar3 + 0xb),*(undefined1 *)(iVar3 + 0x6c));
  }
  cVar5 = *(char *)(iVar3 + 0xe);
  if (cVar5 == '\0') {
    cVar5 = '@';
  }
  if (*(char *)((int)piVar4 + 0x6996) != cVar5) {
    *(char *)((int)piVar4 + 0x6996) = cVar5;
    (**(code **)(*piVar4 + 0x318))
              (piVar4,*(undefined1 *)(iVar3 + 0xb),*(undefined1 *)(iVar3 + 0x6c));
  }
  *(undefined1 *)((int)piVar4 + 0x63b6) = 1;
LAB_1001679f:
  if (*(char *)(param_2 + 2) != '\0') {
    if ((*(char *)((int)piVar4 + 0x63ae) == '\x01') && (*(char *)(iVar3 + 7) == '\x01')) {
      iVar6 = *(int *)(param_2 + 0x30);
    }
    else {
      iVar6 = *(int *)(param_2 + 0x2c);
    }
    uVar7 = (ushort)(*(byte *)(iVar6 + 5) * uVar7) >> 7;
    uVar8 = (ushort)(*(byte *)(iVar6 + 6) * uVar8) >> 7;
    if ((*(char *)((int)piVar4 + 0x69dd) != '\0') ||
       (*(char *)(iVar3 + 0xd8) != *(char *)((int)piVar4 + 0x69de))) {
      param_1 = (int *)(uint)((ushort)((ushort)*(byte *)(iVar6 + 7) * (short)param_1) >> 7);
    }
  }
  *(undefined *)((int)piVar4 + 0x1bf) = (&DAT_10041e90)[local_4];
  bVar2 = (&DAT_10048bc0)[*(byte *)(param_2 + 0x77)];
  *(undefined *)((int)piVar4 + 0x1be) = (&DAT_10048b40)[uVar7];
  uVar7 = (ushort)(byte)(&DAT_10048b40)[uVar8];
  if ((*(char *)((int)piVar4 + 0x66dd) == '\0') && (uVar7 = uVar7 + bVar2, 0xff < uVar7)) {
    uVar7 = 0xff;
  }
  *(char *)(piVar4 + 0x70) = (char)uVar7;
  uVar7 = (ushort)*(byte *)(param_1 + 0x40122d0);
  if (((*(char *)((int)piVar4 + 0x69dd) == '\x01') && ((char)piVar4[0x19b7] == '\0')) &&
     (uVar7 = uVar7 + bVar2, 0xff < uVar7)) {
    uVar7 = 0xff;
  }
  *(char *)((int)piVar4 + 0x1c1) = (char)uVar7;
  return;
}


