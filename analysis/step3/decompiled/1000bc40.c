/* Ghidra analysis of supplied S-YXG50.dll at 1000bc40 */

uint __cdecl FUN_1000bc40(int param_1,char param_2)

{
  byte bVar1;
  uint in_EAX;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  
  bVar1 = *(byte *)(param_1 + 0xd3);
  if (bVar1 != 0) {
    in_EAX = 0;
    if (bVar1 != 0) {
      do {
        if (param_2 == *(char *)((in_EAX & 0xffff) + 0xcb + param_1)) {
          iVar4 = bVar1 + 0xffff;
          if ((ushort)in_EAX < (ushort)iVar4) {
            iVar2 = (in_EAX & 0xffff) + param_1;
            puVar5 = (undefined1 *)(iVar2 + 0xcc);
            puVar6 = (undefined1 *)(iVar2 + 0xcb);
            for (uVar3 = iVar4 - in_EAX & 0xffff; uVar3 != 0; uVar3 = uVar3 - 1) {
              *puVar6 = *puVar5;
              puVar5 = puVar5 + 1;
              puVar6 = puVar6 + 1;
            }
          }
          *(char *)(param_1 + 0xd3) = (char)iVar4;
          return CONCAT22((short)(in_EAX >> 0x10),1);
        }
        in_EAX = in_EAX + 1;
      } while ((ushort)in_EAX < (ushort)bVar1);
    }
  }
  return in_EAX & 0xffff0000;
}


