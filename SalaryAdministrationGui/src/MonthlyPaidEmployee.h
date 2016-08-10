/*
 * MonthlyPaidEmployee.h
 *
 *  Created on: 9.8.2016
 *      Author: keskimol
 */

#ifndef MONTHLYPAIDEMPLOYEE_H_
#define MONTHLYPAIDEMPLOYEE_H_

#include "Employee.h"

class MonthlyPaidEmployee: public Employee
{
  private:
    double monthlySalary;
  public:
    MonthlyPaidEmployee(string newName,
    		string newSocialSecurityNumber,
    		double newMonthlySalary);
    virtual ~MonthlyPaidEmployee();
    void setMonthlySalary(double newMonthlySalary);
    double getMonthlySalary();
    double getSalary();
	void printInfo();
};


#endif /* MONTHLYPAIDEMPLOYEE_H_ */
