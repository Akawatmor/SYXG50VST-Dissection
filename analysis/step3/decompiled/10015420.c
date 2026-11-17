/* Ghidra analysis of supplied S-YXG50.dll at 10015420 */

void FUN_10015420(int *param_1)

{
  if (*(byte *)((int)param_1 + 0x69de) < 0x10) {
    (**(code **)(*param_1 + 0x340))
              (param_1,param_1 + (uint)(byte)(&DAT_100418d0)[*(byte *)((int)param_1 + 0x69de)] *
                                 0x47 + 0x78);
  }
  (**(code **)(*param_1 + 0x564))(param_1);
  return;
}


