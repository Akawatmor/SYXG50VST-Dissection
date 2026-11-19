/* VEG parameter conversion, VA 10012980 */

char FUN_10012980(char param_1,char param_2)

{
  byte bVar1;
  
  bVar1 = param_1 + param_2;
  if (0x7f < bVar1) {
    bVar1 = 0x7f;
  }
  return '\x7f' - bVar1;
}


