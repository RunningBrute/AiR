#ifndef KRUSKAL_H
#define KRUSKAL_H

/*! \file Kruskal.h
 *
 *  \brief Zawiera definicje klasy Kruskal
 *
 *  Plik zawiera definicje klasy Kruskal. Klasa ta korzysta z szablonow
 *  STL. Sa nimi std::<vector> - odpowiedzialny z dodanie dynamicznej tablicy
 *  oraz std::<list> - odpowiedzialny za liste. Klasa ta korzysta z elementow
 *  typu Elem dostepnych w pliku Elem.h, Matrix z Matrix.h oraz List x List.h. 
 *
 *  \author Piotr Basinski
 *  \date 2010.08.01
 *  \version 1.00.00
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "../inc/Elem.h"
#include "../inc/Matrix.h"
#include "../inc/List.h"

/*! \class Kruskal
 *  \brief Modeluje klase zawierajaca algorytm Kruskala
 *  Klasa modeluje algorytm Kruskala. Dziedziczy ona dwie klasy
 *  Matrix oraz List. Umozliwia to wykonanie operacji znajdowania
 *  MST dla roznych reprezentacji grafu. Klasa zawiera tez metode 
 *  odpowiedzialna za przepisanie grafu z reprezentacji 
 *  macierzy sasiadow na liste sasiedztwa. Polami tej klasy sa 
 *  tablice odpowiedzialne za przechowanie MST oraz bufora krawedzi.
 */
	 
struct Kruskal: public Matrix, public List{
    
	/*!
     *  \brief Konstruktor bezparametryczny
	 *  Domyslny konstruktor bezparametryczny.
     */
	Kruskal(){}

	/*!
     *  \brief Start algorytmu Kruskala dla tablicy
	 *  Metoda odpowiedzialna za kolejne wykonywanie metod
	 *  doprowadzajacych do wykonania algorytmu Kruskala na tablicy
	 *  sasiadow.
     */
	void KruskalStartArray();

	/*!
     *  \brief Start algorytmu Kruskala dla listy
	 *  Metoda odpowiedzialna za kolejne wykonywanie metod
	 *  doprowadzajacych do wykonania algorytmu Kruskala na liscie
	 *  sasiedztwa.
     */
	void KruskalStartList();

	/*!
     *  \brief Tworzy liste krawedzi
	 *  Metoda tworzy liste krawedzi z danego wiersza tablicy sasiadow.
	 *  \post Do bufora bufor[i] zostaje zapisany dany wiersz z tablicy
	 *  sasiadow.
     */
	void SetListOfVertexFromArray();
    
    /*!
     *  \brief Tworzy liste krawedzi
	 *  Metoda tworzy liste krawedzi z danej listy sasiedztwa.
	 *  \post Do bufora bufor[i] zostaje zapisana dana lista z tablicy
     */
	void SetListOfVertexFromList();

	/*!
     *  \brief Zwraca minimalny element
	 *  Metoda zwraca minimalny element o minimalnej wadze
	 *  z bufora. 
	 *  \post Zwracany jest element typu Elem, ktory zawiera najmniejsza
     *  wage ze wszystkich krawedzi w tablicy. Najmniejszy element 
	 *  bufora jest oznaczany (waga = 0) aby nie zostal wybrany ponownie 
	 *  w kolejnym kroku.
     */
	Elem ReturnMinElem();

	/*!
     *  \brief Metoda sortujaca
     *  Metoda odpowiedzialna za sortowanie bufora w celu 
     *  uporzadkowania tablicy. Jest to potrzebne do dajszej czesci 
     *  funkcjonowania algorytmu Kruskala.
     */
	void Sort(); 

	/*!
     *  \brief Sprawdzanie czy element jest juz w buforze
	 *  Metoda sprawdzajaca obecnosc elementu _elem
	 *  w buforze.
	 *  \param _elem - sprawdzany element
	 *  \post Zwracana wartoscia jest true gdy dany element wystapi
	 *  w przeciwnym razie zwracana wartoscia jest false
     */
	bool Is(Elem _elem);

	/*!
     *  \brief Sprawdza czy nastapil cykl
	 *  Metoda sprawdzajaca czy element _elem powoduje wywolanie cyklu.
	 *  \param _elem - sprawdzany element
	 *  \post Zwracana wartosca jest tru gdy dany element tworzy cykl
	 *  false w przeciwnym wypadku
     */
	bool IsCycle(Elem _elem);

	/*!
     *  \brief Przepisanie macierzy do listy
	 *  Metoda odpowiedzialna za przepisanie macierzy sasiedztwa
	 *  do listy sasiadow. Wartosci zerowe w tablicy sa ignorowane.
     */
	void WriteMatrixToList();

	/*!
     *  \brief Start listy
	 *  Metoda odpowiedzialna za zainiciowanie listy i wszelkie operacje
	 *  potrzebne do prawidlowego wygenerowania listy.
     */
	void ListStart();

	void RunKruskalAndShowTime(int _i);

	/*!
     *  \brief Metoda wyswietlajaca MST
	 *  Metoda odpowiedzialna za odpowiednie wyswietlenie MST.
     */
    void ShowMST();

  private:
    
	/*!
     *  \brief Tablica zawierajaca MST
	 *  Pole zawiera tablice zawierajaca najmniejsze drzewo
	 *  rozpinajace. Jako struktura danych do reprezentacji 
	 *  MST uzyta zostala tablica dynamiczna z STL.
     */
    std::vector<Elem> MST;

	/*!
     *  \brief Tablica zawierajaca bufor
	 *  Pole zawiera tablice zawierajaca liste wierzcholkow
	 *  sukcesywnie dopelninych o nowe pozycje.
     *  Jako struktura danych do reprezentacji bufora uzyta zostala
     *  tablica dynamiczna z STL.
     */
	std::vector<Elem> bufor;

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
