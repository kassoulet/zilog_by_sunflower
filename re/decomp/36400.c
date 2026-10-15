
void FUN_00036400(void)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  uVar2 = 0x10000;
  iVar1 = 4;
  puVar3 = &DAT_00036226;
  do {
    if (((char)puVar3[4] != '\0') && (*puVar3 < uVar2)) {
      uVar2 = *puVar3;
    }
    puVar3 = (uint *)((int)puVar3 + 0x12);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

