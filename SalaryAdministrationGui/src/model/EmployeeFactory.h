//============================================================================
// Name        : EmployeeFactory.h
// Author      : Aapo Keskimolo
// Description : Abstract class for creating employee classes based on employee
//               types (enum). Returns an instance of employee object initialized
//               with given input parameters.
//============================================================================

#pragma once

#ifndef EMPLOYEEFACTORY_H_
#define EMPLOYEEFACTORY_H_

#include "Employee.h"

class EmployeeFactory {

	public:
        static Employee *getEmployee(employee_types::type typ,
                                     string newFirstName, string newLastName, string newSsn,
                                     double newMonthlySalary, double newHourlySalary,
                                     double newDoneHours, double newBonus, bool newOutcomeClaim);
    private:
        EmployeeFactory() {}; // prevent instantiation (=pure abstract class)
};

#endif /* EMPLOYEEFACTORY_H_ */
