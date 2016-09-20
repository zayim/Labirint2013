//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "profil.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormProfil *FormProfil;
//---------------------------------------------------------------------------
__fastcall TFormProfil::TFormProfil(TComponent* Owner)
        : TForm(Owner)
{
}
void TFormProfil::Set_igrac(Igrac* i)
{
        igrac=i;
        Caption=igrac->Get_ime() + AnsiString(" ") + igrac->Get_prezime() +
        AnsiString(" (High Score: ") + AnsiString(igrac->Get_highScore()) +
        AnsiString(")");

        ed_ime->Text=igrac->Get_ime();
        ed_prezime->Text=igrac->Get_prezime();
        ed_username->Text=igrac->Get_username();
        ed_password->Text=igrac->Get_password();
        l_broj->Caption=AnsiString(igrac->Get_brojRezultata());

        sg_rezultati->RowCount=igrac->Get_brojRezultata()+1;
        sg_rezultati->Cells[0][0]="Redni broj";
        sg_rezultati->Cells[1][0]="Rezultat";

        for (int i=1; i<=igrac->Get_brojRezultata(); i++)
        {
                sg_rezultati->Cells[0][i]=i;
                sg_rezultati->Cells[1][i]=igrac->Get_rezultat(i-1);
        }
}
//---------------------------------------------------------------------------
