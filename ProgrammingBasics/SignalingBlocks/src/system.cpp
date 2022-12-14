#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
#include "../inc/lib.hpp"

using namespace std;

bool System::DodajBlok(char c, float a){
 switch (c) {
   case 'G':
     _ListaBlokow.push_back(new BlokPotegujacy());
     break;
   case 'P':
     _ListaBlokow.push_back(new BlokPrzesuwajacy(a));
     break;
   case 'S':
     _ListaBlokow.push_back(new BlokProstujacy());
     break;
   case 'C':
     _ListaBlokow.push_back(new BlokCalkujacy());
     break;
   case 'D':
     _ListaBlokow.push_back(new BlokDyskryminujacy(a));
     break;
 }
 return true;
}

bool System::Przetwarzaj(){
  
  ifstream IStrm(_PlikWe);
  ofstream OStrm(_PlikWy);
  
  float Liczba;
  
  while (!IStrm.eof() && !IStrm.bad()){
    for (list<BlokPodstawowy*>::iterator Iter = _ListaBlokow.begin();
	 Iter != _ListaBlokow.end(); ++ Iter){
      
      if ((IStrm >> Liczba).good()){
	OStrm << Liczba;
	OStrm << " ";
	IStrm >> Liczba;   
	OStrm << (*Iter)->Przetwarzaj(Liczba) << endl;
      }else {
	IStrm.clear();
	IStrm.ignore();
      }
    }
  }
  return true;
}
    


    
