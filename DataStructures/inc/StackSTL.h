#ifndef STACKSTL_H
#define STACKSTL_H

#include <iostream>
#include <cstdlib>
#include <stack>

typedef std::stack<int> Stack;

struct StackSTL {
  
    StackSTL(){}
    StackSTL(int _stkSize, int _max);
    void InitStackSTL();
    void ShowFirstElem();
    void Pop();
    void ShowStackSize();
    void ShowSeparator(bool _value);
    int ReturnRandValue(){return (rand()%(max+1));}
    
  private:
    
    int max;      
    int stkSize;      
    Stack Stk;    
};

#endif
