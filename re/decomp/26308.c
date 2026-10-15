
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00026308(float *param_1,undefined4 param_2,undefined4 unaff_EBX)

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
      DAT_00040790 = (int)ROUND(*param_1 * _DAT_0003f964);
      DAT_00040794 = (int)ROUND(param_1[1] * _DAT_0003f964);
      DAT_00040798 = (int)ROUND(param_1[2] * _DAT_0003f964);
      DAT_0004079c = (int)ROUND(param_1[3] * _DAT_0003f964);
      DAT_000407a0 = (int)ROUND(*extraout_ECX_01 * _DAT_0003f964);
      DAT_000407a4 = (int)ROUND(extraout_ECX_01[1] * _DAT_0003f964);
      DAT_000407a8 = (int)ROUND(extraout_ECX_01[2] * _DAT_0003f964);
      DAT_000407ac = (int)ROUND(extraout_ECX_01[3] * _DAT_0003f964);
      DAT_000407b0 = (int)ROUND(*pfVar8 * _DAT_0003f964);
      DAT_000407b4 = (int)ROUND(pfVar8[1] * _DAT_0003f964);
      DAT_000407b8 = (int)ROUND(pfVar8[2] * _DAT_0003f964);
      DAT_000407bc = (int)ROUND(pfVar8[3] * _DAT_0003f964);
      DAT_000407c0 = (float)(int)ROUND(pfVar8[4] * _DAT_0003f964);
      FUN_0002be3c(&DAT_00040790,3,param_2,iVar2,iVar3);
      return;
    }
    DAT_000407c0 = *param_1;
    _DAT_000407d0 = param_1[4];
    _DAT_000407c4 = param_1[1];
    _DAT_000407c8 = param_1[2];
    _DAT_000407cc = param_1[3];
    _DAT_000407d4 = *extraout_ECX_01;
    _DAT_000407d8 = extraout_ECX_01[1];
    _DAT_000407dc = extraout_ECX_01[2];
    _DAT_000407e0 = extraout_ECX_01[3];
    _DAT_000407e8 = *pfVar8;
    _DAT_000407ec = pfVar8[1];
    _DAT_000407f0 = pfVar8[2];
    _DAT_000407f4 = pfVar8[3];
    _DAT_000407e4 = extraout_ECX_01[4];
    _DAT_000407f8 = pfVar8[4];
    iVar6 = FUN_0002ad90(&DAT_000408b0,&DAT_000407c0);
    if (2 < iVar6) {
      iVar9 = 0;
      if (0 < iVar6) {
        iVar10 = 0;
        piVar7 = &DAT_000408bc;
        do {
          fVar5 = (*(float **)(iVar10 + DAT_000408b0))[1] * _DAT_0003f964;
          (&DAT_000408b4)[iVar9 * 4] =
               (int)ROUND(**(float **)(iVar10 + DAT_000408b0) * _DAT_0003f964);
          (&DAT_000408b8)[iVar9 * 4] = (int)ROUND(fVar5);
          piVar1 = (int *)(iVar10 + DAT_000408b0);
          iVar10 = iVar10 + 4;
          iVar9 = iVar9 + 1;
          fVar5 = *(float *)(*piVar1 + 0xc) * _DAT_0003f964;
          *piVar7 = (int)ROUND(*(float *)(*piVar1 + 8) * _DAT_0003f964);
          piVar7[1] = (int)ROUND(fVar5);
          piVar7 = piVar7 + 4;
        } while (iVar9 < iVar6);
      }
      FUN_0002be3c(&DAT_000408b4,iVar6,param_2,iVar2,iVar3);
      return;
    }
  }
  return;
}

