
void FUN_00039a15(undefined4 param_1,undefined4 param_2,undefined4 unaff_EBX)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  bool bVar4;
  
  DAT_0003988c = 0;
  uVar2 = DAT_00039880;
  if ((DAT_0003645c & 2) == 0) {
    uVar2 = DAT_00039880 >> 1;
  }
  uVar1 = 0;
  puVar3 = DAT_00039888;
  if ((DAT_0003645c & 0x10) == 0) {
    uVar1 = 0x80808080;
  }
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = uVar1;
    puVar3 = puVar3 + 1;
  }
  bVar4 = (int)(DAT_00039880 << 1) < 0;
  FUN_00037000();
  uVar1 = DAT_00036ffc;
  if (bVar4) {
    uVar1 = FUN_00037099(DAT_00036ffc,param_2,unaff_EBX,0);
  }
  DAT_00039884 = uVar1;
  FUN_00039aa5();
  return;
}

