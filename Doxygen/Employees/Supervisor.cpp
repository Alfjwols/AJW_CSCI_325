/**
 * @file Supervisor.cpp
 * @author alfonsowolski
 * @date 2025-04-18
 * @brief implementation of the Supervisor class
 * 
 * implementation of the Supervisor constructor, Supervisor cunstructor w/ initializers, print, and calculatePay
 */



#include "Supervisor.h"
#include <iostream>

using namespace std;


Supervisor::Supervisor() {
  numSupervised = -1;
}

Supervisor::Supervisor(int ID, int years, double hourlyRate, float hoursWorked, int numSupervised) : Employee(ID, years, hourlyRate, hoursWorked) {
  this->numSupervised = numSupervised;
}

void Supervisor::print() {
  Employee::print();
  cout << " Number Supervised: " << numSupervised << endl;
}

double Supervisor::calculatePay() {
  double val = Employee::calculatePay();
  val = val + val * (.01 * numSupervised);
  return val;
}
