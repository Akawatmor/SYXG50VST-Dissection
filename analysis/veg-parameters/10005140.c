/* VEG parameter conversion, VA 10005140 */

void FUN_10005140(int *param_1,undefined4 param_2)

{
  byte bVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  
  (**(code **)(*param_1 + 0x58))(param_1,0x480,param_2,*(undefined1 *)((int)param_1 + 0x1c6));
  uVar2 = FUN_100050d0(*(undefined2 *)((int)param_1 + 0x1b6),(char)param_1[0x6d]);
  (**(code **)((int)((ulonglong)uVar2 >> 0x20) + 0x5c))(param_1,0x400,param_2,(uint)uVar2 & 0xffff);
  (**(code **)(*param_1 + 0x58))(param_1,0x440,param_2,(char)param_1[0x6e]);
  (**(code **)(*param_1 + 0x58))
            (param_1,0x441,param_2,
             (*(byte *)((int)param_1 + 0x1bb) ^ *(byte *)(param_1 + 0x6f)) & 0x1f ^
             *(byte *)(param_1 + 0x6f));
  (**(code **)(*param_1 + 0x58))(param_1,0x540,param_2,*(undefined1 *)((int)param_1 + 0x1be));
  (**(code **)(*param_1 + 0x58))(param_1,0x541,param_2,*(undefined1 *)((int)param_1 + 0x1bf));
  (**(code **)(*param_1 + 0x58))(param_1,0x580,param_2,(char)param_1[0x70]);
  (**(code **)(*param_1 + 0x58))(param_1,0x581,param_2,*(undefined1 *)((int)param_1 + 0x1c1));
  (**(code **)(*param_1 + 0x58))(param_1,0x5c0,param_2,*(undefined1 *)((int)param_1 + 0x1c2));
  (**(code **)(*param_1 + 0x58))(param_1,0x5c1,param_2,(char)param_1[0x77]);
  bVar1 = *(byte *)((int)param_1 + 0x1c7);
  if ((char)bVar1 < '\0') {
    (**(code **)(*param_1 + 0x58))(param_1,0x4c0,param_2,bVar1 & 0x7f);
    uVar3 = 0;
  }
  else {
    (**(code **)(*param_1 + 0x58))(param_1,0x4c0,param_2,bVar1 | 0x80);
    uVar3 = 0xff;
  }
  (**(code **)(*param_1 + 0x58))(param_1,0x4c1,param_2,uVar3);
  (**(code **)(*param_1 + 0x58))(param_1,0x500,param_2,*(undefined1 *)((int)param_1 + 0x1ca));
  (**(code **)(*param_1 + 0x58))(param_1,0x501,param_2,*(undefined1 *)((int)param_1 + 0x1c9));
  (**(code **)(*param_1 + 0x5c))(param_1,0x680,param_2,(short)param_1[0x71]);
  (**(code **)(*param_1 + 0x5c))(param_1,0x100,param_2,0x8000);
  (**(code **)(*param_1 + 0x5c))(param_1,0x140,param_2,param_1[0x73]);
  (**(code **)(*param_1 + 0x5c))(param_1,0x6c0,param_2,param_1[0x75]);
  (**(code **)(*param_1 + 0x58))(param_1,0x600,param_2,*(undefined1 *)((int)param_1 + 0x1cb));
  (**(code **)(*param_1 + 0x5c))(param_1,0x640,param_2,param_1[0x74]);
  (**(code **)(*param_1 + 0x58))
            (param_1,0x480,param_2,*(byte *)((int)param_1 + 0x1ba) | *(byte *)((int)param_1 + 0x1b9)
            );
  (**(code **)(*param_1 + 0x58))(param_1,0x481,param_2,*(undefined1 *)((int)param_1 + 0x1bd));
  return;
}


