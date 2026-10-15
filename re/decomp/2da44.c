
undefined8 FUN_0002da44(byte *param_1,int *param_2,int unaff_EBX)

{
  byte bVar1;
  uint *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined2 *puVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  int extraout_ECX;
  undefined4 extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  int extraout_ECX_03;
  int extraout_ECX_04;
  int extraout_ECX_05;
  int extraout_ECX_06;
  int extraout_ECX_07;
  int extraout_ECX_08;
  int extraout_ECX_09;
  undefined2 extraout_var;
  int *extraout_EDX;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 uVar9;
  int *extraout_EDX_00;
  undefined2 extraout_var_04;
  undefined2 extraout_var_05;
  undefined4 uVar10;
  uint uVar11;
  short in_DS;
  short sVar12;
  bool bVar13;
  undefined8 uVar14;
  uint local_20;
  undefined2 local_1c;
  undefined1 uStack_1a;
  byte bStack_19;
  undefined4 local_18;
  byte local_14;
  byte local_13;
  
  *(undefined4 *)(unaff_EBX + 0x20) = 0;
  *(undefined4 *)(unaff_EBX + 0x24) = 0;
  *(undefined4 *)(unaff_EBX + 0x28) = 0;
  *(undefined4 *)(unaff_EBX + 0x2c) = 0;
  *(undefined4 *)(unaff_EBX + 0x30) = 0;
  bVar1 = *(byte *)(unaff_EBX + 0x15);
  *(undefined4 *)(unaff_EBX + 0x34) = 0;
  if (bVar1 < 0x69) {
    local_18 = CONCAT22(local_18._2_2_,(short)local_18);
    if (0x57 < bVar1) {
      if (bVar1 < 0x59) goto LAB_0002dab2;
      local_18 = CONCAT22(local_18._2_2_,(short)local_18);
      if (bVar1 == 100) goto LAB_0002db12;
    }
  }
  else if (bVar1 < 0x6a) {
LAB_0002db12:
    if ((*(byte *)(unaff_EBX + 0x1f) & 1) == 0) {
      if ((*(byte *)(unaff_EBX + 0x1e) & 0x20) == 0) {
        puVar4 = (undefined4 *)*param_2;
        *param_2 = (int)(puVar4 + 1);
        uVar10 = *puVar4;
        local_18._0_2_ = (short)uVar10;
        local_18._2_2_ = (short)((uint)uVar10 >> 0x10);
        if ((*(byte *)(unaff_EBX + 0x1e) & 0x10) == 0) goto LAB_0002db68;
        iVar6 = (int)(short)local_18;
      }
      else {
        piVar3 = (int *)*param_2;
        *param_2 = (int)(piVar3 + 1);
        iVar6 = *piVar3;
      }
      local_18._0_2_ = (short)iVar6;
      local_18._2_2_ = (short)((uint)iVar6 >> 0x10);
    }
    else {
      puVar2 = (uint *)*param_2;
      *param_2 = (int)(puVar2 + 1);
      local_20 = *puVar2;
      puVar4 = (undefined4 *)*param_2;
      *param_2 = (int)(puVar4 + 1);
      uVar10 = *puVar4;
      local_1c = (undefined2)uVar10;
      uStack_1a = (undefined1)((uint)uVar10 >> 0x10);
      bStack_19 = (byte)((uint)uVar10 >> 0x18);
    }
LAB_0002db68:
    if ((*(byte *)(unaff_EBX + 0x1f) & 1) == 0) {
      if (-1 < local_18._2_2_) goto LAB_0002dbca;
    }
    else if ((bStack_19 & 0x80) == 0) {
LAB_0002dbca:
      if ((*(byte *)(unaff_EBX + 0x1e) & 4) == 0) {
        local_18 = CONCAT22(local_18._2_2_,(short)local_18);
        if ((*(byte *)(unaff_EBX + 0x1e) & 2) != 0) {
          iVar6 = *(int *)(unaff_EBX + 0x20);
          *(int *)(unaff_EBX + 0x20) = iVar6 + 1;
          param_1[iVar6] = 0x20;
          local_18 = CONCAT22(local_18._2_2_,(short)local_18);
        }
      }
      else {
        iVar6 = *(int *)(unaff_EBX + 0x20);
        *(int *)(unaff_EBX + 0x20) = iVar6 + 1;
        param_1[iVar6] = 0x2b;
        local_18 = CONCAT22(local_18._2_2_,(short)local_18);
      }
      goto LAB_0002dbf1;
    }
    iVar6 = *(int *)(unaff_EBX + 0x20);
    *(int *)(unaff_EBX + 0x20) = iVar6 + 1;
    param_1[iVar6] = 0x2d;
    if ((*(byte *)(unaff_EBX + 0x1f) & 1) == 0) {
      local_18 = -CONCAT22(local_18._2_2_,(short)local_18);
    }
    else {
      uVar11 = ~CONCAT13(bStack_19,CONCAT12(uStack_1a,local_1c));
      local_20 = ~local_20 + 1;
      if (local_20 == 0) {
        uVar11 = uVar11 + 1;
      }
LAB_0002dacf:
      local_1c = (undefined2)uVar11;
      uStack_1a = (undefined1)(uVar11 >> 0x10);
      bStack_19 = (byte)(uVar11 >> 0x18);
      local_18 = CONCAT22(local_18._2_2_,(short)local_18);
    }
  }
  else {
    if (bVar1 < 0x75) {
      bVar13 = bVar1 == 0x6f;
    }
    else {
      if (bVar1 < 0x76) goto LAB_0002dab2;
      bVar13 = bVar1 == 0x78;
    }
    if (bVar13) {
LAB_0002dab2:
      if ((*(byte *)(unaff_EBX + 0x1f) & 1) != 0) {
        puVar2 = (uint *)*param_2;
        *param_2 = (int)(puVar2 + 1);
        local_20 = *puVar2;
        puVar2 = (uint *)*param_2;
        *param_2 = (int)(puVar2 + 1);
        uVar11 = *puVar2;
        goto LAB_0002dacf;
      }
      if ((*(byte *)(unaff_EBX + 0x1e) & 0x20) == 0) {
        puVar2 = (uint *)*param_2;
        *param_2 = (int)(puVar2 + 1);
        local_18 = *puVar2;
        if ((*(byte *)(unaff_EBX + 0x1e) & 0x10) != 0) {
          local_18 = local_18 & 0xffff;
        }
      }
      else {
        puVar2 = (uint *)*param_2;
        *param_2 = (int)(puVar2 + 1);
        local_18 = *puVar2;
      }
    }
  }
LAB_0002dbf1:
  bVar1 = *(byte *)(unaff_EBX + 0x15);
  uVar10 = 10;
  if (bVar1 < 100) {
    if (bVar1 < 0x47) {
      if (bVar1 < 0x45) {
        if (bVar1 == 0x43) {
          puVar5 = (undefined2 *)*param_2;
          *param_2 = (int)(puVar5 + 2);
          iVar7 = FUN_0002f440(param_1,*puVar5,10);
          uVar14 = CONCAT44(iVar7,iVar7);
          iVar6 = extraout_ECX_09;
          if (iVar7 == -1) {
            *(undefined4 *)(extraout_ECX_09 + 0x20) = 0;
            param_2 = (int *)0xffffffff;
            goto LAB_0002dfd4;
          }
LAB_0002df1d:
          param_2 = (int *)((ulonglong)uVar14 >> 0x20);
          *(int *)(iVar6 + 0x20) = (int)uVar14;
          goto LAB_0002dfd4;
        }
        goto LAB_0002dfc1;
      }
      if (0x45 < bVar1) {
LAB_0002dca6:
        if ((*(byte *)(unaff_EBX + 0x1e) & 0x10) != 0) {
          puVar4 = (undefined4 *)*param_2;
          *param_2 = (int)(puVar4 + 1);
          uVar10 = *puVar4;
          local_18._0_2_ = (short)uVar10;
          local_18._2_2_ = (short)((uint)uVar10 >> 0x10);
          sVar12 = in_DS;
          FUN_0002d8c7(param_1,uVar10,unaff_EBX);
          uVar14 = FUN_0002d7dc(param_1,CONCAT22(extraout_var,sVar12),0xffffffff);
          param_2 = (int *)((ulonglong)uVar14 >> 0x20);
          *(int *)(extraout_ECX + 0x28) = (int)uVar14;
          goto LAB_0002dfd4;
        }
      }
    }
    else if (0x47 < bVar1) {
      if (bVar1 < 0x53) {
        bVar13 = bVar1 == 0x50;
LAB_0002dc34:
        if (bVar13) {
          if (*(int *)(unaff_EBX + 4) == 0) {
            if ((*(byte *)(unaff_EBX + 0x1e) & 0x80) == 0) {
              *(undefined4 *)(unaff_EBX + 4) = 8;
            }
            else {
              *(undefined4 *)(unaff_EBX + 4) = 0xd;
            }
          }
          *(byte *)(unaff_EBX + 0x1e) = *(byte *)(unaff_EBX + 0x1e) & 0xf9;
          puVar4 = (undefined4 *)*param_2;
          *param_2 = (int)(puVar4 + 1);
          uVar10 = *puVar4;
          pbVar8 = param_1;
          if ((*(byte *)(unaff_EBX + 0x1e) & 0x80) != 0) {
            *param_2 = (int)(puVar4 + 2);
            FUN_0002d869(puVar4[1] & 0xffff,param_1,4);
            param_1[4] = 0x3a;
            pbVar8 = param_1 + 5;
          }
          FUN_0002d869(uVar10,pbVar8,8);
          uVar9 = extraout_var_04;
          if (*(char *)(extraout_ECX_06 + 0x15) == 'P') {
            FUN_0002dfe0(param_1);
            uVar9 = extraout_var_05;
          }
          uVar14 = FUN_0002d7dc(param_1,CONCAT22(uVar9,in_DS),0xffffffff);
          iVar6 = extraout_ECX_07;
          goto LAB_0002df1d;
        }
        goto LAB_0002dfc1;
      }
      if (bVar1 < 0x54) {
LAB_0002dcf7:
        *param_1 = 0;
        if ((*(byte *)(unaff_EBX + 0x1e) & 0x80) == 0) {
          if ((*(byte *)(unaff_EBX + 0x1e) & 0x40) == 0) {
            puVar4 = (undefined4 *)*param_2;
            *param_2 = (int)(puVar4 + 1);
            pbVar8 = (byte *)*puVar4;
          }
          else {
            puVar4 = (undefined4 *)*param_2;
            *param_2 = (int)(puVar4 + 1);
            pbVar8 = (byte *)*puVar4;
          }
          if (pbVar8 != (byte *)0x0) {
            param_1 = pbVar8;
          }
        }
        else {
          puVar4 = (undefined4 *)*param_2;
          *param_2 = (int)(puVar4 + 2);
          if (((byte *)*puVar4 != (byte *)0x0) || (*(short *)(puVar4 + 1) != 0)) {
            param_1 = (byte *)*puVar4;
            in_DS = *(short *)(puVar4 + 1);
          }
        }
        if (*(char *)(unaff_EBX + 0x15) == 'S') {
          bVar1 = *(byte *)(unaff_EBX + 0x1e) & 0x10;
        }
        else {
          bVar1 = *(byte *)(unaff_EBX + 0x1e) & 0x20;
        }
        if (bVar1 == 0) {
          iVar7 = FUN_0002d7dc(param_1,in_DS,*(undefined4 *)(unaff_EBX + 8));
          iVar6 = extraout_ECX_02;
        }
        else {
          iVar7 = FUN_0002d800(param_1,in_DS,*(undefined4 *)(unaff_EBX + 8));
          iVar6 = extraout_ECX_01;
        }
        param_2 = *(int **)(iVar6 + 8);
        *(int *)(iVar6 + 0x28) = iVar7;
        if ((-1 < (int)param_2) && ((int)param_2 < iVar7)) {
          *(int **)(iVar6 + 0x28) = param_2;
        }
        goto LAB_0002dfd4;
      }
      if (0x57 < bVar1) {
        if (bVar1 < 0x59) {
LAB_0002dd90:
          if ((*(byte *)(unaff_EBX + 0x1e) & 1) != 0) {
            uVar11 = local_18;
            if ((*(byte *)(unaff_EBX + 0x1f) & 1) == 0) {
joined_r0x0002ddb0:
              if (uVar11 == 0) goto LAB_0002ddce;
            }
            else if (local_20 == 0) {
              uVar11 = CONCAT13(bStack_19,CONCAT12(uStack_1a,local_1c));
              goto joined_r0x0002ddb0;
            }
            iVar6 = *(int *)(unaff_EBX + 0x20);
            *(int *)(unaff_EBX + 0x20) = iVar6 + 1;
            param_1[iVar6] = 0x30;
            iVar6 = *(int *)(unaff_EBX + 0x20);
            *(int *)(unaff_EBX + 0x20) = iVar6 + 1;
            param_1[iVar6] = *(byte *)(unaff_EBX + 0x15);
          }
LAB_0002ddce:
          uVar10 = 0x10;
          goto LAB_0002ddd3;
        }
        if (bVar1 == 99) {
          *(undefined4 *)(unaff_EBX + 0x20) = 1;
          if ((*(byte *)(unaff_EBX + 0x1e) & 0x20) == 0) {
            pbVar8 = (byte *)*param_2;
            *param_2 = (int)(pbVar8 + 4);
            *param_1 = *pbVar8;
          }
          else {
            puVar5 = (undefined2 *)*param_2;
            *param_2 = (int)(puVar5 + 2);
            uVar14 = FUN_0002f440(&local_14,*puVar5);
            iVar6 = DAT_00041490;
            param_2 = (int *)((ulonglong)uVar14 >> 0x20);
            if ((((int)uVar14 != -1) && (*param_1 = local_14, iVar6 != 0)) &&
               (((&DAT_00041495)[local_14] & 1) != 0)) {
              param_1[1] = local_13;
              *(int *)(extraout_ECX_08 + 0x20) = *(int *)(extraout_ECX_08 + 0x20) + 1;
            }
          }
          goto LAB_0002dfd4;
        }
      }
LAB_0002dfc1:
      *(undefined4 *)(unaff_EBX + 4) = 0;
      *param_1 = *(byte *)(unaff_EBX + 0x15);
      *(undefined4 *)(unaff_EBX + 0x20) = 1;
      goto LAB_0002dfd4;
    }
LAB_0002dcdb:
    FUN_0002d9a2(param_1,param_2,unaff_EBX);
    FUN_0002d9a9(extraout_ECX_00);
    param_1 = param_1 + 1;
    param_2 = extraout_EDX;
    goto LAB_0002dfd4;
  }
  if (100 < bVar1) {
    if (bVar1 < 0x6f) {
      if (0x65 < bVar1) {
        if (bVar1 < 0x67) goto LAB_0002dca6;
        if (0x67 < bVar1) {
          if (bVar1 != 0x69) goto LAB_0002dfc1;
          goto LAB_0002ddf3;
        }
      }
      goto LAB_0002dcdb;
    }
    if (0x6f < bVar1) {
      if (bVar1 < 0x73) {
        bVar13 = bVar1 == 0x70;
        goto LAB_0002dc34;
      }
      if (bVar1 < 0x74) goto LAB_0002dcf7;
      if (0x74 < bVar1) {
        if (bVar1 < 0x76) goto LAB_0002ddf3;
        if (bVar1 == 0x78) goto LAB_0002dd90;
      }
      goto LAB_0002dfc1;
    }
LAB_0002ddd3:
    if ((*(char *)(unaff_EBX + 0x15) == 'o') && (uVar10 = 8, (*(byte *)(unaff_EBX + 0x1e) & 1) != 0)
       ) {
      iVar6 = *(int *)(unaff_EBX + 0x20);
      *(int *)(unaff_EBX + 0x20) = iVar6 + 1;
      param_1[iVar6] = 0x30;
    }
  }
LAB_0002ddf3:
  pbVar8 = param_1 + *(int *)(unaff_EBX + 0x20);
  if ((*(byte *)(unaff_EBX + 0x1f) & 1) == 0) {
    if ((*(int *)(unaff_EBX + 8) != 0) || (local_18 != 0)) {
      FUN_000296c7(local_18,param_1 + *(int *)(unaff_EBX + 0x20),uVar10);
      uVar9 = extraout_var_02;
      if (*(char *)(extraout_ECX_04 + 0x15) == 'X') {
        FUN_0002dfe0(param_1);
        uVar9 = extraout_var_03;
      }
      goto LAB_0002de64;
    }
LAB_0002de19:
    *pbVar8 = 0;
    param_2 = (int *)0x0;
  }
  else {
    if (((*(int *)(unaff_EBX + 8) == 0) && (local_20 == 0)) &&
       (CONCAT13(bStack_19,CONCAT12(uStack_1a,local_1c)) == 0)) goto LAB_0002de19;
    FUN_0002f4d0(&local_20,param_1 + *(int *)(unaff_EBX + 0x20));
    uVar9 = extraout_var_00;
    if (*(char *)(extraout_ECX_03 + 0x15) == 'X') {
      FUN_0002dfe0(param_1);
      uVar9 = extraout_var_01;
    }
LAB_0002de64:
    param_2 = (int *)FUN_0002d7dc(pbVar8,CONCAT22(uVar9,in_DS),0xffffffff);
    unaff_EBX = extraout_ECX_05;
  }
  *(int **)(unaff_EBX + 0x28) = param_2;
  if ((int)param_2 < *(int *)(unaff_EBX + 8)) {
    *(int *)(unaff_EBX + 0x24) = *(int *)(unaff_EBX + 8) - (int)param_2;
  }
  param_1 = pbVar8;
  if (*(int *)(unaff_EBX + 8) == -1) {
    FUN_0002d9a9(unaff_EBX);
    param_2 = extraout_EDX_00;
  }
LAB_0002dfd4:
  return CONCAT44(CONCAT22((short)((uint)param_2 >> 0x10),in_DS),param_1);
}

