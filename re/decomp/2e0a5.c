
undefined8 FUN_0002e0a5(int param_1,int *param_2,int unaff_EBX)

{
  double *pdVar1;
  int iVar2;
  byte bVar3;
  int extraout_ECX;
  int extraout_EDX;
  int iVar4;
  undefined2 in_DS;
  int local_50 [4];
  undefined4 local_40;
  int local_3c;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  longdouble local_24;
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_50[3] = (int)*(byte *)(unaff_EBX + 0x15);
  local_50[0] = *(int *)(unaff_EBX + 8);
  bVar3 = *(byte *)(unaff_EBX + 0x15) & 0x5f;
  if (bVar3 == 0x47) {
    if (local_50[0] == 0) {
      local_50[0] = 1;
    }
    local_50[2] = 4;
    local_50[3] = local_50[3] - 2;
    local_50[1] = 1;
  }
  else if (bVar3 == 0x45) {
    local_50[2] = 1;
    local_50[1] = 1;
  }
  else {
    local_50[2] = 2;
    local_50[1] = 0;
  }
  if ((*(byte *)(unaff_EBX + 0x1e) & 1) != 0) {
    local_50[2] = local_50[2] | 0x10;
  }
  pdVar1 = (double *)*param_2;
  *param_2 = (int)(pdVar1 + 1);
  local_18 = *(undefined4 *)pdVar1;
  uStack_14 = *(undefined4 *)((int)pdVar1 + 4);
  local_24 = (longdouble)*pdVar1;
  if (local_50[0] == -1) {
    local_50[0] = 6;
  }
  local_40 = 0;
  FUN_000278a1(&local_24,local_50,param_1 + 1);
  *(undefined4 *)(extraout_ECX + 0x28) = local_34;
  *(undefined4 *)(extraout_ECX + 0x2c) = local_30;
  *(undefined4 *)(extraout_ECX + 0x30) = local_2c;
  *(undefined4 *)(extraout_ECX + 0x34) = local_28;
  if (local_3c < 0) {
    iVar2 = *(int *)(extraout_ECX + 0x20);
    iVar4 = iVar2 + 1;
    *(int *)(extraout_ECX + 0x20) = iVar4;
    *(undefined1 *)(param_1 + iVar2) = 0x2d;
  }
  else if ((*(byte *)(extraout_ECX + 0x1e) & 4) == 0) {
    iVar4 = extraout_EDX;
    if ((*(byte *)(extraout_ECX + 0x1e) & 2) != 0) {
      iVar2 = *(int *)(extraout_ECX + 0x20);
      iVar4 = iVar2 + 1;
      *(int *)(extraout_ECX + 0x20) = iVar4;
      *(undefined1 *)(param_1 + iVar2) = 0x20;
    }
  }
  else {
    iVar2 = *(int *)(extraout_ECX + 0x20);
    iVar4 = iVar2 + 1;
    *(int *)(extraout_ECX + 0x20) = iVar4;
    *(undefined1 *)(param_1 + iVar2) = 0x2b;
  }
  return CONCAT44(CONCAT22((short)((uint)iVar4 >> 0x10),in_DS),param_1);
}

