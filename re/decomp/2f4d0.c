
char * FUN_0002f4d0(longlong *param_1,char *param_2,int unaff_EBX)

{
  char cVar1;
  char *pcVar2;
  longlong lVar3;
  undefined1 uVar4;
  char local_57 [35];
  undefined4 local_24;
  undefined4 local_20;
  char *local_18;
  
  pcVar2 = local_57;
  lVar3 = *param_1;
  uVar4 = 0;
  do {
    local_20 = (undefined4)((ulonglong)lVar3 >> 0x20);
    local_24 = (undefined4)lVar3;
    lVar3 = FUN_00030229(local_24,local_20,unaff_EBX,0,uVar4);
    *pcVar2 = s_0123456789abcdefghijklmnopqrstuv_0003fecc[unaff_EBX];
    pcVar2 = pcVar2 + 1;
    local_18 = param_2;
  } while (lVar3 != 0);
  do {
    pcVar2 = pcVar2 + -1;
    cVar1 = *pcVar2;
    *local_18 = cVar1;
    local_18 = local_18 + 1;
  } while (cVar1 != '\0');
  return param_2;
}

