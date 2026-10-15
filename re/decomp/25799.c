
undefined8 FUN_00025799(undefined2 *param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  
  iVar2 = 64000;
  puVar3 = param_1;
  puVar4 = param_2;
  do {
    uVar1 = puVar3[1];
    *puVar4 = *puVar3;
    *(char *)(puVar4 + 1) = (char)uVar1;
    puVar3 = puVar3 + 2;
    puVar4 = (undefined2 *)((int)puVar4 + 3);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT44(param_2,param_1);
}

