/* Ghidra analysis of supplied S-YXG50.dll at 100144a0 */

void FUN_100144a0(int *param_1)

{
  int *piVar1;
  int *piVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  
  piVar2 = param_1;
  param_1 = (int *)0x10;
  do {
    bVar3 = FUN_10014480(*(char *)((int)piVar2 + 0x6a13));
    *(byte *)((int)piVar2 + 0x6a13) = bVar3;
    iVar5 = 0;
    iVar4 = 4;
    do {
      piVar1 = piVar2 + ((uint)*(byte *)((int)piVar2 + 0x6a13) + iVar5) * 0x23 + 0x4e8;
      if ((*(char *)((int)piVar1 + 1) != '\0') && (*(char *)((int)piVar1 + 2) != '\x01')) {
        (**(code **)(*piVar2 + 0x540))(piVar2,piVar1);
      }
      iVar5 = iVar5 + 0x20;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    bVar3 = FUN_10014480((char)piVar2[0x1a85]);
    *(byte *)(piVar2 + 0x1a85) = bVar3;
    iVar5 = 0;
    iVar4 = 4;
    do {
      piVar1 = piVar2 + ((uint)*(byte *)(piVar2 + 0x1a85) + iVar5) * 0x23 + 0x4e8;
      if ((*(char *)((int)piVar1 + 1) != '\0') && (*(char *)((int)piVar1 + 2) != '\x01')) {
        (**(code **)(*piVar2 + 0x544))(piVar2,piVar1);
      }
      iVar5 = iVar5 + 0x20;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    bVar3 = FUN_10014480((char)piVar2[0x1a85]);
    *(byte *)(piVar2 + 0x1a85) = bVar3;
    iVar5 = 0;
    iVar4 = 4;
    do {
      piVar1 = piVar2 + ((uint)*(byte *)(piVar2 + 0x1a85) + iVar5) * 0x23 + 0x4e8;
      if ((*(char *)((int)piVar1 + 1) != '\0') && (*(char *)((int)piVar1 + 2) != '\x01')) {
        (**(code **)(*piVar2 + 0x544))(piVar2,piVar1);
      }
      iVar5 = iVar5 + 0x20;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    bVar3 = *(char *)((int)piVar2 + 0x6a16) + 1;
    *(byte *)((int)piVar2 + 0x6a16) = bVar3;
    if ((bVar3 & 1) != 0) {
      bVar3 = FUN_10014480(*(char *)((int)piVar2 + 0x6a15));
      *(byte *)((int)piVar2 + 0x6a15) = bVar3;
      iVar5 = 0;
      iVar4 = 4;
      do {
        (**(code **)(*piVar2 + 0x548))
                  (piVar2,piVar2 + ((uint)*(byte *)((int)piVar2 + 0x6a15) + iVar5) * 0x23 + 0x4e8);
        iVar5 = iVar5 + 0x20;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    param_1 = (int *)((int)param_1 + -1);
  } while (param_1 != (int *)0x0);
  return;
}


