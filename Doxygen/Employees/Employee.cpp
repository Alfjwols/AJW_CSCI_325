/**
 * @file Employee.cpp
 * @author alfonsowolski
 * @date 2025-04-18
 * @brief The implementation of the Employee class
 * 
 * The implementation of the Emplyee constuctor, Employee constuctor w/ initializers, print, aniversary, and calculatePay
 */



#include "Employee.h"
#include <iostream>

using namespace std;

Employee::Employee() {
  ID = years = hoursWorked = hourlyRate = -1;
}

Employee::Employee(int ID, int years, double hourlyRate, float hoursWorked) {
  this->ID = ID;
  this->years = years;
  this->hourlyRate = hourlyRate;
  this->hoursWorked = hoursWorked;
}

void Employee::print() {
  cout << "Printing information for employee " << ID << ":\n Years Employed: " << years
       << "\n Hourly Rate: " << hourlyRate << "\n Hours Worked: " << hoursWorked
       << endl;
}

void Employee::anniversary() {
  years++;
  hourlyRate = hourlyRate + hourlyRate * .002;
  cout << "Congratulations to employee " << ID << " on " << years << " year(s) at company!"
       << endl;
}

double Employee::calculatePay() {
  return hourlyRate * hoursWorked;
}

