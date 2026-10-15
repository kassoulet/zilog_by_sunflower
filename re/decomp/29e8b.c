
int FUN_00029e8b(int param_1,byte *param_2,undefined4 *unaff_EBX)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  byte *local_18;
  undefined4 local_14;
  
  local_14 = *unaff_EBX;
  iVar8 = 0;
  iVar9 = 0;
  *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) & 0xfd;
  local_18 = param_2;
  do {
    pbVar1 = local_18 + 1;
    uVar6 = (uint)*local_18;
    if (uVar6 == 0) goto LAB_0002a0e4;
    if (((&DAT_0003fda0)[(byte)(*local_18 + 1)] & 2) != 0) {
      local_18 = pbVar1;
      iVar3 = FUN_0002a1f6(param_1);
      iVar9 = iVar9 + iVar3;
      goto LAB_0002a0ae;
    }
    if (uVar6 != 0x25) {
      local_18 = pbVar1;
      uVar4 = FUN_00029e7c(param_1);
      if (uVar4 == uVar6) {
LAB_0002a0ad:
        iVar9 = iVar9 + 1;
        goto LAB_0002a0ae;
      }
LAB_00029ef5:
      if ((*(byte *)(param_1 + 0x10) & 2) == 0) {
        FUN_00029e83(uVar4,param_1);
      }
      goto LAB_0002a0e4;
    }
    local_18 = pbVar1;
    local_18 = (byte *)FUN_0002a0ff(pbVar1,param_1);
    bVar2 = *local_18;
    if (bVar2 != 0) {
      local_18 = local_18 + 1;
    }
    if (bVar2 < 100) {
      if (bVar2 < 0x47) {
        if (bVar2 < 0x43) {
          if (bVar2 == 0x25) {
            uVar4 = FUN_00029e7c(param_1);
            if (uVar4 != 0x25) goto LAB_00029ef5;
            goto LAB_0002a0ad;
          }
        }
        else {
          if (bVar2 < 0x44) {
            *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) | 0x20;
LAB_0002a073:
            iVar3 = FUN_0002a22d(param_1,&local_14);
            goto LAB_0002a07e;
          }
          if (bVar2 == 0x45) goto LAB_0002a042;
        }
      }
      else {
        if (bVar2 < 0x48) {
LAB_0002a042:
          iVar3 = FUN_0002a5f9(param_1,&local_14);
          goto LAB_0002a07e;
        }
        if (bVar2 < 0x58) {
          if (bVar2 == 0x53) {
            *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) | 0x20;
LAB_0002a053:
            iVar3 = FUN_0002a30f(param_1,&local_14);
            goto LAB_0002a07e;
          }
        }
        else {
          if (bVar2 < 0x59) goto LAB_0002a036;
          if (0x5a < bVar2) {
            if (bVar2 < 0x5c) {
              iVar3 = FUN_0002a503(param_1,&local_14,&local_18);
              goto LAB_0002a07e;
            }
            if (bVar2 == 99) goto LAB_0002a073;
          }
        }
      }
    }
    else {
      if (bVar2 < 0x65) {
        uVar7 = 10;
LAB_00029ffc:
        uVar5 = 1;
      }
      else {
        if (0x6e < bVar2) {
          if (bVar2 < 0x70) {
            uVar7 = 8;
          }
          else {
            if (bVar2 < 0x73) {
              bVar10 = bVar2 == 0x70;
            }
            else {
              if (bVar2 < 0x74) goto LAB_0002a053;
              if (bVar2 < 0x75) goto LAB_0002a0ae;
              if (bVar2 < 0x76) {
                uVar7 = 10;
                uVar5 = 0;
                goto LAB_0002a002;
              }
              bVar10 = bVar2 == 0x78;
            }
            if (!bVar10) goto LAB_0002a0ae;
LAB_0002a036:
            uVar7 = 0x10;
          }
          goto LAB_00029ffc;
        }
        if (bVar2 < 0x69) {
          if (bVar2 < 0x68) goto LAB_0002a042;
          goto LAB_0002a0ae;
        }
        if (0x69 < bVar2) {
          if (bVar2 == 0x6e) {
            FUN_0002a462(param_1,&local_14,iVar9);
          }
          goto LAB_0002a0ae;
        }
        uVar5 = 1;
        uVar7 = 0;
      }
LAB_0002a002:
      iVar3 = FUN_0002a8cf(param_1,&local_14,uVar7,uVar5);
LAB_0002a07e:
      if (iVar3 < 1) goto LAB_0002a0e4;
      iVar9 = iVar9 + iVar3;
      if ((*(byte *)(param_1 + 0x10) & 1) != 0) {
        iVar8 = iVar8 + 1;
      }
    }
LAB_0002a0ae:
  } while ((*(byte *)(param_1 + 0x10) & 2) == 0);
  if (*local_18 == 0x25) {
    local_18 = local_18 + 1;
    local_18 = (byte *)FUN_0002a0ff(local_18,param_1);
    if (*local_18 == 0x6e) {
      FUN_0002a462(param_1,&local_14,iVar9);
    }
  }
LAB_0002a0e4:
  if ((iVar8 == 0) && ((*(byte *)(param_1 + 0x10) & 2) != 0)) {
    iVar8 = -1;
  }
  return iVar8;
}

