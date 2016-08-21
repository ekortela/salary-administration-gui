//============================================================================
// Name        : SalesmanEmployee.h
// Author      : Aapo Keskimolo
// Description : Definition file salesman employee class. Inherits from Employee
//               base-class.
//============================================================================

#pragma once

#ifndef SALESMANEMPLOYEE_H_
#define SALESMANEMPLOYEE_H_

#include "Employee.h"

using namespace std;

class SalesmanEmployee: public Employee
{
  private:
  	double monthlySalary;
    double bonus;
    double realizedOutcome;
    bool outcomeClaim;

  public:
    SalesmanEmployee( string newFirstName, string newLastName,
                      string newSsn, double newMonthlySalary,
                      double newBonus, bool newOutcomeClaim );
    virtual ~SalesmanEmployee();
    void setMonthlySalary(double newMonthlySalary);
    double getMonthlySalary();
    void setBonus(double newBonus);
    double getBonus();
    void setOutcomeClaim(bool newOutcomeClaim);
    bool getOutcomeClaim();
    void setRealizedOutcome();
    double getSalary();
    void printInfo();

    friend std::ofstream& operator<<(std::ofstream& os, const SalesmanEmployee& e) {
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

    friend std::ifstream& operator>>(std::ifstream& is, SalesmanEmployee& e) {
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
};



#endif /* SALESMANEMPLOYEE_H_ */
