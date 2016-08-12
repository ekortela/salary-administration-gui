/*
 * testEmployeeFactory.cpp
 *
 *  Created on: 9.8.2016
 *      Author: keskimol
 */

#include <vector>
#include <iostream>
#include "assert.h"
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

	// Esimerkki. 
	// MainWindow.h / MainWindow.cpp (metodi tai konstruktori)
	// EmployeeController c = EmployeeController(this);
	// Se on siina! Nyt kaikki kontrollerin metodit ovat GUI:n kaytossa!

	controller.addHourlyPaidEmployee("Paavo Narkas", "123456-123", 20.0, 180.0);
	controller.addMonthlyPaidEmployee("Teuvo Maantienkuningas", "123456-1244", 3000.0);

	string ssn = "383838-11919";
	controller.addSalesmanEmployee("Risto Varakas", ssn, 1500.50, 30.0, true);

	// Display employees with dummy View 
	cout << "\n *** TEST *** Display all employee information by using dummy view... \n";
	controller.updateView();

	// Test
	cout << "\n *** TEST *** Try to add employee with pre-existing SSN... \n";
	int nEmployees = controller.getEmployeeCount();
	controller.addSalesmanEmployee("Risto Varakas", ssn, 1500.50, 30.0, true);
	assert(nEmployees == controller.getEmployeeCount());

	// Test
	cout << "\n *** TEST *** Try to remove employee that does not exist... \n";
	nEmployees = controller.getEmployeeCount();
	controller.removeEmployeeBySsn("absdjdjd");
	assert(nEmployees == controller.getEmployeeCount());

	// Test
	cout << "\n *** TEST *** Change existing employee name... \n";
	string newName = "Risto Uusisukunimi";
	controller.setEmployeeName(ssn, newName);
	assert(controller.getEmployeeName(ssn) == newName);

	// Test
	cout << "\n *** TEST *** Remove employee... \n";
	ssn = "This SSN will be removed";
	//nEmployees = controller.getEmployeeCount();
	//cout << controller.getEmployeeCount() << "\n";
	controller.updateView();
	controller.addSalesmanEmployee("", ssn, 0.0, 0.0, true);
	controller.removeEmployeeBySsn(ssn);
	assert(controller.getEmployeeIndex(ssn) == -1);
	//cout << controller.getEmployeeCount() << "\n";
	//assert(controller.getEmployeeCount() == (nEmployees-1));


	// Display employees
	cout << "\nFinal employee list:\n";
	controller.updateView();

}
