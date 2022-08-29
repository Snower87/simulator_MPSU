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
        TLabel *Label1;
        TLabel *Label2;
        TMemo *M_IN_DATA;
        TButton *BStart;
        TButton *BExit;
        TLabel *Label3;
        TMemo *M_OUT_DATA;
        TLabel *LCOMPORT;
        TComboBox *COMPORT;
        TCheckListBox *CheckListBoxChanel1;
        TLabel *LPower1;
        TEdit *E_UST_POWER;
        TUpDown *UpDown1;
        TCheckBox *CBSAVE;
        TLabel *LSAVE;
        TLabel *LPower2;
        TGroupBox *GBD_BSPS8;
        TCheckListBox *D_BSPS8;
        TGroupBox *GBD_BSPS9;
        TCheckListBox *D_BSPS9;
        TGroupBox *GBD_BSPS10;
        TCheckListBox *D_BSPS10;
        TGroupBox *GBD_BSPS11;
        TCheckListBox *D_BSPS11;
        TGroupBox *GBD_BSPS12;
        TCheckListBox *D_BSPS12;
        TGroupBox *GBD_BSPS13;
        TCheckListBox *D_BSPS13;
        TPageControl *PCZAPRSVU;
        TTabSheet *ZAPRSVU;
        TPageControl *PCOTVBS;
        TTabSheet *OTVBS;
        TLabel *LSUE;
        TLabel *LD_BSPS0;
        TLabel *LD_BSPS4;
        TEdit *ED_BSPS0;
        TEdit *ED_BSPS4;
        TLabel *LD_BSPS5;
        TLabel *LD_BSPS2;
        TEdit *ED_BSPS5;
        TEdit *ED_BSPS2;
        TLabel *LD_BSPS6;
        TLabel *LD_BSPS7;
        TEdit *ED_BSPS6;
        TEdit *ED_BSPS7;
        TShape *SHNETSV;
        TLabel *LabelDisableCommunication;
        TGroupBox *GBD_BSPS14;
        TCheckListBox *D_BSPS14;
        TGroupBox *GBD_BSPS15;
        TCheckListBox *D_BSPS15;
        void __fastcall BExitClick(TObject *Sender);
        void __fastcall BStartClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall E_UST_POWERChange(TObject *Sender);
        void __fastcall E_UST_POWERKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
