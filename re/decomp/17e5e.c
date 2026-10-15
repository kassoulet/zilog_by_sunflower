
void __regparm1 FUN_00017e5e(int *param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  int iVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  longdouble lVar18;
  int local_38;
  int local_34;
  
  lVar18 = (longdouble)fcos((longdouble)param_2);
  fVar1 = (float)lVar18;
  lVar18 = (longdouble)fsin((longdouble)param_2);
  fVar2 = (float)lVar18;
  lVar18 = (longdouble)fcos((longdouble)param_3);
  fVar3 = (float)lVar18;
  lVar18 = (longdouble)fsin((longdouble)param_3);
  fVar4 = (float)lVar18;
  lVar18 = (longdouble)fcos((longdouble)param_4);
  fVar5 = (float)lVar18;
  lVar18 = (longdouble)fsin((longdouble)param_4);
  fVar6 = (float)lVar18;
  fVar12 = fVar1 * fVar3;
  fVar13 = fVar2 * fVar3;
  fVar14 = fVar2 * fVar5 + fVar1 * fVar4 * fVar6;
  fVar15 = -fVar1 * fVar5 + fVar2 * fVar4 * fVar6;
  fVar16 = fVar2 * fVar6 - fVar1 * fVar4 * fVar5;
  fVar1 = -fVar1 * fVar6 - fVar2 * fVar4 * fVar5;
  if (((char)param_1[7] == '\0') || ((char)param_1[7] == '\x02')) {
    local_34 = *(int *)(*param_1 + 8);
  }
  else {
    local_34 = *(int *)(*param_1 + 4);
  }
  iVar7 = *(int *)(*param_1 + 8);
  iVar8 = *(int *)*param_1;
  if (*(int *)(*param_1 + 0xc) == 0) {
    for (local_38 = 0; local_38 < iVar8; local_38 = local_38 + 1) {
      fVar2 = *(float *)(local_38 * 0xc + local_34);
      fVar9 = *(float *)(local_38 * 0xc + local_34 + 4);
      fVar10 = *(float *)(local_38 * 0xc + local_34 + 8);
      fVar17 = fVar2 * fVar9;
      *(float *)(local_38 * 0xc + iVar7) =
           (fVar10 * fVar4 + (fVar13 + fVar2) * (fVar12 + fVar9)) - (fVar12 * fVar13 + fVar17);
      *(float *)(local_38 * 0xc + iVar7 + 4) =
           (fVar10 * -fVar3 * fVar6 + (fVar15 + fVar2) * (fVar14 + fVar9)) -
           (fVar14 * fVar15 + fVar17);
      *(float *)(local_38 * 0xc + iVar7 + 8) =
           (fVar10 * fVar3 * fVar5 + (fVar1 + fVar2) * (fVar16 + fVar9)) - (fVar16 * fVar1 + fVar17)
      ;
    }
  }
  else {
    iVar11 = *(int *)(*param_1 + 0xc);
    for (local_38 = 0; local_38 < iVar8; local_38 = local_38 + 1) {
      if (*(char *)(iVar11 + local_38) != '\0') {
        fVar2 = *(float *)(local_38 * 0xc + local_34);
        fVar9 = *(float *)(local_38 * 0xc + local_34 + 4);
        fVar10 = *(float *)(local_38 * 0xc + local_34 + 8);
        fVar17 = fVar2 * fVar9;
        *(float *)(local_38 * 0xc + iVar7) =
             (fVar10 * fVar4 + (fVar13 + fVar2) * (fVar12 + fVar9)) - (fVar12 * fVar13 + fVar17);
        *(float *)(local_38 * 0xc + iVar7 + 4) =
             (fVar10 * -fVar3 * fVar6 + (fVar15 + fVar2) * (fVar14 + fVar9)) -
             (fVar14 * fVar15 + fVar17);
        *(float *)(local_38 * 0xc + iVar7 + 8) =
             (fVar10 * fVar3 * fVar5 + (fVar1 + fVar2) * (fVar16 + fVar9)) -
             (fVar16 * fVar1 + fVar17);
      }
    }
  }
  return;
}

