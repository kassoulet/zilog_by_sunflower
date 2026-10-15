
void FUN_00022b9c(undefined4 param_1,int param_2,int unaff_EBX)

{
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar1 = -64000;
  do {
    *(undefined4 *)(&/*c*/20.0 + iVar1 * 4 + unaff_EDI) =
         *(undefined4 *)
          (param_2 +
          (uint)CONCAT11(*(undefined1 *)(unaff_ESI + 64000 + iVar1),
                         *(undefined1 *)(unaff_EBX + 64000 + iVar1)) * 4);
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0);
  return;
}

