
char * FUN_0002f440(char *param_1,undefined4 param_2)

{
  char cVar1;
  
  if (param_1 != (char *)0x0) {
    cVar1 = (char)((uint)param_2 >> 8);
    if (cVar1 != '\0') {
      param_1[1] = (char)param_2;
      *param_1 = cVar1;
      return (char *)0x2;
    }
    *param_1 = (char)param_2;
    param_1 = (char *)0x1;
  }
  return param_1;
}

