
int * FUN_00016031(int *param_1,char *param_2)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  char *pcVar4;
  byte bVar5;
  undefined8 uVar6;
  
  bVar5 = 0;
  if ((param_2 != (char *)0x0) && (*(int *)(*(int *)(*param_1 + 4) + 0x10 + (int)param_1) == 0)) {
    if ((*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 8) != 0) ||
       ((*(uint *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc) & 0x4000) != 0)) {
      uVar6 = FUN_000248e2();
      param_2 = (char *)((ulonglong)uVar6 >> 0x20);
      if ((int)uVar6 == 0) {
        return param_1;
      }
    }
    uVar3 = 0xffffffff;
    pcVar4 = param_2;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + (uint)bVar5 * -2 + 1;
    } while (cVar1 != '\0');
    uVar2 = FUN_00024938(param_1,param_2,~uVar3 - 1,0);
    FUN_00024c72(*(int *)(*param_1 + 4) + (int)param_1,uVar2);
    if ((*(uint *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc) & 0x2000) != 0) {
      FUN_000248a3(param_1);
    }
  }
  return param_1;
}

