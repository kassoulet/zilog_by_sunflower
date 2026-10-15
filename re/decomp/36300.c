
/* WARNING: Removing unreachable block (ram,0x0003634c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00036300(int param_1)

{
  code *pcVar1;
  undefined2 extraout_var;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 4;
  puVar3 = &DAT_00036226;
  do {
    if ((*(char *)(puVar3 + 4) != '\0') && (puVar3[3] == param_1)) goto LAB_00036322;
    puVar3 = (undefined4 *)((int)puVar3 + 0x12);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  param_1 = 0x102;
LAB_00036322:
  *(undefined1 *)(puVar3 + 4) = 0;
  FUN_00036400(param_1);
  FUN_00036422();
  iVar2 = 4;
  puVar3 = &DAT_00036226;
  do {
    if (*(char *)(puVar3 + 4) == '\x01') {
      return;
    }
    puVar3 = (undefined4 *)((int)puVar3 + 0x12);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)(CONCAT22(extraout_var,0x2508),(int)_DAT_00036272);
  DAT_0003626e = 0;
  return;
}

