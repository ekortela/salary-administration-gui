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
    double getSalary();

    friend std::ofstream& operator<<(std::ofstream& os, const SalesmanEmployee& e);
    friend std::ifstream& operator>>(std::ifstream& is, SalesmanEmployee& e);
};



#endif /* SALESMANEMPLOYEE_H_ */
