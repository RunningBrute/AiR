#ifndef ELEM_H
#define ELEM_H

/*! \file Elem.h
 *
 *  \brief Zawiera definicje klasy Elem
 *
 *  Plik zawiera definicje klasy Elem.  
 *
 *  \author Piotr Basinski
 *  \date 2010.08.01
 *  \version 1.00.00
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

/*! \class Elem
 *  \brief Modeluje krawedz wraz z informacjami o niej 
 *  Klasa ta zawiera pola, ktore zawieraja informacje o danej krawedzi. 
 *  Interfejs klasy pozwala na zmiane oraz wyswietlenie kazdej zmiennej.
 */
	 
struct Elem{

	/*!
	 *  \brief Konstruktor bezparametryczny
	 *  Ustawia wszystkie pola na wartosc domysla, ktora jest 0.
	 */
	Elem();

	/*!
	 *  \brief Metoda ustawiajaca numer wierzczolka
	 *  Metoda ta ustawai kolejna wspolrzedne wierzcholkow \link Elem::vertexA vertexA\endlink
	 *  oraz \link Elem::vertexB vertexB\endlink.
	 *  \param _vertexA - wartosc ustawiajaca wierzcholek \link Elem::vertexA vertexA\endlink
	 *  \param _vertexB - wartosc ustawiajaca wierzcholek \link Elem::vertexB vertexB\endlink
     *  \pre Wierzcholki musza byc liczba z zakresu 0 - \link Elem::vVertex vVertex\endlink
     */
	void SetVertex(int _vertexA, int _vertexB){ vertexA = _vertexA; vertexB = _vertexB; }

	/*!
	 *  \brief Metoda ustawiajaca wage krawedzi 
	 *  Metoda ustawia wage krawedzi miedzy wierzcholkami \link Elem::vertexA vertexA\endlink
	 *  oraz \link Elem::vertexB vertexB\endlink. 
	 *  \param _weight - wartosc ustawiajaca wage 
	 *  \pre Waga misi byc z zakresu 1 - 9. Waga zerowa Jest zarezerwowana dla braku po³¹czenia
	 */
	void SetWeight(int _weight){ weight = _weight; }

	/*!
	 *  \brief Metoda ustawiajaca kolor krawedzi 
	 *  Metoda ustawia kolor krawedzi. Kolor jest uzywany do oznaczenia krawedzi w drzewie.
     *  Mowi to nam do jakiego drzewa dana krawedz nalezy.  
	 *  \param _color - wartosc ustawiajaca kolor 
	 *  \pre Kolor musi byc z zakresu -9 - -1.
	 */
	void SetColor(int _color){ color = _color; }

	/*!
	 *  \brief Metoda zwracajaca wage krawedzi
	 *  Metoda zwracajaca wage krawedzi.
	 *  \post wartoscia zwracana jest waga (liczba typu int z zakresu 1 - 9)
	 */
	int ReturnWeight(){ return weight; }

	/*!
	 *  \brief Metoda zwracajaca wierzcholek 
	 *  Metoda zwracajaca wierzcholek \link Elem::vertexA vertexA\endlink.
	 *  \post wartoscia zwracana jest liczba typu int z zakresu 1 - vVertex.
	 */
	int ReturnVertexA(){ return vertexA; }
 
    /*!
	 *  \brief Metoda zwracajaca wierzcholek 
	 *  Metoda zwracajaca wierzcholek \link Elem::vertexB vertexB\endlink.
	 *  \post wartoscia zwracana jest liczba typu int z zakresu 1 - vVertex.
	 */
	int ReturnVertexB(){ return vertexB; }

	/*!
	 *  \brief Metoda zwracajaca kolor krawedzi 
	 *  Metoda zwracajaca kolor krawedzi, ktory okresla dostepnosc krawedzi
     *  i jej przynaleznosc do drzewa.
	 *  \post wartoscia zwracana jest liczba typu int z zakresu 1 - vEdges.
	 */
	int ReturnColor(){ return color; }

	/*!
	 *  \brief Metoda wyswietlajaca informacje o klasie
     *  Metoda wyswietla wspolrzedne krawedzi wraz z jej waga w postaci (1,5;5) -
     *  gdzie kolejne liczy to:
     *  pierwszy wiercholek - \link Elem::vertexA vertexA\endlink
     *  drugi wierzcholek - \link Elem::vertexB vertexB\endlink
     *  waga krawedzi - \link Elem::weight veight\endlink
	 */
    void ShowInfo();

  private:

    /*!
	 *  \brief Pole zawierajace numer wierzcholka
	 *  Pole odpowiedzialne za przetrzymywanie numeru wierzcholka
	 */
    int vertexA;

	/*!
	 *  \brief Pole zawierajace numer wierzcholka
	 *  Pole odpowiedzialne za przetrzymywanie numeru wierzcholka
	 */
    int vertexB;

	/*!
	 *  \brief Pole zawierajace wage krawedzi
	 *  Pole odpowiedzialne za przetrzymywanie wagi krawedzi
	 */
	int weight;

	/*!
	 *  \brief Pole zawierajace kolor krawedzi
	 *  Pole odpowiedzialne za przetrzymywanie koloru krawedzi
	 */
	int color;

};
#endif

