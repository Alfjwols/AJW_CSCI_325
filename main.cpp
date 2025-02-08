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

int main() {
  
  Vector vec1, vec2, vec3;

  // testing initializing using reserve
  vec1.reserve(1);
  DisplayVector(vec1);

  // testing pushback
  vec1.push_back(1);
  DisplayVector(vec1);
  
  vec1.push_back(2);                                                                           
  DisplayVector(vec1);
  vec1.push_back(3);                                                                           
  DisplayVector(vec1);
  vec1.push_back(4);                                                                           
  DisplayVector(vec1);
  vec1.push_back(6);                                                                           
  DisplayVector(vec1);
  vec1.push_back(5);
  DisplayVector(vec1);

  // testing operator =
  vec2 = vec1;
  DisplayVector(vec2);
  
  return 0;
}

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
