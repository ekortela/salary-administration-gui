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

class Employee
{
  private:
    string firstName, lastName, socialSecurityNumber;

  public:
    virtual double getSalary() = 0;
    virtual void printInfo() = 0;
    virtual ~Employee();

    void setFirstName(string newFirstName);
    string getFirstName();
    void setLastName(string newLastName);
    string getLastName();
  	void setSocialSecurityNumber(string newSsn);
  	string getSocialSecurityNumber();
};


#endif /* EMPLOYEE_H_ */
