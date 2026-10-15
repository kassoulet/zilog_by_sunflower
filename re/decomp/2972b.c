
int * FUN_0002972b(int *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  byte bVar6;
  char local_30 [16];
  int local_20;
  int local_1c;
  int local_18;
  
  bVar6 = 0;
  local_18 = FUN_000296a3(*(undefined4 *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc));
  if (((param_2 == 0) || ((*(uint *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc) & 0x400) == 0)) ||
     (local_18 != 10)) {
    local_20 = 0;
  }
  else {
    local_30[0] = '+';
    local_20 = 1;
  }
  FUN_0002edc9(param_2 == 0,local_30,&local_20,local_18,
               *(undefined4 *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc));
  local_1c = local_20;
  FUN_000296c7(param_2,local_30 + local_20,local_18);
  if ((*(uint *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc) & 0x200) != 0) {
    FUN_0002ee16(local_30);
  }
  uVar4 = 0xffffffff;
  pcVar5 = local_30;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + (uint)bVar6 * -2 + 1;
  } while (cVar1 != '\0');
  local_20 = ~uVar4 - 1;
  if (*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 0x10) == 0) {
    if (((*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 8) != 0) ||
        ((*(uint *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc) & 0x4000) != 0)) &&
       (iVar2 = FUN_000248e2(param_1), iVar2 == 0)) {
      return param_1;
    }
    uVar3 = FUN_00024938(param_1,local_30,local_20,local_1c);
    FUN_00024c72(*(int *)(*param_1 + 4) + (int)param_1,uVar3);
    if ((*(uint *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc) & 0x2000) != 0) {
      FUN_000248a3(param_1);
    }
  }
  return param_1;
}

