
uint FUN_0002eb49(undefined4 param_1,undefined4 param_2,uint unaff_EBX)

{
  code *pcVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint extraout_EDX;
  byte bVar5;
  uint uStack_14;
  
  uVar3 = FUN_0002e624();
  if ((uVar3 & 0x80) != 0) {
    bVar5 = 0;
    pcVar1 = (code *)swi(0x21);
    uVar3 = (*pcVar1)(0x4202,0,param_1,0);
    uStack_14 = uVar3 & 0xffff;
    if ((bVar5 & 1) != 0) goto LAB_0002eb81;
  }
  bVar5 = 0;
  pcVar1 = (code *)swi(0x21);
  iVar4 = (*pcVar1)(CONCAT11(0x40,(char)uVar3),param_2,param_1,unaff_EBX);
  bVar2 = (bVar5 & 1) != 0;
  uStack_14 = (iVar4 << 1 | (uint)bVar5) >> 1 | (uint)bVar2 << 0x1f;
  if (!bVar2) {
    if (uStack_14 == unaff_EBX) {
      return uStack_14;
    }
    FUN_000284cf(0xc);
    return extraout_EDX;
  }
LAB_0002eb81:
  uVar3 = FUN_0002e6c3(uStack_14 & 0xffff);
  return uVar3;
}

