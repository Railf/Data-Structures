//
//  doublelinkedlist.hpp
//  DataStructures
//
//  Created by Ralph McCracken, III on 8/8/18.
//  Copyright © 2018 Railf. All rights reserved.
//

#ifndef doublelinkedlist_hpp
#define doublelinkedlist_hpp

template <typename T>
class DoubleLinkedList
{
  typedef struct Node
  {
    T data_;
    Node* prev_;
    Node* next_;
    
    Node(): data_(0), prev_(nullptr), next_(nullptr){}
    Node(T data): data_(data), prev_(nullptr), next_(nullptr){}
  }* Nodeptr;
  
  Nodeptr head_;
  Nodeptr tail_;
  
public:
  DoubleLinkedList();
  ~DoubleLinkedList();
  
  void Push(T data);
  T Pop(T data);
  T Pop();
  
  T Head();
  T Tail();
  
  bool Empty();
  void toString();
};

#include "doublelinkedlist.cpp"
#endif /* doublelinkedlist_hpp */
