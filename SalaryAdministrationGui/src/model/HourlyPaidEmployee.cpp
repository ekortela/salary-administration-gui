//============================================================================
// Name        : HourlyPaidEmployee.cpp
// Author      : Aapo Keskimolo
// Description : Declarations for HourlyPaidEmployee.h
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


std::ofstream& operator<<(std::ofstream& os, const HourlyPaidEmployee& e) {
    os << e.firstName.size() << separator;
    os << e.firstName << separator;
    os << e.lastName.size() << separator;
    os << e.lastName << separator;
    os << e.socialSecurityNumber.size() << separator;
    os << e.socialSecurityNumber<< separator;
    os << e.hourlySalary << separator;
    os << e.doneHours << separator;
    return os;
}


std::ifstream& operator>>(std::ifstream& is, HourlyPaidEmployee& e) {
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
    is >> e.hourlySalary;
    is >> sep;
    is >> e.doneHours;
    is >> sep;
    return is;
}
