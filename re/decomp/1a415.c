
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __regparm2 FUN_0001a415(int *param_1,int param_2,float param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  undefined4 extraout_ECX;
  double dVar9;
  undefined2 extraout_ST0h;
  undefined2 extraout_ST0h_00;
  undefined2 extraout_ST0h_01;
  int local_2c;
  
  if ((char)param_1[7] == '\t') {
    iVar2 = *(int *)(*param_1 + 0x44);
    iVar3 = *(int *)*param_1;
    iVar4 = *(int *)(*param_1 + 0x50);
    for (local_2c = 0; local_2c < iVar3; local_2c = local_2c + 1) {
      if ((0.0 < *(float *)(*(int *)(*param_1 + 8) + local_2c * 0xc + 8)) &&
         (fVar7 = param_3 * *(float *)(local_2c * 4 + iVar4), 0x3f800000 < (int)fVar7)) {
        fVar5 = *(float *)(local_2c * 8 + iVar2);
        fVar6 = *(float *)(local_2c * 8 + iVar2 + 4);
        dVar9 = ftrunc(SUB108((longdouble)fVar6,0));
        iVar8 = (int)ROUND((longdouble)CONCAT28(extraout_ST0h,dVar9)) << 6;
        dVar9 = ftrunc(SUB108((longdouble)fVar5,0));
        iVar8 = iVar8 + (int)ROUND((longdouble)CONCAT28(extraout_ST0h_00,dVar9));
        dVar9 = ftrunc(SUB108((longdouble)fVar6,0));
        cVar1 = *(char *)(iVar8 + (int)ROUND((longdouble)CONCAT28(extraout_ST0h_01,dVar9)) * 0x100 +
                         param_2);
        if (cVar1 == '\0') {
          ftrunc(SUB108((longdouble)fVar7 * (longdouble)/*c*/256.0,0));
          ftrunc(SUB108((longdouble)fVar6 * (longdouble)/*c*/256.0,0));
          ftrunc(SUB108((longdouble)fVar5 * (longdouble)/*c*/256.0,0));
          FUN_0001efbc();
        }
        else if (cVar1 != -1) {
          ftrunc(SUB108((longdouble)fVar7 * (longdouble)/*c*/256.0,0));
          ftrunc(SUB108((longdouble)*(float *)(local_2c * 8 + iVar2 + 4) * (longdouble)/*c*/256.0
                        ,0));
          ftrunc(SUB108((longdouble)*(float *)(local_2c * 8 + iVar2) * (longdouble)/*c*/256.0,0))
          ;
          FUN_0001f6b2(extraout_ECX);
        }
      }
    }
  }
  return;
}

