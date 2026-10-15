
void __regparm2 FUN_00034cff(void)

{
  int in_ECX;
  int iVar1;
  undefined2 *puVar2;
  
  puVar2 = (undefined2 *)(DAT_00033a22 + in_ECX * 0xa0);
  *puVar2 = 0x3110;
  for (iVar1 = DAT_00033a2a - 2; puVar2 = puVar2 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0x3120;
  }
  *puVar2 = 0x3111;
  FUN_00034a8c(CONCAT22((short)((uint)(in_ECX << 5) >> 0x10),0x3100),in_ECX,in_ECX * 0xa0);
  return;
}

