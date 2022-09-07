//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ThreadComPort.h"
#include "UInterface.h"
#include "UCOMPortFunc.h"
#include "UReadAnswer.h"

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
int count_recive = 0;
void __fastcall ThreadComPort::Printing()
{
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

   unsigned char stBData = 0x00; //������������� ����� ������ (��.�.)
   unsigned char mlBData = 0x00; //������������� ����� ������ (��.�.)

   double ValueAnParam = 0;    //������������� ���������� �������� ����������� ���������
   AnsiString StrValueAnDouble = ""; //������ � ��������� ��������� ���������� ��������� ���� double

     if ((dwIN1 == 80)||(dwIN1 == 90)) {
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

    READ_ANSWER();
}

int count_tx1 = 0;
int count_tx2 = 0;

void __fastcall ThreadComPort::pb() {
    static int n = 0;
    n++;

   Form1->LTX1->Caption = count_tx1;
   Form1->LTX2->Caption = count_tx2;
//    Form1->Caption = n;
}

volatile unsigned int aaa = 0;

void __fastcall ThreadComPort::READ_ANSWER2() {
   //1. ������� ������� �� ���� (������� 01h, ��1)
   if (IN_INF_KPA1[1] == 0x01) {
   unsigned char stBData = 0x00; //������������� ����� ������ (��.�.)
   unsigned char mlBData = 0x00; //������������� ����� ������ (��.�.)

   static double ValueAnParam = 0;    //������������� ���������� �������� ����������� ���������
   AnsiString StrValueAnDouble = ""; //������ � ��������� ��������� ���������� ��������� ���� double
      
   mlBData = IN_INF_KPA1[63]; //������� ������ ����, ��.�.  ��� = 1, 0.. 65535
   stBData = IN_INF_KPA1[64]; //������� ������ ����, ��.�.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1;
   aaa = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1;
   Form1->VPCH1_BYTE64->Caption =  ValueAnParam;
   Form1->Caption = aaa;
   }
}
//---------------------------------------------------------------------------
volatile static unsigned int count_req = 1;

unsigned char NCycle = 0;

unsigned char TEMP_BUFF[BuffSize1] = {0};

void __fastcall ThreadComPort::Execute()
{
  //---- Place thread code here ----

  while(!Terminated)
   {
    if (Form1->BStart->Caption ==  "�����") {break;}

  //������ ������ ����� �������
   for (int i = 0; i < 14; i++) {
       OUT_INF_KPA1[i] = 0;
   }

   Sleep (500);

   switch (NCycle)
  {
   case 0:
    {
        OUT_INF_KPA1[0]=0x01; // �1. �����
        OUT_INF_KPA1[1]=0x01; // �2. �������

        unsigned char ByteDiscrComm = 0x00; //������������� ����� ���������� ������

        if (Form1->CheckListBoxChanel1->Checked[7] == true) {ByteDiscrComm = ByteDiscrComm + 0x01;}
        if (Form1->CheckListBoxChanel1->Checked[6] == true) {ByteDiscrComm = ByteDiscrComm + 0x02;}
        if (Form1->CheckListBoxChanel1->Checked[5] == true) {ByteDiscrComm = ByteDiscrComm + 0x04;}
        if (Form1->CheckListBoxChanel1->Checked[4] == true) {ByteDiscrComm = ByteDiscrComm + 0x08;}

        OUT_INF_KPA1[2] = ByteDiscrComm; // �3. ������� ���

        unsigned char ByteAnlgComm = 0x00; //������������� ����� ���������� ������

        if  (Form1->CBSAVE->Checked == true) {
             OUT_INF_KPA1[3]=  (StrToInt(Form1->E_UST_PROMCONTUR->Text) & 0x00FF) / 1;            // �4. ������� �� ���������� � �����������, ��.�.
             OUT_INF_KPA1[4]= ((StrToInt(Form1->E_UST_PROMCONTUR->Text) & 0xFF00) >> 8 ) / 1;     // �5. ������� �� ���������� � �����������, ��.�.

             OUT_INF_KPA1[5]=  (StrToInt(Form1->E_OGR_ZAR_AKB->Text) & 0x00FF) / 1;               // �6. ����������� �� ���������� ������ ���, ��.�.
             OUT_INF_KPA1[6]= ((StrToInt(Form1->E_OGR_ZAR_AKB->Text) & 0xFF00) >> 8 ) / 1;        // �7. ����������� �� ���������� ������ ���, ��.�.

             OUT_INF_KPA1[7]=  StrToInt(Form1->E_OGR_PRIR_J_ZAR_AKB->Text) / 1;                   // �8. ����������� �� ���������� ���� ������ ���

             OUT_INF_KPA1[8]=  (StrToInt(Form1->E_OGR_J_ZAR_AKB->Text) & 0x00FF) / 1;             // �9. ����������� �� ���� ������ ���, ��.�.
             OUT_INF_KPA1[9]= ((StrToInt(Form1->E_OGR_J_ZAR_AKB->Text) & 0xFF00) >> 8 ) / 1;      // �10. ����������� �� ���� ������ ���, ��.�.

             OUT_INF_KPA1[10]=  (StrToInt(Form1->E_OGR_J_PROMCONTUR->Text) & 0x00FF) / 1;         // �11. ����������� �� ���� �����������, ��.�.
             OUT_INF_KPA1[11]= ((StrToInt(Form1->E_OGR_J_PROMCONTUR->Text) & 0xFF00) >> 8 ) / 1;  // �12. ����������� �� ���� �����������, ��.�.
        }

        GCRC=SCalcCRC(OUT_INF_KPA1, 14);
        OUT_INF_KPA1[14]=((UCHAR*)(&GCRC))[0];
        OUT_INF_KPA1[15]=((UCHAR*)(&GCRC))[1];

        WRITECOM(OUT_INF_KPA1,16);
        count_tx1++;

        GCRC = 0; //����� �������� CRC-���� ��� ������� ����� ��������� ���������
        
        break;
    }
   case 1:
    {
        OUT_INF_KPA1[0]=0x01; // �1. �����
        OUT_INF_KPA1[1]=0x02; // �2. �������
        GCRC=SCalcCRC(OUT_INF_KPA1, 2);
        OUT_INF_KPA1[2]=((UCHAR*)(&GCRC))[0];
        OUT_INF_KPA1[3]=((UCHAR*)(&GCRC))[1];

        WRITECOM(OUT_INF_KPA1, 4);
        count_tx2++;

        GCRC = 0; //����� �������� CRC-���� ��� ������� ����� ��������� ���������

        break;
    }
  }

/*
    if (count_req == 1) {
        OUT_INF_KPA1[0]=0x01; // �1. �����
        OUT_INF_KPA1[1]=0x01; // �2. �������

        unsigned char ByteDiscrComm = 0x00; //������������� ����� ���������� ������

        if (Form1->CheckListBoxChanel1->Checked[7] == true) {ByteDiscrComm = ByteDiscrComm + 0x01;}
        if (Form1->CheckListBoxChanel1->Checked[6] == true) {ByteDiscrComm = ByteDiscrComm + 0x02;}
        if (Form1->CheckListBoxChanel1->Checked[5] == true) {ByteDiscrComm = ByteDiscrComm + 0x04;}
        if (Form1->CheckListBoxChanel1->Checked[4] == true) {ByteDiscrComm = ByteDiscrComm + 0x08;}

        OUT_INF_KPA1[2] = ByteDiscrComm; // �3. ������� ���

        unsigned char ByteAnlgComm = 0x00; //������������� ����� ���������� ������

        if  (Form1->CBSAVE->Checked == true) {
             OUT_INF_KPA1[3]=  (StrToInt(Form1->E_UST_PROMCONTUR->Text) & 0x00FF) / 1;            // �4. ������� �� ���������� � �����������, ��.�.
             OUT_INF_KPA1[4]= ((StrToInt(Form1->E_UST_PROMCONTUR->Text) & 0xFF00) >> 8 ) / 1;     // �5. ������� �� ���������� � �����������, ��.�.

             OUT_INF_KPA1[5]=  (StrToInt(Form1->E_OGR_ZAR_AKB->Text) & 0x00FF) / 1;               // �6. ����������� �� ���������� ������ ���, ��.�.
             OUT_INF_KPA1[6]= ((StrToInt(Form1->E_OGR_ZAR_AKB->Text) & 0xFF00) >> 8 ) / 1;        // �7. ����������� �� ���������� ������ ���, ��.�.

             OUT_INF_KPA1[7]=  StrToInt(Form1->E_OGR_PRIR_J_ZAR_AKB->Text) / 1;                   // �8. ����������� �� ���������� ���� ������ ���

             OUT_INF_KPA1[8]=  (StrToInt(Form1->E_OGR_J_ZAR_AKB->Text) & 0x00FF) / 1;             // �9. ����������� �� ���� ������ ���, ��.�.
             OUT_INF_KPA1[9]= ((StrToInt(Form1->E_OGR_J_ZAR_AKB->Text) & 0xFF00) >> 8 ) / 1;      // �10. ����������� �� ���� ������ ���, ��.�.

             OUT_INF_KPA1[10]=  (StrToInt(Form1->E_OGR_J_PROMCONTUR->Text) & 0x00FF) / 1;         // �11. ����������� �� ���� �����������, ��.�.
             OUT_INF_KPA1[11]= ((StrToInt(Form1->E_OGR_J_PROMCONTUR->Text) & 0xFF00) >> 8 ) / 1;  // �12. ����������� �� ���� �����������, ��.�.
        }

        GCRC=SCalcCRC(OUT_INF_KPA1, 14);
        OUT_INF_KPA1[14]=((UCHAR*)(&GCRC))[0];
        OUT_INF_KPA1[15]=((UCHAR*)(&GCRC))[1];

        WRITECOM(OUT_INF_KPA1,16);
        count_tx1++;

        GCRC = 0; //����� �������� CRC-���� ��� ������� ����� ��������� ���������

//        Application->ProcessMessages();
//        READCOM(IN_INF_KPA1, 80);
    } else {
        OUT_INF_KPA1[0]=0x01; // �1. �����
        OUT_INF_KPA1[1]=0x02; // �2. �������
        GCRC=SCalcCRC(OUT_INF_KPA1, 2);
        OUT_INF_KPA1[2]=((UCHAR*)(&GCRC))[0];
        OUT_INF_KPA1[3]=((UCHAR*)(&GCRC))[1];

        WRITECOM(OUT_INF_KPA1, 4);
        count_tx2++;

        GCRC = 0; //����� �������� CRC-���� ��� ������� ����� ��������� ���������

//        Application->ProcessMessages();
//        READCOM(IN_INF_KPA1, 90);
    }

*/

  Application->ProcessMessages();

   switch (NCycle)
  {
   case 0:
    {
     //FUNC_ZAPIS_PRED_BYTE();

     READCOM(TEMP_BUFF, 80);
     break;
    }
   case 1:
    {
     //FUNC_ZAPIS_PRED_BYTE();

     READCOM(TEMP_BUFF, 90);
     break;
    }
  }

  for (int i = 0; i < 100; i ++) {
  }

  memcpy(IN_INF_KPA1, TEMP_BUFF, 99);

   Synchronize (Printing);
   Synchronize (READ_ANSWER2);
   Synchronize (pb);
//        Application->ProcessMessages();

   NCycle++;
   if (NCycle == 2) {NCycle = 0;}

//   count_req++;
   }// �������� while
}
//---------------------------------------------------------------------------


