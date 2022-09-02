#include "../inc/AppInterface.h"

void AppInterface::Array2dStart(){
  array2d.ShowSeparator(true);
  array2d.InitArray();
  array2d.ShowArrayValues();
  array2d.ShowFieldsValues();
  array2d.ShowSeparator(false);
};

void AppInterface::ListSTLStart(){
  listSTL.ShowSeparator(true);
  listSTL.InitListSTL();
  listSTL.AddTwoKnots();
  listSTL.PopBack();
  listSTL.PopFront();
  listSTL.ShowList();
  listSTL.ShowListSize();
  listSTL.ShowSeparator(false);
};

void AppInterface::StackSTLStart(){
  stackSTL.ShowSeparator(true);
  stackSTL.InitStackSTL();
  stackSTL.ShowFirstElem();
  stackSTL.Pop();
  stackSTL.ShowStackSize();
  stackSTL.ShowSeparator(false);
};

void AppInterface::QueueSTLStart(){
  queueSTL.ShowSeparator(true);
  queueSTL.InitQueueSTL();
  queueSTL.Front();
  queueSTL.Pop();
  queueSTL.ShowQueueSize();
  queueSTL.ShowSeparator(false);
};

void AppInterface::List2sStart(){
  list2s.ShowSeparator(true);
  list2s.InitList2s();
  list2s.AddTwoKnots();
  //list2s.PopBack();
  list2s.PopFront();
  list2s.ShowList();
  list2s.ShowListSize();
  list2s.ShowSeparator(false);
};

void AppInterface::Stack2sStart(){
  stack2s.ShowSeparator(true);
  stack2s.InitStack2s();
  stack2s.ShowFirstElem();
  stack2s.Pop();
  stack2s.ShowStackSize();
  stack2s.ShowSeparator(false);
};

void AppInterface::Queue2sStart(){
  queue2s.ShowSeparator(true);
  queue2s.InitQueue2s();
  queue2s.Front();
  //queue2s.Pop();
  queue2s.ShowQueueSize();
  queue2s.ShowSeparator(false);
};

void AppInterface::Run(){
  //Array2dStart();
  //ListSTLStart();
  //StackSTLStart();
  //QueueSTLStart();
  List2sStart();
  Stack2sStart();
  Queue2sStart();
};
