
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __regparm1 FUN_00020b94(int *param_1,float param_2)

{
  double dVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  longdouble lVar6;
  longdouble lVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float *pfVar11;
  float *pfVar12;
  int iVar13;
  longdouble lVar14;
  longdouble lVar15;
  longdouble lVar16;
  longdouble lVar17;
  longdouble lVar18;
  longdouble lVar19;
  longdouble lVar20;
  longdouble lVar21;
  longdouble lVar22;
  longdouble lVar23;
  
  pfVar11 = (float *)param_1[1];
  iVar2 = *param_1;
  lVar14 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.05);
  lVar6 = (longdouble)/*c*/0.0061;
  lVar15 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.02);
  lVar16 = (longdouble)
           fcos(lVar15 + (longdouble)(double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.06))
  ;
  lVar15 = (longdouble)/*c*/0.0061;
  lVar17 = (longdouble)fcos((longdouble)DAT_00040310 * (longdouble)/*c*/0.01);
  lVar7 = (longdouble)/*c*/0.0061;
  fVar8 = DAT_00040310 * (float)/*c*/0.031;
  fVar9 = DAT_00040310 * (float)/*c*/0.042;
  fVar10 = DAT_00040310 * (float)/*c*/0.051;
  iVar13 = 0;
  pfVar12 = (float *)param_1[2];
  if (0 < iVar2) {
    do {
      fVar3 = *pfVar11;
      fVar4 = pfVar11[1];
      fVar5 = pfVar11[2];
      lVar22 = (longdouble)fpatan((longdouble)fVar4,(longdouble)fVar3);
      lVar18 = (longdouble)fVar4 * (longdouble)fVar4 + (longdouble)(fVar3 * fVar3);
      lVar23 = (longdouble)fpatan(SQRT(lVar18),(longdouble)fVar5);
      lVar19 = (longdouble)
               fsin((longdouble)(float)(lVar14 * lVar6) * (longdouble)fVar3 + (longdouble)fVar8);
      lVar20 = (longdouble)
               fsin((longdouble)(float)(lVar16 * lVar15) * (longdouble)fVar4 + (longdouble)fVar9);
      lVar21 = (longdouble)
               fsin((longdouble)(float)(lVar17 * lVar7) * (longdouble)fVar5 + (longdouble)fVar10);
      fVar3 = (float)(lVar21 * (longdouble)(double)(lVar20 * (longdouble)(double)lVar19) *
                      (longdouble)param_2 + (longdouble)SQRT(fVar5 * fVar5 + (float)lVar18));
      lVar18 = (longdouble)fsin((longdouble)(float)lVar23);
      dVar1 = (double)(lVar18 * (longdouble)fVar3);
      lVar18 = (longdouble)fcos((longdouble)(float)lVar22);
      *pfVar12 = (float)(lVar18 * (longdouble)dVar1);
      lVar18 = (longdouble)fsin((longdouble)(float)lVar22);
      pfVar12[1] = (float)(lVar18 * (longdouble)dVar1);
      lVar18 = (longdouble)fcos((longdouble)(float)lVar23);
      pfVar11 = pfVar11 + 3;
      iVar13 = iVar13 + 1;
      pfVar12[2] = (float)(lVar18 * (longdouble)fVar3);
      pfVar12 = pfVar12 + 3;
    } while (iVar13 < iVar2);
  }
  return;
}

