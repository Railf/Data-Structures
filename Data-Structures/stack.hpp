//
//  stack.hpp
//  DataStructures
//
//  Created by Railf on 8/6/18.
//  Copyright © 2018 Railf. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

template <typename T>
class Stack
{
  struct Node
  {
    Node* next_;
    T data_;
  };
  
  Node* top_;
  
public:
  Stack();
  ~Stack();
  
  void Push(T);
  T Pop();
  bool Empty();
  T Top();
  void toString();
};

#include "stack.cpp"
#endif /* stack_hpp */
