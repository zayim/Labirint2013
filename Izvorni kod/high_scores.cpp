//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "high_scores.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TFormHighScores *FormHighScores;
//---------------------------------------------------------------------------

__fastcall TFormHighScores::TFormHighScores(TComponent* Owner)
        : TForm(Owner)
{
        int brojRezultata;
        fstream datoteka("high_scores.txt",ios::in);

        datoteka >> brojRezultata;
        sg_rezultati->RowCount=brojRezultata+1;
        sg_rezultati->Cells[0][0]="Redni broj";
        sg_rezultati->Cells[1][0]="Nick";
        sg_rezultati->Cells[2][0]="Rezultat";

        if (brojRezultata)
        {
                Rezultat1 tmp;
                datoteka >> tmp.id >> tmp.rezultat >> tmp.nick;
                sg_rezultati->Cells[0][1]=1;
                sg_rezultati->Cells[1][1]=tmp.nick.c_str();
                sg_rezultati->Cells[2][1]=tmp.rezultat;
                l_bestNick->Caption=tmp.nick.c_str();
                l_bestScore->Caption=tmp.rezultat;

                for (int i=2; i<=brojRezultata; i++)
                {
                        datoteka >> tmp.id >> tmp.rezultat >> tmp.nick;
                        sg_rezultati->Cells[0][i]=i;
                        sg_rezultati->Cells[1][i]=tmp.nick.c_str();
                        sg_rezultati->Cells[2][i]=tmp.rezultat;
                }
        }
}
//---------------------------------------------------------------------------
