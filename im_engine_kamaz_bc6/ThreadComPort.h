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
protected:
        void __fastcall Execute();
public:
        __fastcall ThreadComPort(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
