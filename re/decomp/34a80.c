
void FUN_00034a80(undefined2 param_1)

{
  char *unaff_ESI;
  int unaff_EDI;
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)(unaff_EDI + DAT_00033768 + 0xb8000);
  while( true ) {
    param_1 = CONCAT11((char)((ushort)param_1 >> 8),*unaff_ESI);
    if (*unaff_ESI == '\0') break;
    *puVar1 = param_1;
    unaff_ESI = unaff_ESI + 1;
    puVar1 = puVar1 + 1;
  }
  return;
}

