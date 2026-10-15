
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __regparm1 FUN_0001b446(int *param_1,float param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  int local_1c;
  
  if (param_1[0x12] == 0) {
    iVar3 = thunk_FUN_00024c8f(*param_1 << 3);
    param_1[0x12] = iVar3;
  }
  iVar3 = param_1[0x12];
  iVar1 = param_1[1];
  iVar2 = *param_1;
  for (local_1c = 0; local_1c < iVar2; local_1c = local_1c + 1) {
    lVar4 = (longdouble)
            fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.01 +
                 (longdouble)param_2 * (longdouble)*(float *)(local_1c * 0xc + iVar1));
    lVar5 = (longdouble)
            fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.02 +
                 (longdouble)param_2 * (longdouble)*(float *)(local_1c * 0xc + iVar1 + 4));
    lVar6 = (longdouble)
            fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.015 +
                 (longdouble)param_2 * (longdouble)*(float *)(local_1c * 0xc + iVar1 + 8));
    *(float *)(local_1c * 8 + iVar3) =
         (float)(lVar6 * (longdouble)
                         (double)(lVar5 * (longdouble)(double)(lVar4 * (longdouble)/*c*/127.0)) +
                (longdouble)/*c*/127.0);
  }
  return;
}

