
void FUN_00017858(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_24;
  uint local_20;
  int local_18;
  
  local_24 = 0x20;
  local_20 = 0;
  for (local_18 = 1; local_18 < param_1; local_18 = local_18 + 1) {
    if ((**(char **)(local_18 * 4 + param_2) == '/') || (**(char **)(local_18 * 4 + param_2) == '-')
       ) {
      iVar2 = FUN_0002431d(*(int *)(local_18 * 4 + param_2) + 1,&DAT_0003dec8,3);
      if (iVar2 == 0) {
        FUN_00024eff();
      }
      else {
        iVar2 = FUN_0002431d(*(int *)(local_18 * 4 + param_2) + 1,&DAT_0003ded3,4);
        if (iVar2 == 0) {
          local_24 = 0xc;
        }
        else {
          iVar2 = FUN_0002431d(*(int *)(local_18 * 4 + param_2) + 1,&DAT_0003ded8,4);
          if (iVar2 == 0) {
            local_24 = 0xb;
          }
          else {
            iVar2 = FUN_0002431d(*(int *)(local_18 * 4 + param_2) + 1,s_nolfb_0003dedd,5);
            if ((iVar2 == 0) ||
               (iVar2 = FUN_0002431d(*(int *)(local_18 * 4 + param_2) + 1,s_banked_0003dee3,6),
               iVar2 == 0)) {
              local_20 = 0x10000;
            }
          }
        }
      }
    }
  }
  if (local_24 < 8) {
    local_24 = 8;
  }
  FUN_0002437e(&DAT_00040540,s_320_200_0003deea);
  if ((local_24 < 0x20) ||
     (DAT_00040530 = FUN_000251e7(0x140,200,local_20 | 0x20), DAT_00040530 == 0)) {
    if ((local_24 < 0x18) ||
       (DAT_00040530 = FUN_000251e7(0x140,200,local_20 | 0x18), DAT_00040530 == 0)) {
      if ((local_24 < 0x10) ||
         (DAT_00040530 = FUN_000251e7(0x140,200,local_20 | 0x10), DAT_00040530 == 0)) {
        if ((local_24 < 0xf) ||
           (DAT_00040530 = FUN_000251e7(0x140,200,local_20 | 0xf), DAT_00040530 == 0)) {
          if (local_24 < 0xc) {
            if ((local_24 == 0xb) &&
               (DAT_00040530 = FUN_000251e7(0x280,400,local_20 | 8), DAT_00040530 != 0)) {
              FUN_00025a7f();
              out(0x3d4,9);
              bVar1 = in(0x3d5);
              out(0x3d5,bVar1 | 0x80);
              DAT_0004053c = 0xb;
              FUN_00025e22(&DAT_00040540,s_strange_fake_12bpp_0003df1a);
              uVar3 = thunk_FUN_00024c8f(0x20000);
              FUN_00025bec(uVar3);
            }
            else if (local_24 == 8) {
              FUN_00025ade();
              DAT_0004053c = 8;
              FUN_00025e22(&DAT_00040540,s_ugly_8bpp_0003df2e);
            }
          }
          else {
            FUN_000259ff();
            DAT_0004053c = 0xc;
            FUN_00025e22(&DAT_00040540,s_fake_12bpp_0003df0e);
            uVar3 = thunk_FUN_00024c8f(0x10100);
            FUN_00025bec(uVar3);
          }
        }
        else {
          DAT_0004053c = 0xf;
          FUN_00025e22(&DAT_00040540,s_15bpp_0003df07);
          uVar3 = thunk_FUN_00024c8f(0x20000);
          FUN_00025cd1(uVar3);
        }
      }
      else {
        DAT_0004053c = 0x10;
        FUN_00025e22(&DAT_00040540,s_16bpp_0003df00);
        uVar3 = thunk_FUN_00024c8f(0x20000);
        FUN_00025c5b(uVar3);
      }
    }
    else {
      DAT_0004053c = 0x18;
      FUN_00025e22(&DAT_00040540,s_24bpp_0003def9);
    }
  }
  else {
    DAT_0004053c = 0x20;
    FUN_00025e22(&DAT_00040540,s_32bpp_0003def2);
  }
  DAT_00040534 = *(int *)(DAT_00040530 + 0x14);
  if ((DAT_0004053c != 0xc) && (DAT_0004053c != 8)) {
    if (DAT_00040534 == 0) {
      FUN_00025e22(&DAT_00040540,s_banked_0003df3e);
    }
    else {
      FUN_00025e22(&DAT_00040540,&DAT_0003df39);
    }
  }
  return;
}

