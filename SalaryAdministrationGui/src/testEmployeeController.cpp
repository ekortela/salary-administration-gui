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

	/*
	View vastaa tassa Dummy implementoinnissa graafista kayttoliittymaa. Kun kaytat Controller luokkaa
	sinun tarvitsee vain alustaa se GUI:ssa (konstruktorissa tai jossain create() metodissa) ja sitten
	kaikki mallin hallitsemiseen tarvitsemasi metodit ovat GUI:n kaytossa. Aina kun mallia muutetaan,
	muista kutsua .updateView() metodia ja se paivittaa GUI:n widget parametrit.
	*/
	EmployeeView view = EmployeeView(); // .... Tama vastaa siis GUI:ta
	EmployeeController controller = EmployeeController(view); // ... Tata luokkaa _kaytetaan_ GUI:ssa

	controller.addHourlyPaidEmployee("Paavo Narkas", "123456-123", 20.0, 180.0);
	controller.addMonthlyPaidEmployee("Teuvo Maantienkuningas", "123456-1244", 3000.0);

	string ssn = "383838-11919";
	controller.addSalesmanEmployee("Risto Varakas", ssn, 1500.50, 30.0, true);

	controller.updateView();

	// try to add employee with same SSN
	controller.addSalesmanEmployee("Risto Varakas", ssn, 1500.50, 30.0, true);
}
