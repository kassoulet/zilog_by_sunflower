
char * FUN_000296c7(uint param_1,char *param_2,uint unaff_EBX)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  char local_37 [35];
  
  pcVar3 = local_37;
  do {
    uVar2 = param_1 / unaff_EBX;
    *pcVar3 = s_0123456789abcdefghijklmnopqrstuv_0003fcbc[param_1 % unaff_EBX];
    pcVar3 = pcVar3 + 1;
    param_1 = uVar2;
    pcVar4 = param_2;
  } while (uVar2 != 0);
  do {
    pcVar3 = pcVar3 + -1;
    cVar1 = *pcVar3;
    *pcVar4 = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  return param_2;
}

