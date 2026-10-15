
void FUN_000326e9(void)

{
  byte bVar1;
  byte *pbVar2;
  ushort uVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = 0;
  do {
    pbVar2 = DAT_00031510;
    if (DAT_00031510 == (byte *)0x0) {
LAB_00032840:
      do {
        (&DAT_000315b0)[iVar6] = 0xff;
        (&DAT_000315f0)[iVar6] = 0xff;
        iVar6 = iVar6 + 1;
      } while (iVar6 != DAT_000314fc);
      return;
    }
    bVar1 = *DAT_00031510;
    if (bVar1 == 0xfc) {
      DAT_00031510 = DAT_00031510 + 1;
      goto LAB_00032840;
    }
    DAT_00031510 = DAT_00031510 + 5;
    DAT_00031523 = (ushort)bVar1;
    (&DAT_00031770)[iVar6] = bVar1;
    DAT_00031521 = (ushort)pbVar2[1];
    (&DAT_00031730)[iVar6] = pbVar2[1];
    uVar3 = (ushort)pbVar2[2];
    DAT_0003152d = (ushort)pbVar2[4];
    DAT_0003152b = (ushort)pbVar2[3];
    if ((pbVar2[3] == 0) && (DAT_0003152d == 0)) {
      DAT_0003152b = 0xff;
    }
    DAT_00031527 = 0xff;
    DAT_00031525 = uVar3;
    if (0x50 < uVar3) {
      DAT_00031525 = 0;
      DAT_00031527 = (ushort)(uVar3 - 0x60) >> 4;
      DAT_00031529 = uVar3 - 0x60 & 0xf;
    }
    (&DAT_000317b0)[iVar6] = (char)DAT_00031525;
    if ((&DAT_000315b0)[iVar6] != (char)DAT_0003152b) {
      sVar4 = FUN_000342c2();
      if (sVar4 != (&DAT_00031670)[iVar6]) {
        FUN_000342cb((&DAT_00031670)[iVar6]);
      }
    }
    if (DAT_0003152b != 0x31) {
      FUN_00032858();
    }
    uVar3 = DAT_00031529;
    uVar5 = (uint)DAT_00031527;
    (&DAT_000315f0)[iVar6] = (char)DAT_00031527;
    if (uVar5 < 10) {
      (**(code **)(&DAT_00033707 + uVar5 * 4))(uVar3);
    }
    uVar5 = (uint)DAT_0003152b;
    if ((DAT_0003152d == 0) && (uVar5 == 0)) {
      uVar5 = 0xff;
    }
    if (uVar5 < 0x44) {
      (**(code **)(&DAT_000334e7 + uVar5 * 4))();
    }
    (&DAT_000315b0)[iVar6] = (char)uVar5;
    iVar6 = iVar6 + 1;
    if (iVar6 == DAT_000314fc) {
      return;
    }
  } while( true );
}

