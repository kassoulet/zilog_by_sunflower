
uint FUN_0002f24c(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_2 & 0x7ff00000) != 0) {
    uVar1 = (uint)(CARRY4(param_2,param_2) || CARRY4(param_2 * 2,(uint)CARRY4(param_1,param_1))) <<
            0x1f;
    uVar2 = param_1 * 2 + 0x20000000;
    uVar3 = param_2 * 2 + (uint)CARRY4(param_1,param_1) + (uint)(0xdfffffff < param_1 * 2);
    if ((uVar3 == 0) || (0x8fdfffff < uVar3)) {
      return uVar1 | 0x7f800000;
    }
    if (0x701fffff < uVar3) {
      return ((uVar3 + 0x90000000) * 2 + (uint)CARRY4(uVar2,uVar2)) * 2 +
             (uint)CARRY4(uVar2 * 2,uVar2 * 2) | uVar1;
    }
  }
  return 0;
}

