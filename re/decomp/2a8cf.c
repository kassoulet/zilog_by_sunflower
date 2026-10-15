
int FUN_0002a8cf(int param_1,int *param_2,int unaff_EBX)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined6 *puVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int extraout_ECX;
  int extraout_ECX_00;
  int iVar7;
  uint *puVar8;
  byte bVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  longlong lVar12;
  uint local_38;
  uint local_34 [4];
  int *local_24;
  int local_20;
  int local_1c;
  int local_14;
  
  bVar9 = 0;
  iVar7 = 0;
  local_38 = 0;
  local_34[0] = 0;
  local_1c = 0;
  local_20 = 0;
  local_24 = param_2;
  while( true ) {
    local_14 = FUN_00029e7c(param_1);
    if (((&DAT_0003fda0)[(byte)((char)local_14 + 1)] & 2) == 0) break;
    local_20 = local_20 + 1;
  }
  if ((*(byte *)(param_1 + 0x10) & 2) == 0) {
    iVar5 = *(int *)(param_1 + 0xc);
    *(int *)(param_1 + 0xc) = iVar5 + -1;
    if (iVar5 == 0) {
LAB_0002aba9:
      FUN_00029e83(local_14,param_1);
    }
    else {
      local_34[3] = 0x2b;
      if ((extraout_ECX != 0) && ((local_14 == 0x2b || (local_14 == 0x2d)))) {
        local_20 = local_20 + 1;
        local_34[3] = local_14;
        local_14 = FUN_0002acfb(param_1);
        if (local_14 == -1) goto LAB_0002abb4;
      }
      if (unaff_EBX == 0) {
        if (local_14 == 0x30) {
          iVar7 = 1;
          local_14 = FUN_0002acfb(param_1);
          if (local_14 == -1) goto LAB_0002abb4;
          if ((local_14 == 0x78) || (local_14 == 0x58)) {
            uVar10 = FUN_0002acfb(param_1,local_20);
            local_14 = (int)uVar10;
            iVar7 = 0;
            local_20 = (int)((ulonglong)uVar10 >> 0x20) + 2;
            if (local_14 == -1) goto LAB_0002abb4;
            unaff_EBX = 0x10;
          }
          else {
            unaff_EBX = 8;
          }
        }
        else {
          unaff_EBX = 10;
        }
      }
      else if ((unaff_EBX == 0x10) && (local_14 == 0x30)) {
        iVar7 = 1;
        local_14 = FUN_0002acfb(param_1);
        iVar5 = local_20;
        if (local_14 == -1) goto LAB_0002abb4;
        if ((local_14 == 0x78) || (local_14 == 0x58)) {
          local_14 = FUN_0002acfb(param_1);
          iVar7 = 0;
          local_20 = iVar5 + 2;
          if (local_14 == -1) goto LAB_0002abb4;
        }
      }
      if ((*(byte *)(param_1 + 0x10) & 0x40) == 0) {
        do {
          iVar5 = FUN_0002acd4(local_14);
          if (unaff_EBX <= iVar5) {
            if ((local_14 != 0x3a) || ((*(byte *)(param_1 + 0x10) & 0x80) == 0)) goto LAB_0002aba9;
            goto LAB_0002ab80;
          }
          iVar7 = iVar7 + 1;
          local_1c = local_1c * unaff_EBX + iVar5;
          local_14 = FUN_0002acfb(param_1);
        } while (local_14 != -1);
      }
      else {
        local_34[2] = 0;
        local_34[1] = unaff_EBX;
        do {
          uVar11 = FUN_0002acd4(local_14,unaff_EBX);
          lVar12 = CONCAT44(local_34[0],local_38);
          if ((int)(uVar11 >> 0x20) <= (int)uVar11) {
            if ((local_14 != 0x3a) || ((*(byte *)(param_1 + 0x10) & 0x80) == 0)) goto LAB_0002aba9;
            goto LAB_0002aad0;
          }
          lVar12 = FUN_0002f298(local_38,local_34[0],local_34[1],local_34[2]);
          lVar12 = lVar12 + (uVar11 & 0xffffffff);
          local_38 = (uint)lVar12;
          local_34[0] = (uint)((ulonglong)lVar12 >> 0x20);
          iVar7 = iVar7 + 1;
          local_14 = FUN_0002acfb(param_1);
        } while (local_14 != -1);
      }
    }
  }
