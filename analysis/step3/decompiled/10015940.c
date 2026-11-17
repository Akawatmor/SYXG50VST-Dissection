/* Ghidra analysis of supplied S-YXG50.dll at 10015940 */

void FUN_10015940(int *param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  undefined1 uVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  
  uVar4 = 0x40;
  if ((*(char *)(param_2 + 2) == '\0') ||
     (bVar1 = *(byte *)(*(int *)(param_2 + 0x2c) + 4), uVar4 = (ushort)bVar1, bVar1 != 0)) {
    *(undefined1 *)(param_2 + 0x75) = 0;
    if (*(char *)(*(int *)(param_2 + 0x20) + 0xe) != '\0') {
      if (*(byte *)(param_3 + 0x41) == 0xf) {
        bVar1 = (&DAT_100480b0)[*(byte *)(param_4 + 1)];
      }
      else {
        bVar1 = (&DAT_100480a0)[(short)(ushort)*(byte *)(param_3 + 0x41)];
      }
      *(byte *)(param_2 + 0x77) = bVar1;
      sVar3 = (uVar4 - 0x40) + (ushort)bVar1;
      if (sVar3 < 0x80) {
        if (sVar3 < 0) {
          sVar3 = 0;
        }
      }
      else {
        sVar3 = 0x7f;
      }
      *(char *)(param_2 + 0x76) = (char)sVar3;
      uVar2 = (**(code **)(*param_1 + 0x4e4))(param_1,param_2);
      *(undefined1 *)(param_2 + 0x4c) = uVar2;
      *(undefined1 *)(param_1 + 0x77) = uVar2;
      return;
    }
  }
  else {
    *(undefined1 *)(param_2 + 0x75) = 1;
  }
  bVar1 = (**(code **)(*param_1 + 0x570))(param_1);
  iVar5 = (int)(short)(ushort)(bVar1 >> 1);
  *(byte *)(param_2 + 0x77) = bVar1 >> 1;
  bVar1 = (&DAT_100474d0)[iVar5] << 4 | (&DAT_1004754f)[-iVar5];
  *(byte *)(param_2 + 0x4c) = bVar1;
  *(byte *)(param_1 + 0x77) = bVar1;
  return;
}


