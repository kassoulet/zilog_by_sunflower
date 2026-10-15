
void __regparm2 FUN_00025864(void)

{
  undefined2 uVar1;
  int in_ECX;
  undefined2 *unaff_ESI;
  undefined2 *unaff_EDI;
  
  do {
    uVar1 = unaff_ESI[1];
    *unaff_EDI = *unaff_ESI;
    *(char *)(unaff_EDI + 1) = (char)uVar1;
    unaff_ESI = unaff_ESI + 2;
    unaff_EDI = (undefined2 *)((int)unaff_EDI + 3);
    in_ECX = in_ECX + -1;
  } while (in_ECX != 0);
  return;
}

