/* Ghidra analysis of supplied S-YXG50.dll at 10016b60 */

undefined2 FUN_10016b60(int *param_1,int param_2)

{
  undefined2 uVar1;
  
  if ((*(byte *)(param_2 + 0x112) & 1) == 0) {
    return *(undefined2 *)(param_2 + 0x10c);
  }
  uVar1 = (**(code **)(*param_1 + 0x4e8))(param_1,param_2);
  *(byte *)(param_2 + 0x112) = *(byte *)(param_2 + 0x112) & 0xfe;
  *(undefined2 *)(param_2 + 0x10c) = uVar1;
  return uVar1;
}


