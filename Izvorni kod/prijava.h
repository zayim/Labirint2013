//---------------------------------------------------------------------------

#ifndef prijavaH
#define prijavaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "igrac.h"
//---------------------------------------------------------------------------
class TFormPrijava : public TForm
{
__published:	// IDE-managed Components
        TEdit *ed_username;
        TEdit *ed_password;
        TLabel *l_username;
        TLabel *l_password;
        TButton *bt_prijava;
        void __fastcall bt_prijavaClick(TObject *Sender);
private:	// User declarations
        bool *prijavljen;
        Igrac **igrac;
        TButton *dugme;
        TLabel *labela;
public:		// User declarations
        __fastcall TFormPrijava(TComponent* Owner);
        void Set_igrac(Igrac** i) { igrac=i; }
        void Set_prijavljen(bool* p) { prijavljen=p; }
        void Set_dugme(TButton* d) { dugme=d; }
        void Set_labela(TLabel* l) { labela=l; }
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPrijava *FormPrijava;
//---------------------------------------------------------------------------
#endif
