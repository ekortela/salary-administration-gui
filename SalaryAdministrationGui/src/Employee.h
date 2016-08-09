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

using namespace std;


class Employee
{
  private:
	string name;
    string socialSecurityNumber;
  public:
    void setName(string newName);
    string getName();
  	void setSocialSecurityNumber(string newSocialSecurityNumber);
  	string getSocialSecurityNumber();
    virtual double getSalary() = 0;
    virtual ~Employee();
};


#endif /* EMPLOYEE_H_ */
