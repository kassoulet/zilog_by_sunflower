
undefined8 FUN_0002587b(undefined2 *param_1,undefined4 param_2)

{
  ushort uVar1;
  int iVar2;
  undefined2 *puVar3;
  byte *pbVar4;
  
  pbVar4 = &DAT_000a0000;
  iVar2 = 64000;
  puVar3 = param_1;
  do {
    uVar1 = CONCAT11((char)((ushort)*puVar3 >> 8),(byte)*puVar3 >> 6) & 0xe0ff;
    *pbVar4 = *(byte *)(puVar3 + 1) & 0xe0 | (byte)(uVar1 >> 0xb) | (byte)uVar1;
    puVar3 = puVar3 + 2;
    pbVar4 = pbVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT44(param_2,param_1);
}

