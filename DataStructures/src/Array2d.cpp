#include "../inc/Array2d.h"

Array2d::Array2d(int _width, int _height, int _max){
  width = _width; height = _height; max = _max;
  min_value = 0; max_value = 0;
  
  tab = new int*[width];
  for (int x = 0; x < width; x++) tab[x] = new int[height];
};

Array2d::~Array2d(){
  for (int x = 0; x < width; x++) delete [] tab[x];
  delete [] tab;
};

void Array2d::InitArray(){
  std::cout << " Array width ... "; std::cin >> width;
  std::cout << " Array height ... "; std::cin >> height;
  std::cout << " Max value ... "; std::cin >> max; std::cout << std::endl;
  min_value = 0; max_value = 0;
  tab = new int*[width];
  for (int x = 0; x < width; x++) tab[x] = new int[height];
  for (int x = 0; x < width; x++){
    for (int y = 0; y < height; y++){
      tab[x][y] = ReturnRandValue();
    }
  }
};

void Array2d::ShowFieldsValues(){
  ShowMinValue();
  ShowMaxValue();
  std::cout << std::endl;
};     

void Array2d::ShowArrayValues(){ 

  std::cout << " Array Values: " << std::endl;
  std::cout << std::endl;

  for (int x = 0; x < width; x++){
    for (int y = 0; y < height; y++){
      std::cout << " " << tab[x][y] << " ";
    }
    std::cout << std::endl;
  }
  
  std::cout << std::endl;         
};

int Array2d::FindMinValue(){
  int tmp = max;  
    
  for (int x = 0; x < width; x++){
    for (int y = 0; y < height; y++){
      if (tab[x][y] < tmp){
        tmp = tab[x][y];
      }
      else tmp = tmp;
    }
  }
  min_value = tmp;
  return tmp;
};

int Array2d::FindMaxValue(){
  int tmp = 0;  
    
  for (int x = 0; x < width; x++){
    for (int y = 0; y < height; y++){
      if (tab[x][y] > tmp){ 
        tmp = tab[x][y];
      }
      else tmp = tmp;
    }
  }
  max_value = tmp;
  return tmp;
};

void Array2d::ShowSeparator(bool _value){
  if (_value == 1){
    std::cout << std::endl;
    std::cout << " ................... ARRAY2D ................... " << std::endl;
    std::cout << std::endl;
  }
  else if (_value == 0){
    std::cout << std::endl;
    std::cout << " Array2d ................................... end " << std::endl;
    std::cout << std::endl;
  }else std::cerr << " Zly parametr!!! " << std::endl;
};
