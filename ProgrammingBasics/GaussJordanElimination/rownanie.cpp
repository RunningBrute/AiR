#include<iostream>
#include<math.h>
#include"../inc/lib.hpp"

using namespace std;

/*!
 * Metoda odpowiedzialna za wczytanie wektora wyrazow wolnych 
 * do tablicy 4 - elementowej.
 *
 * Parametry:
 *     WektorWyrWolnych - Wektor, ktory zapisujemy do tablicy
 *
 * Warunki koncowe:
 *     -
 * Zwracane wartosci:
 *     W przypadku gdy uzytkownik podal poprawna ilosc wektorow
 *     wzracana wartoscia jest true, w przeciwnym wypadku false.
 */
bool Rownanie::WczytajWyrazyWolne(Wektor WektorWyrWolnych){
  _WyrazyWolne[0]=WektorWyrWolnych.x;
  _WyrazyWolne[1]=WektorWyrWolnych.y;
  _WyrazyWolne[2]=WektorWyrWolnych.z;
  _WyrazyWolne[3]=WektorWyrWolnych.w;
  
  return true;
}

/*!
 * Metoda odpowiedzialna za zapis wektora do macierzy 
 *
 * Parametry:
 *     WektorDoMacierzy - Wektor, ktory zapisujemy do tablicy
 *
 * Warunki koncowe:
 *     -
 * Zwracane wartosci:
 *     W przypadku gdy uzytkownik podal poprawna ilosc wektorow
 *     wzracana wartoscia jest true, w przeciwnym wypadku false.
 */
bool Rownanie::ZapiszDoMacierzy(Wektor WektorDoMacierzy, int i){
  if (i<4){
	_Macierz.WczytajDoMacierzy(WektorDoMacierzy, i);
  return true;
  }
else return false;	
}

/*!
 * Metoda odpowiedzialna za wyswietlenie wektora wolnego rownania.
 */
void Rownanie::WyswietlWyrazyWolne(){
  cout << endl;
  cout <<"("<<_WyrazyWolne[0]<<","<<_WyrazyWolne[1]<<","<<_WyrazyWolne[2];
  cout <<","<<_WyrazyWolne[3]<<")"<<endl;
}

/*!
 * Metoda umozliwiajaca wyswietlenie wczesniej wyliczonych niewiadomych
 * ukladu rownan liniowych
 */
void Rownanie::WyswietlNiewiadome(){
  cout << endl;
  cout << "Rozwiazanie (x1,x2,x3,x4): ("<<_Niewiadome.x<<","<<_Niewiadome.y;
  cout <<","<<_Niewiadome.z<<","<<_Niewiadome.w<<")"<<endl;
  cout << endl;
}

/*!
 * Metoda wyswietlajaca macierz wspolczynnikow ukladu rownan liniowych
 */
void Rownanie::WyswietlMacierz(){
  _Macierz.WyswietlMacierz();
}

/*!
 * Metoda odpowiedzialna za sprowadzenie macierzy wspolczynnikow ukladu
 * rownan linowych do macierzy gornej trojkatnej.
 *
 * Parametry:
 *     -
 *
 * Warunki koncowe:
 *     Tablica wektorow wspolczynnikow oraz wyrazow wolnych ukladu 
 *     rownan liniowych zostaje zapisana nowymi wartosciami zgodnie
 *     z algorytmem eliminacji Gaussa.
 *     
 * Zwracane wartosci:
 *     W przypadku gdy operacja sie powiedzie zwracana wartoscia jest true 
 *     w przeciwnym wypadku false.
 */
bool Rownanie::Gauss(){
  int i=0;
  for (i=0;i<4;++i){
    if (_Macierz._Wspol[i].x != 0){
      _WyrazyWolne[i]=_WyrazyWolne[i] / _Macierz._Wspol[i].x;
      _Macierz._Wspol[i]=_Macierz._Wspol[i]/_Macierz._Wspol[i].x;
    }
  }
  for (i=1;i<4;++i){
    if (_Macierz._Wspol[i].x != 0){
      _Macierz._Wspol[i]=(_Macierz._Wspol[i] - _Macierz._Wspol[0]);
      _WyrazyWolne[i]=(_WyrazyWolne[i] - _WyrazyWolne[0]);
    }
  }
  for (i=1;i<4;++i){
    if (_Macierz._Wspol[i].y != 0){
      _WyrazyWolne[i]=_WyrazyWolne[i] / _Macierz._Wspol[i].y;
      _Macierz._Wspol[i]=_Macierz._Wspol[i]/_Macierz._Wspol[i].y;
    }
  }
  for (i=2;i<4;++i){
    if (_Macierz._Wspol[i].y != 0){
      _Macierz._Wspol[i]=(_Macierz._Wspol[i] - _Macierz._Wspol[1]);
      _WyrazyWolne[i]=(_WyrazyWolne[i] - _WyrazyWolne[1]);
    }
  }
  for (i=2;i<4;++i){
    if (_Macierz._Wspol[i].z != 0){
      _WyrazyWolne[i]=_WyrazyWolne[i] / _Macierz._Wspol[i].z;
      _Macierz._Wspol[i]=_Macierz._Wspol[i]/_Macierz._Wspol[i].z;
    } 
  }
  for (i=3;i<4;++i){
    if (_Macierz._Wspol[i].z != 0){
      _Macierz._Wspol[i]=(_Macierz._Wspol[i] - _Macierz._Wspol[2]);
      _WyrazyWolne[i]=(_WyrazyWolne[i] - _WyrazyWolne[2]);
    }
  }
  return true;
  }

