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
#define BuffSize1 100  //константа для задания длины буфера

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
//обработка нажатия на кнопке с надписью равной "Старт"
  if (BStart->Caption ==  "Старт")
  {
   StartError = 0;//обнуляю ошибку, чтобы прошлая ошибка работы с СОМ-порта(запись/чтение данных)
                  //не повлияла на запуск создаваемого вновь потока

//если дескриптор потока hCom равен "0" (не существует, тк не открыт), то открываю СОМ-порт и создаю дескриптор
//в противном случае существующий дескриптор надо закрыть и перейти на ветку CLOSECOM() закрытия дескриптора
   if (hCom == 0)
    {
   OPENCOM();

// если не возникло ошибок при открытии, то далее следует нижняя часть программы
     if (StartError == 0)
      {
   SETTINGCOM();
//запрещаю перевыбор COM-порта после нажатия на кнопку "Старт"
   BStart->Caption =  "Стоп";                //сменить надпись на кнопке

   StartError = 0x00; //обнуляю значение ошибки при старте

//1-ый Вариант задания приоритета для потока (в самом конструкторе потока)
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

//если все же возникла ошибка была при открытии, то закрываю дескриптор (handle) СОМ-порта для повторного открытия
//и обнуляю счетчик ошибок при старте при следующем нажатии на "Старт"
      else {CLOSECOM();}
    }
  }
  else
  {
//обработка нажатия на кнопке с надписью равной "Стоп"

   //останавливаю таймер при нажатии на кнопку "Стоп",
   //а запускаю его в конце обработчика, чтобы не получалась ситуация:
   //когда еще горят зелеными "Ответ" от абонента, счетчик сбоев увеличивался

//при нажатии на кнопку "Стоп" - очищаю буфера приема и передачи,
//устанавливаю счетчик циклов (NCycle) в начало, т.е. равным 1
   CLEARBUFCOM();//
//   NCycle = 1;

if (hCom)
   {PurgeComm(hCom, PURGE_RXCLEAR|PURGE_TXCLEAR|PURGE_TXABORT|PURGE_RXABORT);}

//закрываю дескриптор СОМ-порта
   CLOSECOM();

   BStart->Caption =  "Старт"; //меняю надпись на кнопке

   Form1->StatusBar1->Panels->Items[0]->Text = ""; //очищаю первую колонку строки состояния

   if(ThCom) ThCom->Terminate();   //завершить поток чтения из порта, проверка if(WriteCom) обязательна, иначе возникают ошибки

//обнуляю содержимое указателей на количество переданных/принятых данных
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
char NKey = Key; //переменная с начальным значением нажатой клавиши
if(((NKey<48)||(NKey>57))) Key=0; //(c 48(дес.) по 57(дес) это коды клавиш цифр: с 0 по 9)
if (NKey == 46) Key = 46; //обработка по нажатию клавиши Delete
if (NKey == 0x8) Key = 0x8; //обработка по нажатию клавиши BackSpace        
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

