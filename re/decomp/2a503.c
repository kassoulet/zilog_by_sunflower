
int FUN_0002a503(undefined4 param_1,int *param_2,undefined4 *unaff_EBX)

{
  byte bVar1;
  undefined6 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int iVar5;
  int iVar6;
  undefined1 *unaff_ESI;
  int iVar7;
  undefined8 uVar8;
  byte abStack_40 [32];
  uint local_20;
  uint local_1c;
  uint local_18;
  
  local_1c = (uint)(*(char *)*unaff_EBX == '^');
  if (local_1c != 0) {
    *unaff_EBX = (char *)*unaff_EBX + 1;
  }
  uVar4 = FUN_0002a4c0(*unaff_EBX,abStack_40,unaff_EBX,param_1);
  *unaff_EBX = uVar4;
  bVar1 = *(byte *)(extraout_ECX + 0x10);
  if ((bVar1 & 1) != 0) {
    if ((bVar1 & 4) == 0) {
      if ((bVar1 & 8) == 0) {
        puVar3 = (undefined4 *)*param_2;
        *param_2 = (int)(puVar3 + 1);
        unaff_ESI = (undefined1 *)*puVar3;
      }
      else {
        puVar3 = (undefined4 *)*param_2;
        *param_2 = (int)(puVar3 + 1);
        unaff_ESI = (undefined1 *)*puVar3;
      }
    }
    else {
      puVar2 = (undefined6 *)*param_2;
      *param_2 = (int)(puVar2 + 1);
      unaff_ESI = (undefined1 *)*puVar2;
    }
  }
  iVar6 = *(int *)(extraout_ECX + 0xc);
  iVar7 = 0;
  iVar5 = extraout_ECX;
  do {
    if (iVar6 == 0) {
LAB_0002a5e0:
      if (((*(byte *)(iVar5 + 0x10) & 1) != 0) && (0 < iVar7)) {
        *unaff_ESI = 0;
      }
      return iVar7;
    }
    uVar8 = FUN_00029e7c(iVar5);
    local_18 = (uint)uVar8;
    iVar5 = extraout_ECX_00;
    if ((*(byte *)(extraout_ECX_00 + 0x10) & 2) != 0) goto LAB_0002a5e0;
    local_20 = (uint)abStack_40[(int)local_18 >> 3];
    if ((((&DAT_0003fce4)[local_18 & 7] & abStack_40[(int)local_18 >> 3]) == 0) != local_1c) {
      FUN_00029e83(local_18,extraout_ECX_00);
      iVar5 = extraout_ECX_01;
      goto LAB_0002a5e0;
    }
    iVar7 = iVar7 + 1;
    iVar6 = (int)((ulonglong)uVar8 >> 0x20) + -1;
    if ((*(byte *)(extraout_ECX_00 + 0x10) & 1) != 0) {
      local_18._0_1_ = (undefined1)uVar8;
      *unaff_ESI = (undefined1)local_18;
      unaff_ESI = unaff_ESI + 1;
    }
  } while( true );
}

