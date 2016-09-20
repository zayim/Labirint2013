//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "igra.h"
#include <fstream>
#include <cstring>
#include <algorithm>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormIgra *FormIgra;
//---------------------------------------------------------------------------
__fastcall TFormIgra::TFormIgra(TComponent* Owner)
        : TForm(Owner), level(1), daLiJeLevelGotov(false), rezultat(0), pauzirano(false), daLiJeIgraGotova(false)
{
        slikaPodloge=slikaPodaci=0;
        slikaPodloge = new Graphics::TBitmap;
        slikaPodaci = new Graphics::TBitmap;
        slikaIgraca = new Graphics::TBitmap;
        slikaCilja = new Graphics::TBitmap;

        im_igrac->Height=VISINA_IGRACA_PX;
        im_igrac->Width=SIRINA_IGRACA_PX;
        im_igrac->Top=VISINA_PX - VISINA_IGRACA_PX/2;
        im_igrac->Left=SIRINA_PX - SIRINA_IGRACA_PX/2;

        im_cilj->Height=VISINA_IGRACA_PX;
        im_cilj->Width=SIRINA_IGRACA_PX;
        im_cilj->Top=(Matrica::VISINA-1) * VISINA_PX - VISINA_IGRACA_PX/2;
        im_cilj->Left=(Matrica::SIRINA-1) * SIRINA_PX - SIRINA_IGRACA_PX/2;

	try
        {
                slikaPodloge->LoadFromFile("slike/podloga.bmp");
                slikaPodaci->LoadFromFile("slike/podaci.bmp");
                slikaIgraca->LoadFromFile("slike/igrac.bmp");
                slikaCilja->LoadFromFile("slike/cilj.bmp");
		im_podloga->Picture->Assign(slikaPodloge);
                im_podaci->Picture->Assign(slikaPodaci);
                im_igrac->Picture->Assign(slikaIgraca);
                im_cilj->Picture->Assign(slikaCilja);
	}
	__finally
	{
                delete slikaPodaci;
	};

        matrica = new Matrica(level,slikaPodloge,im_podloga);
        matrica->Set_pozadina(slikaPodloge);
        l_vrijeme->Caption=AnsiString(matrica->Get_vrijeme());
        l_rezultat->Caption="0";
        l_level->Caption="1";
        matrica->crtaj();
        l_ime->Caption="Gost";

        ActiveControl = NULL;
}
void TFormIgra::Set_igrac(Igrac* i)
{
        igrac=i;
        if (igrac) l_ime->Caption=igrac->Get_ime() + AnsiString(" ") + igrac->Get_prezime();
}
//---------------------------------------------------------------------------
void __fastcall TFormIgra::formClose(TObject *Sender, TCloseAction &Action)
{
        glavna->Enabled=true;
        tm_timer->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TFormIgra::FormIgraKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (!daLiJeLevelGotov && !pauzirano)
        {
        switch(Key)
        {
                case VK_LEFT:
                //ShowMessage("Lijevo");
                if(matrica->daLiJeMogucePomjeritiLijevo())
                        matrica->pomjeriLijevo();
                break;

                case VK_RIGHT:
                //ShowMessage("Desno");
                if(matrica->daLiJeMogucePomjeritiDesno())
                        matrica->pomjeriDesno();
                break;

                case VK_UP:
                //ShowMessage("Gore");
                if(matrica->daLiJeMogucePomjeritiGore())
                        matrica->pomjeriGore();
                break;

                case VK_DOWN:
                //ShowMessage("Dole");
                if(matrica->daLiJeMogucePomjeritiDole())
                        matrica->pomjeriDole();
                break;

                case VK_SPACE:
                        matrica->provjeriPrekidac();
                break;
        }
        update();
        }
        //ShowMessage(AnsiString("Top: ") + AnsiString(im_igrac->Top) + AnsiString(" ") + AnsiString("Left: ") + AnsiString(im_igrac->Left));
}
//---------------------------------------------------------------------------
void TFormIgra::update()
{
        im_igrac->Top=matrica->Get_trenutnoY()*VISINA_PX - VISINA_IGRACA_PX/2;
        im_igrac->Left=matrica->Get_trenutnoX()*SIRINA_PX - SIRINA_IGRACA_PX/2;
        rezultat+=matrica->Get_rezultat();
        l_rezultat->Caption=AnsiString(rezultat);

        if (matrica->Get_gotovo()) zavrsiLevel(true);
}


