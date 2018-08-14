//
//  vector.cpp
//  Data-Structures
//
//  Created by Railf on 8/13/18.
//  Copyright © 2018 Railf. All rights reserved.
//

#ifndef vector_cpp
#define vector_cpp
#include "vector.hpp"
#include <iostream>

static const size_t defaultCapacity = 10;

template <typename T>
Vector<T>::Vector()
: size_(0), capacity_(defaultCapacity), content_(nullptr)
{
  content_ = CreateArray(capacity_);
}

template <typename T>
Vector<T>::~Vector<T>()
{
  delete [] content_;
  content_ = nullptr;
  size_ = capacity_ = 0;
}

template <typename T>
T& Vector<T>::operator[](size_t index)
{
  if (index > size_)
  {
    std::cerr << "** Index is out of range.\n";
    
    if (index > capacity_)
      exit(EXIT_FAILURE);
  }
  return content_[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const
{
  if (index > size_)
  {
    std::cerr << "** Index is out of range.\n";
    
    if (index > capacity_)
      exit(EXIT_FAILURE);
  }
  return content_[index];
}

template <typename T>
bool Vector<T>::Empty() const
{
  return (size_ == 0);
}

template <typename T>
bool Vector<T>::PushBack(const T& data)
{
  if((size_ + 1) <= capacity_)
  {
    content_[size_] = data;
    ++size_;
    return 1;
  }
  else
  {
    size_t tempCapacity = Capacity();
    
    if(tempCapacity == 0)
      tempCapacity = 1;
    else
      tempCapacity *= 2;
    
    if (SetCapacity(tempCapacity))
    {
      content_[size_] = data;
      ++size_;
      return 1;
    }
    else
    {
      return 0;
    }
  }
}

template <typename T>
bool Vector<T>::PopBack()
{
  if (size_ == 0)
    return 0;
  
  --size_;
  return 1;
}

template <typename T>
void Vector<T>::Clear()
{
  SetSize(0);
}

template <typename T>
T& Vector<T>::Front()
{
  return content_[0];
}

template <typename T>
const T& Vector<T>::Front() const
{
  return content_[0];
}

template <typename T>
T& Vector<T>::Back()
{
  return content_[size_ - 1];
}

template <typename T>
const T& Vector<T>::Back() const
{
  return content_[size_ - 1];
}

template <typename T>
void Vector<T>::toString()
{
  std::cout << "( " << content_[0];
  for (size_t i = 1; i < size_; ++i)
  {
    std::cout << " , " << content_[i];
  }
  std::cout << " )" << '\n';
}

template <typename T>
bool Vector<T>::SetSize(size_t size)
{
  if (size > capacity_)
    if (!SetCapacity(size))
      return 0;
  
  size_ = size;
  return 1;
}

template <typename T>
bool Vector<T>::SetCapacity(size_t capacity)
{
  if (capacity == 0)
  {
    delete [] content_;
    content_ = nullptr;
    size_ = capacity_ = 0;
    return 1;
  }
  else
  {
    if (capacity_ != capacity)
    {
      T* newArray = CreateArray(capacity);
      
      if (newArray == nullptr)
        return 0;
      
      if (size_ > capacity)
        size_ = capacity;
      
      for (size_t i = 0; i < size_; ++i)
      {
        newArray[i] = content_[i];
      }
      capacity_ = capacity;
      delete [] content_;
      content_ = newArray;
    }
  }
  return 1;
}

template <typename T>
size_t Vector<T>::Size() const
{
  return size_;
}

template <typename T>
size_t Vector<T>::Capacity() const
{
  return capacity_;
}

template <typename T>
T* Vector<T>::CreateArray(size_t newCapacity)
{
  T* array = (newCapacity > 0 ? new(std::nothrow) T[newCapacity] : nullptr);
  return array;
}

#endif //vector_cpp
