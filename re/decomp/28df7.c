
undefined8 FUN_00028df7(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  undefined4 *extraout_ECX_00;
  undefined4 *extraout_ECX_01;
  undefined4 *extraout_ECX_02;
  undefined4 *puVar3;
  
  if (*(int *)(param_1[2] + 8) == 0) {
    FUN_00028c7a(param_1);
    param_1 = extraout_ECX;
  }
  if (((*(byte *)((int)param_1 + 0xd) & 0x20) != 0) && ((*(byte *)((int)param_1 + 0xd) & 6) != 0)) {
    FUN_0002ebe8(0x2000);
    param_1 = extraout_ECX_00;
  }
  *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xfb;
  *param_1 = *(undefined4 *)(param_1[2] + 8);
  if (((param_1[3] & 0x2400) == 0x2400) && (param_1[4] == 0)) {
    param_1[1] = 0;
    iVar1 = FUN_0002ec17();
    puVar3 = extraout_ECX_01;
    if (iVar1 != -1) {
      *(char *)*extraout_ECX_01 = (char)iVar1;
      extraout_ECX_01[1] = 1;
      goto LAB_00028ea3;
    }
  }
  else {
    uVar2 = FUN_00028d01(param_1[4],*param_1);
    extraout_ECX_02[1] = uVar2;
    puVar3 = extraout_ECX_02;
  }
  if ((int)puVar3[1] < 1) {
    if (puVar3[1] == 0) {
      *(byte *)(puVar3 + 3) = *(byte *)(puVar3 + 3) | 0x10;
    }
    else {
      puVar3[1] = 0;
      *(byte *)(puVar3 + 3) = *(byte *)(puVar3 + 3) | 0x20;
    }
  }
LAB_00028ea3:
  return CONCAT44(param_2,puVar3[1]);
}