/*!
 * Metoda odpowiedzialna za rozwiazanie wkladu rownan liniowych. Korzystamy 
 * tutaj z macierzy, ktora zostala wczesniej sprowadzona do macierzy gornej 
 * trojkatnej.
 *
 * Parametry:
 *
 * Warunki koncowe:
 *     Rozwiazania ukladu rownan zapisane sa do wektora _Niewiadome. 
 *
 * Zwracane wartosci:
 *     W przypadku gdy operacja sie powiedzie zwracana wartoscia jest true 
 *     w przeciwnym wypadku false.
 */
bool Rownanie::RozwiazRownanie(){
     
  _Niewiadome.w = _WyrazyWolne[3] / _Macierz._Wspol[3].w;
  
  _Niewiadome.z = _WyrazyWolne[2] - (_Macierz._Wspol[2].w * _Niewiadome.w);
  _Niewiadome.z = _Niewiadome.z / _Macierz._Wspol[2].z;
  
  _Niewiadome.y = _WyrazyWolne[1] - (_Macierz._Wspol[1].z * _Niewiadome.z);
  _Niewiadome.y = _Niewiadome.y - (_Macierz._Wspol[1].w * _Niewiadome.w);
  _Niewiadome.y = _Niewiadome.y / _Macierz._Wspol[1].y;
  
  _Niewiadome.x = _WyrazyWolne[0] - (_Macierz._Wspol[0].y * _Niewiadome.y);
  _Niewiadome.x = _Niewiadome.x - (_Macierz._Wspol[0].z * _Niewiadome.z);
  _Niewiadome.x = _Niewiadome.x - (_Macierz._Wspol[0].w * _Niewiadome.w);
  _Niewiadome.x = _Niewiadome.x / _Macierz._Wspol[0].x;
  
  return true;
}

/*!
 * Metoda odpowiedzialna za wyliczenie normy euklidesowej uk³adu rownan. Dzieki
 * tej operacji mozemy sie dowiedziec z jakim bledem zostaly wykonane 
 * obliczenia.
 *
 * Parametry:
 *     -
 *
 * Warunki koncowe:
 *     Korzystajc z normy euklidesowej w polu _Blad po kilku elementarnych
 *     operacjach otrzymujemy blad obliczen w postaci liczby typu double.
 *     Blad ten jest nastepnie wyswietlany na ekranie. 
 *
 * Zwracane wartosci:
 *     W przypadku gdy operacja sie powiedzie zwracana wartoscia jest true 
 *     w przeciwnym wypadku false.
 */
bool Rownanie::Norma(){
     
  double temp;  
     
  _WektorNormy.x = _Macierz._Wspol[0] & _Niewiadome;
  _WektorNormy.y = _Macierz._Wspol[1] & _Niewiadome; 
  _WektorNormy.z = _Macierz._Wspol[2] & _Niewiadome; 
  _WektorNormy.w = _Macierz._Wspol[3] & _Niewiadome; 
  
  _WektorNormy.x = _WektorNormy.x - _WyrazyWolne[0];
  _WektorNormy.y = _WektorNormy.y - _WyrazyWolne[1];
  _WektorNormy.z = _WektorNormy.z - _WyrazyWolne[2];
  _WektorNormy.w = _WektorNormy.w - _WyrazyWolne[3];
  
  temp = pow(_WektorNormy.x,2)+pow(_WektorNormy.y,2);
  temp = temp + (pow(_WektorNormy.z,2)+pow(_WektorNormy.w,2));
  
  _Blad = sqrt(temp);
  
  cout << endl;
  cout << " Blad obliczen: " << _Blad << endl;
   
  return true; 
}
