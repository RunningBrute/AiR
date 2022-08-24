#include "../inc/Elem.h"

Elem::Elem(){
  vertexA = vertexB = color = weight = 0;
};

void Elem::ShowInfo(){
	std::cout << " (" << vertexA + 1 << "," << vertexB + 1 << ";" 
			  << weight << ")"; 
};
