#include "../inc/Ford.h"

void Ford::FordStartArray(Matrix _G, int _s){
  Elem elem;

  elem.SetPredecessor(101);
  elem.SetWeight(100);
  for (int i = 0; i < _G.ReturnVertexValue(); i++){ SPT.push_back(elem); }
  SPT[_s].SetWeight(0);
  for (int i = 1; i < (_G.ReturnVertexValue() - 1); i++){
	  for (int u = 0; u < _G.ReturnVertexValue(); u++){
		  for (int v = 0; v < _G.ReturnVertexValue(); v++){
			  if (_G.ReturnArrayElement(u,v) != 0){
				  if (SPT[v].ReturnWeight() > (SPT[u].ReturnWeight() + _G.ReturnArrayElement(u,v))){
					  SPT[v].SetWeight(SPT[u].ReturnWeight() + _G.ReturnArrayElement(u,v));
					  SPT[v].SetPredecessor(u);
				  }
			  }
		  }
	  }
  }
  ShowTree();
};

void Ford::ShowTree(){
  std::cout << std::endl;
  std::cout << "|--------------- Belmann - Ford ------------------|" << std::endl;
  for (int i = 0; i < SPT.size(); i++){
	  std::cout << " D[" << i + 1  << "] = " << SPT[i].ReturnWeight();
	  std::cout << std::endl;
  }
  std::cout << std::endl;
};