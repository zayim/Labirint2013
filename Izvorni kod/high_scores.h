//---------------------------------------------------------------------------

#ifndef high_scoresH
#define high_scoresH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <cstring>
#include <fstream>
using namespace std;
//---------------------------------------------------------------------------
class TFormHighScores : public TForm
{
__published:	// IDE-managed Components
        TStringGrid *sg_rezultati;
        TLabel *l_bestNick;
        TLabel *l_bestScore;
private:	// User declarations
public:		// User declarations
        __fastcall TFormHighScores(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormHighScores *FormHighScores;
struct Rezultat1
{
        int rezultat;
        int id;
        string nick;
};
//---------------------------------------------------------------------------
#endif
