
void FUN_00034d94(void)

{
  code *pcVar1;
  char cVar2;
  undefined2 uVar3;
  
  DAT_00033a20 = DAT_00033a20 + -1;
  FUN_00034cff();
  while( true ) {
    pcVar1 = (code *)swi(0x16);
    uVar3 = (*pcVar1)(0);
    cVar2 = (char)uVar3;
    if (cVar2 == '\x1b') {
      return;
    }
    if (cVar2 == '\r') break;
    if (cVar2 == '\0') {
      cVar2 = (char)((ushort)uVar3 >> 8);
      if (cVar2 == 'H') {
        FUN_00034d4f();
      }
      else if (cVar2 == 'P') {
        FUN_00034d4f();
      }
      else if (cVar2 == 'I') {
        FUN_00034d4f();
      }
      else if (cVar2 == 'Q') {
        FUN_00034d4f();
      }
      FUN_00034cff();
    }
  }
  return;
}

