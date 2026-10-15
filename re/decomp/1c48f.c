
undefined4 * FUN_0001c48f(undefined4 *param_1,undefined4 *param_2,uint unaff_EBX)

{
  uint uVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1;
  for (uVar1 = unaff_EBX >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  for (unaff_EBX = unaff_EBX & 3; unaff_EBX != 0; unaff_EBX = unaff_EBX - 1) {
    *(undefined1 *)puVar2 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  return param_1;
}

