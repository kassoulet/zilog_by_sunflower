
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001b687(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  int iVar8;
  int local_1c;
  
  iVar8 = param_1[1];
  iVar1 = param_1[7];
  iVar2 = param_1[6];
  for (local_1c = 0; local_1c < iVar2; local_1c = local_1c + 1) {
    iVar3 = *(int *)(local_1c * 0xc + iVar1);
    iVar4 = *(int *)(local_1c * 0xc + iVar1 + 4);
    fVar5 = *(float *)(iVar4 * 0xc + iVar8);
    fVar6 = *(float *)(iVar4 * 0xc + iVar8 + 4);
    iVar4 = *(int *)(local_1c * 0xc + iVar1 + 8);
    if ((*(float *)(iVar3 * 0xc + iVar8) - fVar5) * (*(float *)(iVar4 * 0xc + iVar8 + 4) - fVar6) -
        (*(float *)(iVar4 * 0xc + iVar8) - fVar5) * (*(float *)(iVar3 * 0xc + iVar8 + 4) - fVar6) <
        0.0) {
      uVar7 = *(undefined4 *)(local_1c * 0xc + iVar1);
      *(undefined4 *)(local_1c * 0xc + iVar1) = *(undefined4 *)(local_1c * 0xc + iVar1 + 4);
      *(undefined4 *)(local_1c * 0xc + iVar1 + 4) = uVar7;
    }
  }
  for (local_1c = 0; local_1c < *param_1; local_1c = local_1c + 1) {
    iVar8 = param_1[1] + local_1c * 0xc;
    *(float *)(iVar8 + 4) = *(float *)(iVar8 + 4) * (float)/*c*/1.03;
  }
  return;
}

