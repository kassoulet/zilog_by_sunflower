
void FUN_00034cae(undefined2 param_1)

{
  char *unaff_ESI;
  undefined2 *unaff_EDI;
  
  while( true ) {
    param_1 = CONCAT11((char)((ushort)param_1 >> 8),*unaff_ESI);
    if (*unaff_ESI == '\0') break;
    *unaff_EDI = param_1;
    unaff_ESI = unaff_ESI + 1;
    unaff_EDI = unaff_EDI + 1;
  }
  return;
}

