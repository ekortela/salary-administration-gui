/*
 * SalesmanEmployee.h
 *
 *  Created on: 9.8.2016
 *      Author: keskimol
 */

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
    SalesmanEmployee( string newName, string newSocialSecurityNumber, double newMonthlySalary, double newBonus, bool newOutcomeClaim );
    virtual ~SalesmanEmployee();

    void setMonthlySalary(double newMonthlySalary);
    double getMonthlySalary();
    void setBonus(double newBonus);
    double getBonus();
    void setOutcomeClaim(bool newOutcomeClaim);
    void setRealizedOutcome();
    double getSalary();
};



#endif /* SALESMANEMPLOYEE_H_ */
