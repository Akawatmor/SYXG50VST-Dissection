/* VEG parameter conversion, VA 10012190 */

void FUN_10012190(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  
  if ((*(char *)(param_2 + 4) == '\0') || (*(char *)(param_2 + 0x85) != '\0')) {
    uVar1 = FUN_10012550(*(undefined4 *)(param_2 + 0x20),*(undefined1 *)(param_3 + 0x45));
    *(undefined1 *)(param_1 + 0x1c7) = uVar1;
    uVar1 = FUN_100125b0(param_2,*(undefined1 *)(param_3 + 0x46));
    *(undefined1 *)(param_1 + 0x1ca) = uVar1;
    uVar1 = FUN_10012600(param_2,*(undefined1 *)(param_3 + 0x47));
    *(undefined1 *)(param_2 + 100) = uVar1;
    *(undefined1 *)(param_2 + 0x6a) = uVar1;
  }
  uVar1 = FUN_10012670(param_2,*(undefined1 *)(param_3 + 0x48));
  *(undefined1 *)(param_2 + 0x69) = uVar1;
  *(undefined1 *)(param_2 + 0x66) = uVar1;
  *(undefined1 *)(param_2 + 0x67) = *(undefined1 *)(param_1 + 0x1c7);
  return;
}


