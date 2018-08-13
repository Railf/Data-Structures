//
//  doublelinkedlist.cpp
//  DataStructures
//
//  Created by Ralph McCracken, III on 8/8/18.
//  Copyright © 2018 Railf. All rights reserved.
//

#ifndef doublelinkedlist_cpp
#define doublelinkedlist_cpp

#include "doublelinkedlist.hpp"
#include <iostream>

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList()
: head_(nullptr), tail_(nullptr)
{}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList<T>()
{
  while(!Empty())
  {
    Pop();
  }
}

template<typename T>
void DoubleLinkedList<T>::Push(T data)
{
  Nodeptr temp = new Node(data);
  
  if (Empty())
  {
    head_ = tail_ = temp;
  }
  else
  {
    tail_->next_ = temp;
    temp->prev_ = tail_;
    tail_ = temp;
  }
}

template<typename T>
T DoubleLinkedList<T>::Pop(T data)
{
  Nodeptr temp = nullptr;
  temp = head_;
  
  while(temp != nullptr)
  {
    Nodeptr temp2 = nullptr;
    
    if (temp->data_ == data)
    {
      if (temp != tail_ && temp != head_)
      {
        temp2 = temp;
        temp = temp->next_;
        temp2 = temp2->prev_;
        temp2->next_ = temp;
        temp->prev_ = temp2;
        break;
      }
      else if (temp == tail_)
      {
        tail_ = tail_->prev_;
        tail_->next_ = nullptr;
        break;
      }
      else if (temp == head_)
      {
        head_ = head_->next_;
        head_->prev_ = nullptr;
        break;
      }
    } else
    {
      temp = temp->next_;
    }
  }
  
  return data;
}

template<typename T>
T DoubleLinkedList<T>::Pop()
{
  if (!Empty())
  {
    T temp = tail_->data_;
  
    if (tail_->prev_ != nullptr)
    {
      tail_ = tail_->prev_;
      tail_->next_ = nullptr;
    }
    else
    {
      head_ = tail_ = nullptr;
    }
  
    return temp;
  }
  return -1;
}

template<typename T>
T DoubleLinkedList<T>::Head()
{
  return head_->data_;
}

template<typename T>
T DoubleLinkedList<T>::Tail()
{
  return tail_->data_;
}

template<typename T>
bool DoubleLinkedList<T>::Empty()
{
  return (head_ == nullptr && tail_ == nullptr);
}

template<typename T>
void DoubleLinkedList<T>::toString()
{
  Nodeptr temp = nullptr;
  temp = head_;
  
  while(temp != nullptr)
  {
    std::cout << "<-" << temp->data_ << "->";
    temp = temp->next_;
  }
  std::cout << '\n';
}

#endif
