//============================================================================
// Name        : Employee.h
// Author      : Aapo Keskimolo
// Description : Generic employee base class that will be used as base for all
//               employee types.
//============================================================================

#pragma once

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

static char const separator = ',';
static char const eof = '\n';

namespace employee_types
{
    enum type {
        UNKNOWN = 0,
        MONTHLY_PAID_EMPLOYEE = 1,
        HOURLY_PAID_EMPLOYEE = 2,
        SALESMAN_EMPLOYEE = 3
    };
}


struct ModelDataHeader {
    unsigned int nMonthly = 0, nHourly = 0, nSalesman = 0;
    ModelDataHeader() {}
    ModelDataHeader(unsigned int mon, unsigned int hou, unsigned int sal): nMonthly(mon), nHourly(hou), nSalesman(sal) {}

    friend std::ofstream& operator<<(std::ofstream& os, const ModelDataHeader& e) {
        os << e.nMonthly << separator;
        os << e.nHourly << separator;
        os << e.nSalesman << separator;
        return os;
    }
    friend std::ifstream& operator>>(std::ifstream& is, ModelDataHeader& e) {
        char sep;
        is >> e.nMonthly;
        is >> sep;
        is >> e.nHourly;
        is >> sep;
        is >> e.nSalesman;
        is >> sep;
        return is;
    }
};


inline const char* employeeTypetoString(employee_types::type typ) {
    switch (typ)
    {
    case employee_types::MONTHLY_PAID_EMPLOYEE:
        return "Monthly";
    case employee_types::HOURLY_PAID_EMPLOYEE:
        return "Hourly";
    case employee_types::SALESMAN_EMPLOYEE:
        return "Salesman";
    default:
        return "";
        }
}

class Employee
{
  protected:
    string lastName, socialSecurityNumber;
    employee_types::type typ;

  public:
    string firstName;
    virtual ~Employee() {}
    virtual double getSalary() = 0;
    virtual void printInfo() = 0;

    employee_types::type getType();
    void setFirstName(string newFirstName);
    string getFirstName();
    void setLastName(string newLastName);
    string getLastName();
  	void setSocialSecurityNumber(string newSsn);
  	string getSocialSecurityNumber();
};


#endif /* EMPLOYEE_H_ */
