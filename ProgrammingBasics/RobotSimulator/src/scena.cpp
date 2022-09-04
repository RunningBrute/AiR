#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include<list>
#include"../inc/lib.hpp"
#include "../inc/lacze_do_gnuplota.hpp"

using namespace std;

void Scena::ZainicjalizujStanPoczatkowy(){
  ofstream  StrmWy;

  StrmWy.open(PLIK_STARTU);
  StrmWy << _Start._Wspol.x << " " << _Start._Wspol.y << " " << "4" << endl;
  StrmWy.close();

  StrmWy.open(PLIK_ROBOTA);
  StrmWy << _Robot._Wspol.x << " " << _Robot._Wspol.x << " " << "9" << endl;
  StrmWy.close();
  
  StrmWy.open(PLIK_CELU);
  StrmWy << _Cel._Wspol.x << " " << _Cel._Wspol.y << " " << "4" << endl;
  StrmWy.close();
}

void Scena::WyswietlMenu() const{
  
  cout << endl;
  cout << "       Menu glowne" << endl;
  cout << endl;
  cout << " s - start algorytmu" << endl;
  cout << " p - przywroc pozycje wyjsciowa" << endl;
  cout << endl;
  cout << " z - zmiana wspolrzednych startu" << endl;
  cout << " c - zmiana wspolrzednych celu" << endl;
  cout << endl;
  cout << " u - usun przeszkode" << endl;
  cout << " w - wstaw nowa przeszkode" << endl;
  cout << " e - edytuj przeszkode" << endl;
  cout << endl;
  cout << " d - zmiana dlugosci pojedynczego przemieszczenia" << endl;
  cout << " i - zmiana jednorazowej ilosci krokow" << endl;
  cout << " l - zmiana ladunku celu" << endl;
  cout << endl;
  cout << " a - wyswietl aktualny stan sceny i robota" << endl;
  cout << " ? - wyswietlenie menu" << endl;
  cout << endl;
  cout << " k - wyjscie z programu" << endl;

}

void Scena::WyswietlWspolStartu() const{
  _Start.PokazWspol();
}

void Scena::WyswietlWspolRobota() const{
  _Robot.PokazWspol();
}

void Scena::WyswietlWspolCelu() const{
  _Cel.PokazWspol();
}

void Scena::WyswietlLadunekCelu() const{
  _Cel.PokazLadunek();
}

void Scena::WyswietlDlPojPrzem() const{
  cout << _ScRob.ZwracajDlPrzem();
}

void Scena::WyswietlIloscKrok() const{
  cout << _ScRob.ZwracajJedIlKrok();
}

void Scena::WyswietlIlWykKrok() const{
  cout << _ScRob.ZwracajWykIlKrok();
}

bool Scena::ZmWspolStartu(){
  cout << endl;
  cout << "Podaj nowe wspol. startu: " << endl;
  _Start.WczytajWspol();
  _Robot.PrzypiszWspol(_Start.ZwracajWspol());
  return true;
}

bool Scena::ZmWspolCelu(){
  cout << endl;
  cout << "Podaj nowe wspol. celu: " << endl;
  _Cel.WczytajWspol();
  return true;
}

bool Scena::ZmLadunekCelu(){
  cout << endl;
  cout << "Podaj nowy ladunek celu: " << endl;
  _Cel.WczytajLadunek();
  return true;
}

bool Scena::ZmDlugoscPrzem(){
  cout << endl;
  cout << "Podaj nowa dlugosc pojedynczego przemieszczenia: " << endl;
  _ScRob.ZmDlPrzem();
 return true;
}

bool Scena::ZmIloscKrokow(){
  cout << endl;
  cout << "Podaj nowa jednorazowa wartosc ilosci krokow: " << endl;
  _ScRob.ZmJedIlKrok();
  return true;
}

bool Scena::WstawPrzeszkode(){
  Obiekt Prze;
  cout << endl;
  cout << "Podaj wspol. przeszkody: " << endl;
  Prze.WczytajWspol();
  cout << "Podaj rozm. przeszkody: " << endl;
  Prze.WczytajRozm();
  _Lst.push_back(Prze);
  return true;
}

bool Scena::UsunPrzeszkode(){
  _Lst.pop_back();
  return true;
}

bool Scena::EdytujPrzeszkode(){
  unsigned int n, i=1;
  cout << endl;
  cout << "Ktora przeszkode chcesz edytowac?";
  cout << "(1-" << _Lst.size() << ")" << endl;
  cin >> n ;
  for (list<Obiekt>::iterator Iter=_Lst.begin();Iter!=_Lst.end();++Iter,++i) {
    if (i==n){
      cout << endl;
      cout << " Podaj nowe wspol. przeszkody: " <<
      Iter->WczytajWspol();
      cout << " Podaj nowy rozmiar przeszkody: ";
      Iter->WczytajRozm();
      cout << endl;
    }
  }
  return true;
}

