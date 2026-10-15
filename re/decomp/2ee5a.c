
uint FUN_0002ee5a(undefined4 *param_1,uint param_2,int unaff_EBX,int *param_4)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int extraout_ECX;
  uint uVar5;
  int extraout_ECX_00;
  uint extraout_EDX;
  byte bVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  undefined4 *local_1c;
  uint local_14;
  uint local_10;
  
  bVar6 = 0;
  if ((*(byte *)(param_4 + 3) & 2) == 0) {
    FUN_000284cf(4);
    *(byte *)(extraout_ECX + 0xc) = *(byte *)(extraout_ECX + 0xc) | 0x20;
    local_14 = 0;
  }
  else {
    local_10 = unaff_EBX * param_2;
    if (local_10 == 0) {
      local_14 = 0;
    }
    else {
      if (*(int *)(param_4[2] + 8) == 0) {
        FUN_00028c7a(param_4);
      }
      uVar2 = param_4[3];
      bVar1 = *(byte *)(param_4 + 3);
      local_14 = 0;
      *(byte *)(param_4 + 3) = bVar1 & 0xcf;
      local_1c = param_1;
      if ((bVar1 & 0x40) == 0) {
        if ((*(byte *)((int)param_4 + 0xd) & 4) != 0) {
          bVar6 = *(byte *)((int)param_4 + 0xd) & 0xfa;
          *(byte *)((int)param_4 + 0xd) = bVar6;
          *(byte *)((int)param_4 + 0xd) = bVar6 | 1;
        }
        uVar3 = *(undefined4 *)(param_4[2] + 0xc);
        *(undefined4 *)(param_4[2] + 0xc) = 1;
        do {
          FUN_0002f37d(*(undefined1 *)param_1,param_4);
          param_1 = (undefined4 *)((int)param_1 + 1);
          if ((*(byte *)(param_4 + 3) & 0x30) != 0) break;
          local_14 = local_14 + 1;
        } while (local_10 - local_14 != 0);
        *(undefined4 *)(param_4[2] + 0xc) = uVar3;
        if (extraout_ECX_00 != 0) {
          bVar6 = *(byte *)((int)param_4 + 0xd) & 0xfa;
          *(byte *)((int)param_4 + 0xd) = bVar6;
          *(byte *)((int)param_4 + 0xd) = bVar6 | 4;
          FUN_00028acc(param_4);
        }
      }
      else {
        do {
          if ((param_4[1] == 0) && ((uint)param_4[5] <= local_10)) {
            uVar4 = FUN_0002eb49(param_4[4],local_1c);
            if (uVar4 != 0xffffffff) {
              if (uVar4 != 0) goto LAB_0002ef6d;
              uVar9 = FUN_0002e51d();
              uVar4 = (uint)((ulonglong)uVar9 >> 0x20);
              *(undefined4 *)uVar9 = 0xc;
            }
            *(byte *)(param_4 + 3) = *(byte *)(param_4 + 3) | 0x20;
          }
          else {
            uVar4 = param_4[5] - param_4[1];
            if (local_10 < (uint)(param_4[5] - param_4[1])) {
              uVar4 = local_10;
            }
            puVar7 = local_1c;
            puVar8 = (undefined4 *)*param_4;
            for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
              *puVar8 = *puVar7;
              puVar7 = puVar7 + (uint)bVar6 * -2 + 1;
              puVar8 = puVar8 + (uint)bVar6 * -2 + 1;
            }
            for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
              *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
              puVar7 = (undefined4 *)((int)puVar7 + (uint)bVar6 * -2 + 1);
              puVar8 = (undefined4 *)((int)puVar8 + (uint)bVar6 * -2 + 1);
            }
            param_4[1] = param_4[1] + uVar4;
            bVar1 = *(byte *)((int)param_4 + 0xd);
            *param_4 = *param_4 + uVar4;
            *(byte *)((int)param_4 + 0xd) = bVar1 | 0x10;
            if ((param_4[1] == param_4[5]) || ((bVar1 & 4) != 0)) {
              FUN_00028acc(param_4);
              uVar4 = extraout_EDX;
            }
          }
LAB_0002ef6d:
          local_1c = (undefined4 *)((int)local_1c + uVar4);
          local_14 = local_14 + uVar4;
          local_10 = local_10 - uVar4;
        } while ((local_10 != 0) && ((*(byte *)(param_4 + 3) & 0x20) == 0));
      }
      if ((*(byte *)(param_4 + 3) & 0x20) != 0) {
        local_14 = 0;
      }
      param_4[3] = param_4[3] | uVar2 & 0x30;
      local_14 = local_14 / param_2;
    }
  }
  return local_14;
}

