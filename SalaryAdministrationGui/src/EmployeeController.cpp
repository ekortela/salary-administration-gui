#include "EmployeeController.h"

EmployeeController::EmployeeController(EmployeeView *view)
{
    this->m_view = view;
    this->m_view->registerObserver(this);
}


bool EmployeeController::addEmployee(employee_types::type typ,
                                     string newFirstName, string newLastName, string newSsn,
                                     double newMonthlySalary = 0.0, double newHourlySalary = 0.0,
                                     double newDoneHours = 0.0, double newBonus = 0.0,
                                     bool newOutcomeClaim = false)
{

    if (getEmployeeIndex(newSsn) == -1) {
        model.push_back(EmployeeFactory::getEmployee(typ, newFirstName, newLastName, newSsn,
                                                     newMonthlySalary, newHourlySalary,
                                                     newDoneHours, newBonus, newOutcomeClaim) );
        qDebug() << "New employee was created with SSN: " << QString::fromStdString(newSsn);
        return true;
    }
    else {
        qCritical() << "Unable to add: Employee already exists! SSN: " << QString::fromStdString(newSsn);
    }
    return false;
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

size_t EmployeeController::getEmployeeCount()
{
    return model.size();
}

void EmployeeController::setEmployeeFirstName(string ssn, string newFirstName)
{
    Employee* p = getEmployee(ssn);
    if (p != nullptr)
        p->setFirstName(newFirstName);
    else
        qCritical() << "Unable to set employee name: Employee does not exist! SSN: " << QString::fromStdString(ssn);
}

string EmployeeController::getEmployeeFirstName(string ssn)
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

void EmployeeController::printEmployeeInfoAll() {
    for (unsigned int i = 0; model.size() > i; i++) {
        model[i]->printInfo();
        cout << "\n";
    }
}


void EmployeeController::updateView() {
    printEmployeeInfoAll();
    m_view->updateEmployeeList(model);
}

void EmployeeController::handleEventAddEmployee(employee_types::type typ,
                                     string newFirstName, string newLastName, string newSsn,
                                     double newMonthlySalary = 0.0, double newHourlySalary = 0.0,
                                     double newDoneHours = 0.0, double newBonus = 0.0, bool newOutcomeClaim = false) {
    if(addEmployee(typ, newFirstName, newLastName, newSsn,
                newMonthlySalary, newHourlySalary, newDoneHours, newBonus, newOutcomeClaim) ) {
        updateView();
    }
    else  {
        m_view->popBox("SSN already exists!");
    }

}

void EmployeeController::handleEventPrintEmployeeInfo() {
    printEmployeeInfoAll();
}
