//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UInterface.h"
#include "UInitialization.h"
#include "UCOMPortFunc.h"
#include "ThreadComPort.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
ThreadComPort *ThCom;

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
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BExitClick(TObject *Sender)
{
// if (hCom!=0) CLOSECOM();
 Close();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BStartClick(TObject *Sender)
{
//��������� ������� �� ������ � �������� ������ "�����"
  if (BStart->Caption ==  "�����")
  {
   StartError = 0;//������� ������, ����� ������� ������ ������ � ���-�����(������/������ ������)
                  //�� �������� �� ������ ������������ ����� ������

//���� ���������� ������ hCom ����� "0" (�� ����������, �� �� ������), �� �������� ���-���� � ������ ����������
//� ��������� ������ ������������ ���������� ���� ������� � ������� �� ����� CLOSECOM() �������� �����������
   if (hCom == 0)
    {
   OPENCOM();

// ���� �� �������� ������ ��� ��������, �� ����� ������� ������ ����� ���������
     if (StartError == 0)
      {
   SETTINGCOM();
//�������� ��������� COM-����� ����� ������� �� ������ "�����"
   BStart->Caption =  "����";                //������� ������� �� ������

   StartError = 0x00; //������� �������� ������ ��� ������

//1-�� ������� ������� ���������� ��� ������ (� ����� ������������ ������)
//   ThreadWriteReadCOMPort = new ThreadWriteRead (false);
//   ThreadWriteReadCOMPort->FreeOnTerminate = true;
//   ThreadWriteRead *ThreadWriteReadCOMPort;

   ThCom = new ThreadComPort (false);
   ThCom->FreeOnTerminate = true;
// ThreadComPort *ThCom;

   M_OUT_DATA->Clear();
   M_IN_DATA->Clear();

   BExit->Enabled = false;
      }

//���� ��� �� �������� ������ ���� ��� ��������, �� �������� ���������� (handle) ���-����� ��� ���������� ��������
//� ������� ������� ������ ��� ������ ��� ��������� ������� �� "�����"
      else {CLOSECOM();}
    }
  }
  else
  {
//��������� ������� �� ������ � �������� ������ "����"

   //������������ ������ ��� ������� �� ������ "����",
   //� �������� ��� � ����� �����������, ����� �� ���������� ��������:
   //����� ��� ����� �������� "�����" �� ��������, ������� ����� ������������

//��� ������� �� ������ "����" - ������ ������ ������ � ��������,
//������������ ������� ������ (NCycle) � ������, �.�. ������ 1
   CLEARBUFCOM();//
//   NCycle = 1;

if (hCom)
   {PurgeComm(hCom, PURGE_RXCLEAR|PURGE_TXCLEAR|PURGE_TXABORT|PURGE_RXABORT);}

//�������� ���������� ���-�����
   CLOSECOM();

   BStart->Caption =  "�����"; //����� ������� �� ������

   Form1->StatusBar1->Panels->Items[0]->Text = ""; //������ ������ ������� ������ ���������

   if(ThCom) ThCom->Terminate();   //��������� ����� ������ �� �����, �������� if(WriteCom) �����������, ����� ��������� ������

//������� ���������� ���������� �� ���������� ����������/�������� ������
dwIN1 = 0;
dwOUT1 = 0;

 BExit->Enabled = true;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
COMPORT->ItemIndex = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::E_UST_PROMCONTURKeyPress(TObject *Sender, char &Key)
{
char NKey = Key; //���������� � ��������� ��������� ������� �������
if(((NKey<48)||(NKey>57))) Key=0; //(c 48(���.) �� 57(���) ��� ���� ������ ����: � 0 �� 9)
if (NKey == 46) Key = 46; //��������� �� ������� ������� Delete
if (NKey == 0x8) Key = 0x8; //��������� �� ������� ������� BackSpace        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B_SHOW_RXTXClick(TObject *Sender)
{
M_OUT_DATA->Visible = true;
MError->Visible = true;
M_IN_DATA->Visible = true;
L_TX_DATA->Visible = true;
L_RX_DATA->Visible = true;
L_ERROR_DATA->Visible = true;
Form1->Width = 1800;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::E_UST_PROMCONTURChange(TObject *Sender)
{
if (E_UST_PROMCONTUR->Text == "") {E_UST_PROMCONTUR->Text = "0";}
if (E_UST_PROMCONTUR->Text.ToInt() > 750) {E_UST_PROMCONTUR->Text = "750";}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::E_OGR_ZAR_AKBChange(TObject *Sender)
{
if (E_OGR_ZAR_AKB->Text == "") {E_OGR_ZAR_AKB->Text = "0";}
if (E_OGR_ZAR_AKB->Text.ToInt() > 750) {E_OGR_ZAR_AKB->Text = "750";}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::E_OGR_PRIR_J_ZAR_AKBChange(TObject *Sender)
{
if (E_OGR_PRIR_J_ZAR_AKB->Text == "") {E_OGR_PRIR_J_ZAR_AKB->Text = "0";}
if (E_OGR_PRIR_J_ZAR_AKB->Text.ToInt() > 100) {E_OGR_PRIR_J_ZAR_AKB->Text = "100";}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::E_OGR_J_ZAR_AKBChange(TObject *Sender)
{
if (E_OGR_J_ZAR_AKB->Text == "") {E_OGR_J_ZAR_AKB->Text = "0";}
if (E_OGR_J_ZAR_AKB->Text.ToInt() > 500) {E_OGR_J_ZAR_AKB->Text = "500";}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::E_OGR_J_PROMCONTURChange(TObject *Sender)
{
if (E_OGR_J_PROMCONTUR->Text == "") {E_OGR_J_PROMCONTUR->Text = "0";}
if (E_OGR_J_PROMCONTUR->Text.ToInt() > 500) {E_OGR_J_PROMCONTUR->Text = "500";}
}
//---------------------------------------------------------------------------

