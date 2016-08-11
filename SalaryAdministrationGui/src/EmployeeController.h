/*
* EmployeeController.cpp
*
* The Controller part of MVC design pattern. The Controller contains
* methods for modifying the Model properties and updates the View 
* whenever the Model changes.
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
	vector<Employee*> model;
	EmployeeView view;
public:
	EmployeeController(EmployeeView view);

	// For adding, removing and inspecting the Model objects 
	void addMonthlyPaidEmployee(string newName, string newSsn,
		double newMonthlySalary);
	void addHourlyPaidEmployee(string newName, string newSsn,
		double newHourlySalary, double newDoneHours);
	void addSalesmanEmployee(string newName, string newSsn,
		double newMonthlySalary, double newBonus, bool newOutcomeClaim);
	void removeEmployeeBySsn(string ssn);
	int getEmployeeIndexBySsn(string ssn);
	Employee* getEmployeeBySsn(string ssn);

	// Getting/setting the Model properties
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

	// Load/Save the Model state in local file
	void loadModelFromFile(string filename);
	void saveModelToFile(string filename);

	// Display the Model in the View 
	void updateView();
};

