
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00016ffb(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  undefined1 *puVar4;
  int iVar5;
  byte bVar6;
  undefined1 *puVar7;
  undefined4 *unaff_ESI;
  undefined4 *puVar8;
  int unaff_EDI;
  undefined1 *puVar9;
  byte bVar10;
  
  bVar10 = 0;
  iRam000170e0 = unaff_EDI - (int)unaff_ESI;
  _DAT_00016ccd = 200;
  DAT_00016ff7 = param_1;
  iRam00017117 = iRam000170e0;
  iRam0001715f = iRam000170e0;
  iRam0001719a = iRam000170e0;
  do {
    while( true ) {
      puVar2 = DAT_00016ff7;
      DAT_00016ff7 = DAT_00016ff7 + 1;
      uVar3 = *puVar2;
      if ((int)uVar3 < 3) break;
      if (0x3f < (int)uVar3) {
        uVar3 = 0x3f;
      }
      DAT_00016cbd = uVar3;
      FUN_00016b44();
      DAT_00016cc5 = DAT_00016cbd >> 1;
      DAT_00016cc9 = DAT_00016cbd - DAT_00016cc5;
      iRam000170f7 = (DAT_00016cc9 + -1) * 4;
      iRam00017140 = (DAT_00016cc5 + 1) * -4;
      puVar4 = DAT_00016b40;
      iVar5 = DAT_00016cc9;
      puVar7 = DAT_00016b40;
      puVar9 = DAT_00016b40;
      do {
        uVar3 = unaff_ESI[iVar5 + -1];
        puVar4 = puVar4 + (uVar3 & 0xff);
        bVar6 = (byte)(uVar3 >> 8);
        puVar9 = puVar9 + bVar6;
        puVar7 = puVar7 + (uVar3 >> 0x10 & 0xff);
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      iRam0001712b = iRam000170f7;
      iRam0001717a = iRam00017140;
      *(uint *)((int)unaff_ESI + 0x11111111) =
           CONCAT22((short)(CONCAT12((char)(uVar3 >> 0x18),CONCAT11(*puVar7,bVar6)) >> 8),
                    CONCAT11(*puVar9,*puVar4));
      puVar8 = unaff_ESI + DAT_00016cc5 + 1;
      iVar5 = (DAT_00016cc5 ^ 0xffffffff) + 1;
      do {
        uVar3 = *(uint *)(&DAT_11111111 + (int)puVar8 + iVar5 * 4);
        puVar4 = puVar4 + (uVar3 & 0xff);
        bVar6 = (byte)(uVar3 >> 8);
        puVar9 = puVar9 + bVar6;
        puVar7 = puVar7 + (uVar3 >> 0x10 & 0xff);
        *(uint *)(&DAT_11111111 + (int)puVar8 + iVar5 * 4) =
             CONCAT22((short)(CONCAT12((char)(uVar3 >> 0x18),CONCAT11(*puVar7,bVar6)) >> 8),
                      CONCAT11(*puVar9,*puVar4));
        iVar5 = iVar5 + 1;
      } while (iVar5 != 0);
      iVar5 = 0x140 - DAT_00016cbd;
      do {
        uVar3 = *(uint *)((int)puVar8 + 0x11111111);
        uVar1 = *(uint *)((int)puVar8 + 0x11111111);
        puVar4 = puVar4 + ((uVar3 & 0xff) - (uVar1 & 0xff));
        bVar6 = (byte)(uVar1 >> 8);
        puVar9 = puVar9 + ((uVar3 >> 8 & 0xff) - (uint)bVar6);
        puVar7 = puVar7 + ((uVar3 >> 0x10 & 0xff) - (uVar1 >> 0x10 & 0xff));
        *(uint *)((int)puVar8 + 0x11111111) =
             CONCAT22((short)(CONCAT12((char)(uVar1 >> 0x18),CONCAT11(*puVar7,bVar6)) >> 8),
                      CONCAT11(*puVar9,*puVar4));
        puVar8 = puVar8 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      unaff_ESI = puVar8 + (DAT_00016cc9 - 1U);
      iVar5 = (DAT_00016cc9 - 1U ^ 0xffffffff) + 1;
      do {
        uVar3 = *(uint *)(&DAT_11111111 + (int)unaff_ESI + iVar5 * 4);
        puVar4 = puVar4 + -(uVar3 & 0xff);
        bVar6 = (byte)(uVar3 >> 8);
        puVar9 = puVar9 + -(uint)bVar6;
        puVar7 = puVar7 + -(uVar3 >> 0x10 & 0xff);
        *(uint *)(&DAT_11111111 + (int)unaff_ESI + iVar5 * 4) =
             CONCAT22((short)(CONCAT12((char)(uVar3 >> 0x18),CONCAT11(*puVar7,bVar6)) >> 8),
                      CONCAT11(*puVar9,*puVar4));
        iVar5 = iVar5 + 1;
      } while (iVar5 != 0);
      _DAT_00016ccd = _DAT_00016ccd + -1;
      if (_DAT_00016ccd == 0) goto LAB_000171ad;
    }
    puVar8 = (undefined4 *)((int)unaff_ESI + iRam000170e0);
    for (iVar5 = 0x140; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar8 = *unaff_ESI;
      unaff_ESI = unaff_ESI + (uint)bVar10 * -2 + 1;
      puVar8 = puVar8 + (uint)bVar10 * -2 + 1;
    }
    _DAT_00016ccd = _DAT_00016ccd + -1;
  } while (_DAT_00016ccd != 0);
LAB_000171ad:
  return CONCAT44(param_2,param_1);
}

