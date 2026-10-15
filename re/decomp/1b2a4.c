
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001b2a4(int *param_1)

{
  float fVar1;
  int iVar2;
  double dVar3;
  longdouble lVar4;
  undefined2 extraout_ST0h;
  int local_24;
  int local_1c;
  
  if (param_1[0x12] == 0) {
    iVar2 = thunk_FUN_00024c8f(*param_1 << 3);
    param_1[0x12] = iVar2;
  }
  for (local_1c = 0; local_1c < *param_1; local_1c = local_1c + 1) {
    fVar1 = *(float *)(param_1[1] + local_1c * 0xc);
    lVar4 = (longdouble)*(float *)(param_1[1] + local_1c * 0xc + 4);
    dVar3 = ftrunc(SUB108((longdouble)/*c*/255.0 -
                          SQRT(lVar4 * lVar4 + (longdouble)(fVar1 * fVar1)) *
                          (longdouble)/*c*/0.51,0));
    local_24 = (int)ROUND((longdouble)CONCAT28(extraout_ST0h,dVar3));
    if (local_24 < 0) {
      local_24 = 0;
    }
    *(float *)(param_1[0x12] + local_1c * 8) = (float)local_24;
  }
  return;
}

