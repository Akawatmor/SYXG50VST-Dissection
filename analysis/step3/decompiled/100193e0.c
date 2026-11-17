/* Ghidra analysis of supplied S-YXG50.dll at 100193e0 */

uint __fastcall FUN_100193e0(undefined4 *param_1)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = 0;
  switch(*param_1) {
  case 0:
    uVar1 = (int)param_1[0x28] >> 0xe & 0x3f;
    bVar2 = (param_1[1] & 0x200) == 0;
    break;
  default:
    goto switchD_100193f3_caseD_1;
  case 0x40:
    uVar1 = FUN_10018e20((int)param_1);
    return uVar1;
  case 0x60:
    uVar1 = (int)param_1[0x3c] >> 0xe & 0x3f;
    bVar2 = (param_1[1] & 0x10000) == 0;
    break;
  case 0x80:
    uVar1 = (int)param_1[0x3f] >> 0xe & 0x3f;
    bVar2 = (param_1[1] & 0x20000) == 0;
    break;
  case 0xa0:
    uVar1 = (int)param_1[0x42] >> 0xe & 0x3f;
    bVar2 = (param_1[1] & 0x40000) == 0;
  }
  if (bVar2) {
    uVar1 = uVar1 | 0x80;
  }
switchD_100193f3_caseD_1:
  return uVar1;
}


