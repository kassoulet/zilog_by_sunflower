
undefined8 FUN_0002929e(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar1 = DAT_0003eeb4;
  piVar3 = (int *)0x0;
  while ((piVar2 = piVar1, piVar2 != (int *)0x0 && (piVar2 <= param_1))) {
    piVar3 = piVar2;
    piVar1 = (int *)piVar2[2];
  }
  param_1[1] = (int)piVar3;
  param_1[2] = (int)piVar2;
  piVar1 = param_1;
  if (piVar3 != (int *)0x0) {
    piVar3[2] = (int)param_1;
    piVar1 = DAT_0003eeb4;
  }
  DAT_0003eeb4 = piVar1;
  if (piVar2 != (int *)0x0) {
    piVar2[1] = (int)param_1;
  }
  piVar1 = param_1 + 8;
  piVar3 = param_1 + 0xb;
  param_1[8] = 0;
  param_1[4] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[9] = (int)piVar1;
  param_1[10] = (int)piVar1;
  param_1[3] = (int)piVar1;
  *piVar3 = *param_1 + -0x2c;
  *(undefined4 *)((int)piVar3 + *param_1 + -0x2c) = 0xffffffff;
  return CONCAT44(param_2,piVar3);
}

