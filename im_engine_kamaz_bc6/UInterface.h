//---------------------------------------------------------------------------

#ifndef UInterfaceH
#define UInterfaceH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <CheckLst.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TStatusBar *StatusBar1;
        TMemo *MError;
        TLabel *L_ERROR_DATA;
        TLabel *L_RX_DATA;
        TMemo *M_IN_DATA;
        TButton *BStart;
        TButton *BExit;
        TLabel *L_TX_DATA;
        TMemo *M_OUT_DATA;
        TLabel *LCOMPORT;
        TComboBox *COMPORT;
        TCheckListBox *CheckListBoxChanel1;
        TLabel *LZPRVU_BYTE4_1;
        TEdit *E_UST_PROMCONTUR;
        TUpDown *UpDown1;
        TCheckBox *CBSAVE;
        TLabel *LSAVE;
        TLabel *LZPRVU_BYTE4_2;
        TGroupBox *GB_PCH1_BYTE31;
        TCheckListBox *CB_PCH1_BYTE31;
        TGroupBox *GB_PCH1_BYTE32;
        TCheckListBox *CB_PCH1_BYTE32;
        TPageControl *PCZAPRSVU;
        TTabSheet *ZAPRSVU;
        TPageControl *OTV_KPSN;
        TTabSheet *OTV_KPSN_01h;
        TLabel *LSUE;
        TGroupBox *GB_RPD_BYTE59;
        TCheckListBox *CB_RPD_BYTE59;
        TGroupBox *GB_RPD_BYTE60;
        TCheckListBox *CB_RPD_BYTE60;
        TGroupBox *GB_RPD_BYTE61;
        TCheckListBox *CB_RPD_BYTE61;
        TGroupBox *GB_RPD_BYTE62;
        TCheckListBox *CB_RPD_BYTE62;
        TTabSheet *OTV_KPSN_02h;
        TGroupBox *GB_PCH1_BYTE33;
        TCheckListBox *CB_PCH1_BYTE33;
        TGroupBox *GB_PCH1_BYTE34;
        TCheckListBox *CB_PCH1_BYTE34;
        TGroupBox *GB_PCH1_BYTE47;
        TCheckListBox *CB_PCH1_BYTE47;
        TGroupBox *GB_PCH1_BYTE48;
        TCheckListBox *CB_PCH1_BYTE48;
        TEdit *EPCH1_BYTE3;
        TLabel *LPCH1_BYTE3;
        TEdit *EPCH1_BYTE5;
        TLabel *LPCH1_BYTE5;
        TEdit *EPCH1_BYTE7;
        TLabel *LPCH1_BYTE7;
        TEdit *EPCH1_BYTE9;
        TLabel *LPCH1_BYTE9;
        TEdit *EPCH1_BYTE10;
        TLabel *LPCH1_BYTE10;
        TEdit *EPCH1_BYTE13;
        TLabel *LPCH1_BYTE13;
        TEdit *EPCH1_BYTE17;
        TLabel *LPCH1_BYTE17;
        TEdit *EPCH1_BYTE23;
        TLabel *LPCH1_BYTE23;
        TEdit *EPCH1_BYTE25;
        TLabel *LPCH1_BYTE25;
        TEdit *EPCH1_BYTE29;
        TLabel *LPCH1_BYTE29;
        TEdit *EPCH1_BYTE39;
        TLabel *LPCH1_BYTE39;
        TEdit *EPCH1_BYTE41;
        TLabel *LPCH1_BYTE41;
        TEdit *EPCH1_BYTE43;
        TLabel *LPCH1_BYTE43;
        TTabSheet *DIAGN_PCH_01h;
        TPageControl *PC_DIAGN_M1;
        TTabSheet *TabSheet3;
        TButton *B_SHOW_RXTX;
        TEdit *EPCH1_BYTE49;
        TLabel *LPCH1_BYTE49;
        TEdit *EPCH1_BYTE51;
        TLabel *LPCH1_BYTE51;
        TEdit *EPCH1_BYTE55;
        TLabel *LPCH1_BYTE55;
        TEdit *EPCH1_BYTE57;
        TLabel *LPCH1_BYTE57;
        TShape *SHNETSV;
        TLabel *LabelDisableCommunication;
        TLabel *LZPRVU_BYTE6_1;
        TLabel *LZPRVU_BYTE6_2;
        TEdit *E_OGR_ZAR_AKB;
        TUpDown *UpDown2;
        TLabel *LZPRVU_BYTE8_1;
        TLabel *LZPRVU_BYTE8_2;
        TEdit *E_OGR_PRIR_J_ZAR_AKB;
        TUpDown *UpDown3;
        TLabel *LZPRVU_BYTE9_1;
        TLabel *LZPRVU_BYTE9_2;
        TEdit *E_OGR_J_ZAR_AKB;
        TUpDown *UpDown4;
        TLabel *LZPRVU_BYTE11_1;
        TLabel *LZPRVU_BYTE11_2;
        TEdit *E_OGR_J_PROMCONTUR;
        TUpDown *UpDown5;
        TTabSheet *DIAGN_PCH_02h;
        TEdit *EPCH2_BYTE49;
        TLabel *LPCH2_BYTE49;
        TEdit *EPCH2_BYTE51;
        TLabel *LPCH2_BYTE51;
        TEdit *EPCH2_BYTE55;
        TLabel *LPCH2_BYTE55;
        TEdit *EPCH2_BYTE57;
        TLabel *LPCH2_BYTE57;
        TGroupBox *GB_PCH2_BYTE48;
        TCheckListBox *CB_PCH2_BYTE48;
        TGroupBox *GB_PCH2_BYTE47;
        TCheckListBox *CB_PCH2_BYTE47;
        TEdit *EPCH2_BYTE3;
        TLabel *LPCH2_BYTE3;
        TEdit *EPCH2_BYTE5;
        TLabel *LPCH2_BYTE5;
        TEdit *EPCH2_BYTE7;
        TLabel *LPCH2_BYTE7;
        TEdit *EPCH2_BYTE9;
        TLabel *LPCH2_BYTE9;
        TEdit *EPCH2_BYTE10;
        TLabel *LPCH2_BYTE10;
        TEdit *EPCH2_BYTE13;
        TLabel *LPCH2_BYTE13;
        TEdit *EPCH2_BYTE17;
        TLabel *LPCH2_BYTE17;
        TEdit *EPCH2_BYTE23;
        TLabel *LPCH2_BYTE23;
        TEdit *EPCH2_BYTE25;
        TLabel *LPCH2_BYTE25;
        TEdit *EPCH2_BYTE29;
        TLabel *LPCH2_BYTE29;
        TEdit *EPCH2_BYTE39;
        TLabel *LPCH2_BYTE39;
        TEdit *EPCH2_BYTE41;
        TLabel *LPCH2_BYTE41;
        TEdit *EPCH2_BYTE43;
        TLabel *LPCH2_BYTE43;
        TGroupBox *GroupBox1;
        TCheckListBox *CheckListBox2;
        TGroupBox *GroupBox2;
        TCheckListBox *CheckListBox3;
        TGroupBox *GroupBox3;
        TCheckListBox *CheckListBox4;
        TGroupBox *GroupBox4;
        TCheckListBox *CheckListBox5;
        TGroupBox *GB_PCH2_BYTE45;
        TCheckListBox *CB_PCH2_BYTE45;
        TGroupBox *GB_PCH2_BYTE46;
        TCheckListBox *CB_PCH2_BYTE46;
        void __fastcall BExitClick(TObject *Sender);
        void __fastcall BStartClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall E_UST_PROMCONTURChange(TObject *Sender);
        void __fastcall E_UST_PROMCONTURKeyPress(TObject *Sender, char &Key);
        void __fastcall B_SHOW_RXTXClick(TObject *Sender);
        void __fastcall E_OGR_PRIR_J_ZAR_AKBChange(TObject *Sender);
        void __fastcall E_OGR_J_ZAR_AKBChange(TObject *Sender);
        void __fastcall E_OGR_J_PROMCONTURChange(TObject *Sender);
        void __fastcall E_OGR_ZAR_AKBChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
