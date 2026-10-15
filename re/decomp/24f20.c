
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_00024f20(undefined4 param_1,undefined4 param_2,undefined4 unaff_EBX,uint param_4)

{
  code *pcVar1;
  uint uVar2;
  undefined2 uVar3;
  int *piVar4;
  int iVar5;
  undefined2 extraout_var;
  short *psVar6;
  undefined1 *puVar7;
  short *psVar8;
  char *pcVar9;
  char *pcVar10;
  undefined1 in_CF;
  bool bVar11;
  byte bVar12;
  undefined8 uVar13;
  uint unaff_retaddr;
  undefined4 extraout_var_00;
  undefined4 uVar14;
  
  bVar12 = 0;
  pcVar1 = (code *)swi(0x31);
  uVar13 = (*pcVar1)(0x100,param_2,0x20);
  if ((bool)in_CF) {
    return (ulonglong)param_4 << 0x20;
  }
  piVar4 = (int *)(((uint)uVar13 & 0xffff) << 4);
  bVar11 = false;
  _DAT_0003ef26 = (undefined2)uVar13;
  DAT_0003f1c4 = (undefined2)((ulonglong)uVar13 >> 0x20);
  DAT_0003f1c0 = _DAT_0003ef26;
  DAT_0003f1c8 = piVar4;
  *piVar4 = 0x32454256;
  DAT_0003ef20 = 0x4f00;
  _DAT_0003ef04 = 0;
  pcVar1 = (code *)swi(0x31);
  uVar14 = extraout_var_00;
  (*pcVar1)(0x300,(int)((ulonglong)uVar13 >> 0x20),0x10,(uint)piVar4 & 0xffff0000);
  if (((!bVar11) && ((char)DAT_0003ef20 == 'O')) && (*DAT_0003f1c8 == 0x41534556)) {
    piVar4 = DAT_0003f1c8;
    puVar7 = &DAT_0003ef88;
    for (iVar5 = 0x200; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = (char)*piVar4;
      piVar4 = (int *)((int)piVar4 + (uint)bVar12 * -2 + 1);
      puVar7 = puVar7 + (uint)bVar12 * -2 + 1;
    }
    DAT_0003ef96 = &DAT_0003f1cc;
    psVar6 = (short *)((*(uint *)((int)DAT_0003f1c8 + 0xe) >> 0x10) * 0x10 +
                      (*(uint *)((int)DAT_0003f1c8 + 0xe) & 0xffff));
    psVar8 = &DAT_0003f1cc;
    while( true ) {
      if (*psVar6 == -1) break;
      *psVar8 = *psVar6;
      psVar6 = psVar6 + (uint)bVar12 * -2 + 1;
      psVar8 = psVar8 + (uint)bVar12 * -2 + 1;
    }
    DAT_0003ef8e = psVar8 + (uint)bVar12 * -2 + 1;
    *psVar8 = -1;
    pcVar10 = (char *)((*(uint *)((int)DAT_0003f1c8 + 6) >> 0x10) * 0x10 +
                      (*(uint *)((int)DAT_0003f1c8 + 6) & 0xffff));
    psVar6 = DAT_0003ef8e;
    while( true ) {
      if (*pcVar10 == '\0') break;
      *(char *)psVar6 = *pcVar10;
      pcVar10 = pcVar10 + (uint)bVar12 * -2 + 1;
      psVar6 = (short *)((int)psVar6 + (uint)bVar12 * -2 + 1);
    }
    DAT_0003ef9e = (char *)((int)psVar6 + (uint)bVar12 * -2 + 1);
    *(char *)psVar6 = '\0';
    if ((short)DAT_0003f1c8[1] < 0x200) {
      uVar2 = (uint)DAT_0003f1c8 & 0xffffff00;
      pcVar10 = DAT_0003ef9e + (uint)bVar12 * -2 + 1;
      DAT_0003efa2 = DAT_0003ef9e;
      DAT_0003efa6 = DAT_0003ef9e;
      *DAT_0003ef9e = '\0';
    }
    else {
      pcVar10 = (char *)((*(uint *)((int)DAT_0003f1c8 + 0x16) >> 0x10) * 0x10 +
                        (*(uint *)((int)DAT_0003f1c8 + 0x16) & 0xffff));
      pcVar9 = DAT_0003ef9e;
      while( true ) {
        if (*pcVar10 == '\0') break;
        *pcVar9 = *pcVar10;
        pcVar10 = pcVar10 + (uint)bVar12 * -2 + 1;
        pcVar9 = pcVar9 + (uint)bVar12 * -2 + 1;
      }
      DAT_0003efa2 = pcVar9 + (uint)bVar12 * -2 + 1;
      *pcVar9 = '\0';
      pcVar10 = (char *)((*(uint *)((int)DAT_0003f1c8 + 0x1a) >> 0x10) * 0x10 +
                        (*(uint *)((int)DAT_0003f1c8 + 0x1a) & 0xffff));
      pcVar9 = DAT_0003efa2;
      while( true ) {
        if (*pcVar10 == '\0') break;
        *pcVar9 = *pcVar10;
        pcVar10 = pcVar10 + (uint)bVar12 * -2 + 1;
        pcVar9 = pcVar9 + (uint)bVar12 * -2 + 1;
      }
      DAT_0003efa6 = pcVar9 + (uint)bVar12 * -2 + 1;
      *pcVar9 = '\0';
      pcVar10 = (char *)((*(uint *)((int)DAT_0003f1c8 + 0x1e) >> 0x10) * 0x10 +
                        (*(uint *)((int)DAT_0003f1c8 + 0x1e) & 0xffff));
      pcVar9 = DAT_0003efa6;
      while( true ) {
        if (*pcVar10 == '\0') break;
        *pcVar9 = *pcVar10;
        pcVar10 = pcVar10 + (uint)bVar12 * -2 + 1;
        pcVar9 = pcVar9 + (uint)bVar12 * -2 + 1;
      }
      uVar2 = 0;
      pcVar10 = pcVar9 + (uint)bVar12 * -2 + 1;
      *pcVar9 = '\0';
    }
    uVar3 = (undefined2)(uVar2 >> 0x10);
    if ((int)pcVar10 < 0x3f5cc) {
      iVar5 = 0;
      if (0x200 < DAT_0003ef8c) {
        iVar5 = 6;
        psVar6 = DAT_0003ef8e;
        do {
          uVar3 = (undefined2)(uVar2 >> 0x10);
          if (s_VORTEX_0003f5cc[0] != (char)*psVar6) goto LAB_000250e0;
          iVar5 = iVar5 + -1;
          uVar2 = CONCAT31((int3)(uVar2 >> 8),(char)*psVar6);
          psVar6 = (short *)((int)psVar6 + (uint)bVar12 * -2 + 1);
        } while (iVar5 != 0);
        DAT_0003ef8c = 0x102;
      }
LAB_000250e0:
      pcVar1 = (code *)swi(0x31);
      (*pcVar1)(CONCAT22(uVar3,0x101),CONCAT22(extraout_var,DAT_0003f1c4),0x10,iVar5,
                register0x00000010,unaff_EBX,param_2,param_4,uVar14);
      return CONCAT44(unaff_retaddr,&DAT_0003ef88);
    }
  }
  pcVar1 = (code *)swi(0x31);
  (*pcVar1)(0x101,CONCAT22(extraout_var,DAT_0003f1c4));
  return (ulonglong)unaff_retaddr << 0x20;
}

