
undefined8 FUN_00028acc(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  undefined4 *extraout_ECX_00;
  undefined4 *extraout_ECX_01;
  int extraout_EDX;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 0;
  if ((*(byte *)((int)param_1 + 0xd) & 0x10) == 0) {
    if ((*(int *)(param_1[2] + 8) != 0) &&
       (*(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xef,
       (*(byte *)((int)param_1 + 0xd) & 0x20) == 0)) {
      iVar5 = param_1[1];
      if (iVar5 != 0) {
        iVar5 = FUN_00028bca(param_1[4],-iVar5,1);
        param_1 = extraout_ECX_01;
      }
      if (iVar5 == -1) {
        *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 0x20;
        iVar3 = -1;
      }
    }
  }
  else {
    *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0xef;
    if (((*(byte *)(param_1 + 3) & 2) != 0) && (iVar5 = *(int *)(param_1[2] + 8), iVar5 != 0)) {
      iVar4 = param_1[1];
      while ((iVar4 != 0 && (iVar3 == 0))) {
        iVar2 = FUN_0002eb49(param_1[4],iVar5,iVar4);
        param_1 = extraout_ECX;
        if (iVar2 == -1) {
          *(byte *)(extraout_ECX + 3) = *(byte *)(extraout_ECX + 3) | 0x20;
          iVar3 = -1;
        }
        else if (iVar2 == 0) {
          FUN_000284cf(0xc);
          iVar3 = -1;
          *(byte *)(extraout_ECX_00 + 3) = *(byte *)(extraout_ECX_00 + 3) | 0x20;
          param_1 = extraout_ECX_00;
          iVar2 = extraout_EDX;
        }
        iVar5 = iVar5 + iVar2;
        iVar4 = iVar4 - iVar2;
      }
    }
  }
  uVar1 = *(undefined4 *)(param_1[2] + 8);
  param_1[1] = 0;
  *param_1 = uVar1;
  if ((iVar3 == 0) && ((*(byte *)(param_1[2] + 0x10) & 1) != 0)) {
    iVar5 = thunk_FUN_0002fe07(param_1[4]);
    if (iVar5 == -1) {
      iVar3 = -1;
    }
  }
  return CONCAT44(param_2,iVar3);
}

