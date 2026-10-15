
ulonglong FUN_0003384b(ushort param_1,undefined4 param_2,uint unaff_EBX,uint param_4)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  
  DAT_000338d5 = (byte)((param_1 & 0x7ff) >> 8);
  DAT_000338d4 = (byte)(param_1 & 0x7ff) & 0xfc;
  bVar1 = DAT_000338d5 >> 2;
  out((ushort)(byte)(&DAT_000338dc)[bVar1],DAT_000338d5 & 3 | 4);
  bVar2 = DAT_000338d5 & 3 | DAT_000338d4;
  out((ushort)(byte)(&DAT_000338de)[bVar1],bVar2);
  out((ushort)(byte)(&DAT_000338e0)[bVar1],bVar2);
  bVar1 = DAT_000338d5 >> 2;
  iVar3 = (param_4 >> bVar1) - 1;
  out((ushort)(byte)(&DAT_000338f8)[DAT_000338d5],(char)iVar3);
  out((ushort)(byte)(&DAT_000338f8)[DAT_000338d5],(char)((uint)iVar3 >> 8));
  unaff_EBX = unaff_EBX >> bVar1;
  out((ushort)(byte)(&DAT_000338f0)[DAT_000338d5],(char)unaff_EBX);
  out((ushort)(byte)(&DAT_000338f0)[DAT_000338d5],(char)(unaff_EBX >> 8));
  out((ushort)(byte)(&DAT_000338e8)[DAT_000338d5],(char)((unaff_EBX >> 0xf) >> (bVar1 ^ 1)));
  out((ushort)(byte)(&DAT_000338dc)[DAT_000338d5 >> 2],DAT_000338d5 & 3);
  return (ulonglong)CONCAT14((&DAT_000338dc)[DAT_000338d5 >> 2],(uint)(DAT_000338d5 & 3));
}

