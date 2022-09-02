#ifndef STACK2S_H
#define STACK2S_H

#include "../inc/List2s.h"

struct Stack2s {
    
    Stack2s(){}
    Stack2s(int _stkSize, int _max);
    void InitStack2s(){ Stk.InitList2s(); }
    void Push(int _data){ Stk.PushFront(_data); }
    void Pop(){ Stk.PopFront(); }
    bool Empty(){ Stk.Empty(); }
    void InitRandValues(){ Stk.InitRandValues(); }
    void ShowStack(){ Stk.ShowList(); }
    void ShowFirstElem(){ Stk.ShowFront(); }
    void ShowStackSize(){ Stk.ShowListSize(); }
    void ShowSeparator(bool _value);

  private:

    int max;
    int stkSize;
    List2s Stk;
};

#endif