LAB_0002abb4:
  if ((*(byte *)(param_1 + 0x10) & 0x40) == 0) {
    if (local_34[3] == 0x2d) {
      local_1c = -local_1c;
    }
    if (0 < iVar7) {
      bVar9 = *(byte *)(param_1 + 0x10);
      iVar7 = iVar7 + local_20;
      if ((bVar9 & 1) != 0) {
        if ((bVar9 & 4) == 0) {
          if ((bVar9 & 8) == 0) {
            puVar2 = (undefined4 *)*local_24;
            *local_24 = (int)(puVar2 + 1);
            piVar6 = (int *)*puVar2;
          }
          else {
            puVar2 = (undefined4 *)*local_24;
            *local_24 = (int)(puVar2 + 1);
            piVar6 = (int *)*puVar2;
          }
        }
        else {
          puVar3 = (undefined6 *)*local_24;
          *local_24 = (int)(puVar3 + 1);
          piVar6 = (int *)*puVar3;
        }
        if ((*(byte *)(param_1 + 0x10) & 0x10) == 0) {
          *piVar6 = local_1c;
        }
        else {
          *(short *)piVar6 = (short)local_1c;
        }
      }
    }
  }
  else {
    if (local_34[3] == 0x2d) {
      local_34[0] = ~local_34[0];
      local_38 = ~local_38 + 1;
      if (local_38 == 0) {
        local_34[0] = local_34[0] + 1;
      }
    }
    if (0 < iVar7) {
      bVar1 = *(byte *)(param_1 + 0x10);
      iVar7 = iVar7 + local_20;
      if ((bVar1 & 1) != 0) {
        if ((bVar1 & 4) == 0) {
          if ((bVar1 & 8) == 0) {
            puVar2 = (undefined4 *)*local_24;
            *local_24 = (int)(puVar2 + 1);
            puVar8 = (uint *)*puVar2;
          }
          else {
            puVar2 = (undefined4 *)*local_24;
            *local_24 = (int)(puVar2 + 1);
            puVar8 = (uint *)*puVar2;
          }
        }
        else {
          puVar2 = (undefined4 *)*local_24;
          *local_24 = (int)(puVar2 + 2);
          puVar8 = (uint *)*puVar2;
        }
        *puVar8 = local_38;
        puVar8[(uint)bVar9 * -2 + 1] = local_34[(uint)bVar9 * -2];
      }
    }
  }
  return iVar7;
LAB_0002ab80:
  iVar7 = iVar7 + 1;
  local_14 = FUN_0002acfb(param_1);
  if (local_14 == -1) goto LAB_0002abb4;
  iVar5 = FUN_0002acd4();
  if (extraout_ECX_00 <= iVar5) goto LAB_0002aba9;
  local_1c = local_1c * extraout_ECX_00 + iVar5;
  goto LAB_0002ab80;
LAB_0002aad0:
  local_34[0] = (uint)((ulonglong)lVar12 >> 0x20);
  local_38 = (uint)lVar12;
  iVar7 = iVar7 + 1;
  local_14 = FUN_0002acfb(param_1);
  if (local_14 == -1) goto LAB_0002abb4;
  uVar4 = FUN_0002acd4();
  if (unaff_EBX <= (int)uVar4) goto LAB_0002aba9;
  lVar12 = FUN_0002f298(local_38,local_34[0],local_34[1],local_34[2]);
  lVar12 = lVar12 + (ulonglong)uVar4;
  goto LAB_0002aad0;
}

