
undefined8 FUN_00025649(undefined2 *param_1,undefined4 param_2,uint unaff_EBX)

{
  undefined2 uVar1;
  code *pcVar2;
  byte bVar5;
  uint uVar3;
  undefined2 extraout_var;
  uint uVar4;
  undefined2 uVar6;
  uint uVar7;
  int iVar8;
  undefined2 extraout_var_00;
  undefined2 *puVar9;
  undefined2 *puVar10;
  
  DAT_0003f5dc = 0;
  uVar3 = (uint)param_1 & 0xffff0000;
  uVar7 = 0;
  puVar9 = param_1;
  do {
    pcVar2 = (code *)swi(0x10);
    (*pcVar2)(CONCAT22((short)(uVar3 >> 0x10),0x4f05),DAT_0003f5dc,unaff_EBX & 0xffff0000);
    unaff_EBX = CONCAT22((short)(unaff_EBX >> 0x10),1);
    pcVar2 = (code *)swi(0x10);
    (*pcVar2)(CONCAT22(extraout_var,0x4f05),CONCAT22(extraout_var_00,DAT_0003f5dc),unaff_EBX);
    puVar10 = (undefined2 *)&DAT_000a0000;
    iVar8 = *(int *)(&DAT_00025641 + uVar7 * 4);
    uVar3 = uVar7;
    do {
      uVar1 = *puVar9;
      unaff_EBX = CONCAT31((int3)(unaff_EBX >> 8),*(undefined1 *)(puVar9 + 1)) & 0xfffffff8;
      uVar4 = CONCAT31((int3)(CONCAT22((short)(uVar3 >> 0x10),uVar1) >> 8),
                       (char)((ushort)uVar1 >> 8) << 3) & 0xffffffe0;
      uVar6 = (undefined2)(uVar4 >> 0x10);
      bVar5 = (byte)(uVar4 >> 8) >> 5;
      uVar3 = (uint)CONCAT21(uVar6,bVar5) << 8;
      *puVar10 = CONCAT11((byte)unaff_EBX | bVar5,(byte)uVar1 >> 3 | (byte)uVar4);
      puVar9 = puVar9 + 2;
      puVar10 = puVar10 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    uVar3 = CONCAT22(uVar6,DAT_0003f5da);
    DAT_0003f5dc = DAT_0003f5dc + DAT_0003f5da;
    uVar7 = uVar7 + 1;
  } while (uVar7 < 2);
  return CONCAT44(param_2,param_1);
}

