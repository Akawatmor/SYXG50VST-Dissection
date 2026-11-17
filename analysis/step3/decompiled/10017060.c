/* Ghidra analysis of supplied S-YXG50.dll at 10017060 */

int __cdecl FUN_10017060(int param_1,int param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_1 >> 0x10);
  if ((*(byte *)(param_1 + 1) <= *(byte *)(param_2 + 1)) &&
     (*(byte *)(param_2 + 1) <= *(byte *)(param_1 + 2))) {
    if (*(char *)(param_2 + 10) == '\0') {
      if ((*(byte *)(param_1 + 3) <= *(byte *)(param_2 + 3)) &&
         (*(byte *)(param_2 + 3) <= *(byte *)(param_1 + 4))) {
LAB_100170a0:
        return CONCAT22(uVar1,1);
      }
    }
    else if ((*(char *)(param_2 + 0xd) != '\x01') ||
            ((*(byte *)(param_1 + 3) <= *(byte *)(param_2 + 3) &&
             (*(byte *)(param_2 + 3) <= *(byte *)(param_1 + 4))))) goto LAB_100170a0;
  }
  return (uint)uVar1 << 0x10;
}


