//---------------------------------------------------------------------------


#pragma hdrstop
#include <ctime>
#include "polje.h"

Polje::Polje(int x, int y)
{
        this->x=x; this->y=y;
        gore=rand()%2; dole=rand()%2;
        lijevo=rand()%2; desno=rand()%2;
}

//---------------------------------------------------------------------------
void Polje::crtaj(TCanvas *pc)
{
        Graphics::TBitmap *slikaV=0, *slikaH=0;

        slikaV=new Graphics::TBitmap;
        slikaH=new Graphics::TBitmap;

        try
        {
                slikaV->LoadFromFile("slike/poljeV.bmp");
                slikaH->LoadFromFile("slike/poljeH.bmp");

                if (gore) pc->Draw(x*SIRINA_PX + SIRINA_PX/2 - DEBLJINA_PX/2,y*VISINA_PX,slikaV);
                if (dole) pc->Draw(x*SIRINA_PX + SIRINA_PX/2 - DEBLJINA_PX/2,y*VISINA_PX+VISINA_PX/2,slikaV);
                if (lijevo) pc->Draw(x*SIRINA_PX,y*VISINA_PX + VISINA_PX/2 - DEBLJINA_PX/2,slikaH);
                if (desno) pc->Draw(x*SIRINA_PX + SIRINA_PX/2,y*VISINA_PX + VISINA_PX/2 - DEBLJINA_PX/2,slikaH);
	}
	__finally
	{
		delete slikaV;
                delete slikaH;
	};
}

void Novcic::crtaj(TCanvas *pc)
{
        const int SIRINA_NOVCICA_PX=40, VISINA_NOVCICA_PX=40;
        Graphics::TBitmap *slika=0;

        slika=new Graphics::TBitmap;
        try
        {
                slika->LoadFromFile("slike/novcic.bmp");
                pc->Draw(x*SIRINA_PX - SIRINA_NOVCICA_PX/2, y*VISINA_PX - VISINA_NOVCICA_PX/2, slika);
	}
	__finally
	{
		delete slika;
	};
}
#pragma package(smart_init)
