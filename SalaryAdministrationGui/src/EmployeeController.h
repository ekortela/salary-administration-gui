/*
* EmployeeController.cpp
*
*  Created on: 10.8.2016
*      Author: keskimol
*/


#include <vector>
#include "EmployeeView.h"
#include "Employee.h"
#include "EmployeeFactory.h"

class EmployeeController {
private:
	vector<Employee*> model;;
	EmployeeView view;
public:
	EmployeeController(EmployeeView view);

	void addMonthlyPaidEmployee(string newName, string newSsn,
		double newMonthlySalary);
	void addHourlyPaidEmployee(string newName, string newSsn,
		double newHourlySalary, double newDoneHours);
	void addSalesmanEmployee(string newName, string newSsn,
		double newMonthlySalary, double newBonus, bool newOutcomeClaim);
	void removeEmployeeBySsn(string ssn);
	int getEmployeeIndexBySsn(string ssn);
	Employee* getEmployeeBySsn(string ssn);
	void printEmployeeInfoAll();

	//	void loadModelFromFile(string filename);
	//	void saveModelToFile(string filename);

	void setEmployeeName();
	void getEmployeeName();
	void setEmployeeSsn();
	void getEmployeeSsn();
	void setEmployeeHourlySalary();
	void getEmployeeHourlySalary();
	void setEmployeeMonthlySalary();
	void getEmployeeMonthlySalary();
	void setEmployeeBonus();
	void getEmployeeBonus();
	void setEmployeeOutcomeclaim();
	void getEmployeeOutcomeclaim();
	void updateView();
};

