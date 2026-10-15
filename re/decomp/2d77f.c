
void FUN_0002d77f(char *param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  
  *(undefined2 *)(param_2 + 0x1e) = 0;
  do {
    cVar1 = *param_1;
    if (cVar1 == '-') {
      *(byte *)(param_2 + 0x1e) = *(byte *)(param_2 + 0x1e) | 8;
    }
    else if (cVar1 == '#') {
      *(byte *)(param_2 + 0x1e) = *(byte *)(param_2 + 0x1e) | 1;
    }
    else if (cVar1 == '+') {
      bVar2 = *(byte *)(param_2 + 0x1e);
      *(byte *)(param_2 + 0x1e) = bVar2 | 4;
      *(byte *)(param_2 + 0x1e) = bVar2 & 0xfd | 4;
    }
    else if (cVar1 == ' ') {
      if ((*(byte *)(param_2 + 0x1e) & 4) == 0) {
        *(byte *)(param_2 + 0x1e) = *(byte *)(param_2 + 0x1e) | 2;
      }
    }
    else {
      if (cVar1 != '0') {
        return;
      }
      *(undefined1 *)(param_2 + 0x16) = 0x30;
    }
    param_1 = param_1 + 1;
  } while( true );
}

