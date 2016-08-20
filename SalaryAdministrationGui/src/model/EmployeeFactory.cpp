//============================================================================
// Name        : EmployeeFactory.cpp
// Author      : Aapo Keskimolo
// Description : Declarations for employee factory abstract class
//============================================================================

#include "EmployeeFactory.h"
#include "MonthlyPaidEmployee.h"
#include "HourlyPaidEmployee.h"
#include "SalesmanEmployee.h"

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
        return nullptr;
    }
}
