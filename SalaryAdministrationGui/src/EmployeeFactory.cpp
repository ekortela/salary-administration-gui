/*
 * EmployeeFactory.cpp
 *
 *  Created on: 9.8.2016
 *      Author: keskimol
 */

#include "EmployeeFactory.h"
#include "MonthlyPaidEmployee.h"
#include "HourlyPaidEmployee.h"
#include "SalesmanEmployee.h"
#include <stdexcept>

using namespace std;


Employee *EmployeeFactory::getEmployee(employee_types::type typ,
                                               string newFirstName, string newLastName, string newSsn,
                                               double newMonthlySalary = 0.0, double newHourlySalary = 0.0,
                                               double newDoneHours = 0.0, double newBonus = 0.0, bool newOutcomeClaim = false)
{
    switch(typ){

    case employee_types::MONTHLY_PAID_EMPLOYEE:
        return new MonthlyPaidEmployee(newFirstName, newLastName, newSsn, newMonthlySalary);

    case employee_types::HOURLY_PAID_EMPLOYEE:
        return new HourlyPaidEmployee(newFirstName, newLastName, newSsn, newHourlySalary, newDoneHours);

    case employee_types::SALESMAN_EMPLOYEE:
        return new SalesmanEmployee(newFirstName, newLastName, newSsn, newMonthlySalary, newBonus, newOutcomeClaim);

    default:
        throw out_of_range("Employee type not recognized: " + to_string(typ));
    }
}
