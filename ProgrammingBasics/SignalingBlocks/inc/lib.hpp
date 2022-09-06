#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>

#define PLIK_OBRAZU "dat/obraz.png"
#define PLIK_DANYCH_TEMP "dat/syg_temp.syg"

using namespace std;


//=========================================================
struct BlokPodstawowy{

    BlokPodstawowy(){}
    virtual float Przetwarzaj(float yy){ return yy;}
    virtual const char* Nazwa() const { return "BlokPodstawowy"; }
};

//=========================================================
struct BlokPotegujacy: public BlokPodstawowy{
    
    BlokPotegujacy(){}
    float Przetwarzaj(float yy){ return yy*yy; }
    const char* Nazwa() const { return "BlokPotegujacy"; }
};

//=========================================================
struct BlokPrzesuwajacy: public BlokPodstawowy{
  
    BlokPrzesuwajacy(int a){ _WartPrzes = a;}
    float Przetwarzaj(float yy){ return yy + _WartPrzes; }
    const char* Nazwa() const { return "BlokPrzesuwajacy"; }

  private:

    float _WartPrzes;
};

//=========================================================
struct BlokProstujacy: public BlokPodstawowy{
    
    BlokProstujacy(){}
    float Przetwarzaj(float yy);
    const char* Nazwa() const { return "BlokProstujacy"; }
};

//=========================================================
struct BlokCalkujacy: public BlokPodstawowy{

    BlokCalkujacy(){}
    float Przetwarzaj(float yy){ return yy; }
    const char* Nazwa() const { return "BlokCalkujacy"; }
};

//=========================================================
struct BlokDyskryminujacy: public BlokPodstawowy{

    BlokDyskryminujacy(int a){ _WartDysk = a; }
    float Przetwarzaj(float yy);
    const char* Nazwa() const { return "BlokDyskryminujacy"; }

  private:

    float _WartDysk;
};

typedef list<BlokPodstawowy*> ListaBlokow;

//=========================================================
struct System{

    bool DodajBlok(char c, float a);
    bool Przetwarzaj();
    void PobNazwePlikuWej(char *plik_we){ _PlikWe = plik_we; }
    void PobNazwePlikuWyj(char *plik_wy){ _PlikWy = plik_wy; }

  private:

    char *_PlikWe;
    char *_PlikWy;
    ListaBlokow _ListaBlokow;
};

