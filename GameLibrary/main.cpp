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


bool GameLibraryView(Library& L);

void SearchByTitle(Library& L);

void SearchByGenre(Library& L);

void AddGame(Library& L);

void RemoveGame(Library& L);

void SaveQuit(Library& L);

string getEntry();

int main() {

  string str;
  
  cout << "Program Started" << endl;

  cout << "Choose file: ";

  cin >> str;
  Library L;

  L.Load_Library("GameLibraries/Library1.txt"); // prechosen for testing purposes


  while(GameLibraryView(L));
  

  
  return 0;
}

bool GameLibraryView(Library& L){

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
  case '2':
    SearchByGenre(L);
    break;
  case '3':
    AddGame(L);
    break;
  case '4':
    RemoveGame(L);
    break;
  case 'q':
    SaveQuit(L);
    return false;
    break;
  }

  return true;
}

void SearchByTitle(Library& L){
  string str;
  cout << "Please enter title to search: ";

  str = getEntry();
  
  cout << "Searching for: " << str << endl;

  L.find_Game(str);
    
}

void SearchByGenre(Library& L){
  string str;
  cout << "Please enter genre to search: ";

  str = getEntry();
  
  cout << "Searching for: " << str << endl;

  L.find_Genre(str);
}

void AddGame(Library& L){
  string Title, Publisher, Genre;
  float HoursPlayed, Price;
  short Year;
  
  cout << "Please enter game title: ";

  Title = getEntry();

  cout << "Please enter publisher name: ";

  Publisher = getEntry();

  cout << "Please enter game genre: ";

  Genre = getEntry();

  cout << "Please enter hours played: ";

  cin >> HoursPlayed;

  cout << "Please enter game price: ";

  cin >> Price;

  cout << "Please enter year of release: ";

  cin >> Year;

  Game g = Game(Title, Publisher, Genre, HoursPlayed, Price, Year);

  L.insert_sorted(g);

  
}

void RemoveGame(Library& L){
  string Title, str;
  short year;
  
  cout << "Please enter title you wish to remove: ";

  Title = getEntry();

  cout << "Please enter release year of title: ";

  cin >> year;

  cout << endl << "Type 'yes' to confirm the removal of the following game: " << endl
       << Title << endl
       << year << endl;

  cin >> str;

  if( str == "yes" ){
    L.delete_Title(Title, year);
    cout << "Game has been removed" << endl;
  }

}

void SaveQuit(Library& L){
  string path;
  cout << "Please enter file to save to: ";

  cin >> path;
  
  L.Save_Library(path);
}

string getEntry(){ // grabs full line of input
  string str1, str2;

  cin >> str1;
  getline(cin, str2);

  str1 += str2;
  
  return str1;
}