void __fastcall TFormIgra::tm_timerOnTimer(TObject *Sender)
{
        if (!pauzirano)
        {
                int vrijeme;
                //if (!l_vrijeme->Caption.AnsiCompare(""))
                vrijeme=l_vrijeme->Caption.ToInt();

                if (vrijeme==1)
                {
                        l_vrijeme->Caption="Kraj";
                        zavrsiLevel(false);
                }
                else
                {
                        matrica->Set_vrijeme(vrijeme-1);
                        l_vrijeme->Caption=AnsiString(matrica->Get_vrijeme());
                }
        }
        ActiveControl=NULL;
}
//---------------------------------------------------------------------------
void TFormIgra::zavrsiLevel(bool uspjeh)
{
        daLiJeLevelGotov=true;
        tm_timer->Enabled=false;
        if (uspjeh)
        {
                int bonus=30;
                switch(level)
                {
                        case 1: bonus-=(25-matrica->Get_vrijeme()); break;
                        case 2: bonus-=(20-matrica->Get_vrijeme()); break;
                        case 3: bonus-=(15-matrica->Get_vrijeme()); break;
                        case 4: bonus-=(15-matrica->Get_vrijeme()); break;
                        case 5: bonus-=(10-matrica->Get_vrijeme()); break;
                }
                bonus*=17*(level+1);

                AnsiString poruka=AnsiString("Upješno ste završili Level ") + AnsiString(level) + AnsiString("! Bravo!");
                poruka+=AnsiString(" Bonus poeni: ") + AnsiString(bonus);

                rezultat+=level*150;
                rezultat+=bonus;
                ShowMessage(poruka);

                level++;
                if (level==BROJ_LEVELA+1) { zavrsiIgru(true); return; }

                l_level->Caption=AnsiString(level);
                l_rezultat->Caption=AnsiString(rezultat);
                delete matrica;

                matrica = new Matrica(level,slikaPodloge,im_podloga);
                matrica->Set_pozadina(slikaPodloge);
                l_vrijeme->Caption=AnsiString(matrica->Get_vrijeme());
                matrica->crtaj();
                tm_timer->Enabled=true;
                daLiJeLevelGotov=false;
                pauzirano=false;
                bt_pauza->Caption="Pauza";
                im_igrac->Top=VISINA_PX - VISINA_IGRACA_PX/2;
                im_igrac->Left=SIRINA_PX - SIRINA_IGRACA_PX/2;

                if (level==BROJ_LEVELA+1) zavrsiIgru(true);
        }
        else
        {
                zavrsiIgru(false);
        }
}
void TFormIgra::zavrsiIgru(bool uspjeh)
{
        AnsiString poruka;

        daLiJeIgraGotova=true;
        daLiJeLevelGotov=true;
        bt_pauza->Caption="Izaði";

        if (uspjeh)
        {
                rezultat+=1000;
                poruka=AnsiString("Èestitamo, uspješno ste završili igru! Bonus: 1000, Rezultat: ") + AnsiString(rezultat);
        }
        else poruka=AnsiString("Kraj igre! Niste došli do kraja. Vaš rezultat: ") + AnsiString(rezultat);

        l_rezultat->Caption=AnsiString(rezultat);

        ShowMessage(poruka);

        if(!igrac) ed_nick->Visible=true;
        bt_sacuvaj->Visible=true;
}


void __fastcall TFormIgra::bt_pauzaClick(TObject *Sender)
{
        if (!daLiJeIgraGotova)
        {
                if (!pauzirano)
                {
                        pauzirano=true;
                        bt_pauza->Caption="Nastavi";
                        tm_timer->Enabled=false;
                        ActiveControl = NULL;
                }
                else
                {
                        pauzirano=false;
                        bt_pauza->Caption="Pauza";
                        tm_timer->Enabled=true;
                        ActiveControl = NULL;
                }
        }
        else
        {
                Close();
        }
}
//---------------------------------------------------------------------------
struct Rezultat
{
        string nick;
        int rezultat;
        int id;
};
bool operator<(Rezultat r1, Rezultat r2) { return (r1.rezultat>r2.rezultat); }
void __fastcall TFormIgra::bt_sacuvajClick(TObject *Sender)
{
        int i=0;
        AnsiString nick;
        if (igrac) nick = igrac->Get_username();
        else nick = ed_nick->Text;

        if (!nick.AnsiCompare(""))
        {
                ShowMessage("Niste unijeli nick!");
                return;
        }

        fstream scores("high_scores.txt",ios::in);
        int brRez;
        Rezultat *rez;
        scores >> brRez; rez = new Rezultat[brRez+1];

        for (i=0; i<brRez; i++)
                scores >> rez[i].id >> rez[i].rezultat >> rez[i].nick;
        scores.close();
        rez[brRez].id=brRez; rez[brRez].rezultat=rezultat;
        rez[brRez].nick=string(nick.c_str());

        sort(rez,rez+brRez+1);

        i=0;
        while (rez[i].id!=brRez && i<=brRez) i++;

        ShowMessage(AnsiString("Vaš ranking: ") + AnsiString(i+1));

        fstream scores2("high_scores.txt",ios::out);
        scores2 << brRez+1 << endl;
        for (i=0; i<=brRez; i++)
                scores2 << rez[i].id << " " <<  rez[i].rezultat << " " << rez[i].nick << endl;
        scores2.close();

        ed_nick->Visible=false;
        bt_sacuvaj->Visible=false;


        if (igrac)
        {
                igrac->dodajRezultat(rezultat);
                igrac->sacuvaj();
        }

}
//---------------------------------------------------------------------------

