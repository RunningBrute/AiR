#include "../inc/Kruskal.h"

void Kruskal::WriteMatrixToList(){
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

void Kruskal::ListStart(){
  WriteMatrixToList();
  //ShowGraph();
  //ShowInfoList();
};

void Kruskal::KruskalStartArray(){
  Elem elem;
  SetListOfVertexFromArray();
  Sort();
  for (int i = 0; i < (ReturnVertexValue() - 1); i++){
	  elem = ReturnMinElem();
	  if (IsCycle(elem)) ;
	  else i--;
  }
  //ShowMST();
  bufor.clear();
  MST.clear();
};

void Kruskal::KruskalStartList(){
  Elem elem;
  SetListOfVertexFromList();
  Sort();
  for (int i = 0; i < (ReturnVertexValue() - 1); i++){
	  elem = ReturnMinElem();
	  if (IsCycle(elem)) ;
	  else i--;
  }
  //ShowMST();
  bufor.clear();
  MST.clear();
};

bool Kruskal::IsCycle(Elem _elem){
  bool cond = false;
  bool condVA = false, condVB = false, cond1 = false, cond2 = false, condC;
  int mem1 = 0, mem2 = 0;
  for (int i = 0; i < MST.size(); i++){
	  condVA = ((_elem.ReturnVertexA() == MST[i].ReturnVertexA()) || 
		       (_elem.ReturnVertexA() == MST[i].ReturnVertexB()));
	  if (condVA){
	    cond1 = true;
		mem1 = i;
	  }
	  condVB = ((_elem.ReturnVertexB() == MST[i].ReturnVertexA()) || 
		       (_elem.ReturnVertexB() == MST[i].ReturnVertexB()));
	  if (condVB){
		cond2 = true;
		mem2 = i;
	  }
  }
  if((cond1 == 0) && (cond2 == 0)){
	  _elem.SetColor(MST.size());
	  MST.push_back(_elem);
	  return true;
  }
  if((cond1 == 1) && (cond2 == 0)){
	  _elem.SetColor(MST[mem1].ReturnColor());
	  MST.push_back(_elem);
	  return true;
  }
  if((cond1 == 0) && (cond2 == 1)){
	  _elem.SetColor(MST[mem2].ReturnColor());
	  MST.push_back(_elem);
	  return true;
  }
  if((cond1 == 1) && (cond2 == 1)){
	  if(MST[mem1].ReturnColor() == MST[mem2].ReturnColor()) return false;
	  else {
		  _elem.SetColor(MST[mem1].ReturnColor());
		  MST.push_back(_elem);
		  for(int i = 0; i < MST.size(); i++){
			  if((MST[mem1].ReturnColor() == MST[i].ReturnColor()) || 
				 (MST[mem2].ReturnColor() == MST[i].ReturnColor())){
				  MST[i].SetColor(_elem.ReturnColor());
			  }
		  }
		  return true;
	  }
  }
};

/*
 * Sortowanie babelkowe uzywane do porownania dzialania algorytmu w zaleznosci
 * od zastosowanego sortowania.
 */
void Kruskal::Sort(){
	for (int i = 0; i < bufor.size(); i++){
		for (int j = 0; j < (bufor.size() - 1); j++){
			if (bufor[j].ReturnWeight() > bufor[j + 1].ReturnWeight()){
				std::swap(bufor[j],bufor[j+1]);
			}
		}
	}
};

/*
 * Sortowanie szybkie polepszajace dzialanie algorytmu uzywane do porownania dzialania 
 * algorytmu w zaleznosci
 * od zastosowanego sortowania.
 */
/*
void Kruskal::Sort(int _left, int _right){
     int i=_left; 
     int j=_right; 
     int x=bufor[(_left+_right)/2].ReturnWeight();
     do{
		 while(bufor[i].ReturnWeight()<x) i++;
         while(bufor[j].ReturnWeight()>x) j--;
         if(i<=j){                  
             Elem temp=bufor[i];
             bufor[i]=bufor[j];
             bufor[j]=temp;
             i++;
             j--;
         }
     }while(i<=j);
     if(_left<j) Sort(_left,j);
     if(_right>i) Sort(i,_right);     
};
*/



void Kruskal::SetListOfVertexFromArray(){
  int k = 0;
  Elem elem;
  for (int i = 0; i < (ReturnVertexValue() - 1); i++){
	  for (int j = i + 1; j < ReturnVertexValue(); j++){
		  if ((ReturnArrayElement(i,j) != 0)){
			  elem.SetVertex(i,j);
			  elem.SetWeight(ReturnArrayElement(i,j));
			  elem.SetColor(k); k++;
			  if(!Is(elem)) bufor.push_back(elem);
		  }
	  }
  }
};

void Kruskal::SetListOfVertexFromList(){
  int k = 0;
  Elem elem;
  for (int i = 0; i < graph.size(); i++){
    for (std::list<Elem>::iterator Iter = (graph[i].begin()); Iter != (graph[i]).end(); ++Iter){
        elem = *Iter;
	    if (!Is(elem)) bufor.push_back(elem);
	}
  }
};

bool Kruskal::Is(Elem _elem){
  bool cond = false;
  for (int i = 0; i < bufor.size(); i++){
    if ((_elem.ReturnVertexA() == bufor[i].ReturnVertexB()) 
		 && (_elem.ReturnVertexB() == bufor[i].ReturnVertexA())){
         cond = true;
	}
  }
  return cond;
};

Elem Kruskal::ReturnMinElem(){
  Elem elem;
  elem.SetWeight(10);
  int mem = 0;
  for (int i = 0; i < bufor.size(); i++){
	  if((elem.ReturnWeight() > bufor[i].ReturnWeight()) && (bufor[i].ReturnWeight() != 0)){
		  elem = bufor[i];
		  mem = i;
	  }
  }
  bufor[mem].SetWeight(0);
  return elem;
};

void Kruskal::ShowMST(){
  std::cout << std::endl;
  std::cout << "|-----------------MST Kruskal------------------|" << std::endl;
  for (int i = 0; i < MST.size(); i++){
	  std::cout << " " << i + 1 << ": ";
	  MST[i].ShowInfo();
	  std::cout << std::endl;
  }
  std::cout << std::endl;
};

void Kruskal::RunKruskalAndShowTime(int _i){
  double timeArray = 0;
  double timeList = 0;

  std::cout << std::endl;
  std::cout << std::endl;
  QueryPerformanceFrequency(&Freq);
  for (int i = 0; i < _i; i++){
	std::cout << " instancja " << i + 1 << std::endl;
    
	RandGraph();
	QueryPerformanceCounter(&start);
    KruskalStartArray();
	QueryPerformanceCounter(&stop);
	timeArray = timeArray + (stop.QuadPart - start.QuadPart)/(Freq.QuadPart/1000);

    ListStart();
	QueryPerformanceCounter(&start);
    KruskalStartList();
	ClearList();
	QueryPerformanceCounter(&stop);
    timeList = timeList + (stop.QuadPart - start.QuadPart)/(Freq.QuadPart/1000);
  }
  std::cout << std::endl;
  std::cout << " KRUSKAL TABLICA " << std::endl;
  std::cout << " Czas dla " << _i << " instancji wynosi: " << timeArray/_i << " ms." << std::endl;
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << " KRUSKAL LISTA " << std::endl;
  std::cout << " Czas dla " << _i << " instancji wynosi: " << timeList/_i << " ms." << std::endl;
  std::cout << std::endl;
};
