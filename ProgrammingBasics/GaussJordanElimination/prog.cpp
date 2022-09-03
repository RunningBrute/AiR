#include<iostream>
#include<math.h>
#include"../inc/lib.hpp"

using namespace std;

/*!
 * Umozliwia wczytanie wektora z wejscia standardowego.
 * 
 * Parametry:
 *   StrmWej - strumien wejsciowy, z ktorego ma byc wczytany
 *       wektor.
 *   Wektor - do niego ma byc wczytany wektor ze strumienia
 *       wejsciowego.
 *
 * Warunki koncowe:
 *   Wektor - zawiera wczytany wektor pod waunkiem ze
 *       zostal odczytany w postaci (x,y,z,w).
 *       W przypadku przeciwnym dzialanie programu zostaje
 *       przerwane z komunikatem bledu.
 *
 * Zwracane wartosci:
 *   Referencja do strumienia, na ktorym wykonana zostala
 *   operacja odczytu wektora.
 */
istream & operator >> (istream & StrmWej, Wektor & W){
  char Znak;
    StrmWej >> Znak;
      if (Znak!='|') {exit(1);}
        StrmWej >> W.x;
        StrmWej >> Znak;
      if (Znak!=','){exit(1);}
        StrmWej >> W.y;
        StrmWej >> Znak;
      if (Znak!=','){exit(1);}
        StrmWej >> W.z;
        StrmWej >> Znak;
      if (Znak!=','){exit(1);}
        StrmWej >> W.w;
        StrmWej >> Znak;
      if (Znak!='|'){exit(1);}
  return StrmWej;
}

int main(){
  
  Wektor W;
  Rownanie R;
  int i=0;
  
// Wczytanie 4 wektorow wspolczynnikow ukladu rownan linowych  
  for (i=0;i<4;++i) {
    cin >> W;
    R.ZapiszDoMacierzy(W,i);
  }
  //cin >> W;
  //R.WczytajWyrazyWolne(W);  // Wczytanie wektora wyrazow wolnych
  
  cout << endl;
  
  R.Gauss();              
  R.RozwiazRownanie();
  R.WyswietlMacierz();
  R.WyswietlWyrazyWolne();
  R.WyswietlNiewiadome();
  R.Norma();
  
  return 0;
} 
