
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000257bb(undefined1 *param_1,undefined4 param_2)

{
  DAT_0003f5dc = 0;
  FUN_00025841();
  FUN_00025864();
  _DAT_000a0000 = CONCAT11(DAT_000a0001,*param_1);
  DAT_0003f5dc = DAT_0003f5dc + DAT_0003f5da;
  FUN_00025841();
  _DAT_000a0000 = *(undefined2 *)(param_1 + 1);
  FUN_00025864();
  _DAT_000a0002 = *(undefined2 *)(param_1 + 4);
  DAT_0003f5dc = DAT_0003f5dc + DAT_0003f5da;
  FUN_00025841();
  _DAT_000a0000 = CONCAT11(DAT_000a0001,param_1[6]);
  FUN_00025864();
  return CONCAT44(param_2,param_1);
}

