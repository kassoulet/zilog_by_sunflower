
int FUN_0002a5f9(int param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  undefined6 *puVar3;
  undefined4 *puVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int *piVar9;
  char *pcVar10;
  int iVar11;
  char local_84;
  char local_83 [79];
  int local_34;
  int local_30;
  int *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  
  pcVar8 = &local_84;
  iVar11 = 0;
  local_1c = 0;
  local_2c = param_2;
  while( true ) {
    iVar6 = FUN_00029e7c(param_1);
    iVar7 = local_1c;
    if (((&DAT_0003fda0)[(byte)((char)iVar6 + 1)] & 2) == 0) break;
    local_1c = local_1c + 1;
  }
  if ((*(byte *)(param_1 + 0x10) & 2) != 0) goto LAB_0002a812;
  iVar2 = *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0xc) = iVar2 + -1;
  pcVar8 = &local_84;
  if (iVar2 != 0) {
    if ((iVar6 == 0x2b) || (pcVar8 = &local_84, iVar6 == 0x2d)) {
      local_84 = (char)iVar6;
      iVar6 = FUN_0002acfb(param_1);
      pcVar8 = local_83;
      local_1c = iVar7 + 1;
      if (iVar6 == -1) goto LAB_0002a812;
    }
    if ((((&DAT_0003fda0)[(byte)((char)iVar6 + 1)] & 0x20) != 0) || (iVar6 == 0x2e)) {
      local_20._0_2_ = 0;
      local_20._2_2_ = 0;
      bVar5 = false;
      if (((&DAT_0003fda0)[(byte)((char)iVar6 + 1)] & 0x20) != 0) {
        bVar5 = true;
        do {
          *pcVar8 = (char)iVar6;
          pcVar8 = pcVar8 + 1;
          if ((*(byte *)(param_1 + 0x10) & 0x10) != 0) {
            local_20._2_2_ = (short)iVar6 + local_20._2_2_ * 10 + -0x30;
          }
          iVar11 = iVar11 + 1;
          iVar6 = FUN_0002acfb(param_1);
          if (iVar6 == -1) goto LAB_0002a812;
        } while (((&DAT_0003fda0)[(byte)((char)iVar6 + 1)] & 0x20) != 0);
      }
      pcVar10 = pcVar8;
      iVar7 = iVar11;
      if (iVar6 == 0x2e) {
        *pcVar8 = '.';
        iVar6 = FUN_0002acfb(param_1);
        pcVar8 = pcVar8 + 1;
        if (iVar6 == -1) goto LAB_0002a812;
        if ((!bVar5) && (((&DAT_0003fda0)[(byte)((char)iVar6 + 1)] & 0x20) == 0)) goto LAB_0002a809;
        iVar11 = iVar11 + 1;
        do {
          if (((&DAT_0003fda0)[(byte)((char)iVar6 + 1)] & 0x20) == 0) break;
          iVar11 = iVar11 + 1;
          *pcVar8 = (char)iVar6;
          iVar6 = FUN_0002acfb(param_1);
          pcVar8 = pcVar8 + 1;
        } while (iVar6 != -1);
        if ((*(byte *)(param_1 + 0x10) & 0x10) != 0) {
          local_24 = 0;
          pcVar10 = pcVar8;
          while( true ) {
            pcVar10 = pcVar10 + -1;
            local_20._0_2_ = (undefined2)local_24;
            if (*pcVar10 == '.') break;
            local_28 = 10;
            local_24 = (uint)CONCAT12(*pcVar10 + -0x30,(undefined2)local_24);
            local_24 = local_24 / 10;
          }
        }
        pcVar10 = pcVar8;
        iVar7 = iVar11;
        if (iVar6 == -1) goto LAB_0002a812;
      }
      pcVar8 = pcVar10;
      iVar11 = iVar7;
      if (((*(byte *)(param_1 + 0x10) & 0x10) == 0) && ((iVar6 == 0x65 || (iVar6 == 0x45)))) {
        iVar11 = iVar7 + 1;
        *pcVar10 = (char)iVar6;
        iVar6 = FUN_0002acfb(param_1);
        pcVar8 = pcVar10 + 1;
        if (iVar6 == -1) goto LAB_0002a812;
        if ((iVar6 == 0x2b) || (iVar6 == 0x2d)) {
          iVar11 = iVar7 + 2;
          *pcVar8 = (char)iVar6;
          iVar6 = FUN_0002acfb(param_1);
          pcVar8 = pcVar10 + 2;
          if (iVar6 == -1) goto LAB_0002a812;
        }
        if (((&DAT_0003fda0)[(byte)((char)iVar6 + 1)] & 0x20) == 0) {
          iVar11 = 0;
        }
        else {
          do {
            iVar11 = iVar11 + 1;
            *pcVar8 = (char)iVar6;
            iVar6 = FUN_0002acfb(param_1);
            pcVar8 = pcVar8 + 1;
            if (iVar6 == -1) goto LAB_0002a812;
          } while (((&DAT_0003fda0)[(byte)((char)iVar6 + 1)] & 0x20) != 0);
        }
      }
    }
  }
LAB_0002a809:
  FUN_00029e83(iVar6,param_1);
LAB_0002a812:
  if ((0 < iVar11) && (iVar11 = iVar11 + local_1c, (*(byte *)(param_1 + 0x10) & 1) != 0)) {
    *pcVar8 = '\0';
    iVar7 = CONCAT22(local_20._2_2_,(undefined2)local_20);
    if ((*(byte *)(param_1 + 0x10) & 0x10) == 0) {
      (*(code *)PTR_FUN_0003fd0c)(&local_84,&local_34);
      iVar7 = CONCAT22(local_20._2_2_,(undefined2)local_20);
    }
    else if (local_84 == '-') {
      iVar7 = -CONCAT22(local_20._2_2_,(undefined2)local_20);
    }
    if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
      if ((*(byte *)(param_1 + 0x10) & 8) == 0) {
        puVar4 = (undefined4 *)*local_2c;
        *local_2c = (int)(puVar4 + 1);
        piVar9 = (int *)*puVar4;
      }
      else {
        puVar4 = (undefined4 *)*local_2c;
        *local_2c = (int)(puVar4 + 1);
        piVar9 = (int *)*puVar4;
      }
    }
    else {
      puVar3 = (undefined6 *)*local_2c;
      *local_2c = (int)(puVar3 + 1);
      piVar9 = (int *)*puVar3;
    }
    bVar1 = *(byte *)(param_1 + 0x10);
    if ((bVar1 & 0x10) == 0) {
      if (((bVar1 & 0x20) != 0) || ((bVar1 & 0x40) != 0)) {
        *piVar9 = local_34;
        piVar9[1] = local_30;
        return iVar11;
      }
      local_20 = iVar7;
      iVar7 = FUN_0002f24c(local_34,local_30);
    }
    *piVar9 = iVar7;
  }
  return iVar11;
}

