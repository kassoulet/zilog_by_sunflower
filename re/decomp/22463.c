
undefined8 FUN_00022463(uint param_1,undefined4 param_2,undefined *unaff_EBX,undefined *param_4)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *unaff_ESI;
  undefined *unaff_EDI;
  
  if ((short)param_1 != 0) {
    DAT_000221f4 = ((param_1 & 0xffff) >> 8) << 0x10;
    uVar2 = (param_1 & 0xff) << 0x10;
    uVar3 = uVar2;
    puVar6 = param_4;
    puVar5 = unaff_EBX;
    if ((int)unaff_ESI < (int)unaff_EBX) {
      LOCK();
      UNLOCK();
      uVar3 = DAT_000221f4;
      puVar6 = unaff_EDI;
      puVar5 = unaff_ESI;
      unaff_ESI = unaff_EBX;
      unaff_EDI = param_4;
      DAT_000221f4 = uVar2;
    }
    DAT_0003ee90 = uVar3;
    if (((int)puVar5 < (int)PTR_LAB_0003ee64) && ((int)PTR_LAB_0003ee64 < (int)unaff_ESI)) {
      DAT_0003ee74 = (int)(CONCAT44((int)PTR_LAB_0003ee64 - (int)puVar5 >> 0x10,
                                    ((int)PTR_LAB_0003ee64 - (int)puVar5) * 0x10000) /
                          (longlong)((int)unaff_ESI - (int)puVar5));
      lVar1 = (longlong)(int)puVar6 * (longlong)(0x10000 - DAT_0003ee74);
      puVar6 = (undefined *)
               (((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) +
               ((uint)((longlong)(int)unaff_EDI * (longlong)DAT_0003ee74) >> 0x10 |
               (int)((ulonglong)((longlong)(int)unaff_EDI * (longlong)DAT_0003ee74) >> 0x20) << 0x10
               ));
      lVar1 = (longlong)(int)uVar3 * (longlong)(0x10000 - DAT_0003ee74);
      uVar3 = (uint)((longlong)(int)DAT_000221f4 * (longlong)DAT_0003ee74) >> 0x10 |
              (int)((ulonglong)((longlong)(int)DAT_000221f4 * (longlong)DAT_0003ee74) >> 0x20) <<
              0x10;
      DAT_0003ee90 = ((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) + uVar3;
      puVar5 = PTR_LAB_0003ee64;
    }
    if (((int)puVar5 <= (int)DAT_0003ee68) && ((int)DAT_0003ee68 < (int)unaff_ESI)) {
      DAT_0003ee74 = (int)(CONCAT44((int)DAT_0003ee68 - (int)puVar5 >> 0x10,
                                    ((int)DAT_0003ee68 - (int)puVar5) * 0x10000) /
                          (longlong)((int)unaff_ESI - (int)puVar5));
      lVar1 = (longlong)(int)puVar6 * (longlong)(0x10000 - DAT_0003ee74);
      unaff_EDI = (undefined *)
                  (((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) +
                  ((uint)((longlong)(int)unaff_EDI * (longlong)DAT_0003ee74) >> 0x10 |
                  (int)((ulonglong)((longlong)(int)unaff_EDI * (longlong)DAT_0003ee74) >> 0x20) <<
                  0x10));
      lVar1 = (longlong)(int)DAT_0003ee90 * (longlong)(0x10000 - DAT_0003ee74);
      uVar3 = (uint)((longlong)(int)DAT_000221f4 * (longlong)DAT_0003ee74) >> 0x10 |
              (int)((ulonglong)((longlong)(int)DAT_000221f4 * (longlong)DAT_0003ee74) >> 0x20) <<
              0x10;
      DAT_000221f4 = ((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) + uVar3;
      unaff_ESI = DAT_0003ee68;
    }
    uVar2 = DAT_000221f4;
    puVar4 = puVar6;
    puVar7 = puVar5;
    if ((int)unaff_EDI < (int)puVar6) {
      LOCK();
      DAT_000221f4 = DAT_0003ee90;
      UNLOCK();
      DAT_0003ee90 = uVar2;
      uVar3 = uVar2;
      puVar4 = unaff_EDI;
      puVar7 = unaff_ESI;
      unaff_ESI = puVar5;
      unaff_EDI = puVar6;
    }
    if (((int)puVar4 < (int)PTR_LAB_0003ee6c) && ((int)PTR_LAB_0003ee6c < (int)unaff_EDI)) {
      DAT_0003ee74 = (int)(CONCAT44((int)PTR_LAB_0003ee6c - (int)puVar4 >> 0x10,
                                    ((int)PTR_LAB_0003ee6c - (int)puVar4) * 0x10000) /
                          (longlong)((int)unaff_EDI - (int)puVar4));
      lVar1 = (longlong)(int)puVar7 * (longlong)(0x10000 - DAT_0003ee74);
      puVar7 = (undefined *)
               (((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) +
               ((uint)((longlong)DAT_0003ee74 * (longlong)(int)unaff_ESI) >> 0x10 |
               (int)((ulonglong)((longlong)DAT_0003ee74 * (longlong)(int)unaff_ESI) >> 0x20) << 0x10
               ));
      lVar1 = (longlong)(int)DAT_0003ee90 * (longlong)(0x10000 - DAT_0003ee74);
      uVar3 = (uint)((longlong)(int)DAT_000221f4 * (longlong)DAT_0003ee74) >> 0x10 |
              (int)((ulonglong)((longlong)(int)DAT_000221f4 * (longlong)DAT_0003ee74) >> 0x20) <<
              0x10;
      DAT_0003ee90 = ((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) + uVar3;
      puVar4 = PTR_LAB_0003ee6c;
    }
    if (((int)DAT_0003ee70 < (int)unaff_EDI) && ((int)puVar4 < (int)DAT_0003ee70)) {
      DAT_0003ee74 = (int)(CONCAT44((int)DAT_0003ee70 - (int)puVar4 >> 0x10,
                                    ((int)DAT_0003ee70 - (int)puVar4) * 0x10000) /
                          (longlong)((int)unaff_EDI - (int)puVar4));
      lVar1 = (longlong)(int)puVar7 * (longlong)(0x10000 - DAT_0003ee74);
      unaff_ESI = (undefined *)
                  (((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) +
                  ((uint)((longlong)DAT_0003ee74 * (longlong)(int)unaff_ESI) >> 0x10 |
                  (int)((ulonglong)((longlong)DAT_0003ee74 * (longlong)(int)unaff_ESI) >> 0x20) <<
                  0x10));
      lVar1 = (longlong)(int)DAT_0003ee90 * (longlong)(0x10000 - DAT_0003ee74);
      uVar3 = (uint)((longlong)(int)DAT_000221f4 * (longlong)DAT_0003ee74) >> 0x10 |
              (int)((ulonglong)((longlong)(int)DAT_000221f4 * (longlong)DAT_0003ee74) >> 0x20) <<
              0x10;
      DAT_000221f4 = ((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) + uVar3;
      unaff_EDI = DAT_0003ee70;
    }
    if ((((((int)PTR_LAB_0003ee64 <= (int)puVar7) && ((int)puVar7 <= (int)DAT_0003ee68)) &&
         ((int)PTR_LAB_0003ee6c <= (int)puVar4)) &&
        (((int)puVar4 <= (int)DAT_0003ee70 && ((int)PTR_LAB_0003ee64 <= (int)unaff_ESI)))) &&
       (((int)unaff_ESI <= (int)DAT_0003ee68 &&
        (((int)PTR_LAB_0003ee6c <= (int)unaff_EDI && ((int)unaff_EDI <= (int)DAT_0003ee70)))))) {
      FUN_0002271c(CONCAT22((short)(uVar3 >> 0x10),CONCAT11(DAT_000221f4._2_1_,DAT_0003ee90._2_1_)))
      ;
    }
  }
  return CONCAT44(param_2,param_1);
}

