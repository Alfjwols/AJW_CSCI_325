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


bool GameLibraryView(Library L);

void SearchByTitle(Library L);

void SearchByGenre(Library L);

void AddGame(Library L);

void RemoveGame(Library L);

void SaveQuit(Library L);

int main() {

  string str;
  
  cout << "Program Started" << endl;

  cout << "Choose file: ";

  cin >> str;
  Library L;

  L.Load_Library("GameLibraries/Library1.txt"); // prechosen for testing purposes

  GameLibraryView(L);
  

  
  return 0;
}

bool GameLibraryView(Library L){

  cout << "Please choose an option" << endl;

  cout << "(1) Search by Title" << endl
       << "(2) Searchy by Genre" << endl
       << "(3) Add new Game" << endl
       << "(4) Remove Game" << endl
       << "(q) Save and Quit" << endl;

  char c;

  cin >> c;

  switch(c){
  case '1':
    SearchByTitle(L);
    break;

  }

  return false;
}

void SearchByTitle(Library L){
  string str1, str2;
  cout << "Please enter title to search: ";

  cin >> str1;

  getline(cin, str2);

  str1 += str2;

  cout << "Searching for: " << str1 << endl;

  L.find_Game(str1);
    
}

void SearchByGenre(Library L){
  
}

void AddGame(Library L){

}

void RemoveGame(Library L){

}

void SaveQuit(Library L){

}
