
undefined4 __regparm2 thunk_FUN_00023acd(undefined4 param_1,char *param_2,undefined1 param_3)

{
  char *pcVar1;
  char cVar2;
  code *pcVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  pcVar3 = (code *)swi(0x21);
  uVar4 = (*pcVar3)(0x3d01,&DAT_000238b0);
  pcVar6 = param_2;
  do {
    pcVar1 = pcVar6 + 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar1;
  } while (cVar2 != '\0');
  pcVar3 = (code *)swi(0x21);
  (*pcVar3)(0x4000,param_2,uVar4,pcVar1 + (-1 - (int)param_2));
  FUN_00024e5a(0,0xf);
  pcVar3 = (code *)swi(0x21);
  uVar5 = (*pcVar3)(CONCAT11(0x4c,param_3));
  return uVar5;
}

