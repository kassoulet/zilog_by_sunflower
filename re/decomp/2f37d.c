
uint FUN_0002f37d(uint param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  uint extraout_ECX;
  int extraout_EDX;
  int *extraout_EDX_00;
  undefined8 uVar3;
  
  iVar1 = *(int *)(param_2[2] + 0xc);
  if (iVar1 != 1) {
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    *(undefined4 *)(param_2[2] + 0xc) = 1;
  }
  if ((*(byte *)(param_2 + 3) & 2) == 0) {
    FUN_000284cf(4);
    *(byte *)(extraout_EDX + 0xc) = *(byte *)(extraout_EDX + 0xc) | 0x20;
  }
  else {
    if (*(int *)(param_2[2] + 8) == 0) {
      FUN_00028c7a(param_2);
      param_2 = extraout_EDX_00;
    }
    uVar2 = 0x400;
    if ((param_1 == 10) && (uVar2 = 0x600, (*(byte *)(param_2 + 3) & 0x40) == 0)) {
      *(byte *)((int)param_2 + 0xd) = *(byte *)((int)param_2 + 0xd) | 0x10;
      *(undefined1 *)*param_2 = 0xd;
      iVar1 = param_2[1];
      *param_2 = *param_2 + 1;
      param_2[1] = iVar1 + 1;
      if (iVar1 + 1 == param_2[5]) {
        uVar3 = FUN_00028acc(param_2);
        param_2 = (int *)((ulonglong)uVar3 >> 0x20);
        uVar2 = extraout_ECX;
        if ((int)uVar3 != 0) {
          return 0xffffffff;
        }
      }
    }
    *(byte *)((int)param_2 + 0xd) = *(byte *)((int)param_2 + 0xd) | 0x10;
    *(char *)*param_2 = (char)param_1;
    iVar1 = param_2[1];
    *param_2 = *param_2 + 1;
    param_2[1] = iVar1 + 1;
    if ((((uVar2 & param_2[3]) == 0) && (iVar1 + 1 != param_2[5])) ||
       (iVar1 = FUN_00028acc(param_2), iVar1 == 0)) {
      return param_1 & 0xff;
    }
  }
  return 0xffffffff;
}

