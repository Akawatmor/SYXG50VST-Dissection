/* Ghidra analysis of supplied S-YXG50.dll at 100180e0 */

undefined4 __thiscall FUN_100180e0(void *this,char param_1,undefined4 param_2,undefined1 param_3)

{
  uint in_EAX;
  undefined4 uVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == '\0') {
    in_EAX = FUN_100181f0((int)this);
    if ((char)in_EAX != '\0') {
      uVar1 = FUN_100185a0(this,param_1,param_2);
      if ((char)uVar1 != '\0') {
        uVar1 = FUN_10018240(this,param_1,param_2);
        if ((char)uVar1 != '\0') {
          uVar1 = FUN_10018480(this,param_1,param_3);
          if ((char)uVar1 != '\0') {
            *(undefined1 *)this = 1;
            return CONCAT31((int3)((uint)uVar1 >> 8),1);
          }
          FUN_100182f0((int)this);
        }
        FUN_10018650((int)this);
      }
      in_EAX = FUN_10018220((int)this);
    }
  }
  return in_EAX & 0xffffff00;
}


