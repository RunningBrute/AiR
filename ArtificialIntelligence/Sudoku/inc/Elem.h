#ifndef ELEM_H
#define ELEM_H

/*! \file Elem.h
 *
 *  \brief Zawiera definicje klasy Elem
 *
 *  Plik zawiera definicje klasy Elem.  
 *
 *  \author Piotr Basinski
 *  \date 2010.06.09
 *  \version 1.00.00
 */

#include <iostream>

/*! \class Elem
 *  \brief Klasa modeluje rekord z planszy sudoku.
 *  Klasa modeluje zerowy rekord planszy sudoku.
 *  Klasa ta zawiera pozycje poszczegolnych elementow
 *  z macierzy w zmiennych i oraz j. Wartosc liczby
 *  ktora znajduje sie pod rekordem (i,j) przechowywana
 *  jest w zmiennej v. Klasa ta posiada tez zestaw metod
 *  pozwalajacych na odczyt oraz zapis pol klasy.
 */
struct Elem{

    /*!
     *  \brief Konstruktor domyslny
     *  Przypisuje wwartosc 0 do zmiennej v ktora
     *  odpowiada za wartosc rekordu (i,j)
     */
	Elem(){ v = 0; }

    /*!
     *  \brief Konstruktor parametryczny
     *  Konstruktor parametryczny z lista inicjalizacyjna.
     *  Inicjalizuje wszystkie zmienne podanymi wielkosciami.
     *  \param - _i - wiersz
     *  \param - _j - kolumna
     *  \param - _v - wartosc rekordu (_i,_j)
     *  \post Pole i zostaje zainicjalizowane parametrem _i
     *  \post Pole j zostaje zainicjalizowane parametrem _j
     *  \post Pole v zostaje zainicjalizowane parametrem _v
     */
	Elem(int _i, int _j, int _v): i(_i), j(_j), v(_v) {}
    
    /*!
     *  \brief Destruktor domyslny
     *  Destruktor domyslny
     */
	~Elem(){}
    
    /*!
     *  \brief Metoda zwraca numer wiersza
     *  Metoda zwraca numer wiersza
	 *  \post Wartoscia zwracana jest numer wiersza
     */
	int I(){ return i; }

    /*!
     *  \brief Metoda zwraca numer kolumny
     *  Metoda zwraca numer kolumny
	 *  \post Wartoscia zwracana jest numer kolumny
     */
	int J(){ return j; }

    /*!
     *  \brief Metoda zwraca wartosc rekordu (i,j)
     *  Metoda zwraca wartosc rekordu (i,j)
	 *  \post Wartoscia zwracana jest wartosc rekordu (i,j)
     */
	int V(){ return v; }

    /*!
     *  \brief Metoda ustawiajaca numer wiersza
	 *  Metoda ustawia numer wiersza
     *  \param - _i - wiersz
	 *  \post Pole i zostaje zainicjalizowane parametrem _i
     */
	void I(int _i){ i = _i; }

    /*!
     *  \brief Metoda ustawiajaca numer kolumny
	 *  Metoda ustawia numer kolumny
     *  \param - _j - kolumna
	 *  \post Pole j zostaje zainicjalizowane parametrem _j
     */
	void J(int _j){ j = _j; }

    /*!
     *  \brief Metoda ustawiajaca wartosc rekordu (i,j)
	 *  Metoda ustawia wartosc rekordu (i,j)
     *  \param - _v - wartosc rekordu (i,j)
	 *  \post Pole v zostaje zainicjalizowane parametrem _v
     */
	void V(int _v){ v = _v; }

  private:

    /*!
     *  \brief Wiersz
	 *  Wiersz
     */
	int i;

	/*!
     *  \brief Kolumna
	 *  Kolumna
     */
	int j;

	/*!
     *  \brief Wartosc rekordu (i,j)
     *  Wartosc rekordu (i,j)
     */
	int v;

};

#endif