//
//  tree.cpp
//  Data-Structures
//
//  Created by Railf on 8/18/18.
//  Copyright © 2018 Railf. All rights reserved.
//

#ifndef tree_cpp
#define tree_cpp

#include "tree.hpp"

template <typename T>
Tree<T>::Tree()
: root_(nullptr)
{}

template <typename T>
Tree<T>::~Tree()
{
  delete [] root_;
}

template <typename T>
bool
Tree<T>::Empty()
{
  return (root_ == nullptr);
}

template <typename T>
void
Tree<T>::Insert(treeNode newNode, treeNode curNode)
{
  if (newNode->data_ < curNode->data_)
  {
    if (curNode->left_ == nullptr)
    {
      curNode->left_ = newNode;
      newNode->parent_ = curNode;
    }
    else
    {
      curNode = curNode->left_;
      Insert(newNode, curNode);
    }
  }
  else if (newNode->data_ > curNode->data_)
  {
    if (curNode->right_ == nullptr)
    {
      curNode->right_ = newNode;
      newNode->parent_ = curNode;
    }
    else
    {
      curNode = curNode->right_;
      Insert(newNode, curNode);
    }
  }
  else
  {
    std::cerr << "** Tree<T>: " << newNode->data_ << " is already present in tree.\n";
  }
}

template <typename T>
void
Tree<T>::Push(T data)
{
  treeNode newNode = new Node(data);
  treeNode curNode = root_;
  
  if (Empty())
    root_ = newNode;
  else
    Insert(newNode, curNode);
}

template <typename T>
T
Tree<T>::Root()
{
  return root_->data_;
}

template <typename T>
void
Tree<T>::toString()
{
  treeNode node = root_;
  
  std::cout << node->data_ << '\n';
  while (node != nullptr && (node->left_ != nullptr || node->right_ != nullptr))
  {
    if (node->left_ != nullptr)
      std::cout << node->left_->data_ << '\n';
    if (node->right_ != nullptr)
      std::cout << node->right_->data_ << '\n';
    
    if (node->left_ != nullptr && node->right_ == nullptr)
    {
      node = node->left_;
      continue;
    }
    else if (node->left_ == nullptr && node->right_ != nullptr)
    {
      node = node->right_;
      continue;
    }
    else if (node->left_ != nullptr && node->right_ != nullptr)
    {
      node = node->left_;
      continue;
    }
    else
    {
      node->left_ = nullptr;
      node->right_ = nullptr;
      node = node->parent_;
      continue;
    }
  }
}

#endif
