
void FUN_00037dc9(undefined4 param_1,uint param_2,uint unaff_EBX)

{
  uint uVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  uint uVar3;
  undefined3 uVar4;
  
  uVar1 = FUN_00037da3(0x89);
  uVar1 = uVar1 & 0xffff;
  uVar3 = unaff_EBX & 0xffffff00;
  uVar2 = uVar1;
  if (param_2 < uVar1) {
    uVar3 = CONCAT31((int3)(unaff_EBX >> 8),0x40);
    uVar2 = param_2;
    param_2 = uVar1;
  }
  param_2 = param_2 - uVar2;
  if (param_2 != 0) {
    uVar4 = (undefined3)(uVar3 >> 8);
    if (param_2 < 0x1000) {
      if ((char)uVar3 != '@') {
        uVar2 = uVar2 + param_2;
      }
      FUN_00037d7a(uVar2,param_2,CONCAT31(uVar4,9),extraout_ECX,param_2);
    }
    else {
      param_2 = param_2 + uVar2;
      if (uVar2 < 0x1000) {
        uVar2 = 0x1000;
      }
      if (0xfc00 < param_2) {
        param_2 = 0xfc00;
      }
      FUN_00037d62(uVar2 >> 8 & 0xff,param_2,CONCAT31(uVar4,7));
      FUN_00037d62(param_2 >> 8 & 0xff,param_2,CONCAT31(uVar4,8));
      FUN_00037d62(uVar3,extraout_EDX,CONCAT31(uVar4,0xd));
      FUN_00037ecb();
      FUN_00037d62();
    }
  }
  return;
}

