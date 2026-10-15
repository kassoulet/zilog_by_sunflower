
undefined4 FUN_0002d371(undefined4 param_1,char *param_2,int *unaff_EBX,code *param_4)

{
  char cVar1;
  undefined6 *puVar2;
  undefined4 *puVar3;
  undefined2 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined2 uVar7;
  undefined6 uVar8;
  undefined4 local_80;
  int local_7c;
  undefined4 local_70;
  char local_6b;
  char local_6a;
  undefined2 local_64;
  ushort local_62;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  undefined1 local_48 [40];
  int local_20;
  int local_1c;
  char *local_18;
  undefined1 local_14 [4];
  
  local_14[0] = 0;
  local_62 = 0;
  local_64 = 100;
  local_70 = 0;
  local_80 = param_1;
  local_18 = param_2;
LAB_0002d41d:
  do {
    while( true ) {
      while( true ) {
        cVar1 = *local_18;
        if (cVar1 == '\0') {
          return local_70;
        }
        if (cVar1 == '%') break;
        local_18 = local_18 + 1;
        (*param_4)(&local_80,cVar1);
      }
      local_20 = *unaff_EBX;
      local_18 = (char *)FUN_0002d632(local_18 + 1,&local_20);
      *unaff_EBX = local_20;
      local_6b = *local_18;
      local_18 = local_18 + 1;
      if (local_6b == '\0') {
        return local_70;
      }
      if (local_6b == 'n') break;
      local_1c = *unaff_EBX;
      uVar8 = FUN_0002da44(local_48,&local_1c,&local_80,local_14);
      uVar7 = (undefined2)((uint6)uVar8 >> 0x20);
      puVar6 = (undefined1 *)uVar8;
      *unaff_EBX = local_1c;
      local_7c = local_7c - (local_60 + local_5c + local_58 + local_54 + local_50 + local_4c);
      if (((local_62 & 8) == 0) && (local_6a == ' ')) {
        for (; 0 < local_7c; local_7c = local_7c + -1) {
          (*param_4)(&local_80,0x20);
        }
      }
      puVar5 = local_48;
      for (; 0 < local_60; local_60 = local_60 + -1) {
        (*param_4)(&local_80,*puVar5);
        puVar5 = puVar5 + 1;
      }
      while( true ) {
        if (local_5c < 1) break;
        (*param_4)(&local_80,0x30);
        local_5c = local_5c + -1;
      }
      if (local_6b == 's') {
        if ((local_62 & 0x20) == 0) {
          for (; 0 < local_58; local_58 = local_58 + -1) {
            (*param_4)(&local_80,*puVar6);
            puVar6 = puVar6 + 1;
          }
        }
        else {
LAB_0002d56d:
          FUN_0002d9ec(puVar6,uVar7,&local_80,param_4);
        }
      }
      else {
        if (local_6b == 'S') goto LAB_0002d56d;
        for (; 0 < local_58; local_58 = local_58 + -1) {
          (*param_4)(&local_80,*puVar6);
          puVar6 = puVar6 + 1;
        }
      }
      for (; 0 < local_54; local_54 = local_54 + -1) {
        (*param_4)(&local_80,0x30);
      }
      for (; 0 < local_50; local_50 = local_50 + -1) {
        (*param_4)(&local_80,*puVar6);
        puVar6 = puVar6 + 1;
      }
      for (; 0 < local_4c; local_4c = local_4c + -1) {
        (*param_4)(&local_80,0x30);
      }
      if ((local_62 & 8) != 0) {
        for (; 0 < local_7c; local_7c = local_7c + -1) {
          (*param_4)(&local_80,0x20);
        }
      }
    }
    if ((local_62 & 0x20) != 0) {
      if ((local_62 & 0x80) == 0) {
        if ((local_62 & 0x40) == 0) {
LAB_0002d40d:
          puVar3 = (undefined4 *)*unaff_EBX;
          *unaff_EBX = (int)(puVar3 + 1);
          puVar3 = (undefined4 *)*puVar3;
        }
        else {
          puVar3 = (undefined4 *)*unaff_EBX;
          *unaff_EBX = (int)(puVar3 + 1);
          puVar3 = (undefined4 *)*puVar3;
        }
LAB_0002d417:
        *puVar3 = local_70;
      }
      else {
        puVar2 = (undefined6 *)*unaff_EBX;
        *unaff_EBX = (int)(puVar2 + 1);
        puVar3 = (undefined4 *)*puVar2;
LAB_0002d3f3:
        *puVar3 = local_70;
      }
      goto LAB_0002d41d;
    }
    if ((local_62 & 0x10) == 0) {
      if ((local_62 & 0x80) == 0) {
        if ((local_62 & 0x40) != 0) goto LAB_0002d40d;
        puVar3 = (undefined4 *)*unaff_EBX;
        *unaff_EBX = (int)(puVar3 + 1);
        puVar3 = (undefined4 *)*puVar3;
        goto LAB_0002d417;
      }
      puVar2 = (undefined6 *)*unaff_EBX;
      *unaff_EBX = (int)(puVar2 + 1);
      puVar3 = (undefined4 *)*puVar2;
      goto LAB_0002d3f3;
    }
    if ((local_62 & 0x80) == 0) {
      if ((local_62 & 0x40) == 0) {
        puVar3 = (undefined4 *)*unaff_EBX;
        *unaff_EBX = (int)(puVar3 + 1);
        puVar4 = (undefined2 *)*puVar3;
      }
      else {
        puVar3 = (undefined4 *)*unaff_EBX;
        *unaff_EBX = (int)(puVar3 + 1);
        puVar4 = (undefined2 *)*puVar3;
      }
      *puVar4 = (short)local_70;
    }
    else {
      puVar2 = (undefined6 *)*unaff_EBX;
      *unaff_EBX = (int)(puVar2 + 1);
      *(undefined2 *)*puVar2 = (short)local_70;
    }
  } while( true );
}

