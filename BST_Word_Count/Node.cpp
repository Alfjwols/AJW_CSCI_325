/**
 * @file Node.cpp
 * @author alfonsowolski
 * @date 2025-04-10
 * @brief Implementation of the Node class
 * 
 * Implementation of the Node class
 */

#include "NODE.H"
#include <iostream>

Node::Node(std::string Key){
  key = Key;
  data = 0;
  left = nullptr;
  right = nullptr;
}

Node::~Node(){
  delete left;
  delete right;
}

void Node::setData(int num){
  data = num;
}

int Node::getData(){
  return data;
}

void Node::add(int num){
  data += num;
}

Node& Node::operator++(){
  data++;
  return *this;
}

Node* Node::getLeft(){
  return left;
}

Node* Node::getRight(){
  return right;
}

void Node::setLeft(Node* n){
  left = n;
}

void Node::setRight(Node* n){
  right = n;
}

std::string Node::getKey(){
  return key;
}

void Node::placeNode(Node* n){
  if( HelperFunctions::ComesBefore(n->getKey(), key) ){ // it comes before
    if( left != nullptr ){ // there is a Node at left
      left->placeNode(n);
    }
    else{ // there is no Node at left
      left = n;
      n->setParent(this);
    }
  }
  else{ // it comes after
    if( right != nullptr ){ // there is a Node at right
      right->placeNode(n);
    }
    else{ // there is no Node at right
      right = n;
      n->setParent(this);
    }
  }
  // code shouldn't get to this point else something is wrong
}

Node* Node::findNode(std::string Key){

  if(Key == key) { // is this the key?
    return this;
  }
  
  if( HelperFunctions::ComesBefore(Key, key) ){ // 'Key' is search and 'key' is this Node's key
    // it comes before this Node
    if( left != nullptr ){ // there is a Node at left
      return left->findNode(Key);
    }
    else{ // there is no Node at left
      return nullptr; // it must not be in the list
    }
  }
  else{ // it comes after this Node
    if( right != nullptr ) { // there is a Node at right
      return right->findNode(Key);
    }
    else{ // there is no Node at right
      return nullptr; // it must not be in the list
    }
  }
}

void Node::print(){
  std::cout << "( " << key << ", " << data << " )";
}

void Node::printAll(){
  if( left != nullptr){
    left->printAll();
  }
  
  print();
  
  if( right != nullptr){
    right->printAll();
  }
}

void Node::save(std::fstream& file){
  if( left != nullptr ){
    left->save(file);
  }

  file << key << " " << data << std::endl;

  if( right != nullptr ){
    right->save(file);
  }
}

Node* Node::getParent(){
  return parent;
}

void Node::setParent(Node* n){
  parent = n;
}
