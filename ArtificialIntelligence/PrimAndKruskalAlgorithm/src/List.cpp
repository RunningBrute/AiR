#include "../inc/List.h"

void List::ShowGraph(){
  std::cout << std::endl;
  std::cout << "|--------------------Graph---------------------|" << std::endl;
  for (int i = 0; i < vVertex; i++){
	  std::cout << " " << "V" << i + 1 << " --";
	  for (std::list<Elem>::iterator Iter = (graph[i]).begin(); Iter != (graph[i]).end(); ++Iter){
		Iter->ShowInfo();
    }
    std::cout << std::endl;
  } 
  std::cout << std::endl;
};

void List::ShowInfoList(){
  std::cout << "|------------------GraphINFO-------------------|" << std::endl;
  std::cout << std::endl;
  std::cout << " Number of vertices: " << vVertex << std::endl;
  std::cout << std::endl;
};
