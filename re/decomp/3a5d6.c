
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0003a5d6(undefined2 param_1,uint param_2,int unaff_EBX)

{
  uint uVar1;
  undefined2 uVar2;
  ushort extraout_CX;
  ushort extraout_CX_00;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  uint extraout_EDX;
  uint extraout_EDX_00;
  undefined3 uVar7;
  int iVar6;
  undefined3 uVar8;
  int unaff_EBP;
  undefined1 *unaff_ESI;
  undefined1 *puVar9;
  short *unaff_EDI;
  undefined1 uVar10;
  bool bVar11;
  
  DAT_000398a0 = param_2 >> 1;
  uVar10 = CARRY4(DAT_000398a4,DAT_000398aa >> 1);
  DAT_000398a4 = DAT_000398a4 + (DAT_000398aa >> 1);
  uVar2 = FUN_00039f4f(param_1,DAT_000398a0);
  uVar5 = extraout_CX;
  uVar1 = extraout_EDX;
  iVar6 = DAT_000398a4;
  while (DAT_000398a4 = iVar6, !(bool)uVar10) {
    uVar2 = FUN_0003a6e0(uVar2,iVar6);
    uVar10 = DAT_000398a0 < 0x10;
    uVar2 = FUN_00039f4f(uVar2,DAT_000398a0 - 0x10);
    uVar5 = extraout_CX_00;
    uVar1 = extraout_EDX_00;
    DAT_000398a0 = extraout_EDX_00;
    iVar6 = DAT_000398a4;
  }
  if ((uVar1 != 0) && ((DAT_00039896 != 0 || (unaff_ESI < DAT_00039892)))) {
    do {
      uVar10 = *unaff_ESI;
      uVar8 = (undefined3)((uint)unaff_EBX >> 8);
      uVar3 = uVar5 + _DAT_0003989a;
      puVar9 = unaff_ESI + (uint)CARRY2(uVar5,_DAT_0003989a) + unaff_EBP;
      uVar7 = (undefined3)((uint)iVar6 >> 8);
      *unaff_EDI = *unaff_EDI + *(short *)(CONCAT31(uVar8,uVar10) * 2);
      unaff_EDI[1] = unaff_EDI[1] + *(short *)(CONCAT31(uVar7,uVar10) * 2);
      uVar10 = *puVar9;
      uVar4 = uVar3 + _DAT_0003989a;
      puVar9 = puVar9 + (uint)CARRY2(uVar3,_DAT_0003989a) + unaff_EBP;
      unaff_EDI[2] = unaff_EDI[2] + *(short *)(CONCAT31(uVar8,uVar10) * 2);
      unaff_EDI[3] = unaff_EDI[3] + *(short *)(CONCAT31(uVar7,uVar10) * 2);
      uVar10 = *puVar9;
      bVar11 = CARRY2(uVar4,_DAT_0003989a);
      uVar4 = uVar4 + _DAT_0003989a;
      unaff_EDI[4] = unaff_EDI[4] + *(short *)(CONCAT31(uVar8,uVar10) * 2);
      unaff_EDI[5] = unaff_EDI[5] + *(short *)(CONCAT31(uVar7,uVar10) * 2);
      uVar10 = puVar9[(uint)bVar11 + unaff_EBP];
      unaff_EBX = CONCAT31(uVar8,uVar10);
      uVar5 = uVar4 + _DAT_0003989a;
      unaff_ESI = puVar9 + (uint)bVar11 + unaff_EBP + (uint)CARRY2(uVar4,_DAT_0003989a) + unaff_EBP;
      iVar6 = CONCAT31(uVar7,uVar10);
      unaff_EDI[6] = unaff_EDI[6] + *(short *)(unaff_EBX * 2);
      unaff_EDI[7] = unaff_EDI[7] + *(short *)(iVar6 * 2);
      unaff_EDI = unaff_EDI + 8;
      DAT_000398a0 = DAT_000398a0 - 1;
    } while (DAT_000398a0 != 0);
  }
  return;
}

