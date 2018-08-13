//
//  stack.cpp
//  DataStructures
//
//  Created by Railf on 8/6/18.
//  Copyright © 2018 Railf. All rights reserved.
//
#ifndef stack_cpp
#define stack_cpp

#include "stack.hpp"
#include <iostream>

template<typename T>
Stack<T>::Stack()
: top_(nullptr)
{}

template<typename T>
Stack<T>::~Stack()
{
  while(!Empty())
  {
    Pop();
  }
}

template<typename T>
void Stack<T>::Push(T data)
{
  Node* temp = new Node();
  temp->data_ = data;
  temp->next_ = top_;
  top_ = temp;
}

template<typename T>
T Stack<T>::Pop()
{
  T popped = top_->data_;
  top_ = top_->next_;
  
  return popped;
}

template<typename T>
bool Stack<T>::Empty()
{
  return (top_ == nullptr);
}

template<typename T>
T Stack<T>::Top()
{
  return top_->data_;
}

template<typename T>
void Stack<T>::toString()
{
  Node* temp = top_;
  while(temp != nullptr)
  {
    std::cout << temp->data_ << '\n';
    temp = temp->next_;
  }
}

#endif
