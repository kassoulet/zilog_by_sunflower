
undefined8 FUN_000256d4(undefined2 *param_1,undefined2 *param_2)

{
  byte bVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  
  iVar2 = 64000;
  puVar3 = param_1;
  puVar4 = param_2;
  do {
    bVar1 = (byte)((ushort)*puVar3 >> 8);
    *puVar4 = CONCAT11((*(byte *)(puVar3 + 1) & 0xf8) >> 1 | bVar1 >> 6,
                       (byte)*puVar3 >> 3 | (bVar1 & 0x38) << 2);
    puVar3 = puVar3 + 2;
    puVar4 = puVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT44(param_2,param_1);
}

