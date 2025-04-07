/**
 * @file main.cpp
 * @author alfonsowolski
 * @date 2025-04-06
 * @brief Testing file for Game Library
 * 
 * provides a menuverable menu to allow adding/removing/viewing games within a game library
 */


#include "Library.h"
#include "Game.h"

#include <iostream>

using namespace std;

int main() {

  string str;
  
  cout << "Program Started" << endl;

  cout << "Enter filename: ";

  cin >> str;

  Library L;

  L.Load_Library(str);

  L.find_Genre("fun");
  
  return 0;
}
