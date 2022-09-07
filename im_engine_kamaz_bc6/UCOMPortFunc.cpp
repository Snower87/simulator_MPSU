//---------------------------------------------------------------------------


#pragma hdrstop

#include "UCOMPortFunc.h"
#include "UInterface.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

// Используемые глобальные переменные:
HANDLE hCom=0;    //дескриптор (handle) COM-порта
TDCB lpDCB={0};   //тип структуры для получения и установки основных параметров COM-порта (скорость передачи, битность, четность и т.д...)
COMMTIMEOUTS tis; //структура для получения и установки значений временных параметров COM-порта (тайм-аутов)
DWORD dwRead;     //указатель на переменную, в которой возвращается число действительно прочитанных
DWORD dwWrite;    //или записанных байтов

DWORD SPEED;
DWORD BYTESYZE;
DWORD PARITTY;
DWORD STOPBITS;
DWORD RITO;
DWORD RTTM;
DWORD RTTC;
DWORD WTTM;
DWORD WTTC;

unsigned short int GCRC=0; //переменная для счета CRC-кода

unsigned char StartError = 0x00; //инициализация ошибки при старте программы

#define BuffSize 100 //Константа для задания длины буфера
unsigned char ZPRKPA1[BuffSize] = {0}; // БУФЕР формирующий запрос по первой команде в канале
unsigned char ZPRKPA2[BuffSize] = {0}; //                          по второй команде
unsigned char ZPRKPA3[BuffSize] = {0}; //                          по третьей команде
unsigned char ZPRKPA4[BuffSize] = {0}; //                          по четвертой команде

unsigned char OTVKPA1[BuffSize] = {0}; // БУФЕР формирующий ответ  по первой команде в канале
unsigned char OTVKPA2[BuffSize] = {0}; //                          по второй команде
unsigned char OTVKPA3[BuffSize] = {0}; //                          по третьей команде
unsigned char OTVKPA4[BuffSize] = {0}; //                          по четвертой команде

unsigned char IN_INF_KPA1[BuffSize] = {0}; //                          по четвертой команде
unsigned char OUT_INF_KPA1[BuffSize] = {0}; //                          по четвертой команде

unsigned char IN_INF_KPSN_01h[BuffSize] = {0};
unsigned char IN_INF_KPSN_02h[BuffSize] = {0};

//Переменные с числом реально переданных/принятых бай
DWORD dwZPR1; //переменная со значением реально переданных байтов по первому запросу
DWORD dwZPR2; //                                                  по второму
DWORD dwZPR3; //                                                  по третьему
DWORD dwZPR4; //                                                  по четвертому
DWORD dwZPR5; //                                                  по пятому

DWORD dwIN1; //                                                  по пятому

DWORD dwOTV1; //переменная со значением реально принятых байтов по первому ответу
DWORD dwOTV2; //                                                по второму
DWORD dwOTV3; //                                                по третьему
DWORD dwOTV4; //                                                по четвертому
DWORD dwOTV5; //                                                по пятому

DWORD dwOUT1; //                                                  по пятому

//---------------------------------------------------------------------------
//Функции, используемые при расчете CRC-кода:
unsigned char TRCH[256]=
{
  0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,
  0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,
  0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,
  0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,
  0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,
  0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,
  0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,
  0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,
  0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,
  0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,
  0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,
  0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,
  0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,
  0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,
  0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,
  0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40
};

