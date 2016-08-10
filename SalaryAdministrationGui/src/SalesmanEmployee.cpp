/*
 * SalesmanEmployee.cpp
 *
 *  Created on: 9.8.2016
 *      Author: keskimol
 */

#include "SalesmanEmployee.h"


SalesmanEmployee::SalesmanEmployee(string newName, string newSocialSecurityNumber, double newMonthlySalary, double newBonus, bool newOutcomeClaim)
{
	Employee::setName(newName);
	Employee::setSocialSecurityNumber(newSocialSecurityNumber);
	setMonthlySalary(newMonthlySalary);
	setBonus(newBonus);
	setOutcomeClaim(newOutcomeClaim);
}

SalesmanEmployee::~SalesmanEmployee() {}

void SalesmanEmployee::setMonthlySalary(double newMonthlySalary) {
	monthlySalary = newMonthlySalary;
};


double SalesmanEmployee::getMonthlySalary() {
	return monthlySalary;
};


void SalesmanEmployee::setBonus(double newBonus) {
	bonus = newBonus;
}


double SalesmanEmployee::getBonus() {
	return bonus;
}


void SalesmanEmployee::setOutcomeClaim(bool newOutcomeClaim) {
	outcomeClaim = newOutcomeClaim;
	setRealizedOutcome();
}

bool SalesmanEmployee::getOutcomeClaim() {
	return outcomeClaim;
}

void SalesmanEmployee::setRealizedOutcome() {
	if (outcomeClaim)
		realizedOutcome = (100+bonus)/100*monthlySalary;
	else
		realizedOutcome = monthlySalary;
}


double SalesmanEmployee::getSalary()
{
  return realizedOutcome;
}

void SalesmanEmployee::printInfo()
{
	cout << "Employee type: " << "SalesmanEmployee" << "\n";
	cout << "Name: " << Employee::getName() << "\n";
	cout << "SSN: " << Employee::getSocialSecurityNumber() << "\n";
	cout << "Salary: " << this->getSalary() << "\n";
	cout << ">Monthly salary: " << this->getMonthlySalary() << "\n";
	cout << ">Bonus: " << this->getBonus() << "\n";
	cout << ">Outcome claim: " << this->getOutcomeClaim() << "\n";
}


