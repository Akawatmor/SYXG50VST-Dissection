/* Ghidra analysis of supplied S-YXG50.dll at 10032b80 */

void FUN_10032b80(byte *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  
  bVar3 = 0;
  bVar2 = 0x5d;
  if (param_2 != 0) {
    do {
      bVar1 = *param_1 ^ bVar2 ^ bVar3;
      *param_1 = (bVar1 >> 4 | bVar1 << 4) ^ 0x5c;
      param_1 = param_1 + 1;
      bVar3 = bVar3 + 1;
      param_2 = param_2 + -1;
      bVar2 = ~bVar2;
    } while (param_2 != 0);
  }
  return;
}


