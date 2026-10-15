
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __regparm3 FUN_00039f80(void)

{
  undefined2 uVar1;
  ushort extraout_CX;
  ushort extraout_CX_00;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  int extraout_EDX;
  uint extraout_EDX_00;
  int extraout_EDX_01;
  int iVar5;
  int unaff_EBX;
  undefined3 uVar6;
  int unaff_EBP;
  undefined1 *unaff_ESI;
  undefined1 *puVar7;
  undefined1 *puVar8;
  short *unaff_EDI;
  undefined1 in_CF;
  bool bVar9;
  
  FUN_00039f4f();
  uVar4 = extraout_CX;
  iVar5 = extraout_EDX;
  while (!(bool)in_CF) {
    uVar1 = FUN_0003a010();
    in_CF = extraout_EDX_00 < 0x10;
    FUN_00039f4f(uVar1,extraout_EDX_00 - 0x10);
    uVar4 = extraout_CX_00;
    iVar5 = extraout_EDX_01;
  }
  if ((iVar5 != 0) && ((DAT_00039896 != 0 || (unaff_ESI < DAT_00039892)))) {
    do {
      uVar6 = (undefined3)((uint)unaff_EBX >> 8);
      uVar2 = uVar4 + _DAT_0003989a;
      puVar7 = unaff_ESI + (uint)CARRY2(uVar4,_DAT_0003989a) + unaff_EBP;
      *unaff_EDI = *unaff_EDI + *(short *)(CONCAT31(uVar6,*unaff_ESI) * 2);
      uVar3 = uVar2 + _DAT_0003989a;
      puVar8 = puVar7 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
      unaff_EDI[1] = unaff_EDI[1] + *(short *)(CONCAT31(uVar6,*puVar7) * 2);
      bVar9 = CARRY2(uVar3,_DAT_0003989a);
      uVar3 = uVar3 + _DAT_0003989a;
      unaff_EDI[2] = unaff_EDI[2] + *(short *)(CONCAT31(uVar6,*puVar8) * 2);
      unaff_EBX = CONCAT31(uVar6,puVar8[(uint)bVar9 + unaff_EBP]);
      uVar4 = uVar3 + _DAT_0003989a;
      unaff_ESI = puVar8 + (uint)bVar9 + unaff_EBP + (uint)CARRY2(uVar3,_DAT_0003989a) + unaff_EBP;
      unaff_EDI[3] = unaff_EDI[3] + *(short *)(unaff_EBX * 2);
      unaff_EDI = unaff_EDI + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return;
}

