//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ThreadComPort.h"
#include "UInterface.h"
#include "UCOMPortFunc.h"

extern HANDLE hCom;
extern unsigned short int GCRC;
extern unsigned char StartError;
#define BuffSize1 0x20  //константа для задания длины буфера

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
//задание приоритета потока в его конструкторе 
Priority = tpTimeCritical; // tpHighest - приоритет потока - на два пункта выше нормального
                           // tpTimeCritical - поток получает самый высокий приоритет
}
//---------------------------------------------------------------------------
void __fastcall ThreadComPort::Printing()
{
    Form1->M_OUT_DATA->Lines->Add(StringToHex(OUT_INF_KPA1,dwOUT1)); //выводим переданную строку в Memo
    Form1->StatusBar1->Panels->Items[1]->Text = "Передано " + IntToStr(dwOUT1) + " байт" ; //выводим количество переданных байт

    Form1->M_IN_DATA->Lines->Add(StringToHex(IN_INF_KPA1,dwIN1)); //выводим принятую строку в Memo
    Form1->StatusBar1->Panels->Items[2]->Text = "Принято " + IntToStr(dwIN1) + " байт" ;  //выводим количество принятых байт

    unsigned short int PrINCRC = 0x00; // проверка CRC-кода входящего буфера
    PrINCRC=SCalcCRC(IN_INF_KPA1,20);

     //если ответ не пришел или пришел не полный, тогда
     //обнуляю отображаемую информацию на форме по данному ответу
     if ((dwIN1==0)||(dwIN1!=21))
        {
         for (int k = 0; k < 0x20; k++) IN_INF_KPA1[k] = 0x00; //обнуляю буфер приема

         Form1->SHNETSV->Brush->Color = clRed;
        }
     else {Form1->SHNETSV->Brush->Color = clGreen;}


     //обнуление всех фонарей при нажатии на кнопку "Стоп"
     if (Form1->BStart->Caption == "Старт")
       {
         memset(IN_INF_KPA1,0,BuffSize1); //обнуляю буфер приема

         Form1->SHNETSV->Brush->Color = clWhite;         
       }

    READ_ANSWER();
}
//---------------------------------------------------------------------------
int count_req = 0;
void __fastcall ThreadComPort::Execute()
{
  //---- Place thread code here ----

  while(!Terminated)
   {
    if (Form1->BStart->Caption ==  "Старт") {break;}
    Sleep (50);

    if ((count_req % 2) == 0) {
        OUT_INF_KPA1[0]=0x01; // б1. адрес
        OUT_INF_KPA1[1]=0x01; // б2. команда

        unsigned char ByteDiscrComm = 0x00; //инициализация байта дискретных команд

        if (Form1->CheckListBoxChanel1->Checked[7] == true) {ByteDiscrComm = ByteDiscrComm + 0x01;}
        if (Form1->CheckListBoxChanel1->Checked[6] == true) {ByteDiscrComm = ByteDiscrComm + 0x02;}
        if (Form1->CheckListBoxChanel1->Checked[5] == true) {ByteDiscrComm = ByteDiscrComm + 0x04;}
        if (Form1->CheckListBoxChanel1->Checked[4] == true) {ByteDiscrComm = ByteDiscrComm + 0x08;}

        OUT_INF_KPA1[2] = ByteDiscrComm; // б3. команды СУЭ

        unsigned char ByteAnlgComm = 0x00; //инициализация байта аналоговых команд

        if  (Form1->CBSAVE->Checked == true) {
             OUT_INF_KPA1[3]=  (StrToInt(Form1->E_UST_POWER->Text) & 0x00FF) / 1;         // б4. уставка по напряжению, мл.б.
             OUT_INF_KPA1[4]= ((StrToInt(Form1->E_UST_POWER->Text) & 0xFF00) >> 8 ) / 1;  // б4. уставка по напряжению, ст.б.
        }

        GCRC=SCalcCRC(OUT_INF_KPA1, 8);
        OUT_INF_KPA1[8]=((UCHAR*)(&GCRC))[0];
        OUT_INF_KPA1[9]=((UCHAR*)(&GCRC))[1];

        WRITECOM(OUT_INF_KPA1,10);

        GCRC = 0; //после подсчета CRC-кода для запроса делаю обнуление параметра

        Application->ProcessMessages();
        READCOM(IN_INF_KPA1, 80);
    } else {
        OUT_INF_KPA1[0]=0x01; // б1. адрес
        OUT_INF_KPA1[1]=0x02; // б2. команда
        GCRC=SCalcCRC(OUT_INF_KPA1, 2);
        OUT_INF_KPA1[2]=((UCHAR*)(&GCRC))[0];
        OUT_INF_KPA1[3]=((UCHAR*)(&GCRC))[1];

        WRITECOM(OUT_INF_KPA1, 4);
    }




   Synchronize (Printing);
   count_req++;
   }// закрытие while
}
//---------------------------------------------------------------------------
