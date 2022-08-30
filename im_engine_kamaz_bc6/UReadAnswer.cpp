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
