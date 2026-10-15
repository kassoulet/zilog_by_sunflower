
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __regparm2 FUN_000219e8(int *param_1,int *param_2,float param_3)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  longdouble lVar6;
  longdouble lVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float *pfVar11;
  float *pfVar12;
  float *pfVar13;
  int iVar14;
  longdouble lVar15;
  longdouble lVar16;
  longdouble lVar17;
  longdouble lVar18;
  longdouble lVar19;
  
  iVar1 = *param_1;
  pfVar2 = (float *)param_1[2];
  pfVar12 = (float *)param_1[1];
  lVar15 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.061);
  lVar6 = (longdouble)/*c*/250.0;
  lVar16 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.073);
  lVar7 = (longdouble)/*c*/50.0;
  iVar14 = 0;
  pfVar11 = pfVar2;
  if (0 < iVar1 >> 1) {
    do {
      iVar3 = *param_2;
      fVar4 = pfVar12[1];
      fVar5 = pfVar12[2];
      fVar8 = *pfVar12 - (float)(lVar15 * lVar6);
      *pfVar11 = *pfVar12;
      fVar9 = fVar4 - (float)(lVar16 * lVar7);
      pfVar11[1] = fVar4;
      fVar10 = fVar5 + /*c*/-340.0;
      pfVar11[2] = fVar5;
      lVar18 = (longdouble)fpatan((longdouble)fVar9,(longdouble)fVar8);
      lVar19 = (longdouble)
               fpatan(SQRT((longdouble)fVar9 * (longdouble)fVar9 + (longdouble)(fVar8 * fVar8)),
                      (longdouble)fVar10);
      fVar4 = (float)lVar19;
      fVar5 = SQRT(fVar10 * fVar10 + fVar9 * fVar9 + fVar8 * fVar8) + param_3;
      lVar19 = (longdouble)fsin((longdouble)fVar4);
      lVar17 = (longdouble)fcos((longdouble)(float)lVar18);
      pfVar13 = pfVar2 + iVar3 * 3;
      *pfVar13 = (float)(lVar17 * (longdouble)(double)(lVar19 * (longdouble)fVar5) +
                        (longdouble)(float)(lVar15 * lVar6));
      lVar19 = (longdouble)fsin((longdouble)fVar4);
      lVar17 = (longdouble)fsin((longdouble)(float)lVar18);
      pfVar13[1] = (float)(lVar17 * (longdouble)(double)(lVar19 * (longdouble)fVar5) +
                          (longdouble)(float)(lVar16 * lVar7));
      lVar19 = (longdouble)fcos((longdouble)fVar4);
      pfVar12 = pfVar12 + 3;
      param_2 = param_2 + 1;
      iVar14 = iVar14 + 1;
      pfVar13[2] = (float)(lVar19 * (longdouble)fVar5 + (longdouble)/*c*/340.0);
      pfVar11 = pfVar11 + 3;
    } while (iVar14 < iVar1 >> 1);
  }
  return;
}

