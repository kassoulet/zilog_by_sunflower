
undefined8 FUN_00015a48(undefined4 param_1,undefined4 param_2)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint *puVar6;
  char cVar7;
  undefined8 uVar8;
  uint local_90;
  uint local_8c;
  uint *local_88;
  int local_84;
  int local_80;
  int local_6c;
  int local_68;
  int local_58;
  int local_54;
  int local_4c;
  int local_1c;
  
  FUN_00016031(&DAT_000404e8,&DAT_0003de2a);
  iVar2 = FUN_00015856(param_1);
  iVar3 = FUN_0002431d(iVar2,&DAT_0003de2c,4);
  local_1c = iVar2;
  if (iVar3 == 0) {
    local_1c = thunk_FUN_00024c8f(*(undefined4 *)(iVar2 + 4));
    uVar8 = thunk_FUN_00024c8f(0x3000);
    uVar4 = (undefined4)uVar8;
    FUN_00024568(uVar4,(int)((ulonglong)uVar8 >> 0x20),uVar4);
    FUN_00023831(iVar2);
    FUN_00023831(uVar4);
    FUN_00016031(&DAT_000404e8,&DAT_0003de31);
  }
  iVar2 = FUN_0002431d(local_1c,&DAT_0003de34,4);
  if (iVar2 == 0) {
    iVar2 = *(int *)(local_1c + 0x12) + local_1c + 0x16;
    if ((*(byte *)(local_1c + 0xd) & 2) != 0) {
      FUN_00016031(&DAT_000404e8,&DAT_0003de39);
      cVar7 = '\0';
      for (local_4c = 0; local_4c < *(int *)(local_1c + 0xe); local_4c = local_4c + 1) {
        cVar7 = cVar7 + *(char *)(iVar2 + local_4c);
        *(char *)(iVar2 + local_4c) = cVar7;
      }
      *(byte *)(local_1c + 0xd) = *(byte *)(local_1c + 0xd) & 0xfd;
    }
    uVar5 = (int)(*(byte *)(local_1c + 0xc) + 1) >> 3;
    if (((*(byte *)(local_1c + 0xd) & 4) != 0) && (1 < uVar5)) {
      FUN_00016031(&DAT_000404e8,&DAT_0003de3d);
      iVar3 = thunk_FUN_00024c8f(*(undefined4 *)(local_1c + 0xe));
      for (local_54 = 0; local_54 < *(int *)(local_1c + 0xe); local_54 = local_54 + uVar5) {
        for (local_58 = 0; local_58 < (int)uVar5; local_58 = local_58 + 1) {
          *(undefined1 *)(local_54 + local_58 + iVar3) =
               *(undefined1 *)
                ((local_58 * *(int *)(local_1c + 0xe) + local_54) / (int)uVar5 + iVar2);
        }
      }
      FUN_0001c48f(iVar2,iVar3,*(undefined4 *)(local_1c + 0xe));
      FUN_00023831(iVar3);
      *(byte *)(local_1c + 0xd) = *(byte *)(local_1c + 0xd) & 0xfb;
    }
    if (*(char *)(local_1c + 0xc) == '\x18') {
      FUN_00016031(&DAT_000404e8,&DAT_0003de40);
      lVar1 = CONCAT44(*(int *)(local_1c + 0xe) >> 0x1f,*(undefined4 *)(local_1c + 0xe));
      iVar3 = thunk_FUN_00024c8f((int)(lVar1 / (longlong)(int)uVar5) * 4 + 0x16,
                                 (int)(lVar1 % (longlong)(int)uVar5));
      FUN_0001c48f(iVar3,local_1c,0x16);
      *(undefined1 *)(iVar3 + 0xc) = 0x20;
      for (local_68 = 0;
          local_68 <
          (int)(CONCAT44(*(int *)(local_1c + 0xe) >> 0x1f,*(undefined4 *)(local_1c + 0xe)) /
               (longlong)(int)uVar5); local_68 = local_68 + 1) {
        for (local_6c = 0; local_6c < 3; local_6c = local_6c + 1) {
          *(undefined1 *)(local_68 * 4 + local_6c + iVar3 + 0x16) =
               *(undefined1 *)(iVar2 + local_68 * 3 + local_6c);
        }
        *(undefined1 *)(local_68 * 4 + iVar3 + 0x16 + 3) = 0;
      }
      *(int *)(iVar3 + 0xe) =
           (int)(CONCAT44(*(int *)(local_1c + 0xe) >> 0x1f,*(undefined4 *)(local_1c + 0xe)) /
                (longlong)(int)uVar5) << 2;
      FUN_00023831(local_1c);
      local_1c = iVar3;
    }
    if (((*(byte *)(local_1c + 0xd) & 1) == 1) && (*(char *)(local_1c + 0xc) == ' ')) {
      FUN_00016031(&DAT_000404e8,&DAT_0003de43);
      iVar2 = *(int *)(local_1c + 4) * *(int *)(local_1c + 8);
      iVar3 = local_1c + 0x16;
      puVar6 = (uint *)thunk_FUN_00024c8f(iVar2 * 4);
      local_80 = 0;
      local_84 = 1;
      local_88 = puVar6;
      while (local_80 < iVar2) {
        local_8c = 0;
        local_90 = *(uint *)(local_80 * 4 + iVar3);
        if (local_90 == 0) {
          while ((local_90 == 0 && (local_80 < iVar2))) {
            local_90 = *(uint *)(local_80 * 4 + iVar3);
            if (local_90 == 0) {
              local_80 = local_80 + 1;
              local_8c = local_8c + 1;
            }
          }
          *local_88 = local_8c;
          local_88 = local_88 + 1;
        }
        else {
          while ((local_90 != 0 && (local_80 < iVar2))) {
            local_90 = *(uint *)(local_80 * 4 + iVar3);
            if (local_90 != 0) {
              puVar6[local_84] = local_90;
              local_80 = local_80 + 1;
              local_8c = local_8c + 1;
              local_84 = local_84 + 1;
            }
          }
          *local_88 = local_8c | 0x80000000;
          local_88 = local_88 + local_8c + 1;
        }
        local_84 = local_84 + 1;
      }
      *local_88 = 0xffffffff;
      iVar2 = thunk_FUN_00024c8f(local_84 * 4 + 0x16);
      FUN_0001c48f(iVar2,local_1c,0x16);
      FUN_0001c48f(iVar2 + 0x16,puVar6,local_84 << 2);
      *(int *)(iVar2 + 0xe) = local_84 << 2;
      FUN_00023831(local_1c);
      FUN_00023831(puVar6);
      local_1c = iVar2;
    }
  }
  FUN_00016031(&DAT_000404e8,&DAT_0003de46);
  return CONCAT44(param_2,local_1c);
}

