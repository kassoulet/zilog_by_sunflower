
undefined8 __regparm3 FUN_00029361(uint param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  bool bVar2;
  undefined2 extraout_var;
  undefined2 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  undefined2 extraout_CX;
  undefined2 extraout_CX_00;
  undefined2 extraout_DX;
  undefined4 extraout_EDX;
  undefined2 unaff_SI;
  undefined *unaff_EDI;
  undefined2 in_ES;
  byte bVar8;
  undefined8 uVar9;
  
  bVar8 = (param_1 >> 0xf & 1) != 0;
  FUN_0002914b(param_1,param_2,param_1 >> 0x10,param_1);
  pcVar1 = (code *)swi(0x31);
  (*pcVar1)(CONCAT31((int3)(CONCAT22(extraout_var,0x500) >> 8),1));
  puVar3 = (undefined2 *)(1 - (uint)bVar8);
  if (puVar3 != (undefined2 *)0x0) {
    puVar3 = (undefined2 *)CONCAT22((short)(param_1 >> 0x10),extraout_CX);
    *puVar3 = (short)unaff_EDI;
    puVar3[1] = unaff_SI;
  }
  if (puVar3 == (undefined2 *)0x0) {
    if ((DAT_0004148c & 0xfff00000) != 0) {
      DAT_0004148c = 0xfffff;
    }
    if (unaff_EDI < &DAT_00010001) {
      bVar8 = 0;
      pcVar1 = (code *)swi(0x21);
      iVar4 = (*pcVar1)(0x4800,extraout_EDX,
                        CONCAT31((uint3)(DAT_0004148c >> 0xc),(char)(DAT_0004148c >> 4)) | 1);
      bVar2 = (bVar8 & 1) != 0;
      uVar6 = (iVar4 << 1 | (uint)bVar8) >> 1;
      uVar5 = uVar6 | (uint)bVar2 << 0x1f;
      if (!bVar2) {
        bVar8 = ((uint)unaff_EDI >> 3 & 1) != 0;
        pcVar1 = (code *)swi(0x21);
        uVar9 = (*pcVar1)(CONCAT22((short)(uVar5 >> 0x10),CONCAT11(0x48,(char)uVar6)),uVar5,
                          (uint)unaff_EDI >> 4);
        bVar2 = (bVar8 & 1) != 0;
        uVar6 = ((int)uVar9 << 1 | (uint)bVar8) >> 1 | (uint)bVar2 << 0x1f;
        pcVar1 = (code *)swi(0x21);
        bVar8 = bVar2;
        iVar4 = (*pcVar1)(CONCAT11(0x49,(char)((ulonglong)uVar9 >> 0x20)),
                          (int)((ulonglong)uVar9 >> 0x20),uVar6);
        if (!bVar2) {
          pcVar1 = (code *)swi(0x31);
          (*pcVar1)(CONCAT31((int3)(((uint)(ushort)((ushort)((uint)(iVar4 << 1) >> 0x11) |
                                                   (ushort)(((uint)((bVar8 & 1) != 0) << 0x1f) >>
                                                           0x10)) << 0x10) >> 8),6));
          piVar7 = (int *)(CONCAT22(extraout_CX_00,extraout_DX) + 8);
          *(uint *)(CONCAT22(extraout_CX_00,extraout_DX) + 4) = uVar6;
          *piVar7 = CONCAT22((short)((uint)unaff_EDI >> 0x10),in_ES) + -8;
          goto LAB_00029429;
        }
      }
    }
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = (int *)(puVar3 + 4);
    *piVar7 = (int)(unaff_EDI + -8);
    *(undefined4 *)(puVar3 + 2) = 0;
  }
LAB_00029429:
  return CONCAT44(param_3,piVar7);
}

