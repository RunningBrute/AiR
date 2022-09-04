#include<iostream>
#include<cmath>
#include<list>

#define PLIK_SCIEZKI   "dat/sciezka.xy"
#define PLIK_ROBOTA    "dat/robot.xyr"
#define PLIK_STARTU    "dat/start.xyr"
#define PLIK_CELU      "dat/cel.xyr"
#define PLIK_PRZESZKOD "dat/przeszkody.xyr"

using namespace std;

//---------------------------------Wektor--------------------------------------
struct Wektor{

   Wektor(){x = y = 0;}
   Wektor operator + (Wektor Skladnik) const;
   Wektor operator - (const Wektor & Odjemnik) const;
   Wektor operator * (const float & Mnoznik) const;
   Wektor operator / (const float & Dzielnik) const;
   float DlWektora() const { return sqrt(x*x + y*y); }
   float DlWektora_2() const { return x*x + y*y; }
   void PokazWektor() const;
   
   float x,y;

};
//---------------------------------Wektor--------------------------------------
//=============================================================================

istream & operator >> (istream & StrmWej, Wektor & W);

typedef std::list<float> ScRobota;

//--------------------------------Sciezka--------------------------------------
struct Sciezka{
   
   Sciezka(){_DlPrzem = _JedIlKrok = _WykIlKrok = 0;}
   bool ZmDlPrzem();
   bool ZmJedIlKrok();
   void DodajIlWykKrok() { ++_WykIlKrok; }
   float ZwracajDlPrzem() const { return _DlPrzem; }
   int ZwracajJedIlKrok() const { return _JedIlKrok; }
   int ZwracajWykIlKrok() const { return _WykIlKrok; }
   
 private:
   
   ScRobota _Sciezka;
   float    _DlPrzem;
   int      _JedIlKrok;
   int      _WykIlKrok;
   
}; 
//--------------------------------Sciezka--------------------------------------
//=============================================================================

//---------------------------------Obiekt--------------------------------------
struct Obiekt{

   Obiekt(){_Rozm = _Ladunek = 0;}
   Wektor ZwracajWspol() const { return _Wspol; } 
   float ZwracajRozm() const { return _Rozm; }
   float ZwracajLadunek() const { return _Ladunek; }
   float ZwracajDlWek() const { return _Wspol.DlWektora(); }
   float ZwracajDlWek_2() const { return _Wspol.DlWektora_2(); }
   bool PrzypiszWspol(const Wektor & Wspol);
   bool WczytajWspol();
   bool WczytajRozm();
   bool WczytajLadunek();
   void PokazWspol() const;
   void PokazRozm() const;
   void PokazLadunek() const;
 
 //private:
  
   Wektor  _Wspol;
   float   _Rozm;
   float   _Ladunek;

};
//---------------------------------Obiekt--------------------------------------
//=============================================================================

typedef std::list<Obiekt> ListaPrzeszkod;

//----------------------------------Scena--------------------------------------
struct Scena{

   Wektor WyliczWekSily();
   float WyliczWartSily();
   void ZainicjalizujStanPoczatkowy();
   Wektor WyliczWersorSily() { return (WyliczWekSily()/WyliczWartSily()); }
   Wektor WyliczWekPrzesRobota();
   bool PrzemiescRobota();
   bool StartAlgorytmu();
   void WyswietlMenu() const;
   bool ZmWspolStartu();
   bool ZmWspolCelu();
   bool UsunPrzeszkode();
   bool WstawPrzeszkode();
   bool EdytujPrzeszkode();
   bool ZmLadunekCelu();
   bool ZmDlugoscPrzem();
   bool ZmIloscKrokow();
   void WyswietlStan();
   void WyswietlWspolStartu() const;
   void WyswietlWspolRobota() const;
   void WyswietlWspolCelu() const;
   void WyswietlLadunekCelu() const;
   void WyswietlPolPrzeszkody() const;
   void WyswietlRozmPrzeszkody() const;
   void WyswietlIloscKrok() const;
   void WyswietlDlPojPrzem() const;
   void WyswietlIlWykKrok() const;
   void PrzetwarzajOpcje(char & Oper);

 private:

   Obiekt          _Cel;
   Obiekt          _Start;
   Obiekt          _Robot;
   Sciezka         _ScRob;
   ListaPrzeszkod  _Lst;

};
//----------------------------------Scena--------------------------------------
//=============================================================================
