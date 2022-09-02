#ifndef LIST2S_H
#define LIST2S_H

#include <iostream>
#include <cstdlib>
#include "../inc/ListElem.h"

/* 
 * Klasa modelujaca lista dwukierunkowa. Metody zawarte w tej klasie pozwalaja
 * na dodawanie oraz usowanie elementow z poczatku i konca listy, zainicjowania
 * listy losowymi wartosciami, pokazania listy, oraz sprawdzenia czy jest pusta.
 * Ponadto klasa zawiera generator liczb losowych. 
 */
struct List2s {
    
    /*
     * Konstruktor bezparametryczny. Ustawia domysle wartosci parametrow listy
     * oraz generuje ja nadaja kazdemu elementowi wartosc losowa.
     */
    List2s();
    
    List2s(int _lstSize, int _max);
    void InitList2s();
    void AddTwoKnots();
    void PushFront(int _data);
    void PushBack(int _data);
    void PopFront();
    void PopBack();
    bool Empty(){ return (head == NULL); }
    void InitRandValues();
    int ReturnRandValue(){return (rand()%(max+1));}
    void ShowListSize();
    void ShowList();
    void ShowFront();
    void ShowBack();
    void ShowSeparator(bool _value);
    
  private:
          
    int max;
    int lstSize;      
    ListElem *head;
    ListElem *tail;
};

#endif
