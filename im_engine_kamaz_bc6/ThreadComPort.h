//---------------------------------------------------------------------------

#ifndef ThreadComPortH
#define ThreadComPortH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class ThreadComPort : public TThread
{            
private:
        void __fastcall Printing();
        void __fastcall READ_ANSWER2();
        void __fastcall pb();
protected:
        void __fastcall Execute();
public:
        __fastcall ThreadComPort(bool CreateSuspended);
};
//---------------------------------------------------------------------------
extern unsigned char NCycle;
#endif
