#ifndef PRIM_H
#define PRIM_H

/*! \file Prim.h
 *
 *  \brief Zawiera definicje klasy Prim
 *
 *  Plik zawiera definicje klasy Prim. Klasa ta korzysta z szablonow
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


/*! \class Prim
 *  \brief Modeluje klase zawierajaca algorytm Prima
 *  Klasa modeluje algorytm prima. Dziedziczy ona dwie klasy
 *  Matrix oraz List. Umozliwia to wykonanie operacji znajdowania
 *  MST dla roznych reprezentacji grafu. Klasa zawiera tez metode 
 *  odpowiedzialna za przepisanie grafu z reprezentacji 
 *  macierzy sasiadow na liste sasiedztwa. Polami tej klasy sa 
 *  tablice odpowiedzialne za przechowanie MST oraz bufora krawedzi.
 */
struct Prim: public Matrix, public List{

    /*!
     *  \brief Konstruktor bezparametryczny
	 *  Domyslny konstruktor bezparametryczny.
     */
	Prim(){}

	/*!
     *  \brief Start algorytmu Prima dla tablicy
	 *  Metoda odpowiedzialna za kolejne wykonywanie metod
	 *  doprowadzajacych do wykonania algorytmu Prima na tablicy
	 *  sasiadow.
     */
    void PrimStartArray();

	/*!
     *  \brief Tworzy liste krawedzi
	 *  Metoda tworzy liste krawedzi z danego wiersza tablicy sasiadow.
	 *  \param _i - indeks wiersza tablicy
	 *  \pre Parametr _i musi byc z zakresu 0 - (vVertex - 1)
	 *  \post Do bufora bufor[i] zostaje zapisany dany wiersz z tablicy
	 *  sasiadow.
     */
    void SetListOfVertexFromArray(int _i);

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
     *  \brief Oznacza dany element
	 *  Metoda oznacza element _elem jezeli ten wystapil juz w byforze.
	 *  Oznaczanie polega na przypisaniu wadze zera.
	 *  \param _elem - sprawdzany element
     */
	void DeleteElem(Elem _elem);

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
	 *  \brief Zwraca ostatni wierzcholek z MST
	 *  Zwraca ostatni wierzcholek z MST. 
	 *  \param _start - okresla czy zwracany wierzcholek jest 
	 *  potrzebny do startu
	 *  \post W przypadku gdy parametr _start posiad wartosc 0 zwracany
	 *  jest pierwszy element, gdy dana jest inna liczy wierzcholek 
	 *  zwracany jest ostatnim wierzchokliem obecnym w MST
	 */
    int ReturnLastVertexFromMST(int _start);

	/*!
     *  \brief Metoda wyswietlajaca MST
	 *  Metoda odpowiedzialna za odpowiednie wyswietlenie MST.
     */
	void ShowMST(); 

	/*!
     *  \brief Metoda wyswietlajaca bufor
	 *  Metoda odpowiedzialna za wyswietlenie bufora.
     */
	void ShowBufor();

	/*!
	 *  \brief Metoda wyswietlajaca czas wykonania _i instancji
	 *  Metoda wyswietla czas wykonania _i instancji algorytmu prima dla _i losowych grafów.
	 *  Wynik eksperymentu jest usredniany. Do obliczenia czasu potrzebnego na wykonanie 
	 *  szeregu eksperymentow uzyte zostaly funkcje QueryPerformanceFrequency() oraz
     *  QueryPerformanceCounter().
	 *  \param _i - liczba wykonywanych instancji
     */
	void RunPrimAndShowTime(int _i);

	/*!
     *  \brief Start algorytmu Prima dla listy
	 *  Metoda odpowiedzialna za kolejne wykonywanie metod
	 *  doprowadzajacych do wykonania algorytmu Prima na liscie
	 *  sasiedztwa.
     */
	void PrimStartList();

	/*!
     *  \brief Tworzy liste krawedzi
	 *  Metoda tworzy liste krawedzi z danej listy sasiedztwa.
	 *  \param _i - indeks komorki tablicy
	 *  \pre Parametr _i musi byc z zakresu 0 - (vVertex - 1)
	 *  \post Do bufora bufor[i] zostaje zapisana dana lista z tablicy
     */
	void SetListOfVertexFromList(int _i);

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

