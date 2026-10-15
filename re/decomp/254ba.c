
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000254ba(undefined4 *param_1,int param_2)

{
  code *pcVar1;
  undefined2 uVar3;
  undefined2 extraout_var;
  int iVar2;
  int iVar4;
  uint uVar5;
  undefined2 extraout_var_00;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  byte bVar9;
  
  bVar9 = 0;
  uVar6 = param_2 * 5;
  DAT_0003f5dc = 0;
  uVar3 = (undefined2)((uint)param_1 >> 0x10);
  iVar4 = *(int *)(&DAT_0002540a + param_2 * 4);
  do {
    if (iVar4 < 1) break;
    DAT_0003f5dc = DAT_0003f5dc + DAT_0003f5da;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  uVar5 = 0;
  puVar7 = param_1;
  _DAT_0003f95f = uVar6;
  do {
    pcVar1 = (code *)swi(0x10);
    (*pcVar1)(CONCAT22(uVar3,0x4f05),DAT_0003f5dc,uVar6 & 0xffff0000);
    uVar6 = CONCAT22((short)(uVar6 >> 0x10),1);
    pcVar1 = (code *)swi(0x10);
    (*pcVar1)(CONCAT22(extraout_var,0x4f05),CONCAT22(extraout_var_00,DAT_0003f5dc),uVar6);
    iVar2 = uVar5 + _DAT_0003f95f;
    puVar8 = (undefined4 *)(&DAT_000a0000 + *(int *)(&DAT_0002541a + iVar2 * 4));
    for (iVar4 = *(int *)(&DAT_0002546a + iVar2 * 4); iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + (uint)bVar9 * -2 + 1;
      puVar8 = puVar8 + (uint)bVar9 * -2 + 1;
    }
    uVar3 = (undefined2)((uint)iVar2 >> 0x10);
    DAT_0003f5dc = DAT_0003f5dc + DAT_0003f5da;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 5);
  return CONCAT44(param_2,param_1);
}

