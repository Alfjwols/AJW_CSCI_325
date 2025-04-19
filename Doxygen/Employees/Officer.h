/**
 * @file Officer.h
 * @author alfonsowolski
 * @date 2025-04-18
 * @brief Definition of the Officer class
 * 
 * Inherits from the Employee class with additional functionality in the print() class and a modified calculatePay() that takes evilness into account
 */



#ifndef OFFICER_H
#define OFFICER_H

#include "Employee.h"

class Officer : public Employee {
 private:
  double evilness; 
 public:


/**
 * runs Employee::print() to print out Employee info and appends the 'evilness' amount
 *
 * @return void  
 * 
 */
  void print();


/**
 * Calculates pay as (hourlyRate + evilness) * hoursWorked
 *
 * @return double the pay owed to the Officer 
 * 
 */
  double calculatePay();


/**
 * default constructor for the Officer class
 * 
 * @post evilness is initialized to 500
 * 
 */
  Officer();


/**
 * constructor for the Officer class with initializers
 *
 * @param int ID the ID of the officer
 * @param int years the years the Officer has been at the company
 * @param double hourlyRate the hourly salary of the Officer
 * @param float hoursWorked the amount of hours the Officer has accumilated
 * @param double evilness the evilness of the Officer
 * @pre 
 * @post the ID, years, hourlyRate, hoursWroked, and evilness are initilaized to the specified values
 * 
 */
  Officer(int ID, int years, double hourlyRate, float hoursWorked, double evilness);
};

#endif //OFFICER_H
