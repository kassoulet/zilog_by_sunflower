
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_000251e7(uint param_1,uint param_2,uint unaff_EBX,uint param_4)

{
  ushort uVar1;
  code *pcVar2;
  undefined2 uVar3;
  undefined2 extraout_CX;
  uint uVar4;
  uint uVar5;
  uint extraout_ECX;
  undefined4 uVar6;
  undefined4 extraout_EDX;
  undefined2 extraout_var;
  ushort *puVar7;
  bool bVar9;
  byte bVar10;
  undefined8 uVar11;
  ushort *puVar8;
  
  bVar10 = 0;
  DAT_0003f95b = unaff_EBX >> 0x10;
  unaff_EBX = unaff_EBX & 0xffff;
  if (DAT_0003f1a0 == 1) {
LAB_000253f6:
    pcVar2 = (code *)swi(0x31);
    (*pcVar2)(0x101,DAT_0003f1c4,unaff_EBX);
    return (ulonglong)param_4 << 0x20;
  }
  DAT_0003f1b0 = (byte)unaff_EBX;
  DAT_0003f1a8 = param_1;
  DAT_0003f1ac = param_2;
  uVar11 = FUN_00024f20();
  bVar9 = false;
  if ((int)uVar11 == 0) goto LAB_000253f6;
  pcVar2 = (code *)swi(0x31);
  uVar11 = (*pcVar2)(0x100,(int)((ulonglong)uVar11 >> 0x20),0x20);
  uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
  if (bVar9) {
    return (ulonglong)param_2 << 0x20;
  }
  uVar4 = ((uint)uVar11 & 0xffff) * 0x10;
  DAT_0003f1c0 = (undefined2)uVar11;
  DAT_0003f1c4 = (undefined2)((ulonglong)uVar11 >> 0x20);
  unaff_EBX = (uint)uVar11 & 0xffff;
  uVar5 = uVar4;
  puVar7 = DAT_0003ef96;
  DAT_0003f1c8 = uVar4;
  do {
    do {
      puVar8 = puVar7 + (uint)bVar10 * -2 + 1;
      uVar1 = *puVar7;
      bVar9 = uVar1 != 0xffff;
      if (uVar1 == 0xffff) goto LAB_000253f6;
      DAT_0003ef20 = 0x4f01;
      _DAT_0003ef14 = 0;
      _DAT_0003ef26 = DAT_0003f1c0;
      _DAT_0003ef04 = 0;
      unaff_EBX = 0x10;
      pcVar2 = (code *)swi(0x31);
      _DAT_0003ef1c = (uint)uVar1;
      DAT_0003f1a4 = uVar1;
      (*pcVar2)(0x300,uVar6,0x10,uVar5 & 0xffff0000);
      if ((bVar9) || ((char)DAT_0003ef20 != 'O')) goto LAB_000253f6;
      uVar5 = extraout_ECX;
      uVar6 = extraout_EDX;
      puVar7 = puVar8;
    } while (*(ushort *)(uVar4 + 0x12) != DAT_0003f1a8);
  } while ((*(ushort *)(uVar4 + 0x14) != DAT_0003f1ac) ||
          (uVar3 = 0, *(byte *)(uVar4 + 0x19) != DAT_0003f1b0));
  if (DAT_0003f95b == 0) {
    pcVar2 = (code *)swi(0x10);
    uVar11 = (*pcVar2)(0x4f02,extraout_EDX,DAT_0003f1a4 | 0x4000);
    uVar3 = (undefined2)((ulonglong)uVar11 >> 0x10);
    if ((char)((ulonglong)uVar11 >> 8) == '\0') {
      uVar5 = *(uint *)(uVar4 + 0x28);
      unaff_EBX = uVar5 >> 0x10;
      bVar9 = true;
      pcVar2 = (code *)swi(0x31);
      (*pcVar2)(0x800,(int)((ulonglong)uVar11 >> 0x20),unaff_EBX,uVar5);
      if (bVar9) goto LAB_000253f6;
      DAT_0003f1b4 = CONCAT22((short)(uVar5 >> 0x10),extraout_CX);
      goto LAB_00025382;
    }
  }
  DAT_0003f94e = '\x01';
  pcVar2 = (code *)swi(0x10);
  (*pcVar2)(CONCAT22(uVar3,0x4f02));
  DAT_0003f5d6 = (uint)*(ushort *)(DAT_0003f1c8 + 4);
  register0x00000000 = (uint)*(ushort *)(DAT_0003f1c8 + 6);
  DAT_0003f5da = *(ushort *)(DAT_0003f1c8 + 6) / *(ushort *)(DAT_0003f1c8 + 4);
LAB_00025382:
  pcVar2 = (code *)swi(0x10);
  (*pcVar2)(0x4f06,0,0,DAT_0003f1a8);
  DAT_0003f1a0 = 1;
  DAT_0003f188 = (uint)DAT_0003f1a4;
  DAT_0003f18c = DAT_0003f1a8;
  DAT_0003f190 = DAT_0003f1ac;
  DAT_0003f194 = (uint)DAT_0003f1b0;
  DAT_0003f198 = (uint)(DAT_0003f1b0 >> 3);
  DAT_0003f19c = DAT_0003f1b4;
  if (DAT_0003f94e != '\0') {
    DAT_0003f19c = 0;
  }
  pcVar2 = (code *)swi(0x31);
  (*pcVar2)(0x101,CONCAT22(extraout_var,DAT_0003f1c4));
  return CONCAT44(param_1,&DAT_0003f188);
}

