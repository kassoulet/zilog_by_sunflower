
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __regparm1 FUN_00019f57(int *param_1,float param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int local_2c;
  
  if ((char)param_1[7] == '\t') {
    iVar2 = *(int *)(*param_1 + 0x44);
    iVar3 = *(int *)*param_1;
    iVar4 = *(int *)(*param_1 + 0x50);
    cVar1 = *(char *)((int)param_1 + 0x1d);
    if (*(int *)(*param_1 + 0xc) == 0) {
      for (local_2c = 0; local_2c < iVar3; local_2c = local_2c + 1) {
        fVar6 = param_2 * *(float *)(local_2c * 4 + iVar4);
        if (0x3f800000 < (int)fVar6) {
          if (cVar1 == '\x03') {
            ftrunc(SUB108((longdouble)fVar6 * (longdouble)/*c*/256.0,0));
            ftrunc(SUB108((longdouble)*(float *)(local_2c * 8 + iVar2 + 4) *
                          (longdouble)/*c*/256.0,0));
            ftrunc(SUB108((longdouble)*(float *)(local_2c * 8 + iVar2) * (longdouble)/*c*/256.0,0
                         ));
            FUN_0001febc(extraout_ECX);
          }
          else {
            ftrunc(SUB108((longdouble)fVar6 * (longdouble)/*c*/256.0,0));
            ftrunc(SUB108((longdouble)*(float *)(local_2c * 8 + iVar2 + 4) *
                          (longdouble)/*c*/256.0,0));
            ftrunc(SUB108((longdouble)*(float *)(local_2c * 8 + iVar2) * (longdouble)/*c*/256.0,0
                         ));
            FUN_0001efbc();
          }
        }
      }
    }
    else {
      iVar5 = *(int *)(*param_1 + 0xc);
      for (local_2c = 0; local_2c < iVar3; local_2c = local_2c + 1) {
        if ((*(char *)(iVar5 + local_2c) != '\0') &&
           (fVar6 = param_2 * *(float *)(local_2c * 4 + iVar4), 0x3f800000 < (int)fVar6)) {
          if (cVar1 == '\x03') {
            ftrunc(SUB108((longdouble)fVar6 * (longdouble)/*c*/256.0,0));
            ftrunc(SUB108((longdouble)*(float *)(local_2c * 8 + iVar2 + 4) *
                          (longdouble)/*c*/256.0,0));
            ftrunc(SUB108((longdouble)*(float *)(local_2c * 8 + iVar2) * (longdouble)/*c*/256.0,0
                         ));
            FUN_0001febc(extraout_ECX_00);
          }
          else {
            ftrunc(SUB108((longdouble)fVar6 * (longdouble)/*c*/256.0,0));
            ftrunc(SUB108((longdouble)*(float *)(local_2c * 8 + iVar2 + 4) *
                          (longdouble)/*c*/256.0,0));
            ftrunc(SUB108((longdouble)*(float *)(local_2c * 8 + iVar2) * (longdouble)/*c*/256.0,0
                         ));
            FUN_0001efbc();
          }
        }
      }
    }
  }
  return;
}

