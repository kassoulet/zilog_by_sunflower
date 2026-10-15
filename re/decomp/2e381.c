
longdouble FUN_0002e381(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_EDX;
  undefined8 local_1c;
  undefined1 uStack_14;
  byte bStack_13;
  undefined8 local_10;
  
  iVar3 = FUN_0002e1ed(param_1,&local_1c,param_2);
  if (iVar3 == 0) {
    uVar4 = 0;
    uVar1 = 0;
  }
  else {
    uVar2 = CONCAT11(bStack_13,uStack_14) & 0x7fff;
    if (uVar2 < 0x43ff) {
      if (uVar2 < 0x3bcd) {
        FUN_000284e2(uVar2,0);
        local_10 = (double)CONCAT44(extraout_EDX,extraout_EDX);
      }
      else {
        local_10 = (double)(longdouble)CONCAT19(bStack_13,CONCAT18(uStack_14,local_1c));
      }
      goto LAB_0002e3f7;
    }
    FUN_000284e2();
    uVar4 = DAT_0003ed04;
    uVar1 = DAT_0003ed00;
    if ((bStack_13 & 0x80) != 0) {
      local_10 = -(double)CONCAT44(DAT_0003ed04,DAT_0003ed00);
      goto LAB_0002e3f7;
    }
  }
  local_10 = (double)CONCAT44(uVar4,uVar1);
LAB_0002e3f7:
  return (longdouble)local_10;
}

