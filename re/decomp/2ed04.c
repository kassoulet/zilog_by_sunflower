
undefined8 FUN_0002ed04(uint param_1,undefined4 param_2)

{
  code *pcVar1;
  bool bVar2;
  undefined2 uVar6;
  int iVar3;
  ushort extraout_var;
  ushort uVar7;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint extraout_EDX;
  uint uVar8;
  uint uVar9;
  undefined1 unaff_DI;
  undefined2 in_DS;
  byte bVar10;
  undefined8 uVar11;
  
  if (DAT_0003ed28 <= param_1) {
    uVar6 = (undefined2)(param_1 >> 0x10);
    if (DAT_0003ed42 == 0) {
      uVar9 = param_1 + 0xf >> 4;
      if (uVar9 == 0) {
        uVar9 = 0xfffffff;
      }
      pcVar1 = (code *)swi(0x21);
      uVar11 = (*pcVar1)(CONCAT22(uVar6,CONCAT11(0xed,(char)in_DS)),param_2,in_DS);
      uVar8 = (uint)((ulonglong)uVar11 >> 0x20);
      iVar3 = (int)uVar11 << 0x1f;
      uVar7 = (ushort)((uint)iVar3 >> 0x10);
      bVar10 = 0;
      if (iVar3 != 0) {
        pcVar1 = (code *)swi(0x21);
        (*pcVar1)(CONCAT22(uVar7,CONCAT11(0x4a,unaff_DI)),uVar8,uVar9);
        bVar2 = (bVar10 & 1) != 0;
        uVar7 = extraout_var & 0x7fff | (ushort)(((uint)bVar2 << 0x1f) >> 0x10);
        uVar8 = extraout_EDX;
        if (bVar2) goto LAB_0002ed6f;
      }
      bVar10 = false;
      uVar4 = CONCAT22(uVar7,in_DS);
    }
    else {
      uVar9 = param_1 + 0xfff >> 0xc;
      if (uVar9 == 0) {
        uVar9 = 0xfffff;
      }
      uVar8 = (uint)DAT_0003ed42;
      bVar10 = DAT_0003ed42 == 0;
      if ((DAT_0003ed42 == 1) && (bVar10 = 1 < DAT_0003ed43, DAT_0003ed43 == 1)) {
        uVar9 = uVar9 << 8;
        bVar10 = false;
      }
      uVar4 = CONCAT22(uVar6,in_DS);
    }
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)(CONCAT22((short)((uint)uVar4 >> 0x10),CONCAT11(0x4a,(char)uVar4)),uVar8,uVar9);
    uVar9 = DAT_0003ed14;
    uVar8 = param_1;
    if ((bVar10 & 1) == 0) goto LAB_0002ecfe;
  }
LAB_0002ed6f:
  puVar5 = (undefined4 *)FUN_0002e51d();
  *puVar5 = 5;
  uVar9 = 0xffffffff;
  uVar8 = DAT_0003ed14;
LAB_0002ecfe:
  DAT_0003ed14 = uVar8;
  return CONCAT44(param_2,uVar9);
}

