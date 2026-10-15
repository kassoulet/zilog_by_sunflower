
void FUN_00033fd9(void)

{
  int iVar1;
  undefined2 *puVar2;
  
  if (DAT_00033997 != '\x01') {
    puVar2 = &DAT_00036472;
    for (iVar1 = 0xa40; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined1 *)puVar2 = 0;
      puVar2 = (undefined2 *)((int)puVar2 + 1);
    }
  }
  return;
}

