
undefined2 FUN_00025a7f(void)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  
  puVar5 = &DAT_0003f5e6;
  uVar4 = 0;
  do {
    uVar2 = 0;
    do {
      *puVar5 = 0;
      puVar1 = puVar5 + 2;
      puVar5[1] = (char)uVar4;
      puVar5 = puVar5 + 3;
      *puVar1 = (char)uVar2;
      uVar2 = uVar2 + 4;
    } while (uVar2 < 0x3d);
    uVar4 = uVar4 + 4;
  } while (uVar4 < 0x39);
  uVar4 = 0;
  do {
    *puVar5 = (char)uVar4;
    puVar1 = puVar5 + 2;
    puVar5[1] = 0;
    puVar5 = puVar5 + 3;
    *puVar1 = 0;
    uVar4 = uVar4 + 4;
  } while (uVar4 < 0x3d);
  iVar3 = 0x300;
  out(0x3c8,0);
  puVar5 = &DAT_0003f5e6;
  do {
    out(*puVar5,0x3c9);
    iVar3 = iVar3 + -1;
    puVar5 = puVar5 + 1;
  } while (iVar3 != 0);
  return 0;
}

