//---------------------------------------------------------------------------

#ifndef pomocH
#define pomocH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormPomoc : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TMemo *Memo1;
private:	// User declarations
public:		// User declarations
        __fastcall TFormPomoc(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPomoc *FormPomoc;
//---------------------------------------------------------------------------
#endif
