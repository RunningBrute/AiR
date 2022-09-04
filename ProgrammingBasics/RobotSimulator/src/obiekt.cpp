#include<iostream>
#include<cstdlib>
#include<list>
#include"../inc/lib.hpp"
#include "../inc/lacze_do_gnuplota.hpp"

using namespace std;

bool Obiekt::PrzypiszWspol(const Wektor & Wspol){
  _Wspol = Wspol;
  return true;
}

bool Obiekt::WczytajWspol(){
  cin >> _Wspol;
  return true;
}

bool Obiekt::WczytajRozm(){
  cin >> _Rozm ;
  return true;
}

bool Obiekt::WczytajLadunek(){
  cin >> _Ladunek ;
  return true;
}

void Obiekt::PokazWspol() const{
  _Wspol.PokazWektor();
}

void Obiekt::PokazRozm() const{
  cout << _Rozm ;
}

void Obiekt::PokazLadunek() const{
  cout << showpos << _Ladunek << noshowpos;
}

