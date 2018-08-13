//
//  vector.hpp
//  Data-Structures
//
//  Created by Railf on 8/13/18.
//  Copyright © 2018 Railf. All rights reserved.
//

#ifndef vector_hpp
#define vector_hpp
#include "vector.hpp"
#include <stddef.h>

template <typename T>
class Vector
{
  // Constructors / Destructor
            Vector  ();
  explicit  Vector  (size_t size);
            Vector  (const Vector<T>&);
  virtual   ~Vector ();
  
  // Member Operators
  Vector<T>&  operator=   (const Vector<T>&);
  Vector<T>&  operator+=  (const Vector<T>&);
  T&          operator[]  (size_t);
  const T&    operator[]  (size_t) const;
  
  // Vector Class
  bool      Empty     ()  const;
  bool      PushBack  (const T&);
  bool      PopBack   ();
  void      Clear     ();
  T&        Front     ();
  const T&  Front     ()  const;
  T&        Back      ();
  const T&  Back      ()  const;
  void      toString  ();
  
  // Other Methods
  bool    SetSize     (size_t);
  bool    SetSize     (size_t, const T&);
  bool    SetCapacity (size_t);
  size_t  Size        () const;
  size_t  Capacity    () const;
  
  // Iterator
  typedef T*  Iterator;
  typedef const T*  ConstIterator;
  
  ConstIterator Begin () const;
  ConstIterator End   () const;
  Iterator      Begin ();
  Iterator      End   ();
  
protected:
  size_t  size_;
  size_t  capacity_;
  T*      content_;
  
  static T* NewArray  (size_t);
};

#include "vector.cpp"
#endif /* vector_hpp */
