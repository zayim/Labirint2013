//---------------------------------------------------------------------------

#ifndef poljeH
#define poljeH
#include <vcl.h>
//---------------------------------------------------------------------------
class Polje
{
        static const VISINA_PX=50;
        static const SIRINA_PX=50;
        static const DEBLJINA_PX=6;
        bool gore,dole,lijevo,desno;
        int x,y;

        public:
        Polje(bool g, bool d, bool l, bool de, int x, int y) : gore(g), dole(d), lijevo(l), desno(de), x(x), y(y) {}
        Polje(int, int);

        void Set_gore(bool g) { gore=g; }
        void Set_dole(bool d) { dole=d; }
        void Set_lijevo(bool l) { lijevo=l; }
        void Set_desno(bool d) { desno=d; }
        void Set_x(int X) { x=X; }
        void Set_y(int Y) { y=Y; }

        bool Get_gore() { return gore; }
        bool Get_dole() { return dole; }
        bool Get_lijevo() { return lijevo; }
        bool Get_desno() { return desno; }
        int Get_x() { return x; }
        int Get_y() { return y; }

        void crtaj(TCanvas *pc);
};

class Novcic
{
        static const VISINA_PX=50;
        static const SIRINA_PX=50;
        
        int x,y;
        int vrijednost;

        public:
        Novcic(int x, int y, int vr) : x(x), y(y), vrijednost(vr) {}

        bool operator=(const Novcic &n) { return (x==n.x && y==n.y && vrijednost==n.vrijednost); }

        void Set_x(int X) { x=X; }
        void Set_y(int Y) { y=Y; }
        void Set_vrijednost(int vr) { vrijednost=vr; }

        int Get_x() { return x; }
        int Get_y() { return y; }
        int Get_vrijednost() { return vrijednost; }

        void crtaj(TCanvas *pc);
};

class Prekidac
{
        int x,y;
        Polje *prvo, *drugo;

        public:
        Prekidac(int x, int y, Polje *p, Polje* d) : x(x), y(y), prvo(p), drugo(d) {}

        void Set_x(int X) { x=X; }
        void Set_y(int Y) { y=Y; }
        void Set_prvo(Polje *p) { prvo=p; }
        void Set_drugo(Polje *d) { drugo=d; }

        int Get_x() { return x; }
        int Get_y() { return y; }
        Polje* Get_prvo() { return prvo; }
        Polje* Get_drugo() { return drugo; }

        void crtaj(TCanvas *pc);
};
#endif
