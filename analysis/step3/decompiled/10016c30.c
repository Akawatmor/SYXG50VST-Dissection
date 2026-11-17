/* Ghidra analysis of supplied S-YXG50.dll at 10016c30 */

undefined1 __cdecl FUN_10016c30(undefined1 param_1,byte param_2,byte param_3)

{
  switch(param_1) {
  case 0:
    if ((param_2 == 0) || (DAT_100552e4[param_2] != *DAT_100552e4)) {
      return 1;
    }
    break;
  default:
    break;
  case 0x78:
    if ((param_3 == 0) || (DAT_100552e8[param_3] != *DAT_100552e8)) {
      return 1;
    }
    break;
  case 0x79:
    if (*(char *)((uint)param_2 + DAT_100552e0) != '\0') {
      return 1;
    }
    break;
  case 0x7f:
    if ((param_3 == 0) || (DAT_100552cc[param_3] != *DAT_100552cc)) {
      return 1;
    }
  }
  return 0;
}


