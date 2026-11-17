/* Ghidra analysis of supplied S-YXG50.dll at 1000c5e0 */

void FUN_1000c5e0(int *param_1,int param_2,char param_3)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0xdc);
  if (iVar2 == 0) {
    return;
  }
  do {
    if ((*(char *)(iVar2 + 7) != '\0') && (*(char *)(iVar2 + 0x7a) == param_3)) {
      cVar1 = *(char *)(iVar2 + 0x81);
      if (*(char *)(param_2 + 199) == '\0') {
        if (cVar1 != '\x03') {
          (**(code **)(*param_1 + 0x3b4))(param_1,iVar2);
          return;
        }
      }
      else if (((cVar1 != '\x03') && (*(char *)(iVar2 + 0x80) == '\0')) || (cVar1 == '\x01')) {
        (**(code **)(*param_1 + 0x3b8))(param_1,iVar2);
        return;
      }
    }
    iVar2 = *(int *)(iVar2 + 0x24);
    if (iVar2 == 0) {
      return;
    }
  } while( true );
}


