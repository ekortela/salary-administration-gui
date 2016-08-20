//============================================================================
// Name        : MonthlyPaidEmployee.h
// Author      : Aapo Keskimolo
// Description : Definition file for monthly paid employee class. Inherits from
//               Employee base-class.
//============================================================================

#pragma once

#ifndef MONTHLYPAIDEMPLOYEE_H_
#define MONTHLYPAIDEMPLOYEE_H_

#include "Employee.h"

class MonthlyPaidEmployee: public Employee
{
  private:
    double monthlySalary;

  public:
    MonthlyPaidEmployee(string newFirstName, string newLastName,
                        string newSsn, double newMonthlySalary);
    virtual ~MonthlyPaidEmployee();
    void setMonthlySalary(double newMonthlySalary);
    double getMonthlySalary();
    double getSalary();
	void printInfo();
};


#endif /* MONTHLYPAIDEMPLOYEE_H_ */
