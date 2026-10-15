
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00032406(void)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  undefined2 extraout_var;
  int iVar4;
  uint uVar5;
  int *unaff_ESI;
  undefined4 *puVar6;
  bool bVar7;
  undefined1 uVar8;
  
  uVar3 = 0x501;
  if ((*unaff_ESI == 0x4d4c5355) && (uVar3 = 0x503, (short)unaff_ESI[1] == 4)) {
    _DAT_000314fa = *(undefined2 *)((int)unaff_ESI + 0x26);
    DAT_000314fc = (uint)*(ushort *)((int)unaff_ESI + 0x2e);
    DAT_000314f6 = unaff_ESI;
    FUN_00033fd9();
    uVar3 = 0x502;
    bVar7 = *(ushort *)((int)unaff_ESI + 0x2e) < 0x40;
    if ((*(ushort *)((int)unaff_ESI + 0x2e) < 0x41) && (uVar3 = FUN_00033ff6(DAT_000314fc), !bVar7))
    {
      DAT_00036460 = (int)unaff_ESI + 0x5be;
      DAT_00036464 = (int)unaff_ESI + 0x7be;
      uVar5 = 0;
      do {
        bVar1 = *(byte *)((int)unaff_ESI + uVar5 + 0x13e);
        if (0x7f < bVar1) {
          bVar1 = bVar1 + 0x80;
        }
        if (bVar1 == 100) {
          bVar1 = 0x40;
        }
        if (bVar1 == 0x40) {
          cVar2 = -1;
        }
        else {
          cVar2 = bVar1 << 2;
        }
        (&DAT_000316f0)[uVar5] = cVar2;
        FUN_00034348();
        uVar5 = uVar5 + 1;
      } while (uVar5 != DAT_000314fc);
      uVar5 = 0;
      do {
        FUN_000340e3(*(undefined1 *)((int)unaff_ESI + uVar5 + 0x17e));
        uVar5 = uVar5 + 1;
      } while (uVar5 != DAT_000314fc);
      DAT_0003646c = (*(ushort *)((int)unaff_ESI + 0x26) & 2) != 0;
      DAT_00036468 = *(undefined2 *)((int)unaff_ESI + 0x2a);
      DAT_0003646a = (undefined2)unaff_ESI[0xb];
      FUN_000340ba(CONCAT31((int3)(CONCAT22(extraout_var,DAT_0003646a) >> 8),(char)unaff_ESI[0xf]));
      uVar8 = 0;
      puVar6 = &DAT_00031500;
      for (iVar4 = 0xdf0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined1 *)puVar6 = 0;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
      FUN_00032a65(*(undefined1 *)((int)unaff_ESI + 0x3b));
      DAT_00031509 = *(char *)((int)unaff_ESI + 0x3a);
      DAT_0003150a = DAT_00031509 + -1;
      uVar3 = FUN_00034009();
      if (!(bool)uVar8) {
        DAT_00034e10 = 0;
        return;
      }
    }
  }
  DAT_00034e10 = uVar3;
  return;
}

