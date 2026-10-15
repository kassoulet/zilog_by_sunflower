
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00027128(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  int *piVar3;
  int iVar4;
  double dVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  float *pfVar12;
  int *piVar13;
  int iVar14;
  undefined8 uVar15;
  int local_2c;
  
  pfVar1 = (float *)(param_1 + 0x14);
  pfVar2 = (float *)(param_1 + 0x28);
  uVar15 = FUN_00025f70(param_1,param_1);
  *(int *)((int)((ulonglong)uVar15 >> 0x20) + 0x10) = (int)uVar15;
  uVar9 = FUN_00025f70(pfVar1);
  *(undefined4 *)(param_1 + 0x24) = uVar9;
  uVar15 = FUN_00025f70(pfVar2);
  pfVar12 = (float *)((ulonglong)uVar15 >> 0x20);
  *(int *)(param_1 + 0x38) = (int)uVar15;
  if (((uint)pfVar12[4] & *(uint *)(param_1 + 0x24) & *(uint *)(param_1 + 0x38)) == 0) {
    fVar6 = *(float *)(param_1 + 0x18) - *(float *)(param_1 + 0x2c);
    fVar8 = pfVar12[1] - *(float *)(param_1 + 0x2c);
    fVar7 = (*pfVar12 - *pfVar2) * fVar6 - (*pfVar1 - *pfVar2) * fVar8;
    dVar5 = (double)fVar7;
    local_2c = SUB84(dVar5,0);
    if ((((ulonglong)dVar5 & 0x7fffffff00000000) != 0) || (local_2c != 0)) {
      iVar4 = (int)ROUND((((pfVar12[2] - *(float *)(param_1 + 0x30)) * fVar6 -
                          (*(float *)(param_1 + 0x1c) - *(float *)(param_1 + 0x30)) * fVar8) / fVar7
                         ) * (float)/*c*/65536.0);
      if ((((uint)pfVar12[4] | *(uint *)(param_1 + 0x24) | *(uint *)(param_1 + 0x38)) & 0xf) == 0) {
        DAT_00040ff8 = (int)ROUND(*pfVar12 * _DAT_0003f964);
        DAT_00040ffc = (int)ROUND(pfVar12[1] * _DAT_0003f964);
        DAT_00041000 = (int)ROUND(pfVar12[2] * (float)/*c*/65536.0);
        DAT_00041004 = (int)ROUND(*pfVar1 * _DAT_0003f964);
        DAT_00041008 = (int)ROUND(*(float *)(param_1 + 0x18) * _DAT_0003f964);
        DAT_0004100c = (int)ROUND(*(float *)(param_1 + 0x1c) * (float)/*c*/65536.0);
        DAT_00041010 = (int)ROUND(*pfVar2 * _DAT_0003f964);
        DAT_00041014 = (int)ROUND(*(float *)(param_1 + 0x2c) * _DAT_0003f964);
        DAT_00041018 = (int)ROUND(*(float *)(param_1 + 0x30) * (float)/*c*/65536.0);
        FUN_0002d0bc(&DAT_00040ff8,3,iVar4);
        return;
      }
      _DAT_0004101c = *pfVar12;
      _DAT_0004102c = pfVar12[4];
      _DAT_00041020 = pfVar12[1];
      _DAT_00041028 = 0;
      _DAT_0004103c = 0;
      _DAT_00041050 = 0;
      _DAT_00041024 = pfVar12[2];
      _DAT_00041030 = *pfVar1;
      _DAT_00041034 = *(undefined4 *)(param_1 + 0x18);
      _DAT_00041038 = *(undefined4 *)(param_1 + 0x1c);
      _DAT_00041044 = *pfVar2;
      _DAT_00041048 = *(undefined4 *)(param_1 + 0x2c);
      _DAT_0004104c = *(undefined4 *)(param_1 + 0x30);
      _DAT_00041040 = *(uint *)(param_1 + 0x24);
      _DAT_00041054 = *(uint *)(param_1 + 0x38);
      iVar10 = FUN_0002ad90(&DAT_0004110c,&DAT_0004101c);
      if (2 < iVar10) {
        iVar14 = 0;
        if (0 < iVar10) {
          iVar11 = 0;
          piVar13 = &DAT_00041118;
          do {
            fVar6 = (*(float **)(iVar11 + DAT_0004110c))[1] * _DAT_0003f964;
            (&DAT_00041110)[iVar14 * 3] =
                 (int)ROUND(**(float **)(iVar11 + DAT_0004110c) * _DAT_0003f964);
            (&DAT_00041114)[iVar14 * 3] = (int)ROUND(fVar6);
            piVar3 = (int *)(iVar11 + DAT_0004110c);
            iVar11 = iVar11 + 4;
            iVar14 = iVar14 + 1;
            *piVar13 = (int)ROUND(*(float *)(*piVar3 + 8) * (float)/*c*/65536.0);
            piVar13 = piVar13 + 3;
          } while (iVar14 < iVar10);
        }
        FUN_0002d0bc(&DAT_00041110,iVar10,iVar4);
        return;
      }
    }
  }
  return;
}

