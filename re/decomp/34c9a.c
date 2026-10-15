
void FUN_00034c9a(short param_1)

{
  short *unaff_ESI;
  
  do {
    if (param_1 == *unaff_ESI) {
      return;
    }
    unaff_ESI = unaff_ESI + 1;
  } while (*unaff_ESI != -1);
  return;
}

