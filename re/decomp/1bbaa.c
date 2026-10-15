
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __regparm2 FUN_0001bbaa(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  longdouble lVar5;
  float in_stack_00000014;
  float in_stack_00000018;
  int local_1c;
  float local_18;
  float local_14;
  int local_10;
  int local_c;
  
  iVar1 = param_1 * param_2;
  iVar2 = thunk_FUN_00024c8f(iVar1 * 0xc);
  iVar3 = thunk_FUN_00024c8f(param_1 * param_2 * 8);
  local_1c = 0;
  for (local_14 = (float)-param_2 * in_stack_00000014 * _DAT_0003e1f8;
      local_14 < (float)param_2 * in_stack_00000014 * _DAT_0003e1fc;
      local_14 = local_14 + in_stack_00000014) {
    for (local_18 = 0.0; local_18 < (float)param_1; local_18 = local_18 + 1.0) {
      lVar5 = (longdouble)
              fcos(((longdouble)local_18 * (longdouble)_DAT_0003e200 * (longdouble)_DAT_0003e208) /
                   (longdouble)param_1);
      *(float *)(local_1c * 0xc + iVar2) =
           (float)(lVar5 * (longdouble)(local_14 * in_stack_00000018));
      lVar5 = (longdouble)
              fsin(((longdouble)local_18 * (longdouble)_DAT_0003e200 * (longdouble)_DAT_0003e208) /
                   (longdouble)param_1);
      *(float *)(local_1c * 0xc + iVar2 + 4) =
           (float)(lVar5 * (longdouble)(local_14 * in_stack_00000018));
      *(float *)(iVar2 + local_1c * 0xc + 8) = local_14;
      local_1c = local_1c + 1;
    }
  }
  local_1c = 0;
  for (local_c = 0; local_c < param_2; local_c = local_c + 1) {
    for (local_10 = 0; local_10 < param_1; local_10 = local_10 + 1) {
      *(int *)(local_1c * 8 + iVar3) = local_c * param_1 + local_10;
      *(int *)(iVar3 + local_1c * 8 + 4) = local_c * param_1 + (local_10 + 1) % param_1;
      local_1c = local_1c + 1;
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

