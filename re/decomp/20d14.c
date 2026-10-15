
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00020d14(int *param_1,undefined4 param_2)

{
  int iVar1;
  float fVar2;
  longdouble lVar3;
  longdouble lVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *pfVar8;
  float *pfVar9;
  int iVar10;
  longdouble lVar11;
  longdouble lVar12;
  longdouble lVar13;
  longdouble lVar14;
  longdouble lVar15;
  
  pfVar8 = (float *)param_1[1];
  iVar1 = *param_1;
  lVar11 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)_DAT_0003e504);
  lVar3 = (longdouble)_DAT_0003e50c;
  lVar12 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)_DAT_0003e50c);
  lVar13 = (longdouble)
           fcos(lVar12 + (longdouble)(double)((longdouble)DAT_00040310 * (longdouble)_DAT_0003e514))
  ;
  lVar12 = (longdouble)_DAT_0003e50c;
  lVar14 = (longdouble)fcos((longdouble)DAT_00040310 * (longdouble)_DAT_0003e50c);
  lVar4 = (longdouble)_DAT_0003e50c;
  fVar5 = DAT_00040310 * (float)_DAT_0003e51c;
  fVar6 = DAT_00040310 * (float)_DAT_0003e524;
  fVar7 = DAT_00040310 * (float)_DAT_0003e52c;
  iVar10 = 0;
  pfVar9 = (float *)param_1[2];
  if (0 < iVar1) {
    do {
      fVar2 = pfVar8[1];
      param_1 = (int *)pfVar8[2];
      lVar15 = (longdouble)
               fcos((longdouble)(float)(lVar13 * lVar12) * (longdouble)(float)param_1 +
                    (longdouble)fVar6);
      lVar15 = (longdouble)fsin(lVar15 + (longdouble)((float)(lVar11 * lVar3) * *pfVar8 + fVar5));
      *pfVar9 = (float)(lVar15 * (longdouble)_DAT_0003e534 + (longdouble)*pfVar8);
      lVar15 = (longdouble)
               fcos((longdouble)(float)(lVar14 * lVar4) * (longdouble)(float)param_1 +
                    (longdouble)fVar7);
      lVar15 = (longdouble)fsin(lVar15 + (longdouble)((float)(lVar13 * lVar12) * fVar2 + fVar6));
      pfVar9[1] = (float)(lVar15 * (longdouble)_DAT_0003e534 + (longdouble)fVar2);
      lVar15 = (longdouble)
               fcos((longdouble)(float)(lVar14 * lVar4) * (longdouble)fVar2 + (longdouble)fVar7);
      lVar15 = (longdouble)
               fsin(lVar15 + (longdouble)((float)(lVar11 * lVar3) * (float)param_1 + fVar5));
      pfVar8 = pfVar8 + 3;
      iVar10 = iVar10 + 1;
      pfVar9[2] = (float)(lVar15 * (longdouble)_DAT_0003e534 + (longdouble)(float)param_1);
      pfVar9 = pfVar9 + 3;
    } while (iVar10 < iVar1);
  }
  return CONCAT44(param_2,param_1);
}

