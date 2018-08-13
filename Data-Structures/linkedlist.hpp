//
//  linkedlist.hpp
//  DataStructures
//
//  Created by Railf on 8/7/18.
//  Copyright © 2018 Railf. All rights reserved.
//

#ifndef linkedlist_hpp
#define linkedlist_hpp

template<typename T>
class LinkedList
{
  typedef struct Node
  {
    T data_;
    Node* next_;
    
    Node(): data_(0), next_(nullptr){}
    Node(T data): data_(data), next_(nullptr){}
  }* Nodeptr;
  
  Nodeptr head_;
  Nodeptr curr_;
  
public:
  LinkedList();
  ~LinkedList();
  
  void Push(T);
  T Pop(T);
  
  T Head();
  
  bool Empty();
  void toString();
};

#include "linkedlist.cpp"
#endif /* linkedlist_hpp */
