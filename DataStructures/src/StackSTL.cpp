#include "../inc/StackSTL.h"

StackSTL::StackSTL(int _stkSize, int _max){
  max=_max;
  for (int i = 0; i < _stkSize; i++){
    Stk.push(ReturnRandValue());
  }
};

void StackSTL::InitStackSTL(){
  std::cout << " Elements amount ... "; std::cin >> stkSize;
  max = 88;
  for (int i = 0; i < stkSize; i++){
    Stk.push(ReturnRandValue());
  }
};

void StackSTL::ShowFirstElem(){
  std::cout << " Top element is: " << Stk.top() << std::endl;
};

void StackSTL::Pop(){
  if (!Stk.empty()){
    std::cout << " Remove top element: " << Stk.top() << std::endl;
    Stk.pop();
  }else std::cerr << " Stack is empty! " << std::endl;
};

void StackSTL::ShowStackSize(){
  std::cout<< " Stack size: " << Stk.size() << std::endl;
};

void StackSTL::ShowSeparator(bool _value){
  if (_value == 1){
    std::cout << std::endl;
    std::cout << " ................... STACKSTL .................. " << std::endl;
    std::cout << std::endl;
  }
  else if (_value == 0){
    std::cout << std::endl;
    std::cout << " StackSTL .................................. end " << std::endl;
    std::cout << std::endl;
  }else std::cerr << " Zly parametr!!! " << std::endl;
};
