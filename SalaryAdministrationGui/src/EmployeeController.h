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
	EmployeeController();
	void addEmployee(Employee* p);
	void removeEmployee(Employee* p);
	void setEmployeeName();
	void setEmployeeSsn();
};

