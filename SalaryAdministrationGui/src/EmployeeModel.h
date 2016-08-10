#pragma once

#include <vector>
#include "Employee.h"

class EmployeeModel {
private:
	vector<Employee*> employeeList;
public:
	void addMonthlyPaidEmployee();
	void addHourlyPaidEmployee();
	void addSalesmanEmployee();
	void removeEmployeeBySsn(string ssn);
	Employee* getEmployeeBySsn(string ssn);
};