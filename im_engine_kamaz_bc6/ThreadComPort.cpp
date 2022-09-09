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
void FUNC_VIEW_ANS_KPSN01h() {
   unsigned char BData = 0x00; //инициализация байта данных

   unsigned char stBData = 0x00; //инициализация байта данных (ст.б.)
   unsigned char mlBData = 0x00; //инициализация байта данных (мл.б.)

   double ValueAnParam = 0;    //инициализация выводимого значения аналогового параметра
   AnsiString StrValueAnDouble = ""; //строка с выводимым значением аналоговым параметра типа double

   //1. Парсинг посылки от КПСН (команда 01h, ПЧ1)
   if ((BUFF_OTV_KPSN_01h[1] == 0x01)) {// && (PR_CORRECT_CRC == true)) {
   mlBData = BUFF_OTV_KPSN_01h[2]; //Fpllout, Вычисленная ФАПЧ частота сети, мл.б. ЦМР = 0,1 Гц, 0..100Гц
   stBData = BUFF_OTV_KPSN_01h[3]; //Fpllout, Вычисленная ФАПЧ частота сети, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH1_BYTE3->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);


   mlBData = BUFF_OTV_KPSN_01h[4]; //Dout RMS, СКЗ коэффициента модуляции ШИМ, мл.б.	ЦМР = 0,1%, 0..200%
   stBData = BUFF_OTV_KPSN_01h[5]; //Dout RMS, СКЗ коэффициента модуляции ШИМ, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH1_BYTE5->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[6]; //Im_set, Задание амплитуды тока, мл.б.	ЦМР = 1А, 0..10000А
   stBData = BUFF_OTV_KPSN_01h[7]; //Im_set, Задание амплитуды тока, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE7->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[8]; //Te, Температура радиатора    ЦМР = 0,5°С 0..127,5°С
   ValueAnParam = ((unsigned char)mlBData)* 0.5;
   Form1->EPCH1_BYTE9->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[9]; //Tecu, Температура контроллера    ЦМР = 0,5°С 0..127,5°С
   ValueAnParam = ((unsigned char)mlBData)* 0.5;
   Form1->EPCH1_BYTE10->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[12]; //Dchop, Коэффициента модуляции ШИМ тормозного ключа, мл.б.   ЦМР = 0,1%,0..100%
   stBData = BUFF_OTV_KPSN_01h[13]; //Dchop, Коэффициента модуляции ШИМ тормозного ключа, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH1_BYTE13->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[16]; //Id (Ibr_m), Средний за период ШИМ ток тормозного резистора, мл.б.   ЦМР = 1А, 0..10000А
   stBData = BUFF_OTV_KPSN_01h[17]; //Id (Ibr_m), Средний за период ШИМ ток тормозного резистора, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE17->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[22]; //Uac RMS, СКЗ напряжения со стороны фазы преобразователя, мл.б. ЦМР = 1В, 0..10000В
   stBData = BUFF_OTV_KPSN_01h[23]; //Uac RMS, СКЗ напряжения со стороны фазы преобразователя, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE23->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[24]; //Ia (I2) RMS, СКЗ тока преобразователя, мл.б. ЦМР = 1А, 0..10000А
   stBData = BUFF_OTV_KPSN_01h[25]; //Ia (I2) RMS, СКЗ тока преобразователя, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE25->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[28]; //Udc, Напряжение конденсаторов, мл.б. ЦМР = 1В, 0..10000В
   stBData = BUFF_OTV_KPSN_01h[29]; //Udc, Напряжение конденсаторов, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE29->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = BUFF_OTV_KPSN_01h[30]; //RUNMODE, Текущий режим работы, мл.б.

   if (BData & 0x80) {Form1->CB_PCH1_BYTE31->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE31->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE31->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE31->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE31->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE31->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE31->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE31->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_01h[31]; //RUNMODE, Текущий режим работы, ст.б.

   if (BData & 0x80) {Form1->CB_PCH1_BYTE32->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE32->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE32->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE32->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE32->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE32->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE32->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE32->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_01h[32]; //STATUS, Биты ошибок, мл.б.

   if (BData & 0x80) {Form1->CB_PCH1_BYTE33->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE33->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE33->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE33->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE33->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE33->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE33->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE33->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_01h[33]; //STATUS, Биты ошибок, ст.б.

   if (BData & 0x80) {Form1->CB_PCH1_BYTE34->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE34->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE34->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE34->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE34->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE34->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE34->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE34->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[7] = cbUnchecked;}

   mlBData = BUFF_OTV_KPSN_01h[38]; //Uac, Мгновенное значение напряжения первичной обмотки (HV) после измерительного трансформатора, мл.б.	ЦМР = 1В,  0..10000В
   stBData = BUFF_OTV_KPSN_01h[39]; //Uac, Мгновенное значение напряжения первичной обмотки (HV) после измерительного трансформатора, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE39->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[40]; //Ia, Мгновенное значение тока Ia, мл.б.	ЦМР = 1А, 0..10000А
   stBData = BUFF_OTV_KPSN_01h[41]; //Ia, Мгновенное значение тока Ia, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE41->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[42]; //Ib, Мгновенное значение тока Ib, мл.б.	ЦМР = 1А, 0..10000А
   stBData = BUFF_OTV_KPSN_01h[43]; //Ib, Мгновенное значение тока Ib, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE43->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = BUFF_OTV_KPSN_01h[46]; //MODESET, Режим работы, мл.б

   if (BData & 0x80) {Form1->CB_PCH1_BYTE47->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE47->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE47->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE47->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE47->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE47->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE47->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE47->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_01h[47]; //MODESET, Режим работы, ст.б

   if (BData & 0x80) {Form1->CB_PCH1_BYTE48->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE48->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE48->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE48->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE48->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE48->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE48->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE48->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[7] = cbUnchecked;}

   mlBData = BUFF_OTV_KPSN_01h[48]; //Set1, Уставка напряжения Udc, мл.б	ЦМР = 1В, 0..10000 В
   stBData = BUFF_OTV_KPSN_01h[49]; //Set1, Уставка напряжения Udc, ст.б
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE49->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[50]; //Set2, Уставка амплитуды тока вторичной обмотки (Im_set), мл.б.	ЦМР = 1А, 0..10000 А
   stBData = BUFF_OTV_KPSN_01h[51]; //Set2, Уставка амплитуды тока вторичной обмотки (Im_set), ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE51->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[54]; //Im_min, Ограничение выхода регулятора Udc минимум, мл.б.  ЦМР = 1А, 0..10000 А
   stBData = BUFF_OTV_KPSN_01h[55]; //Im_min, Ограничение выхода регулятора Udc минимум, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE55->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[56]; //Im_max, Ограничение выхода регулятора Udc максимум, мл.б.	ЦМР = 1А, 0..10000 А
   stBData = BUFF_OTV_KPSN_01h[57]; //Im_max, Ограничение выхода регулятора Udc максимум, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE57->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = BUFF_OTV_KPSN_01h[58]; //Диагностика связи по М1 (59 байт)

   if (BData & 0x80) {Form1->CB_RPD_BYTE59->State[0] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_RPD_BYTE59->State[1] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_RPD_BYTE59->State[2] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_RPD_BYTE59->State[3] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_RPD_BYTE59->State[4] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_RPD_BYTE59->State[5] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_RPD_BYTE59->State[6] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_RPD_BYTE59->State[7] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_01h[59]; //Диагностика связи по М1 (60 байт)

   if (BData & 0x80) {Form1->CB_RPD_BYTE60->State[0] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_RPD_BYTE60->State[1] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_RPD_BYTE60->State[2] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_RPD_BYTE60->State[3] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_RPD_BYTE60->State[4] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_RPD_BYTE60->State[5] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_RPD_BYTE60->State[6] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_RPD_BYTE60->State[7] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_01h[60]; //Диагностика связи по М1 (61 байт)

   if (BData & 0x80) {Form1->CB_RPD_BYTE61->State[0] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_RPD_BYTE61->State[1] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_RPD_BYTE61->State[2] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_RPD_BYTE61->State[3] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_RPD_BYTE61->State[4] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_RPD_BYTE61->State[5] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_RPD_BYTE61->State[6] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_RPD_BYTE61->State[7] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_01h[61]; //Диагностика связи по М1 (62 байт)

   if (BData & 0x80) {Form1->CB_RPD_BYTE62->State[0] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_RPD_BYTE62->State[1] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_RPD_BYTE62->State[2] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_RPD_BYTE62->State[3] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_RPD_BYTE62->State[4] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_RPD_BYTE62->State[5] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_RPD_BYTE62->State[6] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_RPD_BYTE62->State[7] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[7] = cbUnchecked;}

   mlBData = BUFF_OTV_KPSN_01h[62]; //Версия КПСН
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VPCH1_BYTE63->Caption = StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_01h[63]; //Счетчик циклов КПСН, мл.б.  ЦМР = 1, 0.. 65535
   stBData = BUFF_OTV_KPSN_01h[64]; //Счетчик циклов КПСН, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->VPCH1_BYTE64->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = BUFF_OTV_KPSN_01h[65]; //Диагностика связи с ВУ (66 байт)

   if (BData & 0x80) {Form1->CB_PCH1_BYTE66->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE66->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE66->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE66->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE66->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE66->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE66->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE66->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE66->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE66->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE66->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE66->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE66->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE66->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE66->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE66->State[7] = cbUnchecked;}

   mlBData = BUFF_OTV_KPSN_01h[66]; //Состояние КПСН
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VPCH1_BYTE67->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = BUFF_OTV_KPSN_01h[67]; //Признаки отказов (68 байт)

   if (BData & 0x80) {Form1->CB_PCH1_BYTE68->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE68->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE68->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE68->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE68->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE68->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE68->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE68->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE68->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE68->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE68->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE68->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE68->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE68->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE68->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE68->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_01h[68]; //Признаки квитирования (69 байт)

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
   unsigned char BData = 0x00; //инициализация байта данных

   unsigned char stBData = 0x00; //инициализация байта данных (ст.б.)
   unsigned char mlBData = 0x00; //инициализация байта данных (мл.б.)

   double ValueAnParam = 0;    //инициализация выводимого значения аналогового параметра
   AnsiString StrValueAnDouble = ""; //строка с выводимым значением аналоговым параметра типа double

   //2. Парсинг посылки от КПСН (команда 02h, ПЧ2)
   if ((BUFF_OTV_KPSN_02h[1] == 0x02)) {// && (PR_CORRECT_CRC == true)) {
   mlBData = BUFF_OTV_KPSN_02h[2]; //Fpllout, Вычисленная ФАПЧ частота сети, мл.б. ЦМР = 0,1 Гц, 0..100Гц
   stBData = BUFF_OTV_KPSN_02h[3]; //Fpllout, Вычисленная ФАПЧ частота сети, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH2_BYTE3->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[4]; //Dout RMS, СКЗ коэффициента модуляции ШИМ, мл.б.	ЦМР = 0,1%, 0..200%
   stBData = BUFF_OTV_KPSN_02h[5]; //Dout RMS, СКЗ коэффициента модуляции ШИМ, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH2_BYTE5->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[6]; //Im_set, Задание амплитуды тока, мл.б.	ЦМР = 1А, 0..10000А
   stBData = BUFF_OTV_KPSN_02h[7]; //Im_set, Задание амплитуды тока, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE7->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[8]; //Te, Температура радиатора    ЦМР = 0,5°С 0..127,5°С
   ValueAnParam = ((unsigned char)mlBData)* 0.5;
   Form1->EPCH2_BYTE9->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[9]; //Tecu, Температура контроллера    ЦМР = 0,5°С 0..127,5°С
   ValueAnParam = ((unsigned char)mlBData)* 0.5;
   Form1->EPCH2_BYTE10->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[12]; //Dchop, Коэффициента модуляции ШИМ тормозного ключа, мл.б.   ЦМР = 0,1%,0..100%
   stBData = BUFF_OTV_KPSN_02h[13]; //Dchop, Коэффициента модуляции ШИМ тормозного ключа, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH2_BYTE13->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[16]; //Id (Ibr_m), Средний за период ШИМ ток тормозного резистора, мл.б.   ЦМР = 1А, 0..10000А
   stBData = BUFF_OTV_KPSN_02h[17]; //Id (Ibr_m), Средний за период ШИМ ток тормозного резистора, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE17->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[22]; //Uac RMS, СКЗ напряжения со стороны фазы преобразователя, мл.б. ЦМР = 1В, 0..10000В
   stBData = BUFF_OTV_KPSN_02h[23]; //Uac RMS, СКЗ напряжения со стороны фазы преобразователя, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE23->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[24]; //Ia (I2) RMS, СКЗ тока преобразователя, мл.б. ЦМР = 1А, 0..10000А
   stBData = BUFF_OTV_KPSN_02h[25]; //Ia (I2) RMS, СКЗ тока преобразователя, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE25->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[28]; //Udc, Напряжение конденсаторов, мл.б. ЦМР = 1В, 0..10000В
   stBData = BUFF_OTV_KPSN_02h[29]; //Udc, Напряжение конденсаторов, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE29->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = BUFF_OTV_KPSN_02h[30]; //RUNMODE, Текущий режим работы, мл.б.

   if (BData & 0x80) {Form1->CB_PCH2_BYTE31->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE31->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE31->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE31->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE31->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE31->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE31->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE31->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_02h[31]; //RUNMODE, Текущий режим работы, ст.б.

   if (BData & 0x80) {Form1->CB_PCH2_BYTE32->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE32->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE32->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE32->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE32->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE32->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE32->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE32->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_02h[32]; //STATUS, Биты ошибок, мл.б.

   if (BData & 0x80) {Form1->CB_PCH2_BYTE33->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE33->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE33->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE33->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE33->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE33->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE33->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE33->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_02h[33]; //STATUS, Биты ошибок, ст.б.

   if (BData & 0x80) {Form1->CB_PCH2_BYTE34->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE34->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE34->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE34->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE34->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE34->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE34->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE34->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[7] = cbUnchecked;}

   mlBData = BUFF_OTV_KPSN_02h[38]; //Uac, Мгновенное значение напряжения первичной обмотки (HV) после измерительного трансформатора, мл.б.	ЦМР = 1В,  0..10000В
   stBData = BUFF_OTV_KPSN_02h[39]; //Uac, Мгновенное значение напряжения первичной обмотки (HV) после измерительного трансформатора, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE39->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[40]; //Ia, Мгновенное значение тока Ia, мл.б.	ЦМР = 1А, 0..10000А
   stBData = BUFF_OTV_KPSN_02h[41]; //Ia, Мгновенное значение тока Ia, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE41->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[42]; //Ib, Мгновенное значение тока Ib, мл.б.	ЦМР = 1А, 0..10000А
   stBData = BUFF_OTV_KPSN_02h[43]; //Ib, Мгновенное значение тока Ib, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE43->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = BUFF_OTV_KPSN_02h[44]; //NPRM, мл.б

   if (BData & 0x80) {Form1->CB_PCH2_BYTE45->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE45->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE45->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE45->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE45->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE45->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE45->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE45->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_02h[45]; //NPRM, ст.б

   if (BData & 0x80) {Form1->CB_PCH2_BYTE46->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE46->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE46->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE46->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE46->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE46->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE46->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE46->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_02h[46]; //MODESET, Режим работы, мл.б

   if (BData & 0x80) {Form1->CB_PCH2_BYTE47->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE47->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE47->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE47->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE47->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE47->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE47->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE47->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_02h[47]; //MODESET, Режим работы, ст.б

   if (BData & 0x80) {Form1->CB_PCH2_BYTE48->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE48->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE48->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE48->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE48->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE48->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE48->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE48->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[7] = cbUnchecked;}

   mlBData = BUFF_OTV_KPSN_02h[48]; //Set1, Уставка напряжения Udc, мл.б	ЦМР = 1В, 0..10000 В
   stBData = BUFF_OTV_KPSN_02h[49]; //Set1, Уставка напряжения Udc, ст.б
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE49->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[50]; //Set2, Уставка амплитуды тока вторичной обмотки (Im_set), мл.б.	ЦМР = 1А, 0..10000 А
   stBData = BUFF_OTV_KPSN_02h[51]; //Set2, Уставка амплитуды тока вторичной обмотки (Im_set), ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE51->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[54]; //Im_min, Ограничение выхода регулятора Udc минимум, мл.б.  ЦМР = 1А, 0..10000 А
   stBData = BUFF_OTV_KPSN_02h[55]; //Im_min, Ограничение выхода регулятора Udc минимум, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE55->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[56]; //Im_max, Ограничение выхода регулятора Udc максимум, мл.б.	ЦМР = 1А, 0..10000 А
   stBData = BUFF_OTV_KPSN_02h[57]; //Im_max, Ограничение выхода регулятора Udc максимум, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE57->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = BUFF_OTV_KPSN_02h[58]; //Состояние входов 1-8 БВС1К1

   if (BData & 0x80) {Form1->CB_PCH2_BYTE59->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE59->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE59->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE59->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE59->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE59->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE59->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE59->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_02h[59]; //Состояние входов 9-16 БВС1К1

   if (BData & 0x80) {Form1->CB_PCH2_BYTE60->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE60->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE60->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE60->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE60->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE60->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE60->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE60->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_02h[60]; //Состояние входов 1-8 БВС1К2

   if (BData & 0x80) {Form1->CB_PCH2_BYTE61->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE61->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE61->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE61->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE61->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE61->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE61->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE61->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE61->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE61->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE61->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE61->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE61->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE61->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE61->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE61->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_02h[61]; //Состояние входов 9-16 БВС1К2

   if (BData & 0x80) {Form1->CB_PCH2_BYTE62->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE62->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE62->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE62->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE62->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE62->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE62->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE62->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_02h[62]; //Команды БУК1

   if (BData & 0x80) {Form1->CB_PCH2_BYTE63->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE63->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE63->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE63->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE63->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE63->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE63->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE63->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[7] = cbUnchecked;}

   BData = BUFF_OTV_KPSN_02h[63]; //Команды БУК2

   if (BData & 0x80) {Form1->CB_PCH2_BYTE64->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE64->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE64->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE64->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE64->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE64->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE64->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE64->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[7] = cbUnchecked;}

   mlBData = BUFF_OTV_KPSN_02h[64]; //Код неисправности 1 (БУК1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY1->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[65]; //Код неисправности 2 (БУК1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY2->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[66]; //Код неисправности 3 (БУК1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY3->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[67]; //Код неисправности 4 (БУК1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY4->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[68]; //Код неисправности 5 (БУК1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY5->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[69]; //Код неисправности 6 (БУК1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY6->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[70]; //Код неисправности 7 (БУК1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY7->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[71]; //Код неисправности 8 (БУК1)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK1_KEY8->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);


   mlBData = BUFF_OTV_KPSN_02h[72]; //Код неисправности 1 (БУК2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY1->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[73]; //Код неисправности 2 (БУК2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY2->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[74]; //Код неисправности 3 (БУК2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY3->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[75]; //Код неисправности 4 (БУК2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY4->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[76]; //Код неисправности 5 (БУК2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY5->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[77]; //Код неисправности 6 (БУК2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY6->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[78]; //Код неисправности 7 (БУК2)
   ValueAnParam = ((unsigned char)mlBData)* 1.0;
   Form1->VLBUK2_KEY7->Caption =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = BUFF_OTV_KPSN_02h[79]; //Код неисправности 8 (БУК2)
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
     Form1->M_OUT_DATA->Lines->Add(StringToHex(BUFF_ZPR_KPSN_01h, dwZPR_KPSN_01h)); //выводим переданную строку в Memo
     Form1->StatusBar1->Panels->Items[1]->Text = "Передано " + IntToStr(dwZPR_KPSN_01h) + " байт" ; //выводим количество переданных байт

     Form1->M_IN_DATA->Lines->Add(StringToHex(BUFF_OTV_KPSN_01h, dwOTV_KPSN_01h)); //выводим принятую строку в Memo
     Form1->StatusBar1->Panels->Items[2]->Text = "Принято " + IntToStr(dwOTV_KPSN_01h) + " байт" ;  //выводим количество принятых байт

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
     Form1->M_OUT_DATA->Lines->Add(StringToHex(BUFF_ZPR_KPSN_02h, dwZPR_KPSN_02h)); //выводим переданную строку в Memo
     Form1->StatusBar1->Panels->Items[1]->Text = "Передано " + IntToStr(dwZPR_KPSN_02h) + " байт" ; //выводим количество переданных байт

     Form1->M_IN_DATA->Lines->Add(StringToHex(BUFF_OTV_KPSN_02h, dwOTV_KPSN_02h)); //выводим принятую строку в Memo
     Form1->StatusBar1->Panels->Items[2]->Text = "Принято " + IntToStr(dwOTV_KPSN_02h) + " байт" ;  //выводим количество принятых байт

     GCRC1=SCalcCRC(BUFF_OTV_KPSN_02h, 78);
     if((BUFF_OTV_KPSN_02h[0]==0x01)&&(BUFF_OTV_KPSN_02h[1]==0x01)&&
        (BUFF_OTV_KPSN_02h[88]==((UCHAR*)(&GCRC1))[0])&&
        (BUFF_OTV_KPSN_02h[89]==((UCHAR*)(&GCRC1))[1])&&(dwOTV_KPSN_02h==90))
      {
          FUNC_VIEW_ANS_KPSN02h();
      }
    }

     Form1->M_IN_DATA->Lines->Add(""); //выводим принятую строку в Memo

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

    Form1->M_OUT_DATA->Lines->Add(StringToHex(OUT_INF_KPA1,dwOUT1)); //выводим переданную строку в Memo
    Form1->StatusBar1->Panels->Items[1]->Text = "Передано " + IntToStr(dwOUT1) + " байт" ; //выводим количество переданных байт

    Form1->M_IN_DATA->Lines->Add(IntToStr(dwIN1) + " байт: " + StringToHex(IN_INF_KPA1,dwIN1)); //выводим принятую строку в Memo
    Form1->M_IN_DATA->Lines->Add(IntToStr(GCRC) + " H: " + CRCh + " L: " + CRCl);
    if (PR_CORRECT == 1) {
       Form1->M_IN_DATA->Lines->Add("true");
    } else {
       Form1->M_IN_DATA->Lines->Add("false");
    }

    Form1->StatusBar1->Panels->Items[2]->Text = "Принято " + IntToStr(dwIN1) + " байт";  //выводим количество принятых байт

    unsigned short int PrINCRC = 0x00; // проверка CRC-кода входящего буфера
    PrINCRC=SCalcCRC(IN_INF_KPA1,20);

*/

     if ((dwOTV_KPSN_01h == 80)||(dwOTV_KPSN_02h == 90)) {
         Form1->SHNETSV->Brush->Color = clGreen;
     } else {
         Form1->SHNETSV->Brush->Color = clRed;
     }       

     //обнуление всех фонарей при нажатии на кнопку "Стоп"
     if (Form1->BStart->Caption == "Старт")
       {
//         memset(IN_INF_KPA1,0,BuffSize1); //обнуляю буфер приема

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
    if (Form1->BStart->Caption ==  "Старт") { break;}

    Sleep (50);

   switch (NCycle)
  {
   case 1:
    {
        BUFF_ZPR_KPSN_01h[0]=0x01; // б1. адрес
        BUFF_ZPR_KPSN_01h[1]=0x01; // б2. команда

        unsigned char ByteDiscrComm = 0x00; //инициализация байта дискретных команд

        if (Form1->CheckListBoxChanel1->Checked[7] == true) {ByteDiscrComm = ByteDiscrComm + 0x01;}
        if (Form1->CheckListBoxChanel1->Checked[6] == true) {ByteDiscrComm = ByteDiscrComm + 0x02;}
        if (Form1->CheckListBoxChanel1->Checked[5] == true) {ByteDiscrComm = ByteDiscrComm + 0x04;}
        if (Form1->CheckListBoxChanel1->Checked[4] == true) {ByteDiscrComm = ByteDiscrComm + 0x08;}

        BUFF_ZPR_KPSN_01h[2] = ByteDiscrComm; // б3. команды СУЭ

        unsigned char ByteAnlgComm = 0x00; //инициализация байта аналоговых команд

        if  (Form1->CBSAVE->Checked == true) {
             BUFF_ZPR_KPSN_01h[3]=  (StrToInt(Form1->E_UST_PROMCONTUR->Text) & 0x00FF) / 1;            // б4. уставка по напряжению в промконтуре, мл.б.
             BUFF_ZPR_KPSN_01h[4]= ((StrToInt(Form1->E_UST_PROMCONTUR->Text) & 0xFF00) >> 8 ) / 1;     // б5. уставка по напряжению в промконтуре, ст.б.

             BUFF_ZPR_KPSN_01h[5]=  (StrToInt(Form1->E_OGR_ZAR_AKB->Text) & 0x00FF) / 1;               // б6. ограничение по напряжению заряда АКБ, мл.б.
             BUFF_ZPR_KPSN_01h[6]= ((StrToInt(Form1->E_OGR_ZAR_AKB->Text) & 0xFF00) >> 8 ) / 1;        // б7. ограничение по напряжению заряда АКБ, ст.б.

             BUFF_ZPR_KPSN_01h[7]=  StrToInt(Form1->E_OGR_PRIR_J_ZAR_AKB->Text) / 1;                   // б8. ограничение по приращению тока заряда АКБ

             BUFF_ZPR_KPSN_01h[8]=  (StrToInt(Form1->E_OGR_J_ZAR_AKB->Text) & 0x00FF) / 1;             // б9. ограничение по току заряда АКБ, мл.б.
             BUFF_ZPR_KPSN_01h[9]= ((StrToInt(Form1->E_OGR_J_ZAR_AKB->Text) & 0xFF00) >> 8 ) / 1;      // б10. ограничение по току заряда АКБ, ст.б.

             BUFF_ZPR_KPSN_01h[10]=  (StrToInt(Form1->E_OGR_J_PROMCONTUR->Text) & 0x00FF) / 1;         // б11. ограничение по току промконтура, мл.б.
             BUFF_ZPR_KPSN_01h[11]= ((StrToInt(Form1->E_OGR_J_PROMCONTUR->Text) & 0xFF00) >> 8 ) / 1;  // б12. ограничение по току промконтура, ст.б.
        }

        GCRC=SCalcCRC(BUFF_ZPR_KPSN_01h, 14);
        BUFF_ZPR_KPSN_01h[14]=((UCHAR*)(&GCRC))[0];
        BUFF_ZPR_KPSN_01h[15]=((UCHAR*)(&GCRC))[1];

        WRITECOM(BUFF_ZPR_KPSN_01h,16);
        count_tx1++;

        GCRC = 0; //после подсчета CRC-кода для запроса делаю обнуление параметра
        
        break;
    }
   case 2:
    {
        BUFF_ZPR_KPSN_02h[0]=0x01; // б1. адрес
        BUFF_ZPR_KPSN_02h[1]=0x02; // б2. команда
        GCRC=SCalcCRC(BUFF_ZPR_KPSN_02h, 2);
        BUFF_ZPR_KPSN_02h[2]=((UCHAR*)(&GCRC))[0];
        BUFF_ZPR_KPSN_02h[3]=((UCHAR*)(&GCRC))[1];

        WRITECOM(BUFF_ZPR_KPSN_02h, 4);
        count_tx2++;

        GCRC = 0; //после подсчета CRC-кода для запроса делаю обнуление параметра

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
   }// закрытие while
}
//---------------------------------------------------------------------------


