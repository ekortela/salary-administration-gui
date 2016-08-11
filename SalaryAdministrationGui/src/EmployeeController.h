/*
* EmployeeController.cpp
*
*  Created on: 10.8.2016
*      Author: keskimol
*/


#include <vector>
#include "EmployeeView.h"
#include "EmployeeModel.h"
#include "Employee.h"

class EmployeeController {
private:
	EmployeeModel model;
	EmployeeView view;
public:
	EmployeeController(EmployeeModel model, EmployeeView view);
	void addEmployee();
	void removeEmployee();
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

