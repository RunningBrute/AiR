#include "../inc/Queue2s.h"

void Queue2s::ShowSeparator(bool _value){
  if (_value == 1){
    std::cout << std::endl;
    std::cout << " ................... Queue ................... " << std::endl;
    std::cout << std::endl;
  }
  else if (_value == 0){
    std::cout << std::endl;
    std::cout << " Queue ................................... end " << std::endl;
    std::cout << std::endl;
  }else std::cerr << " Zly parametr!!! " << std::endl;
};
