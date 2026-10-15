
undefined8 FUN_0002554c(undefined2 *param_1,undefined2 *param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  
  iVar3 = 64000;
  puVar4 = param_1;
  puVar5 = param_2;
  do {
    bVar1 = (byte)((ushort)*puVar4 >> 8);
    uVar2 = CONCAT11(*(undefined1 *)(puVar4 + 1),(byte)*puVar4 >> 3 | (bVar1 & 0x1c) << 3) & 0xf8ff;
    *puVar5 = CONCAT11((byte)(uVar2 >> 8) | bVar1 >> 5,(char)uVar2);
    puVar4 = puVar4 + 2;
    puVar5 = puVar5 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return CONCAT44(param_2,param_1);
}

