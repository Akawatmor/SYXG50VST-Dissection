/* Ghidra analysis of supplied S-YXG50.dll at 1000b770 */

void FUN_1000b770(int *param_1,int param_2,undefined4 param_3,byte param_4)

{
  byte bStack_28;
  byte bStack_27;
  byte bStack_26;
  undefined1 uStack_18;
  
  if (param_4 == 0) {
    (**(code **)(*param_1 + 0x378))(param_1,param_2,param_3,0);
  }
  else if ((((*(char *)(param_2 + 0x2e) != '\0') && (*(byte *)(param_2 + 0xf) <= (byte)param_3)) &&
           ((byte)param_3 <= *(byte *)(param_2 + 0x10))) &&
          ((*(byte *)(param_2 + 0x66) <= param_4 && (param_4 <= *(byte *)(param_2 + 0x67))))) {
    bStack_28 = (byte)param_3;
    bStack_27 = (byte)param_3;
    bStack_26 = param_4;
    uStack_18 = 0;
    if (*(char *)(param_2 + 7) != '\0') {
      (**(code **)(*param_1 + 0x350))(param_1,param_2,&bStack_28);
      return;
    }
    if (*(char *)(param_2 + 5) == '\x01') {
      (**(code **)(*param_1 + 0x3ac))();
      return;
    }
    (**(code **)(*param_1 + 0x388))(param_1);
    return;
  }
  return;
}


