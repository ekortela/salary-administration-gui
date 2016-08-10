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
		static Employee *getEmployee(employee_types type);
};

#endif /* EMPLOYEEFACTORY_H_ */
