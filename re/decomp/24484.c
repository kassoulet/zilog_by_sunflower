
int * FUN_00024484(int *param_1,undefined4 param_2,undefined4 unaff_EBX)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_ECX;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  byte bVar8;
  longlong lVar9;
  char local_20 [16];
  
  bVar8 = 0;
  lVar9 = FUN_000296a3(*(undefined4 *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc),param_2,
                       unaff_EBX,param_2);
  if ((int)lVar9 == 10) {
    if ((lVar9 < 0x100000000) ||
       ((*(uint *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc) & 0x400) == 0)) {
      iVar6 = 0;
    }
    else {
      local_20[0] = '+';
      iVar6 = 1;
    }
    FUN_00029710(extraout_ECX,local_20 + iVar6);
    if (local_20[0] == '-') {
      iVar6 = 1;
    }
    uVar4 = 0xffffffff;
    pcVar7 = local_20;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + (uint)bVar8 * -2 + 1;
    } while (cVar1 != '\0');
    if ((*(int *)(*(int *)(*param_1 + 4) + 0x10 + (int)param_1) == 0) &&
       (((uVar5 = *(int *)(*param_1 + 4) + (int)param_1, *(int *)(uVar5 + 8) == 0 &&
         (uVar5 = *(uint *)(uVar5 + 0xc), (uVar5 & 0x4000) == 0)) ||
        (iVar2 = FUN_000248e2(param_1,uVar5,~uVar4 - 1), iVar2 != 0)))) {
      uVar3 = FUN_00024938(param_1,local_20,~uVar4 - 1,iVar6);
      FUN_00024c72(*(int *)(*param_1 + 4) + (int)param_1,uVar3);
      if ((*(uint *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc) & 0x2000) != 0) {
        FUN_000248a3(param_1);
      }
    }
  }
  else {
    param_1 = (int *)FUN_0002972b(param_1,(int)((ulonglong)lVar9 >> 0x20),(int)lVar9);
  }
  return param_1;
}

