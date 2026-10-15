
undefined8 FUN_00025582(ushort *param_1,undefined2 *param_2)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  undefined2 *puVar4;
  
  iVar2 = 64000;
  puVar3 = param_1;
  puVar4 = param_2;
  do {
    uVar1 = *puVar3 & 0xf0ff;
    if ((char)(uVar1 >> 8) == -0x10) {
      uVar1 = CONCAT11(0xe0,(char)uVar1);
    }
    *puVar4 = CONCAT11(((byte)puVar3[1] >> 4) - 0x10,(byte)uVar1 >> 4 | (byte)(uVar1 >> 8));
    puVar3 = puVar3 + 2;
    puVar4 = puVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT44(param_2,param_1);
}

