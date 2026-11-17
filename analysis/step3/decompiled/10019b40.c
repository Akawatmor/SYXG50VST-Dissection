/* Ghidra analysis of supplied S-YXG50.dll at 10019b40 */

void __fastcall FUN_10019b40(int param_1)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  float10 fVar4;
  int iVar5;
  int iVar6;
  
  if ((*(uint *)(param_1 + 4) & 0x100) == 0) {
    iVar6 = *(int *)(param_1 + 0xa8);
    iVar5 = *(int *)(param_1 + 0xa4);
    piVar3 = (int *)(param_1 + 0xa0);
  }
  else {
    iVar6 = *(int *)(param_1 + 0xa8);
    iVar5 = 0;
    piVar3 = (int *)(param_1 + 0xac);
  }
  cVar1 = FUN_10019540(piVar3,iVar5,iVar6);
  if (cVar1 == '\0') {
    uVar2 = *(uint *)(param_1 + 4) | 0x200;
  }
  else {
    uVar2 = *(uint *)(param_1 + 4) & 0xfffffdff;
  }
  *(uint *)(param_1 + 4) = uVar2;
  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0xb8);
  fVar4 = FUN_10019bc0(*(int *)(param_1 + 0xa0) -
                       (*(int *)(param_1 + 0x60) * *(int *)(param_1 + 0x44) >>
                       ((byte)*(undefined4 *)(param_1 + 0x54) & 0x1f)));
  *(float *)(param_1 + 0xb8) = (float)fVar4;
  return;
}


