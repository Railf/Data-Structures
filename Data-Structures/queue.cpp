//
//  queue.cpp
//  DataStructures
//
//  Created by Railf on 8/6/18.
//  Copyright © 2018 Railf. All rights reserved.
//

#ifndef queue_cpp
#define queue_cpp

#include "queue.hpp"
#include <iostream>

template<typename T>
Queue<T>::Queue()
: back_(nullptr), front_(nullptr)
{}

template<typename T>
Queue<T>::~Queue()
{
  while(!Empty())
  {
    Pop();
  }
}

template<typename T>
void Queue<T>::Push(T data)
{
  Node* temp = new Node(data);
  if(Empty())
  {
    front_ = back_ = temp;
  } else
  {
    back_->prev_ = temp;
    back_ = temp;
  }
}

template<typename T>
T Queue<T>::Pop()
{
  if (front_ != nullptr)
  {
    Node* temp = front_;
    T popped = temp->data_;
    front_ = temp->prev_;
    return popped;
  }
  return 0;
}

template<typename T>
T Queue<T>::Front()
{
  return front_->data_;
}

template<typename T>
T Queue<T>::Back()
{
  return back_->data_;
}

template<typename T>
bool Queue<T>::Empty()
{
  return (front_ == nullptr);
}

template<typename T>
void Queue<T>::toString()
{
  Node* temp = front_;
  while(temp != nullptr)
  {
    std::cout << temp->data_ << ' ';
    temp = temp->prev_;
  }
  std::cout << '\n';
}

#endif
