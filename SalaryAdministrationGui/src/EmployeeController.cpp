#include "EmployeeController.h"

// TODO Add classes for exceptions

EmployeeController::EmployeeController(QWidget *view)
{
	this->view = view;
    this->empView = new EmployeeView(view);
}


void EmployeeController::addMonthlyPaidEmployee(string newName, string newSsn,
	double newMonthlySalary)
{
	if (getEmployeeIndexBySsn(newSsn) == -1)
		model.push_back(EmployeeFactory::getMonthlyPaidEmployee(
			newName, newSsn, newMonthlySalary));
	else
		cout << "Unable to add: Employee already found with SSN: " << newSsn << "\n";
}

void EmployeeController::addHourlyPaidEmployee(string newName, string newSsn,
	double newHourlySalary, double newDoneHours) {

	if (getEmployeeIndexBySsn(newSsn) == -1)
		model.push_back(EmployeeFactory::getHourlyPaidEmployee(
			newName, newSsn, newHourlySalary, newDoneHours));
	else
		cout << "Unable to add: Employee already found with SSN: " << newSsn << "\n";
}

void EmployeeController::addSalesmanEmployee(string newName, string newSsn,
	double newMonthlySalary, double newBonus, bool newOutcomeClaim) {

	if (getEmployeeIndexBySsn(newSsn) == -1)
		model.push_back(EmployeeFactory::getSalesmanEmployee(
			newName, newSsn, newMonthlySalary, newBonus, newOutcomeClaim));
	else
		cout << "Unable to add: Employee already found with SSN: " << newSsn << "\n";
}

void EmployeeController::removeEmployeeBySsn(string ssn) {

	int idx = getEmployeeIndexBySsn(ssn);
	if (idx != -1)
		delete model[idx];
	else
		cout << "Unable to remove: Employee not found with SSN: " << ssn << "\n";
}


int EmployeeController::getEmployeeIndexBySsn(string ssn) {

	for (unsigned int i = 0; i < model.size(); i++) {
		if (model[i]->getSocialSecurityNumber() == ssn) {
			return i;
		}
	}
	return -1;
}


void EmployeeController::updateView() {
    //view.printEmployeeInfoAll(model);

}
