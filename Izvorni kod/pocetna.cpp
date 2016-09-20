//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "pocetna.h"
#include "pomoc.h"
#include "registracija.h"
#include "prijava.h"
#include "profil.h"
#include "igra.h"
#include "high_scores.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormGlavna *FormGlavna;
//---------------------------------------------------------------------------
__fastcall TFormGlavna::TFormGlavna(TComponent* Owner)
        : TForm(Owner), daLiJePrijavljen(false), igrac(0)
{
        Graphics::TBitmap *slikaPozadine = new Graphics::TBitmap;

	try
        {
                slikaPozadine->LoadFromFile("slike/bg.bmp");
		im_pozadina->Picture->Assign(slikaPozadine);
	}
	__finally
	{
		delete slikaPozadine;
	};

}
void TFormGlavna::init()
{
        FormPrijava->Set_igrac(&igrac);
        FormPrijava->Set_prijavljen(&daLiJePrijavljen);
        FormPrijava->Set_dugme(bt_prijava);
        FormPrijava->Set_labela(l_imePrezime);
}
//---------------------------------------------------------------------------
void __fastcall TFormGlavna::bt_krajClick(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------

void __fastcall TFormGlavna::bt_pomocClick(TObject *Sender)
{
        FormPomoc->Show();        
}
//---------------------------------------------------------------------------


void __fastcall TFormGlavna::bt_registracijaClick(TObject *Sender)
{
        FormRegistracija->Show();        
}
//---------------------------------------------------------------------------

void __fastcall TFormGlavna::bt_prijavaClick(TObject *Sender)
{
        init();
        if (!daLiJePrijavljen) FormPrijava->Visible=true;
        else FormPrijava->bt_prijavaClick(this);
}
//---------------------------------------------------------------------------
void __fastcall TFormGlavna::l_imePrezimeClick(TObject *Sender)
{
        FormProfil->Show();
        FormProfil->Set_igrac(igrac);
}
//---------------------------------------------------------------------------

void __fastcall TFormGlavna::l_imePrezimeMouseEnter(TObject *Sender)
{
        l_imePrezime->Font->Color=clSkyBlue;
}
//---------------------------------------------------------------------------

void __fastcall TFormGlavna::l_imePrezimeMouseLeave(TObject *Sender)
{
        l_imePrezime->Font->Color=clWhite;
}
//---------------------------------------------------------------------------


void __fastcall TFormGlavna::bt_novaIgraClick(TObject *Sender)
{
        FormIgra = new TFormIgra(this);
        FormIgra->Show();
        FormIgra->Set_igrac(igrac);
        FormIgra->Set_glavna(this);
        FormIgra->ukljuciTimer();
        Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TFormGlavna::bt_highScoresClick(TObject *Sender)
{
        FormHighScores = new TFormHighScores(this);
        FormHighScores->Show();
}
//---------------------------------------------------------------------------

