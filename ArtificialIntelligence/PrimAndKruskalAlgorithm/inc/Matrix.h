#ifndef MATRIX_H
#define MATRIX_H

/*! \file Matrix.h
 *
 *  \brief Zawiera definicje klasy Matrix
 *
 *  Plik zawiera definicje klasy Matrix. Obiektem tej klasy jest dynamiczna
 *  tablica dwuwymiarowa zawierajaca elementy typu int.
 
 *  \author Piotr Basinski
 *  \date 2010.08.01
 *  \version 1.00.00
 */
 
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

/*! \class Matrix
 *  \brief Modeluje graw w postaci macierzy sasiedztwa. Macierz ta 
 *  reprezentowana jest przez dynamiczna tablice dwuwymiarowa. Pola tej klasy
 *  zawieraj¹ informacje na temat wielkoœci grafu oraz jego ilosci krawedzi
 *  w nim wystepujacych.
 */ 
struct Matrix{
    
    /*!
     *  \brief Konstruktor domyslny
     *  Przypisuje domyslna wartosc wierzcholkow dla grafu jego gestosc oraz przypisuje
     *  wartosc NULL do zmiennej \link Matrix::**Array **Array\endlink.
	 *  Wywolanie metody DeleteConnectionsValue() powoduje obliczenie krawedzi do usuniecia.
	 *  Zerowany jest tez tutaj generator pseudolosowy dla zwiekszenia losowosci
	 *  grafu. 
     */
    Matrix();      
    
    /*!
     *  \brief Konstruktor parametryczny
     *  Przypisuje wartosc _vVertex podana przez uzytkownika do zmiennej
     *  \link Matrix::vVertex vVertex\endlink oraz wartosc NULL do zmiennej 
     *  \link Matrix::**Array **Array\endlink. Gestosc grafu jest ustalana
	 *  przez zmienna _density.
     *  \param _vVertex - ilosc wierzcholkow grafu
	 *  \param _density - gestosc grafu
     *  \pre Wartosc parametru \e _vVertex musi byc zawsze wieksza od 0.
	 *  \pre Gestosc to liczby ze zbioru {0.25, 0.5, 0.75}
     *  \post Wartosc parametru \e _vVertex zostaje przypisana polu
     *  \link Matrix::vVertex vVertex\endlink.
	 *  \post Wartosc parametru \e _density zostaje przepisana do pola 
	 *  \link Matrix::density density\endlink.
     */
    Matrix(int _vVertex, double _density);
    
    /*!
     *  \brief Destruktor domyslny
     *  Usowa z pamieci tab. dynamiczna \link Matrix::**Array **Array\endlink.
     */
    ~Matrix();

	/*!
	 *  \brief Metoda ustawiajaca liczbe wierzcholkow grafu
	 *  Metoda ustala liczbe wierzcholkow grafu. 
	 *  \param _vVertex - nowa liczba wirzcholkow 
	 *  \pre Liczba wierzcholkow musi byc rozna od zera
	 *  \post Zmienna _vVertex jest zapisana do pola 
	 *  \link Matrix::vVertex vVertex\endlink
	 */
	void SetVertex(int _vVertex){ vVertex = _vVertex; }

	/*!
	 *  \brief Metoda ustawiajaca gestosc grafu
	 *  Metoda ustala gestosc grafu. 
	 *  \param _density - nowa wartosc gestosc grafu 
	 *  \pre Gestosc grafu musi byc z zakresu 0 - 1
	 *  \post Zmienna _density jest zapisana do pola 
	 *  \link Matrix::density density\endlink
	 */
	void SetDensity(double _density){ density = _density; }
    
    /*!
     *  \brief Metoda deklarujaca talice dynamiczna
     *  Metoda pozwala zadeklarowac dynamiczna tablice dwuwymiarowa o szerokosci
     *  oraz wysokosc vVertex.
     */
    void InitMatrix();
    
	/*
	 *  \brief Metoda usowajaca wymagana ilosc krawedzi
	 *  Metoda usowa wymagana ilosc krawedzi. Informacja o ilosc 
	 *  zawarta jest w zmiennej \link Matrix::dConnections dConnevtions\endlink
	 */
	void DeleteConnections();

    /*!
     *  \brief Metoda losujaca graf
     *  Metoda odpowiedzialna za kolejne wykonanie metod pozwalajacych
	 *  na wygenerowanie losowego grafu.
     */
    void RandGraph();

    /*!
     *  \brief Metoda losujaca wierzcholek
     *  Metoda losuje wierzcholek. Liczba losowana jest zapisywana 
	 *  w tablicy Array[i][j].
	 *  \post Wartosc typu int z zakresu 0 - vVertex (aby pasowalo
     *  do indeksow tablicy) 
     */
    int ReturnRandVertex(){ return (rand() % vVertex); }
    
    /*!
     *  \brief Metoda losujaca wage krawedzi z przedzialu 1 - 9
     *  Metoda losuje wage krawedzi z przedzialu 1 - 9. 
	 *  \post Wartoscia zwracana jest liczba typu int z przedzialu
	 *  1 - 9.
     */
    int ReturnRandValue(){ return (1 + (rand() % 9)); }

	/*!
	 *  \brief Metoda losujaca wage krawedzi z przedzialu 0 - 9
	 *  Metoda losuje wage krawedzi. Dopuszczalna jest tez wartosc 
     *  0, ktora opisuje brak polaczenia.
     *  \post Wartoscia zwracana jest liczba typu int z przedzialu
     *  0 - 9  
	 */
	int ReturnRandValueWithZero(){ return (rand() % 10); }
	
