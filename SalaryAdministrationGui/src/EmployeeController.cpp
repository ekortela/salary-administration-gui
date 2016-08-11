#include "EmployeeController.h"
#include <algorithm>

// TODO Add classes for exceptions

EmployeeController::EmployeeController(EmployeeView* pView)
{
	this->pView = pView;
}


void EmployeeController::addMonthlyPaidEmployee(string newName, string newSsn,
	double newMonthlySalary)
{
	if (getEmployeeIndex(newSsn) == -1)
		model.push_back(EmployeeFactory::getMonthlyPaidEmployee(
			newName, newSsn, newMonthlySalary));
	else
		cout << "Unable to add: Employee already found with SSN: " << newSsn << "\n";
}

void EmployeeController::addHourlyPaidEmployee(string newName, string newSsn,
	double newHourlySalary, double newDoneHours) {

	if (getEmployeeIndex(newSsn) == -1)
		model.push_back(EmployeeFactory::getHourlyPaidEmployee(
			newName, newSsn, newHourlySalary, newDoneHours));
	else
		cout << "Unable to add: Employee already found with SSN: " << newSsn << "\n";
}

void EmployeeController::addSalesmanEmployee(string newName, string newSsn,
	double newMonthlySalary, double newBonus, bool newOutcomeClaim) {

	if (getEmployeeIndex(newSsn) == -1)
		model.push_back(EmployeeFactory::getSalesmanEmployee(
			newName, newSsn, newMonthlySalary, newBonus, newOutcomeClaim));
	else
		cout << "Unable to add: Employee already found with SSN: " << newSsn << "\n";
}

void EmployeeController::removeEmployeeBySsn(string ssn) {

	int idx = getEmployeeIndex(ssn);
	if (idx != -1)
		model.erase(model.begin() + idx);
	else
		cout << "Employee with SSN " << ssn << " was not found!\n";
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
	else
		return nullptr;
}

int EmployeeController::getEmployeeCount()
{
	return model.size();
}

void EmployeeController::setEmployeeName(string ssn, string newName)
{
	Employee* p = getEmployee(ssn);
	p->setName(newName);
}

string EmployeeController::getEmployeeName(string ssn)
{
	Employee* p = getEmployee(ssn);
	return p->getName();
}


void EmployeeController::updateView() {
	pView->printEmployeeInfoAll(model);
}
