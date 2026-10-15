
undefined8 FUN_000255b7(undefined2 *param_1,undefined4 param_2,uint unaff_EBX)

{
  code *pcVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined2 extraout_var;
  undefined2 uVar4;
  uint uVar5;
  int iVar6;
  undefined2 extraout_var_00;
  char cVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  
  DAT_0003f5dc = 0;
  uVar3 = (uint)param_1 & 0xffff0000;
  uVar5 = 0;
  puVar8 = param_1;
  do {
    pcVar1 = (code *)swi(0x10);
    (*pcVar1)(CONCAT22((short)(uVar3 >> 0x10),0x4f05),DAT_0003f5dc,unaff_EBX & 0xffff0000);
    unaff_EBX = CONCAT22((short)(unaff_EBX >> 0x10),1);
    pcVar1 = (code *)swi(0x10);
    (*pcVar1)(CONCAT22(extraout_var,0x4f05),CONCAT22(extraout_var_00,DAT_0003f5dc),unaff_EBX);
    puVar9 = (undefined2 *)&DAT_000a0000;
    iVar6 = *(int *)(&DAT_00025641 + uVar5 * 4);
    uVar3 = uVar5;
    do {
      uVar3 = CONCAT22((short)(uVar3 >> 0x10),*puVar8) & 0xfffff0ff;
      if ((char)(uVar3 >> 8) == -0x10) {
        uVar3 = CONCAT22((short)(uVar3 >> 0x10),CONCAT11(0xe0,(char)uVar3));
      }
      cVar7 = (*(byte *)(puVar8 + 1) >> 4) - 0x10;
      unaff_EBX = CONCAT31((int3)(unaff_EBX >> 8),cVar7);
      uVar4 = (undefined2)(uVar3 >> 0x10);
      uVar2 = CONCAT11(cVar7,(byte)uVar3 >> 4 | (byte)(uVar3 >> 8));
      uVar3 = CONCAT22(uVar4,uVar2);
      *puVar9 = uVar2;
      puVar8 = puVar8 + 2;
      puVar9 = puVar9 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    uVar3 = CONCAT22(uVar4,DAT_0003f5da);
    DAT_0003f5dc = DAT_0003f5dc + DAT_0003f5da;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 2);
  return CONCAT44(param_2,param_1);
}

