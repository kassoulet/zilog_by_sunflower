
/* WARNING: Type propagation algorithm not settling */

uint FUN_000278a1(uint *param_1,int *param_2,undefined1 *unaff_EBX)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  uint extraout_ECX;
  uint extraout_ECX_00;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ushort in_FPUControlWord;
  longdouble lVar10;
  char local_9c [64];
  longdouble local_5c;
  undefined1 local_50 [8];
  undefined2 uStack_48;
  undefined1 local_44 [8];
  undefined2 uStack_3c;
  uint local_38;
  uint uStack_34;
  undefined1 uStack_30;
  byte bStack_2f;
  char *local_2c;
  undefined4 local_28;
  int iStack_20;
  int local_1c;
  char cStack_14;
  
  param_2[5] = 0;
  uVar1 = (ushort)param_1[2];
  uStack_30 = (undefined1)uVar1;
  bStack_2f = (byte)(uVar1 >> 8);
  uStack_34 = param_1[1];
  local_38 = *param_1;
  if ((uVar1 & 0x8000) != 0) {
    param_2[5] = -1;
  }
  bStack_2f = bStack_2f & 0x7f;
  param_2[7] = 0;
  param_2[8] = 0;
  param_2[9] = 0;
  param_2[10] = 0;
  iVar8 = 0;
  param_2[6] = 0;
  uVar2 = FUN_0002e400(&local_38);
  uVar4 = extraout_ECX;
  switch(uVar2) {
  case 0:
  case 4:
    param_2[5] = 0;
LAB_0002793b:
    uVar4 = 0;
    break;
  case 1:
    uVar4 = (int)((CONCAT11(bStack_2f,uStack_30) - 0x3ffe) * 0x7597) / 100000 - 4;
    if (uVar4 != 0) {
      if ((int)uVar4 < 0) {
        uVar4 = -(3 - uVar4 & 0xfffffffc);
      }
      else {
        if ((CONCAT11(bStack_2f,uStack_30) < 0x4019) ||
           ((CONCAT11(bStack_2f,uStack_30) == 0x4019 && (uStack_34 < 3200000000))))
        goto LAB_0002793b;
        if ((CONCAT11(bStack_2f,uStack_30) < 0x4034) ||
           ((CONCAT11(bStack_2f,uStack_30) == 0x4034 &&
            ((uStack_34 < 0x8e1bc9bf || ((uStack_34 == 0x8e1bc9bf && (local_38 < 0x4000000)))))))) {
          _local_50 = (longdouble)CONCAT28(0x4019,0xbebc200000000000);
          _local_50 = (longdouble)((unkuint10)stack0xffffffb4 << 0x20);
          iVar8 = (int)ROUND((longdouble)
                             CONCAT19(bStack_2f,CONCAT18(uStack_30,CONCAT44(uStack_34,local_38))) /
                             _local_50);
          local_5c = (longdouble)iVar8;
          _local_50 = _local_50 * (longdouble)iVar8;
          uVar4 = 8;
          lVar10 = (longdouble)CONCAT19(bStack_2f,CONCAT18(uStack_30,CONCAT44(uStack_34,local_38)))
                   - _local_50;
          local_38 = SUB104(lVar10,0);
          uStack_34 = (uint)((unkuint10)lVar10 >> 0x20);
          uStack_30 = (undefined1)((unkuint10)lVar10 >> 0x40);
          bStack_2f = (byte)((unkuint10)lVar10 >> 0x48);
          break;
        }
        uVar4 = uVar4 & 0xfffffffc;
      }
      FUN_00027847(&local_38,-uVar4);
      uVar4 = extraout_ECX_00;
    }
    break;
  case 2:
    *unaff_EBX = 0x6e;
    unaff_EBX[1] = 0x61;
    unaff_EBX[2] = 0x6e;
    goto LAB_00027950;
  case 3:
    *unaff_EBX = 0x69;
    unaff_EBX[1] = 0x6e;
    unaff_EBX[2] = 0x66;
LAB_00027950:
    unaff_EBX[3] = 0;
    param_2[7] = 3;
    return (uint)in_FPUControlWord;
  }
  if ((*(byte *)(param_2 + 2) & 2) == 0) {
    local_1c = *param_2 + 7;
  }
  else {
    local_1c = *param_2 + uVar4 + 10;
    if (0 < param_2[1]) {
      local_1c = local_1c + param_2[1];
    }
  }
  iVar3 = 0xf;
  if ((*(byte *)(param_2 + 2) & 0x20) != 0) {
    iVar3 = 0x14;
  }
  if ((*(byte *)(param_2 + 2) & 0x40) != 0) {
    iVar3 = iVar3 * 2;
  }
  if (iVar3 + 4 < local_1c) {
    local_1c = iVar3 + 4;
  }
  local_9c[0] = '0';
  local_9c[1] = 0;
  local_2c = local_9c + 1;
  local_28 = 0;
  if (local_1c < 1) {
LAB_00027bd0:
    iVar8 = 0;
    pcVar6 = local_9c;
    iVar3 = uVar4 + 7;
    while (pcVar6 = pcVar6 + 1, *pcVar6 == '0') {
      iVar8 = iVar8 + -1;
      iVar3 = iVar3 + -1;
    }
    iVar9 = *param_2;
    if ((*(byte *)(param_2 + 2) & 2) == 0) {
      if ((*(byte *)(param_2 + 2) & 1) != 0) {
        if (param_2[1] < 1) {
          iVar9 = iVar9 + param_2[1];
        }
        else {
          iVar9 = iVar9 + 1;
        }
        iVar3 = (iVar3 + 1) - param_2[1];
      }
    }
    else {
      iVar3 = iVar3 + param_2[1];
      iVar9 = iVar9 + iVar3 + 1;
    }
    if (-1 < iVar9) {
      if (iVar8 < iVar9) {
        iVar9 = iVar8;
      }
      iVar7 = 0xf;
      if ((*(byte *)(param_2 + 2) & 0x20) != 0) {
        iVar7 = 0x14;
      }
      if ((*(byte *)(param_2 + 2) & 0x40) != 0) {
        iVar7 = iVar7 * 2;
      }
      if (iVar7 < iVar9) {
        iVar9 = iVar7 + 1;
      }
      cStack_14 = '0';
      if ((iVar9 < iVar8) && (0x34 < (byte)pcVar6[iVar9])) {
        cStack_14 = '9';
      }
      pcVar5 = pcVar6 + iVar9;
      iStack_20 = iVar9;
      while( true ) {
        iStack_20 = iStack_20 + -1;
        pcVar5 = pcVar5 + -1;
        if (*pcVar5 != cStack_14) break;
        iVar9 = iVar9 + -1;
      }
      if (cStack_14 == '9') {
        *pcVar5 = *pcVar5 + '\x01';
      }
      if (iStack_20 < 0) {
        pcVar6 = pcVar6 + -1;
        iVar9 = iVar9 + 1;
        iVar3 = iVar3 + 1;
      }
    }
    if (iVar9 < 1) {
      iVar9 = 1;
      iVar3 = 0;
      local_9c[0] = '0';
      pcVar6 = local_9c;
      param_2[5] = 0;
    }
    if (((*(byte *)(param_2 + 2) & 2) == 0) &&
       (((*(byte *)(param_2 + 2) & 4) == 0 ||
        (((iVar3 < -4 || (*param_2 <= iVar3)) && ((*(byte *)(param_2 + 2) & 8) == 0)))))) {
      FUN_00027f01(param_2,pcVar6,iVar9,iVar3,unaff_EBX);
    }
    else {
      FUN_00027ce3(param_2,pcVar6,iVar9,iVar3,unaff_EBX);
    }
    return (uint)in_FPUControlWord;
  }
  if (iVar8 == 0) {
    if ((CONCAT11(bStack_2f,uStack_30) & 0x7fff) == 0) goto LAB_00027bd0;
    iVar8 = (int)ROUND((longdouble)
                       CONCAT19(bStack_2f,CONCAT18(uStack_30,CONCAT44(uStack_34,local_38))));
    if (0 < local_1c + -8) {
      _local_44 = (longdouble)CONCAT28(0x4019,0xbebc200000000000);
      _local_44 = (longdouble)((unkuint10)stack0xffffffc0 << 0x20);
      lVar10 = _local_44 *
               ((longdouble)CONCAT19(bStack_2f,CONCAT18(uStack_30,CONCAT44(uStack_34,local_38))) -
               (longdouble)iVar8);
      local_38 = SUB104(lVar10,0);
      uStack_34 = (uint)((unkuint10)lVar10 >> 0x20);
      uStack_30 = (undefined1)((unkuint10)lVar10 >> 0x40);
      bStack_2f = (byte)((unkuint10)lVar10 >> 0x48);
    }
  }
  FUN_00027b75(iVar8,0,local_9c + 1);
  uVar4 = FUN_00027bba();
  return uVar4;
}

