/* Ghidra analysis of supplied S-YXG50.dll at 10018c60 */

int __fastcall FUN_10018c60(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0xc);
  iVar2 = 0;
  iVar4 = 0x100;
  do {
    iVar1 = FUN_10019520(iVar3);
    if ((char)iVar1 != '\0') {
      iVar2 = iVar2 + 1;
    }
    iVar3 = iVar3 + 0x170;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return iVar2;
}


