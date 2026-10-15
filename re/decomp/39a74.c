
void FUN_00039a74(undefined4 param_1,undefined4 param_2,undefined4 unaff_EBX,undefined4 param_4)

{
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined1 in_CF;
  
  FUN_0003704a(DAT_00039884);
  if ((bool)in_CF) {
    FUN_00037099();
    param_4 = extraout_ECX;
    param_2 = extraout_EDX;
  }
  FUN_0003704a(DAT_000398ae);
  if ((bool)in_CF) {
    FUN_00037099(DAT_00036ffc,param_2,unaff_EBX,param_4);
  }
  return;
}

