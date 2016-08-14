#include "EmployeeController.h"

EmployeeController::EmployeeController(EmployeeView *view)
{
    this->m_view = view;
    this->m_view->registerObserver(this);
}


void EmployeeController::addMonthlyPaidEmployee(string newName, string newSsn,
	double newMonthlySalary)
{
    if (getEmployeeIndex(newSsn) == -1)
        model.push_back(EmployeeFactory::getMonthlyPaidEmployee(
			newName, newSsn, newMonthlySalary));
	else
        qCritical() << "Unable to add: Employee already exists! SSN: " << QString::fromStdString(newSsn);
}

void EmployeeController::addHourlyPaidEmployee(string newName, string newSsn,
	double newHourlySalary, double newDoneHours) {

    if (getEmployeeIndex(newSsn) == -1)
        model.push_back(EmployeeFactory::getHourlyPaidEmployee(
			newName, newSsn, newHourlySalary, newDoneHours));
	else
        qCritical() << "Unable to add: Employee already exists! SSN: " << QString::fromStdString(newSsn);
}

void EmployeeController::addSalesmanEmployee(string newName, string newSsn,
	double newMonthlySalary, double newBonus, bool newOutcomeClaim) {

    if (getEmployeeIndex(newSsn) == -1)
        model.push_back(EmployeeFactory::getSalesmanEmployee(
			newName, newSsn, newMonthlySalary, newBonus, newOutcomeClaim));
	else
        qCritical() << "Unable to add: Employee already exists! SSN: " << QString::fromStdString(newSsn);
}

void EmployeeController::removeEmployee(string ssn) {

    int idx = getEmployeeIndex(ssn);
	if (idx != -1)
        delete model[idx];
	else
        qCritical() << "Unable to remove: Employee does not exist! SSN: " << QString::fromStdString(ssn);
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
        p->setFirstName(newName);
    else
        qCritical() << "Unable to set employee name: Employee does not exist! SSN: " << QString::fromStdString(ssn);
}

string EmployeeController::getEmployeeName(string ssn)
{
    Employee* p = getEmployee(ssn);
    if (p != nullptr)
        return p->getFirstName();
    else
        qCritical() << "Unable to get employee name: Employee does not exist! SSN: " << QString::fromStdString(ssn);
    return("");
}

void EmployeeController::clearEmployees() {
    model.clear();
}

void EmployeeController::updateView() {
//    view.printEmployeeInfoAll(model);

}

void EmployeeController::handleEvent() {
    qInfo("handleEvent() has been called!");
}
