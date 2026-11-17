/* Ghidra analysis of supplied S-YXG50.dll at 1001a020 */

void __thiscall FUN_1001a020(void *this,int param_1,undefined4 param_2)

{
                    /* WARNING: Load size is inaccurate */
  *(undefined4 *)(param_1 * 0x54 + 0x4c + *this) = param_2;
  FUN_1001a690(*(int *)(*(int *)((int)this + 0x10) + param_1 * 4));
  return;
}


