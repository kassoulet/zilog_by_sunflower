
/* WARNING: Removing unreachable block (ram,0x000362cb) */
/* WARNING: Removing unreachable block (ram,0x000362e7) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0003627e(undefined4 param_1,undefined4 param_2,undefined4 unaff_EBX)

{
  code *pcVar1;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  int iVar2;
  undefined4 *puVar3;
  undefined2 in_ES;
  undefined2 in_DS;
  
  iVar2 = 4;
  puVar3 = &DAT_00036226;
  do {
    if (*(char *)(puVar3 + 4) == '\0') goto LAB_00036299;
    puVar3 = (undefined4 *)((int)puVar3 + 0x12);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  param_1 = 0x101;
LAB_00036299:
  *puVar3 = unaff_EBX;
  puVar3[1] = 0;
  puVar3[2] = 0;
  puVar3[3] = param_1;
  *(undefined1 *)(puVar3 + 4) = 1;
  FUN_00036400();
  if (DAT_0003626e == 0) {
    pcVar1 = (code *)swi(0x21);
    DAT_0003627c = in_DS;
    (*pcVar1)(CONCAT22(extraout_var,0x3508));
    pcVar1 = (code *)swi(0x21);
    DAT_00036272 = unaff_EBX;
    _DAT_00036276 = in_ES;
    (*pcVar1)(CONCAT22(extraout_var_00,0x2508),&LAB_00036369);
  }
  FUN_00036422();
  return;
}

