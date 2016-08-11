/*
 * testEmployeeFactory.cpp
 *
 *  Created on: 9.8.2016
 *      Author: keskimol
 */

#include <vector>
#include <iostream>
#include "EmployeeFactory.h"
#include "EmployeeModel.h"

using namespace std;


int main(void)
{
	EmployeeModel model = EmployeeModel();

	model.addHourlyPaidEmployee("Paavo Narkas", "123456-123", 20.0, 180.0);
	model.addMonthlyPaidEmployee("Teuvo Maantienkuningas", "123456-1244", 3000.0);

	string ssn = "383838-11919";
	model.addSalesmanEmployee("Risto Varakas", ssn, 1500.50, 30.0, true);

	model.printEmployeeInfoAll();

	// try to add employee with same SSN
	model.addSalesmanEmployee("Risto Varakas", ssn, 1500.50, 30.0, true);


}
