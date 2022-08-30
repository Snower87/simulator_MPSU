//---------------------------------------------------------------------------


#pragma hdrstop

#include "UReadAnswer.h"
#include "UInterface.h"
#include "UCOMPortFunc.h"

#define BuffSize1 0x20  //��������� ��� ������� ����� ������
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

/*
   mlBData = IN_INF_KPA1[2]; //������� �������� ������ ���-200(���), ��. �., D_BSPS+0, {��� = 1��/���, �������� 0...4000 ��/���}
   stBData = IN_INF_KPA1[3]; //������� �������� ������ ���-200(���), ��. �., D_BSPS+1
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->ED_BSPS0->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[4]; //�������� �� ���� ���-200(���), ��. �., D_BSPS+2, {��� = 1���, �������� 0...500���}
   stBData = IN_INF_KPA1[5]; //�������� �� ���� ���-200(���), ��. �., D_BSPS+3
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->ED_BSPS2->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = IN_INF_KPA1[6]; //����������� �������� ���� ���� A(��������), D_BSPS+4, {��� = 2�, �������� 0...500�}
   ValueAnParam = (unsigned char)BData * 2.0;
   Form1->ED_BSPS4->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = IN_INF_KPA1[7]; //����������� �������� ���� ���� B(��������), D_BSPS+5, {��� = 2�, �������� 0...500�}
   ValueAnParam = (unsigned char)BData * 2.0;
   Form1->ED_BSPS5->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = IN_INF_KPA1[8]; //����������� �������� ���� ���� C(��������), D_BSPS+6, {��� = 2�, �������� 0...500�}
   ValueAnParam = (unsigned char)BData * 2.0;
   Form1->ED_BSPS6->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = IN_INF_KPA1[9]; //������� ���� ��������� (���), D_BSPS+7, {��� = 0,5��, �������� 0...60��}
   ValueAnParam = (unsigned char)BData * 0.5;
   Form1->ED_BSPS7->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);


   BData = IN_INF_KPA1[10]; //����������� ��-�� (�����������), D_BSPS+8

   if (BData & 0x80) {Form1->D_BSPS8->State[0] = cbChecked;} else {Form1->D_BSPS8->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->D_BSPS8->State[1] = cbChecked;} else {Form1->D_BSPS8->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->D_BSPS8->State[2] = cbChecked;} else {Form1->D_BSPS8->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->D_BSPS8->State[3] = cbChecked;} else {Form1->D_BSPS8->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->D_BSPS8->State[4] = cbChecked;} else {Form1->D_BSPS8->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->D_BSPS8->State[5] = cbChecked;} else {Form1->D_BSPS8->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->D_BSPS8->State[6] = cbChecked;} else {Form1->D_BSPS8->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->D_BSPS8->State[7] = cbChecked;} else {Form1->D_BSPS8->State[7] = cbUnchecked;}


   BData = IN_INF_KPA1[11]; //����������� ���-200 (�����������), D_BSPS+9

   if (BData & 0x80) {Form1->D_BSPS9->State[0] = cbChecked;} else {Form1->D_BSPS9->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->D_BSPS9->State[1] = cbChecked;} else {Form1->D_BSPS9->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->D_BSPS9->State[2] = cbChecked;} else {Form1->D_BSPS9->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->D_BSPS9->State[3] = cbChecked;} else {Form1->D_BSPS9->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->D_BSPS9->State[4] = cbChecked;} else {Form1->D_BSPS9->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->D_BSPS9->State[5] = cbChecked;} else {Form1->D_BSPS9->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->D_BSPS9->State[6] = cbChecked;} else {Form1->D_BSPS9->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->D_BSPS9->State[7] = cbChecked;} else {Form1->D_BSPS9->State[7] = cbUnchecked;}


   BData = IN_INF_KPA1[12]; //����������� ��-�� (��������), D_BSPS+10

   if (BData & 0x80) {Form1->D_BSPS10->State[0] = cbChecked;} else {Form1->D_BSPS10->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->D_BSPS10->State[1] = cbChecked;} else {Form1->D_BSPS10->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->D_BSPS10->State[2] = cbChecked;} else {Form1->D_BSPS10->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->D_BSPS10->State[3] = cbChecked;} else {Form1->D_BSPS10->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->D_BSPS10->State[4] = cbChecked;} else {Form1->D_BSPS10->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->D_BSPS10->State[5] = cbChecked;} else {Form1->D_BSPS10->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->D_BSPS10->State[6] = cbChecked;} else {Form1->D_BSPS10->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->D_BSPS10->State[7] = cbChecked;} else {Form1->D_BSPS10->State[7] = cbUnchecked;}


   BData = IN_INF_KPA1[13]; //����������� ��-�� (��������) (2), D_BSPS+11

   if (BData & 0x80) {Form1->D_BSPS11->State[0] = cbChecked;} else {Form1->D_BSPS11->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->D_BSPS11->State[1] = cbChecked;} else {Form1->D_BSPS11->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->D_BSPS11->State[2] = cbChecked;} else {Form1->D_BSPS11->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->D_BSPS11->State[3] = cbChecked;} else {Form1->D_BSPS11->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->D_BSPS11->State[4] = cbChecked;} else {Form1->D_BSPS11->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->D_BSPS11->State[5] = cbChecked;} else {Form1->D_BSPS11->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->D_BSPS11->State[6] = cbChecked;} else {Form1->D_BSPS11->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->D_BSPS11->State[7] = cbChecked;} else {Form1->D_BSPS11->State[7] = cbUnchecked;}


   BData = IN_INF_KPA1[14]; //����������� ����� � ���������� ��, D_BSPS+12

   if (BData & 0x80) {Form1->D_BSPS12->State[0] = cbChecked;} else {Form1->D_BSPS12->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->D_BSPS12->State[1] = cbChecked;} else {Form1->D_BSPS12->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->D_BSPS12->State[2] = cbChecked;} else {Form1->D_BSPS12->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->D_BSPS12->State[3] = cbChecked;} else {Form1->D_BSPS12->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->D_BSPS12->State[4] = cbChecked;} else {Form1->D_BSPS12->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->D_BSPS12->State[5] = cbChecked;} else {Form1->D_BSPS12->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->D_BSPS12->State[6] = cbChecked;} else {Form1->D_BSPS12->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->D_BSPS12->State[7] = cbChecked;} else {Form1->D_BSPS12->State[7] = cbUnchecked;}

   
   BData = IN_INF_KPA1[15]; //����������� �� ������, D_BSPS+13

   if (BData & 0x80) {Form1->D_BSPS13->State[0] = cbChecked;} else {Form1->D_BSPS13->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->D_BSPS13->State[1] = cbChecked;} else {Form1->D_BSPS13->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->D_BSPS13->State[2] = cbChecked;} else {Form1->D_BSPS13->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->D_BSPS13->State[3] = cbChecked;} else {Form1->D_BSPS13->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->D_BSPS13->State[4] = cbChecked;} else {Form1->D_BSPS13->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->D_BSPS13->State[5] = cbChecked;} else {Form1->D_BSPS13->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->D_BSPS13->State[6] = cbChecked;} else {Form1->D_BSPS13->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->D_BSPS13->State[7] = cbChecked;} else {Form1->D_BSPS13->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[16]; //����������� �� ������ (2), D_BSPS+14

   if (BData & 0x80) {Form1->D_BSPS14->State[0] = cbChecked;} else {Form1->D_BSPS14->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->D_BSPS14->State[1] = cbChecked;} else {Form1->D_BSPS14->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->D_BSPS14->State[2] = cbChecked;} else {Form1->D_BSPS14->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->D_BSPS14->State[3] = cbChecked;} else {Form1->D_BSPS14->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->D_BSPS14->State[4] = cbChecked;} else {Form1->D_BSPS14->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->D_BSPS14->State[5] = cbChecked;} else {Form1->D_BSPS14->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->D_BSPS14->State[6] = cbChecked;} else {Form1->D_BSPS14->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->D_BSPS14->State[7] = cbChecked;} else {Form1->D_BSPS14->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[17]; //����������� �� ������ (3), D_BSPS+15

   if (BData & 0x80) {Form1->D_BSPS15->State[0] = cbChecked;} else {Form1->D_BSPS15->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->D_BSPS15->State[1] = cbChecked;} else {Form1->D_BSPS15->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->D_BSPS15->State[2] = cbChecked;} else {Form1->D_BSPS15->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->D_BSPS15->State[3] = cbChecked;} else {Form1->D_BSPS15->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->D_BSPS15->State[4] = cbChecked;} else {Form1->D_BSPS15->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->D_BSPS15->State[5] = cbChecked;} else {Form1->D_BSPS15->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->D_BSPS15->State[6] = cbChecked;} else {Form1->D_BSPS15->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->D_BSPS15->State[7] = cbChecked;} else {Form1->D_BSPS15->State[7] = cbUnchecked;}
*/

   //�����, �������� ����!
   BData = 0;
   mlBData = 0;
   stBData = 0;
   
} //����� ������� READ_ANSWER()
