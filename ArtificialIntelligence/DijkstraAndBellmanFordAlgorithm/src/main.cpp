#include "../inc/Dijkstra.h"
#include "../inc/Ford.h"

int main(){
  
  Matrix G;
  Ford ford;
  Dijkstra dijkstra;

  G.RandGraph();
  G.ShowMatrix();

  ford.FordStartArray(G,0);

  G.ShowMatrix();

  dijkstra.DijkstraStartArray(G,0);
  
  system("PAUSE");
  return 0;
    
}
