#ifndef FORD_H
#define FORD_H

/*!
 *
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "../inc/Elem.h"
#include "../inc/Matrix.h"
#include "../inc/List.h"

#define INF 100

/*!
 *
 */
struct Ford{

	/*!
	 *
	 */
	Ford(){}

	/*!
	 *
	 */
	~Ford(){}

	/*
	 */
	void FordStartArray(Matrix _G, int _s);


    /*
	 */
	void ShowTree();

  private:

	/*!
	 *
	 */
    std::vector<Elem> SPT;

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
