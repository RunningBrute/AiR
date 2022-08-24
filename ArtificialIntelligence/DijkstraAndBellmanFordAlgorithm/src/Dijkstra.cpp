#include "../inc/Dijkstra.h"

void Dijkstra::DijkstraStartArray(Matrix _G, int _s){
  Elem elem;
  int u;

  elem.SetPredecessor(101);
  elem.SetWeight(100);
  for (int i = 0; i < _G.ReturnVertexValue(); i++){ SPT.push_back(elem); }
  SPT[_s].SetWeight(0);
  for (int i = 0; i < _G.ReturnVertexValue(); i++){ pQueue.push(i); }
  while (pQueue.size() != 0){
	  u = pQueue.top();
	  pQueue.pop();
	  for (int i = 0; i < _G.ReturnVertexValue(); i++){
		  if((SPT[i].ReturnWeight() > (SPT[u].ReturnWeight() + _G.ReturnArrayElement(u,i)) 
			  && (_G.ReturnArrayElement(u,i) != 0))){
		    SPT[i].SetWeight((SPT[u].ReturnWeight() + _G.ReturnArrayElement(u,i)));
			SPT[i].SetPredecessor(u);
		  }
	  }
  }
  ShowTree();
};

void Dijkstra::ShowTree(){
  std::cout << std::endl;
  std::cout << "|------------------- Dijkstra ------------------|" << std::endl;
  for (int i = 0; i < SPT.size(); i++){
	  std::cout << " D[" << i + 1  << "] = " << SPT[i].ReturnWeight();
	  std::cout << std::endl;
  }
  std::cout << std::endl;
};