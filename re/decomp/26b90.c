
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00026b90(float *param_1,undefined4 param_2,undefined4 unaff_EBX)

{
  int *piVar1;
  int iVar2;
  double dVar3;
  float fVar4;
  int iVar5;
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  float *extraout_ECX_01;
  int *piVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  int local_2c;
  
  fVar4 = (float)FUN_00025f70(param_1,param_1 + 10,unaff_EBX,param_1 + 5);
  param_1[4] = fVar4;
  uVar10 = FUN_00025f70(extraout_ECX);
  *(int *)(extraout_ECX_00 + 0x10) = (int)uVar10;
  uVar10 = FUN_00025f70((int)((ulonglong)uVar10 >> 0x20));
  pfVar7 = (float *)((ulonglong)uVar10 >> 0x20);
  pfVar7[4] = (float)uVar10;
  dVar3 = (double)((*param_1 - *pfVar7) * (extraout_ECX_01[1] - pfVar7[1]) -
                  (*extraout_ECX_01 - *pfVar7) * (param_1[1] - pfVar7[1]));
  local_2c = SUB84(dVar3,0);
  if ((((ulonglong)dVar3 & 0x7fffffff00000000) != 0) || (local_2c != 0)) {
    iVar2 = (int)ROUND((((double)param_1[2] - (double)pfVar7[2]) *
                        (double)(extraout_ECX_01[1] - pfVar7[1]) -
                       ((double)extraout_ECX_01[2] - (double)pfVar7[2]) *
                       (double)(param_1[1] - pfVar7[1])) * (1.0 / dVar3) * /*c*/65536.0);
    if ((((uint)param_1[4] | (uint)extraout_ECX_01[4] | (uint)pfVar7[4]) & 0xf) == 0) {
      DAT_00040c30 = (int)ROUND(*param_1 * _DAT_0003f964);
      DAT_00040c34 = (int)ROUND(param_1[1] * _DAT_0003f964);
      DAT_00040c38 = (int)ROUND(param_1[2] * _DAT_0003f964);
      DAT_00040c3c = (int)ROUND(param_1[3] * _DAT_0003f964);
      DAT_00040c40 = (int)ROUND(*extraout_ECX_01 * _DAT_0003f964);
      DAT_00040c44 = (int)ROUND(extraout_ECX_01[1] * _DAT_0003f964);
      DAT_00040c48 = (int)ROUND(extraout_ECX_01[2] * _DAT_0003f964);
      DAT_00040c4c = (int)ROUND(extraout_ECX_01[3] * _DAT_0003f964);
      DAT_00040c50 = (int)ROUND(*pfVar7 * _DAT_0003f964);
      DAT_00040c54 = (int)ROUND(pfVar7[1] * _DAT_0003f964);
      DAT_00040c58 = (int)ROUND(pfVar7[2] * _DAT_0003f964);
      DAT_00040c5c = (int)ROUND(pfVar7[3] * _DAT_0003f964);
      FUN_0002c7ec(&DAT_00040c30,3,param_2,iVar2);
      return;
    }
    _DAT_00040c60 = *param_1;
    _DAT_00040c70 = param_1[4];
    _DAT_00040c64 = param_1[1];
    _DAT_00040c68 = param_1[2];
    _DAT_00040c74 = *extraout_ECX_01;
    _DAT_00040c78 = extraout_ECX_01[1];
    _DAT_00040c7c = extraout_ECX_01[2];
    _DAT_00040c88 = *pfVar7;
    _DAT_00040c8c = pfVar7[1];
    _DAT_00040c90 = pfVar7[2];
    _DAT_00040c84 = extraout_ECX_01[4];
    _DAT_00040c98 = pfVar7[4];
    iVar5 = FUN_0002b634(&DAT_00040d50,&DAT_00040c60);
    if (2 < iVar5) {
      iVar8 = 0;
      if (0 < iVar5) {
        iVar9 = 0;
        piVar6 = &DAT_00040d5c;
        do {
          fVar4 = (*(float **)(iVar9 + DAT_00040d50))[1] * _DAT_0003f964;
          (&DAT_00040d54)[iVar8 * 4] =
               (int)ROUND(**(float **)(iVar9 + DAT_00040d50) * _DAT_0003f964);
          (&DAT_00040d58)[iVar8 * 4] = (int)ROUND(fVar4);
          piVar1 = (int *)(iVar9 + DAT_00040d50);
          iVar9 = iVar9 + 4;
          iVar8 = iVar8 + 1;
          fVar4 = *(float *)(*piVar1 + 0xc) * _DAT_0003f964;
          *piVar6 = (int)ROUND(*(float *)(*piVar1 + 8) * _DAT_0003f964);
          piVar6[1] = (int)ROUND(fVar4);
          piVar6 = piVar6 + 4;
        } while (iVar8 < iVar5);
      }
      FUN_0002c7ec(&DAT_00040d54,iVar5,param_2,iVar2);
      return;
    }
  }
  return;
}

