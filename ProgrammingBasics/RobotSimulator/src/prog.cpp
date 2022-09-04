#include<iostream>
#include<cstdlib>
#include<list>
#include"../inc/lib.hpp"
#include "../inc/lacze_do_gnuplota.hpp"

using namespace std;

istream & operator >> (istream & StrmWej, Wektor & W){
  char Znak;
    StrmWej >> Znak;
      if (Znak!='(') {exit(1);}
        StrmWej >> W.x;
        StrmWej >> Znak;
      if (Znak!=','){exit(1);}
        StrmWej >> W.y;
        StrmWej >> Znak;
      if (Znak!=')'){exit(1);}
  return StrmWej;
}

int main(){

  PzG::LaczeDoGNUPlota Lacze;
  Scena S;
  char oper;
  
  Lacze.DodajNazwePliku_PunktyRoznejWielkosci("dat/przeszkody.xyr").ZmienKolor(1);

  Lacze.DodajNazwePliku_PunktyRoznejWielkosci("dat/start.xyr").
      ZmienKolor(3).ZmienEtykiete("Start");

  Lacze.DodajNazwePliku_PunktyRoznejWielkosci("dat/cel.xyr").
      ZmienKolor(4).ZmienEtykiete("Cel");

  Lacze.DodajNazwePliku_PunktyRoznejWielkosci("dat/robot.xyr").
      ZmienKolor(-1).ZmienEtykiete("Robot");

  Lacze.Inicjalizuj();
  Lacze.ZmienTrybRys(PzG::TR_2D);

  Lacze.UstawZakresX(0,55);
  Lacze.UstawZakresY(0,60);
  
  S.WyswietlMenu();
  S.ZainicjalizujStanPoczatkowy();
  
  do{
    cout << endl;
    cout << "(Wyswietl menu: ?) > ";
    cin >> oper;
    S.PrzetwarzajOpcje(oper);
    Lacze.Rysuj();
  }  
  while ( oper != 'k');
  
  return 0;
}
