/**
 * @file main.cpp
 * @author alfonsowolski
 * @date 2025-02-07
 * @brief Testing file
 * 
 * This file is for testing the implementation of the vector type
 */

#include "vector.h"
#include <iostream>

using namespace std;

void DisplayVector(Vector vec);

void AddElementsToVector(Vector& vec, int num);

int main() {
  
  Vector vec1, vec2, vec3;
  int num;

  cout << "How many elements should vec1 have? ";
  cin >> num;
  AddElementsToVector(vec1,num); // demenstrating pushback & []

  cout << "How many elements should vec 2 have? ";
  cin >> num;
  AddElementsToVector(vec2,num); // demonstrating pushback & []

  
  cout << "Printing stars equal to number of elements in each: ";
  for(int i = 0; i < vec1.size() + vec2.size(); i++){ // demonstrating using size() in a loop
    cout << "*";
  }

  cout << "Vec1: " << endl;
  DisplayVector(vec1);

  cout << endl;
  
  cout << "Vec2: " << endl;
  DisplayVector(vec2);

  cout << endl;
  
  cout << "assignment vector vec3 = vec1:" << endl;
  vec3 = vec1; // demonstrating using assignment
  DisplayVector(vec3); 

  cout << endl;

  cout << "copy vector vec3 = new Vector(vec2)" << endl;
   
  vec3 = Vector(vec2); // demonstratin using copy constructor
  DisplayVector(vec3);
  
  
  return 0;
}



/**
 * add a bunch of elements 1-n to the vector for testing
 *
 * @param Vector& vec the vector to add elements to
 * @param int num number of element to add
 * @pre vec.vec_ptr must be initialized
 * 
 */
void AddElementsToVector(Vector& vec, int num){
  vec.reserve(num);
  for(int i = 0; i < num; i++){
    vec.push_back(i);
    vec[i/2] += 1;
  }
}



/**
 * Displays breif description of vector and its elements
 *
 * @param Vector vec the vector to display
 * @pre vec.vec_ptr must be initialized 
 * 
 */
void DisplayVector(Vector vec){

  cout << "----" << endl;
  cout << "Capacity: " << vec.capacity() << endl;
  cout << "Size: " << vec.size() << endl;
  
  cout << "Elements:";
  for(int i = 0; i < vec.size(); i++){
    cout << vec[i] << " ";
  }
  cout << endl;
  cout << "----" << endl;
}
