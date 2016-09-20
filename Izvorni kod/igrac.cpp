//---------------------------------------------------------------------------


#pragma hdrstop

#include "igrac.h"
#include <string>
#include <fstream>

//---------------------------------------------------------------------------

Igrac::Igrac (AnsiString im, AnsiString pr, AnsiString un, AnsiString pw) :
ime(im), prezime(pr), username(un), password(pw), brojRezultata(0)
{
}
void Igrac::dodajRezultat(int rezultat)
{
        if (rezultati.empty())
        {
                rezultati.push_back(rezultat);
                brojRezultata=0;
                return;
        }
        vector<int>::iterator it=rezultati.begin();
        while (*it > rezultat && it!=rezultati.end()) it++;
        rezultati.insert(it,rezultat);
        brojRezultata++;
}
void Igrac::foo()
{
        AnsiString ispis="";
        for (int i=0; i<rezultati.size(); i++)
           ispis+=AnsiString(rezultati[i])+"\n";
        ShowMessage(ispis);
}
void Igrac::sacuvaj()
{
        string imeDatoteke = string("igraci/") + string(username.c_str()) + string(".txt");
        fstream datoteka(imeDatoteke.c_str(),ios::out);
        datoteka << password.c_str() << endl << username.c_str() << endl;
        datoteka << ime.c_str() << endl << prezime.c_str() << endl;
        datoteka << rezultati.size() << endl;

        for (int i=0; i<rezultati.size(); i++)
                datoteka << rezultati[i] << endl;

        datoteka.close();
}

#pragma package(smart_init)
