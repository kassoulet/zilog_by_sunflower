
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0003b0e6(undefined4 param_1,uint param_2,int unaff_EBX)

{
  uint uVar1;
  undefined4 uVar2;
  ushort uVar3;
  ushort uVar4;
  int extraout_ECX;
  int extraout_ECX_00;
  undefined2 uVar5;
  uint extraout_EDX;
  uint extraout_EDX_00;
  int iVar6;
  int iVar7;
  undefined3 uVar8;
  int unaff_EBP;
  undefined1 *unaff_ESI;
  undefined1 *puVar9;
  int *unaff_EDI;
  undefined1 in_CF;
  
  DAT_000398a0 = param_2;
  FUN_00039f4f();
  iVar7 = extraout_ECX;
  uVar1 = extraout_EDX;
  while (!(bool)in_CF) {
    uVar2 = FUN_0003b1e8();
    in_CF = DAT_000398a0 < 0x10;
    FUN_00039f4f(uVar2,DAT_000398a0 - 0x10);
    iVar7 = extraout_ECX_00;
    uVar1 = extraout_EDX_00;
    DAT_000398a0 = extraout_EDX_00;
  }
  if ((uVar1 != 0) && ((DAT_00039896 != 0 || (unaff_ESI < DAT_00039892)))) {
    do {
      uVar8 = (undefined3)((uint)unaff_EBX >> 8);
      iVar6 = (int)*(short *)(CONCAT31(uVar8,*unaff_ESI) * 2);
      *unaff_EDI = *unaff_EDI +
                   iVar6 * 0x10000 + (*(short *)(CONCAT31(uVar8,unaff_ESI[1]) * 2) - iVar6) * iVar7;
      uVar5 = (undefined2)((uint)iVar7 >> 0x10);
      uVar3 = (ushort)iVar7 + _DAT_0003989a;
      puVar9 = unaff_ESI + (uint)CARRY2((ushort)iVar7,_DAT_0003989a) + unaff_EBP;
      iVar7 = (int)*(short *)(CONCAT31(uVar8,*puVar9) * 2);
      unaff_EDI[1] = unaff_EDI[1] +
                     iVar7 * 0x10000 +
                     (*(short *)(CONCAT31(uVar8,puVar9[1]) * 2) - iVar7) * CONCAT22(uVar5,uVar3);
      uVar4 = uVar3 + _DAT_0003989a;
      puVar9 = puVar9 + (uint)CARRY2(uVar3,_DAT_0003989a) + unaff_EBP;
      iVar7 = (int)*(short *)(CONCAT31(uVar8,*puVar9) * 2);
      unaff_EDI[2] = unaff_EDI[2] +
                     iVar7 * 0x10000 +
                     (*(short *)(CONCAT31(uVar8,puVar9[1]) * 2) - iVar7) * CONCAT22(uVar5,uVar4);
      uVar3 = uVar4 + _DAT_0003989a;
      puVar9 = puVar9 + (uint)CARRY2(uVar4,_DAT_0003989a) + unaff_EBP;
      iVar7 = (int)*(short *)(CONCAT31(uVar8,*puVar9) * 2);
      unaff_EBX = CONCAT31(uVar8,puVar9[1]);
      unaff_EDI[3] = unaff_EDI[3] +
                     iVar7 * 0x10000 + (*(short *)(unaff_EBX * 2) - iVar7) * CONCAT22(uVar5,uVar3);
      iVar7 = CONCAT22(uVar5,uVar3 + _DAT_0003989a);
      unaff_ESI = puVar9 + (uint)CARRY2(uVar3,_DAT_0003989a) + unaff_EBP;
      unaff_EDI = unaff_EDI + 4;
      DAT_000398a0 = DAT_000398a0 - 1;
    } while (DAT_000398a0 != 0);
  }
  return;
}

