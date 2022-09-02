#ifndef LISTSTL_H
#define LISTSTL_H

#include <iostream>
#include <cstdlib>
#include <list>

typedef std::list<int> List;

struct ListSTL {

    ListSTL(){}
    ListSTL(int _lstSize, int _max);
    void InitListSTL();
    void AddTwoKnots();
    void PopBack();
    void PopFront();
    void ShowList();
    void ShowListSize();
    void ShowSeparator(bool _value);
    bool IsEmpty(){return Lst.empty();}
    int ReturnRandValue(){return (rand()%(max+1));}
    
  private:
    
    int max;
    int lstSize;
    List Lst;   
};

#endif
