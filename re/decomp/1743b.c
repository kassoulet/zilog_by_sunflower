
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001743b(undefined4 param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  ushort *puVar5;
  int unaff_ESI;
  uint *puVar6;
  int unaff_EDI;
  int iVar7;
  
  bRam000174a4 = (byte)param_1;
  iRam000174c0 = (1 << (bRam000174a4 & 0x1f)) << 1;
  iVar7 = 1 << (bRam000174a4 & 0x1f);
  uVar3 = 0;
  puVar5 = param_2;
  do {
    uVar3 = uVar3 + *(byte *)(unaff_ESI + (uint)*puVar5);
    puVar5 = puVar5 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar7 = 0x17800;
  s_4OemVend_0001742f._4_4_ = param_1;
  unique0x1000004e = unaff_EDI;
  iRam000174aa = unaff_EDI;
  bRam000174b1 = bRam000174a4;
  iRam000174b6 = unaff_ESI;
  iRam000174c8 = unaff_ESI;
  do {
    uVar1 = *param_2;
    (&DAT_11111111)[uVar1] = (char)(uVar3 >> 6);
    iVar2 = ram0x00017437;
    uVar3 = (((uVar3 >> 6) << 6 | uVar3 & 0x3f) - (ushort)(byte)(&DAT_11111111)[uVar1]) +
            (ushort)(byte)(&DAT_11111111)[*(ushort *)((int)param_2 + 0x11111111)];
    param_2 = param_2 + 1;
    iVar7 = iVar7 + -1;
    iVar4 = DAT_00040300;
    puVar6 = DAT_000402fc;
  } while (iVar7 != 0);
  do {
    *(undefined1 *)(iVar2 + (*puVar6 >> 0x10)) = *(undefined1 *)(iVar2 + (*puVar6 & 0xffff));
    iVar4 = iVar4 + -1;
    puVar6 = puVar6 + 1;
  } while (iVar4 != 0);
  return;
}

