//============================================================================
// Name        : HourlyPaidEmployee.h
// Author      : Aapo Keskimolo
// Description : Definition file for hourly paid employee class. Inherits from
//               Employee base-class.
//============================================================================

#pragma once

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

    friend std::ofstream& operator<<(std::ofstream& os, const HourlyPaidEmployee& e);
    friend std::ifstream& operator>>(std::ifstream& is, HourlyPaidEmployee& e);
};


#endif /* HOURLYPAIDEMPLOYEE_H_ */
