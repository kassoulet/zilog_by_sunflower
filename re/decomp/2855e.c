
uint FUN_0002855e(char *param_1,byte param_2,uint unaff_EBX,int *param_4)

{
  uint *puVar1;
  code *pcVar2;
  uint uVar3;
  bool bVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  byte bVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  int iStack_18;
  uint local_14;
  uint uStack_10;
  
  for (; *param_1 == ' '; param_1 = param_1 + 1) {
  }
  local_14._0_1_ = param_2 & 0x83;
  bVar10 = 0;
  uVar9 = 0xffffffff;
  pcVar2 = (code *)swi(0x21);
  iVar5 = (*pcVar2)(CONCAT11(0x3d,(byte)local_14 | (byte)unaff_EBX),param_1);
  bVar4 = (bVar10 & 1) != 0;
  uVar7 = (iVar5 << 1 | (uint)bVar10) >> 1;
  local_14 = uVar7 | (uint)bVar4 << 0x1f;
  if ((!bVar4) && (uVar9 = uVar7 & 0xffff, uVar7 = DAT_0003fd1c, DAT_0003fd1c <= uVar9)) {
LAB_000285b5:
    pcVar2 = (code *)swi(0x21);
    (*pcVar2)(CONCAT22((short)(local_14 >> 0x10),CONCAT11(0x3e,(char)local_14)),uVar7,uVar9);
    uVar6 = 0xb;
LAB_000285c4:
    FUN_000284cf(uVar6);
    return 0xffffffff;
  }
  if (((unaff_EBX & 3) != 0) && (uVar9 != 0xffffffff)) {
    uVar11 = FUN_0002e69a(uVar9);
    if ((int)uVar11 == 0) {
      if (((unaff_EBX & 0x400) != 0) && ((uVar11 & 0x200000000000) != 0)) {
        pcVar2 = (code *)swi(0x21);
        (*pcVar2)(0x3e00,(int)(uVar11 >> 0x20),uVar9);
        uVar6 = 7;
        goto LAB_000285c4;
      }
      if ((unaff_EBX & 0x40) != 0) {
        bVar10 = 0;
        pcVar2 = (code *)swi(0x21);
        uVar12 = (*pcVar2)(0x4000,&stack0xfffffff4,uVar9,0);
        bVar4 = (bVar10 & 1) != 0;
        uVar7 = ((int)uVar12 << 1 | (uint)bVar10) >> 1;
        local_14 = uVar7 | (uint)bVar4 << 0x1f;
        if (bVar4) {
          pcVar2 = (code *)swi(0x21);
          (*pcVar2)(CONCAT22((short)(local_14 >> 0x10),CONCAT11(0x3e,(char)uVar7)),
                    (int)((ulonglong)uVar12 >> 0x20),uVar9);
          goto LAB_00028634;
        }
      }
    }
  }
  if (uVar9 == 0xffffffff) {
    if (((unaff_EBX & 0x20) == 0) || ((short)local_14 != 2)) {
LAB_00028634:
      uVar7 = FUN_0002e6c3(local_14 & 0xffff);
      return uVar7;
    }
    puVar1 = (uint *)*param_4;
    puVar8 = puVar1 + 1;
    *param_4 = (int)puVar8;
    uVar7 = *puVar1;
    *param_4 = 0;
    if (uVar7 == 0) {
      uVar7 = 0x180;
    }
    uVar7 = uVar7 & ~DAT_0003fd88;
    bVar10 = 0;
    pcVar2 = (code *)swi(0x21);
    uVar12 = (*pcVar2)(CONCAT22((short)(uVar7 >> 0x10),CONCAT11(0x3c,(char)uVar7)),param_1,puVar8,
                       (uVar7 & 0x80) == 0);
    uVar7 = (uint)((ulonglong)uVar12 >> 0x20);
    bVar4 = (bVar10 & 1) != 0;
    uVar3 = ((int)uVar12 << 1 | (uint)bVar10) >> 1;
    local_14 = uVar3 | (uint)bVar4 << 0x1f;
    if (bVar4) goto LAB_00028634;
    uVar9 = uVar3 & 0xffff;
    if (DAT_0003fd1c <= uVar9) goto LAB_000285b5;
    bVar10 = 0;
    if (iStack_18 != 0) {
      pcVar2 = (code *)swi(0x21);
      iVar5 = (*pcVar2)(CONCAT22((short)(local_14 >> 0x10),CONCAT11(0x3e,(char)uVar3)),uVar7,uVar9);
      bVar4 = (bVar10 & 1) != 0;
      local_14 = (iVar5 << 1 | (uint)bVar10) >> 1 | (uint)bVar4 << 0x1f;
      if (bVar4) goto LAB_00028634;
      bVar10 = 0;
      pcVar2 = (code *)swi(0x21);
      iVar5 = (*pcVar2)(CONCAT22((short)(local_14 >> 0x10),
                                 CONCAT11(0x3d,(byte)uStack_10 | (byte)iStack_18)),param_1);
      local_14 = (iVar5 << 1 | (uint)bVar10) >> 1;
      if ((bVar10 & 1) != 0) goto LAB_00028634;
      uVar9 = local_14 & 0xffff;
    }
  }
  uVar7 = FUN_0002e624(uVar9);
  uVar12 = FUN_0002e69a(uVar9,uVar7 & 0xffffff3c);
  uVar7 = (uint)((ulonglong)uVar12 >> 0x20);
  if ((int)uVar12 != 0) {
    uVar7 = uVar7 | 0x2000;
  }
  uStack_10 = uStack_10 & 0xffffff7f;
  if (uStack_10 == 2) {
    uVar7 = uVar7 | 3;
  }
  if (uStack_10 == 0) {
    uVar7 = uVar7 | 1;
  }
  if (uStack_10 == 1) {
    uVar7 = uVar7 | 2;
  }
  if ((unaff_EBX & 0x10) != 0) {
    uVar7 = uVar7 | 0x80;
  }
  if ((unaff_EBX & 0x300) == 0) {
    if (DAT_0003fc11 != 0x200) goto LAB_00028765;
  }
  else if ((unaff_EBX & 0x200) == 0) goto LAB_00028765;
  uVar7 = uVar7 | 0x40;
LAB_00028765:
  FUN_0002e679(uVar9,uVar7);
  return uVar9;
}

