#include "EmployeeController.h"
#include "HourlyPaidEmployee.h"
#include "MonthlyPaidEmployee.h"
#include "SalesmanEmployee.h"

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
        Employee* p = EmployeeFactory::getEmployee(typ, newFirstName, newLastName, newSsn,
                                                     newMonthlySalary, newHourlySalary,
                                                     newDoneHours, newBonus, newOutcomeClaim);
        if(p != nullptr) {
            model.push_back(p);
            qDebug() << "New employee was added to model with SSN: " << QString::fromStdString(newSsn);
            return true;
        }
        else
            qDebug() << "Employee type was not recognized: " << typ;
    }
    else {
        qCritical() << "Unable to add: Employee already exists! SSN: " << QString::fromStdString(newSsn);
    }
    return false;
}



bool EmployeeController::removeEmployee(string ssn) {

    int idx = getEmployeeIndex(ssn);
    if (idx != -1) {
        model.erase(model.begin() + idx);
        return true;
    }
	else
        qCritical() << "Unable to remove: Employee does not exist! SSN: " << QString::fromStdString(ssn);
    return false;
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

bool EmployeeController::setEmployeeFirstName(string ssn, string newFirstName)
{
    Employee* p = getEmployee(ssn);
    if (p != nullptr) {
        p->setFirstName(newFirstName);
        return true;
    }
    else
        qCritical() << "Unable to set employee first name: Employee does not exist! SSN: " << QString::fromStdString(ssn);
    return false;
}

string EmployeeController::getEmployeeFirstName(string ssn)
{
    Employee* p = getEmployee(ssn);
    if (p != nullptr)
        return p->getFirstName();
    else
        qCritical() << "Unable to get employee first name: Employee does not exist! SSN: " << QString::fromStdString(ssn);
    return("");
}

bool EmployeeController::setEmployeeLastName(string ssn, string newLastName)
{
    Employee* p = getEmployee(ssn);
    if (p != nullptr) {
        p->setLastName(newLastName);
        return true;
    }
    else
        qCritical() << "Unable to set employee last name: Employee does not exist! SSN: " << QString::fromStdString(ssn);
    return false;
}

string EmployeeController::getEmployeeLastName(string ssn)
{
    Employee* p = getEmployee(ssn);
    if (p != nullptr)
        return p->getLastName();
    else
        qCritical() << "Unable to get employee last name: Employee does not exist! SSN: " << QString::fromStdString(ssn);
    return("");
}

bool EmployeeController::setEmployeeSsn(string ssn, string newSsn)
{
    Employee* p = getEmployee(ssn);
    if (p != nullptr) {
        p->setSocialSecurityNumber(newSsn);
        return true;
    }
    else
        qCritical() << "Unable to set employee social security number: Employee does not exist! SSN: " << QString::fromStdString(ssn);
    return false;
}

string EmployeeController::getEmployeeSsn(string ssn)
{
    Employee* p = getEmployee(ssn);
    if (p != nullptr)
        return p->getSocialSecurityNumber();
    else
        qCritical() << "Unable to get employee social security number: Employee does not exist! SSN: " << QString::fromStdString(ssn);
    return("");
}

bool EmployeeController::setEmployeeHourlySalary(string ssn, double newHourlySalary)
{
    Employee* p = getEmployee(ssn);
    if (p != nullptr)
        if (p->getType() == employee_types::HOURLY_PAID_EMPLOYEE) {
            HourlyPaidEmployee *m = dynamic_cast<HourlyPaidEmployee *>(p);
            m->setHourlySalary(newHourlySalary);
            return true;
        }
        else
            qCritical() << "Unable to set hourly salary: Invalid employee type: " << QString::fromStdString(employeeTypetoString(p->getType() ));
    else
        qCritical() << "Unable to set hourly salary: Employee does not exist! SSN: " << QString::fromStdString(ssn);
    return false;
}

double EmployeeController::getEmployeeHourlySalary(string ssn)
{
    Employee* p = getEmployee(ssn);
    if (p != nullptr)
        if (p->getType() == employee_types::HOURLY_PAID_EMPLOYEE) {
            HourlyPaidEmployee *m = dynamic_cast<HourlyPaidEmployee *>(p);
            return m->getHourlySalary();
        }
        else
            qCritical() << "Unable to get hourly salary: Invalid employee type: " << QString::fromStdString(employeeTypetoString(p->getType() ));
    else
        qCritical() << "Unable to get hourly salary: Employee does not exist! SSN: " << QString::fromStdString(ssn);
    return 0.0;
}

bool EmployeeController::setEmployeeMonthlySalary(string ssn, double newMonthlySalary)
{
    Employee* p = getEmployee(ssn);

    if (p != nullptr) {
        if (p->getType() == employee_types::MONTHLY_PAID_EMPLOYEE) {
            MonthlyPaidEmployee *m = dynamic_cast<MonthlyPaidEmployee* >(p);
            m->setMonthlySalary(newMonthlySalary);
            return true;
        }
        else if (p->getType() == employee_types::SALESMAN_EMPLOYEE){
            SalesmanEmployee *m = dynamic_cast<SalesmanEmployee* >(p);
            m->setMonthlySalary(newMonthlySalary);
            return true;
        }
        else {
            qCritical() << "Unable to set monthly salary: Invalid employee type: " << QString::fromStdString(employeeTypetoString(p->getType() ));
        }
    }
    else
        qCritical() << "Unable to set monthly salary: Employee does not exist! SSN: " << QString::fromStdString(ssn);
    return false;
}

double EmployeeController::getEmployeeMonthlySalary(string ssn)
{
    Employee* p = getEmployee(ssn);

    if (p != nullptr) {
        if (p->getType() == employee_types::MONTHLY_PAID_EMPLOYEE) {
            MonthlyPaidEmployee *m = dynamic_cast<MonthlyPaidEmployee* >(p);
            return m->getMonthlySalary();
        }
        else if (p->getType() == employee_types::SALESMAN_EMPLOYEE){
            SalesmanEmployee *m = dynamic_cast<SalesmanEmployee* >(p);
            return m->getMonthlySalary();
        }
        else {
            qCritical() << "Unable to set monthly salary: Invalid employee type: " << QString::fromStdString(employeeTypetoString(p->getType() ));
        }
    }
    else
        qCritical() << "Unable to set monthly salary: Employee does not exist! SSN: " << QString::fromStdString(ssn);
    return 0.0;
}

bool EmployeeController::setEmployeeBonus(string ssn, double newBonus)
{
    Employee* p = getEmployee(ssn);
    if (p != nullptr)
        if (p->getType() == employee_types::SALESMAN_EMPLOYEE) {
            SalesmanEmployee *m = dynamic_cast<SalesmanEmployee *>(p);
            m->setBonus(newBonus);
            return true;
        }
        else
            qCritical() << "Unable to set bonus: Invalid employee type: " << QString::fromStdString(employeeTypetoString(p->getType() ));
    else
        qCritical() << "Unable to set bonus: Employee does not exist! SSN: " << QString::fromStdString(ssn);
    return false;
}

double EmployeeController::getEmployeeBonus(string ssn)
{
    Employee* p = getEmployee(ssn);
    if (p != nullptr)
        if (p->getType() == employee_types::SALESMAN_EMPLOYEE) {
            SalesmanEmployee *m = dynamic_cast<SalesmanEmployee *>(p);
            return m->getBonus();
        }
        else
            qCritical() << "Unable to get monthly salary: Invalid employee type: " << QString::number(static_cast<int>(p->getType()) );
    else
        qCritical() << "Unable to get monthly salary: Employee does not exist! SSN: " << QString::fromStdString(ssn);
    return 0.0;
}

bool EmployeeController::setEmployeeOutcomeclaim(string ssn, bool newOutcomeClaim)
{
    Employee* p = getEmployee(ssn);

    if (p != nullptr)
        if (p->getType() == employee_types::SALESMAN_EMPLOYEE) {
            SalesmanEmployee *m = dynamic_cast<SalesmanEmployee *>(p);
            m->setOutcomeClaim(newOutcomeClaim);
            return true;
        }
        else
            qCritical() << "Unable to set outcome claim: Invalid employee type: " << QString::number(static_cast<int>(p->getType()) );
    else
        qCritical() << "Unable to set outcome claim: Employee does not exist! SSN: " << QString::fromStdString(ssn);
    return false;
}

bool EmployeeController::getEmployeeOutcomeClaim(string ssn) {

    Employee* p = getEmployee(ssn);

    if (p != nullptr)
        if (p->getType() == employee_types::SALESMAN_EMPLOYEE) {
            SalesmanEmployee *m = dynamic_cast<SalesmanEmployee *>(p);
            return m->getOutcomeClaim();
        }
        else
            qCritical() << "Unable to get outcome claim: Invalid employee type: " << QString::number(static_cast<int>(p->getType()) );
    else
        qCritical() << "Unable to get outcome claim: Employee does not exist! SSN: " << QString::fromStdString(ssn);
    return false;
}

bool EmployeeController::setEmployeeDoneHours(string ssn, double newDoneHours) {

    Employee* p = getEmployee(ssn);

    if (p != nullptr)
        if (p->getType() == employee_types::HOURLY_PAID_EMPLOYEE) {
            HourlyPaidEmployee *m = dynamic_cast<HourlyPaidEmployee *>(p);
            m->setDoneHours(newDoneHours);
            return true;
        }
        else
            qCritical() << "Unable to set done hours: Invalid employee type: " << QString::number(static_cast<int>(p->getType()) );
    else
        qCritical() << "Unable to set done hours: Employee does not exist! SSN: " << QString::fromStdString(ssn);
    return false;
}

double EmployeeController::getEmployeeDoneHours(string ssn) {

    Employee* p = getEmployee(ssn);

    if (p != nullptr)
        if (p->getType() == employee_types::HOURLY_PAID_EMPLOYEE) {
            HourlyPaidEmployee *m = dynamic_cast<HourlyPaidEmployee *>(p);
            return m->getDoneHours();
        }
        else
            qCritical() << "Unable to get done hours: Invalid employee type: " << QString::number(static_cast<int>(p->getType()) );
    else
        qCritical() << "Unable to get done hours: Employee does not exist! SSN: " << QString::fromStdString(ssn);
    return 0.0;
}


void EmployeeController::clearEmployees() {
    model.clear();
}

void EmployeeController::printEmployeeModel() {
    for (unsigned int i = 0; model.size() > i; i++) {
        model[i]->printInfo();
        cout << "\n";
    }
}

void EmployeeController::updateView() {
    m_view->updateEmployeeList(model);
    qDebug() << "Controller updated View";
}

void EmployeeController::handleEventAddEmployee(employee_types::type typ,
                                     string newFirstName, string newLastName, string newSsn,
                                     double newMonthlySalary = 0.0,
                                     double newHourlySalary = 0.0, double newDoneHours = 0.0,
                                     double newBonus = 0.0, bool newOutcomeClaim = false) {
    if(addEmployee(typ, newFirstName, newLastName, newSsn,
                newMonthlySalary, newHourlySalary, newDoneHours, newBonus, newOutcomeClaim) ) {
        updateView();
    }
    else  {
        m_view->popBox("SSN already exists!");
    }
}

void EmployeeController::handleEventRemoveEmployee(string ssn) {
    if(removeEmployee(ssn) ) {
        updateView();
    }
    else  {
        m_view->popBox("Unable to remove employee!");
    }
}

void EmployeeController::handleEventPrintEmployees() {
    printEmployeeModel();
}

void EmployeeController::handleEventRequestViewUpdate() {
    updateView();
}

Employee* EmployeeController::handleEventGetEmployee(string ssn) {
    return getEmployee(ssn);
}
