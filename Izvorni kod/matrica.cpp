//---------------------------------------------------------------------------


#pragma hdrstop
#include <ctime>
#include <fstream>
#include <iostream>
#include "matrica.h"

//---------------------------------------------------------------------------
Matrica::Matrica(int level, Graphics::TBitmap* p, TImage* t) : level(level), trenutnoX(1), trenutnoY(1), im_podloga(t), pozadina(p), gotovo(false)
{
    srand(time(0));
    matrica=new Polje**[VISINA];

    for (int i=0; i<VISINA; i++)
        matrica[i]=new Polje*[SIRINA];

    for (int i=1; i<SIRINA-1; i++)
    {
        matrica[0][i]=new Polje(false,false,true,true,i,0);
        matrica[VISINA-1][i]=new Polje(false,false,true,true,i,VISINA-1);
    }
    for (int i=1; i<SIRINA-1; i++)
    {
        matrica[i][0]=new Polje(true,true,false,false,0,i);
        matrica[i][SIRINA-1]=new Polje(true,true,false,false,SIRINA-1,i);
    }

    matrica[0][0]=new Polje(false,true,false,true,0,0);
    matrica[0][SIRINA-1]=new Polje(false,true,true,false,SIRINA-1,0);
    matrica[VISINA-1][0]=new Polje(true,false,false,true,0,VISINA-1);
    matrica[VISINA-1][SIRINA-1]=new Polje(true,false,true,false,SIRINA-1,VISINA-1);
    matrica[1][1]=new Polje(false,false,false,false,1,1);

    for (int i=1; i<VISINA-1; i++)
        for (int j=1; j<SIRINA-1; j++)
                {
                        bool gore=matrica[i-1][j]->Get_dole();
                        bool lijevo=matrica[i][j-1]->Get_desno();
                        bool dole=rand()%2;
                        bool desno=rand()%2;
                        matrica[i][j]=new Polje(gore,dole,lijevo,desno,j,i);
                }
    for (int i=1; i<SIRINA; i++)
        matrica[VISINA-1][i]->Set_gore(matrica[VISINA-2][i]->Get_dole());
    for (int i=1; i<VISINA; i++)
        matrica[i][SIRINA-1]->Set_lijevo(matrica[i][SIRINA-2]->Get_desno());

    oslobodiPolje(VISINA-2,SIRINA-2); oslobodiPolje(VISINA-3,SIRINA-2);
    oslobodiPolje(VISINA-2,SIRINA-3); oslobodiPolje(VISINA-3,SIRINA-3);

    int ocistiI=4+rand()%3;
    int ocistiJ=2+rand()%3;
    oslobodiPolje(ocistiI,ocistiJ);

    ocistiI=2+rand()%3;
    ocistiJ=4+rand()%3;
    oslobodiPolje(ocistiI,ocistiJ);

    ocistiI=5+rand()%3;
    ocistiJ=5+rand()%3;
    oslobodiPolje(ocistiI,ocistiJ);

    ocistiI=VISINA-2-rand()%2;
    ocistiJ=1+rand()%2;
    oslobodiPolje(ocistiI,ocistiJ);

    ocistiI=1+rand()%2;
    ocistiJ=SIRINA-2-rand()%2;
    oslobodiPolje(ocistiI,ocistiJ);

    oslobodiPolje(6,4);

    fstream zayim("matrica.txt",ios::out);
    for (int i=0; i<VISINA; i++)
    {
        for (int j=0; j<SIRINA; j++)
                zayim << "----";
        zayim << endl;

        for (int j=0; j<SIRINA; j++)
                zayim << "| " << (matrica[i][j]->Get_gore() ? "*" : " ") << " ";
        zayim << endl;
        for (int j=0; j<SIRINA; j++)
                zayim << (matrica[i][j]->Get_lijevo() ? "|*" : "| ") << "*" << (matrica[i][j]->Get_desno() ? "*" : " ");
        zayim << endl;
        for (int j=0; j<SIRINA; j++)
                zayim << "| " << (matrica[i][j]->Get_dole() ? "*" : " ") << " ";
        zayim << endl;

    }
    zayim.close();

    switch(level)
    {
        case 1:
        vrijeme=25; break;

        case 2:
        vrijeme=20; break;

        case 3:
        vrijeme=15; break;

        case 4:
        vrijeme=15; break;

        case 5:
        vrijeme=10; break;

        default:
        vrijeme=30; break;
    }
    brojNovcica=rand()%(10);
    for (int i=0; i<brojNovcica; i++)
    {
        int posX=1+rand()%(SIRINA-2);
        int posY=1+rand()%(VISINA-2);
        int vr=(1+rand()%10)*10;
        novcici.push_back(Novcic(posX,posY,vr));
    }
}
void Matrica::crtaj(/*TCanvas *pc*/)
{
        TCanvas *pc=im_podloga->Canvas;
        pc->Draw(0,0,pozadina);
        for (int i=0; i<VISINA; i++)
                for (int j=0; j<SIRINA; j++)
                        matrica[i][j]->crtaj(pc);

        for (list<Novcic>::iterator it=novcici.begin(); it!=novcici.end(); it++)
                it->crtaj(pc);

}
bool Matrica::daLiJeMogucePomjeritiLijevo()
{
        return (trenutnoX>1 && !matrica[trenutnoY][trenutnoX-1]->Get_gore());
}
bool Matrica::daLiJeMogucePomjeritiDesno()
{
        return (trenutnoX<SIRINA-1 && !matrica[trenutnoY][trenutnoX]->Get_gore());
}
bool Matrica::daLiJeMogucePomjeritiGore()
{
        return (trenutnoY>1 && !matrica[trenutnoY-1][trenutnoX]->Get_lijevo());
}
bool Matrica::daLiJeMogucePomjeritiDole()
{
        return (trenutnoY<VISINA-1 && !matrica[trenutnoY][trenutnoX]->Get_lijevo());
}

void Matrica::pomjeriLijevo()
{
        trenutnoX--;
        update();
}
void Matrica::pomjeriDesno()
{
        trenutnoX++;
        update();
}
void Matrica::pomjeriGore()
{
        trenutnoY--;
        update();
}
void Matrica::pomjeriDole()
{
        trenutnoY++;
        update();
}
void Matrica::provjeriPrekidac()
{
        //ShowMessage("Prekidaè!");
}
void Matrica::update()
{
        rezultat=0;
        for (list<Novcic>::iterator it=novcici.begin(); it!=novcici.end(); it++)
                if (it->Get_x()==trenutnoX && it->Get_y()==trenutnoY)
                {
                        rezultat=it->Get_vrijednost();
                        novcici.erase(it);
                        crtaj();
                        break;
                }

        if (trenutnoX==SIRINA-2 && trenutnoY==VISINA-1 && !matrica[trenutnoY][trenutnoX]->Get_gore())
                gotovo=true;
        else if(trenutnoX==SIRINA-1 && trenutnoY==VISINA-2 && !matrica[trenutnoY][trenutnoX]->Get_lijevo())
                gotovo=true;
}
void Matrica::oslobodiPolje(int i, int j)
{
        matrica[i][j]->Set_desno(false); matrica[i][j]->Set_dole(false);
        matrica[i][j]->Set_gore(false); matrica[i][j]->Set_lijevo(false);

        matrica[i-1][j]->Set_dole(false);
        matrica[i][j-1]->Set_desno(false);
        matrica[i+1][j]->Set_gore(false);
        matrica[i][j+1]->Set_lijevo(false);
};
#pragma package(smart_init)
