//============================================================================
// Name        : EmployeeController.h
// Author      : Aapo Keskimolo
// Description : The Controller part of MVC design pattern. The Controller contains
//               methods for modifying the Model properties and updates the View
//               whenever the Model changes. View can request actions from the
//               from the Controller via the observer interface.
//============================================================================

#pragma once

#include <vector>
#include <QtWidgets>
#include "EmployeeView.h"
#include "Employee.h"
#include "EmployeeFactory.h"
#include "IController.h"
#include "EmployeeControllerException.h"


class EmployeeController: public IController {

private:
    vector<Employee*> model;
    EmployeeView *m_view;
    ModelDataHeader createModelDataHeader();

    void writeEmployeeTypeToStream(ofstream &ofs, employee_types::type typ);
    // For adding, updating, removing and inspecting the Model objects
    bool createEmployee(employee_types::type typ,
                     string newFirstName, string newLastName, string newSsn,
                     double newMonthlySalary, double newHourlySalary,
                     double newDoneHours, double newBonus, bool newOutcomeClaim);
    bool updateEmployee(string ssn,
                     string newFirstName, string newLastName,
                     double newMonthlySalary, double newHourlySalary,
                     double newDoneHours, double newBonus, bool newOutcomeClaim);
    bool removeEmployee(string ssn);
    int getEmployeeIndex(string ssn);
    Employee* getEmployee(string ssn);
    size_t getEmployeeCount();
    void clearEmployees();
    void printEmployeeModel();

    // Getting/setting the employee properties by using unique social security number
    bool setEmployeeFirstName(string ssn, string newFirstName);
    string getEmployeeFirstName(string ssn);
    bool setEmployeeLastName(string ssn, string newLastName);
    string getEmployeeLastName(string ssn);
    bool setEmployeeSsn(string ssn, string newSsn);
    string getEmployeeSsn(string ssn);
    bool setEmployeeHourlySalary(string ssn, double newHourlySalary);
    double getEmployeeHourlySalary(string ssn);
    bool setEmployeeMonthlySalary(string ssn, double newMonthlySalary);
    double getEmployeeMonthlySalary(string ssn);
    bool setEmployeeBonus(string ssn, double newBonus);
    double getEmployeeBonus(string ssn);
    bool setEmployeeOutcomeclaim(string ssn, bool newOutcomeClaim);
    bool getEmployeeOutcomeClaim(string ssn);
    bool setEmployeeDoneHours(string ssn, double newDoneHours);
    double getEmployeeDoneHours(string ssn);

public:
    EmployeeController(EmployeeView *view);
    ~EmployeeController() {};

    // Display the Model in the View
    void updateView();

    // Methods that handle messages from View to Controller
    void handleEventCreateEmployee(employee_types::type typ,
                     string newFirstName, string newLastName, string newSsn,
                     double newMonthlySalary, double newHourlySalary,
                     double newDoneHours, double newBonus, bool newOutcomeClaim);
    void handleEventRemoveEmployee(string ssn);
    void handleEventClearEmployees();
    void handleEventUpdateEmployee(string newSsn,
                             string newFirstName, string newLastName,
                             double newMonthlySalary, double newHourlySalary,
                             double newDoneHours, double newBonus, bool newOutcomeClaim);
    void handleEventRequestViewUpdate();
    Employee* handleEventGetEmployee(string ssn);
    void handleEventSaveModelStateToFile(string filename);
    void handleEventLoadModelDataFromFile(string filename, bool &firstRun);
};
