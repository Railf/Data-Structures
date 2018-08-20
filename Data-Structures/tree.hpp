//
//  tree.hpp
//  Data-Structures
//
//  Created by Railf on 8/18/18.
//  Copyright © 2018 Railf. All rights reserved.
//

#ifndef tree_hpp
#define tree_hpp

#include <iostream>

template <typename T>
class Tree
{
  typedef struct Node
  {
    T data_;
    Node* left_;
    Node* right_;
    
    Node(): data_(0), left_(nullptr), right_(nullptr){}
    Node(T data): data_(data), left_(nullptr), right_(nullptr){}
  } *treeNode;
  
  treeNode root_;
  
public:
  Tree();
  ~Tree();
  
  bool Empty();
  
  void Insert(treeNode newNode, treeNode curNode);
  void Push(T data);
  
  T Root();
  void toString();
};

#include "tree.cpp"
#endif /* tree_hpp */
