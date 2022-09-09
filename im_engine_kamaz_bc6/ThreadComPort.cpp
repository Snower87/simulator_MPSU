//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ThreadComPort.h"
#include "UInterface.h"
#include "UCOMPortFunc.h"
#include "UReadAnswer.h"

//unsigned char NCycle = 1;

extern DWORD dwZPR_KPSN_01h;
extern DWORD dwZPR_KPSN_02h;

extern DWORD dwOTV_KPSN_01h;
extern DWORD dwOTV_KPSN_02h;

extern HANDLE hCom;
extern unsigned short int GCRC;
extern unsigned char StartError;
#define BuffSize1 100  //��������� ��� ������� ����� ������

extern unsigned char IN_INF_KPA1[BuffSize1];
extern unsigned char OUT_INF_KPA1[BuffSize1];

extern DWORD dwIN1;
extern DWORD dwOUT1;

extern void COMERROR(unsigned char ERR);
extern void OPENCOM();
extern void CLOSECOM();
extern void SETTINGCOM();
extern void WRITECOM(UCHAR *BFCOMTX, UCHAR TXLEN);
extern void READCOM(UCHAR *BFCOMRX, UCHAR RXLEN);
extern void CLEARBUFCOM();

extern AnsiString StringToHex(unsigned char* Stroka, int StrLength);
extern unsigned char TRCH[256];
extern unsigned char TRCL[256];
extern unsigned int SCalcCRC(unsigned char *BFCRC, unsigned char Index);

extern void READ_ANSWER ();

