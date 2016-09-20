//---------------------------------------------------------------------------

#ifndef profilH
#define profilH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "igrac.h"
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TFormProfil : public TForm
{
__published:	// IDE-managed Components
        TEdit *ed_ime;
        TEdit *ed_prezime;
        TEdit *ed_username;
        TEdit *ed_password;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *l_broj;
        TStringGrid *sg_rezultati;
private:	// User declarations
        Igrac* igrac;
public:		// User declarations
        __fastcall TFormProfil(TComponent* Owner);
        void Set_igrac(Igrac*);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormProfil *FormProfil;
//---------------------------------------------------------------------------
#endif
