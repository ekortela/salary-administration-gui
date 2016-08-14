/*
 * EmployeeFactory.h
 *
 *  Created on: 9.8.2016
 *      Author: keskimol
 */

#ifndef EMPLOYEEFACTORY_H_
#define EMPLOYEEFACTORY_H_

enum employee_types { MONTHLY_PAID_EMPLOYEE, HOURLY_PAID_EMPLOYEE, SALESMAN_EMPLOYEE};

#include "Employee.h"

class EmployeeFactory {

	public:
		static Employee *getMonthlyPaidEmployee(string newName, string newSsn,
	    		double newMonthlySalary);
		static Employee *getHourlyPaidEmployee(string newName, string newSsn,
	    		double newHourlySalary, double doneHours);
		static Employee *getSalesmanEmployee(string newName, string newSsn,
				double newMonthlySalary, double newBonus, bool newOutcomeClaim);
    private:
        EmployeeFactory() {}; // prevent creating an instance of this class
};

#endif /* EMPLOYEEFACTORY_H_ */
