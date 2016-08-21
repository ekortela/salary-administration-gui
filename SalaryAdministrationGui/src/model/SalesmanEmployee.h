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

    friend inline std::ofstream& operator<<(std::ofstream& os, const SalesmanEmployee& e) {
        os << e.firstName;
        return os;
    }

    friend inline std::ifstream& operator>>(std::ifstream& is, SalesmanEmployee& e) {
        is >> e.firstName;
        return is;
    }
};



#endif /* SALESMANEMPLOYEE_H_ */
