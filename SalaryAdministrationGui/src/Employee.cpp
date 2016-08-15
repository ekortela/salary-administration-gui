//============================================================================
// Name        : Employee.cpp
// Author      : Aapo Keskimolo
// Description : Class implementations for Employee types by using Factory Pattern
//============================================================================

#include <string>
#include <vector>
#include <iostream>
#include "Employee.h"

using namespace std;


Employee::~Employee() {}


void Employee::setFirstName(string newFirstName) {
    firstName = newFirstName;
}


string Employee::getFirstName() {
    return firstName;
}

void Employee::setLastName(string newLastName) {
    lastName = newLastName;
}


string Employee::getLastName() {
    return lastName;
}

void Employee::setSocialSecurityNumber(string newSsn) {
	socialSecurityNumber = newSsn;
}


string Employee::getSocialSecurityNumber() {
	return socialSecurityNumber;
}

employee_types::type Employee::getType() {
    return typ;
}
