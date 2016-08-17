/*
 * HourlyPaidEmployee.h
 *
 *  Created on: 9.8.2016
 *      Author: keskimol
 */

#ifndef HOURLYPAIDEMPLOYEE_H_
#define HOURLYPAIDEMPLOYEE_H_

#include "Employee.h"


class HourlyPaidEmployee: public Employee
{
  private:
    double hourlySalary;
    double doneHours;

  public:
    HourlyPaidEmployee(string newFirstName, string newLastName,
                       string newSsn, double newHourlySalary, double newDoneHours);
    virtual ~HourlyPaidEmployee();
    void setHourlySalary(double newHourlySalary);
    double getHourlySalary();
    void setDoneHours(double newDoneHours);
    double getDoneHours();
	double getSalary();
	void printInfo();
};


#endif /* HOURLYPAIDEMPLOYEE_H_ */
