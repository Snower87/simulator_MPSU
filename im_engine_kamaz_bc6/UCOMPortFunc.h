//---------------------------------------------------------------------------

#ifndef UCOMPortFuncH
#define UCOMPortFuncH
//---------------------------------------------------------------------------
extern unsigned char NCycle;

//����������� ������ ����������� ����� (CRC16)
unsigned int SCalcCRC(unsigned char *BFCRC, unsigned char Index);

#define BuffSize 100 //��������� ��� ������� ����� ������

extern unsigned char IN_INF_KPSN_01h[BuffSize];
extern unsigned char IN_INF_KPSN_02h[BuffSize];

extern unsigned char BUFF_ZPR_KPSN_01h[BuffSize];
extern unsigned char BUFF_ZPR_KPSN_02h[BuffSize];

extern unsigned char BUFF_OTV_KPSN_01h[BuffSize];
extern unsigned char BUFF_OTV_KPSN_02h[BuffSize];

#endif
