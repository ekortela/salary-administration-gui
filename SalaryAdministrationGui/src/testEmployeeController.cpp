/*
 * testEmployeeFactory.cpp
 *
 *  Created on: 9.8.2016
 *      Author: keskimol
 */

#include <vector>
#include <iostream>
#include "EmployeeFactory.h"
#include "EmployeeView.h"
#include "EmployeeController.h"

using namespace std;


int main(void)
{
	EmployeeView view = EmployeeView();
	EmployeeController controller = EmployeeController(view);

	controller.addHourlyPaidEmployee("Paavo Narkas", "123456-123", 20.0, 180.0);
	controller.addMonthlyPaidEmployee("Teuvo Maantienkuningas", "123456-1244", 3000.0);

	string ssn = "383838-11919";
	controller.addSalesmanEmployee("Risto Varakas", ssn, 1500.50, 30.0, true);

	controller.printEmployeeInfoAll();

	// try to add employee with same SSN
	controller.addSalesmanEmployee("Risto Varakas", ssn, 1500.50, 30.0, true);
}
