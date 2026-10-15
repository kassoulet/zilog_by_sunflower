
void __regparm3 FUN_00033b46(void)

{
  code *pcVar1;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined4 uVar2;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined2 extraout_var_05;
  undefined2 extraout_var_06;
  undefined2 extraout_var_07;
  undefined2 extraout_var_08;
  undefined2 extraout_var_09;
  undefined2 extraout_var_10;
  undefined2 extraout_var_11;
  undefined2 extraout_var_12;
  undefined2 extraout_var_13;
  undefined2 extraout_var_14;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  uint extraout_ECX_01;
  uint extraout_ECX_02;
  uint extraout_ECX_03;
  undefined4 extraout_ECX_04;
  uint extraout_ECX_05;
  undefined4 extraout_ECX_06;
  uint extraout_ECX_07;
  undefined4 extraout_ECX_08;
  uint extraout_ECX_09;
  undefined4 extraout_ECX_10;
  uint extraout_ECX_11;
  undefined4 extraout_ECX_12;
  uint extraout_ECX_13;
  uint uVar3;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined4 extraout_EDX_07;
  undefined4 extraout_EDX_08;
  undefined4 extraout_EDX_09;
  byte unaff_BL;
  ushort uVar4;
  undefined4 uVar5;
  undefined1 in_CF;
  undefined8 uVar6;
  
  pcVar1 = (code *)swi(0x10);
  uVar6 = (*pcVar1)(3);
  uVar4 = (ushort)unaff_BL;
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)(CONCAT11(2,(char)uVar6),(uint)((ulonglong)uVar6 >> 0x20) & 0xffffff00);
  FUN_00034a96(CONCAT22(extraout_var,0x3100),extraout_EDX,uVar4,0x50);
  FUN_00034a80(CONCAT22(extraout_var_00,0x3100));
  FUN_00034a96(CONCAT22(extraout_var_01,0x3100),extraout_EDX_00,uVar4,0x50);
  FUN_00034a80(CONCAT22(extraout_var_02,0x3100));
  FUN_000349a2();
  DAT_00033a2c = uVar4;
  FUN_00037000(0x280);
  uVar2 = DAT_00036ffc;
  if ((bool)in_CF) {
    uVar2 = FUN_00037099(DAT_00036ffc,extraout_EDX_01,uVar4,extraout_ECX);
  }
