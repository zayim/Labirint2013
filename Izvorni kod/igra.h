//---------------------------------------------------------------------------

#ifndef igraH
#define igraH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "matrica.h"
#include "igrac.h"
//---------------------------------------------------------------------------
class TFormIgra : public TForm
{
__published:	// IDE-managed Components
        TImage *im_podloga;
        TImage *im_podaci;
        TImage *im_igrac;
        TTimer *tm_timer;
        TLabel *l_vrijemeTekst;
        TLabel *l_vrijeme;
        TShape *Shape1;
        TShape *Shape2;
        TLabel *l_rezultatTekst;
        TLabel *l_rezultat;
        TShape *Shape3;
        TLabel *l_levelTekst;
        TLabel *l_level;
        TImage *im_cilj;
        TShape *Shape4;
        TLabel *l_ime;
        TButton *bt_pauza;
        TEdit *ed_nick;
        TButton *bt_sacuvaj;
        void __fastcall formClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormIgraKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall tm_timerOnTimer(TObject *Sender);
        void __fastcall bt_pauzaClick(TObject *Sender);
        void __fastcall bt_sacuvajClick(TObject *Sender);
private:	// User declarations
        static const VISINA_PX=50;
        static const SIRINA_PX=50;
        static const DEBLJINA_PX=6;
        static const VISINA_IGRACA_PX=40;
        static const SIRINA_IGRACA_PX=40;
        static const BROJ_LEVELA=5;

        Graphics::TBitmap *slikaPodloge;
        Graphics::TBitmap *slikaPodaci;
        Graphics::TBitmap *slikaIgraca;
        Graphics::TBitmap *slikaNovcica;
        Graphics::TBitmap *slikaCilja;
        TForm *glavna;
        Matrica *matrica;
        Igrac *igrac;

        int level;
        int rezultat;
        bool daLiJeLevelGotov;
        bool daLiJeIgraGotova;
        bool pauzirano;

        void update();
public:		// User declarations
        __fastcall TFormIgra(TComponent* Owner);
        void Set_glavna(TForm *g) { glavna=g; }
        void Set_igrac(Igrac*);

        void zavrsiLevel(bool);
        void zavrsiIgru(bool);
        void ukljuciTimer() { tm_timer->Enabled=true; }
        void iskljuciTimer() { tm_timer->Enabled=false; }
};
//---------------------------------------------------------------------------
extern PACKAGE TFormIgra *FormIgra;
//---------------------------------------------------------------------------
#endif
