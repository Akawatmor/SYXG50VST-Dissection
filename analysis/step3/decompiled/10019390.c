/* Ghidra analysis of supplied S-YXG50.dll at 10019390 */

void __thiscall FUN_10019390(void *this,undefined4 param_1)

{
  if ((*(byte *)((int)this + 4) & 1) == 0) {
    *(undefined4 *)((int)this + 4) = 3;
    *(undefined4 *)((int)this + 0x24) = param_1;
    FUN_1001ab00((int)this);
    FUN_1001a6e0((int)this);
    FUN_10019b00((int)this);
    FUN_10018ea0((int)this);
    FUN_1001b070((int)this);
  }
  return;
}


