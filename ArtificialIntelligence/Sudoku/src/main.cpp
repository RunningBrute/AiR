#include <fstream>
#include <string>

#include "../inc/Sudoku.h"


/*!
 *  \brief Metoda wczytujaca dane z pliku
 *  Metoda wczytuje wszelakie dane z pliku. Sa one potrzebne
 *  do prawidlowego dzialania algorytmu BT
 *  \param - &_S - referencja na plansze sudoku
 *  \post Dane z pliku zostaja zapisane do planszy sudoku
 */
void ReadFile(Sudoku &_S){

  std::string text;

  std::cout << std::endl;
  std::cout << " Podaj pelna sciezke do pliku " << std::endl;
  std::cout << " w formacie D:/Folder/plik.txt." << std::endl;
  std::cout << " W przypadku podania niewlasciwej " << std::endl;
  std::cout << " sciezki do pliku zostanie wczytane " << std::endl;
  std::cout << " domyslne puste sudoku. " << std::endl;
  std::cin >> text;
  
  std::ifstream IStrm(text); 
  int v = 0;
  double ii = 0.00;

  for (int i = 0; i < 9; i++){
	  for (int j = 0; j < 9; j++){
          IStrm >> v; 
		  _S.SetArrayElement(i,j,v);
		  if (v != 0) ii++;
      }
  }
  std::cout << std::endl;
  std::cout << "   Wypelnienie: " << (ii/81)*100 
	        << "%" << std::endl;
  std::cout << std::endl;
};

int main(){

	std::cout << std::endl;
	std::cout << "         SUDOKU " << std::endl;
	std::cout << "   wyk. Piotr Basinski "
			  << std::endl;

    Sudoku sudoku;
	double time;
	
	ReadFile(sudoku);
	sudoku.ShowBoard();
	QueryPerformanceFrequency(&(sudoku.Freq));
	QueryPerformanceCounter(&(sudoku.start));
	sudoku.ListFreeRecords();
	sudoku.BT();
	QueryPerformanceCounter(&(sudoku.stop));
	time = (sudoku.stop.QuadPart - sudoku.start.QuadPart)/(sudoku.Freq.QuadPart/1000);
	sudoku.ShowBoard();

	std::cout << "        Czas: " << time << "ms" <<std::endl;
	std::cout << std::endl;

	system("PAUSE");
    return 0;
}