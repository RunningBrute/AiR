#ifndef QUEUE2S_H
#define QUEUE2S_H

#include "../inc/List2s.h"

struct Queue2s {
    
    Queue2s(){}
    Queue2s(int _queSize, int _max);
    void InitQueue2s(){ Que.InitList2s(); }
    void Push(int _data){ Que.PushFront(_data); }
    void Pop(){ Que.PopBack(); }
    bool Empty(){ Que.Empty(); }
    void InitRandValues(){ Que.InitRandValues(); }
    void ShowQueue(){ Que.ShowList(); }
    void Front(){ Que.ShowBack(); }
    void ShowQueueSize(){ Que.ShowListSize(); }
    void ShowSeparator(bool _value);
    
  private:
          
    int max;
    int queSize;
    List2s Que;
};

#endif
