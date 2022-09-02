#include "../inc/QueueSTL.h"

QueueSTL::QueueSTL(int _queSize, int _max){
  max =_max;
  for (int i = 0; i < _queSize; i++){
    Que.push(ReturnRandValue());
  }
};

void QueueSTL::InitQueueSTL(){
  std::cout << " Elements amount ... "; std::cin >> queSize;
  max = 88;
  for (int i = 0; i < queSize; i++){
    Que.push(ReturnRandValue());
  } 
};

void QueueSTL::Front(){
  std::cout << " First element: " << Que.front() << std::endl;
};

void QueueSTL::Pop(){
  if (!Que.empty()){
    std::cout << " Remove element" << std::endl;
    Que.pop();
  }else std::cerr << " Queue is empty! " << std::endl;
};

void QueueSTL::ShowQueueSize(){
  std::cout << " Queue size: " << Que.size() << std::endl;
};

void QueueSTL::ShowSeparator(bool _value){
  if (_value == 1){
    std::cout << std::endl;
    std::cout << " ................... QUEUESTL .................. " << std::endl;
    std::cout << std::endl;
  }
  else if (_value == 0){
    std::cout << std::endl;
    std::cout << " QueueSTL .................................. end " << std::endl;
    std::cout << std::endl;
  }else std::cerr << " Zly parametr!!! " << std::endl;
};
