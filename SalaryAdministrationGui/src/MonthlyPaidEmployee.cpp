/*
 * MonthlyPaidEmployee.cpp
 *
 *  Created on: 9.8.2016
 *      Author: keskimol
 */

#include <string>
#include "MonthlyPaidEmployee.h"


MonthlyPaidEmployee::MonthlyPaidEmployee(string newFirstName, string newLastName,
                                         string newSsn, double newMonthlySalary)
{
    typ = employee_types::MONTHLY_PAID_EMPLOYEE;
    Employee::setFirstName(newFirstName);
    Employee::setLastName(newLastName);
	Employee::setSocialSecurityNumber(newSsn);
	setMonthlySalary(newMonthlySalary);
};


MonthlyPaidEmployee::~MonthlyPaidEmployee() {}


void MonthlyPaidEmployee::setMonthlySalary(double newMonthlySalary)
{
	monthlySalary = newMonthlySalary;
}


double MonthlyPaidEmployee::getMonthlySalary()
{
	return monthlySalary;
}


double MonthlyPaidEmployee::getSalary()
{
	return monthlySalary;
}

void MonthlyPaidEmployee::printInfo()
{
	cout << "Type: " << "MonthlyPaidEmployee" << "\n";
    cout << "First Name: " << Employee::getFirstName() << "\n";
    cout << "Last Name: " << Employee::getLastName() << "\n";
	cout << "SSN: " << Employee::getSocialSecurityNumber() << "\n";
	cout << "Salary: " << this->getSalary() << "\n";
	cout << ">Monthly salary: " << this->getMonthlySalary() << "\n";
}