void Scena::PrzetwarzajOpcje(char & Oper){
  switch (Oper) {
  case 's': StartAlgorytmu(); break;
  case 'p': break;
  case 'z': ZmWspolStartu(); 
            ZainicjalizujStanPoczatkowy(); 
            break;
  case 'c': ZmWspolCelu(); 
            ZainicjalizujStanPoczatkowy(); 
            break;
  case 'u': UsunPrzeszkode(); break;
  case 'w': WstawPrzeszkode(); break;
  case 'e': EdytujPrzeszkode(); break;
  case 'd': ZmDlugoscPrzem(); break;
  case 'i': ZmIloscKrokow(); break;
  case 'l': ZmLadunekCelu(); break;
  case 'a': WyswietlStan(); break;
  case '?': WyswietlMenu(); break;
  case 'k': break;
  }
}    

void Scena::WyswietlStan(){
  int i=1;
  
  cout << endl;
  cout << " Aktualny stan: " << endl;
  cout << endl;
  cout << "  Dlugosc pojedynczego przemieszczenia: ";
  WyswietlDlPojPrzem();
  cout << endl;
  cout << "              Jednorazowa ilosc krokow: ";
  WyswietlIloscKrok();
  cout << endl;
  cout << "               Ilosc wykonanych krokow: ";
  WyswietlIlWykKrok();
  cout << endl;
  cout << "            Start: ";
  WyswietlWspolStartu();
  cout << endl;
  cout << "      ====> Robot: ";
  WyswietlWspolRobota();
  cout << endl;
  cout << "              Cel: ";
  WyswietlWspolCelu();
  cout << endl;
  cout << endl;
  cout << "            Ladunek celu: ";
  WyswietlLadunekCelu();
  cout << endl;
  cout << endl;
  cout << " Polozenie przeszkod: " << endl;
  for (list<Obiekt>::iterator Iter=_Lst.begin();Iter!=_Lst.end();++Iter) {
    cout << "             " << i << ": ";
    Iter->PokazWspol();
    cout << "   Rozmiar: ";
    Iter->PokazRozm();
    cout << endl;
    ++i;
  }
  cout << endl;
}

Wektor Scena::WyliczWekSily(){
  Wektor WektorSily, Wek_1;
  float Skalar;
  
  for (list<Obiekt>::iterator Iter=_Lst.begin();Iter!=_Lst.end();++Iter) {
    Wek_1 = (Iter->ZwracajWspol() - _Robot.ZwracajWspol()) / (Iter->ZwracajDlWek() - _Robot.ZwracajDlWek());
    Skalar = Iter->ZwracajRozm() / (Iter->ZwracajDlWek_2() - _Robot.ZwracajDlWek_2());
    WektorSily = WektorSily + (Wek_1 * Skalar);
  }
  Wek_1 = (_Cel.ZwracajWspol() - _Robot.ZwracajWspol()) / (_Cel.ZwracajDlWek() - _Robot.ZwracajDlWek());
  Skalar = _Cel.ZwracajLadunek() / (_Cel.ZwracajDlWek_2() - _Robot.ZwracajDlWek_2());
  WektorSily = WektorSily + (Wek_1 * Skalar);
  return WektorSily;
}

float Scena::WyliczWartSily(){
  Wektor Wektor;
  Wektor = WyliczWekSily(); 
  return Wektor.DlWektora();
}

Wektor Scena::WyliczWekPrzesRobota(){ 
  return WyliczWersorSily() * _ScRob.ZwracajDlPrzem(); 
}

bool Scena::PrzemiescRobota(){
  _Robot.PrzypiszWspol(_Robot.ZwracajWspol() + WyliczWekPrzesRobota());
  return true;
}  

bool Scena::StartAlgorytmu(){
  int i, n=0;
  char Oper;
  
  ZainicjalizujStanPoczatkowy();
   
  cout << "Krok 1: Start. Aby kontynuowac nacisnij ENTER ..." << flush;
  cin >> Oper;
  
  while (n<5){
    for(i=0;i<_ScRob.ZwracajJedIlKrok();++i){
      PrzemiescRobota();
      _ScRob.DodajIlWykKrok();
    }  
    cout << endl;
    cout << "     Laczna ilosc krokow: ";
    WyswietlDlPojPrzem();
    cout << endl;
    cout << " Aktualna pozycja robota: ";
    WyswietlWspolRobota();
    cout << endl;
    cout << "     Cel nie jest jeszcze osiagniety." << endl;
    cout << endl;
    ++n;
  }
  return true;
}
