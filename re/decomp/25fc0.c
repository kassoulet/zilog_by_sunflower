
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00025fc0(float *param_1,undefined4 param_2,undefined4 unaff_EBX)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  float fVar5;
  int iVar6;
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  float *extraout_ECX_01;
  int *piVar7;
  float *pfVar8;
  int iVar9;
  int iVar10;
  undefined8 uVar11;
  int local_38;
  
  fVar5 = (float)FUN_00025f70(param_1,param_1 + 10,unaff_EBX,param_1 + 5);
  param_1[4] = fVar5;
  uVar11 = FUN_00025f70(extraout_ECX);
  *(int *)(extraout_ECX_00 + 0x10) = (int)uVar11;
  uVar11 = FUN_00025f70((int)((ulonglong)uVar11 >> 0x20));
  pfVar8 = (float *)((ulonglong)uVar11 >> 0x20);
  pfVar8[4] = (float)uVar11;
  dVar4 = (double)((*param_1 - *pfVar8) * (extraout_ECX_01[1] - pfVar8[1]) -
                  (*extraout_ECX_01 - *pfVar8) * (param_1[1] - pfVar8[1]));
  local_38 = SUB84(dVar4,0);
  if ((((ulonglong)dVar4 & 0x7fffffff00000000) != 0) || (local_38 != 0)) {
    dVar4 = (1.0 / dVar4) * /*c*/65536.0;
    iVar2 = (int)ROUND(((param_1[2] - pfVar8[2]) * (extraout_ECX_01[1] - pfVar8[1]) -
                       (extraout_ECX_01[2] - pfVar8[2]) * (param_1[1] - pfVar8[1])) * (float)dVar4);
    iVar3 = (int)ROUND(((extraout_ECX_01[1] - pfVar8[1]) * (param_1[3] - pfVar8[3]) -
                       (param_1[1] - pfVar8[1]) * (extraout_ECX_01[3] - pfVar8[3])) * (float)dVar4);
    if ((((uint)param_1[4] | (uint)extraout_ECX_01[4] | (uint)pfVar8[4]) & 0xf) == 0) {
      DAT_000405ac = (int)ROUND(*param_1 * _DAT_0003f964);
      DAT_000405b0 = (int)ROUND(param_1[1] * _DAT_0003f964);
      DAT_000405b4 = (int)ROUND(param_1[2] * _DAT_0003f964);
      DAT_000405b8 = (int)ROUND(param_1[3] * _DAT_0003f964);
      DAT_000405bc = (int)ROUND(*extraout_ECX_01 * _DAT_0003f964);
      DAT_000405c0 = (int)ROUND(extraout_ECX_01[1] * _DAT_0003f964);
      DAT_000405c4 = (int)ROUND(extraout_ECX_01[2] * _DAT_0003f964);
      DAT_000405c8 = (int)ROUND(extraout_ECX_01[3] * _DAT_0003f964);
      DAT_000405cc = (int)ROUND(*pfVar8 * _DAT_0003f964);
      DAT_000405d0 = (int)ROUND(pfVar8[1] * _DAT_0003f964);
      DAT_000405d4 = (int)ROUND(pfVar8[2] * _DAT_0003f964);
      DAT_000405d8 = (int)ROUND(pfVar8[3] * _DAT_0003f964);
      DAT_000405dc = (float)(int)ROUND(pfVar8[4] * _DAT_0003f964);
      FUN_0002bbec(&DAT_000405ac,3,param_2,iVar2,iVar3);
      return;
    }
    DAT_000405dc = *param_1;
    _DAT_000405ec = param_1[4];
    _DAT_000405e0 = param_1[1];
    _DAT_000405e4 = param_1[2];
    _DAT_000405e8 = param_1[3];
    _DAT_000405f0 = *extraout_ECX_01;
    _DAT_000405f4 = extraout_ECX_01[1];
    _DAT_000405f8 = extraout_ECX_01[2];
    _DAT_000405fc = extraout_ECX_01[3];
    _DAT_00040604 = *pfVar8;
    _DAT_00040608 = pfVar8[1];
    _DAT_0004060c = pfVar8[2];
    _DAT_00040610 = pfVar8[3];
    _DAT_00040600 = extraout_ECX_01[4];
    _DAT_00040614 = pfVar8[4];
    iVar6 = FUN_0002ad90(&DAT_000406cc,&DAT_000405dc);
    if (2 < iVar6) {
      iVar9 = 0;
      if (0 < iVar6) {
        iVar10 = 0;
        piVar7 = &DAT_000406d8;
        do {
          fVar5 = (*(float **)(iVar10 + DAT_000406cc))[1] * _DAT_0003f964;
          (&DAT_000406d0)[iVar9 * 4] =
               (int)ROUND(**(float **)(iVar10 + DAT_000406cc) * _DAT_0003f964);
          (&DAT_000406d4)[iVar9 * 4] = (int)ROUND(fVar5);
          piVar1 = (int *)(iVar10 + DAT_000406cc);
          iVar10 = iVar10 + 4;
          iVar9 = iVar9 + 1;
          fVar5 = *(float *)(*piVar1 + 0xc) * _DAT_0003f964;
          *piVar7 = (int)ROUND(*(float *)(*piVar1 + 8) * _DAT_0003f964);
          piVar7[1] = (int)ROUND(fVar5);
          piVar7 = piVar7 + 4;
        } while (iVar9 < iVar6);
      }
      FUN_0002bbec(&DAT_000406d0,iVar6,param_2,iVar2,iVar3);
      return;
    }
  }
  return;
}

