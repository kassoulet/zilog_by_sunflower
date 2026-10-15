
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001c34e(int *param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  int local_1c;
  
  pfVar1 = (float *)param_1[0x11];
  local_2c = *pfVar1;
  local_24 = pfVar1[1];
  local_28 = local_2c;
  local_20 = local_24;
  for (local_1c = 0; local_1c < *param_1; local_1c = local_1c + 1) {
    fVar2 = pfVar1[local_1c * 2];
    fVar3 = pfVar1[local_1c * 2 + 1];
    if (fVar2 < local_2c) {
      local_2c = fVar2;
    }
    if (local_28 < fVar2) {
      local_28 = fVar2;
    }
    if (fVar3 < local_24) {
      local_24 = fVar3;
    }
    if (local_20 < fVar3) {
      local_20 = fVar3;
    }
  }
  if (local_2c < 0.0) {
    local_2c = 0.0;
  }
  if (0x439f8000 < (int)local_28) {
    local_28 = 319.0;
  }
  if (local_24 < 0.0) {
    local_24 = 0.0;
  }
  if (0x43470000 < (int)local_20) {
    local_20 = 199.0;
  }
  _DAT_00040358 = local_2c;
  _DAT_0004035c = local_28;
  _DAT_00040360 = local_24;
  _DAT_00040364 = local_20;
  return;
}

