
longlong FUN_0002e400(int *param_1,uint param_2)

{
  if ((*(ushort *)(param_1 + 2) & 0x7fff) == 0x7fff) {
    if ((param_1[1] == -0x80000000) && (*param_1 == 0)) {
      return CONCAT44(param_2,3);
    }
    return CONCAT44(param_2,2);
  }
  if ((*(ushort *)(param_1 + 2) & 0x7fff) != 0) {
    return CONCAT44(param_2,1);
  }
  if ((param_1[1] == 0) && (*param_1 == 0)) {
    return (ulonglong)param_2 << 0x20;
  }
  return CONCAT44(param_2,4);
}

