/* Ghidra analysis of supplied S-YXG50.dll at 100143c0 */

void __cdecl FUN_100143c0(int param_1)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = 0;
  for (iVar1 = *(int *)(param_1 + 0xdc); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x24)) {
    if (bVar2 < *(byte *)(iVar1 + 0x74)) {
      bVar2 = *(byte *)(iVar1 + 0x74);
    }
  }
  return;
}


