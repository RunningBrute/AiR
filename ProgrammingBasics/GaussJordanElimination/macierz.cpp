#include<iostream>
#include<math.h>
#include"../inc/lib.hpp"

using namespace std;
 
/*!
 * Metoda pozwalajaca na umieszczenie wspolczynnikow macierzy w postaci wektorow 
 * do tablicy statycznej.
 *
 * Parametry:
 *     WektorDoMacierzy - Wektor ktory zapisujemy do tablicy
 *      i - licznik pozwalajacy na zapisanie odpowiedniej wartosci wektorow
 *
 * Warunki koncowe:
 *     -
 * Zwracane wartosci:
 *     Metoda zwraca wartosci typu bool. Gdy wszystko wyjdzie zgodnie z planem 
 *     zwracana wartoscia jest true, w przeciwnym wypadku false.
 */
bool Macierz::WczytajDoMacierzy(Wektor WektorDoMacierzy, int i){  
  if (i<4){
	_Wspol[i]=WektorDoMacierzy;
  return true;
  }
  else return false;
}

/*!
 * Metoda umozliwiajaca wyswietlenie macierzy.
 */
void Macierz::WyswietlMacierz(){
  int i=0;
  for (i=0;i<4;++i){
    cout <<"|"<<_Wspol[i].x<<" "<<_Wspol[i].y;
    cout <<" "<<_Wspol[i].z<<" "<<_Wspol[i].w<<"|"<<endl; 
  }
}
