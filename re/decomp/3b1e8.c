
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0003b1e8(undefined4 param_1,undefined4 param_2,undefined4 unaff_EBX,int param_4)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined3 uVar5;
  int unaff_EBP;
  undefined1 *unaff_ESI;
  undefined1 *puVar6;
  int *unaff_EDI;
  
  uVar5 = (undefined3)((uint)unaff_EBX >> 8);
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*unaff_ESI) * 2);
  *unaff_EDI = *unaff_EDI +
               iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,unaff_ESI[1]) * 2) - iVar4) * param_4;
  uVar3 = (undefined2)((uint)param_4 >> 0x10);
  uVar1 = (ushort)param_4 + _DAT_0003989a;
  puVar6 = unaff_ESI + (uint)CARRY2((ushort)param_4,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[1] = unaff_EDI[1] +
                 iVar4 * 0x10000 +
                 (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1);
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[2] = unaff_EDI[2] +
                 iVar4 * 0x10000 +
                 (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2);
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[3] = unaff_EDI[3] +
                 iVar4 * 0x10000 +
                 (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1);
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[4] = unaff_EDI[4] +
                 iVar4 * 0x10000 +
                 (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2);
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[5] = unaff_EDI[5] +
                 iVar4 * 0x10000 +
                 (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1);
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[6] = unaff_EDI[6] +
                 iVar4 * 0x10000 +
                 (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2);
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[7] = unaff_EDI[7] +
                 iVar4 * 0x10000 +
                 (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1);
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[8] = unaff_EDI[8] +
                 iVar4 * 0x10000 +
                 (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2);
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[9] = unaff_EDI[9] +
                 iVar4 * 0x10000 +
                 (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1);
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[10] =
       unaff_EDI[10] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0xb] =
       unaff_EDI[0xb] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0xc] =
       unaff_EDI[0xc] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0xd] =
       unaff_EDI[0xd] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0xe] =
       unaff_EDI[0xe] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0xf] =
       unaff_EDI[0xf] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x10] =
       unaff_EDI[0x10] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x11] =
       unaff_EDI[0x11] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x12] =
       unaff_EDI[0x12] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x13] =
       unaff_EDI[0x13] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x14] =
       unaff_EDI[0x14] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x15] =
       unaff_EDI[0x15] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x16] =
       unaff_EDI[0x16] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x17] =
       unaff_EDI[0x17] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x18] =
       unaff_EDI[0x18] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x19] =
       unaff_EDI[0x19] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x1a] =
       unaff_EDI[0x1a] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x1b] =
       unaff_EDI[0x1b] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x1c] =
       unaff_EDI[0x1c] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x1d] =
       unaff_EDI[0x1d] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x1e] =
       unaff_EDI[0x1e] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x1f] =
       unaff_EDI[0x1f] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x20] =
       unaff_EDI[0x20] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x21] =
       unaff_EDI[0x21] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x22] =
       unaff_EDI[0x22] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x23] =
       unaff_EDI[0x23] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x24] =
       unaff_EDI[0x24] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x25] =
       unaff_EDI[0x25] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x26] =
       unaff_EDI[0x26] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x27] =
       unaff_EDI[0x27] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x28] =
       unaff_EDI[0x28] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x29] =
       unaff_EDI[0x29] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x2a] =
       unaff_EDI[0x2a] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x2b] =
       unaff_EDI[0x2b] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x2c] =
       unaff_EDI[0x2c] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x2d] =
       unaff_EDI[0x2d] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x2e] =
       unaff_EDI[0x2e] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x2f] =
       unaff_EDI[0x2f] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x30] =
       unaff_EDI[0x30] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x31] =
       unaff_EDI[0x31] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x32] =
       unaff_EDI[0x32] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x33] =
       unaff_EDI[0x33] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x34] =
       unaff_EDI[0x34] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x35] =
       unaff_EDI[0x35] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x36] =
       unaff_EDI[0x36] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x37] =
       unaff_EDI[0x37] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x38] =
       unaff_EDI[0x38] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x39] =
       unaff_EDI[0x39] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x3a] =
       unaff_EDI[0x3a] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x3b] =
       unaff_EDI[0x3b] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x3c] =
       unaff_EDI[0x3c] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  uVar1 = uVar2 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x3d] =
       unaff_EDI[0x3d] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar1)
  ;
  uVar2 = uVar1 + _DAT_0003989a;
  puVar6 = puVar6 + (uint)CARRY2(uVar1,_DAT_0003989a) + unaff_EBP;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,*puVar6) * 2);
  unaff_EDI[0x3e] =
       unaff_EDI[0x3e] +
       iVar4 * 0x10000 + (*(short *)(CONCAT31(uVar5,puVar6[1]) * 2) - iVar4) * CONCAT22(uVar3,uVar2)
  ;
  iVar4 = (int)*(short *)(CONCAT31(uVar5,puVar6[(uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP]) * 2)
  ;
  unaff_EDI[0x3f] =
       unaff_EDI[0x3f] +
       iVar4 * 0x10000 +
       (*(short *)(CONCAT31(uVar5,(puVar6 + (uint)CARRY2(uVar2,_DAT_0003989a) + unaff_EBP)[1]) * 2)
       - iVar4) * CONCAT22(uVar3,uVar2 + _DAT_0003989a);
  return;
}

