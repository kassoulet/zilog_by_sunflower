
/* WARNING: Removing unreachable block (ram,0x00028c14) */

undefined4 FUN_00028bca(undefined4 param_1,uint param_2,undefined1 unaff_BL)

{
  code *pcVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar2;
  undefined4 unaff_EDI;
  ulonglong uVar3;
  
  uVar3 = FUN_0002e624();
  uVar2 = extraout_ECX;
  if ((0xffffffff < (longlong)uVar3) && ((uVar3 & 0x80) == 0)) {
    FUN_0002e679(extraout_ECX,(uint)uVar3 | 0x8000);
    uVar2 = extraout_ECX_00;
  }
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)(CONCAT11(0x42,unaff_BL),param_2,uVar2,param_2 >> 0x10);
  return unaff_EDI;
}

