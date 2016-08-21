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

    friend std::ofstream& operator<<(std::ofstream& os, const MonthlyPaidEmployee& e) {
        os << e.firstName.size() << separator;
        os << e.firstName << separator;
        os << e.lastName.size() << separator;
        os << e.lastName << separator;
        os << e.socialSecurityNumber.size() << separator;
        os << e.socialSecurityNumber<< separator;
        os << e.monthlySalary << separator;
        return os;
    }

    friend std::ifstream& operator>>(std::ifstream& is, MonthlyPaidEmployee& e) {
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
        is >> e.monthlySalary;
        is >> sep;
        return is;
    }
};


#endif /* MONTHLYPAIDEMPLOYEE_H_ */
