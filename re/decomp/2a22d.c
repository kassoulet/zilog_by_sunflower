
int FUN_0002a22d(int param_1,int *param_2)

{
  byte bVar1;
  undefined6 *puVar2;
  undefined4 *puVar3;
  byte bVar4;
  int iVar5;
  int extraout_ECX;
  int extraout_ECX_00;
  int iVar6;
  byte *unaff_ESI;
  int iVar7;
  undefined1 local_20 [4];
  byte local_1c;
  undefined1 local_1b;
  
  if ((*(byte *)(param_1 + 0x10) & 1) != 0) {
    if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
      if ((*(byte *)(param_1 + 0x10) & 8) == 0) {
        puVar3 = (undefined4 *)*param_2;
        *param_2 = (int)(puVar3 + 1);
        unaff_ESI = (byte *)*puVar3;
      }
      else {
        puVar3 = (undefined4 *)*param_2;
        *param_2 = (int)(puVar3 + 1);
        unaff_ESI = (byte *)*puVar3;
      }
    }
    else {
      puVar2 = (undefined6 *)*param_2;
      *param_2 = (int)(puVar2 + 1);
      unaff_ESI = (byte *)*puVar2;
    }
  }
  iVar7 = *(int *)(param_1 + 0xc);
  iVar6 = 0;
  if (iVar7 == -1) {
    iVar7 = 1;
  }
  while( true ) {
    if (iVar7 < 1) {
      return iVar6;
    }
    bVar4 = FUN_00029e7c(param_1);
    bVar1 = *(byte *)(extraout_ECX + 0x10);
    if ((bVar1 & 2) != 0) break;
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 + -1;
    param_1 = extraout_ECX;
    if ((bVar1 & 1) != 0) {
      if ((bVar1 & 0x20) == 0) {
        *unaff_ESI = bVar4;
        unaff_ESI = unaff_ESI + 1;
      }
      else {
        local_1c = bVar4;
        if ((DAT_00041490 != 0) && (((&DAT_00041495)[bVar4] & 1) != 0)) {
          local_1b = FUN_00029e7c(extraout_ECX);
        }
        iVar5 = FUN_0002f18b(local_20,&local_1c,2);
        if (iVar5 == -1) {
          return 0;
        }
        *(short *)unaff_ESI = local_20._0_2_;
        unaff_ESI = unaff_ESI + 2;
        param_1 = extraout_ECX_00;
      }
    }
  }
  return iVar6;
}

