
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00026e28(int param_1,undefined4 param_2,undefined4 unaff_EBX)

{
  float *pfVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  float fVar6;
  undefined4 uVar7;
  int iVar8;
  int extraout_ECX;
  float *extraout_ECX_00;
  int iVar9;
  float *pfVar10;
  int iVar11;
  int *piVar12;
  undefined8 uVar13;
  int local_38;
  
  pfVar1 = (float *)(param_1 + 0x14);
  uVar7 = FUN_00025f70(param_1,param_1 + 0x28,unaff_EBX,param_1);
  *(undefined4 *)(extraout_ECX + 0x10) = uVar7;
  uVar13 = FUN_00025f70(pfVar1);
  *(int *)(param_1 + 0x24) = (int)uVar13;
  uVar13 = FUN_00025f70((int)((ulonglong)uVar13 >> 0x20));
  pfVar10 = (float *)((ulonglong)uVar13 >> 0x20);
  pfVar10[4] = (float)uVar13;
  if (((uint)extraout_ECX_00[4] & *(uint *)(param_1 + 0x24) & (uint)pfVar10[4]) == 0) {
    fVar6 = *(float *)(param_1 + 0x18) - pfVar10[1];
    dVar5 = (double)((*extraout_ECX_00 - *pfVar10) * fVar6 -
                    (*pfVar1 - *pfVar10) * (extraout_ECX_00[1] - pfVar10[1]));
    local_38 = SUB84(dVar5,0);
    if ((((ulonglong)dVar5 & 0x7fffffff00000000) != 0) || (local_38 != 0)) {
      dVar5 = (1.0 / dVar5) * /*c*/65536.0;
      iVar3 = (int)ROUND(((extraout_ECX_00[2] - pfVar10[2]) * fVar6 -
                         (*(float *)(param_1 + 0x1c) - pfVar10[2]) *
                         (extraout_ECX_00[1] - pfVar10[1])) * (float)dVar5);
      iVar4 = (int)ROUND(((*(float *)(param_1 + 0x18) - pfVar10[1]) *
                          (extraout_ECX_00[3] - pfVar10[3]) -
                         (extraout_ECX_00[1] - pfVar10[1]) *
                         (*(float *)(param_1 + 0x20) - pfVar10[3])) * (float)dVar5);
      if ((((uint)extraout_ECX_00[4] | *(uint *)(param_1 + 0x24) | (uint)pfVar10[4]) & 0xf) == 0) {
        DAT_00040e14 = (int)ROUND(*extraout_ECX_00 * _DAT_0003f964);
        DAT_00040e18 = (int)ROUND(extraout_ECX_00[1] * _DAT_0003f964);
        DAT_00040e1c = (int)ROUND(extraout_ECX_00[2] * _DAT_0003f964);
        DAT_00040e20 = (int)ROUND(extraout_ECX_00[3] * _DAT_0003f964);
        DAT_00040e24 = (int)ROUND(*pfVar1 * _DAT_0003f964);
        DAT_00040e28 = (int)ROUND(*(float *)(param_1 + 0x18) * _DAT_0003f964);
        DAT_00040e2c = (int)ROUND(*(float *)(param_1 + 0x1c) * _DAT_0003f964);
        DAT_00040e30 = (int)ROUND(*(float *)(param_1 + 0x20) * _DAT_0003f964);
        DAT_00040e34 = (int)ROUND(*pfVar10 * _DAT_0003f964);
        DAT_00040e38 = (int)ROUND(pfVar10[1] * _DAT_0003f964);
        DAT_00040e3c = (int)ROUND(pfVar10[2] * _DAT_0003f964);
        DAT_00040e40 = (int)ROUND(pfVar10[3] * _DAT_0003f964);
        FUN_0002cc2c(&DAT_00040e14,3,param_2,unaff_EBX,iVar3,iVar4);
        return;
      }
      _DAT_00040e44 = *extraout_ECX_00;
      _DAT_00040e54 = extraout_ECX_00[4];
      _DAT_00040e48 = extraout_ECX_00[1];
      _DAT_00040e4c = extraout_ECX_00[2];
      _DAT_00040e50 = extraout_ECX_00[3];
      _DAT_00040e58 = *pfVar1;
      _DAT_00040e5c = *(undefined4 *)(param_1 + 0x18);
      _DAT_00040e60 = *(undefined4 *)(param_1 + 0x1c);
      _DAT_00040e64 = *(undefined4 *)(param_1 + 0x20);
      _DAT_00040e6c = *pfVar10;
      _DAT_00040e70 = pfVar10[1];
      _DAT_00040e74 = pfVar10[2];
      _DAT_00040e78 = pfVar10[3];
      _DAT_00040e68 = *(uint *)(param_1 + 0x24);
      _DAT_00040e7c = pfVar10[4];
      iVar8 = FUN_0002ad90(&DAT_00040f34,&DAT_00040e44);
      if (2 < iVar8) {
        iVar9 = 0;
        if (0 < iVar8) {
          iVar11 = 0;
          piVar12 = &DAT_00040f40;
          do {
            fVar6 = (*(float **)(iVar11 + DAT_00040f34))[1] * _DAT_0003f964;
            (&DAT_00040f38)[iVar9 * 4] =
                 (int)ROUND(**(float **)(iVar11 + DAT_00040f34) * _DAT_0003f964);
            (&DAT_00040f3c)[iVar9 * 4] = (int)ROUND(fVar6);
            piVar2 = (int *)(iVar11 + DAT_00040f34);
            iVar11 = iVar11 + 4;
            iVar9 = iVar9 + 1;
            fVar6 = *(float *)(*piVar2 + 0xc) * _DAT_0003f964;
            *piVar12 = (int)ROUND(*(float *)(*piVar2 + 8) * _DAT_0003f964);
            piVar12[1] = (int)ROUND(fVar6);
            piVar12 = piVar12 + 4;
          } while (iVar9 < iVar8);
        }
        FUN_0002cc2c(&DAT_00040f38,iVar8,param_2,unaff_EBX,iVar3,iVar4);
        return;
      }
    }
  }
  return;
}

