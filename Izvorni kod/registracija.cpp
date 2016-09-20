//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "registracija.h"
#include "igrac.h"
#include <fstream>
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormRegistracija *FormRegistracija;
//---------------------------------------------------------------------------
__fastcall TFormRegistracija::TFormRegistracija(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormRegistracija::bt_registracijaClick(TObject *Sender)
{
        char imeDatoteke[255];
        strcpy(imeDatoteke,"igraci/");
        strcat(imeDatoteke,ed_username->Text.c_str());
        strcat(imeDatoteke,".txt");

        if (!ed_ime->Text.AnsiCompare(""))
        {
                ShowMessage("Niste unijeli ime!");
                return;
        }
        if (!ed_prezime->Text.AnsiCompare(""))
        {
                ShowMessage("Niste unijeli prezime!");
                return;
        }
        if (!ed_username->Text.AnsiCompare(""))
        {
                ShowMessage("Niste unijeli username!");
                return;
        }
        if (!ed_password->Text.AnsiCompare(""))
        {
                ShowMessage("Niste unijeli password!");
                return;
        }

        ifstream file(imeDatoteke);
        if (!file)
        {
                fstream datoteka(imeDatoteke,ios::out);
                datoteka << ed_password->Text.c_str() << endl;
                datoteka << ed_username->Text.c_str() << endl;
                datoteka << ed_ime->Text.c_str() << endl;
                datoteka << ed_prezime->Text.c_str() << endl;
                datoteka << 0 << endl;
                ShowMessage(AnsiString("Igraè uspješno unesen!"));
                ed_ime->Text="";
                ed_prezime->Text="";
                ed_username->Text="";
                ed_password->Text="";
                datoteka.close();
                Close();
        }
        else
                ShowMessage("Zauzet username!");
}
//---------------------------------------------------------------------------
