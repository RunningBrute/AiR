#ifndef SUDOKU_H
#define SUDOKU_H

/*! \file Sudoku.h
 *
 *  \brief Zawiera definicje klasy Sudoku
 *
 *  Plik zawiera definicje klasy Sudoku.  
 *
 *  \author Piotr Basinski
 *  \date 2010.06.09
 *  \version 1.00.00
 */

#include <list>
#include <windows.h>

#include "../inc/Elem.h"


/*! \class Sudoku
 *  \brief Klasa modeluje plansze sudoku wraz z algorytmem
 *  pozwalajacym na jego rozwiazanie. Algorytm ten nosi nazwe 
 *  "przeszukiwanie priorytetowe z powracaniem". Klasa ta 
 *  umozliwia tez wyliczenie czasu dzialania algorytmu.
 */
struct Sudoku{

        /*!
         *  \brief Konstruktor domyslny
		 *  Konstruktor domyslny inicjalizujacy sudoku
		 *  domyslnymi wartosciami (w tym przypadku 0)
         */
	    Sudoku();

	 	/*!
         *  \brief Destruktor domyslny
         *  Destruktor domyslny
         */
	    ~Sudoku();

		/*!
         *  \brief Metoda inicjalizujaca plansze sudoku
		 *  Metoda inicjalizuje plansze sudoku, ktora
         *  przechowywana jest w pamieci jako tablica
		 *  dynamiczna o dwoch wymiarach
         */
		void InitBoard();

		/*!
         *  \brief Metoda zerujaca plansze sudoku
         *  Metoda zapisuje w kazdy rekord planszy sudoku
		 *  liczbe zero.
         */
		void ResetBoard();

		/*!
         *  \brief Metoda ustawiajaca rekord (_i,_j)
		 *  Metoda ustawia rekord (_i,_j) wartoscia _v
         *  \param - _i - wiersz
         *  \param - _j - kolumna
         *  \param - _v - wartosc rekordu (_i,_j)
         *  \post Do rekordu Board[_i][_j] zostaje wpisana wartosc _v
         */
		void SetArrayElement(int _i, int _j, int _v){ Board[_i][_j] = _v; } 

		/*!
         *  \brief Metoda zwraca rekord (_i,_j)
         *  Metoda zwraca rekord (_i,_j)
		 *  \param - _i - wiersz
         *  \param - _j - kolumna
		 *  \post Wartoscia zwracana jest rekord Board[_i][_j]
         */
		int ReturnArrayElement(int _i, int _j){ return Board[_i][_j]; }

		/*!
         *  \brief Metoda sprawdzajaca 
		 *  Metoda sprawdza czy w wierszu, kolumnie lub kwadracie
		 *  znajduje sie liczba _v.
         *  \param - _i - wiersz
         *  \param - _j - kolumna
         *  \param - _v - wartosc rekordu (_i,_j)
         *  \post W wypadku gdy liczba _v jest w wierszu, kolumnie
         *  lub kwadracie wartoscia zwracana jest true,
         *  w przeciwnym wypadku zwracana jest wartosc false 
         */
		bool Check(int _i, int _j, int _v);

		/*!
         *  \brief Metoda tworzaca liste zerowych rekordow sudoku 
         *  Metoda ta tworzy liste wolnych rekordow sudoku do
		 *  ktorych mozna wpisac liczbe. Lista jest zbudowana na
		 *  bazie szablonu std::list z <list>
         */
		void ListFreeRecords();

		/*!
         *  \brief Przeszukiwanie priorytetowe z nawracaniem
         *  Metoda przeszukiwania priorytetowego z nawracaniem. 
		 *  Jest to algorytm rozwiazujacy sudoku bez wzgledu na 
		 *  stopien trudnosci
         */
		void BT();

		/*!
         *  \brief Metoda wyswietlajaca sudoku
		 *  Metoda wyswietla sudoku na ekran monitora
         */
		void ShowBoard();

	private:

	    /*!
         *  \brief Lista zerowych elementow sudoku
         *  Lista elementow, ktore mozna uzupelnic w sudoku
         */
		std::list<Elem> Rec;

		/*! 
         *  \brief Plansza sudoku
         *  Tablica dwuwymiarowa reprezentujaca plansze sudoku
         */
		int **Board;

		/*!
         *  \brief Wielkosc planszy sudoku
         *  Pole przechowuje plansze sudoku. Domyslnie jest to wartosc 9
         */
		int size;
	
    public:

        /*!
	     *  \brief Pole zawierajace czas
	     *  Ilosc taktow procesora ktore uplynely do momentu rozpoczecia 
	     *  dzialania algorytmu. Zapisaniem tego pola zajmuje sie funkcja
	     *  QueryPerformanceCounter(LARGE_INTEGER *lp) z pliku <windows.h>
	     */
	    LARGE_INTEGER start;

	    /*!
	     *  \brief Pole zawierajace czas
    	 *  Ilosc taktow procesora ktore uplynely do czasu zakonczenia 
    	 *  dzialania algorytmu. Zapisaniem tego pola zajmuje sie funkcja
    	 *  QueryPerformanceCounter(LARGE_INTEGER *lp) z pliku <windows.h>
    	 */
 	    LARGE_INTEGER stop;

        /*!
	     *  \brief Pole zawierajace czestotliwosc
	     *  Pole zawiera czestotliwosc. Pole te jest zapisywane przez funkcje 
         *  QueryPerformanceFrequency(LARGE_INTEGER *lp) z pliku <windows.h>
	     */
        LARGE_INTEGER Freq;

};

#endif