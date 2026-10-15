
undefined8 __regparm2 FUN_00025ade(void)

{
  code *pcVar1;
  undefined4 in_ECX;
  int iVar2;
  undefined1 *puVar3;
  byte bVar4;
  undefined4 unaff_retaddr;
  
  bVar4 = 0;
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)(0x13);
  iVar2 = 0x300;
  out(0x3c8,0);
  puVar3 = &DAT_0003f5e6;
  do {
    out(*puVar3,0x3c9);
    iVar2 = iVar2 + -1;
    puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
  } while (iVar2 != 0);
  return CONCAT44(in_ECX,unaff_retaddr);
}

