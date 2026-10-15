
undefined8 FUN_0002f6d8(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  short sVar2;
  undefined2 uVar3;
  undefined2 in_DS;
  
  if (DAT_0003ff0c != 0) goto LAB_0002f756;
  if (DAT_0003ed42 == '\x01') {
LAB_0002f6fc:
    pcVar1 = (code *)swi(0x31);
    uVar3 = (*pcVar1)(0x400,in_DS);
    if ((uint)(byte)((ushort)uVar3 >> 8) + (uint)(byte)uVar3 != 0) {
      DAT_0003ff0c = 1;
      goto LAB_0002f756;
    }
  }
  else {
    pcVar1 = (code *)swi(0x2f);
    sVar2 = (*pcVar1)(0x1686);
    if (sVar2 == 0) goto LAB_0002f6fc;
  }
  DAT_0003ff0c = -1;
LAB_0002f756:
  return CONCAT44(param_2,DAT_0003ff0c);
}

