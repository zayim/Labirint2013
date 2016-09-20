//---------------------------------------------------------------------------

#ifndef registracijaH
#define registracijaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormRegistracija : public TForm
{
__published:	// IDE-managed Components
        TLabel *l_ime;
        TLabel *l_prezime;
        TLabel *l_username;
        TLabel *l_password;
        TEdit *ed_ime;
        TEdit *ed_prezime;
        TEdit *ed_username;
        TEdit *ed_password;
        TButton *bt_registracija;
        void __fastcall bt_registracijaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormRegistracija(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormRegistracija *FormRegistracija;
//---------------------------------------------------------------------------
#endif
