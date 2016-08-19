#include "EmployeeController.h"
#include "HourlyPaidEmployee.h"
#include "MonthlyPaidEmployee.h"
#include "SalesmanEmployee.h"

using namespace ec;

EmployeeController::EmployeeController(EmployeeView *view)
{
    this->m_view = view;
    this->m_view->registerObserver(this);

//    // Add dummy employees
//    addEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "Eero", "Tuominen", "1", 3200.0, 0.0, 0.0, 0.0, false);
//    addEmployee(employee_types::HOURLY_PAID_EMPLOYEE, "Vaka-Vanha", "Vainamoinen", "2", 0.0, 20.0, 220.0, 0.0, false);
//    addEmployee(employee_types::SALESMAN_EMPLOYEE, "Liisa", "Ilmarinen", "3", 1500.0, 0.0, 0.0, 30.0, true);
//    updateView();
}


bool EmployeeController::addEmployee(employee_types::type typ,
                                     string newFirstName, string newLastName, string newSsn,
                                     double newMonthlySalary, double newHourlySalary,
                                     double newDoneHours, double newBonus,
                                     bool newOutcomeClaim)
{

    if (getEmployeeIndex(newSsn) == -1) {

        Employee* p = EmployeeFactory::getEmployee(typ, newFirstName, newLastName, newSsn,
                    newMonthlySalary, newHourlySalary, newDoneHours, newBonus, newOutcomeClaim);

        if(p != nullptr) {
            model.push_back(p);
            qDebug() << "New employee was added to model with SSN: " << QString::fromStdString(newSsn);
            return true;
        }
        else
            throw EmployeeTypeInvalidException("Employee factory returned null!");
    }
    else {
        throw EmployeeAlreadyExistsException("SSN: " + newSsn);
    }
}

bool EmployeeController::updateEmployee(string ssn,
                                     string newFirstName, string newLastName,
                                     double newMonthlySalary, double newHourlySalary,
                                     double newDoneHours, double newBonus,
                                     bool newOutcomeClaim)
{

    unsigned int idx = getEmployeeIndex(ssn);

    if (idx != -1) {

        Employee* p = getEmployee(ssn);

        if(p != nullptr) {

            employee_types::type typ = p->getType();

            switch(typ) {
            case employee_types::MONTHLY_PAID_EMPLOYEE:
            {
                MonthlyPaidEmployee *m1 = dynamic_cast<MonthlyPaidEmployee *> (p);
                m1->setFirstName(newFirstName);
                m1->setLastName(newLastName);
                m1->setMonthlySalary(newMonthlySalary);
            }
                break;
            case employee_types::HOURLY_PAID_EMPLOYEE:
            {
                HourlyPaidEmployee *m2 = dynamic_cast<HourlyPaidEmployee *> (p);
                m2->setFirstName(newFirstName);
                m2->setLastName(newLastName);
                m2->setHourlySalary(newHourlySalary);
                m2->setDoneHours(newDoneHours);
            }
                break;
            case employee_types::SALESMAN_EMPLOYEE:
            {
                SalesmanEmployee *m3 = dynamic_cast<SalesmanEmployee *> (p);
                m3->setFirstName(newFirstName);
                m3->setLastName(newLastName);
                m3->setMonthlySalary(newMonthlySalary);
                m3->setBonus(newBonus);
                m3->setOutcomeClaim(newOutcomeClaim);
            }
                break;
            default:
                throw EmployeeTypeInvalidException("Type: " + string(employeeTypetoString(typ)) );
                break;
            }

            return true;

        } else {
            throw SsnDoesNotExistException("Odd behaviour: Getting employee returned null!");
        }
    }

    else {
        throw SsnDoesNotExistException("SSN: " + ssn);
    }
}



bool EmployeeController::removeEmployee(string ssn) {

    int idx = getEmployeeIndex(ssn);
    if (idx != -1) {
        model.erase(model.begin() + idx);
        return true;

    } else {
        throw SsnDoesNotExistException("SSN: " + ssn);
    }

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
        throw SsnDoesNotExistException("SSN: " + ssn);
    return false;
}

string EmployeeController::getEmployeeFirstName(string ssn)
{
    Employee* p = getEmployee(ssn);
    if (p != nullptr)
        return p->getFirstName();
    else
        throw SsnDoesNotExistException("SSN: " + ssn);
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
        throw SsnDoesNotExistException("SSN: " + ssn);
    return false;
}

