/* Ghidra analysis of supplied S-YXG50.dll at 1001c070 */

undefined4 __thiscall FUN_1001c070(void *this,int param_1,char param_2,undefined4 param_3)

{
  uint in_EAX;
  undefined4 uVar1;
  
                    /* WARNING: Load size is inaccurate */
  if ((*this == '\0') && (param_1 != 0)) {
    in_EAX = FUN_1001c260((int)this);
    if ((char)in_EAX != '\0') {
      uVar1 = FUN_1001c5b0((int)this);
      if ((char)uVar1 != '\0') {
        *(undefined4 *)((int)this + 4) = param_3;
        FUN_1001c120(this,param_2);
        FUN_1001d350(this,0xac44);
        FUN_1001d4a0(this,1);
        FUN_1001d4e0(this,0);
        FUN_1001d570(this,0,0);
        FUN_1001d7b0(this,'\x01');
        FUN_1001d7f0(this,'\x01');
        FUN_1001d850(this,'\x01');
        *(int *)((int)this + 8) = param_1;
        uVar1 = FUN_1001c240(this,0xff);
        *(undefined1 *)this = 1;
        return CONCAT31((int3)((uint)uVar1 >> 8),1);
      }
      in_EAX = FUN_1001c2e0((int)this);
    }
  }
  return in_EAX & 0xffffff00;
}


