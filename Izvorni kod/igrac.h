//---------------------------------------------------------------------------

#ifndef igracH
#define igracH
#include <vcl.h>
#include <vector>
//---------------------------------------------------------------------------
using namespace std;
class Igrac
{
        private:
        //static const int MAX_BROJ_REZULTATA=20;
        AnsiString ime, prezime, username, password;
        int brojRezultata;
        vector<int> rezultati;

        public:
        Igrac(AnsiString, AnsiString, AnsiString, AnsiString);
        void dodajRezultat(int rezultat);
        AnsiString Get_ime() { return ime; }
        AnsiString Get_prezime() { return prezime; }
        AnsiString Get_username() { return username; }
        AnsiString Get_password() { return password; }
        int Get_highScore() { return (rezultati.empty() ? 0 : rezultati[0]); }
        int Get_brojRezultata() { return rezultati.size(); }
        int Get_rezultat(int i) { return rezultati[i]; }
        void sacuvaj();
        void foo();
};
#endif
