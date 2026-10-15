
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00016e53(uint param_1,undefined4 param_2)

{
  uint uVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  undefined1 *puVar7;
  int unaff_ESI;
  int iVar8;
  int unaff_EDI;
  undefined1 *puVar9;
  
  iRam00016f22 = unaff_EDI - unaff_ESI;
  DAT_00016cbd = param_1;
  iRam00016f53 = iRam00016f22;
  iRam00016fa1 = iRam00016f22;
  iRam00016fd6 = iRam00016f22;
  FUN_00016b44();
  DAT_00016cc5 = DAT_00016cbd >> 1;
  DAT_00016cc9 = DAT_00016cbd - DAT_00016cc5;
  iRam00016f34 = (DAT_00016cc9 + -1) * 0x500;
  iRam00016f82 = (DAT_00016cc5 + 1) * -0x500;
  _DAT_00016ccd = 0x140;
  iRam00016f6d = iRam00016f34;
  iRam00016fb7 = iRam00016f82;
  do {
    iVar3 = DAT_00016cc9 * 0x140;
    puVar2 = DAT_00016b40;
    puVar7 = DAT_00016b40;
    puVar9 = DAT_00016b40;
    do {
      uVar4 = *(uint *)(unaff_ESI + -0x500 + iVar3 * 4);
      puVar2 = puVar2 + (uVar4 & 0xff);
      bVar6 = (byte)(uVar4 >> 8);
      puVar9 = puVar9 + bVar6;
      puVar7 = puVar7 + (uVar4 >> 0x10 & 0xff);
      iVar3 = iVar3 + -0x140;
    } while (iVar3 != 0);
    *(uint *)(&DAT_11111111 + unaff_ESI) =
         CONCAT22((short)(CONCAT12((char)(uVar4 >> 0x18),CONCAT11(*puVar7,bVar6)) >> 8),
                  CONCAT11(*puVar9,*puVar2));
    iVar3 = unaff_ESI + 0x500;
    uVar4 = DAT_00016cc5;
    do {
      uVar1 = *(uint *)(&DAT_11111111 + iVar3);
      puVar2 = puVar2 + (uVar1 & 0xff);
      bVar6 = (byte)(uVar1 >> 8);
      puVar9 = puVar9 + bVar6;
      puVar7 = puVar7 + (uVar1 >> 0x10 & 0xff);
      *(uint *)(&DAT_11111111 + iVar3) =
           CONCAT22((short)(CONCAT12((char)(uVar1 >> 0x18),CONCAT11(*puVar7,bVar6)) >> 8),
                    CONCAT11(*puVar9,*puVar2));
      iVar3 = iVar3 + 0x500;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
    iVar5 = 200 - DAT_00016cbd;
    do {
      uVar4 = *(uint *)(&DAT_11111111 + iVar3);
      uVar1 = *(uint *)(&DAT_11111111 + iVar3);
      puVar2 = puVar2 + ((uVar4 & 0xff) - (uVar1 & 0xff));
      bVar6 = (byte)(uVar1 >> 8);
      puVar9 = puVar9 + ((uVar4 >> 8 & 0xff) - (uint)bVar6);
      puVar7 = puVar7 + ((uVar4 >> 0x10 & 0xff) - (uVar1 >> 0x10 & 0xff));
      *(uint *)(&DAT_11111111 + iVar3) =
           CONCAT22((short)(CONCAT12((char)(uVar1 >> 0x18),CONCAT11(*puVar7,bVar6)) >> 8),
                    CONCAT11(*puVar9,*puVar2));
      iVar3 = iVar3 + 0x500;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar5 = DAT_00016cc9 + -1;
    do {
      iVar8 = iVar3;
      uVar4 = *(uint *)(&DAT_11111111 + iVar8);
      puVar2 = puVar2 + -(uVar4 & 0xff);
      bVar6 = (byte)(uVar4 >> 8);
      puVar9 = puVar9 + -(uint)bVar6;
      puVar7 = puVar7 + -(uVar4 >> 0x10 & 0xff);
      *(uint *)(&DAT_11111111 + iVar8) =
           CONCAT22((short)(CONCAT12((char)(uVar4 >> 0x18),CONCAT11(*puVar7,bVar6)) >> 8),
                    CONCAT11(*puVar9,*puVar2));
      iVar5 = iVar5 + -1;
      iVar3 = iVar8 + 0x500;
    } while (iVar5 != 0);
    unaff_ESI = iVar8 + -0x3e2fc;
    _DAT_00016ccd = _DAT_00016ccd + -1;
  } while (_DAT_00016ccd != 0);
  return CONCAT44(param_2,param_1);
}

