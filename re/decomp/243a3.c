
undefined8 FUN_000243a3(uint param_1,undefined4 param_2)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int extraout_ECX;
  uint uVar5;
  undefined2 in_DS;
  undefined8 uVar6;
  
  if ((param_1 != 0) && (param_1 < 0xffffffd5)) {
    uVar5 = param_1 + 0xb & 0xfffffff8;
    if (uVar5 < 0x10) {
      uVar5 = 0x10;
    }
    iVar3 = 0;
    bVar2 = false;
LAB_000243da:
    do {
      if ((uVar5 <= DAT_0003eebc) || (iVar4 = DAT_0003eeb8, DAT_0003eeb8 == 0)) {
        DAT_0003eebc = 0;
        iVar4 = DAT_0003eeb4;
      }
      for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
        uVar1 = *(uint *)(iVar4 + 0x14);
        DAT_0003eeb8 = iVar4;
        if ((param_1 <= uVar1) &&
           (iVar3 = FUN_00028f00(param_1,in_DS,iVar4), iVar4 = extraout_ECX, iVar3 != 0))
        goto LAB_0002446b;
        if (DAT_0003eebc < uVar1) {
          DAT_0003eebc = uVar1;
        }
      }
      if (!bVar2) {
        uVar6 = FUN_000294df(param_1,iVar3);
        iVar3 = (int)((ulonglong)uVar6 >> 0x20);
        if ((int)uVar6 != 0) {
          bVar2 = true;
          goto LAB_000243da;
        }
      }
      uVar6 = FUN_000296a0(param_1);
      iVar3 = (int)((ulonglong)uVar6 >> 0x20);
      if ((int)uVar6 == 0) goto LAB_0002446b;
      bVar2 = false;
    } while( true );
  }
  iVar3 = 0;
LAB_00024475:
  return CONCAT44(param_2,iVar3);
LAB_0002446b:
  DAT_000411e0 = 0;
  goto LAB_00024475;
}

