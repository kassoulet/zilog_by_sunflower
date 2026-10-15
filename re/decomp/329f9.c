
void FUN_000329f9(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)DAT_0003151f;
  DAT_00031510 = DAT_0003150c;
  if (DAT_0003150c != (char *)0x0) {
    if (*(ushort *)(DAT_0003150c + 10) <= DAT_0003151f) {
      uVar1 = 0;
    }
    DAT_00031518 = (short)uVar1;
    DAT_00031510 = DAT_0003150c + 0xc;
    iVar2 = DAT_000314fc;
    if (DAT_00031518 != 0) {
LAB_00032a29:
      do {
        if (*DAT_00031510 == -4) {
          DAT_00031510 = DAT_00031510 + 1;
        }
        else {
          DAT_00031510 = DAT_00031510 + 5;
          iVar2 = iVar2 + -1;
          if (iVar2 != 0) goto LAB_00032a29;
        }
        uVar1 = uVar1 - 1;
        iVar2 = DAT_000314fc;
      } while (uVar1 != 0);
    }
  }
  DAT_0003151f = 0xffff;
  return;
}

