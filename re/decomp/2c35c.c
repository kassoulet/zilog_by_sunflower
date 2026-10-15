
void FUN_0002c35c(int param_1,int param_2,int unaff_EBX,int param_4,int param_5,int param_6,
                 undefined4 param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  
  iVar4 = 1;
  iVar8 = *(int *)(param_1 + 4);
  iVar2 = param_1 + 0x18;
  iVar7 = iVar8;
  iVar5 = iVar8;
  iVar6 = param_1;
  DAT_0004135c = param_1;
  DAT_00041350 = param_1;
  if (1 < param_2) {
    do {
      iVar1 = *(int *)(iVar2 + 4);
      iVar8 = iVar1;
      DAT_0004135c = iVar2;
      if ((iVar7 <= iVar1) && (iVar8 = iVar7, DAT_0004135c = iVar6, iVar5 < iVar1)) {
        iVar5 = iVar1;
        DAT_00041350 = iVar2;
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 0x18;
      iVar7 = iVar8;
      iVar6 = DAT_0004135c;
    } while (iVar4 < param_2);
  }
  DAT_00041358 = iVar2 + -0x18;
  bVar9 = DAT_0004135c == DAT_00041350;
  DAT_00041354 = param_1;
  DAT_00041360 = DAT_0004135c;
  while( true ) {
    if (bVar9) {
      return;
    }
    FUN_0002c0a0();
    if (0 < DAT_00041364) break;
    bVar9 = DAT_0004135c == DAT_00041350;
  }
  do {
    if (DAT_00041360 == DAT_00041350) {
      return;
    }
    FUN_0002c16c();
  } while (DAT_00041368 < 1);
  DAT_000413a0 = param_5;
  DAT_000413a4 = param_6;
  iVar8 = DAT_00040304[2] + (iVar8 + 0xffff >> 0x10) * *DAT_00040304 * 4;
  DAT_000413a8 = param_7;
  DAT_0004139c = param_4;
  do {
    while( true ) {
      iVar7 = DAT_00041374 + 0xffff >> 0x10;
      uVar3 = (DAT_0004136c + 0xffff >> 0x10) - iVar7;
      if (0 < (int)uVar3) {
        iVar5 = iVar7 * 0x10000 - DAT_00041374;
        iVar6 = DAT_0004137c +
                ((uint)((longlong)iVar5 * (longlong)param_4) >> 0x10 |
                (int)((ulonglong)((longlong)iVar5 * (longlong)param_4) >> 0x20) << 0x10);
        iVar2 = DAT_00041380 +
                ((uint)((longlong)iVar5 * (longlong)param_6) >> 0x10 |
                (int)((ulonglong)((longlong)iVar5 * (longlong)param_6) >> 0x20) << 0x10);
        FUN_0002f2b4(iVar6,iVar2,unaff_EBX >> 2 | uVar3 & 0xffff,
                     DAT_0004138c +
                     ((uint)((longlong)iVar5 * (longlong)param_5) >> 0x10 |
                     (int)((ulonglong)((longlong)iVar5 * (longlong)param_5) >> 0x20) << 0x10),iVar6,
                     iVar2,iVar7 * 4 + iVar8);
      }
      DAT_00041364 = DAT_00041364 + -1;
      iVar8 = iVar8 + *DAT_00040304 * 4;
      if (DAT_00041364 < 1) {
        do {
          if (DAT_0004135c == DAT_00041350) {
            return;
          }
          FUN_0002c0a0();
        } while (DAT_00041364 < 1);
      }
      else {
        DAT_0004136c = DAT_0004136c + DAT_00041370;
      }
      DAT_00041368 = DAT_00041368 + -1;
      if (DAT_00041368 < 1) break;
      DAT_00041374 = DAT_00041374 + DAT_00041378;
      DAT_0004137c = DAT_0004137c + DAT_00041384;
      DAT_0004138c = DAT_0004138c + DAT_00041394;
      DAT_00041380 = DAT_00041380 + DAT_00041388;
      DAT_00041390 = DAT_00041390 + DAT_00041398;
    }
    do {
      if (DAT_00041360 == DAT_00041350) {
        return;
      }
      FUN_0002c16c();
    } while (DAT_00041368 < 1);
  } while( true );
}

