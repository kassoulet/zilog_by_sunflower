
int FUN_0002a30f(int param_1,int *param_2)

{
  byte bVar1;
  undefined6 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int extraout_ECX;
  int extraout_ECX_00;
  int iVar6;
  int extraout_ECX_01;
  int extraout_ECX_02;
  undefined1 uVar7;
  undefined2 *unaff_ESI;
  int iVar8;
  undefined1 local_24 [4];
  undefined1 local_20;
  undefined1 local_1f;
  byte local_1c;
  
  if ((*(byte *)(param_1 + 0x10) & 0x20) == 0) {
    local_1c = 1;
  }
  else {
    local_1c = 2;
  }
  bVar1 = *(byte *)(param_1 + 0x10);
  if ((bVar1 & 1) != 0) {
    if ((bVar1 & 4) == 0) {
      if ((bVar1 & 8) == 0) {
        puVar3 = (undefined4 *)*param_2;
        *param_2 = (int)(puVar3 + 1);
        unaff_ESI = (undefined2 *)*puVar3;
      }
      else {
        puVar3 = (undefined4 *)*param_2;
        *param_2 = (int)(puVar3 + 1);
        unaff_ESI = (undefined2 *)*puVar3;
      }
    }
    else {
      puVar2 = (undefined6 *)*param_2;
      *param_2 = (int)(puVar2 + 1);
      unaff_ESI = (undefined2 *)*puVar2;
    }
  }
  iVar8 = 0;
  while (uVar4 = FUN_00029e7c(param_1), ((&DAT_0003fda0)[(byte)((char)uVar4 + 1)] & 2) != 0) {
    iVar8 = iVar8 + 1;
    param_1 = extraout_ECX;
  }
  if ((*(byte *)(extraout_ECX + 0x10) & 2) == 0) {
    iVar5 = *(int *)(extraout_ECX + 0xc);
    *(int *)(extraout_ECX + 0xc) = iVar5 + -1;
    iVar6 = extraout_ECX;
    if (iVar5 != 0) {
      do {
        iVar8 = iVar8 + 1;
        if ((*(byte *)(iVar6 + 0x10) & 1) != 0) {
          uVar7 = (undefined1)uVar4;
          if (local_1c == 1) {
            *(undefined1 *)unaff_ESI = uVar7;
          }
          else {
            local_20 = uVar7;
            if ((DAT_00041490 != 0) && (((&DAT_00041495)[uVar4 & 0xff] & 1) != 0)) {
              local_1f = FUN_00029e7c(iVar6);
            }
            iVar5 = FUN_0002f18b(local_24,&local_20,2);
            if (iVar5 == -1) {
              return 0;
            }
            *unaff_ESI = local_24._0_2_;
            iVar6 = extraout_ECX_00;
          }
          unaff_ESI = (undefined2 *)((int)unaff_ESI + (uint)local_1c);
        }
        uVar4 = FUN_0002acfb(iVar6);
        iVar5 = extraout_ECX_01;
        if (uVar4 == 0xffffffff) goto LAB_0002a43b;
        iVar6 = extraout_ECX_01;
      } while (((&DAT_0003fda0)[(byte)((char)uVar4 + 1)] & 2) == 0);
    }
    FUN_00029e83(uVar4,iVar6);
    iVar5 = extraout_ECX_02;
  }
  else {
    iVar8 = 0;
    iVar5 = extraout_ECX;
  }
LAB_0002a43b:
  if (((*(byte *)(iVar5 + 0x10) & 1) != 0) && (0 < iVar8)) {
    if (local_1c == 1) {
      *(undefined1 *)unaff_ESI = 0;
    }
    else {
      *unaff_ESI = 0;
    }
  }
  return iVar8;
}

