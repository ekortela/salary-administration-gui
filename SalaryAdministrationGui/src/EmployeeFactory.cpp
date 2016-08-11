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

using namespace std;


Employee *EmployeeFactory::getMonthlyPaidEmployee(string newName,
		string newSsn, double newMonthlySalary)
{
	return new MonthlyPaidEmployee(newName, newSsn, newMonthlySalary);
}

Employee *EmployeeFactory::getHourlyPaidEmployee(string newName,
		string newSsn, double newHourlySalary, double newDoneHours)
{
	return new HourlyPaidEmployee(newName, newSsn, newHourlySalary, newDoneHours);
}

Employee *EmployeeFactory::getSalesmanEmployee(string newName, string newSsn,
		double newMonthlySalary, double newBonus, bool newOutcomeClaim)
{
	return new SalesmanEmployee(newName, newSsn, newMonthlySalary, newBonus, newOutcomeClaim);
}
