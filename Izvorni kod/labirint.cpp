//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("pocetna.cpp", FormGlavna);
USEFORM("pomoc.cpp", FormPomoc);
USEFORM("registracija.cpp", FormRegistracija);
USEFORM("prijava.cpp", FormPrijava);
USEFORM("profil.cpp", FormProfil);
USEFORM("igra.cpp", FormIgra);
USEFORM("high_scores.cpp", FormHighScores);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TFormGlavna), &FormGlavna);
                 Application->CreateForm(__classid(TFormPomoc), &FormPomoc);
                 Application->CreateForm(__classid(TFormRegistracija), &FormRegistracija);
                 Application->CreateForm(__classid(TFormPrijava), &FormPrijava);
                 Application->CreateForm(__classid(TFormProfil), &FormProfil);
                 //Application->CreateForm(__classid(TFormHighScores), &FormHighScores);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
