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


void Employee::setName(string newName) {
	name = newName;
}


string Employee::getName() {
	return name;
}


void Employee::setSocialSecurityNumber(string newSocialSecurityNumber) {
	socialSecurityNumber = newSocialSecurityNumber;
}


string Employee::getSocialSecurityNumber() {
	return socialSecurityNumber;
}
