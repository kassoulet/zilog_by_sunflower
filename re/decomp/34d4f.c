
void __regparm2 FUN_00034d4f(void)

{
  int in_ECX;
  uint uVar1;
  undefined2 *puVar2;
  
  puVar2 = (undefined2 *)(DAT_00033a22 + in_ECX * 0xa0);
  for (uVar1 = (uint)DAT_00033a2a; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = 0x7120;
    puVar2 = puVar2 + 1;
  }
  FUN_00034a8c(CONCAT22((short)((uint)(in_ECX << 5) >> 0x10),0x7100),in_ECX,in_ECX * 0xa0);
  return;
}

