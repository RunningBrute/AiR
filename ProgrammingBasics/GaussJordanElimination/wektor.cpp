#include<iostream>
#include<math.h>
#include"../inc/lib.hpp"

using namespace std;

/* 
 * Realizuje iloczyn skalarny 2 wektorow.
 *
 * Parametry:
 *   Mnoznik - wektor do pomnozenia
 *
 * Zwracana wartosc:
 *   Wynik operacji mnozenia skalarnego, ktora zdefiniowania jest
 *   bezposrednio w przeciazenie operatora '&'. Zmienna Skalar zwraca
 *   powstala liczbe bedaca skalarem.
 */
double Wektor::operator & (const Wektor & Mnoznik){
      double Skalar;
      Skalar = x*Mnoznik.x + y*Mnoznik.y + z*Mnoznik.z + w*Mnoznik.w;
      return Skalar;       
}

/* 
 * Realizuje dzielenie wektora przez liczbe.
 *
 * Parametry:
 *   Dzielnik - liczba przez ktora dzielimy wektor
 *
 * Zwracana wartosc:
 *   Wynik operacji dzilenia, ktora zdefiniowania jest
 *   bezposrednio w przeciazenie operatora '/'. Zmienna 
 *   Wektor_tmp zawiera wektor powstaly po operacji dzielenia.
 */
Wektor Wektor::operator / (const double & Dzielnik){
      Wektor Wektor_tmp;
      Wektor_tmp.x = x / Dzielnik;
      Wektor_tmp.y = y / Dzielnik;
      Wektor_tmp.z = z / Dzielnik;
      Wektor_tmp.w = w / Dzielnik;
      return Wektor_tmp;
}

/* 
 * Realizuje odejmowanie dwoch wektorow.
 *
 * Parametry:
 *   Odjemnik - wektor do odjecia
 *
 * Zwracana wartosc:
 *   Wynik operacji odejmownia, ktora zdefiniowania jest
 *   bezposrednio w przeciazenie operatora '-'. Zmienna 
 *   Odjemnik_tmp zawiera wektor powstaly po operacji odejmowania.
 */
Wektor Wektor::operator - (const Wektor & Odjemnik){
      Wektor Odjemnik_tmp;
      Odjemnik_tmp.x = x - Odjemnik.x;
      Odjemnik_tmp.y = y - Odjemnik.y;
      Odjemnik_tmp.z = z - Odjemnik.z;
      Odjemnik_tmp.w = w - Odjemnik.w;
      return Odjemnik_tmp;
}
