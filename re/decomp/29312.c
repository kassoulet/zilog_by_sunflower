
longlong FUN_00029312(undefined4 param_1,uint param_2)

{
  int *piVar1;
  undefined3 uVar2;
  ushort in_DS;
  
  if (DAT_0003eeb4 != 0) {
    piVar1 = *(int **)(DAT_0003eeb4 + 0x24);
    if (((1 < DAT_0003ed42) && (DAT_0003ed42 < 9)) && (DAT_0003ed44 == '\0')) {
      uVar2 = SegmentLimit((uint)in_DS);
      DAT_0003ed14 = (ushort)uVar2 + 1;
    }
    if ((int)piVar1 + *piVar1 + 4 == DAT_0003ed14) {
      return CONCAT44(param_2,*piVar1);
    }
  }
  return (ulonglong)param_2 << 0x20;
}

