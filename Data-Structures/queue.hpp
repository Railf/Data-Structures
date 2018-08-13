//
//  queue.hpp
//  DataStructures
//
//  Created by Railf on 8/6/18.
//  Copyright © 2018 Railf. All rights reserved.
//

#ifndef queue_hpp
#define queue_hpp

template<typename T>
class Queue
{
  struct Node
  {
    T data_;
    Node* prev_;
    
    Node(T data)
    : data_(data), prev_(nullptr)
    {}
  };
  
  Node* back_;
  Node* front_;
  
public:
  Queue();
  ~Queue();
  
  void Push(T);
  T Pop();
  T Front();
  T Back();
  bool Empty();
  void toString();
};

#include "queue.cpp"
#endif /* queue_hpp */
