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
	int getEmployeeIndex(string ssn);
	Employee* getEmployee(string ssn);
	int getEmployeeCount();

	// Getting/setting the Model properties
	void setEmployeeName(string ssn, string newName);
	string getEmployeeName(string ssn);
	void setEmployeeSsn(string ssn, string newSsn);
	string getEmployeeSsn(string ssn);
	void setEmployeeHourlySalary(string ssn, double newSalary);
	double getEmployeeHourlySalary(string ssn, double newSalary);
	void setEmployeeMonthlySalary(string ssn, double newMonthlySalary);
	double getEmployeeMonthlySalary(string ssn);
	void setEmployeeBonus(string ssn, double newBonus);
	double getEmployeeBonus(string ssn);
	void setEmployeeOutcomeclaim(string ssn, bool newOutcomeClaim);
	bool getEmployeeOutcomeclaim(string ssn);

	// Load/Save the Model state in local file
	void loadModelFromFile(string filename);
	void saveModelToFile(string filename);

	// Display the Model in the View 
	void updateView();
};

