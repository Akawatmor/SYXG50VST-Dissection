/* VEG parameter conversion, VA 10004f50 */

void FUN_10004f50(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = param_1 + 0x69;
  do {
    (**(code **)(*param_1 + 0x5c))(param_1,8,iVar1,*piVar2);
    *piVar2 = 0;
    iVar1 = iVar1 + 0x20;
    piVar2 = piVar2 + 1;
  } while ((ushort)iVar1 < 0x80);
  return;
}


