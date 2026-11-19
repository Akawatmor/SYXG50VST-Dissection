/* VEG parameter conversion, VA 10012a60 */

void FUN_10012a60(int param_1)

{
  undefined1 uVar1;
  
  if (*(char *)(param_1 + 2) != '\x01') {
    uVar1 = FUN_10012670(param_1,*(undefined1 *)(*(int *)(param_1 + 0x28) + 0x48));
    *(undefined1 *)(param_1 + 0x69) = uVar1;
    *(undefined1 *)(param_1 + 0x66) = uVar1;
  }
  return;
}


