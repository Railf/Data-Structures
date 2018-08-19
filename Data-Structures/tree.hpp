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
  struct Node
  {
    T data_;
    Node* left_;
    Node* right_;
    
    Node(): data_(0), left_(nullptr), right_(nullptr){}
    Node(T data): data_(data), left_(nullptr), right_(nullptr){}
  };
  
  Node* root_;
  
public:
  Tree(): root_(nullptr)
  {}
  
  ~Tree()
  {
    delete [] root_;
  }
  
  bool Empty()
  {
    return (root_ == nullptr);
  }
  
  void Push(T data)
  {
    Node* newNode = new Node(data);
    Node* curNode = root_;
    
    if (Empty())
    {
      root_ = newNode;
    }
    else if (newNode->data_ < curNode->data_)
    {
      curNode->left_ = newNode;
    }
    else if (newNode->data_ > curNode->data_)
    {
      curNode->right_ = newNode;
    }
    else
    {
      std::cerr << "** Tree<T>: " << data << " is already present in tree.\n";
    }
  }
  
  T    Root()
  {
    return root_->data_;
  }
  
  void toString()
  {
    std::cout << root_->data_ << '\n';
    std::cout << root_->left_->data_ << " " << root_->right_->data_ << '\n';
  }
};

#include "tree.cpp"
#endif /* tree_hpp */
