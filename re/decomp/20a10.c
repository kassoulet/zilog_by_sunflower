
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00020a10(int *param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  longdouble lVar9;
  longdouble lVar10;
  longdouble lVar11;
  longdouble lVar12;
  longdouble lVar13;
  longdouble lVar14;
  longdouble lVar15;
  longdouble lVar16;
  longdouble lVar17;
  
  pfVar7 = (float *)param_1[1];
  iVar2 = *param_1;
  lVar9 = (longdouble)fcos((longdouble)DAT_00040310 * (longdouble)/*c*/0.0347);
  lVar10 = (longdouble)
           fsin(lVar9 + (longdouble)(double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.00132));
  lVar9 = (longdouble)/*c*/200.0;
  lVar11 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.0458);
  lVar12 = (longdouble)
           fcos((longdouble)(double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.00241) - lVar11)
  ;
  lVar11 = (longdouble)/*c*/200.0;
  lVar13 = (longdouble)fcos((longdouble)DAT_00040310 * (longdouble)/*c*/0.0612);
  lVar14 = (longdouble)
           fsin(lVar13 + (longdouble)(double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.00145))
  ;
  lVar13 = (longdouble)/*c*/200.0;
  iVar8 = 0;
  pfVar6 = (float *)param_1[2];
  if (0 < iVar2) {
    do {
      fVar3 = *pfVar7 - (float)(lVar10 * lVar9);
      fVar4 = pfVar7[1] - (float)(lVar12 * lVar11);
      fVar5 = pfVar7[2] - (float)(lVar14 * lVar13);
      lVar16 = (longdouble)fpatan((longdouble)fVar4,(longdouble)fVar3);
      lVar17 = (longdouble)
               fpatan(SQRT((longdouble)fVar4 * (longdouble)fVar4 + (longdouble)(fVar3 * fVar3)),
                      (longdouble)fVar5);
      fVar1 = (float)lVar17;
      fVar3 = SQRT(fVar5 * fVar5 + fVar4 * fVar4 + fVar3 * fVar3 + (float)/*c*/200000.0) +
              (float)/*c*/-200.0;
      lVar17 = (longdouble)fsin((longdouble)fVar1);
      lVar15 = (longdouble)fcos((longdouble)(float)lVar16);
      *pfVar6 = (float)(lVar15 * (longdouble)(double)(lVar17 * (longdouble)fVar3) +
                       (longdouble)(float)(lVar10 * lVar9));
      lVar17 = (longdouble)fsin((longdouble)fVar1);
      lVar15 = (longdouble)fsin((longdouble)(float)lVar16);
      pfVar6[1] = (float)(lVar15 * (longdouble)(double)(lVar17 * (longdouble)fVar3) +
                         (longdouble)(float)(lVar12 * lVar11));
      lVar17 = (longdouble)fcos((longdouble)fVar1);
      pfVar7 = pfVar7 + 3;
      iVar8 = iVar8 + 1;
      pfVar6[2] = (float)(lVar17 * (longdouble)fVar3 + (longdouble)(float)(lVar14 * lVar13));
      pfVar6 = pfVar6 + 3;
    } while (iVar8 < iVar2);
  }
  return;
}

