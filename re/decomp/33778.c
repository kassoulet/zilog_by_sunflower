
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00033778(undefined2 param_1,undefined4 param_2,undefined4 unaff_EBX)

{
  undefined2 *puVar1;
  code *pcVar2;
  int extraout_ECX;
  int extraout_ECX_00;
  uint extraout_EDX;
  uint extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined2 uVar3;
  undefined2 in_ES;
  
  puVar1 = (undefined2 *)segment(param_1,0x2c);
  uVar3 = (undefined2)((uint)unaff_EBX >> 0x10);
  pcVar2 = (code *)swi(0x31);
  (*pcVar2)(6,0,CONCAT22(uVar3,*puVar1));
  DAT_00033770 = extraout_EDX & 0xffff | extraout_ECX << 0x10;
  pcVar2 = (code *)swi(0x31);
  (*pcVar2)(6,0);
  _DAT_0003376c = extraout_EDX_00 & 0xffff | extraout_ECX_00 << 0x10;
  DAT_00033768 = 0;
  FUN_00033900();
  DAT_00033760 = extraout_EDX_01;
  DAT_00033764 = CONCAT22(uVar3,in_ES);
  return;
}

