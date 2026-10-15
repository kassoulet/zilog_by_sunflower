
void FUN_000343a6(void)

{
  short *psVar1;
  undefined1 uVar2;
  int iVar3;
  short sVar4;
  ushort uVar5;
  char cVar6;
  int iVar7;
  
  iVar7 = 0;
  do {
    iVar3 = (&DAT_000364f2)[iVar7];
    if ((iVar3 != 0) && (((&DAT_00036472)[iVar7] & 2) != 0)) {
      if ((*(byte *)(iVar3 + 0xa4) & 1) != 0) {
        if (((&DAT_00036472)[iVar7] & 8) != 0) {
          sVar4 = (&DAT_00036ab2)[iVar7] - *(ushort *)(iVar3 + 0x2a);
          if ((ushort)(&DAT_00036ab2)[iVar7] < *(ushort *)(iVar3 + 0x2a)) {
            sVar4 = 0;
            (&DAT_00036472)[iVar7] = (&DAT_00036472)[iVar7] | 4;
          }
          (&DAT_00036ab2)[iVar7] = sVar4;
        }
        if ((&DAT_00036bb2)[iVar7] == 0) {
          cVar6 = (char)(&DAT_00036b32)[iVar7];
          if (((((*(byte *)(iVar3 + 0xa4) & 2) == 0) || (cVar6 != *(char *)(iVar3 + 0xa6))) ||
              (((&DAT_00036472)[iVar7] & 8) == 0)) &&
             (((*(byte *)(iVar3 + 0xa4) & 4) != 0 && (cVar6 == *(char *)(iVar3 + 0xa8))))) {
            (&DAT_00036b32)[iVar7] =
                 CONCAT11((char)((ushort)(&DAT_00036b32)[iVar7] >> 8),*(undefined1 *)(iVar3 + 0xa7))
            ;
          }
        }
        psVar1 = (short *)(iVar3 + 0xa9 + (uint)(ushort)(&DAT_00036b32)[iVar7] * 4);
        if ((char)((char)(&DAT_00036b32)[iVar7] + '\x01') == *(char *)(iVar3 + 0xa5)) {
          (&DAT_00036c32)[iVar7] = (char)psVar1[1];
        }
        else {
          DAT_000343a4 = psVar1[2] - *psVar1;
          (&DAT_00036c32)[iVar7] =
               (char)(((int)(short)(psVar1[3] - psVar1[1]) * (int)(short)(&DAT_00036bb2)[iVar7]) /
                     (int)(short)DAT_000343a4) + (char)psVar1[1];
          if ((((&DAT_00036bb2)[iVar7] != 0) || ((*(byte *)(iVar3 + 0xa4) & 2) == 0)) ||
             ((((&DAT_00036472)[iVar7] & 8) != 0 ||
              ((char)(&DAT_00036b32)[iVar7] != *(char *)(iVar3 + 0xa6))))) {
            uVar5 = (&DAT_00036bb2)[iVar7] + 1;
            if (DAT_000343a4 <= uVar5) {
              uVar5 = 0;
              (&DAT_00036b32)[iVar7] = (&DAT_00036b32)[iVar7] + 1;
            }
            (&DAT_00036bb2)[iVar7] = uVar5;
          }
        }
        (&DAT_00036472)[iVar7] = (&DAT_00036472)[iVar7] | 0x40;
      }
      if ((*(byte *)(iVar3 + 0xd9) & 1) != 0) {
        if ((&DAT_00036cf2)[iVar7] == 0) {
          cVar6 = (char)(&DAT_00036c72)[iVar7];
          if (((((*(byte *)(iVar3 + 0xd9) & 2) == 0) || (cVar6 != *(char *)(iVar3 + 0xdb))) ||
              (((&DAT_00036472)[iVar7] & 8) == 0)) &&
             (((*(byte *)(iVar3 + 0xd9) & 4) != 0 && (cVar6 == *(char *)(iVar3 + 0xdd))))) {
            (&DAT_00036c72)[iVar7] =
                 CONCAT11((char)((ushort)(&DAT_00036c72)[iVar7] >> 8),*(undefined1 *)(iVar3 + 0xdc))
            ;
          }
        }
        psVar1 = (short *)(iVar3 + 0xde + (uint)(ushort)(&DAT_00036c72)[iVar7] * 4);
        if ((char)((char)(&DAT_00036c72)[iVar7] + '\x01') == *(char *)(iVar3 + 0xda)) {
          (&DAT_00036d72)[iVar7] = (char)psVar1[1];
        }
        else {
          DAT_000343a4 = psVar1[2] - *psVar1;
          (&DAT_00036d72)[iVar7] =
               (char)(((int)(short)(psVar1[3] - psVar1[1]) * (int)(short)(&DAT_00036cf2)[iVar7]) /
                     (int)(short)DAT_000343a4) + (char)psVar1[1];
          if ((((&DAT_00036cf2)[iVar7] != 0) || ((*(byte *)(iVar3 + 0xd9) & 2) == 0)) ||
             ((((&DAT_00036472)[iVar7] & 8) != 0 ||
              ((char)(&DAT_00036c72)[iVar7] != *(char *)(iVar3 + 0xdb))))) {
            uVar5 = (&DAT_00036cf2)[iVar7] + 1;
            if (DAT_000343a4 <= uVar5) {
              uVar5 = 0;
              (&DAT_00036c72)[iVar7] = (&DAT_00036c72)[iVar7] + 1;
            }
            (&DAT_00036cf2)[iVar7] = uVar5;
          }
        }
        (&DAT_00036472)[iVar7] = (&DAT_00036472)[iVar7] | 0x80;
      }
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 != DAT_0003646e);
  iVar7 = 0;
  do {
    iVar3 = (&DAT_000368b2)[iVar7];
    if (((iVar3 != 0) && (((&DAT_00036472)[iVar7] & 2) != 0)) && (*(char *)(iVar3 + 0x48) != '\0'))
    {
      uVar2 = (&DAT_00036db2)[iVar7];
      sVar4 = FUN_000347c4();
      (&DAT_00036db2)[iVar7] = uVar2;
      if ((byte)(&DAT_00036df2)[iVar7] < *(byte *)(iVar3 + 0x47)) {
        sVar4 = (short)(((int)sVar4 * (int)(short)(ushort)(byte)(&DAT_00036df2)[iVar7]) /
                       (int)(short)(ushort)*(byte *)(iVar3 + 0x47));
        (&DAT_00036df2)[iVar7] = (&DAT_00036df2)[iVar7] + '\x01';
      }
      (&DAT_00036e32)[iVar7] = -(sVar4 >> 8);
      (&DAT_00036472)[iVar7] = (&DAT_00036472)[iVar7] | 0x20;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 != DAT_0003646e);
  return;
}

