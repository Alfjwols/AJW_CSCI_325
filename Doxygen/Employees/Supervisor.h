/**
 * @file Supervisor.h
 * @author alfonsowolski
 * @date 2025-04-18
 * @brief Definiton of the Supervisor class
 * 
 * Definition of the Supervisor class that inherits from Employee with a modified print and calculatePay class
 */



#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "Employee.h"

class Supervisor : public Employee {
 private:
  int numSupervised;
 public:


/**
 * runs Employee::print() which prints employee info, and appends the 'numSupervised' amount
 *
 * @return void  
 * 
 */
  void print();


/**
 * uses result from Employee::calulatePay and modifies it further as follows: val * val (.01 * numSupervised)
 *
 * @return double the amount owed to the supervisor
 * 
 */
  double calculatePay();


/**
 * The default constructor for the Supervisor class
 *
 * @pre 
 * @post numSupervised is initialized to -1
 * 
 */
  Supervisor();


/**
 * constructor for the Supervisor class with initializers
 *
 * @param int ID the ID of the Supervisor
 * @param int years the number of years the Supervisor has worked with the company
 * @param double hourlyRate the hourly pay of the Supervisor
 * @param float hoursWorked the hours worked by the supervisor
 * @param int numSupervised the number of people supervised by the Supervisor 
 * @post ID, years, hourlyRate, hoursWorked, and numSupervised are initialized to the specified values
 * 
 */
  Supervisor(int ID, int years, double hourlyRate, float hoursWorked, int numSupervised);
};

#endif //SUPERVISOR_H
