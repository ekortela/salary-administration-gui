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
#include <QtWidgets>
#include "EmployeeView.h"
#include "Employee.h"
#include "EmployeeFactory.h"
#include "IObserver.h"

class EmployeeController: public IObserver {

private:
    vector<Employee*> model;

public:
    EmployeeView *m_view;
    EmployeeController(EmployeeView *view);
    ~EmployeeController() {};

	// For adding, removing and inspecting the Model objects 
	void addMonthlyPaidEmployee(string newName, string newSsn,
		double newMonthlySalary);
	void addHourlyPaidEmployee(string newName, string newSsn,
		double newHourlySalary, double newDoneHours);
	void addSalesmanEmployee(string newName, string newSsn,
		double newMonthlySalary, double newBonus, bool newOutcomeClaim);
    void removeEmployee(string ssn);
    int getEmployeeIndex(string ssn);
    Employee* getEmployee(string ssn);
    int getEmployeeCount();
    void clearEmployees();

	// Getting/setting the Model properties
    void setEmployeeName(string ssn, string newName);
    string getEmployeeName(string ssn);
    void setEmployeeSsn(string ssn, string newSsn);
    string getEmployeeSsn(string ssn);
    void setEmployeeHourlySalary(string ssn, double newHourlySalary);
    double getEmployeeHourlySalary(string ssn);
    void setEmployeeMonthlySalary(string ssn, double newMonthlySalary);
    double getEmployeeMonthlySalary(string ssn);
    void setEmployeeBonus(string ssn, double newBonus);
    double getEmployeeBonus(string ssn);
    void setEmployeeOutcomeclaim(string ssn, bool newOutcomeClaim);
    bool getEmployeeOutcomeclaim(string ssn);

	// Display the Model in the View 
	void updateView();

    void handleEvent();
};

