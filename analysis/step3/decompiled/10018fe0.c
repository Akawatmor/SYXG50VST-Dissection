/* Ghidra analysis of supplied S-YXG50.dll at 10018fe0 */

void __fastcall FUN_10018fe0(int param_1)

{
  char cVar1;
  float10 fVar2;
  
  *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_1 + 0xe4);
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x2000;
  switch(*(undefined4 *)(param_1 + 0xc4)) {
  case 0:
    cVar1 = FUN_10019540((int *)(param_1 + 200),0,*(int *)(param_1 + 0xd4));
    if (cVar1 != '\0') {
      *(undefined4 *)(param_1 + 0xc4) = 3;
    }
    goto LAB_1001910b;
  case 1:
    cVar1 = FUN_10019540((int *)(param_1 + 0xdc),0,*(int *)(param_1 + 0xd4));
    if (cVar1 != '\0') {
      *(undefined4 *)(param_1 + 0xc4) = 3;
    }
    *(undefined4 *)(param_1 + 0xe4) = 0x3f800000;
    goto switchD_1001900b_default;
  case 2:
    cVar1 = FUN_10019540((int *)(param_1 + 200),*(int *)(param_1 + 0xcc),*(int *)(param_1 + 0xd4));
    if (cVar1 != '\0') {
      *(undefined4 *)(param_1 + 0xc4) = 3;
    }
    fVar2 = FUN_10019580(*(uint *)(param_1 + 200));
    break;
  case 3:
    cVar1 = FUN_10019540((int *)(param_1 + 200),*(int *)(param_1 + 0xd0),*(int *)(param_1 + 0xd8));
    if (cVar1 != '\0') {
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffffdfff;
    }
    fVar2 = FUN_10019580(*(uint *)(param_1 + 200));
    break;
  case 4:
    cVar1 = FUN_10019540((int *)(param_1 + 200),*(int *)(param_1 + 0xd0),*(int *)(param_1 + 0xd8));
    if (cVar1 != '\0') {
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffffdfff;
    }
LAB_1001910b:
    fVar2 = (float10)*(float *)(param_1 + 0xec) -
            (float10)*(int *)(param_1 + 200) * (float10)*(float *)(param_1 + 0xe8);
    break;
  default:
    goto switchD_1001900b_default;
  }
  *(float *)(param_1 + 0xe4) = (float)fVar2;
switchD_1001900b_default:
  if (((1 < *(int *)(param_1 + 0xc4)) && (*(int *)(param_1 + 0xc4) < 5)) &&
     (fVar2 = FUN_10019580(0x80000), (float10)*(float *)(param_1 + 0xe4) <= fVar2)) {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffffdfff | 0x1000;
    *(undefined4 *)(param_1 + 0xd0) = 0xfffff;
    *(undefined4 *)(param_1 + 0xcc) = 0xfffff;
    *(undefined4 *)(param_1 + 200) = 0xfffff;
    *(undefined4 *)(param_1 + 0xe4) = 0;
  }
  return;
}


