//
//  linkedlist.cpp
//  DataStructures
//
//  Created by Railf on 8/7/18.
//  Copyright © 2018 Railf. All rights reserved.
//

#ifndef linkedlist_cpp
#define linkedlist_cpp

#include "linkedlist.hpp"
#include <iostream>

template<typename T>
LinkedList<T>::LinkedList()
: head_(nullptr), curr_(nullptr)
{}

template<typename T>
LinkedList<T>::~LinkedList<T>()
{}

template<typename T>
void LinkedList<T>::Push(T data)
{
  Nodeptr temp = new Node(data);
  
  if(Empty())
    head_ = curr_ = temp;
  else
  {
    curr_ = head_;
    while (curr_->next_ != nullptr)
    {
      curr_ = curr_->next_;
    }
    curr_->next_ = temp;
  }
}

template<typename T>
T LinkedList<T>::Pop(T data)
{
  Nodeptr temp = nullptr;
  
  curr_ = temp = head_;
  
  while(curr_ != nullptr)
  {
    if(curr_->data_ == data)
    {
      curr_ = curr_->next_;
      temp->next_ = curr_;
    } else
    {
      if (curr_ == head_ && temp == head_)
      {
        curr_ = curr_->next_;
      } else
      {
        curr_ = curr_->next_;
        temp = temp->next_;
      }
    }
  }
  
  return data;
}

template<typename T>
T LinkedList<T>::Head()
{
  return head_->data_;
}

template<typename T>
bool LinkedList<T>::Empty()
{
  return (head_ == nullptr);
}

template<typename T>
void LinkedList<T>::toString()
{
  Nodeptr temp = head_;
  
  while(temp != nullptr)
  {
    std::cout << temp->data_ << "->";
    temp = temp->next_;
  }
  std::cout << '\n';
}

#endif
