
void thunk_FUN_00027561(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *extraout_ECX;
  undefined2 in_DS;
  
  if (param_1 != (int *)0x0) {
    if (((DAT_000411a0 == (int *)0x0) ||
        ((((param_1 < DAT_000411a0 ||
           (piVar2 = DAT_000411a0, (int *)(*DAT_000411a0 + (int)DAT_000411a0) <= param_1)) &&
          ((piVar2 = (int *)DAT_000411a0[1], piVar2 == (int *)0x0 ||
           ((param_1 < piVar2 || ((int *)(*piVar2 + (int)piVar2) <= param_1)))))) &&
         ((piVar2 = (int *)DAT_000411a0[2], piVar2 == (int *)0x0 ||
          ((param_1 < piVar2 || ((int *)(*piVar2 + (int)piVar2) <= param_1)))))))) &&
       ((piVar1 = DAT_0003eeb4, DAT_0003eeb8 == (int *)0x0 ||
        ((((param_1 < DAT_0003eeb8 ||
           (piVar2 = DAT_0003eeb8, (int *)(*DAT_0003eeb8 + (int)DAT_0003eeb8) <= param_1)) &&
          ((piVar2 = (int *)DAT_0003eeb8[1], piVar2 == (int *)0x0 ||
           ((param_1 < piVar2 || ((int *)(*piVar2 + (int)piVar2) <= param_1)))))) &&
         ((piVar2 = (int *)DAT_0003eeb8[2], piVar2 == (int *)0x0 ||
          ((param_1 < piVar2 || ((int *)(*piVar2 + (int)piVar2) <= param_1)))))))))) {
      while( true ) {
        if (piVar1 == (int *)0x0) {
          return;
        }
        if ((piVar1 <= param_1) && (piVar2 = piVar1, param_1 < (int *)(*piVar1 + (int)piVar1)))
        break;
        piVar1 = (int *)piVar1[2];
      }
    }
    FUN_00028fb0(param_1,in_DS,piVar2);
    if ((extraout_ECX < DAT_0003eeb8) && (DAT_0003eebc < (uint)extraout_ECX[5])) {
      DAT_0003eebc = extraout_ECX[5];
    }
    DAT_000411e0 = 0;
    DAT_000411a0 = extraout_ECX;
  }
  return;
}

