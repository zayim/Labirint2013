//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "prijava.h"
#include "igrac.h"
#include <string>
#include <cstring>
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPrijava *FormPrijava;
using namespace std;
//---------------------------------------------------------------------------
__fastcall TFormPrijava::TFormPrijava(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormPrijava::bt_prijavaClick(TObject *Sender)
{
        if (!(*prijavljen))
        {
                char imeDatoteke[255];
                strcpy(imeDatoteke,"igraci/");
                strcat(imeDatoteke,ed_username->Text.c_str());
                strcat(imeDatoteke,".txt");

                ifstream file(imeDatoteke);
                if (!file)
                        ShowMessage("Pogrešan username!");
                else
                {
                        fstream datoteka(imeDatoteke,ios::in);
                        string pw;
                        datoteka >> pw;
                        if (pw == string(ed_password->Text.c_str()))
                        {
                                string un,im,pr;
                                int brojRezultata;

                                datoteka >> un >> im >> pr >> brojRezultata;
                                delete igrac;
                                *igrac = new Igrac(im.c_str(),pr.c_str(),un.c_str(),pw.c_str());
                                for (int i=0; i<brojRezultata; i++)
                                {
                                        int rezultat;
                                        datoteka >> rezultat;
                                        (*igrac)->dodajRezultat(rezultat);
                                }
                                *prijavljen=true;
                                dugme->Caption="Odjavi se";
                                labela->Caption=(*igrac)->Get_ime() + AnsiString(" ") + (*igrac)->Get_prezime();
                                labela->Visible=true;
                                ShowMessage("Uspješno prijavljen!");
                                ed_username->Text="";
                                ed_password->Text="";
                                Visible=false;
                        }
                        else ShowMessage("Pogrešan password!");
                }
        }
        else
        {
                delete *igrac;
                *igrac=0;
                *prijavljen=false;
                dugme->Caption="Prijavi se";
                labela->Caption="";
                labela->Visible=false;
                ShowMessage("Uspješno odjavljen!");
        }
}
//---------------------------------------------------------------------------
