//
//  main.cpp
//  DataStructures
//
//  Created by Railf on 8/6/18.
//  Copyright © 2018 Railf. All rights reserved.
//

#include <iostream>

#include "stack.hpp"
#include "queue.hpp"
#include "linkedlist.hpp"
#include "doublelinkedlist.hpp"
#include "vector.hpp"

int main(int argc, const char * argv[]) {
  std::cout << "======================================\n";
  std::cout << "Stack\n";
  std::cout << "======================================\n";
  Stack<int> stack;
  
  std::cout << "Empty?: " << stack.Empty() << '\n';
  stack.Push(1);
  stack.Push(2);
  stack.Push(3);
  stack.Pop();
  stack.Pop();
  stack.Push(15);
  stack.toString();
  std::cout << "Top of stack: " << stack.Top() << '\n';
  std::cout << "Empty?: " << stack.Empty() << '\n' << '\n';
  
  
  std::cout << "======================================\n";
  std::cout << "Queue\n";
  std::cout << "======================================\n";
  Queue<int> q;
  
  std::cout << "Empty?: " << q.Empty() << '\n';
  q.Push(1);
  q.Push(2);
  q.Push(3);
  q.Pop();
  q.Pop();
  q.Push(15);
  q.toString();
  std::cout << "Front of queue: " << q.Front() << '\n';
  std::cout << "Back  of queue: " << q.Back() << '\n';
  std::cout << "Empty?: " << q.Empty() << '\n' << '\n';
  
  
  std::cout << "======================================\n";
  std::cout << "Linked List\n";
  std::cout << "======================================\n";
  LinkedList<int> list;
  
  std::cout << "Empty?: " << list.Empty() << '\n';
  list.Push(1);
  list.Push(2);
  list.Push(3);
  list.Pop(3);
  list.Push(4);
  list.Push(5);
  list.toString();
  std::cout << "Head of list: " << list.Head() << '\n';
  std::cout << "Empty?: " << list.Empty() << '\n' << '\n';
  
  
  std::cout << "======================================\n";
  std::cout << "Doubly-Linked List\n";
  std::cout << "======================================\n";
  DoubleLinkedList<int> dlist;
  
  std::cout << "Empty?: " << dlist.Empty() << '\n';
  dlist.Push(1);
  dlist.Push(2);
  dlist.Push(3);
  dlist.Push(4);
  dlist.Push(5);
  dlist.Push(6);
  dlist.Push(7);
  dlist.Push(8);
  dlist.Push(9);
  dlist.Pop(1);
  dlist.Pop(5);
  dlist.Pop(9);
  dlist.Pop();
  dlist.toString();
  std::cout << "Head of list: " << dlist.Head() << '\n';
  std::cout << "Tail of list: " << dlist.Tail() << '\n';
  std::cout << "Empty?: " << list.Empty() << '\n' << '\n';
  

  std::cout << "======================================\n";
  std::cout << "Vector\n";
  std::cout << "======================================\n";
  Vector<int> vector;
  
  std::cout << "Empty?: " << vector.Empty() << '\n';
  vector.PushBack(1);
  vector.PushBack(3);
  vector.PushBack(4);
  vector.toString();
  std::cout << "Front of vector:  " << vector.Front() << '\n';
  std::cout << "vector[1] output: " << vector[1] << '\n';
  std::cout << "Back of vector:   " << vector.Back() << '\n';
  std::cout << "Empty?: " << list.Empty() << '\n' << '\n';
}
