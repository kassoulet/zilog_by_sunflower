
undefined8 FUN_0002ebe3(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint extraout_ECX;
  undefined4 *extraout_EDX;
  undefined4 *puVar2;
  int iVar3;
  
  uVar1 = 0xffffffff;
  iVar3 = 0;
  for (puVar2 = DAT_000411cc; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
    if (((*(uint *)(puVar2[1] + 0xc) & uVar1) != 0) &&
       (iVar3 = iVar3 + 1, (*(byte *)(puVar2[1] + 0xd) & 0x10) != 0)) {
      FUN_00028acc();
      uVar1 = extraout_ECX;
      puVar2 = extraout_EDX;
    }
  }
  return CONCAT44(param_2,iVar3);
}

