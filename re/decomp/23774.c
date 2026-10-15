
int * FUN_00023774(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  char *pcVar5;
  byte bVar6;
  char local_2c [24];
  
  bVar6 = 0;
  FUN_00017e46(local_2c,0,0x18);
  FUN_000273da(local_2c,param_2,*(undefined4 *)((int)param_1 + *(int *)(*param_1 + 4) + 0x18),
               *(undefined4 *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc));
  if ((local_2c[0] == '-') || (local_2c[0] == '+')) {
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  if (*(int *)(*(int *)(*param_1 + 4) + 0x10 + (int)param_1) == 0) {
    if (((*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 8) != 0) ||
        ((*(uint *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc) & 0x4000) != 0)) &&
       (iVar2 = FUN_000248e2(), iVar2 == 0)) {
      return param_1;
    }
    uVar3 = 0xffffffff;
    pcVar5 = local_2c;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + (uint)bVar6 * -2 + 1;
    } while (cVar1 != '\0');
    uVar4 = FUN_00024938(param_1,local_2c,~uVar3 - 1,uVar4);
    FUN_00024c72(*(int *)(*param_1 + 4) + (int)param_1,uVar4);
    if ((*(uint *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc) & 0x2000) != 0) {
      FUN_000248a3(param_1);
    }
  }
  return param_1;
}

