#include "../inc/Matrix.h"

Matrix::Matrix(){ 
  vVertex = 120; 
  vEdge = vEdgeCount(); 
  density = 1;
  dConnections = DeleteConnectionsValue();
  Array = NULL; 
  srand(time(NULL));
};

Matrix::Matrix(int _vVertex, double _density){ 
  vVertex = _vVertex; 
  vEdge = vEdgeCount();
  density = _density;
  dConnections = DeleteConnectionsValue();
  Array = NULL;
  srand(time(NULL));
};

Matrix::~Matrix(){
  for (int i = 0; i < vVertex; i++) delete [] Array[i];
  delete [] Array;
};

void Matrix::InitMatrix(){
  Array = new int*[vVertex];
  for (int i = 0; i < vVertex; i++) Array[i] = new int[vVertex];
};

void Matrix::DeleteConnections(){
  int _count = 0;
  int _value = 1;

  while (_count < dConnections){ 
    for (int i = 0; i < vVertex; i++){
      for (int j = 0; j < vVertex; j++){
		  if ((i!=j) && (i!=(j-1)) && ((i-1)!=j) && (Array[i][j]!=0) && (_count<=dConnections)){
		    _value = ReturnRandValueWithZero();
		    Array[i][j] = _value; Array[j][i] = _value;
		    if (_value == 0) _count++;
		  }
	  }
    }
  }
};

void Matrix::RandGraph(){
  InitMatrix(); 
  ResetMatrix(); 
  RandMatrix();
  DeleteConnections();
  ResetDiagonal();
  //ShowMatrix();
  //ShowInfo();
};

void Matrix::ResetDiagonal(){
  for (int i = 0; i < vVertex; i++){
    for (int j = 0; j < vVertex; j++){
      if (i==j) Array[i][j] = 0;
    }
  }
};

void Matrix::ShowMatrix(){
  std::cout << std::endl;
  std::cout << "|--------------------Matrix--------------------|" << std::endl;
  for (int i = 0; i < vVertex; i++){
    for (int j = 0; j < vVertex; j++){
        std::cout << " " << Array[i][j];
    }
    std::cout << std::endl;
  } 
  std::cout << std::endl;
};

void Matrix::ShowInfo(){
  std::cout << "|------------------MatrixINFO------------------|" << std::endl;
  std::cout << std::endl;
  std::cout << " Number of vertices: " << vVertex << std::endl;
  std::cout << " Number of edges:    " << vEdge << std::endl;
  std::cout << " Number of delete connections: " << dConnections << std::endl;
  std::cout << std::endl;
};

void Matrix::ResetMatrix(){
  for (int i = 0; i < vVertex; i++){
    for (int j = 0; j < vVertex; j++){
      Array[i][j] = 0;
    }
  } 
};

void Matrix::RandMatrix(){
  int _value = 0;
  for (int i = 0; i < vVertex; i++){
    for (int j = 0; j < vVertex; j++){
	  _value = ReturnRandValue();
      Array[i][j] = Array[j][i] = _value;
    }
  } 
};
/*
void ShowTime(){ 
  std::cout << " Time: " << (stop.QuadPart - start.QuadPart)/(Freq.QuadPart/1000) << std::endl; 
};
*/
