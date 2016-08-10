/*
 * EmployeeModel.cpp
 *
 *  Created on: 10.8.2016
 *      Author: Aapo Keskimölö
 */


#include "EmployeeModel.h"


// TODO Add classes for exceptions

void EmployeeModel::addMonthlyPaidEmployee(string newName, string newSsn,
		double newMonthlySalary)
{
	if (getEmployeeIndexBySsn(newSsn) == -1)
		employeeList.push_back(EmployeeFactory::getMonthlyPaidEmployee(
			newName, newSsn, newMonthlySalary));
	else
		cout << "Unable to add: Employee already found with SSN: " << newSsn << "\n";
}

void EmployeeModel::addHourlyPaidEmployee(string newName, string newSsn,
		double newHourlySalary, double newDoneHours) {

	if (getEmployeeIndexBySsn(newSsn) == -1)
		employeeList.push_back(EmployeeFactory::getHourlyPaidEmployee(
			newName, newSsn, newHourlySalary, newDoneHours));
	else
		cout << "Unable to add: Employee already found with SSN: " << newSsn << "\n";
}

void EmployeeModel::addSalesmanEmployee(string newName, string newSsn,
		double newMonthlySalary, double newBonus, bool newOutcomeClaim) {

	if (getEmployeeIndexBySsn(newSsn) == -1)
		employeeList.push_back(EmployeeFactory::getSalesmanEmployee(
				newName, newSsn, newMonthlySalary, newBonus, newOutcomeClaim));
	else
		cout << "Unable to add: Employee already found with SSN: " << newSsn << "\n";
}

void EmployeeModel::removeEmployeeBySsn(string ssn) {

	int idx = getEmployeeIndexBySsn(ssn);
	if (idx != -1)
		delete employeeList[idx];
	else
		cout << "Unable to remove: Employee not found with SSN: " << ssn << "\n";
}


int EmployeeModel::getEmployeeIndexBySsn(string ssn) {

	for (unsigned int i = 0; i < employeeList.size(); i++) {
		if (employeeList[i]->getSocialSecurityNumber() == ssn) {
			return i;
		}
	}
	return -1;
}


void EmployeeModel::printEmployeeInfoAll() {
	for (unsigned int i = 0; employeeList.size() > i; i++) {
		employeeList[i]->printInfo();
		cout << "\n";
	}
}

