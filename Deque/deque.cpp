/**
 * @file deque.cpp
 * @author alfonsowolski
 * @date 2025-04-28
 * @brief the implementation of the deque class
 * 
 * the implementation of the deque class
 */

#include "deque.h"
#include <utility>

Deque::Deque(int BlockSize){
  blockSize = BlockSize;
  rows = 5; // set to default of 5

  blockmap = new int*[rows];
  
  for(int i = 0; i < rows; i++){
    blockmap[i] = new int[blockSize];
  }

  end = start = {rows / 2, blockSize / 2}; // set to middle element of the middle block

  elements = 0; // no elements yet
}

Deque::~Deque(){

  for(int i = 0; i < rows; i++){
    delete [] blockmap[i];
  }

  delete [] blockmap;
}


void Deque::change_blocks(int amount, bool toFront){

  int** arr2 = new int*[rows + amount];

  int num = (toFront)? amount : 0; // if toFront then we need to leave the first position empty
  for(int i = 0; i < rows; i++){
    arr2[i + num] = blockmap[i]; // if toFront, then we assign blockmap[0] to arr2[i + num] and so on
  }

  if(toFront){
    start.first += amount;
    end.first += amount;
  }
  
  delete [] blockmap;
  blockmap = arr2;
  
}


void Deque::push_front(int num){

  if( start.second == 0){ // block is full?
    if( start.first == 0 && elements != 0){ // in first block and not first element
      change_blocks(1, true); // adds new block (new block is at blockmap[0])
    }
    else{ // there is a empty block before current
      start.first--; // move to the empty block
    }
    
    start.second = blockSize - 1; // sets start to the last element of the block

    end.first++; // end gets pushed forward by a block due to adding a new block

  }
  else if(elements != 0){ // not at end of block
    start.second--; // move to earlier (empty) element in block
  }
  // must be first element if both above did not fire thus nothing extra needs changed

  blockmap[start.first][start.second] = num; // set the new start location with the value num
  elements++;
}

void Deque::push_back(int num){


  
  if(end.second == blockSize -1 && elements != 0){ // is at end of block and not first element

    if(end.first == rows){ // is at last block
      change_blocks(1, false);
    }
    else{ // there is an empty block after current
      end.first++;
    }

    end.second = 0; // set to start of block
  }
  else if (elements != 0){ // not at end of block and not first element
    end.second++;
  }
  // was first element if both above did not fire thus nothing extra needs changed

  blockmap[end.first][end.second] = num;
  elements++;
}

int Deque::pop_front(){

  if( elements == 0){
    return 0;
  }
  
  int num = blockmap[start.first][start.second];

  // move the start pointer to next element
  
  if (elements > 1){ // if not last element in deque
    if(start.second == blockSize -1){ // is at last element of block
      start.first++;
      start.second = 0;
    }
    else{ // not at last element of block
      start.second++;
    }
  }

  if(start.first > 3){ // if there are more than 3 empty blocks before current
    change_blocks(-2,true); // remove to of the empty blocks
  }
  
  elements--;
  return num;
}

int Deque::pop_back(){

  if( elements == 0 ) {
    return 0;
  }
  
  int num = blockmap[end.first][end.second];

  // move the end pointer to next element
  
  if (elements > 1){ // if not last element in deque
    if(end.second == 0){ // is at first element of block
      end.first--;
      end.second = blockSize - 1;
    }
    else{ // not at first element of block
      end.second--;
    }
  }


  if(end.first < rows - 3){ // if there are more than 3 empty blocks after current
    change_blocks(-2,false); // remove to of the empty blocks
  }
  
  elements--;
  return num;
}

int Deque::front(){
  return blockmap[start.first][start.second];
}

int Deque::back(){
  return blockmap[end.first][end.second];
}

bool Deque::empty(){
  if(elements == 0){
    return true;
  }

  return false;
}

int Deque::size(){
  return elements;
}

int& Deque::operator[](int index){
  
  int block = start.first + (index + start.second) / blockSize;
  int element = (index + start.second)%blockSize;

  return blockmap[block][element];
}
