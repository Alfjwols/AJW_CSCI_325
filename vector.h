/**
 * @file vector.h
 * @author alfonsowolski
 * @date 2025-01-23
 * @brief Vector Object Definition
 * 
 * The definition of a new vector object
 */


#include <iostream>
#include <fstream>

using namespace std;

#ifndef VECTOR_H
#define VECTOR_H

class Vector{
 public:

/**
 * Default constructor. Initializes an empty vector
 *
 * @post vec_ptr is NULL, vec_size=0, and vec_capacity=0. 
 */
  Vector();
  

/**
 * copy constructor. Initializes a dynamic array of the appropriate
 * size/capacity and copies data from other's array to the new array.
 *
 * @param const Vector &other the vector to copy
 * @pre other vector is initialized
 * @post vec_ptr is initialized, and its array contains other.vec_ptr's data,
 *       vec_size=other.vec_size, and vec_capacity=other.vec_capacity.
 */
  Vector(const Vector &other);

  

/**
 * Deconstructor. Deallocates vec_ptr.
 *
 * @post vec_ptr has been deallocated, current_size=0, and capacity = 0.
 * 
 */
  ~Vector();
  
/**
 * Assignment operator. Initializes a dynamic array of the appropriate size/capacity and copies data from other's array to the new array
 *
 * @param const Vector &other, the vector to copy.
 * @pre other is initialized
 * @post vec_ptr is initialized, its array contains other.vec_ptr's data, vec_size=other.vec_size, and vec_capacity=other.vec_capacity
 * 
 */
  Vector& operator=(const Vector &other);




/**
 * Returns the number of elements in the vector
 *
 * @return int the number of elements in the vector. 
 * 
 */
  int size();

  



/**
 * Returns the currently allocated storage capacity of the vector.
 *
 * @return int amount of currently allocated storage capacity of vector 
 * 
 */
  int capacity();


/**
 * stores element at the end of the vector.
 *
 * @param int element the element to be placed at the end of the vector
 * @pre array must be initialized
 * @return void 
 * @post element has been placed in the last position in the array
 * 
 */
  void push_back(int element);


/**
 * Requests that the vector capacity be resized at least enough to contain n elements
 *
 * @param int n total capacity needed
 * @return void 
 * @post capacity has been changed to n 
 * 
 */
  void reserve(int n);


/**
 * Returns a reference to the element at position index
 *
 * @param unsigned int index position of desired element, index < vec_size
 * @pre vec_ptr is initialized, index is less than vec_size
 * @return int& 
 * 
 */
  int& operator[](unsigned int index);
    
  
 private:
  int *vec_ptr; // Points to the vector's dynamic array
  int vec_size, vec_capacity; // Same as size and capacity for std::vector
}

#endif
