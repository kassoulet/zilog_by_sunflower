
char * FUN_0002fdd2(char *param_1,char *param_2,int unaff_EBX)

{
  char *pcVar1;
  
  pcVar1 = param_1;
  for (; (unaff_EBX != 0 && (*param_2 != '\0')); param_2 = param_2 + 1) {
    unaff_EBX = unaff_EBX + -1;
    *pcVar1 = *param_2;
    pcVar1 = pcVar1 + 1;
  }
  for (; unaff_EBX != 0; unaff_EBX = unaff_EBX + -1) {
    *pcVar1 = '\0';
    pcVar1 = pcVar1 + 1;
  }
  return param_1;
}

