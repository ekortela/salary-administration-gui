#pragma once

/*
 * Employee.h
 *
 *  Created on: 9.8.2016
 *      Author: keskimol
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

namespace employee_types
{
    enum type {
        UNKNOWN = 0,
        MONTHLY_PAID_EMPLOYEE = 1,
        HOURLY_PAID_EMPLOYEE = 2,
        SALESMAN_EMPLOYEE = 3
    };
}

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
  private:
    string firstName, lastName, socialSecurityNumber;

  protected:
    employee_types::type typ;

  public:
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
