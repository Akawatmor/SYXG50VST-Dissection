/* Ghidra analysis of supplied S-YXG50.dll at 100164f0 */

int __cdecl FUN_100164f0(byte *param_1,byte param_2)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte bVar6;
  byte bVar5;
  
  if (param_2 <= *param_1) {
    return param_1[4] - 0x40;
  }
  bVar5 = param_1[3];
  if (bVar5 <= param_2) {
    return param_1[7] - 0x40;
  }
  bVar6 = param_1[2];
  if (bVar6 == param_2) {
    return param_1[6] - 0x40;
  }
  if (param_2 < bVar6) {
    bVar5 = param_1[1];
    if (bVar5 == param_2) {
      return param_1[5] - 0x40;
    }
    if (bVar5 <= param_2) {
      bVar1 = param_1[5];
      bVar3 = param_1[6];
      bVar4 = bVar6 - bVar5;
      goto LAB_10016585;
    }
    bVar6 = *param_1;
    bVar1 = param_1[4];
    bVar3 = param_1[5];
  }
  else {
    bVar1 = param_1[6];
    bVar3 = param_1[7];
  }
  bVar4 = bVar5 - bVar6;
  bVar5 = bVar6;
LAB_10016585:
  iVar2 = FUN_100165b0(param_2 - bVar5,bVar3 - bVar1,bVar4,bVar1);
  return iVar2;
}


