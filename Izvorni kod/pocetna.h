//---------------------------------------------------------------------------

#ifndef pocetnaH
#define pocetnaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "igrac.h"
//---------------------------------------------------------------------------
class TFormGlavna : public TForm
{
        //friend class Igrac;
__published:	// IDE-managed Components
        TImage *im_pozadina;
        TButton *bt_novaIgra;
        TButton *bt_prijava;
        TButton *bt_registracija;
        TButton *bt_pomoc;
        TButton *bt_kraj;
        TLabel *l_imePrezime;
        TButton *bt_highScores;
        void __fastcall bt_krajClick(TObject *Sender);
        void __fastcall bt_pomocClick(TObject *Sender);
        void __fastcall bt_registracijaClick(TObject *Sender);
        void __fastcall bt_prijavaClick(TObject *Sender);
        void __fastcall l_imePrezimeClick(TObject *Sender);
        void __fastcall l_imePrezimeMouseEnter(TObject *Sender);
        void __fastcall l_imePrezimeMouseLeave(TObject *Sender);
        void __fastcall bt_novaIgraClick(TObject *Sender);
        void __fastcall bt_highScoresClick(TObject *Sender);
private:	// User declarations
        bool daLiJePrijavljen;
        Igrac* igrac;
public:		// User declarations
        __fastcall TFormGlavna(TComponent* Owner);
        void init();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGlavna *FormGlavna;
//---------------------------------------------------------------------------
#endif
