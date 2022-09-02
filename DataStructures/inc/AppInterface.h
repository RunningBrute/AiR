#ifndef APPINTERFACE_H
#define APPINTERFACE_H

#include "../inc/Array2d.h"
#include "../inc/ListSTL.h"
#include "../inc/StackSTL.h"
#include "../inc/QueueSTL.h"
#include "../inc/List2s.h"
#include "../inc/Stack2s.h"
#include "../inc/Queue2s.h"

/*!
 * Klasa pozwalajaca na wygodny dostep oraz wygodne operowanie na roznych 
 * typach danych. Interfejs pozwala na dokladne kontrolowanie kazdej
 * ze struktury danych zawartej w polach klasy. 
 */
struct AppInterface {
       
    /* 
     * Konstruktor domyslny.
     */
    AppInterface(){}
    
    /*
     * Metoda inicjalizujaca dynamicza tablice o dwuch wymiarach. W metodzie
     * tej znajduja sie wszystkie wywolania metod klasy 'array2d'.
     */
    void Array2dStart();
    
    /*
     * Metoda inicjalizujaca szablon listy std::<list>.
     */
    void ListSTLStart();
    
    /*
     * Metoda inicjalizujaca szablon stosu std::<stack>.
     */
    void StackSTLStart();
    
    /*
     * Metoda inicjalizujaca szablon kolejki std::<queue>.
     */
    void QueueSTLStart();
    
    /* 
     * Metoda inicjalizujaca liste dwukierunkowa.
     */
    void List2sStart();
    
    /*
     * Metoda inicjalizujaca stos oparty na liscie dwukierunkowej 'list2s'.
     */
    void Stack2sStart();
    
    /*
     * Metoda inicjalizujaca kolejke oparta na liscie dwukierunkowej 'list2s'.
     */
    void Queue2sStart();
    
    /*
     * Metoda ta ma za zadanie wywolac wszystkie funkcje sterujace 
     * poszczegolnymi typami danych.
     */
    void Run();
       
  private:
    
    Array2d  array2d;    // Tablica dwuwymiarowa
    ListSTL  listSTL;    // Lista z uzyciem std::<list>
    StackSTL stackSTL;   // Stos z uzyciem std::<stack>
    QueueSTL queueSTL;   // Kolejka z uzyciem std::<queue>
    List2s   list2s;     // Lista implementowana samodzielnie
    Stack2s  stack2s;    // Stos implementowany samodzielnie
    Queue2s  queue2s;    // Kolejka implementowana samodzielnie
};

#endif
