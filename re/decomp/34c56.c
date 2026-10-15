
void FUN_00034c56(void)

{
  short sVar1;
  short *unaff_ESI;
  
  while( true ) {
    sVar1 = *unaff_ESI;
    unaff_ESI = unaff_ESI + 1;
    if (sVar1 == -1) break;
    FUN_00034bf8();
  }
  return;
}

