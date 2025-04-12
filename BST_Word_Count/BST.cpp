/**
 * @file BST.cpp
 * @author alfonsowolski
 * @date 2025-04-11
 * @brief implementation of the BST class
 * 
 * implementation of the BST class
 */

#include "BST.h"
#include "HelperFunctions.h"
#include <fstream>
#include <iostream>

BST::BST(){
  start = nullptr;
}

BST::~BST(){
  delete start;
}

int BST::find(std::string key){
  return start->findNode(key)->getData();
}

void BST::add(std::string key){
  
  if(start == nullptr){
    Node* n = new Node(key);
    (*n)++;
    start = n;
    return;
  }
  
  Node* n = start->findNode(key);
  //std::cout << "found Node '" << n->getKey() << "'" << std::endl;
  
  if(n != nullptr){
    
    //std::cout << "incremented " << n->getKey() << std::endl;
    (*n)++;
  }
  else{
    n = new Node(key);
    (*n)++;
    start->placeNode(n);
  }
}

void BST::set(std::string key, int count){
  if(start == nullptr){
    Node* n = new Node(key);
    n->setData(count);
    start = n;
    return;
  }

  Node* n = start->findNode(key);
  if ( n == nullptr ){ // Node was not found
    Node* n2 = new Node(key);
    n2->setData(count);
    start->placeNode(n2);
  }
  else{
    n->setData(count);
  }
}

void BST::print(){
  start->printAll();
}

void BST::min(){
  Node* leftmost = start;

  while(leftmost->getLeft() != nullptr){
    leftmost = leftmost->getLeft();
  }
  leftmost->print();
}

void BST::max(){
  Node* rightmost = start;

  while(rightmost->getRight() != nullptr){
    rightmost = rightmost->getRight();
  }
  rightmost->print();
}

void BST::save_file(std::string path){
  std::ofstream file;

  file.open(path);
  
  start->save(file);

  file.close();
  
}

void BST::load_file(std::string path){
  std::ifstream file;
  std::string key;
  int data;
  
  file.open(path);

  if(!file){
    std::cout << "Unable to open file '" << path << "'" << std::endl;
    return;
  }
  
  while(file){
    file >> key >> data;
    set(key,data);
  }
  
  file.close();
}

void BST::deleteNode(std::string key){
  Node* n = start->findNode(key);
  Node* replacementNode = nullptr;
  Node* parentNode = n->getParent();  
  bool isLeft = true; // of parent

  if(parentNode->getLeft() != n){
    isLeft = false;
  }
  
  
  // find the replacement node to keep tree intact - using rightmost left method
  if( n->getLeft() != nullptr ){ // if there is a Node at left
    replacementNode = n->getLeft();

    // set replacementNode to the rightmost Node
    while (replacementNode->getRight() != nullptr){
      replacementNode = replacementNode->getRight();
    }

    // set the old 'left' of the replacementNode to be the new 'right' of the parent
    replacementNode->getParent()->setRight( replacementNode->getLeft() );

    // set 'right' of replacementNode to be the old 'right' of n  - if it is nullptr, it has same result
    replacementNode->setRight( n->getRight() );

    
    // left is set differently to avoid setting it as its own parent
    if( n->getLeft() != replacementNode ){ // if the replacement is the 'left' of n, it needs to keep its current 'left' child
      replacementNode->setLeft( n->getLeft() );
    }
    
  }
  else if (n->getRight() != nullptr){ // there was no Node at left so we must bring up right node
    replacementNode = n->getRight();
    
  }

  if( parentNode != nullptr) { // is not at start
    replacementNode->setParent( parentNode );
    (isLeft)? parentNode->setLeft(replacementNode) : parentNode->setRight(replacementNode);
  }
  else{ // is at start
    replacementNode->setParent(nullptr);
    start = replacementNode;
  }
  
  // n should be disconnected and left and right are connected to the replacement node
  n->setLeft(nullptr);
  n->setRight(nullptr);
  n->setParent(nullptr);
  delete n;
  
}






