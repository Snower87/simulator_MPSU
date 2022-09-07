//---------------------------------------------------------------------------

#ifndef UCOMPortFuncH
#define UCOMPortFuncH
//---------------------------------------------------------------------------
//Статический расчет контрольной суммы (CRC16)
unsigned int SCalcCRC(unsigned char *BFCRC, unsigned char Index);

unsigned char IN_INF_KPSN_01h[BuffSize];
unsigned char IN_INF_KPSN_02h[BuffSize];
#endif