LAB_00033bce:
  do {
    do {
      DAT_00033a1c = uVar2;
      FUN_00034b19();
      FUN_00034b33();
      DAT_00033a20 = (undefined2)extraout_ECX_00;
      uVar5 = 0x20;
      DAT_00033a2a = 0x20;
      DAT_00033a22 = 0x210;
      FUN_00034ac8(CONCAT22(extraout_var_03,0x7100),extraout_ECX_00);
      FUN_00034a80(CONCAT22(extraout_var_04,0x7100));
      FUN_00034cb8(4);
      FUN_00034d94();
      if ((bool)in_CF) {
        FUN_0003704a(DAT_00033a1c);
        if ((bool)in_CF) {
          FUN_00037099(DAT_00036ffc,extraout_EDX_02,0x20,extraout_ECX_01);
        }
        pcVar1 = (code *)swi(0x10);
        (*pcVar1)(3);
        DAT_00034e10 = 0x301;
        DAT_00036450 = 0xffff;
        return;
      }
      in_CF = false;
      if (extraout_ECX_01 == 0) {
        FUN_00034a03(DAT_00033a2c);
        uVar3 = extraout_ECX_02;
        uVar2 = extraout_EDX_03;
        goto LAB_00033f6f;
      }
      FUN_00034a03(extraout_ECX_01 & 0xffff);
      uVar2 = DAT_00033a1c;
    } while ((bool)in_CF);
    in_CF = DAT_00036456 != -1;
    uVar3 = extraout_ECX_03;
    uVar2 = extraout_EDX_04;
    if (DAT_00036456 != -1) {
      FUN_00034b19();
      FUN_00034c78();
      DAT_00033a20 = (undefined2)extraout_ECX_04;
      uVar5 = 0xd;
      DAT_00033a2a = 0xd;
      DAT_00033a22 = 0x220;
      FUN_00034ac8(CONCAT22(extraout_var_05,0x7100),extraout_ECX_04);
      FUN_00034a80(CONCAT22(extraout_var_06,0x7100));
      FUN_00034cb8(10);
      FUN_00034c9a(DAT_00036456);
      FUN_00034d94();
      uVar2 = DAT_00033a1c;
      if ((bool)in_CF) goto LAB_00033bce;
      DAT_00036456 = *(short *)(*(int *)(DAT_0003398f + 0x1e) + extraout_ECX_05 * 2);
      in_CF = DAT_00036458 != -1;
      uVar3 = extraout_ECX_05;
      uVar2 = extraout_EDX_05;
      if (DAT_00036458 != -1) {
        FUN_00034b19();
        FUN_00034c56();
        DAT_00033a20 = (undefined2)extraout_ECX_06;
        uVar5 = 0xc;
        DAT_00033a2a = 0xc;
        DAT_00033a22 = 0x220;
        FUN_00034ac8(CONCAT22(extraout_var_07,0x7100),extraout_ECX_06);
        FUN_00034a80(CONCAT22(extraout_var_08,0x7100));
        FUN_00034cb8(10);
        FUN_00034c9a(DAT_00036458);
        FUN_00034d94();
        uVar2 = DAT_00033a1c;
        if ((bool)in_CF) goto LAB_00033bce;
        DAT_00036458 = (char)*(undefined2 *)((int)&PTR_LAB_00033b12 + extraout_ECX_07 * 2);
        uVar3 = extraout_ECX_07;
        uVar2 = extraout_EDX_06;
      }
    }
    in_CF = DAT_00036459 != -1;
    if (DAT_00036459 != -1) {
      FUN_00034b19();
      FUN_00034c56();
      DAT_00033a20 = (undefined2)extraout_ECX_08;
      uVar5 = 0xc;
      DAT_00033a2a = 0xc;
      DAT_00033a22 = 0x220;
      FUN_00034ac8(CONCAT22(extraout_var_09,0x7100),extraout_ECX_08);
      FUN_00034a80(CONCAT22(extraout_var_10,0x7100));
      FUN_00034cb8(10);
      FUN_00034c9a(DAT_00036459);
      FUN_00034d94();
      uVar2 = DAT_00033a1c;
      if ((bool)in_CF) goto LAB_00033bce;
      DAT_00036459 = (char)*(undefined2 *)((int)&PTR_LAB_00033b28 + extraout_ECX_09 * 2);
      uVar3 = extraout_ECX_09;
      uVar2 = extraout_EDX_07;
    }
    in_CF = DAT_0003645a != -1;
    if (DAT_0003645a != -1) {
      FUN_00034b19();
      FUN_00034c56();
      DAT_00033a20 = (undefined2)extraout_ECX_10;
      uVar5 = 0x14;
      DAT_00033a2a = 0x14;
      DAT_00033a22 = 0x21a;
      FUN_00034ac8(CONCAT22(extraout_var_11,0x7100),extraout_ECX_10);
      FUN_00034a80(CONCAT22(extraout_var_12,0x7100));
      FUN_00034cb8(0xe);
      FUN_00034c9a(DAT_0003645a);
      FUN_00034d94();
      uVar2 = DAT_00033a1c;
      if ((bool)in_CF) goto LAB_00033bce;
      DAT_0003645a = *(short *)(&DAT_00033b36 + extraout_ECX_11 * 2);
      uVar3 = extraout_ECX_11;
      uVar2 = extraout_EDX_08;
    }
    in_CF = DAT_0003645c != 0xffff;
    if ((DAT_0003645c == 0xffff) || (in_CF = 0, (DAT_0003645c & 0x100) == 0)) goto LAB_00033f6f;
    FUN_00034b19();
    FUN_00034b8d();
    DAT_00033a20 = (undefined2)extraout_ECX_12;
    uVar5 = 0x18;
    DAT_00033a2a = 0x18;
    DAT_00033a22 = 0x216;
    FUN_00034ac8(CONCAT22(extraout_var_13,0x7100),extraout_ECX_12);
    FUN_00034a80(CONCAT22(extraout_var_14,0x7100));
    FUN_00034cb8(4);
    in_CF = false;
    FUN_00034d94();
    uVar2 = DAT_00033a1c;
    if (!(bool)in_CF) {
      uVar3 = extraout_ECX_13;
      if ((DAT_0003645c & 8) == 0) {
        uVar3 = extraout_ECX_13 << 1;
      }
      if ((uVar3 & 1) == 0) {
        DAT_0003645c = DAT_0003645c & 0xfff7;
        DAT_0003645c = DAT_0003645c | 4;
      }
      else {
        DAT_0003645c = DAT_0003645c & 0xfffb;
        DAT_0003645c = DAT_0003645c | 8;
      }
      in_CF = uVar3 == 0;
      uVar2 = extraout_EDX_09;
      if (1 < uVar3) {
        in_CF = 0;
        DAT_0003645c = DAT_0003645c | 0x20;
      }
LAB_00033f6f:
      FUN_0003704a(DAT_00033a1c);
      if ((bool)in_CF) {
        FUN_00037099(DAT_00036ffc,uVar2,uVar5,uVar3);
      }
      pcVar1 = (code *)swi(0x10);
      (*pcVar1)(3);
      DAT_00034e10 = 0;
      return;
    }
  } while( true );
}

