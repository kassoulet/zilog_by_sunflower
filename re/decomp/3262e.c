
void FUN_0003262e(void)

{
  int iVar1;
  
  DAT_0003150a = DAT_0003150a + '\x01';
  if (DAT_0003150a != DAT_00031509) {
LAB_000326b1:
    DAT_0003150b = DAT_0003150b + '\x01';
    iVar1 = 0;
    do {
      if ((byte)(&DAT_000315f0)[iVar1] < 10) {
        (**(code **)(&DAT_0003372f + (uint)(byte)(&DAT_000315f0)[iVar1] * 4))();
      }
      if ((byte)(&DAT_000315b0)[iVar1] < 0x44) {
        (**(code **)(&DAT_000335f7 + (uint)(byte)(&DAT_000315b0)[iVar1] * 4))();
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 != DAT_0003646e);
    return;
  }
  DAT_0003150a = '\0';
  DAT_0003150b = '\0';
  if (DAT_0003151c != '\0') {
    DAT_0003151c = DAT_0003151c + -1;
    goto LAB_000326b1;
  }
  if (DAT_0003151d == -1) {
    if (DAT_00031518 < DAT_0003151a) goto LAB_00032695;
    DAT_0003151f = 0;
    DAT_0003151d = DAT_00031514 + 1;
  }
  FUN_0003299e();
LAB_00032695:
  if (DAT_0003151f != -1) {
    FUN_000329f9();
  }
  FUN_000326e9();
  DAT_00031518 = DAT_00031518 + 1;
  return;
}

