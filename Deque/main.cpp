/**
 * @file main.cpp
 * @author alfonsowolski
 * @date 2025-04-28
 * @brief Driver for testing the Deque object
 * 
 * Driver for testing the Deque object
 */

#include "deque.h"
#include <cctype>
#include <iostream>

using namespace std;

void DisplayInfo(Deque& deq);

void GrabNumber(Deque& deq);

void AddNumber(Deque& deq);

bool AskUser(Deque& deq);

int main() {

  
  cout << "Testing Deque" << endl;

  cout << "Please enter a size for the Deque's blocks: ";

  int blocks;

  cin >> blocks;

  Deque deq = Deque(blocks);
  
  while(AskUser(deq));

  
  return 0;
}

bool AskUser(Deque& deq){
  cout << endl << "Enter option to continue: " << endl
       << "(A) to add a number to the deque" << endl
       << "(G) to grab a number from the deque" << endl
       << "(I) to display info about the deque" << endl
       << "(Q) to quit" << endl;

  char c;
  cin >> c;
  c = tolower(c);

  switch(c){
  case 'a':
    AddNumber(deq);
    break;
  case 'g':
    GrabNumber(deq);
    break;
  case 'i':
    DisplayInfo(deq);
    break;
  case 'q':
    return 0;
  }

  return 1;
}

void AddNumber(Deque& deq){
  cout << "Please enter a number: ";
  int n;
  cin >> n;

  cout << "Should we add '" << n << "' to the (F)ront or (B)ack? ";
  char c;
  cin >> c;

  c = tolower(c);

  if( c == 'f'){
    deq.push_front(n);
  }
  else if( c == 'b'){
    deq.push_back(n);
  }
  else{
    cout << "invalid input: " << c << endl;
    cout << "valid inputs: 'f' for front, 'b' for back" << endl;
  }
    
}

void GrabNumber(Deque& deq){
  cout << "Should we grab the number from the (F)ront or (B)ack? ";
  char c;
  cin >> c;

  c = tolower(c);

  if( c == 'f'){
    cout << "From Front: " << deq.pop_front() << endl;
    cout << "New Back: " << deq.front() << endl;
  }
  else if( c == 'b'){
    cout << "From Back: " << deq.pop_back() << endl;
    cout << "New Back: " << deq.back() << endl;
  }
  else{
    cout << "invalid input: " << c << endl;
    cout << "valid inputs: 'f' for front, 'b' for back" << endl;
  }
    
}

void DisplayInfo(Deque& deq){

  cout << "Deque Info" << endl
       << "| Elements: " << deq.size() << endl
       << "| Front: " << deq.front() << endl
       << "| Back: " << deq.back() << endl; 
    
}
