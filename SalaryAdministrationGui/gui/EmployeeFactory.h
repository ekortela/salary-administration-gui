/*
 * EmployeeFactory.h
 *
 *  Created on: 9.8.2016
 *      Author: keskimol
 */

#ifndef EMPLOYEEFACTORY_H_
#define EMPLOYEEFACTORY_H_

enum employee_types { MONTHLY_PAID_EMPLOYEE = 0, HOURLY_PAID_EMPLOYEE = 1, SALESMAN_EMPLOYEE = 2 };

#include "Employee.h"

class EmployeeFactory {
	public:
		static Employee *getMonthlyPaidEmployee(string newName, string newSsn,
	    		double newMonthlySalary);
		static Employee *getHourlyPaidEmployee(string newName, string newSsn,
	    		double newHourlySalary, double doneHours);
		static Employee *getSalesmanEmployee(string newName, string newSsn,
				double newMonthlySalary, double newBonus, bool newOutcomeClaim);
};

#endif /* EMPLOYEEFACTORY_H_ */