unsigned char TRCL[256]=
{
  0x00,0xC0,0xC1,0x01,0xC3,0x03,0x02,0xC2,0xC6,0x06,0x07,0xC7,0x05,0xC5,0xC4,0x04,
  0xCC,0x0C,0x0D,0xCD,0x0F,0xCF,0xCE,0x0E,0x0A,0xCA,0xCB,0x0B,0xC9,0x09,0x08,0xC8,
  0xD8,0x18,0x19,0xD9,0x1B,0xDB,0xDA,0x1A,0x1E,0xDE,0xDF,0x1F,0xDD,0x1D,0x1C,0xDC,
  0x14,0xD4,0xD5,0x15,0xD7,0x17,0x16,0xD6,0xD2,0x12,0x13,0xD3,0x11,0xD1,0xD0,0x10,
  0xF0,0x30,0x31,0xF1,0x33,0xF3,0xF2,0x32,0x36,0xF6,0xF7,0x37,0xF5,0x35,0x34,0xF4,
  0x3C,0xFC,0xFD,0x3D,0xFF,0x3F,0x3E,0xFE,0xFA,0x3A,0x3B,0xFB,0x39,0xF9,0xF8,0x38,
  0x28,0xE8,0xE9,0x29,0xEB,0x2B,0x2A,0xEA,0xEE,0x2E,0x2F,0xEF,0x2D,0xED,0xEC,0x2C,
  0xE4,0x24,0x25,0xE5,0x27,0xE7,0xE6,0x26,0x22,0xE2,0xE3,0x23,0xE1,0x21,0x20,0xE0,
  0xA0,0x60,0x61,0xA1,0x63,0xA3,0xA2,0x62,0x66,0xA6,0xA7,0x67,0xA5,0x65,0x64,0xA4,
  0x6C,0xAC,0xAD,0x6D,0xAF,0x6F,0x6E,0xAE,0xAA,0x6A,0x6B,0xAB,0x69,0xA9,0xA8,0x68,
  0x78,0xB8,0xB9,0x79,0xBB,0x7B,0x7A,0xBA,0xBE,0x7E,0x7F,0xBF,0x7D,0xBD,0xBC,0x7C,
  0xB4,0x74,0x75,0xB5,0x77,0xB7,0xB6,0x76,0x72,0xB2,0xB3,0x73,0xB1,0x71,0x70,0xB0,
  0x50,0x90,0x91,0x51,0x93,0x53,0x52,0x92,0x96,0x56,0x57,0x97,0x55,0x95,0x94,0x54,
  0x9C,0x5C,0x5D,0x9D,0x5F,0x9F,0x9E,0x5E,0x5A,0x9A,0x9B,0x5B,0x99,0x59,0x58,0x98,
  0x88,0x48,0x49,0x89,0x4B,0x8B,0x8A,0x4A,0x4E,0x8E,0x8F,0x4F,0x8D,0x4D,0x4C,0x8C,
  0x44,0x84,0x85,0x45,0x87,0x47,0x46,0x86,0x82,0x42,0x43,0x83,0x41,0x81,0x80,0x40
};

//Статический расчет контрольной суммы (CRC16)
unsigned int SCalcCRC(unsigned char *BFCRC, unsigned char Index)
{
  unsigned char y=0;
  unsigned char ix=0;
  unsigned short int CRC=0xFFFF;

  while(ix<Index)
  {
    y=(((unsigned char*)(&CRC))[1])^BFCRC[ix];
    ((unsigned char*)(&CRC))[1]=(((unsigned char*)(&CRC))[0])^TRCH[y];
    ((unsigned char*)(&CRC))[0]=TRCL[y];
    ix++;
  }
  return CRC;
}

//---------------------------------------------------------------------------
//Функция перевода строки в hex-код

AnsiString StringToHex(unsigned char* Stroka, int StrLength)
{
 int length = StrLength;
 AnsiString RES;
 AnsiString R;

 for (int i=0; i < length; i++)
 {
 RES.sprintf("%.2X", Stroka[i]);
 R += RES + "h ";
 }

 return R;
}

//---------------------------------------------------------------------------
//Функции для работы с COM-портом (шесть функций):

//1.Функция обработки ошибок, возникающих при работе с СОМ-портом
void COMERROR(unsigned char ERR)
{
  AnsiString Str="";
  AnsiString StrPovtor="";

  switch(ERR)
  {
    case 1:
      Str = Form1->COMPORT->Text + " занят другим приложением \r\nили его не существует!";
      MessageBox(0,Str.c_str(),"COM-port ERROR...",MB_OK|MB_ICONERROR);
      Form1->StatusBar1->Panels->Items[0]->Text = "1. Неправильно настроен СОМ-порт или 2. Переподключите кабель MOXA к USB-порту";
      //"Ошибка при открытии COM-порта:"
      StrPovtor = "1. Неправильно настроен СОМ-порт или 2. Переподключите кабель MOXA к USB-порту";
//      Form1->MError->Lines->Add("0x01 " + StrPovtor); //выводим полученную ошибку в поле MError
      break;
    case 2:
      Str = "Ошибка при считывании настроек COM-порта!";
//      Form1->MError->Lines->Add("0x02 " + Str); //выводим полученную ошибку в поле MError
      break;
    case 3:
      Str = "Ошибка при установке настроек COM-порта!";
//      Form1->MError->Lines->Add("0x03 " + Str); //выводим полученную ошибку в поле MError
      break;
    case 4:
      Str = "Ошибка при выставлении таймаутов!";
//      Form1->MError->Lines->Add("0x04 " + Str); //выводим полученную ошибку в поле MError
      break;
    case 5:
      Str = "Ошибка при записи данных!";
//      Form1->MError->Lines->Add("0x05 " + Str); //выводим полученную ошибку в поле MError
      break;
    case 6:
      Str = "Ошибка при чтении данных!";
//      Form1->MError->Lines->Add("0x06 " + Str); //выводим полученную ошибку в поле MError
      break;
  }
//      Form1->MError->Lines->Add("-----------------------------------------------"); //

  if (hCom!=0)
  CloseHandle(hCom);
  hCom = 0;

//  StartError = ERR; //запоминание ошибки ERR в StartError
}


