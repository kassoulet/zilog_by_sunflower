
void FUN_00037099(int param_1,undefined4 param_2,undefined4 unaff_EBX)

{
  code *pcVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 uVar2;
  bool in_CF;
  
  if (in_CF) {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)(CONCAT11(9,(char)param_1),&DAT_000370a3);
    uVar2 = extraout_ECX;
    if (param_1 == 1) {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)(0x901,&DAT_000370c6);
      uVar2 = extraout_ECX_00;
    }
    if (param_1 == 2) {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)(0x902,&DAT_000370ec);
      uVar2 = extraout_ECX_01;
    }
    if (param_1 == 3) {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)(0x903,&DAT_00037111);
      uVar2 = extraout_ECX_02;
    }
    if (param_1 == 4) {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)(0x904,&DAT_0003713e,unaff_EBX,uVar2,4);
    }
  }
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)(0x4c00,param_2);
  return;
}

