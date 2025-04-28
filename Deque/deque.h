/**
 * @file deque.h
 * @author alfonsowolski
 * @date 2025-04-25
 * @brief The definition of the deque object
 * 
 * The definition of the deque object
 */

#ifndef DEQUE_H
#define DEQUE_H

#include <utility>

class Deque{
 public:


/**
 * Constructor for the Deque class
 *
 * @param int Rows the number of rows the Deque should start with
 * @param int BlockSize the amount of elements each block can hold 
 * @post blockSize, rows are set to respective values, size = 0, blockmap is initialized
 * 
 */
  Deque(int Rows, int BlockSize);
  

/**
 * Deconstructor for the Deque class
 * 
 * @post blockmap is deleted along with it's child arrays
 * 
 */
  ~Deque();


/**
 * Adds/Removes blocks from the deque
 *
 * @param int amount number of blocks to remove from deque
 * @param bool fromFront should the blocks be removed from the front?
 * @pre amount is not larger than size. if removing, only remove empty blocks
 * @return void 
 * @post new blocks are added/removed at either front or back depending on fromFront
 * 
 */
  void change_blocks(int amount, bool fromFront);
  

/**
 * Adds an element to the front of the deque
 *
 * @param int num the number to add to the front of the deque
 * @pre blockmap is initialized
 * @return void 
 * @post num is added at the front of deque. size is incremented.
 * 
 */
  void push_front(int num);


/**
 * Adds an element to the back of the deque
 *
 * @param int num the number to add to the back of the deque
 * @pre blockmap is initialized
 * @return void 
 * @post num is added at the end of deque. size is incremented
 * 
 */
  void push_back(int num);


/**
 * Take out the element at front of deque
 *
 * @pre blockmap is initialized and deque is not empty
 * @return int the element from the front of the deque. if empty then defaults to 0
 * @post element at front is removed. start is moved to next first element. size is decremented
 * 
 */
  int pop_front();


/**
 * Take out the element at end of deque
 *
 * @pre blockmap is initialized and deque is not empty
 * @return int the element from the end of the deque. if empty then defaults to 0
 * @post element at end is removed. end is moved to the next last element. size is decremented
 * 
 */
  int pop_back();


/**
 * Returns the element at front of deque
 *
 * @pre blockmap is initialized and deque is not empty
 * @return int the element from the front of the deque
 * 
 */
  int front();


/**
 * Returns the element at end of deque
 *
 * @pre blockmap is initialized and deque is not empty
 * @return int the element from the end of deque 
 * 
 */
  int back();


/**
 * Returns true if deque is empty
 *
 * @pre deque is initialized
 * @return bool is deque empty?
 * 
 */
  bool empty();


/**
 * Returns the number of elements in the deque
 *
 * @pre deque is initialized
 * @return int the number of elements in the deque 
 * 
 */
  int size();

  int& operator[](int index);
  
 private:
  int** blockmap; // 2d array storing blocks of ints
  std::pair<int,int> start; // location of the first element
  std::pair<int,int> end; // location of the last element
  int blockSize; //  max elements per block
  int elements; // how many element there are
  int rows; // how many blocks there are
};

#endif