	/*!
	 *  \brief Metoda zwracajaca dany element tablicy
	 *  Metoda zwraca dany element tablicy Array[i][j] przez
	 *  bezposrednie odwolanie sie do odpowiedniego wiersza i kolumny.
	 *  \param _i - wiersz macierzy
	 *  \param _j - kolumna macierzy
	 *  \pre Zmienna _i jak i _j musi byc z zakresu 0 - vVertex
     *  \post Wartoscia zwracana jest element typu int. Odpowiada on wadze 
     *  polaczenia wierzcholka _i z _j 
	 */
	int ReturnArrayElement(int _i, int _j){ return Array[_i][_j]; }

	/*!
	 *  \brief Metoda obliczajaca minimalna ilosc polaczen w grafie
	 *  Metoda oblicza minimalna wartosc ilosc polaczen ktore musza 
	 *  zostac w grafie aby graf byl dalej spojny oraz posiadal odpowiednia
	 *  gestosc. Ilosc ta jest obliczana ze wzoru (1 - gestosc_grafu)*liczba_krawedzi.
	 *  \post Wartoscia zwracana jest liczba typu int opisujaca minimalna 
	 *  wartosc krawedzi spelniajaca powyzsze warunki
	 */
	int DeleteConnectionsValue(){ return static_cast<int>((1 - density)*vEdge); }

	/*!
	 *  \brief Metoda zwracajaca ilosc wierzcholkow
	 *  Metoda zwraca liczbe wierzcholkow wygenerowanego grafu.
	 *  \post Wartoscia zwracana jest liczba \link Matrix::vVertex vVertex\endlink
	 */
	int ReturnVertexValue(){ return vVertex; }

    /*!
     *  \brief Metoda zerujaca wartosci diagonalne macierzy
     *  Metoda resetuje wartosci macierzy znajdujace sie na jej przekatnej 
	 *  (Array[i][j], gdzie i == j). 
     */
    void ResetDiagonal();
    
    /*!
     *  \brief Metoda wyswietlajaca macierz sasiedztwa
     *  Metoda wyswietlajaca macierz sasiedztwa.
     */
    void ShowMatrix();
    
    /*!
     *  \brief Metoda wyswietlajaca informacje 
     *  Metoda wyswietla informacje o macierzy. Sa nimi liczba krawedzi
	 *  do usuniecia \link::Matrix dConnections dConnections\endlink,
	 *  liczba krawedzi w grafie \link::Matrix vEdges vEdges\endlink
	 *  oraz liczba wierzcholkow \link::Matrix vVertex vVertex\endlink.
     */
    void ShowInfo();
    
    /*!  
     *  \brief Metoda resetujaca macierz sasiedztwa
	 *  Metoda ta resetuje macierz sasiedztwa zapisujac wszystkie pola
	 *  zerami.
     */
    void ResetMatrix();
    
    /*!
     *  \brief Metoda losujaca macierz
     *  Metoda ta wywoluje kolejno po sobie metody pozwalajace na odpowiednie
	 *  wygenerowanie grafu w postaci macierzy sasiedztwa.
     */
    void RandMatrix();
    
    /*!
     *  \brief Metoda obliczajaca ilosc krawedzi grafu
     *  Metoda oblicza ilosc krawedzi jaka moze zawierac grac wedlug wzoru 
     *  (n^2)/2 - n/2, gdzie n to zmienna \link Matrix::vVertex vVertex\endlink.
     *  \post Zwraca wartosc krawedzi w grafie obliczanych ze wzoru (n^2)/2 - n/2
     */
    int vEdgeCount(){ return (((vVertex*vVertex)/2) - (vVertex/2)); }

  private:
          
    /*! 
	 *  \brief Wskaznik na dwuwymiarowa tablice dynamiczna
     *  Pole zawiera wskaznik na dynamiczna tablice dwuwymiarowa. Jest ono 
     *  niezbedne do pozniejszego zadeklarowania tablicy.    
     */
    int **Array;
    
    /*! 
	 *  \brief Liczba wierzcholkow grafu
     *  Pole zawiera ilosc wierzcholkow grafu. Jest ono niezbedne do poprawnego 
     *  zadeklarowania tablicy \link Matrix::**Array **Array\endlink. Rozmiar
     *  macierzy wyraza sie nastepujaco: vVertex x vVertex.
     */
    int vVertex;
    
    /*! 
	 *  \brief Liczba krawedzi w grafie
     *  Pole zawiera ilosc krawedzi w grafie. Zmienna jest obliczana ze wzoru 
     *  (n^2)/2 - n/2, gdzie n to zmienna \link Matrix::vVertex vVertex\endlink.
     */
    int vEdge;

	/*!
	 *  \brief Gestosc grafu
	 *  Zmienna mowiaca o tym jaka gestosc ma graf. Zmienna jest z zakresu 0 - 1.
	 *  Dla tego programu uzywanymi wartosciami sa wartosci z zakresu {0.25, 0.5, 0.75}
	 */
	double density;

	/*!
	 *  \briel Liczba polaczen do usuniecia  
	 *  Liczba polaczenm ktore nalezy usonac aby dany graf byl
	 *  grafem o danej gestosc. 
	 */
	int dConnections;
};

#endif
