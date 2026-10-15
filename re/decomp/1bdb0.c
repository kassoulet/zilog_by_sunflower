
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __regparm2 FUN_0001bdb0(int param_1,int param_2,float param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  longdouble lVar5;
  int local_30;
  float local_2c;
  int local_24;
  int local_20;
  float local_1c;
  
  iVar1 = param_1 * param_2;
  iVar2 = thunk_FUN_00024c8f(iVar1 * 0xc);
  iVar3 = thunk_FUN_00024c8f(param_1 * param_2 * 8);
  local_30 = 0;
  for (local_1c = param_3 / (float)param_2; local_1c <= param_3;
      local_1c = param_3 / (float)param_2 + local_1c) {
    for (local_2c = 0.0; local_2c < (float)param_1; local_2c = local_2c + 1.0) {
      lVar5 = (longdouble)
              fcos(((longdouble)local_2c * (longdouble)/*c*/2.0 * (longdouble)/*c*/3.1415927) /
                   (longdouble)param_1);
      *(float *)(local_30 * 0xc + iVar2) = (float)((longdouble)local_1c * lVar5);
      lVar5 = (longdouble)
              fsin(((longdouble)local_2c * (longdouble)/*c*/2.0 * (longdouble)/*c*/3.1415927) /
                   (longdouble)param_1);
      *(float *)(local_30 * 0xc + iVar2 + 4) = (float)((longdouble)local_1c * lVar5);
      *(undefined4 *)(local_30 * 0xc + iVar2 + 8) = 0;
      local_30 = local_30 + 1;
    }
  }
  local_30 = 0;
  for (local_20 = 0; local_20 < param_2; local_20 = local_20 + 1) {
    for (local_24 = 0; local_24 < param_1; local_24 = local_24 + 1) {
      *(int *)(local_30 * 8 + iVar3) = local_20 * param_1 + local_24;
      *(int *)(iVar3 + local_30 * 8 + 4) = local_20 * param_1 + (local_24 + 1) % param_1;
      local_30 = local_30 + 1;
    }
  }
  piVar4 = (int *)FUN_00024c8f(0x54);
  *piVar4 = iVar1;
  piVar4[1] = iVar2;
  iVar2 = thunk_FUN_00024c8f(iVar1 * 0xc);
  piVar4[2] = iVar2;
  piVar4[0x10] = iVar3;
  piVar4[0xf] = param_1 * param_2;
  iVar1 = thunk_FUN_00024c8f(iVar1 * 8);
  piVar4[0x11] = iVar1;
  piVar4[3] = 0;
  piVar4[0x14] = 0;
  piVar4[0x12] = 0;
  return piVar4;
}