#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall ThreadComPort::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall ThreadComPort::ThreadComPort(bool CreateSuspended)
        : TThread(CreateSuspended)
{
//������� ���������� ������ � ��� ������������ 
Priority = tpTimeCritical; // tpHighest - ��������� ������ - �� ��� ������ ���� �����������
                           // tpTimeCritical - ����� �������� ����� ������� ���������
}
//---------------------------------------------------------------------------
void FUNC_VIEW_ANS_KPSN01h() {
   unsigned char BData = 0x00; //������������� ����� ������

   unsigned char stBData = 0x00; //������������� ����� ������ (��.�.)
   unsigned char mlBData = 0x00; //������������� ����� ������ (��.�.)

   double ValueAnParam = 0;    //������������� ���������� �������� ����������� ���������
   AnsiString StrValueAnDouble = ""; //������ � ��������� ��������� ���������� ��������� ���� double

   //1. ������� ������� �� ���� (������� 01h, ��1)
   if ((BUFF_OTV_KPSN_01h[1] == 0x01)) {// && (PR_CORRECT_CRC == true)) {
   mlBData = BUFF_OTV_KPSN_01h[2]; //Fpllout, ����������� ���� ������� ����, ��.�. ��� = 0,1 ��, 0..100��
   stBData = BUFF_OTV_KPSN_01h[3]; //Fpllout, ����������� ���� ������� ����, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH1_BYTE3->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);


   mlBData = BUFF_OTV_KPSN_01h[4]; //Dout RMS, ��� ������������ ��������� ���, ��.�.	��� = 0,1%, 0..200%
   stBData = BUFF_OTV_KPSN_01h[5]; //Dout RMS, ��� ������������ ��������� ���, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH1_BYTE5->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[6]; //Im_set, ������� ��������� ����, ��.�.	��� = 1�, 0..10000�
   stBData = BUFF_OTV_KPSN_01h[7]; //Im_set, ������� ��������� ����, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE7->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[8]; //Te, ����������� ���������    ��� = 0,5�� 0..127,5��
   ValueAnParam = ((unsigned char)mlBData)* 0.5;
   Form1->EPCH1_BYTE9->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[9]; //Tecu, ����������� �����������    ��� = 0,5�� 0..127,5��
   ValueAnParam = ((unsigned char)mlBData)* 0.5;
   Form1->EPCH1_BYTE10->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[12]; //Dchop, ������������ ��������� ��� ���������� �����, ��.�.   ��� = 0,1%,0..100%
   stBData = BUFF_OTV_KPSN_01h[13]; //Dchop, ������������ ��������� ��� ���������� �����, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH1_BYTE13->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[16]; //Id (Ibr_m), ������� �� ������ ��� ��� ���������� ���������, ��.�.   ��� = 1�, 0..10000�
   stBData = BUFF_OTV_KPSN_01h[17]; //Id (Ibr_m), ������� �� ������ ��� ��� ���������� ���������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE17->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[22]; //Uac RMS, ��� ���������� �� ������� ���� ���������������, ��.�. ��� = 1�, 0..10000�
   stBData = BUFF_OTV_KPSN_01h[23]; //Uac RMS, ��� ���������� �� ������� ���� ���������������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE23->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[24]; //Ia (I2) RMS, ��� ���� ���������������, ��.�. ��� = 1�, 0..10000�
   stBData = BUFF_OTV_KPSN_01h[25]; //Ia (I2) RMS, ��� ���� ���������������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE25->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[28]; //Udc, ���������� �������������, ��.�. ��� = 1�, 0..10000�
   stBData = BUFF_OTV_KPSN_01h[29]; //Udc, ���������� �������������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE29->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = BUFF_OTV_KPSN_01h[30]; //RUNMODE, ������� ����� ������, ��.�.

   if (BData & 0x80) {Form1->CB_PCH1_BYTE31->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE31->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE31->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE31->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE31->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE31->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE31->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE31->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_01h[31]; //RUNMODE, ������� ����� ������, ��.�.

   if (BData & 0x80) {Form1->CB_PCH1_BYTE32->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE32->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE32->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE32->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE32->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE32->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE32->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE32->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_01h[32]; //STATUS, ���� ������, ��.�.

   if (BData & 0x80) {Form1->CB_PCH1_BYTE33->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE33->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE33->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE33->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE33->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE33->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE33->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE33->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_01h[33]; //STATUS, ���� ������, ��.�.

   if (BData & 0x80) {Form1->CB_PCH1_BYTE34->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE34->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE34->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE34->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE34->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE34->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE34->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE34->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[7] = cbUnchecked;}

   mlBData = BUFF_OTV_KPSN_01h[38]; //Uac, ���������� �������� ���������� ��������� ������� (HV) ����� �������������� ��������������, ��.�.	��� = 1�,  0..10000�
   stBData = BUFF_OTV_KPSN_01h[39]; //Uac, ���������� �������� ���������� ��������� ������� (HV) ����� �������������� ��������������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE39->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[40]; //Ia, ���������� �������� ���� Ia, ��.�.	��� = 1�, 0..10000�
   stBData = BUFF_OTV_KPSN_01h[41]; //Ia, ���������� �������� ���� Ia, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE41->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[42]; //Ib, ���������� �������� ���� Ib, ��.�.	��� = 1�, 0..10000�
   stBData = BUFF_OTV_KPSN_01h[43]; //Ib, ���������� �������� ���� Ib, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE43->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = BUFF_OTV_KPSN_01h[46]; //MODESET, ����� ������, ��.�

   if (BData & 0x80) {Form1->CB_PCH1_BYTE47->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE47->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE47->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE47->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE47->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE47->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE47->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE47->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_01h[47]; //MODESET, ����� ������, ��.�

   if (BData & 0x80) {Form1->CB_PCH1_BYTE48->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE48->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE48->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE48->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE48->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE48->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE48->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE48->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[7] = cbUnchecked;}

   mlBData = BUFF_OTV_KPSN_01h[48]; //Set1, ������� ���������� Udc, ��.�	��� = 1�, 0..10000 �
   stBData = BUFF_OTV_KPSN_01h[49]; //Set1, ������� ���������� Udc, ��.�
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE49->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[50]; //Set2, ������� ��������� ���� ��������� ������� (Im_set), ��.�.	��� = 1�, 0..10000 �
   stBData = BUFF_OTV_KPSN_01h[51]; //Set2, ������� ��������� ���� ��������� ������� (Im_set), ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE51->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[54]; //Im_min, ����������� ������ ���������� Udc �������, ��.�.  ��� = 1�, 0..10000 �
   stBData = BUFF_OTV_KPSN_01h[55]; //Im_min, ����������� ������ ���������� Udc �������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE55->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[56]; //Im_max, ����������� ������ ���������� Udc ��������, ��.�.	��� = 1�, 0..10000 �
   stBData = BUFF_OTV_KPSN_01h[57]; //Im_max, ����������� ������ ���������� Udc ��������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE57->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = BUFF_OTV_KPSN_01h[58]; //����������� ����� �� �1 (59 ����)

   if (BData & 0x80) {Form1->CB_RPD_BYTE59->State[0] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_RPD_BYTE59->State[1] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_RPD_BYTE59->State[2] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_RPD_BYTE59->State[3] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_RPD_BYTE59->State[4] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_RPD_BYTE59->State[5] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_RPD_BYTE59->State[6] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_RPD_BYTE59->State[7] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_01h[59]; //����������� ����� �� �1 (60 ����)

   if (BData & 0x80) {Form1->CB_RPD_BYTE60->State[0] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_RPD_BYTE60->State[1] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_RPD_BYTE60->State[2] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_RPD_BYTE60->State[3] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_RPD_BYTE60->State[4] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_RPD_BYTE60->State[5] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_RPD_BYTE60->State[6] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_RPD_BYTE60->State[7] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_01h[60]; //����������� ����� �� �1 (61 ����)

   if (BData & 0x80) {Form1->CB_RPD_BYTE61->State[0] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_RPD_BYTE61->State[1] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_RPD_BYTE61->State[2] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_RPD_BYTE61->State[3] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_RPD_BYTE61->State[4] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_RPD_BYTE61->State[5] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_RPD_BYTE61->State[6] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_RPD_BYTE61->State[7] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_01h[61]; //����������� ����� �� �1 (62 ����)

   if (BData & 0x80) {Form1->CB_RPD_BYTE62->State[0] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_RPD_BYTE62->State[1] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_RPD_BYTE62->State[2] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_RPD_BYTE62->State[3] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_RPD_BYTE62->State[4] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_RPD_BYTE62->State[5] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_RPD_BYTE62->State[6] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_RPD_BYTE62->State[7] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[7] = cbUnchecked;}

   mlBData = BUFF_OTV_KPSN_01h[62]; //������ ����
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VPCH1_BYTE63->Caption = StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[63]; //������� ������ ����, ��.�.  ��� = 1, 0.. 65535
   stBData = BUFF_OTV_KPSN_01h[64]; //������� ������ ����, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->VPCH1_BYTE64->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = BUFF_OTV_KPSN_01h[65]; //����������� ����� � �� (66 ����)

   if (BData & 0x80) {Form1->CB_PCH1_BYTE66->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE66->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE66->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE66->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE66->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE66->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE66->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE66->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE66->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE66->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE66->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE66->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE66->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE66->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE66->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE66->State[7] = cbUnchecked;}

   mlBData = BUFF_OTV_KPSN_01h[66]; //��������� ����
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VPCH1_BYTE67->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = BUFF_OTV_KPSN_01h[67]; //�������� ������� (68 ����)

   if (BData & 0x80) {Form1->CB_PCH1_BYTE68->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE68->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE68->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE68->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE68->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE68->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE68->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE68->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE68->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE68->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE68->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE68->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE68->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE68->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE68->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE68->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_01h[68]; //�������� ������������ (69 ����)

   if (BData & 0x80) {Form1->CB_PCH1_BYTE69->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE69->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE69->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE69->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE69->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE69->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE69->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE69->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE69->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE69->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE69->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE69->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE69->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE69->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE69->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE69->State[7] = cbUnchecked;}
   }
}

void FUNC_VIEW_ANS_KPSN02h() {
   unsigned char BData = 0x00; //������������� ����� ������

   unsigned char stBData = 0x00; //������������� ����� ������ (��.�.)
   unsigned char mlBData = 0x00; //������������� ����� ������ (��.�.)

   double ValueAnParam = 0;    //������������� ���������� �������� ����������� ���������
   AnsiString StrValueAnDouble = ""; //������ � ��������� ��������� ���������� ��������� ���� double

   //2. ������� ������� �� ���� (������� 02h, ��2)
   if ((BUFF_OTV_KPSN_02h[1] == 0x02)) {// && (PR_CORRECT_CRC == true)) {
   mlBData = BUFF_OTV_KPSN_02h[2]; //Fpllout, ����������� ���� ������� ����, ��.�. ��� = 0,1 ��, 0..100��
   stBData = BUFF_OTV_KPSN_02h[3]; //Fpllout, ����������� ���� ������� ����, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH2_BYTE3->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[4]; //Dout RMS, ��� ������������ ��������� ���, ��.�.	��� = 0,1%, 0..200%
   stBData = BUFF_OTV_KPSN_02h[5]; //Dout RMS, ��� ������������ ��������� ���, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH2_BYTE5->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[6]; //Im_set, ������� ��������� ����, ��.�.	��� = 1�, 0..10000�
   stBData = BUFF_OTV_KPSN_02h[7]; //Im_set, ������� ��������� ����, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE7->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[8]; //Te, ����������� ���������    ��� = 0,5�� 0..127,5��
   ValueAnParam = ((unsigned char)mlBData)* 0.5;
   Form1->EPCH2_BYTE9->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[9]; //Tecu, ����������� �����������    ��� = 0,5�� 0..127,5��
   ValueAnParam = ((unsigned char)mlBData)* 0.5;
   Form1->EPCH2_BYTE10->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[12]; //Dchop, ������������ ��������� ��� ���������� �����, ��.�.   ��� = 0,1%,0..100%
   stBData = BUFF_OTV_KPSN_02h[13]; //Dchop, ������������ ��������� ��� ���������� �����, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH2_BYTE13->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[16]; //Id (Ibr_m), ������� �� ������ ��� ��� ���������� ���������, ��.�.   ��� = 1�, 0..10000�
   stBData = BUFF_OTV_KPSN_02h[17]; //Id (Ibr_m), ������� �� ������ ��� ��� ���������� ���������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE17->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[22]; //Uac RMS, ��� ���������� �� ������� ���� ���������������, ��.�. ��� = 1�, 0..10000�
   stBData = BUFF_OTV_KPSN_02h[23]; //Uac RMS, ��� ���������� �� ������� ���� ���������������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE23->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[24]; //Ia (I2) RMS, ��� ���� ���������������, ��.�. ��� = 1�, 0..10000�
   stBData = BUFF_OTV_KPSN_02h[25]; //Ia (I2) RMS, ��� ���� ���������������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE25->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[28]; //Udc, ���������� �������������, ��.�. ��� = 1�, 0..10000�
   stBData = BUFF_OTV_KPSN_02h[29]; //Udc, ���������� �������������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE29->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = BUFF_OTV_KPSN_02h[30]; //RUNMODE, ������� ����� ������, ��.�.

   if (BData & 0x80) {Form1->CB_PCH2_BYTE31->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE31->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE31->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE31->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE31->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE31->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE31->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE31->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_02h[31]; //RUNMODE, ������� ����� ������, ��.�.

   if (BData & 0x80) {Form1->CB_PCH2_BYTE32->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE32->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE32->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE32->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE32->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE32->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE32->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE32->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_02h[32]; //STATUS, ���� ������, ��.�.

   if (BData & 0x80) {Form1->CB_PCH2_BYTE33->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE33->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE33->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE33->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE33->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE33->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE33->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE33->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_02h[33]; //STATUS, ���� ������, ��.�.

   if (BData & 0x80) {Form1->CB_PCH2_BYTE34->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE34->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE34->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE34->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE34->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE34->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE34->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE34->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[7] = cbUnchecked;}

   mlBData = BUFF_OTV_KPSN_02h[38]; //Uac, ���������� �������� ���������� ��������� ������� (HV) ����� �������������� ��������������, ��.�.	��� = 1�,  0..10000�
   stBData = BUFF_OTV_KPSN_02h[39]; //Uac, ���������� �������� ���������� ��������� ������� (HV) ����� �������������� ��������������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE39->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[40]; //Ia, ���������� �������� ���� Ia, ��.�.	��� = 1�, 0..10000�
   stBData = BUFF_OTV_KPSN_02h[41]; //Ia, ���������� �������� ���� Ia, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE41->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[42]; //Ib, ���������� �������� ���� Ib, ��.�.	��� = 1�, 0..10000�
   stBData = BUFF_OTV_KPSN_02h[43]; //Ib, ���������� �������� ���� Ib, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE43->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = BUFF_OTV_KPSN_02h[44]; //NPRM, ��.�

   if (BData & 0x80) {Form1->CB_PCH2_BYTE45->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE45->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE45->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE45->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE45->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE45->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE45->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE45->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_02h[45]; //NPRM, ��.�

   if (BData & 0x80) {Form1->CB_PCH2_BYTE46->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE46->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE46->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE46->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE46->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE46->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE46->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE46->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_02h[46]; //MODESET, ����� ������, ��.�

   if (BData & 0x80) {Form1->CB_PCH2_BYTE47->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE47->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE47->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE47->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE47->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE47->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE47->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE47->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_02h[47]; //MODESET, ����� ������, ��.�

   if (BData & 0x80) {Form1->CB_PCH2_BYTE48->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE48->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE48->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE48->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE48->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE48->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE48->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE48->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[7] = cbUnchecked;}

   mlBData = BUFF_OTV_KPSN_02h[48]; //Set1, ������� ���������� Udc, ��.�	��� = 1�, 0..10000 �
   stBData = BUFF_OTV_KPSN_02h[49]; //Set1, ������� ���������� Udc, ��.�
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE49->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[50]; //Set2, ������� ��������� ���� ��������� ������� (Im_set), ��.�.	��� = 1�, 0..10000 �
   stBData = BUFF_OTV_KPSN_02h[51]; //Set2, ������� ��������� ���� ��������� ������� (Im_set), ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE51->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[54]; //Im_min, ����������� ������ ���������� Udc �������, ��.�.  ��� = 1�, 0..10000 �
   stBData = BUFF_OTV_KPSN_02h[55]; //Im_min, ����������� ������ ���������� Udc �������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE55->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[56]; //Im_max, ����������� ������ ���������� Udc ��������, ��.�.	��� = 1�, 0..10000 �
   stBData = BUFF_OTV_KPSN_02h[57]; //Im_max, ����������� ������ ���������� Udc ��������, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE57->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = BUFF_OTV_KPSN_02h[58]; //��������� ������ 1-8 ���1�1

   if (BData & 0x80) {Form1->CB_PCH2_BYTE59->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE59->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE59->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE59->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE59->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE59->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE59->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE59->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_02h[59]; //��������� ������ 9-16 ���1�1

   if (BData & 0x80) {Form1->CB_PCH2_BYTE60->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE60->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE60->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE60->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE60->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE60->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE60->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE60->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_02h[60]; //��������� ������ 1-8 ���1�2

   if (BData & 0x80) {Form1->CB_PCH2_BYTE61->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE61->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE61->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE61->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE61->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE61->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE61->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE61->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE61->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE61->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE61->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE61->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE61->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE61->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE61->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE61->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_02h[61]; //��������� ������ 9-16 ���1�2

   if (BData & 0x80) {Form1->CB_PCH2_BYTE62->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE62->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE62->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE62->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE62->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE62->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE62->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE62->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_02h[62]; //������� ���1

   if (BData & 0x80) {Form1->CB_PCH2_BYTE63->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE63->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE63->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE63->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE63->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE63->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE63->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE63->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_02h[63]; //������� ���2

   if (BData & 0x80) {Form1->CB_PCH2_BYTE64->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE64->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE64->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE64->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE64->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE64->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE64->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE64->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[7] = cbUnchecked;}

   mlBData = BUFF_OTV_KPSN_02h[64]; //��� ������������� 1 (���1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY1->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[65]; //��� ������������� 2 (���1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY2->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[66]; //��� ������������� 3 (���1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY3->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[67]; //��� ������������� 4 (���1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY4->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[68]; //��� ������������� 5 (���1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY5->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[69]; //��� ������������� 6 (���1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY6->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[70]; //��� ������������� 7 (���1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY7->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[71]; //��� ������������� 8 (���1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY8->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);


   mlBData = BUFF_OTV_KPSN_02h[72]; //��� ������������� 1 (���2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY1->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[73]; //��� ������������� 2 (���2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY2->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[74]; //��� ������������� 3 (���2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY3->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[75]; //��� ������������� 4 (���2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY4->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[76]; //��� ������������� 5 (���2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY5->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[77]; //��� ������������� 6 (���2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY6->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[78]; //��� ������������� 7 (���2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY7->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[79]; //��� ������������� 8 (���2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY8->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);
   }
}
//---------------------------------------------------------------------------
int count_recive = 0;
void __fastcall ThreadComPort::Printing()
{
    unsigned int GCRC1 = 0x00;

    if (NCycle==1)
    {
     Form1->M_OUT_DATA->Lines->Add(StringToHex(BUFF_ZPR_KPSN_01h, dwZPR_KPSN_01h)); //������� ���������� ������ � Memo
     Form1->StatusBar1->Panels->Items[1]->Text = "�������� " + IntToStr(dwZPR_KPSN_01h) + " ����" ; //������� ���������� ���������� ����

     Form1->M_IN_DATA->Lines->Add(StringToHex(BUFF_OTV_KPSN_01h, dwOTV_KPSN_01h)); //������� �������� ������ � Memo
     Form1->StatusBar1->Panels->Items[2]->Text = "������� " + IntToStr(dwOTV_KPSN_01h) + " ����" ;  //������� ���������� �������� ����

     GCRC1=SCalcCRC(BUFF_OTV_KPSN_01h, 78);
     if((BUFF_OTV_KPSN_01h[0]==0x01)&&(BUFF_OTV_KPSN_01h[1]==0x01)&&
        (BUFF_OTV_KPSN_01h[78]==((UCHAR*)(&GCRC1))[0])&&
        (BUFF_OTV_KPSN_01h[79]==((UCHAR*)(&GCRC1))[1])&&(dwOTV_KPSN_01h==80))
      {
          FUNC_VIEW_ANS_KPSN01h();
      }
    }

    if (NCycle==2)
    {
     Form1->M_OUT_DATA->Lines->Add(StringToHex(BUFF_ZPR_KPSN_02h, dwZPR_KPSN_02h)); //������� ���������� ������ � Memo
     Form1->StatusBar1->Panels->Items[1]->Text = "�������� " + IntToStr(dwZPR_KPSN_02h) + " ����" ; //������� ���������� ���������� ����

     Form1->M_IN_DATA->Lines->Add(StringToHex(BUFF_OTV_KPSN_02h, dwOTV_KPSN_02h)); //������� �������� ������ � Memo
     Form1->StatusBar1->Panels->Items[2]->Text = "������� " + IntToStr(dwOTV_KPSN_02h) + " ����" ;  //������� ���������� �������� ����

     GCRC1=SCalcCRC(BUFF_OTV_KPSN_02h, 78);
     if((BUFF_OTV_KPSN_02h[0]==0x01)&&(BUFF_OTV_KPSN_02h[1]==0x01)&&
        (BUFF_OTV_KPSN_02h[88]==((UCHAR*)(&GCRC1))[0])&&
        (BUFF_OTV_KPSN_02h[89]==((UCHAR*)(&GCRC1))[1])&&(dwOTV_KPSN_02h==90))
      {
          FUNC_VIEW_ANS_KPSN02h();
      }
    }

     Form1->M_IN_DATA->Lines->Add(""); //������� �������� ������ � Memo

/*    
   unsigned char CRCh = 0x00;
   unsigned char CRCl = 0x00;
   unsigned short int GCRC;
   bool PR_CORRECT = false;

   if ((IN_INF_KPA1[1] == 0x01) && (dwIN1 == 80)) {
       GCRC=SCalcCRC(IN_INF_KPA1, 78);
       CRCh = ((UCHAR*)(&GCRC))[0];
       CRCl = ((UCHAR*)(&GCRC))[1];

       if ((IN_INF_KPA1[78] == CRCh) && (IN_INF_KPA1[79] == CRCl)) {
           counter_01h++;
           PR_CORRECT = true;
       }
   }

   if ((IN_INF_KPA1[1] == 0x02) && (dwIN1 == 90)) {
       GCRC=SCalcCRC(IN_INF_KPA1, 88);
       CRCh = ((UCHAR*)(&GCRC))[0];
       CRCl = ((UCHAR*)(&GCRC))[1];

       if ((IN_INF_KPA1[88] == CRCh) && (IN_INF_KPA1[89] == CRCl)) {
           counter_02h++;
           PR_CORRECT = true;
       }
   }

    Form1->M_OUT_DATA->Lines->Add(StringToHex(OUT_INF_KPA1,dwOUT1)); //������� ���������� ������ � Memo
    Form1->StatusBar1->Panels->Items[1]->Text = "�������� " + IntToStr(dwOUT1) + " ����" ; //������� ���������� ���������� ����

    Form1->M_IN_DATA->Lines->Add(IntToStr(dwIN1) + " ����: " + StringToHex(IN_INF_KPA1,dwIN1)); //������� �������� ������ � Memo
    Form1->M_IN_DATA->Lines->Add(IntToStr(GCRC) + " H: " + CRCh + " L: " + CRCl);
    if (PR_CORRECT == 1) {
       Form1->M_IN_DATA->Lines->Add("true");
    } else {
       Form1->M_IN_DATA->Lines->Add("false");
    }

    Form1->StatusBar1->Panels->Items[2]->Text = "������� " + IntToStr(dwIN1) + " ����";  //������� ���������� �������� ����

    unsigned short int PrINCRC = 0x00; // �������� CRC-���� ��������� ������
    PrINCRC=SCalcCRC(IN_INF_KPA1,20);

*/

     if ((dwOTV_KPSN_01h == 80)||(dwOTV_KPSN_02h == 90)) {
         Form1->SHNETSV->Brush->Color = clGreen;
     } else {
         Form1->SHNETSV->Brush->Color = clRed;
     }       

     //��������� ���� ������� ��� ������� �� ������ "����"
     if (Form1->BStart->Caption == "�����")
       {
//         memset(IN_INF_KPA1,0,BuffSize1); //������� ����� ������

         Form1->SHNETSV->Brush->Color = clWhite;         
       }

//    if (dwIN1 == 80) counter_01h++;
//    if (dwIN1 == 90) counter_02h++;    

//    READ_ANSWER();


}

int count_tx1 = 0;
int count_tx2 = 0;

void CLR_BUFF_ZPR_KPSN_01h() {
   memset(BUFF_ZPR_KPSN_01h, 0, 100);
}

void CLR_BUFF_ZPR_KPSN_02h() {
   memset(BUFF_ZPR_KPSN_02h, 0, 100);
}

//---------------------------------------------------------------------------
volatile static unsigned int count_req = 1;

unsigned char TEMP_BUFF[BuffSize1] = {0};

void __fastcall ThreadComPort::Execute()
{
  //---- Place thread code here ----

  while(!Terminated)
   {
    if (Form1->BStart->Caption ==  "�����") { break;}

    Sleep (50);

   switch (NCycle)
  {
   case 1:
    {
        BUFF_ZPR_KPSN_01h[0]=0x01; // �1. �����
        BUFF_ZPR_KPSN_01h[1]=0x01; // �2. �������

        unsigned char ByteDiscrComm = 0x00; //������������� ����� ���������� ������

        if (Form1->CheckListBoxChanel1->Checked[7] == true) {ByteDiscrComm = ByteDiscrComm + 0x01;}
        if (Form1->CheckListBoxChanel1->Checked[6] == true) {ByteDiscrComm = ByteDiscrComm + 0x02;}
        if (Form1->CheckListBoxChanel1->Checked[5] == true) {ByteDiscrComm = ByteDiscrComm + 0x04;}
        if (Form1->CheckListBoxChanel1->Checked[4] == true) {ByteDiscrComm = ByteDiscrComm + 0x08;}

        BUFF_ZPR_KPSN_01h[2] = ByteDiscrComm; // �3. ������� ���

        unsigned char ByteAnlgComm = 0x00; //������������� ����� ���������� ������

        if  (Form1->CBSAVE->Checked == true) {
             BUFF_ZPR_KPSN_01h[3]=  (StrToInt(Form1->E_UST_PROMCONTUR->Text) & 0x00FF) / 1;            // �4. ������� �� ���������� � �����������, ��.�.
             BUFF_ZPR_KPSN_01h[4]= ((StrToInt(Form1->E_UST_PROMCONTUR->Text) & 0xFF00) >> 8 ) / 1;     // �5. ������� �� ���������� � �����������, ��.�.

             BUFF_ZPR_KPSN_01h[5]=  (StrToInt(Form1->E_OGR_ZAR_AKB->Text) & 0x00FF) / 1;               // �6. ����������� �� ���������� ������ ���, ��.�.
             BUFF_ZPR_KPSN_01h[6]= ((StrToInt(Form1->E_OGR_ZAR_AKB->Text) & 0xFF00) >> 8 ) / 1;        // �7. ����������� �� ���������� ������ ���, ��.�.

             BUFF_ZPR_KPSN_01h[7]=  StrToInt(Form1->E_OGR_PRIR_J_ZAR_AKB->Text) / 1;                   // �8. ����������� �� ���������� ���� ������ ���

             BUFF_ZPR_KPSN_01h[8]=  (StrToInt(Form1->E_OGR_J_ZAR_AKB->Text) & 0x00FF) / 1;             // �9. ����������� �� ���� ������ ���, ��.�.
             BUFF_ZPR_KPSN_01h[9]= ((StrToInt(Form1->E_OGR_J_ZAR_AKB->Text) & 0xFF00) >> 8 ) / 1;      // �10. ����������� �� ���� ������ ���, ��.�.

             BUFF_ZPR_KPSN_01h[10]=  (StrToInt(Form1->E_OGR_J_PROMCONTUR->Text) & 0x00FF) / 1;         // �11. ����������� �� ���� �����������, ��.�.
             BUFF_ZPR_KPSN_01h[11]= ((StrToInt(Form1->E_OGR_J_PROMCONTUR->Text) & 0xFF00) >> 8 ) / 1;  // �12. ����������� �� ���� �����������, ��.�.
        }

        GCRC=SCalcCRC(BUFF_ZPR_KPSN_01h, 14);
        BUFF_ZPR_KPSN_01h[14]=((UCHAR*)(&GCRC))[0];
        BUFF_ZPR_KPSN_01h[15]=((UCHAR*)(&GCRC))[1];

        WRITECOM(BUFF_ZPR_KPSN_01h,16);
        count_tx1++;

        GCRC = 0; //����� �������� CRC-���� ��� ������� ����� ��������� ���������
        
        break;
    }
   case 2:
    {
        BUFF_ZPR_KPSN_02h[0]=0x01; // �1. �����
        BUFF_ZPR_KPSN_02h[1]=0x02; // �2. �������
        GCRC=SCalcCRC(BUFF_ZPR_KPSN_02h, 2);
        BUFF_ZPR_KPSN_02h[2]=((UCHAR*)(&GCRC))[0];
        BUFF_ZPR_KPSN_02h[3]=((UCHAR*)(&GCRC))[1];

        WRITECOM(BUFF_ZPR_KPSN_02h, 4);
        count_tx2++;

        GCRC = 0; //����� �������� CRC-���� ��� ������� ����� ��������� ���������

        break;
    }
  }

  Application->ProcessMessages();

   switch (NCycle)
  {
   case 1:
    {
     //FUNC_ZAPIS_PRED_BYTE();

     READCOM(BUFF_OTV_KPSN_01h, 80);
     break;
    }
   case 2:
    {
     //FUNC_ZAPIS_PRED_BYTE();

     READCOM(BUFF_OTV_KPSN_02h, 90);
     break;
    }
  }

  Synchronize (Printing);

  switch (NCycle)
  {
   case 1:
    {
     CLR_BUFF_ZPR_KPSN_01h();
     break;
    }

   case 2:
    {
     CLR_BUFF_ZPR_KPSN_02h();
     break;
    }
  }

   NCycle++;
   if (NCycle == 3) {NCycle = 1;}
   }// �������� while
}
//---------------------------------------------------------------------------


