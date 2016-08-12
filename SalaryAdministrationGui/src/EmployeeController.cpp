#include "EmployeeController.h"
#include <algorithm>
#include <stdexcept>
#include <stdio.h>

// TODO Add classes for exceptions

EmployeeController::EmployeeController(EmployeeView view)
{
	this->view = view;
}


void EmployeeController::addMonthlyPaidEmployee(string newName, string newSsn,
	double newMonthlySalary)
{
	if (getEmployeeIndex(newSsn) == -1)
		model.push_back(EmployeeFactory::getMonthlyPaidEmployee(
			newName, newSsn, newMonthlySalary));
	else
		cerr << "Unable to add: Employee already found with SSN: " << newSsn << "\n";
}

void EmployeeController::addHourlyPaidEmployee(string newName, string newSsn,
	double newHourlySalary, double newDoneHours) {

	if (getEmployeeIndex(newSsn) == -1)
		model.push_back(EmployeeFactory::getHourlyPaidEmployee(
			newName, newSsn, newHourlySalary, newDoneHours));
	else
		cerr << "Unable to add: Employee already found with SSN: " << newSsn << "\n";
}

void EmployeeController::addSalesmanEmployee(string newName, string newSsn,
	double newMonthlySalary, double newBonus, bool newOutcomeClaim) {

	if (getEmployeeIndex(newSsn) == -1)
		model.push_back(EmployeeFactory::getSalesmanEmployee(
			newName, newSsn, newMonthlySalary, newBonus, newOutcomeClaim));
	else
		cerr << "Unable to add: Employee already found with SSN: " << newSsn << "\n";
}

void EmployeeController::removeEmployee(string ssn) {

	int idx = getEmployeeIndex(ssn);
	if (idx != -1) {
		model.erase(model.begin() + idx);
//		vector<Employee*>(model).swap(model);
	}
	else
		throw out_of_range(ssn);
}


int EmployeeController::getEmployeeIndex(string ssn) {

	for (unsigned int i = 0; i < model.size(); i++) {
		if (model[i]->getSocialSecurityNumber() == ssn) {
			return i;
		}
	}
	return -1;
}

Employee * EmployeeController::getEmployee(string ssn)
{
	int idx = getEmployeeIndex(ssn);
	if (idx != -1)
		return model[idx];
	return nullptr;
}

int EmployeeController::getEmployeeCount()
{
	return model.size();
}

void EmployeeController::setEmployeeName(string ssn, string newName)
{
	Employee* p = getEmployee(ssn);
	if (p != nullptr)
		p->setName(newName);
	else
		throw invalid_argument(ssn);
}

string EmployeeController::getEmployeeName(string ssn)
{
	Employee* p = getEmployee(ssn);
	if (p != nullptr)
		return p->getName();
	else
		throw invalid_argument(ssn);;
}

void EmployeeController::removeEmployeesAll() {
	model.clear();
}


void EmployeeController::updateView() {
	view.printEmployeeInfoAll(model);
}
