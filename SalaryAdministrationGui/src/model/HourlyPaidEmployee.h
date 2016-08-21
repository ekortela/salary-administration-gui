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

    friend std::ofstream& operator<<(std::ofstream& os, const HourlyPaidEmployee& e) {
        os << e.firstName.size() << separator;
        os << e.firstName << separator;
        os << e.lastName.size() << separator;
        os << e.lastName << separator;
        os << e.socialSecurityNumber.size() << separator;
        os << e.socialSecurityNumber<< separator;
        os << e.hourlySalary << separator;
        os << e.doneHours << separator;
        return os;
    }

    friend std::ifstream& operator>>(std::ifstream& is, HourlyPaidEmployee& e) {
        int len = 0;
        char sep;
        is >> len;
        is >> sep;
        if (len) {
            std::vector<char> tmp(len);
            is.read(tmp.data() , len);
            e.firstName.assign(tmp.data(), len);
        }
        is >> sep;
        is >> len;
        is >> sep;
        if (len) {
            std::vector<char> tmp(len);
            is.read(tmp.data() , len);
            e.lastName.assign(tmp.data(), len);
        }
        is >> sep;
        is >> len;
        is >> sep;
        if (len) {
            std::vector<char> tmp(len);
            is.read(tmp.data() , len);
            e.socialSecurityNumber.assign(tmp.data(), len);
        }
        is >> sep;
        is >> e.hourlySalary;
        is >> sep;
        is >> e.doneHours;
        is >> sep;
        return is;
    }
};


#endif /* HOURLYPAIDEMPLOYEE_H_ */
