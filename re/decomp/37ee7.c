
void __regparm3 FUN_00037ee7(void)

{
  char cVar1;
  int iVar2;
  int extraout_ECX;
  uint extraout_ECX_00;
  uint extraout_ECX_01;
  uint uVar3;
  short sVar4;
  undefined2 uVar5;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  undefined4 unaff_EBX;
  
  sVar4 = DAT_00036456 + 0x103;
  out(sVar4,0x4c);
  uVar5 = CONCAT11((char)((ushort)sVar4 >> 8),(char)sVar4 + '\x02');
  out(uVar5,7);
  iVar2 = 0x100;
  do {
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  DAT_00037a47 = 0;
  do {
    FUN_00037e9f(0x55,uVar5,unaff_EBX,DAT_00037a47);
    FUN_00037e9f(0xaa,extraout_DX,unaff_EBX,extraout_ECX + 1);
    cVar1 = FUN_00037e75();
    uVar3 = extraout_ECX_00;
    if (cVar1 != -0x56) break;
    cVar1 = FUN_00037e75();
    uVar3 = extraout_ECX_01;
    if (cVar1 != 'U') break;
    uVar3 = extraout_ECX_01 + 0x40000;
    uVar5 = extraout_DX_00;
    DAT_00037a47 = uVar3;
  } while (uVar3 != 0x100000);
  if (1 < uVar3) {
    return;
  }
  return;
}

