#include "../inc/ListSTL.h"

ListSTL::ListSTL(int _lstSize, int _max){
  max = _max;
  for (int i = 0; i < _lstSize; i++){
    Lst.push_back(ReturnRandValue());
  }                 
};

void ListSTL::InitListSTL(){
  std::cout << " Elements amount ... "; std::cin >> lstSize;
  max = 88;
  for (int i = 0; i < lstSize; i++){
    Lst.push_back(ReturnRandValue());
  } 
};

void ListSTL::PopBack(){
  if (!IsEmpty()){
    Lst.pop_back();
  }
  else std::cout << " Empty list " << std::endl;
};

void ListSTL::PopFront(){
  if (!IsEmpty()){
    Lst.pop_front();
  }
  else std::cout << " Empty list " << std::endl;
};

void ListSTL::ShowList(){
  std::cout << " List elements: " << std::endl;
  std::cout << std::endl;
  for (std::list<int>::iterator iter=Lst.begin(); iter!=Lst.end(); iter++){
    std::cout << " " << *iter;
  }
  std::cout << std::endl << std::endl;;
};

void ListSTL::ShowListSize(){
  std::cout << " Size: "<< Lst.size() << std::endl << std::endl;
};

void ListSTL::AddTwoKnots(){
  int elem;
  std::cout << " Add first element ... "; std::cin >> elem;
  Lst.push_front(elem); 
  std::cout << " Add second element ... "; std::cin >> elem;
  Lst.push_front(elem);
};

void ListSTL::ShowSeparator(bool _value){
  if (_value == 1){
    std::cout << std::endl;
    std::cout << " ................... LISTSTL ................... " << std::endl;
    std::cout << std::endl;
  }
  else if (_value == 0){
    std::cout << std::endl;
    std::cout << " ListSTL ................................... end " << std::endl;
    std::cout << std::endl;
  }else std::cerr << " Zly parametr!!! " << std::endl;
};
