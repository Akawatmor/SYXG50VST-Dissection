/* Ghidra analysis of supplied S-YXG50.dll at 10017130 */

uint FUN_10017130(void)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  bVar1 = FUN_100170b0();
  if (CONCAT31(extraout_var,bVar1) != 0) {
    iVar2 = FUN_100170e0(1,&local_4,&local_8,&local_c,&local_10);
    if (iVar2 != 0) {
      return local_10 >> 0x17 & 1;
    }
  }
  return 0;
}


