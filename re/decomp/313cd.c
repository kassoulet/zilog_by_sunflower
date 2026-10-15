
longlong FUN_000313cd(undefined4 param_1,uint param_2)

{
  ulonglong uVar1;
  
  uVar1 = FUN_0003146f(param_1,param_1);
  if ((int)uVar1 == 0) {
    return CONCAT44(param_2,(uint)((&DAT_0003fda0)[(byte)((char)(uVar1 >> 0x20) + 1)] & 0x80));
  }
  if ((0x8280ffffffff < uVar1) && (uVar1 < 0x829b00000000)) {
    return CONCAT44(param_2,1);
  }
  return (ulonglong)param_2 << 0x20;
}

