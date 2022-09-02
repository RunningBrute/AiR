#ifndef LISTELEM_H
#define LISTELEM_H

#include <iostream>
#include <cstdlib>

/*! 
 * Klasa modeluje element, z ktorego zbudowana jest lista.
 */
struct ListElem {
    int data;       // Pole z danymi.
    ListElem *next; // Wskaznik na kolejny element.
    ListElem *prev; // Wskaznik na poprzedni element.
};

#endif
