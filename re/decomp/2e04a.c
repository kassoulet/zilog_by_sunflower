
undefined8 func_2e04a(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  byte bVar3;
  
  iVar2 = CONCAT22((short)((uint)param_1 >> 0x10),CONCAT11(DAT_0003ed42,(char)param_1));
  DAT_0003fd90 = 0x8000;
  if ((DAT_0003ed42 < 2) || (8 < DAT_0003ed42)) {
    iVar2 = FUN_0002f6d8();
    if (iVar2 == 1) {
      bVar3 = 0;
      pcVar1 = (code *)swi(0x31);
      (*pcVar1)(0x600,0,0x3b08,CONCAT22(extraout_var_00,2));
      iVar2 = CONCAT22(extraout_var,-(ushort)bVar3);
    }
  }
  return CONCAT44(param_2,iVar2);
}

