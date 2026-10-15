
void FUN_0002edc9(char param_1,int param_2,int *unaff_EBX,int param_4,uint param_5)

{
  int iVar1;
  undefined1 uVar2;
  
  if ((param_5 & 0x80) != 0) {
    if (param_4 == 8) {
      if (param_1 == '\0') {
        iVar1 = *unaff_EBX;
        *unaff_EBX = iVar1 + 1;
        *(undefined1 *)(iVar1 + param_2) = 0x30;
        return;
      }
    }
    else if (param_4 == 0x10) {
      iVar1 = *unaff_EBX;
      *unaff_EBX = iVar1 + 1;
      *(undefined1 *)(iVar1 + param_2) = 0x30;
      if ((param_5 & 0x200) == 0) {
        uVar2 = 0x78;
      }
      else {
        uVar2 = 0x58;
      }
      iVar1 = *unaff_EBX;
      *unaff_EBX = iVar1 + 1;
      *(undefined1 *)(iVar1 + param_2) = uVar2;
      return;
    }
  }
  return;
}

