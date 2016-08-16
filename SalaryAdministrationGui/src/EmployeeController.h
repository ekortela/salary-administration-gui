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
    bool addEmployee(employee_types::type typ,
                     string newFirstName, string newLastName, string newSsn,
                     double newMonthlySalary, double newHourlySalary,
                     double newDoneHours, double newBonus, bool newOutcomeClaim);


    bool removeEmployee(string ssn);
    int getEmployeeIndex(string ssn);
    Employee* getEmployee(string ssn);
    size_t getEmployeeCount();
    void clearEmployees();
    void printEmployeeModel();

    // Getting/setting the employee properties by using unique social security number
    void setEmployeeFirstName(string ssn, string newName);
    string getEmployeeFirstName(string ssn);
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

    // Methods that handle messages from View to Controller
    void handleEventAddEmployee(employee_types::type typ,
                     string newFirstName, string newLastName, string newSsn,
                     double newMonthlySalary, double newHourlySalary,
                     double newDoneHours, double newBonus, bool newOutcomeClaim);
    void handleEventRemoveEmployee(string ssn);
    void handleEventPrintEmployees();
    void handleEventRequestViewUpdate();
    Employee* handleEventGetEmployee(string ssn);
};

