
undefined8
FUN_00021b70(undefined4 param_1,undefined4 param_2,undefined *unaff_EBX,undefined *param_4)

{
  longlong lVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *unaff_ESI;
  undefined *unaff_EDI;
  
  puVar4 = param_4;
  puVar3 = unaff_EBX;
  if ((int)unaff_ESI < (int)unaff_EBX) {
    puVar4 = unaff_EDI;
    puVar3 = unaff_ESI;
    unaff_ESI = unaff_EBX;
    unaff_EDI = param_4;
  }
  if (((int)puVar3 < (int)PTR_LAB_0003ee64) && ((int)PTR_LAB_0003ee64 < (int)unaff_ESI)) {
    DAT_0003ee74 = (int)(CONCAT44((int)PTR_LAB_0003ee64 - (int)puVar3 >> 0x10,
                                  ((int)PTR_LAB_0003ee64 - (int)puVar3) * 0x10000) /
                        (longlong)((int)unaff_ESI - (int)puVar3));
    lVar1 = (longlong)(int)puVar4 * (longlong)(0x10000 - DAT_0003ee74);
    puVar4 = (undefined *)
             (((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) +
             ((uint)((longlong)(int)unaff_EDI * (longlong)DAT_0003ee74) >> 0x10 |
             (int)((ulonglong)((longlong)(int)unaff_EDI * (longlong)DAT_0003ee74) >> 0x20) << 0x10))
    ;
    puVar3 = PTR_LAB_0003ee64;
  }
  if (((int)puVar3 <= (int)DAT_0003ee68) && ((int)DAT_0003ee68 < (int)unaff_ESI)) {
    DAT_0003ee74 = (int)(CONCAT44((int)DAT_0003ee68 - (int)puVar3 >> 0x10,
                                  ((int)DAT_0003ee68 - (int)puVar3) * 0x10000) /
                        (longlong)((int)unaff_ESI - (int)puVar3));
    lVar1 = (longlong)(int)puVar4 * (longlong)(0x10000 - DAT_0003ee74);
    unaff_EDI = (undefined *)
                (((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) +
                ((uint)((longlong)(int)unaff_EDI * (longlong)DAT_0003ee74) >> 0x10 |
                (int)((ulonglong)((longlong)(int)unaff_EDI * (longlong)DAT_0003ee74) >> 0x20) <<
                0x10));
    unaff_ESI = DAT_0003ee68;
  }
  puVar2 = puVar4;
  puVar5 = puVar3;
  if ((int)unaff_EDI < (int)puVar4) {
    puVar2 = unaff_EDI;
    puVar5 = unaff_ESI;
    unaff_ESI = puVar3;
    unaff_EDI = puVar4;
  }
  if (((int)puVar2 < (int)PTR_LAB_0003ee6c) && ((int)PTR_LAB_0003ee6c < (int)unaff_EDI)) {
    DAT_0003ee74 = (int)(CONCAT44((int)PTR_LAB_0003ee6c - (int)puVar2 >> 0x10,
                                  ((int)PTR_LAB_0003ee6c - (int)puVar2) * 0x10000) /
                        (longlong)((int)unaff_EDI - (int)puVar2));
    lVar1 = (longlong)(int)puVar5 * (longlong)(0x10000 - DAT_0003ee74);
    puVar5 = (undefined *)
             (((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) +
             ((uint)((longlong)DAT_0003ee74 * (longlong)(int)unaff_ESI) >> 0x10 |
             (int)((ulonglong)((longlong)DAT_0003ee74 * (longlong)(int)unaff_ESI) >> 0x20) << 0x10))
    ;
    puVar2 = PTR_LAB_0003ee6c;
  }
  if (((int)DAT_0003ee70 < (int)unaff_EDI) && ((int)puVar2 < (int)DAT_0003ee70)) {
    DAT_0003ee74 = (int)(CONCAT44((int)DAT_0003ee70 - (int)puVar2 >> 0x10,
                                  ((int)DAT_0003ee70 - (int)puVar2) * 0x10000) /
                        (longlong)((int)unaff_EDI - (int)puVar2));
    lVar1 = (longlong)(int)puVar5 * (longlong)(0x10000 - DAT_0003ee74);
    unaff_ESI = (undefined *)
                (((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) +
                ((uint)((longlong)DAT_0003ee74 * (longlong)(int)unaff_ESI) >> 0x10 |
                (int)((ulonglong)((longlong)DAT_0003ee74 * (longlong)(int)unaff_ESI) >> 0x20) <<
                0x10));
    unaff_EDI = DAT_0003ee70;
  }
  DAT_0003ee90 = param_1;
  if ((((((int)PTR_LAB_0003ee64 <= (int)puVar5) && ((int)puVar5 <= (int)DAT_0003ee68)) &&
       ((int)PTR_LAB_0003ee6c <= (int)puVar2)) &&
      (((int)puVar2 <= (int)DAT_0003ee70 && ((int)PTR_LAB_0003ee64 <= (int)unaff_ESI)))) &&
     (((int)unaff_ESI <= (int)DAT_0003ee68 &&
      (((int)PTR_LAB_0003ee6c <= (int)unaff_EDI && ((int)unaff_EDI <= (int)DAT_0003ee70)))))) {
    FUN_00021d1c(param_1);
  }
  return CONCAT44(param_2,param_1);
}

