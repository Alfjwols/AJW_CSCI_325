/**
 * @file vector.cpp
 * @author alfonsowolski
 * @date 2025-02-05
 * @brief Implementation of vector.h
 * 
 * This is the implementation of my custom vector object
 */

#include "vector.h"

int PUSHBACK_RESERVE_AMOUNT = 2; // used for when pushback needs to reserve more space

Vector::Vector(){
  vec_ptr = NULL;
  vec_size = 0;
  vec_capacity = 0;
}

Vector::Vector(const Vector &other){
  vec_size = other.vec_size;
  vec_capacity = other.vec_capacity;
  vec_ptr = new int[vec_capacity];

  for(int i = 0; i < vec_size; i++){
    vec_ptr[i] = other.vec_ptr[i];
  }
}

Vector::~Vector(){
  delete[] vec_ptr;
}

Vector& Vector::operator=(const Vector &other){

  vec_capacity = other.vec_capacity;
  vec_size = other.vec_size;

  delete[] vec_ptr;
  vec_ptr = new int[vec_capacity];
  
  for (int i = 0; i < other.vec_size; i++){
    vec_ptr[i] = other.vec_ptr[i];
  }

  return *this;
}

int Vector::size(){
  return vec_size;
}

int Vector::capacity(){
  return vec_capacity;
}

void Vector::reserve(int n){
  if(n <= vec_capacity) return;

  int* temp_ptr = new int[n];
  
  // copy each element in vec_ptr to temp_ptr
  for(int i = 0; i < vec_size; i++){   
    temp_ptr[i] = vec_ptr[i];
  }

  // deallocate old array
  delete[] vec_ptr;

  // set vec_ptr to point to temp_ptr
  vec_ptr = temp_ptr;

  // set new vec_capacity
  vec_capacity = n;
}

void Vector::push_back(int element){
  // if the vector is already full, call reserve to increase capacity
  if(vec_size == vec_capacity){
    reserve(vec_capacity + PUSHBACK_RESERVE_AMOUNT);
  }

  // add the element at the point 
  vec_ptr[vec_size] = element;

  vec_size++;
}

int& Vector::operator[](unsigned int index){
  return vec_ptr[index];
}
