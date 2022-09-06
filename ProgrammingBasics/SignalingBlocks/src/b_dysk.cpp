#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
#include "../inc/lib.hpp"

using namespace std;

float BlokDyskryminujacy::Przetwarzaj(float yy){
  if (yy > _WartDysk) return 1;
  else return 0;
}
