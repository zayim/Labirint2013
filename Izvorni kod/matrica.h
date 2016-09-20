//---------------------------------------------------------------------------

#ifndef matricaH
#define matricaH
//---------------------------------------------------------------------------
#include "polje.h"
#include <list.h>

class Matrica
{
        static const VISINA=10;
        static const SIRINA=10;

        Polje ***matrica;
        int trenutnoX,trenutnoY;

        bool gotovo;
        int level;
        int vrijeme;
        int rezultat;
        int brojNovcica;
        list<Novcic> novcici;
        int brojPrekidaca;
        list<Prekidac> prekidaci;
        Graphics::TBitmap *pozadina;
        TImage *im_podloga;

        public:
        Matrica(int,Graphics::TBitmap*,TImage*);
        void crtaj();
        bool daLiJeMogucePomjeritiLijevo();
        bool daLiJeMogucePomjeritiDesno();
        bool daLiJeMogucePomjeritiGore();
        bool daLiJeMogucePomjeritiDole();

        void pomjeriLijevo();
        void pomjeriDesno();
        void pomjeriGore();
        void pomjeriDole();

        void provjeriPrekidac();

        void update();

        void oslobodiPolje(int i, int j);

        int Get_trenutnoX() { return trenutnoX; }
        int Get_trenutnoY() { return trenutnoY; }

        int Get_vrijeme() { return vrijeme; }
        void Set_vrijeme(int v) { vrijeme=v; }

        int Get_rezultat() { return rezultat; }
        void Set_rezultat(int v) { rezultat=v; }

        Graphics::TBitmap* Get_pozadina() { return pozadina; }
        void Set_pozadina(Graphics::TBitmap* p) { pozadina=p; }

        bool Get_gotovo() { return gotovo; }
};

#endif
