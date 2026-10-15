
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0003bd0e(undefined4 param_1,uint param_2,int unaff_EBX)

{
  char cVar1;
  undefined4 uVar2;
  ushort uVar3;
  ushort uVar4;
  int extraout_ECX;
  int extraout_ECX_00;
  undefined2 uVar6;
  int iVar5;
  undefined3 uVar8;
  int iVar7;
  undefined3 uVar9;
  char *unaff_ESI;
  char *pcVar10;
  short *unaff_EDI;
  undefined1 uVar11;
  undefined8 uVar12;
  
  DAT_000398a0 = param_2 >> 1;
  uVar11 = CARRY4(DAT_000398a4,DAT_000398aa >> 1);
  DAT_000398a4 = DAT_000398a4 + (DAT_000398aa >> 1);
  uVar12 = FUN_00039f4f(param_1,DAT_000398a0);
  iVar5 = extraout_ECX;
  iVar7 = DAT_000398a4;
  while( true ) {
    DAT_000398a4 = iVar7;
    if ((bool)uVar11) break;
    uVar2 = FUN_0003be6c((int)uVar12,iVar7);
    uVar11 = DAT_000398a0 < 0x10;
    uVar12 = FUN_00039f4f(uVar2,DAT_000398a0 - 0x10);
    DAT_000398a0 = (uint)((ulonglong)uVar12 >> 0x20);
    iVar5 = extraout_ECX_00;
    iVar7 = DAT_000398a4;
  }
  if (((int)((ulonglong)uVar12 >> 0x20) != 0) && ((DAT_00039896 != 0 || (unaff_ESI < DAT_00039892)))
     ) {
    do {
      cVar1 = *unaff_ESI + (char)((uint)(((int)unaff_ESI[1] - (int)*unaff_ESI) * iVar5) >> 0x10);
      uVar9 = (undefined3)((uint)unaff_EBX >> 8);
      *unaff_EDI = *unaff_EDI + *(short *)(CONCAT31(uVar9,cVar1) * 2);
      uVar8 = (undefined3)((uint)iVar7 >> 8);
      unaff_EDI[1] = unaff_EDI[1] + *(short *)(CONCAT31(uVar8,cVar1) * 2);
      uVar6 = (undefined2)((uint)iVar5 >> 0x10);
      uVar3 = (ushort)iVar5 + _DAT_0003989a;
      pcVar10 = unaff_ESI + (uint)CARRY2((ushort)iVar5,_DAT_0003989a) + _DAT_0003989c;
      cVar1 = *pcVar10 +
              (char)((uint)(((int)pcVar10[1] - (int)*pcVar10) * CONCAT22(uVar6,uVar3)) >> 0x10);
      unaff_EDI[2] = unaff_EDI[2] + *(short *)(CONCAT31(uVar9,cVar1) * 2);
      unaff_EDI[3] = unaff_EDI[3] + *(short *)(CONCAT31(uVar8,cVar1) * 2);
      uVar4 = uVar3 + _DAT_0003989a;
      pcVar10 = pcVar10 + (uint)CARRY2(uVar3,_DAT_0003989a) + _DAT_0003989c;
      cVar1 = *pcVar10 +
              (char)((uint)(((int)pcVar10[1] - (int)*pcVar10) * CONCAT22(uVar6,uVar4)) >> 0x10);
      unaff_EDI[4] = unaff_EDI[4] + *(short *)(CONCAT31(uVar9,cVar1) * 2);
      unaff_EDI[5] = unaff_EDI[5] + *(short *)(CONCAT31(uVar8,cVar1) * 2);
      uVar3 = uVar4 + _DAT_0003989a;
      pcVar10 = pcVar10 + (uint)CARRY2(uVar4,_DAT_0003989a) + _DAT_0003989c;
      cVar1 = *pcVar10 +
              (char)((uint)(((int)pcVar10[1] - (int)*pcVar10) * CONCAT22(uVar6,uVar3)) >> 0x10);
      unaff_EBX = CONCAT31(uVar9,cVar1);
      unaff_EDI[6] = unaff_EDI[6] + *(short *)(unaff_EBX * 2);
      iVar7 = CONCAT31(uVar8,cVar1);
      unaff_EDI[7] = unaff_EDI[7] + *(short *)(iVar7 * 2);
      iVar5 = CONCAT22(uVar6,uVar3 + _DAT_0003989a);
      unaff_ESI = pcVar10 + (uint)CARRY2(uVar3,_DAT_0003989a) + _DAT_0003989c;
      unaff_EDI = unaff_EDI + 8;
      DAT_000398a0 = DAT_000398a0 - 1;
    } while (DAT_000398a0 != 0);
  }
  return;
}

