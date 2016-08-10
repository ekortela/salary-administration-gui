/*
 * EmployeeFactory.h
 *
 *  Created on: 9.8.2016
 *      Author: keskimol
 */

#ifndef EMPLOYEEFACTORY_H_
#define EMPLOYEEFACTORY_H_

#include "Employee.h"


class EmployeeFactory {
	public:
		static Employee *getEmployee(int employeeType);
		static Employee *getEmployee(string employeeType);
};

#endif /* EMPLOYEEFACTORY_H_ */
