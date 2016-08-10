#pragma once

#include <vector>
#include <stdexcept>
#include "Employee.h"
#include "EmployeeFactory.h"


struct EmployeeNotFound: public exception
{
  const char * what () const throw ()
  {
    return "Employee with SSN already in the data base!";
  }
};


class EmployeeModel {
private:
	vector<Employee*> employeeList;
public:
	void addMonthlyPaidEmployee(string newName, string newSsn,
			double newMonthlySalary);
	void addHourlyPaidEmployee(string newName, string newSsn,
			double newHourlySalary, double newDoneHours);
	void addSalesmanEmployee(string newName, string newSsn,
			double newMonthlySalary, double newBonus, bool newOutcomeClaim);
	void removeEmployeeBySsn(string ssn);
	int getEmployeeIndexBySsn(string ssn);
	void printEmployeeInfoAll();
//	void loadEmployeesFromFile(string filename);
//	void saveEmployeesToFile(string filename);
};
