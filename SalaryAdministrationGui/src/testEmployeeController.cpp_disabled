/*
 * testEmployeeFactory.cpp
 *
 *  Created on: 9.8.2016
 *      Author: keskimol
 */

#include <vector>
#include <iostream>
#include <stdexcept>
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
	controller.addSalesmanEmployee("Risto Varakas", "383838-11919", 1500.50, 30.0, true);

	// Display employees with dummy View 
	cout << "\n *** TEST *** Display all employee information by using dummy view... \n";
	controller.updateView();


	// Test variables
	int count = 0;
	string newName = "";
	string newSsn = "";


	cout << "\n *** TEST *** Try to add employee with pre-existing SSN... \n";
	newName = "Risto Varakas";
	newSsn = "123456-789";
	controller.addSalesmanEmployee(newName, newSsn, 1500.50, 30.0, true);
	count = controller.getEmployeeCount();
	controller.addSalesmanEmployee(newName, newSsn, 1500.50, 30.0, true);
	assert(count == controller.getEmployeeCount());


	cout << "\n *** TEST *** Change existing employee name... \n";
	newName = "new_name";
	newSsn = "111111-111";
	controller.addSalesmanEmployee(newName, newSsn, 1500.50, 30.0, true);
	controller.setEmployeeName(newSsn, newName);
	assert(controller.getEmployeeName(newSsn) == newName);


	cout << "\n *** TEST *** Add and remove employee... \n";
	newSsn = "ssn_to_be_removed";
	count = controller.getEmployeeCount();
	controller.addSalesmanEmployee("", newSsn, 0.0, 0.0, true);
	controller.removeEmployee(newSsn);
	assert(controller.getEmployeeCount() == count);


	cout << "\n *** TEST *** Remove all employees... \n";
	controller.removeEmployeesAll();
	assert(controller.getEmployeeCount() == 0);


	cout << "\n *** TEST *** Try to REMOVE non-existent employee... \n";
	newSsn = "ssn_that_does_not_exist";
	try {
		controller.removeEmployee(newSsn);
		assert(false);
	} catch (out_of_range e1) {
		// do nothing
	} catch (...) {
		assert(false);
	}


	cout << "\n *** TEST *** Try to SET name of non-existent employee... \n";
	newSsn = "ssn_that_does_not_exist";
	try {
		controller.setEmployeeName(newSsn, "");
		assert(false);
	} catch (invalid_argument e1) {
		// do nothing
	} catch (...) {
		assert(false);
	}


	cout << "\n *** TEST *** Try to GET name of non-existent employee... \n";
	newSsn = "ssn_that_does_not_exist";
	try {
		assert(controller.getEmployeeName(newSsn) == "");
		assert(false);
	} catch (invalid_argument e1) {
		// do nothing
	} catch (...) {
		assert(false);
	}

}
