
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001870b(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  undefined4 uVar6;
  byte bVar7;
  float local_40;
  int *local_3c;
  float local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  float local_20;
  int local_1c;
  
  bVar7 = 0;
  local_3c = param_1;
  if (*(int *)(*param_1 + 0x50) == 0) {
    uVar6 = thunk_FUN_00024c8f(*(int *)*param_1 << 2);
    *(undefined4 *)(*local_3c + 0x50) = uVar6;
  }
  local_28 = *(int *)(*local_3c + 0x50);
  local_38 = (float)local_3c[3];
  local_20 = (float)local_3c[4];
  local_34 = *(int *)*local_3c;
  local_30 = *(int *)(*local_3c + 0x44);
  local_2c = *(int *)(*local_3c + 8);
  fVar1 = (float)local_3c[1];
  (&local_40)[(uint)bVar7 * -2] = (float)local_3c[(uint)bVar7 * -2 + 2];
  if (*(int *)(*local_3c + 0xc) == 0) {
    for (local_1c = 0; local_1c < local_34; local_1c = local_1c + 1) {
      fVar2 = *(float *)(local_1c * 0xc + local_2c);
      fVar3 = *(float *)(local_1c * 0xc + local_2c + 4);
      fVar5 = 1.0 / (*(float *)(local_1c * 0xc + local_2c + 8) / local_20 + local_38);
      *(float *)(local_1c * 4 + local_28) = fVar5;
      *(float *)(local_1c * 8 + local_30) = fVar2 * fVar5 + fVar1;
      *(float *)(local_1c * 8 + local_30 + 4) = local_40 + fVar3 * fVar5 * (float)/*c*/0.83;
    }
  }
  else {
    iVar4 = *(int *)(*local_3c + 0xc);
    for (local_1c = 0; local_1c < local_34; local_1c = local_1c + 1) {
      if (*(char *)(iVar4 + local_1c) != '\0') {
        fVar2 = *(float *)(local_1c * 0xc + local_2c);
        fVar3 = *(float *)(local_1c * 0xc + local_2c + 4);
        fVar5 = 1.0 / (*(float *)(local_1c * 0xc + local_2c + 8) / local_20 + local_38);
        *(float *)(local_1c * 4 + local_28) = fVar5;
        *(float *)(local_1c * 8 + local_30) = fVar2 * fVar5 + fVar1;
        *(float *)(local_1c * 8 + local_30 + 4) = local_40 + fVar3 * fVar5 * (float)/*c*/0.83;
      }
    }
  }
  return;
}

