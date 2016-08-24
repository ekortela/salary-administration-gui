//============================================================================
// Name        : MonthlyPaidEmployee.cpp
// Author      : Aapo Keskimolo
// Description : Declarations for monthly paid employee class methods
//============================================================================

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
    cout << "Type: " << employeeTypetoString(typ) << "\n";
    cout << "First Name: " << Employee::getFirstName() << "\n";
    cout << "Last Name: " << Employee::getLastName() << "\n";
	cout << "SSN: " << Employee::getSocialSecurityNumber() << "\n";
	cout << "Salary: " << this->getSalary() << "\n";
	cout << ">Monthly salary: " << this->getMonthlySalary() << "\n";
}


std::ofstream& operator<<(std::ofstream& os, const MonthlyPaidEmployee& e) {
    os << e.firstName.size() << separator;
    os << e.firstName << separator;
    os << e.lastName.size() << separator;
    os << e.lastName << separator;
    os << e.socialSecurityNumber.size() << separator;
    os << e.socialSecurityNumber<< separator;
    os << e.monthlySalary << separator;
    return os;
}


std::ifstream& operator>>(std::ifstream& is, MonthlyPaidEmployee& e) {
    int len = 0;
    char sep;
    is >> len;
    is >> sep;
    if (len) {
        std::vector<char> tmp(len);
        is.read(tmp.data() , len);
        e.firstName.assign(tmp.data(), len);
    }
    is >> sep;
    is >> len;
    is >> sep;
    if (len) {
        std::vector<char> tmp(len);
        is.read(tmp.data() , len);
        e.lastName.assign(tmp.data(), len);
    }
    is >> sep;
    is >> len;
    is >> sep;
    if (len) {
        std::vector<char> tmp(len);
        is.read(tmp.data() , len);
        e.socialSecurityNumber.assign(tmp.data(), len);
    }
    is >> sep;
    is >> e.monthlySalary;
    is >> sep;
    return is;
}

