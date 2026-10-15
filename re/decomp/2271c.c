
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0002271c(uint param_1,undefined4 param_2,int unaff_EBX,int param_4)

{
  longlong lVar1;
  undefined3 uVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined2 uVar8;
  undefined1 *puVar7;
  int iVar9;
  int iVar10;
  int iVar11;
  int unaff_ESI;
  int iVar12;
  int unaff_EDI;
  uint *puVar13;
  
  iVar10 = (param_1 >> 8 & 0xff) << 0x10;
  DAT_000221f4 = iVar10;
  DAT_0003ee90 = (param_1 & 0xff) << 0x10;
  DAT_0003eea0 = 1;
  iVar4 = unaff_ESI - unaff_EBX;
  DAT_0003ee94 = iVar4;
  DAT_0003ee98 = unaff_EDI - param_4;
  iVar5 = iVar4;
  if (iVar4 < 0) {
    iVar5 = -iVar4;
  }
  iVar11 = DAT_0003ee98;
  if (DAT_0003ee98 < 0) {
    iVar11 = -DAT_0003ee98;
  }
  if ((iVar5 == 0) && (iVar11 == 0)) {
    return CONCAT44(param_2,param_1);
  }
  iVar9 = param_4;
  iVar12 = unaff_ESI;
  if (iVar5 <= iVar11) {
    LOCK();
    UNLOCK();
    iVar9 = unaff_EBX;
    unaff_EBX = param_4;
    iVar12 = unaff_EDI;
    unaff_EDI = unaff_ESI;
    DAT_0003ee94 = DAT_0003ee98;
    DAT_0003ee98 = iVar4;
  }
  DAT_0003eea0 = (uint)(iVar5 > iVar11);
  iVar5 = unaff_EBX;
  if (iVar12 < unaff_EBX) {
    LOCK();
    UNLOCK();
    DAT_0003ee94 = -DAT_0003ee94;
    DAT_0003ee98 = -DAT_0003ee98;
    iVar9 = unaff_EDI;
    iVar5 = iVar12;
    iVar12 = unaff_EBX;
    DAT_000221f4 = DAT_0003ee90;
    DAT_0003ee90 = iVar10;
  }
  DAT_000221f8 = (int)((longlong)((ulonglong)(uint)(DAT_000221f4 - DAT_0003ee90 >> 0x10) << 0x20) /
                      (longlong)DAT_0003ee94);
  DAT_0003ee84 = (int)(CONCAT44(DAT_0003ee98 >> 0x10,DAT_0003ee98 << 0x10) / (longlong)DAT_0003ee94)
  ;
  uVar6 = iVar5 + 0x8000U & 0xffff0000;
  _DAT_0003ee7a = 0;
  DAT_0003ee7c._0_2_ = (undefined2)(uVar6 >> 0x10);
  lVar1 = (longlong)(int)(uVar6 - iVar5) * (longlong)DAT_0003ee84;
  DAT_0003ee9c = ((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) + iVar9;
  DAT_0003ee80 = iVar12 + 0x8000 >> 0x10;
  iVar5 = CONCAT22(DAT_0003ee7c._2_2_,(undefined2)DAT_0003ee7c);
  puVar7 = DAT_000402f8;
  do {
    uVar8 = (undefined2)((uint)puVar7 >> 0x10);
    uVar3 = (undefined1)((uint)DAT_0003ee90 >> 0x10);
    if (DAT_0003eea0 == 0) {
      puVar13 = (uint *)((iVar5 * 0x140 + (DAT_0003ee9c >> 0x10)) * 4 + DAT_000402f0);
      uVar6 = ~*puVar13;
      uVar2 = CONCAT21(uVar8,*(undefined1 *)
                              CONCAT22(uVar8,~CONCAT11((char)(0xffff - (DAT_0003ee9c & 0xffff) >> 8)
                                                       ,uVar3)));
      uVar3 = *(undefined1 *)CONCAT31(uVar2,(char)(uVar6 >> 8));
      *puVar13 = CONCAT22((ushort)(uVar6 >> 0x18),
                          CONCAT11(*(undefined1 *)CONCAT31(uVar2,(char)(uVar6 >> 0x10)),uVar3)) << 8
                 | CONCAT11(uVar3,*(undefined1 *)CONCAT31(uVar2,(char)uVar6)) & 0xff;
      uVar6 = ~puVar13[1];
      uVar2 = CONCAT21(uVar8,*(undefined1 *)
                              CONCAT22(uVar8,~CONCAT11((char)(DAT_0003ee9c >> 8),
                                                       (char)((uint)DAT_0003ee90 >> 0x10))));
      uVar3 = *(undefined1 *)CONCAT31(uVar2,(char)(uVar6 >> 8));
      puVar7 = (undefined1 *)CONCAT31(uVar2,(char)(uVar6 >> 0x10));
      puVar13[1] = CONCAT22((ushort)(uVar6 >> 0x18),CONCAT11(*puVar7,uVar3)) << 8 |
                   CONCAT11(uVar3,*(undefined1 *)CONCAT31(uVar2,(char)uVar6)) & 0xff;
    }
    else {
      puVar13 = (uint *)(((DAT_0003ee9c >> 0x10) * 0x140 + iVar5) * 4 + DAT_000402f0);
      uVar6 = ~*puVar13;
      uVar2 = CONCAT21(uVar8,*(undefined1 *)
                              CONCAT22(uVar8,~CONCAT11((char)(0xffff - (DAT_0003ee9c & 0xffff) >> 8)
                                                       ,uVar3)));
      uVar3 = *(undefined1 *)CONCAT31(uVar2,(char)(uVar6 >> 8));
      *puVar13 = CONCAT22((ushort)(uVar6 >> 0x18),
                          CONCAT11(*(undefined1 *)CONCAT31(uVar2,(char)(uVar6 >> 0x10)),uVar3)) << 8
                 | CONCAT11(uVar3,*(undefined1 *)CONCAT31(uVar2,(char)uVar6)) & 0xff;
      uVar6 = ~puVar13[0x140];
      uVar2 = CONCAT21(uVar8,*(undefined1 *)
                              CONCAT22(uVar8,~CONCAT11((char)(DAT_0003ee9c >> 8),
                                                       (char)((uint)DAT_0003ee90 >> 0x10))));
      uVar3 = *(undefined1 *)CONCAT31(uVar2,(char)(uVar6 >> 8));
      puVar7 = (undefined1 *)CONCAT31(uVar2,(char)(uVar6 >> 0x10));
      puVar13[0x140] =
           CONCAT22((ushort)(uVar6 >> 0x18),CONCAT11(*puVar7,uVar3)) << 8 |
           CONCAT11(uVar3,*(undefined1 *)CONCAT31(uVar2,(char)uVar6)) & 0xff;
    }
    DAT_0003ee90 = DAT_0003ee90 + DAT_000221f8;
    DAT_0003ee9c = DAT_0003ee9c + DAT_0003ee84;
    iVar5 = iVar5 + 1;
  } while (iVar5 < DAT_0003ee80);
  return CONCAT44(param_2,param_1);
}

