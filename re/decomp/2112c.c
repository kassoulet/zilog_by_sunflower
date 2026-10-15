
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002112c(int *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float *pfVar9;
  float *pfVar10;
  int extraout_ECX;
  float *pfVar11;
  int iVar12;
  int iVar13;
  double dVar14;
  undefined2 extraout_ST0h;
  longdouble lVar15;
  longdouble lVar16;
  longdouble lVar17;
  longdouble lVar18;
  
  iVar4 = *param_1;
  iVar5 = param_1[1];
  iVar12 = 0;
  iVar6 = param_1[2];
  if (0 < iVar4) {
    iVar13 = iVar5;
    do {
      dVar14 = ftrunc(SUB108((longdouble)*(float *)(iVar13 + 8) + (longdouble)/*c*/700.0,0));
      iVar1 = (int)ROUND((longdouble)CONCAT28(extraout_ST0h,dVar14));
      lVar15 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.01);
      lVar15 = lVar15 * (longdouble)/*c*/3.0 * (longdouble)iVar1 * (longdouble)/*c*/0.002;
      lVar16 = (longdouble)fsin(lVar15);
      lVar15 = (longdouble)fcos((longdouble)(float)lVar15);
      lVar17 = (longdouble)fcos((longdouble)DAT_00040310 * (longdouble)/*c*/0.01);
      lVar18 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.13);
      fVar2 = (float)(lVar18 * (longdouble)
                               (double)(lVar17 * (longdouble)/*c*/10.0 * (longdouble)iVar1 *
                                       (longdouble)/*c*/0.004));
      lVar17 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.07);
      fVar3 = (float)(lVar17 * (longdouble)/*c*/10.0 * (longdouble)iVar1 *
                     (longdouble)/*c*/0.004);
      pfVar9 = (float *)(iVar5 + extraout_ECX);
      pfVar11 = (float *)(iVar6 + extraout_ECX);
      do {
        fVar7 = *pfVar9 - fVar2;
        fVar8 = pfVar9[1] - fVar3;
        *pfVar11 = fVar8 * (float)lVar16 + fVar7 * (float)lVar15 + fVar2;
        pfVar10 = pfVar9 + 3;
        pfVar11[1] = (fVar7 * (float)lVar16 + fVar3) - fVar8 * (float)lVar15;
        pfVar11[2] = pfVar9[2];
        pfVar9 = pfVar10;
        pfVar11 = pfVar11 + 3;
      } while (pfVar10 != (float *)(extraout_ECX + iVar5 + 0x504));
      iVar12 = iVar12 + 0x6b;
      iVar13 = iVar13 + 0x504;
    } while (iVar12 < iVar4);
  }
  return;
}

