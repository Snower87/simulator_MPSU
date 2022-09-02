//---------------------------------------------------------------------------


#pragma hdrstop

#include "UReadAnswer.h"
#include "UInterface.h"
#include "UCOMPortFunc.h"

#define BuffSize1 100  //��������� ��� ������� ����� ������
extern unsigned char IN_INF_KPA1[BuffSize1];
extern unsigned char OUT_INF_KPA1[BuffSize1];

//---------------------------------------------------------------------------

#pragma package(smart_init)

//������� ������ � ����������� ����������� ������ �� �������� 01h
void READ_ANSWER ()
{
   unsigned char BData = 0x00; //������������� ����� ������

   unsigned char stBData = 0x00; //������������� ����� ������ (��.�.)
   unsigned char mlBData = 0x00; //������������� ����� ������ (��.�.)

   double ValueAnParam = 0;    //������������� ���������� �������� ����������� ���������
   AnsiString StrValueAnDouble = ""; //������ � ��������� ��������� ���������� ��������� ���� double

   //1. ������� ������� �� ���� (������� 01h, ��1)
   if (IN_INF_KPA1[1] == 0x01) {
   mlBData = IN_INF_KPA1[2]; //Fpllout, ����������� ���� ������� ����, ��.�. ��� = 0,1 ��, 0..100��
   stBData = IN_INF_KPA1[3]; //Fpllout, ����������� ���� ������� ����, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH1_BYTE3->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);


   mlBData = IN_INF_KPA1[4]; //Dout RMS, ��� ������������ ��������� ���, ��.�.	��� = 0,1%, 0..200%
   stBData = IN_INF_KPA1[5]; //Dout RMS, ��� ������������ ��������� ���, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH1_BYTE5->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = IN_INF_KPA1[6]; //Im_set, ������� ��������� ����, ��.�.	��� = 1�, 0..10000�
   stBData = IN_INF_KPA1[7]; //Im_set, ������� ��������� ����, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE7->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[8]; //Te, ����������� ���������    ��� = 0,5�� 0..127,5��
   ValueAnParam = ((unsigned char)mlBData)* 0.5;
   Form1->EPCH1_BYTE9->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = IN_INF_KPA1[9]; //Tecu, ����������� �����������    ��� = 0,5�� 0..127,5��
   ValueAnParam = ((unsigned char)mlBData)* 0.5;
   Form1->EPCH1_BYTE10->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = IN_INF_KPA1[12]; //Dchop, ������������ ��������� ��� ���������� �����, ��.�.   ��� = 0,1%,0..100%
   stBData = IN_INF_KPA1[13]; //Dchop, ������������ ��������� ��� ���������� �����, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH1_BYTE13->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = IN_INF_KPA1[16]; //Id (Ibr_m), ������� �� ������ ��� ��� ���������� ���������, ��.�.   ��� = 1�, 0..10000�
   stBData = IN_INF_KPA1[17]; //Id (Ibr_m), ������� �� ������ ��� ��� ���������� ���������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE17->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[22]; //Uac RMS, ��� ���������� �� ������� ���� ���������������, ��.�. ��� = 1�, 0..10000�
   stBData = IN_INF_KPA1[23]; //Uac RMS, ��� ���������� �� ������� ���� ���������������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE23->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[24]; //Ia (I2) RMS, ��� ���� ���������������, ��.�. ��� = 1�, 0..10000�
   stBData = IN_INF_KPA1[25]; //Ia (I2) RMS, ��� ���� ���������������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE25->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[28]; //Udc, ���������� �������������, ��.�. ��� = 1�, 0..10000�
   stBData = IN_INF_KPA1[29]; //Udc, ���������� �������������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE29->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = IN_INF_KPA1[30]; //RUNMODE, ������� ����� ������, ��.�.

   if (BData & 0x80) {Form1->CB_PCH1_BYTE31->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE31->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE31->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE31->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE31->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE31->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE31->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE31->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[31]; //RUNMODE, ������� ����� ������, ��.�.

   if (BData & 0x80) {Form1->CB_PCH1_BYTE32->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE32->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE32->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE32->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE32->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE32->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE32->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE32->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[32]; //STATUS, ���� ������, ��.�.

   if (BData & 0x80) {Form1->CB_PCH1_BYTE33->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE33->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE33->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE33->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE33->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE33->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE33->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE33->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[33]; //STATUS, ���� ������, ��.�.

   if (BData & 0x80) {Form1->CB_PCH1_BYTE34->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE34->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE34->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE34->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE34->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE34->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE34->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE34->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[7] = cbUnchecked;}

   mlBData = IN_INF_KPA1[38]; //Uac, ���������� �������� ���������� ��������� ������� (HV) ����� �������������� ��������������, ��.�.	��� = 1�,  0..10000�
   stBData = IN_INF_KPA1[39]; //Uac, ���������� �������� ���������� ��������� ������� (HV) ����� �������������� ��������������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE39->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[40]; //Ia, ���������� �������� ���� Ia, ��.�.	��� = 1�, 0..10000�
   stBData = IN_INF_KPA1[41]; //Ia, ���������� �������� ���� Ia, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE41->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[42]; //Ib, ���������� �������� ���� Ib, ��.�.	��� = 1�, 0..10000�
   stBData = IN_INF_KPA1[43]; //Ib, ���������� �������� ���� Ib, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE43->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = IN_INF_KPA1[46]; //MODESET, ����� ������, ��.�

   if (BData & 0x80) {Form1->CB_PCH1_BYTE47->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE47->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE47->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE47->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE47->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE47->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE47->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE47->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[47]; //MODESET, ����� ������, ��.�

   if (BData & 0x80) {Form1->CB_PCH1_BYTE48->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE48->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE48->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE48->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE48->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE48->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE48->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE48->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[7] = cbUnchecked;}

   mlBData = IN_INF_KPA1[48]; //Set1, ������� ���������� Udc, ��.�	��� = 1�, 0..10000 �
   stBData = IN_INF_KPA1[49]; //Set1, ������� ���������� Udc, ��.�
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE49->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[50]; //Set2, ������� ��������� ���� ��������� ������� (Im_set), ��.�.	��� = 1�, 0..10000 �
   stBData = IN_INF_KPA1[51]; //Set2, ������� ��������� ���� ��������� ������� (Im_set), ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE51->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[54]; //Im_min, ����������� ������ ���������� Udc �������, ��.�.  ��� = 1�, 0..10000 �
   stBData = IN_INF_KPA1[55]; //Im_min, ����������� ������ ���������� Udc �������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE55->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[56]; //Im_max, ����������� ������ ���������� Udc ��������, ��.�.	��� = 1�, 0..10000 �
   stBData = IN_INF_KPA1[57]; //Im_max, ����������� ������ ���������� Udc ��������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE57->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = IN_INF_KPA1[58]; //����������� ����� �� �1 (59 ����)

   if (BData & 0x80) {Form1->CB_RPD_BYTE59->State[0] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_RPD_BYTE59->State[1] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_RPD_BYTE59->State[2] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_RPD_BYTE59->State[3] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_RPD_BYTE59->State[4] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_RPD_BYTE59->State[5] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_RPD_BYTE59->State[6] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_RPD_BYTE59->State[7] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[59]; //����������� ����� �� �1 (60 ����)

   if (BData & 0x80) {Form1->CB_RPD_BYTE60->State[0] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_RPD_BYTE60->State[1] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_RPD_BYTE60->State[2] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_RPD_BYTE60->State[3] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_RPD_BYTE60->State[4] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_RPD_BYTE60->State[5] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_RPD_BYTE60->State[6] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_RPD_BYTE60->State[7] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[60]; //����������� ����� �� �1 (61 ����)

   if (BData & 0x80) {Form1->CB_RPD_BYTE61->State[0] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_RPD_BYTE61->State[1] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_RPD_BYTE61->State[2] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_RPD_BYTE61->State[3] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_RPD_BYTE61->State[4] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_RPD_BYTE61->State[5] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_RPD_BYTE61->State[6] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_RPD_BYTE61->State[7] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[61]; //����������� ����� �� �1 (62 ����)

   if (BData & 0x80) {Form1->CB_RPD_BYTE62->State[0] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_RPD_BYTE62->State[1] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_RPD_BYTE62->State[2] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_RPD_BYTE62->State[3] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_RPD_BYTE62->State[4] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_RPD_BYTE62->State[5] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_RPD_BYTE62->State[6] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_RPD_BYTE62->State[7] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[7] = cbUnchecked;}
   }

   //2. ������� ������� �� ���� (������� 02h, ��2)
   if (IN_INF_KPA1[1] == 0x02) {
   mlBData = IN_INF_KPA1[2]; //Fpllout, ����������� ���� ������� ����, ��.�. ��� = 0,1 ��, 0..100��
   stBData = IN_INF_KPA1[3]; //Fpllout, ����������� ���� ������� ����, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH2_BYTE3->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = IN_INF_KPA1[4]; //Dout RMS, ��� ������������ ��������� ���, ��.�.	��� = 0,1%, 0..200%
   stBData = IN_INF_KPA1[5]; //Dout RMS, ��� ������������ ��������� ���, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH2_BYTE5->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = IN_INF_KPA1[6]; //Im_set, ������� ��������� ����, ��.�.	��� = 1�, 0..10000�
   stBData = IN_INF_KPA1[7]; //Im_set, ������� ��������� ����, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE7->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[8]; //Te, ����������� ���������    ��� = 0,5�� 0..127,5��
   ValueAnParam = ((unsigned char)mlBData)* 0.5;
   Form1->EPCH2_BYTE9->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = IN_INF_KPA1[9]; //Tecu, ����������� �����������    ��� = 0,5�� 0..127,5��
   ValueAnParam = ((unsigned char)mlBData)* 0.5;
   Form1->EPCH2_BYTE10->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = IN_INF_KPA1[12]; //Dchop, ������������ ��������� ��� ���������� �����, ��.�.   ��� = 0,1%,0..100%
   stBData = IN_INF_KPA1[13]; //Dchop, ������������ ��������� ��� ���������� �����, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH2_BYTE13->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = IN_INF_KPA1[16]; //Id (Ibr_m), ������� �� ������ ��� ��� ���������� ���������, ��.�.   ��� = 1�, 0..10000�
   stBData = IN_INF_KPA1[17]; //Id (Ibr_m), ������� �� ������ ��� ��� ���������� ���������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE17->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[22]; //Uac RMS, ��� ���������� �� ������� ���� ���������������, ��.�. ��� = 1�, 0..10000�
   stBData = IN_INF_KPA1[23]; //Uac RMS, ��� ���������� �� ������� ���� ���������������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE23->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[24]; //Ia (I2) RMS, ��� ���� ���������������, ��.�. ��� = 1�, 0..10000�
   stBData = IN_INF_KPA1[25]; //Ia (I2) RMS, ��� ���� ���������������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE25->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[28]; //Udc, ���������� �������������, ��.�. ��� = 1�, 0..10000�
   stBData = IN_INF_KPA1[29]; //Udc, ���������� �������������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE29->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = IN_INF_KPA1[30]; //RUNMODE, ������� ����� ������, ��.�.

   if (BData & 0x80) {Form1->CB_PCH2_BYTE31->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE31->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE31->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE31->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE31->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE31->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE31->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE31->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[31]; //RUNMODE, ������� ����� ������, ��.�.

   if (BData & 0x80) {Form1->CB_PCH2_BYTE32->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE32->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE32->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE32->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE32->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE32->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE32->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE32->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[32]; //STATUS, ���� ������, ��.�.

   if (BData & 0x80) {Form1->CB_PCH2_BYTE33->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE33->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE33->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE33->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE33->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE33->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE33->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE33->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[33]; //STATUS, ���� ������, ��.�.

   if (BData & 0x80) {Form1->CB_PCH2_BYTE34->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE34->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE34->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE34->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE34->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE34->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE34->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE34->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[7] = cbUnchecked;}

   mlBData = IN_INF_KPA1[38]; //Uac, ���������� �������� ���������� ��������� ������� (HV) ����� �������������� ��������������, ��.�.	��� = 1�,  0..10000�
   stBData = IN_INF_KPA1[39]; //Uac, ���������� �������� ���������� ��������� ������� (HV) ����� �������������� ��������������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE39->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[40]; //Ia, ���������� �������� ���� Ia, ��.�.	��� = 1�, 0..10000�
   stBData = IN_INF_KPA1[41]; //Ia, ���������� �������� ���� Ia, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE41->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[42]; //Ib, ���������� �������� ���� Ib, ��.�.	��� = 1�, 0..10000�
   stBData = IN_INF_KPA1[43]; //Ib, ���������� �������� ���� Ib, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE43->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = IN_INF_KPA1[44]; //NPRM, ��.�

   if (BData & 0x80) {Form1->CB_PCH2_BYTE45->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE45->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE45->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE45->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE45->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE45->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE45->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE45->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[45]; //NPRM, ��.�

   if (BData & 0x80) {Form1->CB_PCH2_BYTE46->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE46->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE46->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE46->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE46->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE46->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE46->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE46->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[46]; //MODESET, ����� ������, ��.�

   if (BData & 0x80) {Form1->CB_PCH2_BYTE47->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE47->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE47->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE47->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE47->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE47->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE47->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE47->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[47]; //MODESET, ����� ������, ��.�

   if (BData & 0x80) {Form1->CB_PCH2_BYTE48->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE48->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE48->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE48->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE48->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE48->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE48->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE48->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[7] = cbUnchecked;}

   mlBData = IN_INF_KPA1[48]; //Set1, ������� ���������� Udc, ��.�	��� = 1�, 0..10000 �
   stBData = IN_INF_KPA1[49]; //Set1, ������� ���������� Udc, ��.�
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE49->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[50]; //Set2, ������� ��������� ���� ��������� ������� (Im_set), ��.�.	��� = 1�, 0..10000 �
   stBData = IN_INF_KPA1[51]; //Set2, ������� ��������� ���� ��������� ������� (Im_set), ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE51->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[54]; //Im_min, ����������� ������ ���������� Udc �������, ��.�.  ��� = 1�, 0..10000 �
   stBData = IN_INF_KPA1[55]; //Im_min, ����������� ������ ���������� Udc �������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE55->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[56]; //Im_max, ����������� ������ ���������� Udc ��������, ��.�.	��� = 1�, 0..10000 �
   stBData = IN_INF_KPA1[57]; //Im_max, ����������� ������ ���������� Udc ��������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE57->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = IN_INF_KPA1[58]; //��������� ������ 1-8 ���1�1

   if (BData & 0x80) {Form1->CB_PCH2_BYTE59->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE59->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE59->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE59->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE59->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE59->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE59->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE59->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[59]; //��������� ������ 9-16 ���1�1

   if (BData & 0x80) {Form1->CB_PCH2_BYTE60->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE60->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE60->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE60->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE60->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE60->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE60->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE60->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[60]; //��������� ������ 1-8 ���1�2

   if (BData & 0x80) {Form1->CB_PCH2_BYTE61->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE61->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE61->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE61->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE61->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE61->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE61->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE61->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[61]; //��������� ������ 9-16 ���1�2

   if (BData & 0x80) {Form1->CB_PCH2_BYTE62->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE62->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE62->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE62->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE62->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE62->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE62->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE62->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[62]; //������� ���1

   if (BData & 0x80) {Form1->CB_PCH2_BYTE63->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE63->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE63->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE63->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE63->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE63->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE63->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE63->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[63]; //������� ���2

   if (BData & 0x80) {Form1->CB_PCH2_BYTE64->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE64->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE64->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE64->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE64->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE64->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE64->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE64->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[7] = cbUnchecked;}

   mlBData = IN_INF_KPA1[64]; //��� ������������� 1 (���1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY1->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[65]; //��� ������������� 2 (���1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY2->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[66]; //��� ������������� 3 (���1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY3->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[67]; //��� ������������� 4 (���1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY4->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[68]; //��� ������������� 5 (���1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY5->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[69]; //��� ������������� 6 (���1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY6->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[70]; //��� ������������� 7 (���1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY7->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[71]; //��� ������������� 8 (���1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY8->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);


   mlBData = IN_INF_KPA1[72]; //��� ������������� 1 (���2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY1->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[73]; //��� ������������� 2 (���2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY2->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[74]; //��� ������������� 3 (���2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY3->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[75]; //��� ������������� 4 (���2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY4->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[76]; //��� ������������� 5 (���2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY5->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[77]; //��� ������������� 6 (���2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY6->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[78]; //��� ������������� 7 (���2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY7->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[79]; //��� ������������� 8 (���2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY8->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);
   }

   //�����, �������� ����!
   BData = 0;
   mlBData = 0;
   stBData = 0;
   
} //����� ������� READ_ANSWER()