string EmployeeController::getEmployeeLastName(string ssn)
{
    Employee* p = getEmployee(ssn);
    if (p != nullptr)
        return p->getLastName();
    else
        throw SsnDoesNotExistException("SSN: " + ssn);
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
        throw SsnDoesNotExistException("SSN: " + ssn);
    return false;
}

string EmployeeController::getEmployeeSsn(string ssn)
{
    Employee* p = getEmployee(ssn);
    if (p != nullptr)
        return p->getSocialSecurityNumber();
    else
        throw SsnDoesNotExistException("SSN: " + ssn);
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
            throw EmployeeTypeInvalidException("Type: " + string(employeeTypetoString(p->getType())) );
    else
        throw SsnDoesNotExistException("SSN: " + ssn);
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
            throw EmployeeTypeInvalidException("Type: " + string(employeeTypetoString(p->getType())) );
    else
        throw SsnDoesNotExistException("SSN: " + ssn);
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
            throw EmployeeTypeInvalidException("Type: " + string(employeeTypetoString(p->getType())) );
        }
    }
    else
        throw SsnDoesNotExistException("SSN: " + ssn);
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
            throw EmployeeTypeInvalidException("Type: " + string(employeeTypetoString(p->getType())) );
        }
    }
    else
        throw SsnDoesNotExistException("SSN: " + ssn);
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

        } else
            throw EmployeeTypeInvalidException("Type: " + string(employeeTypetoString(p->getType())) );

    else
        throw SsnDoesNotExistException("SSN: " + ssn);

    return false;
}

double EmployeeController::getEmployeeBonus(string ssn)
{
    Employee* p = getEmployee(ssn);

    if (p != nullptr)

        if (p->getType() == employee_types::SALESMAN_EMPLOYEE) {
            SalesmanEmployee *m = dynamic_cast<SalesmanEmployee *>(p);
            return m->getBonus();

        } else
            throw EmployeeTypeInvalidException("Type: " + string(employeeTypetoString(p->getType())) );
    else
        throw SsnDoesNotExistException("SSN: " + ssn);

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
            throw EmployeeTypeInvalidException("Type: " + string(employeeTypetoString(p->getType())) );
    else
        throw SsnDoesNotExistException("SSN: " + ssn);
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
            throw EmployeeTypeInvalidException("Type: " + string(employeeTypetoString(p->getType())) );
    else
        throw SsnDoesNotExistException("SSN: " + ssn);
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
            throw EmployeeTypeInvalidException("Type: " + string(employeeTypetoString(p->getType())) );
    else
        throw SsnDoesNotExistException("SSN: " + ssn);
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
            throw EmployeeTypeInvalidException("Type: " + string(employeeTypetoString(p->getType())) );
    else
        throw SsnDoesNotExistException("SSN: " + ssn);
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
                                     double newMonthlySalary,
                                     double newHourlySalary, double newDoneHours,
                                     double newBonus, bool newOutcomeClaim) {
    try {
        addEmployee(typ, newFirstName, newLastName, newSsn, newMonthlySalary, newHourlySalary, newDoneHours, newBonus, newOutcomeClaim);
        updateView();

    } catch (EmployeeControllerException) {
        throw;

    } catch (exception &e) {
        cerr << "Uhandled exception caught: " << e.what() << "\n";
    }
}

void EmployeeController::handleEventUpdateEmployee(string ssn,
                                     string newFirstName, string newLastName,
                                     double newMonthlySalary,
                                     double newHourlySalary, double newDoneHours,
                                     double newBonus, bool newOutcomeClaim) {
    try {
        updateEmployee(ssn, newFirstName, newLastName, newMonthlySalary, newHourlySalary, newDoneHours, newBonus, newOutcomeClaim);
        updateView();

    } catch (EmployeeControllerException) {
        cerr << "Exception caught???\n";
        throw;

    } catch (exception &e) {
        cerr << "Unhandled exception caught: " << e.what() << "\n";
    }
}

void EmployeeController::handleEventRemoveEmployee(string ssn) {

    try {
        removeEmployee(ssn);
        updateView();

    } catch(...) {
        throw;
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

