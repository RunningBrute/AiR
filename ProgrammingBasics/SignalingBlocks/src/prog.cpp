#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <list>
#include "../inc/lib.hpp"
#include "../inc/lacze_do_gnuplota.hpp"

using namespace std;

/*
 * Ponizszy kod jest przykladem programu analizujacego zestaw opcji.
 * Przyklad poprawnego wywolania programu:
 * 
 *  ./a.out -i sygnal_wej -o sygnal_wyj  -G -P parametr1 -S -C -D parametr2
 */

int main(int argc, char *argv[]){

 PzG::LaczeDoGNUPlota Lacze;
 System _System;
 extern char *optarg;
 extern int optopt;
 char c;

 while ((c = getopt(argc, argv, "i:o:GP:SCD:")) != -1) {
   switch (c) {
   case 'i':
     _System.PobNazwePlikuWej(optarg);
     break;
   case 'o':
     _System.PobNazwePlikuWyj(optarg);
     Lacze.DodajNazwePliku_Lamana(optarg).
           ZmienKolor(2).ZmienStyl(5).ZmienSzerokosc(2);
     break;
   case 'G':
     _System.DodajBlok(c,0);
     break;
   case 'P':
     _System.DodajBlok(c,atof(optarg));
     break;
   case 'S':
     _System.DodajBlok(c,0);
     break;
   case 'C':
     _System.DodajBlok(c,0);
     break;
   case 'D':
     _System.DodajBlok(c,atof(optarg));
     break;
   case ':':
     cout << "Opcja -" << optopt << " wywolana bez parametru." << endl;
     break;
   case '?':
     cout << "Zly parametr: -" << static_cast<char>(optopt) << endl;
     break;
   }
 }
 _System.Przetwarzaj();

 Lacze.Inicjalizuj();
 Lacze.ZmienTrybRys(PzG::TR_2D);

 Lacze.UstawZakresX(0,10);
 Lacze.UstawZakresY(-2,2);

 Lacze.Rysuj();
 Lacze.RysujDoPliku(PLIK_OBRAZU);

 cout << "Aby zakonczyc nacisnij klawisz k ..." ;
 cin >> c ;

}


