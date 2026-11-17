/* Ghidra analysis of supplied S-YXG50.dll at 10014610 */

void FUN_10014610(int *param_1,int param_2)

{
  short sVar1;
  ushort uVar2;
  byte bVar3;
  
  if (*(char *)(param_2 + 0xb) == '\0') {
    if (*(char *)(param_2 + 0x5d) == '\0') {
      bVar3 = *(char *)(param_2 + 0x60) + *(char *)(param_2 + 0x5f);
      *(byte *)(param_2 + 0x60) = bVar3;
      *(undefined1 *)(param_2 + 0xb) = 1;
      if (*(byte *)(param_2 + 0x5e) <= bVar3) {
        *(byte *)(param_2 + 0x60) = *(byte *)(param_2 + 0x5e);
        *(undefined1 *)(param_2 + 0xb) = 2;
      }
      *(ushort *)(param_2 + 0xc) = *(ushort *)(param_2 + 0xc) | 1;
    }
    else {
      *(char *)(param_2 + 0x5d) = *(char *)(param_2 + 0x5d) + -1;
    }
  }
  else if (*(char *)(param_2 + 0xb) == '\x01') {
    bVar3 = *(char *)(param_2 + 0x60) + *(char *)(param_2 + 0x5f);
    *(byte *)(param_2 + 0x60) = bVar3;
    if (*(byte *)(param_2 + 0x5e) <= bVar3) {
      *(byte *)(param_2 + 0x60) = *(byte *)(param_2 + 0x5e);
      *(undefined1 *)(param_2 + 0xb) = 2;
    }
    *(byte *)(param_2 + 0xc) = *(byte *)(param_2 + 0xc) | 1;
  }
  if (*(byte *)(param_2 + 10) != 0) {
    uVar2 = *(byte *)(param_2 + 10) - 1;
    if (uVar2 == 0) {
      sVar1 = (**(code **)(*param_1 + 0x570))(param_1);
      *(short *)(param_2 + 0x12) =
           (short)((ushort)*(byte *)(*(int *)(param_2 + 0x28) + 10) * (sVar1 >> 1)) >> 2;
      uVar2 = (ushort)(byte)(0x40 - *(char *)(*(int *)(param_2 + 0x28) + 7));
      *(byte *)(param_2 + 0xc) = *(byte *)(param_2 + 0xc) | 4;
    }
    *(char *)(param_2 + 10) = (char)uVar2;
  }
  return;
}


