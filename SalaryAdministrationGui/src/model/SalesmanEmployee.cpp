//============================================================================
// Name        : SalesmanEmployee.cpp
// Author      : Aapo Keskimolo
// Description : Declarations for salesman class methods
//============================================================================

#include "SalesmanEmployee.h"


SalesmanEmployee::SalesmanEmployee(string newFirstName, string newLastName,
                                    string newSsn, double newMonthlySalary,
                                    double newBonus, bool newOutcomeClaim )
{
    typ = employee_types::SALESMAN_EMPLOYEE;
    Employee::setFirstName(newFirstName);
    Employee::setLastName(newLastName);
	Employee::setSocialSecurityNumber(newSsn);
	setMonthlySalary(newMonthlySalary);
	setBonus(newBonus);
	setOutcomeClaim(newOutcomeClaim);
}

SalesmanEmployee::~SalesmanEmployee() {}

void SalesmanEmployee::setMonthlySalary(double newMonthlySalary) {
	monthlySalary = newMonthlySalary;
}


double SalesmanEmployee::getMonthlySalary() {
	return monthlySalary;
}


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


std::ofstream& operator<<(std::ofstream& os, const SalesmanEmployee& e) {
    os << e.firstName.size() << separator;
    os << e.firstName << separator;
    os << e.lastName.size() << separator;
    os << e.lastName << separator;
    os << e.socialSecurityNumber.size() << separator;
    os << e.socialSecurityNumber<< separator;
    os << e.monthlySalary << separator;
    os << e.bonus << separator;
    os << e.outcomeClaim << separator;
    return os;
}


std::ifstream& operator>>(std::ifstream& is, SalesmanEmployee& e) {
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
       is >> e.bonus;
       is >> sep;
       is >> e.outcomeClaim;
       is >> sep;
       return is;
}
