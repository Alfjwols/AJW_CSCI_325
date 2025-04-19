/**
 * @file Employee.h
 * @author alfonsowolski
 * @date 2025-04-17
 * @brief The definition of the Employee class
 * 
 * contains ID, years, hourlyRate, and hoursWorked. has functionality for printing, aniversary handling
 */



#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
 private:
  int ID; //employee ID
  int years; // years worked at company
  
 protected:
  double hourlyRate; // how much the Employee makes per hour
  float hoursWorked; // how many hours the Employee has worked
 public:
  

/**
 * Displays info about imployee including ID, years at company, hourly rate, and hours worked 
 * 
 * @return virtual void
 * 
 */
  virtual void print();


/**
 * Calculates the due payment to the Employee based on hours worked and hourly rate
 *
 * @pre 
 * @return virtual double the amount due to the Employee
 * 
 */
  virtual double calculatePay();


/**
 * Displays a congratulations to Employee and gives a 2% raise
 *
 * @return void 
 * 
 */
  void anniversary();


/**
 * Base constructor for the Employee object
 * 
 * @post ID, years, hourlyRate, and hoursWorked are initialized to -1
 * 
 */
  Employee();


/**
 * Constructor for the Employee object with initializers
 *
 * @param int ID The Employee ID
 * @param int years Years the Employee has worked 
 * @param double hourlyRate The hourly wage/charge of the Employee
 * @param float hoursWorked the hours the Employee has worked
 * @pre ID, years, hourlyRate, hoursWorked are initialized values
 * @post ID, years, hourlyRate, hoursWorked are set to the specified values
 * 
 */
  Employee(int ID, int years, double hourlyRate, float hoursWorked);
};

#endif //EMPLOYEE_H
