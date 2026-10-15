
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __regparm1 FUN_0001a5ea(int *param_1,float param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  undefined4 extraout_ECX;
  int local_2c;
  
  if ((char)param_1[7] == '\t') {
    iVar2 = *(int *)(*param_1 + 0x44);
    iVar3 = *(int *)*param_1;
    iVar4 = *(int *)(*param_1 + 0x50);
    cVar1 = *(char *)((int)param_1 + 0x1d);
    for (local_2c = 0; local_2c < iVar3; local_2c = local_2c + 1) {
      if ((*(float *)(*(int *)(*param_1 + 8) + local_2c * 0xc + 8) < 0.0) &&
         (fVar5 = param_2 * *(float *)(local_2c * 4 + iVar4), 0x3f800000 < (int)fVar5)) {
        if (cVar1 == '\x03') {
          ftrunc(SUB108((longdouble)fVar5 * (longdouble)/*c*/256.0,0));
          ftrunc(SUB108((longdouble)*(float *)(local_2c * 8 + iVar2 + 4) * (longdouble)/*c*/256.0
                        ,0));
          ftrunc(SUB108((longdouble)*(float *)(local_2c * 8 + iVar2) * (longdouble)/*c*/256.0,0))
          ;
          FUN_0001febc(extraout_ECX);
        }
        if (cVar1 == '\x06') {
          ftrunc(SUB108((longdouble)fVar5 * (longdouble)/*c*/256.0,0));
          ftrunc(SUB108((longdouble)*(float *)(local_2c * 8 + iVar2 + 4) * (longdouble)/*c*/256.0
                        ,0));
          ftrunc(SUB108((longdouble)*(float *)(local_2c * 8 + iVar2) * (longdouble)/*c*/256.0,0))
          ;
          FUN_0001f337();
        }
        else {
          ftrunc(SUB108((longdouble)fVar5 * (longdouble)/*c*/256.0,0));
          ftrunc(SUB108((longdouble)*(float *)(local_2c * 8 + iVar2 + 4) * (longdouble)/*c*/256.0
                        ,0));
          ftrunc(SUB108((longdouble)*(float *)(local_2c * 8 + iVar2) * (longdouble)/*c*/256.0,0))
          ;
          FUN_0001efbc();
        }
      }
    }
  }
  return;
}

