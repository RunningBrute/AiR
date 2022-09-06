#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
#include "../inc/lib.hpp"

using namespace std;

float BlokProstujacy::Przetwarzaj(float yy){
  if (yy < 0) return -yy;
  else return yy;
}
