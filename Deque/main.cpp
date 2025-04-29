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
#include <random>

using namespace std;

void RandomNums(Deque& deq);

void Print(Deque& deq);

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
       << "(P) to print the values in deque" << endl
       << "(R) to populate deque with random numbers: " << endl
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
  case 'p':
    Print(deq);
    break;
  case 'r':
    RandomNums(deq);
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
    cout << "New Front: " << deq.front() << endl;
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

void Print(Deque& deq){
  cout << "Printing" << endl;
  deq.print();
  cout << endl;
}

void RandomNums(Deque& deq){
  int num,min,max;
  cout << "How many numbers should we generate? ";
  cin >> num;
  cout << "What can the smallest number be? ";
  cin >> min;
  cout << "What can the largest number be? ";
  cin >> max;

  random_device rd;
  mt19937 gen(rd());

  uniform_int_distribution<> dis(min,max);
  uniform_int_distribution<> pr(0,1); // 0 means push_front 1 means push_back

  for(int i = 0; i < num; i++){
    if( pr(gen) == 0){
      deq.push_front(dis(gen));
    }
    else{
      deq.push_back(dis(gen));
    }
  }
}
