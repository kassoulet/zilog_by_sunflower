
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000206e0(int *param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  longdouble lVar6;
  float fVar7;
  float fVar8;
  float *pfVar9;
  float *pfVar10;
  int iVar11;
  longdouble lVar12;
  longdouble lVar13;
  longdouble lVar14;
  longdouble lVar15;
  longdouble lVar16;
  longdouble lVar17;
  
  pfVar9 = (float *)param_1[1];
  iVar2 = *param_1;
  lVar12 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.03);
  lVar6 = (longdouble)/*c*/0.01;
  lVar13 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.1);
  lVar14 = (longdouble)
           fcos(lVar13 + (longdouble)(double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.04))
  ;
  lVar13 = (longdouble)/*c*/0.01;
  fcos((longdouble)DAT_00040310 * (longdouble)/*c*/0.02);
  fVar7 = DAT_00040310 * (float)/*c*/0.0041;
  fVar8 = DAT_00040310 * (float)/*c*/0.0062;
  iVar11 = 0;
  pfVar10 = (float *)param_1[2];
  if (0 < iVar2) {
    do {
      fVar3 = *pfVar9;
      fVar4 = pfVar9[1];
      fVar5 = pfVar9[2];
      lVar16 = (longdouble)fpatan((longdouble)fVar4,(longdouble)fVar3);
      lVar17 = (longdouble)
               fpatan(SQRT((longdouble)fVar4 * (longdouble)fVar4 + (longdouble)(fVar3 * fVar3)),
                      (longdouble)fVar5);
      fVar1 = (float)lVar17;
      fVar3 = SQRT(fVar5 * fVar5 + fVar4 * fVar4 + fVar3 * fVar3);
      lVar17 = (longdouble)
               fcos((longdouble)(float)(lVar14 * lVar13) * (longdouble)fVar3 - (longdouble)fVar8);
      lVar17 = (longdouble)fsin(lVar17 + (longdouble)((float)(lVar12 * lVar6) * fVar3 + fVar7));
      fVar3 = (float)(lVar17 * (longdouble)/*c*/140.0 + (longdouble)fVar3);
      lVar17 = (longdouble)fsin((longdouble)fVar1);
      lVar15 = (longdouble)fcos((longdouble)(float)lVar16);
      *pfVar10 = (float)(lVar15 * (longdouble)(double)(lVar17 * (longdouble)fVar3));
      lVar17 = (longdouble)fsin((longdouble)fVar1);
      lVar15 = (longdouble)fsin((longdouble)(float)lVar16);
      pfVar10[1] = (float)(lVar15 * (longdouble)(double)(lVar17 * (longdouble)fVar3));
      lVar17 = (longdouble)fcos((longdouble)fVar1);
      pfVar9 = pfVar9 + 3;
      iVar11 = iVar11 + 1;
      pfVar10[2] = (float)(lVar17 * (longdouble)fVar3);
      pfVar10 = pfVar10 + 3;
    } while (iVar11 < iVar2);
  }
  return;
}

