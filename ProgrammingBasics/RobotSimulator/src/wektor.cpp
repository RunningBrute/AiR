#include<iostream>
#include<cstdlib>
#include<list>
#include"../inc/lib.hpp"
#include "../inc/lacze_do_gnuplota.hpp"

using namespace std;

Wektor Wektor::operator + (Wektor Skladnik) const{
  Skladnik.x += x;
  Skladnik.y += y;
  return Skladnik;
}

Wektor Wektor::operator - (const Wektor & Odjemnik) const{
  Wektor Odjemnik_tmp;
  Odjemnik_tmp.x = x - Odjemnik.x;
  Odjemnik_tmp.y = y - Odjemnik.y;
  return Odjemnik_tmp;
}
Wektor Wektor::operator * (const float & Mnoznik) const{
  Wektor Mnoznik_tmp;
  Mnoznik_tmp.x *= Mnoznik;
  Mnoznik_tmp.y *= Mnoznik;
  return Mnoznik_tmp;
}
  
Wektor Wektor::operator / (const float & Dzielnik) const{
  Wektor Dzielnik_tmp;
  Dzielnik_tmp.x /= Dzielnik;
  Dzielnik_tmp.y /= Dzielnik;
  return Dzielnik_tmp;
}

void Wektor::PokazWektor() const{
  cout << "(" << x << ", " << y << ")" ;
}
