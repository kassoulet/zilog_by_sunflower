
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00037726(void)

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
  undefined2 extraout_DX_01;
  
  sVar4 = DAT_00036456 + 0x103;
  out(sVar4,0x4c);
  uVar5 = CONCAT11((char)((ushort)sVar4 >> 8),(char)sVar4 + '\x02');
  out(uVar5,7);
  iVar2 = 0x100;
  do {
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_000375a1(1,uVar5,0x19);
  ram0x0003724d = 0;
  uVar5 = extraout_DX;
  do {
    FUN_000376de(0x55,uVar5,0x19,ram0x0003724d);
    FUN_000376de(0xaa,extraout_DX_00,0x19,extraout_ECX + 1);
    cVar1 = FUN_000376b4();
    uVar3 = extraout_ECX_00;
    if (cVar1 != -0x56) break;
    cVar1 = FUN_000376b4();
    uVar3 = extraout_ECX_01;
    if (cVar1 != 'U') break;
    uVar3 = extraout_ECX_01 + 0x40000;
    uVar5 = extraout_DX_01;
    unique0x10000052 = uVar3;
  } while (uVar3 != 0x1000000);
  if (1 < uVar3) {
    return;
  }
  return;
}

