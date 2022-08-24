#include "../inc/Prim.h"

void Prim::PrimStartArray(){
  Elem elem;
  for (int i = 0; i < (ReturnVertexValue() - 1); i++){
    SetListOfVertexFromArray(ReturnLastVertexFromMST(i));
	elem = ReturnMinElem();
	if (!IsCycle(elem)) MST.push_back(elem);
	else i--;
  }
  //ShowMST();
  bufor.clear();
  MST.clear();
};

void Prim::PrimStartList(){
  Elem elem;
  for (int i = 0; i < (ReturnVertexValue() - 1); i++){
    SetListOfVertexFromList(ReturnLastVertexFromMST(i));
	elem = ReturnMinElem();
	if (!IsCycle(elem)) MST.push_back(elem);
	else i--;
  }
  //ShowMST();
  bufor.clear();
  MST.clear();
};

void Prim::SetListOfVertexFromList(int _i){
  Elem elem;
  for (std::list<Elem>::iterator Iter = (graph[_i].begin()); Iter != (graph[_i]).end(); ++Iter){
      elem = *Iter;
	  if (!Is(elem)) bufor.push_back(elem);
  }
};

void Prim::SetListOfVertexFromArray(int _i){
  Elem elem;
  for (int j = 0; j < ReturnVertexValue(); j++){
	if (ReturnArrayElement(_i,j) != 0){
      elem.SetVertex(_i,j);
	  elem.SetWeight(ReturnArrayElement(_i,j));
	  if (!Is(elem)) bufor.push_back(elem);
    }
  }
};

Elem Prim::ReturnMinElem(){
  int mem = 0;
  Elem elem;
  elem.SetWeight(10);
  for (int i = 0; i < bufor.size(); i++){
	  if ((elem.ReturnWeight() > bufor[i].ReturnWeight()) && (bufor[i].ReturnWeight() != 0)){
	    elem = bufor[i];
		mem = i;
	  }
  }
  bufor[mem].SetWeight(0);
  //DeleteElem(elem);
  return elem;
};

void Prim::DeleteElem(Elem _elem){
	for (int i = 0; i < bufor.size(); i++){
	  if ((_elem.ReturnVertexA() == bufor[i].ReturnVertexB()) 
		 && (_elem.ReturnVertexB() == bufor[i].ReturnVertexA())){
	     bufor[i].SetWeight(0);
	  }
   }
};

bool Prim::Is(Elem _elem){
  bool cond = false;
  for (int i = 0; i < bufor.size(); i++){
    if ((_elem.ReturnVertexA() == bufor[i].ReturnVertexB()) 
		 && (_elem.ReturnVertexB() == bufor[i].ReturnVertexA())){
         cond = true;
	}
  }
  return cond;
};

bool Prim::IsCycle(Elem _elem){
  bool cond = false;
  bool condVA = false, condVB = false, cond1 = false, cond2 = false;
  for (int i = 0; i < MST.size(); i++){
	  condVA = ((_elem.ReturnVertexA() == MST[i].ReturnVertexA()) || 
		       (_elem.ReturnVertexA() == MST[i].ReturnVertexB()));
	  if (condVA) cond1 = true;
	  condVB = ((_elem.ReturnVertexB() == MST[i].ReturnVertexA()) || 
		       (_elem.ReturnVertexB() == MST[i].ReturnVertexB()));
	  if (condVB) cond2 = true;
  }
  if ((cond1 && cond2)) cond = true;
  return cond;
};

int Prim::ReturnLastVertexFromMST(int _start){
  int lastVertex;
  if (_start == 0) return 0;
  else lastVertex = (MST.size() - 1); 
  return MST[lastVertex].ReturnVertexB();
};

void Prim::ShowMST(){
  std::cout << std::endl;
  std::cout << "|-------------------MST Prim-------------------|" << std::endl;
  for (int i = 0; i < MST.size(); i++){
	  std::cout << " " << i + 1 << ": ";
	  MST[i].ShowInfo();
	  std::cout << std::endl;
  }
  std::cout << std::endl;
};

void Prim::ShowBufor(){
  std::cout << std::endl;
  std::cout << "|--------------------Bufor---------------------|" << std::endl;
  for (int i = 0; i < bufor.size(); i++){
	  std::cout << " " << i + 1 << ": ";
	  bufor[i].ShowInfo();
	  std::cout << std::endl;
  }
  std::cout << std::endl;
};

void Prim::WriteMatrixToList(){
  Elem elem;
  std::list<Elem> list;
  SetVertexValue(ReturnVertexValue());
  for (int i = 0; i < ReturnVertexValue(); i++){
	SetArrayElement();
    for (int j = 0; j < ReturnVertexValue(); j++){
	  if ((ReturnArrayElement(i,j) != 0)){
	    elem.SetVertex(i,j);
		elem.SetWeight(ReturnArrayElement(i,j));
		SetListElement(i,elem);
	  }
	}
  }
};

void Prim::ListStart(){
  WriteMatrixToList();
  //ShowGraph();
  //ShowInfoList();
};

void Prim::RunPrimAndShowTime(int _i){
  
  double timeArray = 0;
  double timeList = 0;

  std::cout << std::endl;
  std::cout << std::endl;
  QueryPerformanceFrequency(&Freq);
  for (int i = 0; i < _i; i++){
	std::cout << " instancja " << i + 1 << std::endl;
	
	RandGraph();
	QueryPerformanceCounter(&start);
    PrimStartArray();
	QueryPerformanceCounter(&stop);
	timeArray = timeArray + (stop.QuadPart - start.QuadPart)/(Freq.QuadPart/1000);

    ListStart();
	QueryPerformanceCounter(&start);
    PrimStartList();
	ClearList();
	QueryPerformanceCounter(&stop);
    timeList = timeList + (stop.QuadPart - start.QuadPart)/(Freq.QuadPart/1000);
  }
  std::cout << std::endl;
  std::cout << " PRIM TABLICA " << std::endl;
  std::cout << " Czas dla " << _i << " instancji wynosi: " << timeArray/_i << " ms." << std::endl;
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << " PRIM LISTA " << std::endl;
  std::cout << " Czas dla " << _i << " instancji wynosi: " << timeList/_i << " ms." << std::endl;
  std::cout << std::endl;
};
