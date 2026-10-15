
int * FUN_000174fe(int param_1,byte param_2,int unaff_EBX)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  byte local_38;
  int local_24;
  int local_20;
  int local_1c;
  undefined1 local_18;
  
  piVar2 = (int *)FUN_00024c8f(0x1c);
  FUN_00017e46(piVar2,0,0x1c);
  piVar2[1] = *(int *)(param_1 + 4);
  piVar2[2] = *(int *)(param_1 + 8);
  piVar2[4] = (uint)param_2;
  piVar2[3] = unaff_EBX;
  *piVar2 = param_1 + 0x16;
  iVar3 = thunk_FUN_00024c8f(unaff_EBX);
  piVar2[6] = iVar3;
  iVar3 = thunk_FUN_00024c8f(unaff_EBX * 2);
  piVar2[5] = iVar3;
  local_1c = 0;
  sVar1 = 0;
  for (local_24 = 0; local_24 < piVar2[1]; local_24 = local_24 + 1) {
    local_38 = 0;
    for (local_20 = 0; local_20 < piVar2[2]; local_20 = local_20 + 1) {
      local_38 = local_38 | *(byte *)(*piVar2 + piVar2[1] * local_20 + local_24);
    }
    if (local_38 == 0) {
      *(short *)(piVar2[5] + local_1c * 2) = (short)local_24 - sVar1;
      local_18 = (undefined1)sVar1;
      *(undefined1 *)(local_1c + piVar2[6]) = local_18;
      sVar1 = 0;
      local_1c = local_1c + 1;
    }
    sVar1 = sVar1 + 1;
  }
  return piVar2;
}

