
void FUN_0002f03a(undefined4 *param_1,undefined4 *param_2,uint unaff_EBX)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  
  if (param_2 != param_1) {
    if ((param_2 < param_1) && (param_1 < (undefined4 *)((int)param_2 + unaff_EBX))) {
      uVar1 = unaff_EBX >> 1;
      puVar2 = (undefined4 *)((int)param_2 + unaff_EBX);
      puVar3 = (undefined2 *)((int)param_1 + unaff_EBX);
      while( true ) {
        if (uVar1 == 0) break;
        uVar1 = uVar1 - 1;
        puVar3[-1] = *(undefined2 *)((int)puVar2 - 2U);
        puVar2 = (undefined4 *)((int)puVar2 - 2U);
        puVar3 = puVar3 + -1;
      }
      uVar1 = (uint)((unaff_EBX & 1) != 0);
      while( true ) {
        puVar3 = (undefined2 *)((int)puVar3 + -1);
        puVar2 = (undefined4 *)((int)puVar2 - 1);
        if (uVar1 == 0) break;
        uVar1 = uVar1 - 1;
        *(undefined1 *)puVar3 = *(undefined1 *)puVar2;
      }
      return;
    }
    for (uVar1 = unaff_EBX >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *param_1 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
    for (unaff_EBX = unaff_EBX & 3; unaff_EBX != 0; unaff_EBX = unaff_EBX - 1) {
      *(undefined1 *)param_1 = *(undefined1 *)param_2;
      param_2 = (undefined4 *)((int)param_2 + 1);
      param_1 = (undefined4 *)((int)param_1 + 1);
    }
  }
  return;
}

