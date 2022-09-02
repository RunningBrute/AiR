#ifndef QUEUESTL_H
#define QUEUESTL_H

#include <iostream>
#include <cstdlib>
#include <queue>

typedef std::queue<int> Queue;

struct QueueSTL {
    
    QueueSTL(){}
    QueueSTL(int _queSize, int _max);
    void InitQueueSTL();
    void Front();
    void Pop();
    void ShowQueueSize();
    int ReturnRandValue(){return (rand()%(max+1));}
    void ShowSeparator(bool _value);

  private:
    
    int max;
    int queSize;
    Queue Que;  
};

#endif
