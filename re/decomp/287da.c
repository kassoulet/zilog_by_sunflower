
undefined8 FUN_000287da(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined *puVar3;
  int extraout_ECX;
  int extraout_ECX_00;
  uint uVar4;
  
  if (DAT_000411d0 == (undefined4 *)0x0) {
    for (puVar3 = &DAT_0003fa08; puVar3 < &DAT_0003fc10; puVar3 = puVar3 + 0x1a) {
      if ((puVar3[0xc] & 3) == 0) {
        puVar1 = (undefined4 *)FUN_000243a3(0x15);
        if (puVar1 == (undefined4 *)0x0) goto LAB_00028871;
        uVar4 = 3;
        iVar2 = extraout_ECX;
        goto LAB_00028849;
      }
    }
    uVar4 = 0x4003;
    puVar1 = (undefined4 *)FUN_000243a3(0x2f);
    if (puVar1 == (undefined4 *)0x0) {
LAB_00028871:
      FUN_000284cf(5);
      iVar2 = 0;
      goto LAB_0002887d;
    }
    iVar2 = (int)puVar1 + 0x15;
  }
  else {
    iVar2 = DAT_000411d0[1];
    uVar4 = (uint)((ushort)*(undefined4 *)(iVar2 + 0xc) & 0x4003 | 3);
    puVar1 = DAT_000411d0;
    DAT_000411d0 = (undefined4 *)*DAT_000411d0;
  }
LAB_00028849:
  FUN_00017e46(iVar2,0,0x1a);
  *(uint *)(extraout_ECX_00 + 0xc) = uVar4;
  puVar1[1] = extraout_ECX_00;
  *(undefined4 **)(extraout_ECX_00 + 8) = puVar1;
  *puVar1 = DAT_000411cc;
  DAT_000411cc = puVar1;
  iVar2 = extraout_ECX_00;
LAB_0002887d:
  return CONCAT44(param_2,iVar2);
}

