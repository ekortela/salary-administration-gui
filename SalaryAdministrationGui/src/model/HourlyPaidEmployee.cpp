//============================================================================
// Name        : HourlyPaidEmployee.cpp
// Author      : Aapo Keskimolo
// Description : Declarations for hourly paid employee class methods
//============================================================================

#include "HourlyPaidEmployee.h"


HourlyPaidEmployee::HourlyPaidEmployee(string newFirstName, string newLastName,
                                       string newSsn, double newHourlySalary, double newDoneHours)
{
    typ = employee_types::HOURLY_PAID_EMPLOYEE;
    Employee::setFirstName(newFirstName);
    Employee::setLastName(newLastName);
	setSocialSecurityNumber(newSsn);
	setHourlySalary(newHourlySalary);
	setDoneHours(newDoneHours);
}

HourlyPaidEmployee::~HourlyPaidEmployee() {}

void HourlyPaidEmployee::setHourlySalary(double newHourlySalary) {
	hourlySalary = newHourlySalary;
}


double HourlyPaidEmployee::getHourlySalary() {
	return hourlySalary;
}


void HourlyPaidEmployee::setDoneHours(double newDoneHours) {
	doneHours = newDoneHours;
}


double HourlyPaidEmployee::getDoneHours() {
	return doneHours;
}


double HourlyPaidEmployee::getSalary() {
  return hourlySalary*doneHours;
}


void HourlyPaidEmployee::printInfo() {
    cout << "Type: " << employeeTypetoString(typ) << "\n";
    cout << "First Name: " << Employee::getFirstName() << "\n";
    cout << "Last Name: " << Employee::getLastName() << "\n";
	cout << "SSN: " << Employee::getSocialSecurityNumber() << "\n";
	cout << "Salary: " << this->getSalary() << "\n";
	cout << ">Done hours: " << this->getDoneHours() << "\n";
	cout << ">Hourly salary: " << this->getHourlySalary() << "\n";
}
