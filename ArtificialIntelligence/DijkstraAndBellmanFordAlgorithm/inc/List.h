#ifndef LIST_H
#define LIST_H

/*! \file List.h
 *
 *  \brief Zawiera definicje klasy List
 *
 *  Plik zawiera definicje klasy List. Klasa ta korzysta z szablonow
 *  STL. Sa nimi std::<vector> - odpowiedzialny z dodanie dynamicznej tablicy
 *  oraz std::<list> - odpowiedzialny za liste. Klasa ta korzysta z elementow
 *  typu Elem dostepnych w pliku Elem.h.
 *
 *  \author Piotr Basinski
 *  \date 2010.08.01
 *  \version 1.00.00
 */

#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>
#include "../inc/Elem.h"

struct List{
    
	/*!
	 *  \brief Konstruktor bezparametryczny
	 *  Domyslny konstruktor bezparametryczny.
	 */
	List(){}

	/*!
	 *  \brief Ustawia ilosc wierzcholkow
	 *  Metoda ustawia ilosc wierzcholkow ktore beza budowac liste sasiedztwa.
	 *  \param _vVertex - ilosc wierzcholkow
	 *  \pre Wartosc parametru _vVertex musi byc wieksza od zera
	 *  \post Parametr _vVertex jest zapisywany w polu 
     *  \link List::vVertex vVertex\endlink
	 */
	void SetVertexValue(int _vVertex){ vVertex = _vVertex; }

	/*!
	 *  \brief Dodaje element do tablicy 
	 *  Metoda dodajaca liste elementow typu Elem do tablicy dynamicznej 
	 *  graph[i]. Do dodania listy uzyta jest metoda push_back.
	 */
	void SetArrayElement(){ std::list<Elem> list; graph.push_back(list); }

	/*!
	 *  \brief Dodaje element do listy 
	 *  Metoda dodajaca podany element typu Elem do listy sasiedztwa.
	 *  Mozliwe jest dolaczenie do _i - tego wiersza tablicy.
	 *  \param _i - liczba reprezentujaca wiersz tablicy 
	 *  \param _elem - element dodany do listy w danym rekordzie tabeli
	 *  \pre Parametr _i musi byc z zakresu 0 - (vVertex - 1)
	 *  \post Parametr _elem zostaje zapisany do tablicy list graph
	 */
	void SetListElement(int _i, Elem _elem){ graph[_i].push_back(_elem); }

	/*!
	 *  \brief Metoda wyswietlajaca dany graf
     *  Metoda wyswietla dany graf w postaci V1 -- (1,4;6), gdzie kolejne 
     *  pola to V1 - numer wierzcholka odniesienia, 1 - wiercholek pierwszy
     *  4 - wierzcholek drugi, 6 - waga krawedzi. 
	 */
	void ShowGraph();

	/*!
     *  \brief Metoda wyswietlajaca informacje 
     *  Metoda wyswietla informacje o liscie. Informacje to zawieraja
	 *  liczbe wierzchoklow dostepnych w grafie. 
     */
    void ShowInfoList();

	/*!
	 */
	void ClearList(){ graph.clear(); }

  private:

    /*!
	 *  \brief Liczba wierzcholkow
	 *  Pole zawiera liczbe wierzcholkow dostepnym w grafie.
	 */
	int vVertex;

  public:

    /*!
	 *  \brief Lista sasiedztwa
	 *  Lista sasiedztwa zrealizowana przy pomocy kontenerow z
	 *  plikow <vector> oraz <list>. obiekt graph jest tablica 
	 *  list elementow typu Elem.
	 */
    std::vector< std::list<Elem> > graph;
};

#endif
