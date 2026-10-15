
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00016cdd(uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  undefined1 *puVar7;
  int unaff_ESI;
  int unaff_EDI;
  undefined1 *puVar8;
  
  iRam00016d84 = unaff_EDI - unaff_ESI;
  DAT_00016cbd = param_1;
  iRam00016dbb = iRam00016d84;
  iRam00016e03 = iRam00016d84;
  iRam00016e3e = iRam00016d84;
  FUN_00016b44();
  DAT_00016cc5 = DAT_00016cbd >> 1;
  DAT_00016cc9 = DAT_00016cbd - DAT_00016cc5;
  iRam00016dcf = (DAT_00016cc9 + -1) * 4;
  iRam00016e1e = (DAT_00016cc5 + 1) * -4;
  _DAT_00016ccd = 200;
  puVar3 = DAT_00016b40;
  iVar4 = DAT_00016cc9;
  puVar7 = DAT_00016b40;
  puVar8 = DAT_00016b40;
  iRam00016de4 = iRam00016e1e;
  iRam00016d9b = iRam00016dcf;
  do {
    do {
      uVar1 = *(uint *)(unaff_ESI + -4 + iVar4 * 4);
      puVar3 = puVar3 + (uVar1 & 0xff);
      bVar6 = (byte)(uVar1 >> 8);
      puVar8 = puVar8 + bVar6;
      puVar7 = puVar7 + (uVar1 >> 0x10 & 0xff);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    *(uint *)(&DAT_11111111 + unaff_ESI) =
         CONCAT22((short)(CONCAT12((char)(uVar1 >> 0x18),CONCAT11(*puVar7,bVar6)) >> 8),
                  CONCAT11(*puVar8,*puVar3));
    iVar4 = unaff_ESI + 4 + DAT_00016cc5 * 4;
    iVar5 = (DAT_00016cc5 ^ 0xffffffff) + 1;
    do {
      uVar1 = *(uint *)(&DAT_11111111 + iVar5 * 4 + iVar4);
      puVar3 = puVar3 + (uVar1 & 0xff);
      bVar6 = (byte)(uVar1 >> 8);
      puVar8 = puVar8 + bVar6;
      puVar7 = puVar7 + (uVar1 >> 0x10 & 0xff);
      *(uint *)(&DAT_11111111 + iVar5 * 4 + iVar4) =
           CONCAT22((short)(CONCAT12((char)(uVar1 >> 0x18),CONCAT11(*puVar7,bVar6)) >> 8),
                    CONCAT11(*puVar8,*puVar3));
      iVar5 = iVar5 + 1;
    } while (iVar5 != 0);
    iVar5 = 0x140 - DAT_00016cbd;
    do {
      uVar1 = *(uint *)(&DAT_11111111 + iVar4);
      uVar2 = *(uint *)(&DAT_11111111 + iVar4);
      puVar3 = puVar3 + ((uVar1 & 0xff) - (uVar2 & 0xff));
      bVar6 = (byte)(uVar2 >> 8);
      puVar8 = puVar8 + ((uVar1 >> 8 & 0xff) - (uint)bVar6);
      puVar7 = puVar7 + ((uVar1 >> 0x10 & 0xff) - (uVar2 >> 0x10 & 0xff));
      *(uint *)(&DAT_11111111 + iVar4) =
           CONCAT22((short)(CONCAT12((char)(uVar2 >> 0x18),CONCAT11(*puVar7,bVar6)) >> 8),
                    CONCAT11(*puVar8,*puVar3));
      iVar4 = iVar4 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    unaff_ESI = iVar4 + (DAT_00016cc9 - 1U) * 4;
    iVar4 = (DAT_00016cc9 - 1U ^ 0xffffffff) + 1;
    do {
      uVar1 = *(uint *)(&DAT_11111111 + iVar4 * 4 + unaff_ESI);
      puVar3 = puVar3 + -(uVar1 & 0xff);
      bVar6 = (byte)(uVar1 >> 8);
      puVar8 = puVar8 + -(uint)bVar6;
      puVar7 = puVar7 + -(uVar1 >> 0x10 & 0xff);
      *(uint *)(&DAT_11111111 + iVar4 * 4 + unaff_ESI) =
           CONCAT22((short)(CONCAT12((char)(uVar1 >> 0x18),CONCAT11(*puVar7,bVar6)) >> 8),
                    CONCAT11(*puVar8,*puVar3));
      iVar4 = iVar4 + 1;
    } while (iVar4 != 0);
    _DAT_00016ccd = _DAT_00016ccd + -1;
    puVar3 = DAT_00016b40;
    iVar4 = DAT_00016cc9;
    puVar7 = DAT_00016b40;
    puVar8 = DAT_00016b40;
  } while (_DAT_00016ccd != 0);
  return CONCAT44(param_2,param_1);
}

