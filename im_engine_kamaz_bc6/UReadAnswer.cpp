//---------------------------------------------------------------------------


#pragma hdrstop

#include "UReadAnswer.h"
#include "UInterface.h"
#include "UCOMPortFunc.h"

#define BuffSize1 0x20  //константа для задания длины буфера
extern unsigned char IN_INF_KPA1[BuffSize1];
extern unsigned char OUT_INF_KPA1[BuffSize1];

//---------------------------------------------------------------------------

#pragma package(smart_init)

//функция чтения и отображения принимаемых ответа по командам 01h
void READ_ANSWER ()
{
   unsigned char BData = 0x00; //инициализация байта данных

   unsigned char stBData = 0x00; //инициализация байта данных (ст.б.)
   unsigned char mlBData = 0x00; //инициализация байта данных (мл.б.)

   double ValueAnParam = 0;    //инициализация выводимого значения аналогового параметра
   AnsiString StrValueAnDouble = ""; //строка с выводимым значением аналоговым параметра типа double

   //1. Парсинг посылки от КПСН (команда 01h, ПЧ1)
   mlBData = IN_INF_KPA1[2]; //Fpllout, Вычисленная ФАПЧ частота сети, мл.б. ЦМР = 0,1 Гц, 0..100Гц
   stBData = IN_INF_KPA1[3]; //Fpllout, Вычисленная ФАПЧ частота сети, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH1_BYTE3->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);


   mlBData = IN_INF_KPA1[4]; //Dout RMS, СКЗ коэффициента модуляции ШИМ, мл.б.	ЦМР = 0,1%, 0..200%
   stBData = IN_INF_KPA1[5]; //Dout RMS, СКЗ коэффициента модуляции ШИМ, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH1_BYTE5->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = IN_INF_KPA1[6]; //Im_set, Задание амплитуды тока, мл.б.	ЦМР = 1А, 0..10000А
   stBData = IN_INF_KPA1[7]; //Im_set, Задание амплитуды тока, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE7->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[8]; //Te, Температура радиатора    ЦМР = 0,5°С 0..127,5°С
   ValueAnParam = ((unsigned char)mlBData)* 0.5;
   Form1->EPCH1_BYTE9->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = IN_INF_KPA1[9]; //Tecu, Температура контроллера    ЦМР = 0,5°С 0..127,5°С
   ValueAnParam = ((unsigned char)mlBData)* 0.5;
   Form1->EPCH1_BYTE10->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = IN_INF_KPA1[12]; //Dchop, Коэффициента модуляции ШИМ тормозного ключа, мл.б.   ЦМР = 0,1%,0..100%
   stBData = IN_INF_KPA1[13]; //Dchop, Коэффициента модуляции ШИМ тормозного ключа, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH1_BYTE13->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = IN_INF_KPA1[16]; //Id (Ibr_m), Средний за период ШИМ ток тормозного резистора, мл.б.   ЦМР = 1А, 0..10000А
   stBData = IN_INF_KPA1[17]; //Id (Ibr_m), Средний за период ШИМ ток тормозного резистора, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE17->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[22]; //Uac RMS, СКЗ напряжения со стороны фазы преобразователя, мл.б. ЦМР = 1В, 0..10000В
   stBData = IN_INF_KPA1[23]; //Uac RMS, СКЗ напряжения со стороны фазы преобразователя, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE23->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[24]; //Ia (I2) RMS, СКЗ тока преобразователя, мл.б. ЦМР = 1А, 0..10000А
   stBData = IN_INF_KPA1[25]; //Ia (I2) RMS, СКЗ тока преобразователя, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE25->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[28]; //Udc, Напряжение конденсаторов, мл.б. ЦМР = 1В, 0..10000В
   stBData = IN_INF_KPA1[29]; //Udc, Напряжение конденсаторов, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE29->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = IN_INF_KPA1[30]; //RUNMODE, Текущий режим работы, мл.б.

   if (BData & 0x80) {Form1->CB_PCH1_BYTE31->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE31->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE31->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE31->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE31->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE31->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE31->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE31->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE31->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[31]; //RUNMODE, Текущий режим работы, ст.б.

   if (BData & 0x80) {Form1->CB_PCH1_BYTE32->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE32->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE32->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE32->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE32->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE32->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE32->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE32->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE32->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[32]; //STATUS, Биты ошибок, мл.б.

   if (BData & 0x80) {Form1->CB_PCH1_BYTE33->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE33->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE33->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE33->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE33->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE33->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE33->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE33->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE33->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[33]; //STATUS, Биты ошибок, ст.б.

   if (BData & 0x80) {Form1->CB_PCH1_BYTE34->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE34->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE34->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE34->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE34->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE34->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE34->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE34->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE34->State[7] = cbUnchecked;}

   mlBData = IN_INF_KPA1[38]; //Uac, Мгновенное значение напряжения первичной обмотки (HV) после измерительного трансформатора, мл.б.	ЦМР = 1В,  0..10000В
   stBData = IN_INF_KPA1[39]; //Uac, Мгновенное значение напряжения первичной обмотки (HV) после измерительного трансформатора, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE39->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[40]; //Ia, Мгновенное значение тока Ia, мл.б.	ЦМР = 1А, 0..10000А
   stBData = IN_INF_KPA1[41]; //Ia, Мгновенное значение тока Ia, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE41->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[42]; //Ib, Мгновенное значение тока Ib, мл.б.	ЦМР = 1А, 0..10000А
   stBData = IN_INF_KPA1[43]; //Ib, Мгновенное значение тока Ib, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE43->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = IN_INF_KPA1[46]; //MODESET, Режим работы, мл.б

   if (BData & 0x80) {Form1->CB_PCH1_BYTE47->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE47->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE47->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE47->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE47->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE47->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE47->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE47->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE47->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[47]; //MODESET, Режим работы, ст.б

   if (BData & 0x80) {Form1->CB_PCH1_BYTE48->State[0] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH1_BYTE48->State[1] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH1_BYTE48->State[2] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH1_BYTE48->State[3] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH1_BYTE48->State[4] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH1_BYTE48->State[5] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH1_BYTE48->State[6] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH1_BYTE48->State[7] = cbChecked;} else {Form1->CB_PCH1_BYTE48->State[7] = cbUnchecked;}

   mlBData = IN_INF_KPA1[48]; //Set1, Уставка напряжения Udc, мл.б	ЦМР = 1В, 0..10000 В
   stBData = IN_INF_KPA1[49]; //Set1, Уставка напряжения Udc, ст.б
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE49->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[50]; //Set2, Уставка амплитуды тока вторичной обмотки (Im_set), мл.б.	ЦМР = 1А, 0..10000 А
   stBData = IN_INF_KPA1[51]; //Set2, Уставка амплитуды тока вторичной обмотки (Im_set), ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE51->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[54]; //Im_min, Ограничение выхода регулятора Udc минимум, мл.б.  ЦМР = 1А, 0..10000 А
   stBData = IN_INF_KPA1[55]; //Im_min, Ограничение выхода регулятора Udc минимум, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE55->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[56]; //Im_max, Ограничение выхода регулятора Udc максимум, мл.б.	ЦМР = 1А, 0..10000 А
   stBData = IN_INF_KPA1[57]; //Im_max, Ограничение выхода регулятора Udc максимум, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH1_BYTE57->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = IN_INF_KPA1[58]; //Диагностика связи по М1 (59 байт)

   if (BData & 0x80) {Form1->CB_RPD_BYTE59->State[0] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_RPD_BYTE59->State[1] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_RPD_BYTE59->State[2] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_RPD_BYTE59->State[3] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_RPD_BYTE59->State[4] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_RPD_BYTE59->State[5] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_RPD_BYTE59->State[6] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_RPD_BYTE59->State[7] = cbChecked;} else {Form1->CB_RPD_BYTE59->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[59]; //Диагностика связи по М1 (60 байт)

   if (BData & 0x80) {Form1->CB_RPD_BYTE60->State[0] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_RPD_BYTE60->State[1] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_RPD_BYTE60->State[2] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_RPD_BYTE60->State[3] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_RPD_BYTE60->State[4] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_RPD_BYTE60->State[5] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_RPD_BYTE60->State[6] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_RPD_BYTE60->State[7] = cbChecked;} else {Form1->CB_RPD_BYTE60->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[60]; //Диагностика связи по М1 (61 байт)

   if (BData & 0x80) {Form1->CB_RPD_BYTE61->State[0] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_RPD_BYTE61->State[1] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_RPD_BYTE61->State[2] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_RPD_BYTE61->State[3] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_RPD_BYTE61->State[4] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_RPD_BYTE61->State[5] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_RPD_BYTE61->State[6] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_RPD_BYTE61->State[7] = cbChecked;} else {Form1->CB_RPD_BYTE61->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[61]; //Диагностика связи по М1 (62 байт)

   if (BData & 0x80) {Form1->CB_RPD_BYTE62->State[0] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_RPD_BYTE62->State[1] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_RPD_BYTE62->State[2] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_RPD_BYTE62->State[3] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_RPD_BYTE62->State[4] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_RPD_BYTE62->State[5] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_RPD_BYTE62->State[6] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_RPD_BYTE62->State[7] = cbChecked;} else {Form1->CB_RPD_BYTE62->State[7] = cbUnchecked;}

   //2. Парсинг посылки от КПСН (команда 02h, ПЧ2)
   mlBData = IN_INF_KPA1[2]; //Fpllout, Вычисленная ФАПЧ частота сети, мл.б. ЦМР = 0,1 Гц, 0..100Гц
   stBData = IN_INF_KPA1[3]; //Fpllout, Вычисленная ФАПЧ частота сети, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH2_BYTE3->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = IN_INF_KPA1[4]; //Dout RMS, СКЗ коэффициента модуляции ШИМ, мл.б.	ЦМР = 0,1%, 0..200%
   stBData = IN_INF_KPA1[5]; //Dout RMS, СКЗ коэффициента модуляции ШИМ, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH2_BYTE5->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = IN_INF_KPA1[6]; //Im_set, Задание амплитуды тока, мл.б.	ЦМР = 1А, 0..10000А
   stBData = IN_INF_KPA1[7]; //Im_set, Задание амплитуды тока, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE7->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[8]; //Te, Температура радиатора    ЦМР = 0,5°С 0..127,5°С
   ValueAnParam = ((unsigned char)mlBData)* 0.5;
   Form1->EPCH2_BYTE9->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = IN_INF_KPA1[9]; //Tecu, Температура контроллера    ЦМР = 0,5°С 0..127,5°С
   ValueAnParam = ((unsigned char)mlBData)* 0.5;
   Form1->EPCH2_BYTE10->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = IN_INF_KPA1[12]; //Dchop, Коэффициента модуляции ШИМ тормозного ключа, мл.б.   ЦМР = 0,1%,0..100%
   stBData = IN_INF_KPA1[13]; //Dchop, Коэффициента модуляции ШИМ тормозного ключа, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 0.1;
   Form1->EPCH2_BYTE13->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);

   mlBData = IN_INF_KPA1[16]; //Id (Ibr_m), Средний за период ШИМ ток тормозного резистора, мл.б.   ЦМР = 1А, 0..10000А
   stBData = IN_INF_KPA1[17]; //Id (Ibr_m), Средний за период ШИМ ток тормозного резистора, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE17->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[22]; //Uac RMS, СКЗ напряжения со стороны фазы преобразователя, мл.б. ЦМР = 1В, 0..10000В
   stBData = IN_INF_KPA1[23]; //Uac RMS, СКЗ напряжения со стороны фазы преобразователя, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE23->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[24]; //Ia (I2) RMS, СКЗ тока преобразователя, мл.б. ЦМР = 1А, 0..10000А
   stBData = IN_INF_KPA1[25]; //Ia (I2) RMS, СКЗ тока преобразователя, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE25->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[28]; //Udc, Напряжение конденсаторов, мл.б. ЦМР = 1В, 0..10000В
   stBData = IN_INF_KPA1[29]; //Udc, Напряжение конденсаторов, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE29->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = IN_INF_KPA1[30]; //RUNMODE, Текущий режим работы, мл.б.

   if (BData & 0x80) {Form1->CB_PCH2_BYTE31->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE31->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE31->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE31->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE31->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE31->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE31->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE31->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE31->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[31]; //RUNMODE, Текущий режим работы, ст.б.

   if (BData & 0x80) {Form1->CB_PCH2_BYTE32->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE32->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE32->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE32->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE32->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE32->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE32->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE32->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE32->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[32]; //STATUS, Биты ошибок, мл.б.

   if (BData & 0x80) {Form1->CB_PCH2_BYTE33->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE33->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE33->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE33->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE33->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE33->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE33->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE33->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE33->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[33]; //STATUS, Биты ошибок, ст.б.

   if (BData & 0x80) {Form1->CB_PCH2_BYTE34->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE34->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE34->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE34->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE34->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE34->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE34->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE34->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE34->State[7] = cbUnchecked;}

   mlBData = IN_INF_KPA1[38]; //Uac, Мгновенное значение напряжения первичной обмотки (HV) после измерительного трансформатора, мл.б.	ЦМР = 1В,  0..10000В
   stBData = IN_INF_KPA1[39]; //Uac, Мгновенное значение напряжения первичной обмотки (HV) после измерительного трансформатора, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE39->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[40]; //Ia, Мгновенное значение тока Ia, мл.б.	ЦМР = 1А, 0..10000А
   stBData = IN_INF_KPA1[41]; //Ia, Мгновенное значение тока Ia, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE41->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[42]; //Ib, Мгновенное значение тока Ib, мл.б.	ЦМР = 1А, 0..10000А
   stBData = IN_INF_KPA1[43]; //Ib, Мгновенное значение тока Ib, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE43->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = IN_INF_KPA1[44]; //NPRM, мл.б

   if (BData & 0x80) {Form1->CB_PCH2_BYTE45->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE45->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE45->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE45->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE45->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE45->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE45->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE45->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE45->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[45]; //NPRM, ст.б

   if (BData & 0x80) {Form1->CB_PCH2_BYTE46->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE46->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE46->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE46->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE46->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE46->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE46->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE46->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE46->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[46]; //MODESET, Режим работы, мл.б

   if (BData & 0x80) {Form1->CB_PCH2_BYTE47->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE47->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE47->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE47->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE47->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE47->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE47->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE47->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE47->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[47]; //MODESET, Режим работы, ст.б

   if (BData & 0x80) {Form1->CB_PCH2_BYTE48->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE48->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE48->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE48->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE48->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE48->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE48->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE48->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE48->State[7] = cbUnchecked;}

   mlBData = IN_INF_KPA1[48]; //Set1, Уставка напряжения Udc, мл.б	ЦМР = 1В, 0..10000 В
   stBData = IN_INF_KPA1[49]; //Set1, Уставка напряжения Udc, ст.б
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE49->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[50]; //Set2, Уставка амплитуды тока вторичной обмотки (Im_set), мл.б.	ЦМР = 1А, 0..10000 А
   stBData = IN_INF_KPA1[51]; //Set2, Уставка амплитуды тока вторичной обмотки (Im_set), ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE51->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[54]; //Im_min, Ограничение выхода регулятора Udc минимум, мл.б.  ЦМР = 1А, 0..10000 А
   stBData = IN_INF_KPA1[55]; //Im_min, Ограничение выхода регулятора Udc минимум, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE55->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[56]; //Im_max, Ограничение выхода регулятора Udc максимум, мл.б.	ЦМР = 1А, 0..10000 А
   stBData = IN_INF_KPA1[57]; //Im_max, Ограничение выхода регулятора Udc максимум, ст.б.
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->EPCH2_BYTE57->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = IN_INF_KPA1[58]; //Состояние входов 1-8 БВС1К1

   if (BData & 0x80) {Form1->CB_PCH2_BYTE59->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE59->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE59->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE59->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE59->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE59->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE59->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE59->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[59]; //Состояние входов 9-16 БВС1К1

   if (BData & 0x80) {Form1->CB_PCH2_BYTE60->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE60->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE60->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE60->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE60->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE60->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE60->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE60->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE60->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[60]; //Состояние входов 1-8 БВС1К2

   if (BData & 0x80) {Form1->CB_PCH2_BYTE61->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE61->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE61->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE61->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE61->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE61->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE61->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE61->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE59->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[61]; //Состояние входов 9-16 БВС1К2

   if (BData & 0x80) {Form1->CB_PCH2_BYTE62->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE62->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE62->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE62->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE62->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE62->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE62->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE62->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE62->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[62]; //Команды БУК1

   if (BData & 0x80) {Form1->CB_PCH2_BYTE63->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE63->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE63->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE63->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE63->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE63->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE63->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE63->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE63->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[63]; //Команды БУК2

   if (BData & 0x80) {Form1->CB_PCH2_BYTE64->State[0] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->CB_PCH2_BYTE64->State[1] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->CB_PCH2_BYTE64->State[2] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->CB_PCH2_BYTE64->State[3] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->CB_PCH2_BYTE64->State[4] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->CB_PCH2_BYTE64->State[5] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->CB_PCH2_BYTE64->State[6] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->CB_PCH2_BYTE64->State[7] = cbChecked;} else {Form1->CB_PCH2_BYTE64->State[7] = cbUnchecked;}

/*
   mlBData = IN_INF_KPA1[2]; //Частота вращения ротора ГПЧ-200(СУЭ), мл. б., D_BSPS+0, {ЦМР = 1об/мин, диапазон 0...4000 об/мин}
   stBData = IN_INF_KPA1[3]; //Частота вращения ротора ГПЧ-200(СУЭ), ст. б., D_BSPS+1
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->ED_BSPS0->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   mlBData = IN_INF_KPA1[4]; //Мощность на валу ГПЧ-200(СУЭ), мл. б., D_BSPS+2, {ЦМР = 1кВт, диапазон 0...500кВт}
   stBData = IN_INF_KPA1[5]; //Мощность на валу ГПЧ-200(СУЭ), ст. б., D_BSPS+3
   ValueAnParam = ((unsigned char)stBData*256 + (unsigned char)mlBData)* 1.0;
   Form1->ED_BSPS2->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = IN_INF_KPA1[6]; //Действующее значение тока фазы A(инвертор), D_BSPS+4, {ЦМР = 2А, диапазон 0...500А}
   ValueAnParam = (unsigned char)BData * 2.0;
   Form1->ED_BSPS4->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = IN_INF_KPA1[7]; //Действующее значение тока фазы B(инвертор), D_BSPS+5, {ЦМР = 2А, диапазон 0...500А}
   ValueAnParam = (unsigned char)BData * 2.0;
   Form1->ED_BSPS5->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = IN_INF_KPA1[8]; //Действующее значение тока фазы C(инвертор), D_BSPS+6, {ЦМР = 2А, диапазон 0...500А}
   ValueAnParam = (unsigned char)BData * 2.0;
   Form1->ED_BSPS6->Text =  StrValueAnDouble.FormatFloat("0",ValueAnParam);

   BData = IN_INF_KPA1[9]; //Частота тока Инвертора (СУЭ), D_BSPS+7, {ЦМР = 0,5Гц, диапазон 0...60Гц}
   ValueAnParam = (unsigned char)BData * 0.5;
   Form1->ED_BSPS7->Text =  StrValueAnDouble.FormatFloat("#0.0#",ValueAnParam);


   BData = IN_INF_KPA1[10]; //Диагностика ПЧ-СГ (выпрямитель), D_BSPS+8

   if (BData & 0x80) {Form1->D_BSPS8->State[0] = cbChecked;} else {Form1->D_BSPS8->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->D_BSPS8->State[1] = cbChecked;} else {Form1->D_BSPS8->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->D_BSPS8->State[2] = cbChecked;} else {Form1->D_BSPS8->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->D_BSPS8->State[3] = cbChecked;} else {Form1->D_BSPS8->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->D_BSPS8->State[4] = cbChecked;} else {Form1->D_BSPS8->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->D_BSPS8->State[5] = cbChecked;} else {Form1->D_BSPS8->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->D_BSPS8->State[6] = cbChecked;} else {Form1->D_BSPS8->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->D_BSPS8->State[7] = cbChecked;} else {Form1->D_BSPS8->State[7] = cbUnchecked;}


   BData = IN_INF_KPA1[11]; //Диагностика ГПЧ-200 (выпрямитель), D_BSPS+9

   if (BData & 0x80) {Form1->D_BSPS9->State[0] = cbChecked;} else {Form1->D_BSPS9->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->D_BSPS9->State[1] = cbChecked;} else {Form1->D_BSPS9->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->D_BSPS9->State[2] = cbChecked;} else {Form1->D_BSPS9->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->D_BSPS9->State[3] = cbChecked;} else {Form1->D_BSPS9->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->D_BSPS9->State[4] = cbChecked;} else {Form1->D_BSPS9->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->D_BSPS9->State[5] = cbChecked;} else {Form1->D_BSPS9->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->D_BSPS9->State[6] = cbChecked;} else {Form1->D_BSPS9->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->D_BSPS9->State[7] = cbChecked;} else {Form1->D_BSPS9->State[7] = cbUnchecked;}


   BData = IN_INF_KPA1[12]; //Диагностика ПС-СГ (инвертор), D_BSPS+10

   if (BData & 0x80) {Form1->D_BSPS10->State[0] = cbChecked;} else {Form1->D_BSPS10->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->D_BSPS10->State[1] = cbChecked;} else {Form1->D_BSPS10->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->D_BSPS10->State[2] = cbChecked;} else {Form1->D_BSPS10->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->D_BSPS10->State[3] = cbChecked;} else {Form1->D_BSPS10->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->D_BSPS10->State[4] = cbChecked;} else {Form1->D_BSPS10->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->D_BSPS10->State[5] = cbChecked;} else {Form1->D_BSPS10->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->D_BSPS10->State[6] = cbChecked;} else {Form1->D_BSPS10->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->D_BSPS10->State[7] = cbChecked;} else {Form1->D_BSPS10->State[7] = cbUnchecked;}


   BData = IN_INF_KPA1[13]; //Диагностика ПС-СГ (инвертор) (2), D_BSPS+11

   if (BData & 0x80) {Form1->D_BSPS11->State[0] = cbChecked;} else {Form1->D_BSPS11->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->D_BSPS11->State[1] = cbChecked;} else {Form1->D_BSPS11->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->D_BSPS11->State[2] = cbChecked;} else {Form1->D_BSPS11->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->D_BSPS11->State[3] = cbChecked;} else {Form1->D_BSPS11->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->D_BSPS11->State[4] = cbChecked;} else {Form1->D_BSPS11->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->D_BSPS11->State[5] = cbChecked;} else {Form1->D_BSPS11->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->D_BSPS11->State[6] = cbChecked;} else {Form1->D_BSPS11->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->D_BSPS11->State[7] = cbChecked;} else {Form1->D_BSPS11->State[7] = cbUnchecked;}


   BData = IN_INF_KPA1[14]; //Диагностика Связи с абонентами СУ, D_BSPS+12

   if (BData & 0x80) {Form1->D_BSPS12->State[0] = cbChecked;} else {Form1->D_BSPS12->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->D_BSPS12->State[1] = cbChecked;} else {Form1->D_BSPS12->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->D_BSPS12->State[2] = cbChecked;} else {Form1->D_BSPS12->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->D_BSPS12->State[3] = cbChecked;} else {Form1->D_BSPS12->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->D_BSPS12->State[4] = cbChecked;} else {Form1->D_BSPS12->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->D_BSPS12->State[5] = cbChecked;} else {Form1->D_BSPS12->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->D_BSPS12->State[6] = cbChecked;} else {Form1->D_BSPS12->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->D_BSPS12->State[7] = cbChecked;} else {Form1->D_BSPS12->State[7] = cbUnchecked;}

   
   BData = IN_INF_KPA1[15]; //Диагностика СУ Макета, D_BSPS+13

   if (BData & 0x80) {Form1->D_BSPS13->State[0] = cbChecked;} else {Form1->D_BSPS13->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->D_BSPS13->State[1] = cbChecked;} else {Form1->D_BSPS13->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->D_BSPS13->State[2] = cbChecked;} else {Form1->D_BSPS13->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->D_BSPS13->State[3] = cbChecked;} else {Form1->D_BSPS13->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->D_BSPS13->State[4] = cbChecked;} else {Form1->D_BSPS13->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->D_BSPS13->State[5] = cbChecked;} else {Form1->D_BSPS13->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->D_BSPS13->State[6] = cbChecked;} else {Form1->D_BSPS13->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->D_BSPS13->State[7] = cbChecked;} else {Form1->D_BSPS13->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[16]; //Диагностика СУ Макета (2), D_BSPS+14

   if (BData & 0x80) {Form1->D_BSPS14->State[0] = cbChecked;} else {Form1->D_BSPS14->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->D_BSPS14->State[1] = cbChecked;} else {Form1->D_BSPS14->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->D_BSPS14->State[2] = cbChecked;} else {Form1->D_BSPS14->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->D_BSPS14->State[3] = cbChecked;} else {Form1->D_BSPS14->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->D_BSPS14->State[4] = cbChecked;} else {Form1->D_BSPS14->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->D_BSPS14->State[5] = cbChecked;} else {Form1->D_BSPS14->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->D_BSPS14->State[6] = cbChecked;} else {Form1->D_BSPS14->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->D_BSPS14->State[7] = cbChecked;} else {Form1->D_BSPS14->State[7] = cbUnchecked;}

   BData = IN_INF_KPA1[17]; //Диагностика СУ Макета (3), D_BSPS+15

   if (BData & 0x80) {Form1->D_BSPS15->State[0] = cbChecked;} else {Form1->D_BSPS15->State[0] = cbUnchecked;}
   if (BData & 0x40) {Form1->D_BSPS15->State[1] = cbChecked;} else {Form1->D_BSPS15->State[1] = cbUnchecked;}
   if (BData & 0x20) {Form1->D_BSPS15->State[2] = cbChecked;} else {Form1->D_BSPS15->State[2] = cbUnchecked;}
   if (BData & 0x10) {Form1->D_BSPS15->State[3] = cbChecked;} else {Form1->D_BSPS15->State[3] = cbUnchecked;}
   if (BData & 0x08) {Form1->D_BSPS15->State[4] = cbChecked;} else {Form1->D_BSPS15->State[4] = cbUnchecked;}
   if (BData & 0x04) {Form1->D_BSPS15->State[5] = cbChecked;} else {Form1->D_BSPS15->State[5] = cbUnchecked;}
   if (BData & 0x02) {Form1->D_BSPS15->State[6] = cbChecked;} else {Form1->D_BSPS15->State[6] = cbUnchecked;}
   if (BData & 0x01) {Form1->D_BSPS15->State[7] = cbChecked;} else {Form1->D_BSPS15->State[7] = cbUnchecked;}
*/

   //уходя, выключай свет!
   BData = 0;
   mlBData = 0;
   stBData = 0;
   
} //конец функции READ_ANSWER()
