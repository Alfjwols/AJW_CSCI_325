/**
 * @file driver.cpp
 * @author alfonsowolski
 * @date 2025-04-11
 * @brief User interaction file
 * 
 * User interaction file - manages and steers user interaction in the program
 */


#include "BST.h"
#include "HelperFunctions.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

std::string ALLOWED_CHARACHTERS = "abcdefghijklmnopqrstuvwxyz'&";

bool Menu(BST& wordList);

void DisplayWordCounts(BST& wordList);

void AddWord(BST& wordList);

void RemoveWord(BST& wordList);

void ReadFile(BST& wordList);

void LoadFile(BST& wordList);

void SaveFile(BST& wordList);

void getWordCounts(BST& wordList,string path);

int main() {
  string path;
  
  BST wordList = BST();
  
  cout << "Welcome to Word Counter!" << endl << endl;

  while(Menu(wordList));
  
  return 0;
}

bool Menu(BST& wordList){
  cout << "Please choose an option: " << endl
       << "(1) Display Word Counts " << endl
       << "(2) Add Word " << endl
       << "(3) Remove Word" << endl
       << endl
       << "(r) Read File" << endl
       << "(l) Load File" << endl
       << "(s) Save File" << endl
       << "(q) Quit" << endl;
  
  char c;

  cin >> c;

  cout << endl; // just a bit of spaceing
  
  switch(c){
  case '1':
    DisplayWordCounts(wordList);
    break;
  case '2':
    AddWord(wordList);
    break;
  case '3':
    RemoveWord(wordList);
    break;
  case 'r':
    ReadFile(wordList);
    break;
  case 'l':
    LoadFile(wordList);
    break;
  case 's':
    SaveFile(wordList);
    break;
  case 'q':
    return false;
    break;
  }

  cout << endl; // a small buffer
  
  return true;
}

void DisplayWordCounts(BST& wordList){
  cout << "-Word Counts-" << endl;

  wordList.print();

  cout << endl;
}

void AddWord(BST& wordList){
  cout << "-Add Word-" << endl;

  cout << "Enter word to add to list: ";
  string str;
  cin >> str;

  str = HelperFunctions::toLower(str);
  str = HelperFunctions::filterChars(str, ALLOWED_CHARACHTERS);
  
  wordList.add(str);

  cout << "Added '" << str << "' to list" << endl
       << "Count is now at: " << wordList.find(str) << endl;
  
}

void RemoveWord(BST& wordList){
  cout << "-Remove Word-" << endl;

  cout << "Enter word to remove entirely from list: ";
  string str;
  cin >> str;

  cout << "Are you sure you want to remove '" << str << "' from the list? (y/n)";

  char c;
  cin >> c;

  if(c == 'y'){
    wordList.deleteNode(str);
    cout << "Removed " << str << "from list" << endl;
  }
}

void ReadFile(BST& wordList){
  cout << "-Read From File-" << endl;

  cout << "Please enter file to read from: ";
  string str;
  cin >> str;

  getWordCounts(wordList, str);
  
}

void LoadFile(BST& wordList){
  cout << "-Load From File-" << endl;

  cout << "Please enter file to load from: ";
  string str;
  cin >> str;

  wordList.load_file(str);

  cout << "Loaded from file '" << str << "'" << endl;
}

void SaveFile(BST& wordList){
  cout << "-Save to File-" << endl;

  cout << "Please enter file to save to: ";
  string str;
  cin >> str;

  wordList.save_file(str);

  cout << "Saved to file '" << str << "'" << endl;
}

void getWordCounts(BST& wordlist, string path){
  ifstream file;
  file.open(path);

  string str;

  if(!file){
    cout << "Unable to open file '" << path << "'" << endl;
    return;
  }
  
  while(file){
    file >> str;

    //cout << "found word '" << str << "'" << endl;
    
    str = HelperFunctions::toLower(str);
    str = HelperFunctions::filterChars(str, ALLOWED_CHARACHTERS);

    
    if(!str.empty()){
      wordlist.add(str);
    }
  }
  file.close();

  cout << "Read from file '" << path << "'" << endl;
}
