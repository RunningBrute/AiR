#include "../inc/List2s.h"

List2s::List2s(){
  head = tail = NULL; max = 40; lstSize = 0;
};

List2s::List2s(int _lstSize, int _max){
  head = tail = NULL; max = _max; lstSize = _lstSize;
};

void List2s::InitList2s(){
  std::cout << " Elements amount ... "; std::cin >> lstSize;
  max = 88;
  InitRandValues();
};

void List2s::AddTwoKnots(){
  int elem;
  std::cout << " Add first element ... "; std::cin >> elem;
  PushFront(elem); 
  std::cout << " Add second element ... "; std::cin >> elem;
  PushFront(elem);
};

void List2s::ShowListSize(){
  ListElem *pTmp;
  int licznik = 0;
  for (pTmp = head; pTmp != NULL; pTmp = pTmp->next, licznik++){}
  std::cout << std::endl;
  std::cout << " Size: " << licznik << std::endl;
};

void List2s::PushFront(int _data){
  std::cout << "     list2s.PushFront() " << std::endl;
  ListElem *pTmp = head;
  head = new ListElem;
  head->data = _data;
  head->next = pTmp;
  head->prev = NULL;
  if (tail == NULL) tail = head;
};

void List2s::PushBack(int _data){
  std::cout << "     list2s.PushBack() " << std::endl;
  ListElem *pTmp = tail;
  tail->next = new ListElem;
  tail = tail->next;
  tail->data = _data;
  tail->next = NULL;
  tail->prev = pTmp;
  if (head == NULL) head = tail;
};

void List2s::PopFront(){
  std::cout << "     list2s.PopFront() " << std::endl;
  ListElem *pTmp = head;
  if (Empty()) std::cerr << " List is empty!!! " << std::endl;
  else if (head == tail){ head = tail = NULL; }
  else{
    head = head->next;
    head->prev = NULL;
    delete pTmp;
  }
};

void List2s::PopBack(){
  std::cout << "     list2s.PopBack() " << std::endl;
  ListElem *pTmp = tail;
  if (Empty()) std::cerr << " List is empty!!! " << std::endl;
  else if (head == tail){ head = tail = NULL; }
  else{
    tail = tail->prev;
    tail->next = NULL;
    delete pTmp;
  }
};

void List2s::InitRandValues(){
  for (int i = 0; i < lstSize; i++){
    PushFront(ReturnRandValue());
  }
};

void List2s::ShowFront(){
  std::cout << " First stack element: " << head->data << std::endl;
};

void List2s::ShowBack(){
  std::cout << " Front queue element: " << tail->data << std::endl;
};

void List2s::ShowList(){ 
  std::cout << "     list2s.ShowList() " << std::endl;
  std::cout << std::endl;
  ListElem *pTmp;
  for (pTmp = head; pTmp != NULL; pTmp = pTmp->next){
    std::cout << " " << pTmp->data;
  }
  std::cout << std::endl;
};

void List2s::ShowSeparator(bool _value){
  if (_value == 1){
    std::cout << std::endl;
    std::cout << " ................... LIST2S .................... " << std::endl;
    std::cout << std::endl;
  }
  else if (_value == 0){
    std::cout << std::endl;
    std::cout << " List2S .................................... end " << std::endl;
    std::cout << std::endl;
  }else std::cerr << " Zly parametr!!! " << std::endl;
};