//2.Функция открывающая СОМ-порт
// (создает дескриптор (hCom) работы с СОМ-портом)
void OPENCOM()
{
  AnsiString S = "";
  S = Form1->COMPORT->Text ;

  hCom = CreateFile(S.c_str(),GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

  if(hCom==INVALID_HANDLE_VALUE)
    {
     COMERROR(0x01);
     //вывести сообщение в строке состояния для дальнейших действий
     Form1->StatusBar1->Panels->Items[0]->Text = "1. Неправильно настроен СОМ-порт или 2. Переподключите кабель MOXA к USB-порту";
    }
}


//3. Функция закрытия COM-порта
void CLOSECOM()
{
  if (hCom!=0)
  CloseHandle(hCom);
  hCom = 0;
}


//4 Функция настройки СОМ-порта:
//4.1 Функция настройки основных параметров СОМ-порта
//4.2 Функция установки таймаутов СОМ-порта
void SETTINGCOM()
{

  if(!GetCommState(hCom,&lpDCB))
    COMERROR(0x02);
  else
  {
    lpDCB.BaudRate = 57600;
    lpDCB.ByteSize = 8;
    lpDCB.Parity   = NOPARITY;
    lpDCB.StopBits = ONESTOPBIT;
  }

  if(!SetCommState(hCom,&lpDCB))
    COMERROR(0x03);
  else
  {
    //Выставляем таймауты!!!
    tis.ReadIntervalTimeout = 1;            //RITO
    tis.ReadTotalTimeoutMultiplier = 1;     //RTTM
    tis.ReadTotalTimeoutConstant = 1;       //RTTC
    tis.WriteTotalTimeoutMultiplier = 1;    //WTTM
    tis.WriteTotalTimeoutConstant = 1;      //WTTC

    if(!SetCommTimeouts(hCom, &tis))
    {
      COMERROR(0x04); //MessageBox(0,"Cannot set timeouts","ERROR",MB_OK|MB_ICONERROR);
    }

  }

}


//5 Функция записи данных в СОМ-порт
void WRITECOM(UCHAR *BFCOMTX, UCHAR TXLEN)
{
  if(!WriteFile(hCom, BFCOMTX, TXLEN, &dwWrite, NULL))
    COMERROR(0x05);
  else
     {
     dwOUT1 = dwWrite;
     }
}


//6 Функция чтения данных из СОМ-порта
void READCOM(UCHAR *BFCOMRX, UCHAR RXLEN)
{
  if(!ReadFile(hCom, BFCOMRX, RXLEN, &dwRead, NULL))
    COMERROR(0x06);
  else
     {
     dwIN1 = dwRead;
     }
}

//---------------------------------------------------------------------------
//функция очистки передающего/принимающего буфера СОМ-порта
void CLEARBUFCOM()
{
    //очистка передающего буфера СОМ-порта
    memset(OTVKPA1,0,BuffSize);	//очистить программный передающий буфер, чтобы данные не накладывались друг на друга
    PurgeComm(hCom, PURGE_TXCLEAR); //очистить передающий буфер порта
    //для других команд действия аналогичные

    memset(ZPRKPA1,0,BuffSize);
    PurgeComm(hCom, PURGE_RXCLEAR);

    memset(OTVKPA2,0,BuffSize);
    PurgeComm(hCom, PURGE_TXCLEAR);

    memset(ZPRKPA2,0,BuffSize);
    PurgeComm(hCom, PURGE_RXCLEAR);

    memset(OTVKPA3,0,BuffSize);
    PurgeComm(hCom, PURGE_TXCLEAR);

    memset(ZPRKPA3,0,BuffSize);
    PurgeComm(hCom, PURGE_RXCLEAR);

    memset(OTVKPA4,0,BuffSize);
    PurgeComm(hCom, PURGE_TXCLEAR);

    memset(ZPRKPA4,0,BuffSize);
    PurgeComm(hCom, PURGE_RXCLEAR);

//-------------------
    memset(OUT_INF_KPA1,0,BuffSize);
    PurgeComm(hCom, PURGE_TXCLEAR);

    memset(IN_INF_KPA1,0,BuffSize);
    PurgeComm(hCom, PURGE_RXCLEAR);

}
