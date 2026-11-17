/* Ghidra analysis of supplied S-YXG50.dll at 100146d0 */

void FUN_100146d0(int *param_1,undefined1 *param_2)

{
  byte bVar1;
  undefined1 uVar2;
  bool bVar3;
  undefined2 uVar4;
  
  if ((param_2[4] == '\0') || (*(short *)(param_2 + 0x16) == *(short *)(param_2 + 0x14))) {
    bVar3 = false;
  }
  else {
    FUN_10014d80((int)param_2);
    bVar3 = true;
  }
  if ((param_2[5] != '\x03') && (param_2[5] != '\x05')) {
    FUN_10015ac0((int)param_2);
    bVar3 = true;
  }
  if ((param_2[8] != '\x03') && (param_2[8] != '\x05')) {
    FUN_10013b60((int)param_2);
    bVar3 = true;
  }
  bVar1 = param_2[0xc];
  if ((bVar1 & 7) == 0) {
    *(undefined1 *)(param_1 + 0x6d) = param_2[9];
  }
  else {
    (**(code **)(*param_1 + 0x4dc))(param_1,param_2,*(undefined4 *)(param_2 + 0x28));
  }
  if ((bVar1 & 7) != 0 || bVar3) {
    *(ushort *)(param_2 + 0xc) = *(ushort *)(param_2 + 0xc) & 0x39;
    uVar4 = (**(code **)(*param_1 + 0x5a0))(param_1,param_2);
    *(undefined2 *)(param_1 + 0x71) = uVar4;
    (**(code **)(*param_1 + 0x4d0))
              (param_1,param_2,*(short *)(param_2 + 0x1a) + *(short *)(param_2 + 0x18));
    uVar2 = *param_2;
    (**(code **)(*param_1 + 0x88))(param_1,uVar2,(short)param_1[0x71]);
    (**(code **)(*param_1 + 0x8c))(param_1,uVar2);
  }
  return;
}


